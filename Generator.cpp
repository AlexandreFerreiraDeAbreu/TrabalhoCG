#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
using namespace std;


void drawPlano (float l, int d){
    
    ofstream fileP ("plano.3d", ios::trunc);

    float n = (l/float(d));
    float u = (l/2.0f);

    for (int j = 0; j < d; j++){
		for (int i = 0; i < d; i++){
			fileP << ((n*i)-u) << " 0 " << ((n*j)-u) << endl;
			fileP << ((n*i)-u) << " 0 " << ((n*(j+1))-u) << endl;
			fileP << ((n*(i+1))-u) << " 0 " << ((n*(j+1))-u) << endl;

			fileP << ((n*i)-u) << " 0 " << ((n*j)-u) << endl;
			fileP << ((n*(i+1))-u) << " 0 " << ((n*(j+1))-u) << endl;
			fileP << ((n*(i+1))-u) << " 0 " << ((n*j)-u) << endl;
		}
	}
    fileP.close();
}




void drawBox(float l, int d){
	float n = (l/float(d));
    float u = (l/2.0f);

    ofstream fileB ("box.3d", ios::trunc);
	
	for (int j = 0; j < d; j++){
		for (int i = 0; i < d; i++){
			fileB << ((n*i)-u) << ' ' << (-u) << ' ' << ((n*j)-u) << endl;
			fileB << ((n*i)-u) << ' ' << (-u) << ' ' << ((n*(j+1))-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << (-u) << ' ' << ((n*(j+1))-u) << endl;

			fileB << ((n*i)-u) << ' ' << u << ' ' << ((n*(j+1))-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << u << ' ' << ((n*(j+1))-u) << endl;


			fileB << ((n*i)-u) << ' ' << (-u) << ' ' << ((n*j)-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << (-u) << ' ' << ((n*(j+1))-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << (-u) << ' ' << ((n*j)-u) << endl;

			fileB << ((n*i)-u) << ' ' << u << ' ' << ((n*j)-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << u << ' ' << ((n*(j+1))-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << u << ' ' << ((n*j)-u) << endl;



			fileB << u << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*i)) << endl;
			fileB << u << ' ' << (-u+(n*j)) << ' ' << (u-(n*i)) << endl;
			fileB << u << ' ' << (-u+(n*j)) << ' ' << (u-(n*(i+1))) << endl;

			fileB << u << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*(i+1))) << endl;
			fileB << u << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*i)) << endl;
			fileB << u << ' ' << (-u+(n*j)) << ' ' << (u-(n*(i+1))) << endl;


			fileB << (-u) << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*i)) << endl;
			fileB << (-u) << ' ' << (-u+(n*j)) << ' ' << (u-(n*i)) << endl;
			fileB << (-u) << ' ' << (-u+(n*j)) << ' ' << (u-(n*(i+1))) << endl;

			fileB << (-u) << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*(i+1))) << endl;
			fileB << (-u) << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*i)) << endl;
			fileB << (-u) << ' ' << (-u+(n*j)) << ' ' << (u-(n*(i+1))) << endl;



			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*j)) << ' ' << u << endl;
			fileB << (u-(n*i)) << ' ' << (-u+(n*j)) << ' ' << u << endl;
			fileB << (u-(n*i)) << ' ' << (-u+(n*(j+1))) << ' ' << u << endl;

			fileB << (u-(n*i)) << ' ' << (-u+(n*(j+1))) << ' ' << u << endl;
			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*(j+1))) << ' ' << u << endl;
			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*j)) << ' ' << u << endl;


			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*j)) << ' ' << (-u) << endl;
			fileB << (u-(n*i)) << ' ' << (-u+(n*j)) << ' ' << (-u) << endl;
			fileB << (u-(n*i)) << ' ' << -(u+(n*(j+1))) << ' ' << (-u) << endl;

			fileB << (u-(n*i)) << ' ' << (-u+(n*(j+1))) << ' ' << (-u) << endl;
			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*(j+1))) << ' ' << (-u) << endl;
			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*j)) << ' ' << (-u) << endl;
		}
	}
	fileB.close();
}



void drawCone(float radius, float height, int slices, int stacks) {

	float angle = 2.0f*M_PI/slices;
	float somaAng = 0;	
	float h = height/2;

	ofstream fileC ("cone.3d", ios::trunc);

	for(int i = 0; i <= slices; i++){
		fileC << "0 " << " 0 " << " 0" << endl;
		fileC << (sin(somaAng)*radius) << " 0 " << (cos(somaAng)*radius) << endl;
		somaAng -= angle;
		fileC << (sin(somaAng)*radius) << " 0 " << (cos(somaAng)*radius) << endl;
	}


	for(int j= 0; j < stacks; j++){
		for(int i = 0; i <= slices; i++){
			fileC << (sin(somaAng)*(radius-(radius/stacks)*(j+1))) << ' ' << ((height/stacks)*(j+1)) << ' ' << (cos(somaAng)*(radius-(radius/stacks)*(j+1))) << endl;
			fileC << (sin(somaAng)*(radius-(radius/stacks)*j)) << ' ' << ((height/stacks)*j) << ' ' << (cos(somaAng)*(radius-(radius/stacks)*j)) << endl;
			somaAng += angle;
			fileC << (sin(somaAng)*(radius-(radius/stacks)*j)) << ' ' << ((height/stacks)*j) << ' ' << (cos(somaAng)*(radius-(radius/stacks)*j)) << endl;
		}
		for(int i = 0; i <= slices; i++){
			fileC << (sin(somaAng)*(radius-(radius/stacks)*(j+1))) << ' ' << ((height/stacks)*(j+1)) << ' ' << (cos(somaAng)*(radius-(radius/stacks)*(j+1))) << endl;
			somaAng += angle;
			fileC << (sin(somaAng)*(radius-(radius/stacks)*j)) << ' ' << ((height/stacks)*j) << ' ' << (cos(somaAng)*(radius-(radius/stacks)*j)) << endl;
			fileC << (sin(somaAng)*(radius-(radius/stacks)*(j+1))) << ' ' << ((height/stacks)*(j+1)) << ' ' << (cos(somaAng)*(radius-(radius/stacks)*(j+1))) << endl;
		}
	}
	fileC.close();
}



int main (){

    drawPlano(3, 3);

    drawBox(3, 3);

	drawCone(3, 3, 4, 3);

    return 0;
}