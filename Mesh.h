#pragma once
#include "Shader.h"
#include <iostream>
#include <fstream> 
#include <string> 
#include <sstream>  
#include <vector>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <windows.h>
#include "Camera.h"
using namespace std;


struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
};

class Mesh
{
public:
    bool wireframe;
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, bool wireframe);
    vector< glm::vec3> coords;
    vector< glm::vec3> normal;
    vector< glm::vec2> texCoords;
    vector <int> faceIndex;
    vector<int> textureIndex;
    unsigned int VAO, VBO, EBO;

    vector<Vertex> vertices;
    vector<unsigned int> indices;

    void loadObjModel(const char * filename);
    void setupMesh();
    void cpyIntoStructure();
    void Draw(Shader * shader, Camera camera);
};


