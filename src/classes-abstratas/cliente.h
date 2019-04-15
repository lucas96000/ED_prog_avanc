#ifndef _CLIENTE_H_
#define _CLIENTE_H_

#include <iostream>
#include <string>

using namespace std;

class Cliente{
	public:
		//getters
		string getNome(){
			return _nome;
		}
		
		//setters
		void setNome(string nome){
			_nome = nome;
		}
		
		//construtor e destrutor
		Cliente(string nome = "") : 
		_nome(nome){
		}
		
	protected:
		string _nome;
};

#endif
