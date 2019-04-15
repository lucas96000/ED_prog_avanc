#ifndef _BANCO_CONTROLLER_H_
#define _BANCO_CONTROLLER_H_

#include "./conta.h"
#include "./cliente.h"
#include "./contaPoupanca.h"
#include "./contaCorrente.h"
#include <iostream>

#define MAX_TAMANHO 100

using namespace std;

class BancoController {
	public:		
		//construtor e destrutor
		int getNumContas(){
			return _numContas;
		}
		
		ContaCorrente* getConta(int contaIndex){
			return _contas[contaIndex];
		}
		
		BancoController(){
			_numContas = 0;
		}
	
		void cadastrarConta(string nome, int contaNum){
			Cliente* cliente = new Cliente(nome);
			
			ContaCorrente* cc = new ContaCorrente(contaNum, cliente);
			
			_contas[_numContas] = cc;			
			_numContas++;
		}
		
		ContaCorrente* selecionarConta(int contaNum){
			ContaCorrente* c = NULL;
			
			for(int i = 0; i < getNumContas(); i++){
				ContaCorrente* contaAtual = getConta(i);
				
				if(contaAtual->getNumero() == contaNum){					
					c = contaAtual;
				}
			}
			
			return c;
		}
				
		void realizarDeposito(ContaCorrente* conta, float valor){
			conta->deposita(valor);
		}
		
		void realizarRetirada(ContaCorrente* conta, float valor){
			conta->retira(valor);
		}
		
		void realizarTransferencia(ContaCorrente* conta, int contaDestinoNum, float valor){
			ContaCorrente* contaDestino = selecionarConta(contaDestinoNum);
			
			if(contaDestino == NULL){
				cout << "\nErro ao selecionar conta de destino!\n" << endl;
				return;
			}		
			
			conta->transfere(contaDestino, valor);
			cout << "\nTransferencia realizada com sucesso!\n" << endl;
		}
		
		void exibirExtrato(ContaCorrente* conta){
			conta->extrato();
		}
				
	protected:
		//ContaCorrente* *_contas = new ContaCorrente*[MAX_TAMANHO];
		ContaCorrente* _contas[MAX_TAMANHO];
		int    _numContas;
};

#endif
