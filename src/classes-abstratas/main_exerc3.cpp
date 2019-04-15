#include <iostream>
#include <string>
#include "./bancoView.h"

using namespace std;

//Opcoes do menu, enum para melhor visualizacao do codigo na parte do switch
enum MenuOps{
	CADASTRAR 	    = 1,
	LISTAR	  	    = 2,
	SELECIONAR 	    = 3,
	DEPOSITAR	    = 4,
	RETIRAR		    = 5,
	EXTRATO		    = 6,
	TRANSFERENCIA 	    = 7,
	SAIR		    = 8
};

int main(int argc, char** argv) {
	int op;
	BancoView* banco = new BancoView();
	
	do{
		banco->exibirMenu();
	
		op = banco->lerOpcao();
	
		switch(op){
			case CADASTRAR:	
				banco->exibirCadastroConta();				
				break;
				 
			case LISTAR:
				banco->exibirContas();
				break;	
					 
			case SELECIONAR:
				banco->selecionarConta();
				break;	 
				
			case DEPOSITAR:
				banco->exibirDeposito();
				break;
					 
			case RETIRAR:
				banco->exibirRetirada();
				break;	
					
			case EXTRATO:
				banco->exibirExtrato();
				break;		
				
			case TRANSFERENCIA:
				banco->exibirTransferencia();
				break;
				
			case SAIR:
				break;
				
			default:
				cout << "Opcao invalida" << endl;
				break;
		};
	} while(op != 8);

	
	return 0;
}
