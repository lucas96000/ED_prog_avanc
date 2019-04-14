#ifndef _CONTA_H_
#define _CONTA_H_

#include "./cliente.h"
#include <iostream>
#include <string>

using namespace std;

class Conta{
	public:
		//getters
		int getNumero(){
			return _numero;
		}
		
		double getSaldo(){
			return _saldo;
		}
		
		//setters
		void setNumero(int numero){
			_numero = numero;
		}
		
		void setSaldo(float saldo){
			_saldo = saldo;
		}
		
		//construtor e destrutor
		Conta(int numero, Cliente* cliente) : 
		_numero(numero)
		{
			cout << "Criando conta " << numero << " cliente -> "<<  cliente->getNome() << endl;
			setSaldo(0);
		}
		
		virtual ~Conta(){
		}
		
		//Metodos
		void deposita(float valor){
			setSaldo(getSaldo() + valor);
		}
		
		void retira(float valor){
			setSaldo(getSaldo() - valor);
		}
		
		void transfere (Conta* conta){
			conta->setSaldo(getSaldo());
			setSaldo(0);
		}
		
		virtual void extrato(){
			cout << "Conta -> " << getNumero() << endl;
			cout << "Saldo -> " << getSaldo () << endl;
		}	
				
		virtual void aplicaJurosDiarios() = 0;		
	protected:
		int 	_numero;
		float  _saldo;
};

#endif
