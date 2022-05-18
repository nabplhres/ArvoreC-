#ifndef ARV_H
#define ARV_H

#include <iostream>
#include <string>
using namespace std;


class NoArv
{
	NoArv* esquerda;
	NoArv* direita;
	NoArv* pai;
	string valor;
public:
	friend class Arv;
	NoArv(string a)
	{
		esquerda = NULL;
		direita = NULL;
		pai = NULL;
		valor = a;
	}
	NoArv()
	{
		esquerda = NULL;
		direita = NULL;
		pai = NULL;
	}
	void inserir(string&);
	void impr_pos()const;
	void impr_pre()const;
	void impr_ordem()const;
	void mostrar_detalhes()const;
	NoArv* busca(string&);
};

class Arv
{
	NoArv* raiz;
public:
	Arv()
	{
		raiz = 0;
	}
	bool estaVazia()const;
	void inserir(string&);
	void delearv(NoArv*);
	void impr_pos()const;
	void impr_pre()const;
	void impr_ordem()const;
	void mostrar_detalhes()const;
	bool remover(string&);
	void remove_raiz();
	void iniciar();
	NoArv* busca(string&);
	~Arv();
};
#endif

