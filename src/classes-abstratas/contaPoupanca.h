#ifndef _CONTA_POUPANCA_H_
#define _CONTA_POUPANCA_H_

#include "./conta.h"
#include "./cliente.h"
#include <iostream>
#include <string>

using namespace std;

class ContaPoupanca : public Conta {
	public:
		//construtor e destrutor
		ContaPoupanca(int numero, Cliente* cliente) : Conta(numero, cliente)
		{
		}
		
		//Metodos		
		virtual void extrato(){
			cout << "Conta Poupanca" << endl;
			Conta::extrato();
		}	
				
		void aplicaJurosDiarios(){
			setSaldo(getSaldo() + (getSaldo() * 0.08));
		};		
};

#endif
