#include <iostream>
#include <string>
#include "./cliente.h"
#include "./conta.h"
#include "./contaCorrente.h"
#include "./contaPoupanca.h"

using namespace std;

int main(int argc, char** argv) {
	//Clientes
	Cliente cli1("Roberto"), cli2("Eduardo"), cli3("Roberson"), cli4("Robesvaldo");
	
	//Contas correntes
	ContaCorrente cc1(5762342, &cli1), cc2(26382423, &cli2), cc3(1789424, &cli4);
	
	//Contas poupancas
	ContaPoupanca cp1(2352525, &cli3), cp2(23523525, &cli4), cp3(6273442, &cli4);
	
	// Depositos e retiradas
	cc1.deposita(300);
	cc1.deposita(100);
	cc1.retira(200);
	
	cc2.deposita(150);
	cc2.deposita(150);
	cc2.retira(200);

	cp1.deposita(300);
	cp1.deposita(100);
	cp1.retira(200);
	
	cp2.deposita(350);
	cp2.deposita(130);
	cp2.retira(30);	
		
	//Extratos
	cout << "\n\n---------------Extratos---------------\n\n" << endl;
	cc1.extrato();
	printf("\n");
	cp3.extrato();
	printf("\n");
	cp1.extrato();
	printf("\n");
	cp2.extrato();
	cout << "\n\n--------------------------------------\n\n" <<endl;

	//transferencia de conta
	cout << "\n\n Antes da transferencia" << endl;
	cp3.deposita(1000);
	cp3.extrato();
	
	//Apos a transferencia
	cout << "\n\n Apos transferencia para conta -> " << cc3.getNumero() << endl;
	cp3.transfere(&cc3);
	cp3.extrato();
	printf("\n");
	cc3.extrato();

	//Aplicando juros em duas contas de mesmo saldo
	cout << "\n\n Aplicando juros de 100 dias em duas contas com ambas o mesmo saldo\n" << endl;
	cout << "extrato antes\n\n"<< endl;
	cc1.extrato();
	printf("\n");
	cp1.extrato();
	
	//estrutura de repeticao para aplicar os juros
	for(int i = 1; i <= 100; ++i){
		cc1.aplicaJurosDiarios();
		cp1.aplicaJurosDiarios();
	}
	
	//pos juros
	cout << "\n\nextrato depois\n\n"<< endl;
	cc1.extrato();
	printf("\n");
	cp1.extrato();
	
	return 0;
}
