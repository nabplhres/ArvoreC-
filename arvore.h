#include <iostream>
using namespace std;

#ifndef ARVORE_H
#define ARVORE_H


class Expno
{
public:
	virtual double valor() = 0;
	virtual void mostrar() = 0;
};

class Vno: public Expno
{
	double numero;
public:
	Vno(double n)
	{
		numero = n;
	}
	double valor();
	void mostrar();
};

class Sno: public Expno
{
	char simbolo;
	Expno *esquerda;
	Expno *direita;
public:
	Sno(char s, Expno* esq, Expno* dir)
	{
		simbolo = s;
		esquerda = esq;
		direita = dir;
	}
	double valor();
	void mostrar();
};

class Arv
{
	Sno *raiz;
public:
	Arv()
	{
		raiz = 0;
	}
	void iniciar(double&,double&,double&,double&);
	double valor();
	void mostrar();
};

#endif
