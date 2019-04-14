#ifndef _CONTA_CORRENTE_H_
#define _CONTA_CORRENTE_H_

#include "./conta.h"
#include "./cliente.h"
#include <iostream>
#include <string>

using namespace std;

class ContaCorrente : public Conta {
	public:
		//construtor e destrutor
		ContaCorrente(int numero, Cliente* cliente) : Conta(numero, cliente)
		{
		}
		
		//Metodos		
		virtual void extrato(){
			cout << "Conta Corrente" << endl;
			Conta::extrato();
		}	
				
		void aplicaJurosDiarios(){
			setSaldo(getSaldo() + (getSaldo() * 0.01));
		};		
};

#endif
