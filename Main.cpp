#include "Mesh.h"
#include "Shader.h"
#include "Main.h"
#include "Bezier.h"
#include "Camera.h"

void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInputCamera(GLFWwindow* window);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void mouse_callback(GLFWwindow* window, double xposIn, double yposIn);

// lighting
glm::vec3 lightPos(1.2f, 1.0f, 2.0f);

// camera
Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
float lastX = SCR_WIDTH / 2.0f;
float lastY = SCR_HEIGHT / 2.0f;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

int main()
{
	//option wireframe
	std::cout << "Press 1 if you want to visualize wireframe. Else press 0" << std::endl;

	int x{ }; // define variable x to hold user input (and zero-initialize it)
	std::cin >> x; // get number from keyboard and store it in variable x

	std::cout << "You entered " << x << '\n';
	bool wireframe = x;

	//nombres de points voulus sur la courbe de bézier
	std::cout << "How many points do you want to draw the Bezier curve?" << std::endl;
	int nbPoints{ }; // define variable x to hold user input (and zero-initialize it)
	std::cin >> nbPoints; // get number from keyboard and store it in variable x

	std::cout << "aaaaaaaaah" << std::endl;


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


		---JPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP

		// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	#ifdef __APPLE__
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

		
	} */
	
	
	//-----------------------create points of bezier curve -------------------------


		// glfw: initialize and configure
		// ------------------------------
	/*glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	#endif

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_TRUE);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);


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
	//shader= new Shader("camera.vs", "camera.fs");
	shader = new Shader("vertex.glsl", "fragment.glsl");
	bezier->bezierMesh->setupMesh();


	while (!glfwWindowShouldClose(window))
	{
		float currentFrame = static_cast<float>(glfwGetTime());
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// input
		// -----
		processInputCamera(window);
		bezier->bezierMesh->Draw(shader, camera);
		glfwSwapBuffers(window);
		glfwPollEvents();

	}




	std::cout << "Coucou: ";
	return 0; */

}


//---------------functions to handle camera and mouse-------------------------------------------------

void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
{
	float xpos = static_cast<float>(xposIn);
	float ypos = static_cast<float>(yposIn);

	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}


void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(static_cast<float>(yoffset));
}

void processInputCamera(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);
}
