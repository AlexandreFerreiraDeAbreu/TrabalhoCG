#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;


void drawPlano (float l, int d, char* ficheiro){
    
    ofstream fileP (ficheiro, ios::trunc);

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




void drawBox(float l, int d, char* ficheiro){
	float n = (l/float(d));
    float u = (l/2.0f);

    ofstream fileB (ficheiro, ios::trunc);
	
	for (int j = 0; j < d; j++){
		for (int i = 0; i < d; i++){
			fileB << ((n*i)-u) << ' ' << (-u) << ' ' << ((n*j)-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << (-u) << ' ' << ((n*(j+1))-u) << endl;
			fileB << ((n*i)-u) << ' ' << (-u) << ' ' << ((n*(j+1))-u) << endl;
																						//base de baixo
			fileB << ((n*i)-u) << ' ' << (-u) << ' ' << ((n*j)-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << (-u) << ' ' << ((n*j)-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << (-u) << ' ' << ((n*(j+1))-u) << endl;



			fileB << ((n*i)-u) << ' ' << u << ' ' << ((n*j)-u) << endl;
			fileB << ((n*i)-u) << ' ' << u << ' ' << ((n*(j+1))-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << u << ' ' << ((n*(j+1))-u) << endl;
																						//base de cima
			fileB << ((n*i)-u) << ' ' << u << ' ' << ((n*j)-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << u << ' ' << ((n*(j+1))-u) << endl;
			fileB << ((n*(i+1))-u) << ' ' << u << ' ' << ((n*j)-u) << endl;



			fileB << u << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*i)) << endl;
			fileB << u << ' ' << (-u+(n*j)) << ' ' << (u-(n*i)) << endl;
			fileB << u << ' ' << (-u+(n*j)) << ' ' << (u-(n*(i+1))) << endl;
																						//lado1
			fileB << u << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*(i+1))) << endl;
			fileB << u << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*i)) << endl;
			fileB << u << ' ' << (-u+(n*j)) << ' ' << (u-(n*(i+1))) << endl;


			fileB << (-u) << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*(i+1))) << endl;
			fileB << (-u) << ' ' << (-u+(n*j)) << ' ' << (u-(n*(i+1))) << endl;
			fileB << (-u) << ' ' << (-u+(n*j)) << ' ' << (u-(n*i)) << endl;
																						//lado1 oposto
			fileB << (-u) << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*(i+1))) << endl;
			fileB << (-u) << ' ' << (-u+(n*j)) << ' ' << (u-(n*i)) << endl;
			fileB << (-u) << ' ' << (-u+(n*(j+1))) << ' ' << (u-(n*i)) << endl;



			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*j)) << ' ' << u << endl;
			fileB << (u-(n*i)) << ' ' << (-u+(n*j)) << ' ' << u << endl;
			fileB << (u-(n*i)) << ' ' << (-u+(n*(j+1))) << ' ' << u << endl;
																						//lado2
			fileB << (u-(n*i)) << ' ' << (-u+(n*(j+1))) << ' ' << u << endl;
			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*(j+1))) << ' ' << u << endl;
			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*j)) << ' ' << u << endl;


			fileB << (u-(n*i)) << ' ' << (-u+(n*(j+1))) << ' ' << (-u) << endl;
			fileB << (u-(n*i)) << ' ' << (-u+(n*j)) << ' ' << (-u) << endl;
			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*(j+1))) << ' ' << (-u) << endl;
																						//lado2 oposto
			fileB << (u-(n*i)) << ' ' << (-u+(n*j)) << ' ' << (-u) << endl;
			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*j)) << ' ' << (-u) << endl;
			fileB << (u-(n*(i+1))) << ' ' << (-u+(n*(j+1))) << ' ' << (-u) << endl;
		}
	}
	fileB.close();
}



void drawCone(float radius, float height, int slices, int stacks, char* ficheiro) {

	float angle = 2.0f*M_PI/slices;
	float somaAng = 0;	
	float h = height/2;
	int j = 0;

	ofstream fileC (ficheiro, ios::trunc);

	for(int i = 0; i <= slices; i++){
		fileC << "0 " << " 0 " << " 0" << endl;
		fileC << (sin(somaAng)*radius) << " 0 " << (cos(somaAng)*radius) << endl;
		somaAng -= angle;
		fileC << (sin(somaAng)*radius) << " 0 " << (cos(somaAng)*radius) << endl;
	}


	for(j= 0; j < stacks-1; j++){
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
	for(int i = 0; i <= slices; i++){
			fileC << (sin(somaAng)*(radius-(radius/stacks)*(j+1))) << ' ' << ((height/stacks)*(j+1)) << ' ' << (cos(somaAng)*(radius-(radius/stacks)*(j+1))) << endl;
			fileC << (sin(somaAng)*(radius-(radius/stacks)*j)) << ' ' << ((height/stacks)*j) << ' ' << (cos(somaAng)*(radius-(radius/stacks)*j)) << endl;
			somaAng += angle;
			fileC << (sin(somaAng)*(radius-(radius/stacks)*j)) << ' ' << ((height/stacks)*j) << ' ' << (cos(somaAng)*(radius-(radius/stacks)*j)) << endl;
	}

	fileC.close();
}

void drawEsfera(float radius, int slices, int stacks, char* ficheiro){

	float angleH = 2.0f*M_PI/slices;
	float angleV = M_PI/stacks;
	float somaAngH = 0;
	float somaAngV = M_PI/2;
	int j = 0;

	ofstream fileE (ficheiro, ios::trunc);


	for(j= 1; j < stacks-1; j++){

		somaAngV = M_PI/2 - (j*angleV);

		for(int i = 0; i < slices; i++){
			somaAngH = i*angleH;
			fileE << (radius*cos(somaAngV))*sin(somaAngH) << ' ' << radius*sin(somaAngV) << ' ' << (radius*cos(somaAngV))*cos(somaAngH) << endl;
			fileE << (radius*cos(somaAngV - angleV))*sin(somaAngH) << ' ' << radius*sin(somaAngV-angleV) << ' ' << (radius*cos(somaAngV - angleV))*cos(somaAngH) << endl;
			fileE << (radius*cos(somaAngV - angleV))*sin(somaAngH + angleH) << ' ' << radius*sin(somaAngV-angleV) << ' ' << (radius*cos(somaAngV - angleV))*cos(somaAngH + angleH) << endl;
		
			fileE << (radius*cos(somaAngV))*sin(somaAngH) << ' ' << radius*sin(somaAngV) << ' ' << (radius*cos(somaAngV))*cos(somaAngH) << endl;
			fileE << (radius*cos(somaAngV - angleV))*sin(somaAngH + angleH) << ' ' << radius*sin(somaAngV-angleV) << ' ' << (radius*cos(somaAngV - angleV))*cos(somaAngH + angleH) << endl;
			fileE << (radius*cos(somaAngV))*sin(somaAngH + angleH) << ' ' << radius*sin(somaAngV) << ' ' << (radius*cos(somaAngV))*cos(somaAngH + angleH) << endl;
		}
	}

	somaAngV = M_PI/2;
	for(int i = 0; i < slices; i++){
		somaAngH = i*angleH;
		fileE << (radius*cos(somaAngV))*sin(somaAngH) << ' ' << radius*sin(somaAngV) << ' ' << (radius*cos(somaAngV))*cos(somaAngH) << endl;
		fileE << (radius*cos(somaAngV - angleV))*sin(somaAngH) << ' ' << radius*sin(somaAngV-angleV) << ' ' << (radius*cos(somaAngV - angleV))*cos(somaAngH) << endl;
		fileE << (radius*cos(somaAngV - angleV))*sin(somaAngH + angleH) << ' ' << radius*sin(somaAngV-angleV) << ' ' << (radius*cos(somaAngV - angleV))*cos(somaAngH + angleH) << endl;
	}

	somaAngV = -(M_PI/2);
	for(int i = 0; i < slices; i++){
		somaAngH = -i*angleH;
		fileE << (radius*cos(somaAngV))*sin(somaAngH) << ' ' << radius*sin(somaAngV) << ' ' << (radius*cos(somaAngV))*cos(somaAngH) << endl;
		fileE << (radius*cos(somaAngV - angleV))*sin(somaAngH) << ' ' << radius*sin(somaAngV-angleV) << ' ' << (radius*cos(somaAngV - angleV))*cos(somaAngH) << endl;
		fileE << (radius*cos(somaAngV - angleV))*sin(somaAngH - angleH) << ' ' << radius*sin(somaAngV-angleV)  << ' ' << (radius*cos(somaAngV - angleV))*cos(somaAngH - angleH) << endl;
	}

	fileE.close();
}



int main(int argc, char* argv[]){

	if(std::strcmp(argv[1], "plano") == 0){
		if(argc == 5){
			drawPlano(stof(argv[2]), atoi(argv[3]), argv[4]);
		}
		else{
			printf("Número de argumentos para desenhar o plano errado\n");
		}
	}
	else if (std::strcmp(argv[1], "box") == 0){
		if(argc == 5){
			drawBox(stof(argv[2]), atoi(argv[3]), argv[4]);
		}
		else{
			printf("Número de argumentos para desenhar o cubo errado\n");
		}
	}
	else if (std::strcmp(argv[1], "cone") == 0){
		if(argc == 7){
			drawCone(stof(argv[2]), stof(argv[3]), atoi(argv[4]), atoi(argv[5]), argv[6]);
		}
		else{
			printf("Número de argumentos para desenhar o cone errado\n");
		}
	}
	else if (std::strcmp(argv[1], "sphere") == 0){
		if(argc == 6){
			drawEsfera(stof(argv[2]), atoi(argv[3]), atoi(argv[4]), argv[5]);
		}
		else{
			printf("Número de argumentos para desenhar a esfera errado\n");
		}
	}
	else{
		printf("Erro nos argumentos\n");
	}

    return 0;
}