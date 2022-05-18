#include<iostream>
#include<set>

using namespace std;

int main()
{
	multiset<int>A;
	set<int>::iterator a;
	int c[] = {13, 2, 6, 8, 3, 51, 2, 8};
	int busca;
	
	//INSERÇÃO DE VALORES
	for(short int i = 0; i < 8; i++)
		A.insert(c[i]);
	
	//IMPRESSÃO DE VALORES
	for(a = A.begin(); a != A.end(); ++a)
		cout << *a << " ";
	
	//BUSCA DE UM VALOR NA ÁRVORE
	cout << endl << "Digite o valor a ser buscado:" << endl;
	cin >> busca;
	if(A.find(busca) != A.end())
	{
		cout << "Valor " << busca << " encontrado." << endl;
	}	
	else
	{
		cout << "Valor " << busca << " nao encontrado." << endl;
	}
}
