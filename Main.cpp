#include "Mesh.h"
#include "Shader.h"
#include "Main.h"
#include "Bezier.h"

int main()
{
	//option wireframe
	std::cout << "Press 1 if you want to visualize wireframe. Else press 0" << std::endl;

	int x{ }; // define variable x to hold user input (and zero-initialize it)
	std::cin >> x; // get number from keyboard and store it in variable x

	std::cout << "You entered " << x << '\n';
	bool wireframe = x;

	//nombres de points voulus sur la courbe de b�zier
	std::cout << "How many points do you want on your Bezier curve?" << std::endl;
	int nbPoints{ }; // define variable x to hold user input (and zero-initialize it)
	std::cin >> nbPoints; // get number from keyboard and store it in variable x

	/*----------DISPLAY TWO TRIANGLES

	vector<unsigned int> indices;
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(3);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);


	struct Vertex v1;
	v1.Position = glm::vec3(0.5f, 0.5f, 0.0f);
	v1.Normal = glm::vec3(1.0f, 1.0f, 1.0f);
	v1.TexCoords = glm::vec2(0.0f, 0.0f);

	struct Vertex v2;
	v2.Position = glm::vec3(0.5f, -0.5f, 0.0f);
	v2.Normal = glm::vec3(1.0f, 1.0f, 1.0f);
	v2.TexCoords = glm::vec2(0.0f, 0.0f);

	struct Vertex v3;
	v3.Position = glm::vec3(-0.5f, -0.5f, 0.0f);
	v3.Normal = glm::vec3(1.0f, 1.0f, 1.0f);
	v3.TexCoords = glm::vec2(0.0f, 0.0f);

	struct Vertex v4;
	v4.Position = glm::vec3(-0.5f, 0.5f, 0.0f);
	v4.Normal = glm::vec3(1.0f, 1.0f, 1.0f);
	v4.TexCoords = glm::vec2(0.0f, 0.0f);

	vector<Vertex> vertices;
	vertices.push_back(v1);
	vertices.push_back(v2);
	vertices.push_back(v3);
	vertices.push_back(v4);


	//init glfw et glad
	GLFWwindow* window = init_utils();

	//create vertices made with bezier points
	struct vertex
	//Mesh* mesh = new Mesh(vertices, indices, wireframe);
	Shader* shader;
	shader = new Shader("vertex.glsl", "fragment.glsl");
	mesh->setupMesh();

	vector <glm::vec3> controlPoints;
	controlPoints.push_back(v1.Position);
	controlPoints.push_back(v2.Position);
	controlPoints.push_back(v4.Position);

	Bezier* bezier = new Bezier(controlPoints);


	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		mesh->Draw(shader);
		glfwSwapBuffers(window);
		glfwPollEvents();

	} */

	//init glfw et glad
	GLFWwindow* window = init_utils();

	struct Vertex v1;
	v1.Position = glm::vec3(0.5f, 0.5f, 0.0f);
	v1.Normal = glm::vec3(1.0f, 1.0f, 1.0f);
	v1.TexCoords = glm::vec2(0.0f, 0.0f);

	struct Vertex v2;
	v2.Position = glm::vec3(0.5f, -0.5f, 0.0f);
	v2.Normal = glm::vec3(1.0f, 1.0f, 1.0f);
	v2.TexCoords = glm::vec2(0.0f, 0.0f);


	struct Vertex v4;
	v4.Position = glm::vec3(-0.5f, 0.5f, 0.0f);
	v4.Normal = glm::vec3(1.0f, 1.0f, 1.0f);
	v4.TexCoords = glm::vec2(0.0f, 0.0f);


	vector <glm::vec3> controlPoints;
	controlPoints.push_back(v1.Position);
	controlPoints.push_back(v2.Position);
	controlPoints.push_back(v4.Position);


	Bezier* bezier = new Bezier(controlPoints, nbPoints);

	Shader* shader;
	shader = new Shader("vertex.glsl", "fragment.glsl");
	/*bezier->bezierMesh->setupMesh();


	while (!glfwWindowShouldClose(window))
	{
		processInput(window);
		bezier->bezierMesh->Draw(shader);
		glfwSwapBuffers(window);
		glfwPollEvents();

	} */

	std::cout << "Coucou: ";
	return 0;

}