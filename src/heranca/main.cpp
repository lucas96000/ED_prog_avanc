#include <iostream>
#include "./veiculo.h"
#include "./carro.h"
#include "./caminhao.h"


using namespace std;

int main(int argc, char** argv) {
	Veiculo v1("ASR6709", 1230.45, 260, 70.500), v2("BRT5368", 1500.30, 200, 50.000);
	
	cout << "------Veiculos------\n" << endl;
	printf("\n");
	v1.imprime();
	printf("\n");
	v2.imprime();
	printf("\n");
	
	Carro c1("HAI2453", 1530.45, 250, 88.500, "Polo", BRANCO), c2("UJS7892", 2030.45, 270, 80.500, "Renegade", PRETO);
		
	cout << "------Carros------\n" << endl;
	printf("\n");
	c1.imprime();
	printf("\n");
	c2.imprime();
	printf("\n");
	
	Caminhao cam1("YTU8709", 5230.45, 200, 400.500, 2000, 3.3, 2.3), cam2("IOY8926", 4530.45, 180, 700.500, 4000, 3.2, 2.5);
		
	cout << "------Caminhões------\n" << endl;
	printf("\n");
	cam1.imprime();
	printf("\n");
	cam2.imprime();
	printf("\n");	
		
	return 0;
}
