#pragma once
#include "Elemento.h"


template <class TL> class Lista
{
private:
	Elemento<TL>* pPrimeiro;
	Elemento<TL>* pUltimo;
	int len;

public:
	Lista();
	~Lista();


	int getLen() 
	{ 
		return len; 
	}

	TL* getItem(int posicao) {
		if (posicao > len)
			return nullptr;

		Elemento<TL>* temp = pPrimeiro;

		for (int i = 0; i < posicao; i++)
		{
			temp = temp->getPProx(); //Só para diminuir um pouco o código, para posicao = 0 pula o loop e retorna o primeiro
		}

		if (temp != nullptr)
			return temp->getItem();
		return nullptr;
	}

	void push(TL* item) {
		Elemento<TL>* temp = new Elemento<TL>();
		temp->setItem(item);
		if (pPrimeiro == nullptr)
			pPrimeiro = temp;
		else 
			pUltimo->setPProx(temp);
		pUltimo = temp;
		len++;
	}

	void pop(TL* item) {
		Elemento<TL>* temp = pPrimeiro;
		Elemento<TL>* tempAnt = nullptr;

		while (temp->getItem() != item) {
			tempAnt = temp;
			temp = temp->getPProx();
		}

		if (temp == pPrimeiro) {
			pPrimeiro = temp->getPProx();
		} 
		
		else if (temp == pUltimo) {
			tempAnt->setPProx(nullptr);
			pUltimo = tempAnt;
		} 
		
		else {
			tempAnt->setPProx(temp->getPProx());
		}

		delete temp;
		len--;
	}

	void clear() {
		Elemento<TL>* temp = pPrimeiro;
		while (temp != nullptr)
		{
			pPrimeiro = pPrimeiro->getPProx();
			delete temp;
			temp = pPrimeiro;
		}
		len = 0;
		pPrimeiro = nullptr;
		pUltimo = nullptr;
	}

};


template<class TL>
inline Lista<TL>::Lista():
	len(0)
{
	pPrimeiro = nullptr;
	pUltimo = nullptr;
}


template<class TL>
inline Lista<TL>::~Lista()
{
	clear();
	len = -1;
}
