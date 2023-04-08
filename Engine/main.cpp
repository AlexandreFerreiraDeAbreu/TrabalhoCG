#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "tinyxml2-master/tinyxml2.h"



std::vector<std::string> ficheiros;
std::vector<float> vertices;

std::vector<float> x;
std::vector<float> y;
std::vector<float> z;


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}


void Desenhar() {
	glBegin(GL_TRIANGLES);
	for(int i = 0; i<vertices.size();i+=3){
		glColor3f(1.0f,0.5f,0.0f);
		glVertex3f(vertices[i],vertices[i+1],vertices[i+2]);
	}
	glEnd();
}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(x[0],y[0],z[0],
					 x[1],y[1],z[1],
					 x[2],y[2],z[2]);

	glBegin(GL_LINES);
								// X axis in red
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-100.0f, 0.0f, 0.0f);
	glVertex3f( 100.0f, 0.0f, 0.0f);
									// Y Axis in Green
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, -100.0f, 0.0f);
	glVertex3f(0.0f, 100.0f, 0.0f);
									// Z Axis in Blue
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, -100.0f);
	glVertex3f(0.0f, 0.0f, 100.0f);
	glEnd();


	Desenhar();

	// End of frame
	glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {
// put code to process regular keys in here
}


void processSpecialKeys(int key, int xx, int yy) {
// put code to process special keys in here
}

int Ler_XML(){
		 int i = 0;
	   tinyxml2::XMLDocument xml_doc;

	   tinyxml2::XMLError eResult = xml_doc.LoadFile("xml_syntax.xml");
	   if (eResult != tinyxml2::XML_SUCCESS) return -1;

	   tinyxml2::XMLNode* root = xml_doc.FirstChildElement("world");
	   if (root == nullptr) return -1;

	   tinyxml2::XMLNode* camroot = root->FirstChildElement("camera");
	   if (camroot == nullptr) return -1;

	   tinyxml2::XMLElement* child = camroot->FirstChildElement("position");
	   if (child == nullptr) return -1;

		 while (child != nullptr){
	     x.push_back(std::stof(child->Attribute("x")));
	     y.push_back(std::stof(child->Attribute("y")));
	     z.push_back(std::stof(child->Attribute("z")));

	     if(i == 0) child = child->NextSiblingElement("lookAt");
	     else child = child->NextSiblingElement("up");
	     i = i + 1;
	   }

	   tinyxml2::XMLNode* root3 = root->FirstChildElement("group");
	   if (root3 == nullptr) return -1;

	   tinyxml2::XMLNode* root4 = root3->FirstChildElement("models");
	   if (root4 == nullptr) return -1;

	   tinyxml2::XMLElement* elemente = root4->FirstChildElement("model");
	   if (elemente == nullptr) return -1;

	   while (elemente != nullptr){
	       ficheiros.push_back(elemente->Attribute("file"));
	       elemente = elemente->NextSiblingElement("model");
	   }

	   return 1;
}


void Ler_Ficheiro3D(){

	std::string linha;
	float x,y,z;

	for(std::string i : ficheiros){
		std::ifstream file(i);
		while(std::getline(file,linha)){
			std::istringstream in (linha);
			in >> x;
			in >> y;
			in >> z;

			vertices.push_back(x);
			vertices.push_back(y);
			vertices.push_back(z);
		}
		file.close();
	}

}

int main(int argc, char **argv) {

	int ler = Ler_XML();
	if(ler == -1) return 1;
	Ler_Ficheiro3D();


// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");

// Required callback registry
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);

// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
// enter GLUT's main cycle
	glutMainLoop();

	return 1;
}
