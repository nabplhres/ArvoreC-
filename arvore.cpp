#include <iostream>
#include "arvore.h"
using namespace std;


void Arv::iniciar(double &w, double &x, double &y, double &z)
{
	Vno* v0	= new Vno(w);
	Vno* v1 = new Vno(x);
	Vno* v2 = new Vno(y);
	Vno* v3 = new Vno(z);
	Sno* op1 = new Sno('+', v0, v1);
	Sno* op2 = new Sno('*', v2, v3);

	raiz = new Sno('/', op1, op2);
}

double Vno::valor()
{
	return numero;
}

double Sno::valor()
{
	double x = esquerda->valor();
	double y = direita->valor();

	switch(simbolo)
	{
	case '+':
		return x + y;
		break;
	case '-':
		return x - y;
		break;
	case '*':
		return x * y;
		break;
	case '/':
		return x / y;
		break;
	default:
		cout << "Operação Inválida" << endl;
	}
	return 0;
}

double Arv::valor()
{
	return raiz->valor();
}

void Arv::mostrar()
{
	if(raiz == 0)
	{
		cout << "Árvore Vazia" << endl;
	}
	else
	{
		raiz->mostrar();
	}
}

void Sno::mostrar()
{
	if(this != 0)
	{
		cout << "(";
		esquerda->mostrar();
		cout << simbolo;
		direita->mostrar();
		cout << ")";
	}
}

void Vno::mostrar()
{
	if(this != 0)
	{
		cout << numero;
	}
}
