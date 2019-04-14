#ifndef _CARRO_H_
#define _CARRO_H_

#include <iostream>
#include <string>

#include "veiculo.h"

using namespace std;

enum Cores {
	PRETO,
	BRANCO,
	CINZA
};

class Carro : public Veiculo {
	public:
		//getters 
		string  getModelo  (){ return _modelo; }
		string  getCor 	   (){ 
			switch(_cor){
				case PRETO:
					return "Preto";
					break;
				case BRANCO:
					return "Branco";
					break;
				case CINZA:
					return "Cinza";
					break;
			};	
		}
		
		//setters
		void 	setModelo  (string modelo){
			_modelo = modelo;
		}
		
		void 	setCor  (Cores cor){
			_cor = cor;
		}
		
		// construtores
		Carro(string placa = "", double peso = 0, int velocidadeMax = 0, double preco = 0, string modelo = "", Cores cor = PRETO) : 
		_modelo(modelo),
		_cor(cor),
		Veiculo (placa, peso, velocidadeMax, preco)
		{
		}	
		
		//Metodos
		void imprime(){
			Veiculo::imprime();
			cout << "modelo -> "     << getModelo() << endl;
			cout << "cor -> " 	 << getCor() 	<< endl;
		}
		
	protected:
		string _modelo;
	        Cores  _cor;
};

#endif
