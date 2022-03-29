#include "Bezier.h"


glm::vec3 Bezier::getBezierPoints(float t, int start, int stop)
{
    if (start == stop) return controlPoints.at(start);
    glm::vec3 left = getBezierPoints(t, start, stop - 1);
    glm::vec3 right = getBezierPoints(t, start + 1, stop);
    return ((1 - t) * left) + (t * right);
}

Bezier::Bezier(vector < glm::vec3> controlPoints, int nbPoints)
{
	this->controlPoints = controlPoints;
	this->nbPoints = nbPoints;
	
	//tableau indices
	vector<unsigned int> indices;
	for (int i = 0; i < nbPoints; i++)
	{
		indices.push_back(i);
	}
	
	vector<Vertex> bezierVertices;

	vector <glm::vec3> bezierPoints;
	float step = 1.0 / (float)this->nbPoints;
	//std::cout << "STEP= " << step << std::endl;
	for (float t = 0; t < 1.0f ; t += step)
	{
		std::cout << t << std::endl ;
		struct Vertex v;
		v.Position = getBezierPoints(t, 0, 2);
		v.Normal = glm::vec3(1.0f, 1.0f, 1.0f);
		v.TexCoords = glm::vec2(0.0f, 0.0f);
		bezierVertices.push_back(v);
	}
		
	//DISPLAY RESULTS
	for (int i = 0; i < bezierVertices.size(); i++)
	{
		std::cout << "Point" << i << ":" << bezierVertices.at(i).Position.x << "," << bezierVertices.at(i).Position.y << "," << bezierVertices.at(i).Position.z << std::endl;
	}

	//create mesh with Bezier points created
	this->bezierMesh = new Mesh(bezierVertices, indices, 1);

    
}