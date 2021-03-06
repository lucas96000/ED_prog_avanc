#ifndef _CAMINHAO_H_
#define _CAMINHAO_H_

#include <iostream>
#include <string>

using namespace std;

class Caminhao : public Veiculo {
	public:
		//getters 
		double  getCapacidade  	    (){ return _capacidade ; }
		double  getComprimento 	    (){ return _comprimento; }
		double  getAlturaMax 	    (){ return _alturaMax  ; }
		
		//setters
		void 	setCapacidade   (double capacidade){
			if(capacidade > 0){
				_capacidade = capacidade;
			}
			else{
				cout << "O numero deve ser positivo!\n" << endl;
			}
		}
		
		void 	setComprimento  (double comprimento){
			if(comprimento > 0){							
				_comprimento = comprimento;
			}
			else{
				cout << "O numero deve ser positivo!\n" << endl;
			}
		}
		
		void 	setAlturaMax    (double alturaMax){
			if(alturaMax > 0){							
				_alturaMax = alturaMax;
			}
			else{
				cout << "O numero deve ser positivo!\n" << endl;
			}
		}
		
		// construtores
		Caminhao(string placa = "", double peso = 0, int velocidadeMax = 0, double preco = 0, double capacidade = 0, double comprimento = 0, double alturaMax = 0) : 
		_capacidade(capacidade),
		_comprimento(comprimento),
		_alturaMax(alturaMax),
		Veiculo (placa, peso, velocidadeMax, preco)
		{
		}		
		
		//Metodos
		void imprime(){
			Veiculo::imprime();
			cout << "capaciadade   -> "	<< getCapacidade() 	<< " Kg" << endl;
			cout << "comprimento   -> "	<< getComprimento()     << " m"  << endl;
			cout << "altura maxima -> "     << getAlturaMax() 	<< " m"  << endl;
		}
		
	protected:
	    double _capacidade;
	    double _comprimento;
	    double _alturaMax;
};

#endif
