#ifndef _VEICULO_H_
#define _VEICULO_H_

#include <iostream>
#include <string>

using namespace std;

class Veiculo {
	public:
		//getters 
		string  getPlaca  (){ return _placa; }
		double  getPeso   (){ return _peso; }
		int  getVelocidadeMax(){ return _velocidadeMax; }
		double  getPreco  (){ return _preco; }
		
		//setters
		void setPlaca(string placa){ 
			_placa = placa ; 
		}
	
		void setPeso(double peso){ 
			if(peso > 0){ 
				_peso = peso; 
			} 
			else{ 
				cout << "O número deve ser positivo" << endl; 
			}
		}
		
		void setVelocidadeMax(int velocidadeMax){ 
			if(velocidadeMax  > 0){ 
				_velocidadeMax = velocidadeMax; 
			} 
			else{ 
				cout << "O número deve ser positivo" << endl;
			}
		}
		
		void setPreco(double preco){ 
			if(preco    > 0){
				_preco = preco; 
			} 
			else{ 
				cout << "O número deve ser positivo" << endl; 
			} 
		}
		
		//Construtor
		Veiculo(string placa = "", double peso = 0, int velocidadeMax = 0, double preco = 0) : 
		_placa(placa),
		_peso(peso),
		_velocidadeMax(velocidadeMax),
		_preco(preco)
		{
		}
		
		//Destrutor
		virtual ~Veiculo(){}
		
		//Imprime o veiculo na tela
		virtual void imprime(){			
			cout << "placa 				-> " << getPlaca() 			<< endl;
			cout << "peso 				-> " << getPeso() 			<< " Kg" << endl;
			cout << "velocidade maxima  -> " << getVelocidadeMax() 	<< " Km/h"<< endl;
			cout << "preco 				-> " << getPreco() 			<< " R$" << endl;
		}
	
	protected:
		//Atributos
		string _placa;
		double _peso;
		int    _velocidadeMax;
		double _preco;
};

#endif
