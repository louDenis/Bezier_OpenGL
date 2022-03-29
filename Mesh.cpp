#include "Mesh.h"

Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices, bool wireframe)
{
    this->vertices = vertices;
    this->indices = indices;
    setupMesh();
    this->wireframe = wireframe;
}

void Mesh::cpyIntoStructure()
{
    for (int i = 0; i < coords.size(); i++)
    {
        //recopier tout dans la structure vertices, c moche mé c oké
        this->vertices[i].Position = coords[i];
        this->vertices[i].TexCoords = texCoords[i];
        this->vertices[i].Normal = normal[i];
    }

    for (int i = 0; i < coords.size(); i++)
    {
        this->indices[i] = faceIndex[i];
    }
}

void Mesh::loadObjModel(const char* filename)
{
    std::ifstream in(filename, std::ios::in);
    if (!in)
    {
        std::cerr << "Fichier introuvable " << filename << std::endl;
        exit(1);

    }
    vector<string> lines;
    std::string line;
    getline(in, line);
    
    while (getline(in, line)) {
        if (line.substr(0, 2) == "v ")
        {
            std::istringstream v(line.substr(2));
            double x, y, z;
            v >> x; v >> y; v >> z;
            glm::vec3 coord = glm::vec3(x, y, z);
            this->coords.push_back(coord);

        }

        else if (line.substr(0, 2) == "vt")
        {
            std::istringstream v(line.substr(3));
            glm::vec2 tex;
            int U, V;
            v >> U; v >> V;
            tex = glm::vec2(U, V);
            this->texCoords.push_back(tex);
         }

     
        else if (line.substr(0, 2) == "f ") {
            int a, b, c; //to store mesh index
            int A, B, C; //to store texture index
         
            const char* chh = line.c_str();
            sscanf_s(chh, "f %i/%i %i/%i %i/%i", &a, &A, &b, &B, &c, &C); //here it read the line start with f and store the corresponding values in the variables

            a--; b--; c--;
            A--; B--; C--;
           
            this->faceIndex.push_back(a); this->textureIndex.push_back(A);
            this->faceIndex.push_back(b); this->textureIndex.push_back(B);
            this->faceIndex.push_back(c); this->textureIndex.push_back(C);
        }

        else if (line.substr(0, 2) == "Vn") {
            std::istringstream v(line.substr(2));
            double x, y, z;
            v >> x; v >> y; v >> z;
            glm::vec3 norm = glm::vec3(x, y, z);
            this->normal.push_back(norm);
            //vertex.Position = glm::vec3(x, y, z);
            //std::cout << "coords:" << coord.x << coord.y << coord.z << std::endl;
        }


    }

}

void Mesh::setupMesh()
{
    //cpyIntoStructure();

    // create buffers/arrays
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);
    // load data into vertex buffers
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // A great thing about structs is that their memory layout is sequential for all its items.
    // The effect is that we can simply pass a pointer to the struct and it translates perfectly to a glm::vec3/2 array which
    // again translates to 3/2 floats which translates to a byte array.
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    // set the vertex attribute pointers
    // vertex Positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, Normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, TexCoords));

}

//v= vertices
//vt= texture coordinates
//f= faces

//coordcartésiennes


void Mesh::Draw(Shader * shader)
{
   if (!(this->wireframe))
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    else
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    shader->use();
    glBindVertexArray(VAO);
    glDrawElements(GL_LINE_STRIP, static_cast<unsigned int>(indices.size()), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);

} 