#include "Mesh.h"

class Bezier
{
public:
	Mesh * bezierMesh;
   
	vector<glm::vec3> controlPoints;
    int nbPoints;
	//int degree; //nb_controlPoints-1
    //int number_of_curve_points;
        
    glm::vec3 getBezierPoints(float t, int start, int stop);
    Bezier(vector <glm::vec3> controlPoints, int nbPoints);
};