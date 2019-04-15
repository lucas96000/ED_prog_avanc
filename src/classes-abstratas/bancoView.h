#ifndef _BANCO_VIEW_H_
#define _BANCO_VIEW_H_

#include "./bancoController.h"
#include <iostream>
#include <string>

using namespace std;

BancoController* bc = new BancoController();

//Conta selecionada (no momento) para realizar deposito/retirada/transferencia
ContaCorrente* contaSelecionada = NULL;

class BancoView {
	public:		
		//construtor e destrutor
		BancoView(){
		}
		
		void exibirMenu(){
			cout << "\n-------------------MENU-------------------\n" << endl; 
			cout << "1 - CADASTRAR "								 << endl;
			cout << "2 - EXIBIR "									 << endl;
			cout << "3 - SELECIONAR "								 << endl;
			cout << "4 - DEPOSITAR "								 << endl;
			cout << "5 - RETIRAR "									 << endl;
			cout << "6 - EXTRATO "									 << endl;
			cout << "7 - TRANSFERENCIA "							 << endl;
			cout << "8 - SAIR "										 << endl;
			cout << "\n------------------------------------------\n" << endl; 
		}
		
		int lerOpcao(){
			int op;
			
			cin >> op;
			
			return op;
		}
		
		void exibirCadastroConta(){
			string nome;
			int contaNum;
						
			cout << "\nNome do Cliente: "<< endl;
			cin  >> nome;			
			
			cout << "\nNumero da conta: "<< endl;
			cin  >> contaNum;
						
			if(contaNum <= 0){
				exibirMensagemErro("O numero da conta tem que ser positivo.\n");
				return;
			}			
			
			bc->cadastrarConta(nome, contaNum);
			
			exibirMensagemSucesso("\nConta criada com sucesso!\n");
		}
		
		void exibirContas(){
			cout << "\n\nLista de Contas " << endl;
			
			for(int i = 0; i < bc->getNumContas(); i++){
				ContaCorrente* cc = bc->getConta(i);
				cc->extrato();
				printf("\n");
			}
		}
		
		void selecionarConta(){	
			int contaNum;
					
			cout << "Selecionar conta: " << " (Numero da conta)\n"<< endl;
			
			cin  >> contaNum;
			
			if(contaNum <= 0){
				exibirMensagemErro("Numero de conta invalido!");
			}
			
			contaSelecionada = bc->selecionarConta(contaNum);
			
			if(contaSelecionada != NULL){
				exibirMensagemSucesso("Conta selecionada!\n");
			}
			else{
				exibirMensagemErro("Nenhuma conta encontrada com esse numero!\n");
			}
		}
		
		void exibirDeposito(){
			float valor;
			
			if(contaSelecionada == NULL){
				cout << "Eh necessario selecionar uma conta antes!" << endl;
				
				return;
			}
			
			cout << "\nValor do deposito (R$): "<< endl;
			cin  >> valor;
			
			bc->realizarDeposito(contaSelecionada, valor);
			
			exibirMensagemSucesso("Valor depositado com sucesso! \n");
		}
		
		void exibirRetirada(){
			float valor;
			
			if(contaSelecionada == NULL){
				cout << "Eh necessario selecionar uma conta antes!" << endl;
				
				return;
			}
			
			cout << "\nValor da retirada (R$): "<< endl;
			cin  >> valor;
									
			bc->realizarRetirada(contaSelecionada, valor);
			
			exibirMensagemSucesso("Valor retirado com sucesso! \n");
		}
		
		void exibirExtrato(){
			if(contaSelecionada == NULL){
				cout << "Eh necessario selecionar uma conta antes!" << endl;
				
				return;
			}
			
			bc->exibirExtrato(contaSelecionada);
		}
		
		void exibirTransferencia(){
			int contaDestino;
			float valor;
			
			if(contaSelecionada == NULL){
				cout << "Eh necessario selecionar uma conta antes!" << endl;
				
				return;
			}
			
			cout << "\nConta de Destino (Numero da conta): "<< endl;
			cin  >> contaDestino;
			
			cout << "\nValor da transferencia (R$): "<< endl;
			cin  >> valor;
			
			bc->realizarTransferencia(contaSelecionada, contaDestino, valor);
		}
		
		void exibirMensagemErro(string m){
			cout << m << "\n" << endl;
		}
		
		void exibirMensagemSucesso(string m){
			cout << m << "\n" << endl;
		}
};

#endif
