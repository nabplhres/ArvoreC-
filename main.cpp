#include "Arv.h"
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <clocale>
#include <cstdlib>
using namespace std;

int main()
{

	setlocale(LC_ALL, "Portuguese");

	char opcao;
	char botao;
	bool i;
	string aux;
	Arv a1;

	a1.iniciar();
	
	while(true)
	{
		i = 1;
		cout << "DIGITE <i> PARA INSERIR NOMES." << endl
			 << "DIGETE <m> PARA MOSTAR OS NOMES." << endl
			 << "DIGITE <p> PARA PROCURAR UM NOME." << endl
			 << "DIGITE <r> PARA REMOVER UM NOME." << endl
			 << "DIGITE <s> PARA SAIR." << endl;
		cin >> opcao;
		opcao = tolower(opcao);
		system("cls");
		switch(opcao)
		{
		case 'i':
			cout << "DIGITE OS NOMES PARA CONSTRUIR A �RVORE (f para encerrar):" << endl;
			while(true)
			{
				fflush(stdin);
				getline(cin, aux);
				if(aux == "f" || aux == "F")
					break;
				a1.inserir(aux);
			}
			system("cls");
			break;
		case 'm':
			while(i)
			{
				cout << "<a> _ PR�-ORDEM" << endl
					 << "<b> _ ORDEM" << endl
					 << "<c> _ P�S-ORDEM" << endl
					 << "<d> _ DETALHADA" << endl
					 << "<s> _ VOLTAR" << endl;
				cin >> botao;
				botao = tolower(botao);
				system("cls");
				switch(botao)
				{
				case 'a':
					a1.impr_pre();
					system("pause");
					system("cls");
					break;
				case 'b':
					a1.impr_ordem();
					system("pause");
					system("cls");
					break;
				case 'c':
					a1.impr_pos();
					system("pause");
					system("cls");
					break;
				case 'd':
					a1.mostrar_detalhes();
					system("pause");
					system("cls");
					break;
				case 's':
					i = 0;
					system("cls");
					break;
				default:
					cout << "OP��O INV�LIDA." << endl;
					continue;
				}
			}
			break;
		case 'p':
			cout << "DIGITE O NOME A SER PROCURADO (f para encerrar)" << endl;
			fflush(stdin);
			getline(cin, aux);
			if(aux == "f" || aux == "F")
			{
				system("cls");
				break;
			}
			if(a1.busca(aux) != 0)
			{
				cout << "O NOME " << aux << " FOI ENCONTRADO." << endl;
			}
			else
			{
				cout << "O NOME " << aux << " N�O FOI ENCONTRADO." << endl;
			}
			system("pause");
			system("cls");
			break;
		case 'r':
			a1.impr_ordem();
			cout << "DIGITE O NOME A SER REMOVIDO (f para encerrar)" << endl;
			fflush(stdin);
			getline(cin, aux);
			if(aux == "f" || aux == "F")
			{
				system("cls");
				break;
			}
			if(a1.remover(aux))
			{
				cout << "NOME " << aux << " REMOVIDO COM SUCESSO." << endl;
			}
			else
			{
				cout << "NOME " << aux << " N�O ENCONTRADO." << endl;
			}
			system("pause");
			system("cls");
			break;
		case 's':
			return 0;
			break;
		default:
			cout << "OP��O INV�LIDA." << endl;
		}
	}
}
