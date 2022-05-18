#include "Arv.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;


//IMPRESSÃO PRÉ-ORDEM
void Arv::impr_pre() const
{
	if(!estaVazia())
	{
		raiz->impr_pre();
	}
	else
	{
		cout << "A ÁRVORE ESTÁ VAZIA" << endl;
	}
	return;
}

void NoArv::impr_pre() const
{
	cout << valor << endl;
	if (esquerda != 0)
	{
		esquerda->impr_pre();
	}
	if (direita != 0)
	{
		direita->impr_pre();
	}
}//FIM DA PRÉ-ORDEM


//IMPRESSÃO EM ORDEM
void Arv::impr_ordem() const
{
	if(!estaVazia())
	{
		raiz->impr_ordem();
	}
	else
	{
		cout << "A ÁRVORE ESTÁ VAZIA" << endl;
	}
	return;
}

void NoArv::impr_ordem() const
{
	if (esquerda != 0)
	{
		esquerda->impr_ordem();
	}
	cout << valor << endl;
	if (direita != 0)
	{
		direita->impr_ordem();
	}
}//FIM DA EM ORDEM


//IMPRESSÃO PÓS-ORDEM
void Arv::impr_pos() const
{
	if(!estaVazia())
	{
		raiz->impr_pos();
	}
	else
	{
		cout << "A ÁRVORE ESTÁ VAZIA" << endl;
	}
	return;
}

void NoArv::impr_pos() const
{
	if (esquerda != 0)
	{
		esquerda->impr_pos();
	}
	if (direita != 0)
	{
		direita->impr_pos();
	}
	cout << valor << endl;
}//FIM DA PÓS-ORDEM


bool Arv::estaVazia() const
{
	if(raiz == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//INICIALIZADOR DA ÁRVORE
void Arv::iniciar()
{

	ifstream entrada;
	string nome;

	entrada.open("nomes.txt");
	if(!entrada)
	{
		return;
	}

	while(!entrada.eof())
	{
		getline(entrada, nome);
		inserir(nome);
	}
	entrada.close();
	if(!estaVazia())
	{
		cout << "ÁRVORE CONSTRUÍDA COM SUCESSO!" << endl;
		system("pause");
		system("cls");
	}
}


//INSERÇÃO DE DADOS
void Arv::inserir(string &a)
{
	if(estaVazia())
	{
		raiz = new NoArv(a);
		cout << "NOME " << a << " INSERIDO NA RAIZ." << endl;
	}
	else
		raiz->inserir(a);
}

void NoArv::inserir(string &b)
{
	if(b > this->valor)
	{
		if(this->direita == 0)
		{
			this->direita = new NoArv(b);
			this->direita->pai = this;
			cout << "NOME " << b << " INSERIDO À DIREITA DE " << this->valor << "." << endl;
		}
		else
			this->direita->inserir(b);
	}
	else if(b < this->valor)
	{
		if(this->esquerda == 0)
		{
			this->esquerda = new NoArv(b);
			this->esquerda->pai = this;
			cout << "NOME " << b << " INSERIDO À ESQUERDA DE " << this->valor << "." << endl;
		}
		else
			this->esquerda->inserir(b);
	}
	else
	{
		cout << "NOME NÃO INSERIDO. RAZÃO: REPETIDO." << endl;
		return;
	}
}//FIM DA INSERÇÃO DE DADOS


//BUSCA
NoArv* Arv::busca(string &teste)
{
	if(!estaVazia())
	{
		if(teste == raiz->valor)
		{
			cout << "1 Passagem" << endl;
			return raiz;
		}
		else if(teste > raiz->valor && raiz->direita != 0)
		{
			cout << "1 Passagem" << endl;
			return raiz->direita->busca(teste);
		}
		else if(raiz->esquerda != 0)
		{
			cout << "1 Passagem" << endl;
			return raiz->esquerda->busca(teste);
		}
	}
	return 0;
}

NoArv* NoArv::busca(string &teste)
{

	if(teste == this->valor)
	{
		cout << "1 Passagem" << endl;
		return this;
	}
	else if(teste > this->valor && this->direita != 0)
	{
		cout << "1 Passagem" << endl;
		return this->direita->busca(teste);
	}
	else if(this->esquerda != 0)
	{
		cout << "1 Passagem" << endl;
		return this->esquerda->busca(teste);
	}

	return 0;
}//FIM DA BUSCA


//EXCLUSÃO DE DADOS
bool Arv::remover(string &teste)
{

	NoArv* no = this->busca(teste);

	if(no == 0)
	{
		return false;
	}
	else if(no == raiz)
	{
		remove_raiz();
		return true;
	}
	else
	{
		if(no->direita == 0 && no->esquerda == 0)
		{
			if(no->pai->esquerda == no)
				no->pai->esquerda = 0;
			else
			{
				no->pai->direita = 0;
			}
			delete no;
			return true;
		}
		else if(no->direita == 0 && no->esquerda != 0)
		{
			no->esquerda->pai = no->pai;
			if(no->pai->esquerda == no)
				no->pai->esquerda = no->esquerda;
			else
			{
				no->pai->direita = no->esquerda;
			}
			delete no;
			return true;
		}
		else if(no->direita != 0 && no->esquerda == 0)
		{
			no->direita->pai = no->pai;
			if(no->pai->esquerda == no)
				no->pai->esquerda = no->direita;
			else
			{
				no->pai->direita = no->direita;
			}
			delete no;
			return true;
		}
		else
		{
			NoArv* aux = no->direita;
			while(aux->esquerda != 0)
				aux = aux->esquerda;
			aux->pai = no->pai;
			aux->pai->direita = aux;
			if(aux->direita == 0)
			{
				aux->direita = no->direita;
				aux->direita->pai = aux;
				aux->direita->esquerda = 0;
			}
			else
			{
				aux->direita->pai = aux->pai;
				aux->pai->esquerda = aux->direita;
				aux->direita = no->direita;
				aux->direita->pai = aux;
			}

			if(no->esquerda != 0)
			{
				aux->esquerda = no->esquerda;
				aux->esquerda->pai = aux;
			}
			delete no;
			return true;
		}
	}
}

void Arv::remove_raiz()
{
	NoArv* no;
	if(raiz->direita == 0 && raiz->esquerda == 0)
	{
		delete raiz;
		raiz = 0;
		return;
	}
	else if(raiz->direita != 0 && raiz->esquerda == 0)
	{
		no = raiz;
		raiz = raiz->direita;
		raiz->pai = 0;
		delete no;
		return;
	}
	else if(raiz->direita == 0 && raiz->esquerda != 0)
	{
		no = raiz;
		raiz = raiz->esquerda;
		raiz->pai = 0;
		delete no;
		return;
	}
	else
	{
		NoArv* aux = raiz->direita;
		no = raiz;
		while(aux->esquerda != 0)
			aux = aux->esquerda;

		aux->esquerda = raiz->esquerda;
		raiz->esquerda->pai = aux;
		aux->pai->esquerda = 0;
		if(aux->direita != 0)
		{
			aux->direita->pai = aux->pai;
			aux->pai->direita = aux->direita;
			aux->direita = raiz->direita;
			raiz->direita->pai = aux;
		}
		else if(raiz->direita != aux)
		{
			aux->direita = raiz->direita;
			raiz->direita->pai = aux;
		}
		else
		{
			aux->direita = 0;
		}
		raiz = aux;
		raiz->pai = 0;
		delete no;
	}
}//FIM DA EXCLUSÃO DE DADOS


//DESTRUTOR DA ÁRVORE
Arv::~Arv()
{
	delearv(raiz);
}

void Arv::delearv(NoArv*no)
{

	if(no != NULL)
	{
		if(no->esquerda != 0)
			delearv(no->esquerda);
		if(no->direita != 0)
			delearv(no->direita);
		delete no;
		no = NULL;
	}
}

//FUNÇÃO DE EXIBIÇÃO EM TELA DETALHADA
void Arv::mostrar_detalhes() const
{
	if(!estaVazia())
	{
		cout << raiz->valor << endl;
		if(raiz->esquerda != 0)
		{
			cout << "Filhos Esquerda: " << raiz->esquerda->valor << endl;
		}
		if(raiz->direita != 0)
		{
			cout << "       Direita : " << raiz->direita->valor << endl;
		}
		cout << endl;
		raiz->esquerda->mostrar_detalhes();
		raiz->direita->mostrar_detalhes();
	}
}

void NoArv::mostrar_detalhes() const
{
	if(this != 0)
	{
		cout << this->valor << endl;
		if(this->esquerda != 0)
		{
			cout << "Filhos Esquerda: " << this->esquerda->valor << endl;
		}
		if(this->direita != 0)
		{
			cout << "       Direita : " << this->direita->valor << endl;
		}
		cout << endl;
		this->esquerda->mostrar_detalhes();
		this->direita->mostrar_detalhes();
	}
}