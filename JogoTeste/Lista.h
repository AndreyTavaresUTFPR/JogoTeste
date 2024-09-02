#pragma once

template <class TL> class Lista
{
private:
	class Elemento
	{
	private:
		Elemento* pProx;
		TL* item;

	public:
		Elemento() :
			pProx(nullptr), item(nullptr)
		{
		}

		~Elemento()
		{
		}

		Elemento* getPProx()
		{
			return pProx;
		}

		TL* getItem()
		{
			return item;
		}

		void setPProx(Elemento* pProx)
		{
			this->pProx = pProx;
		}

		void setItem(TL* item)
		{
			this->item = item;
		}
	};

	Elemento* pPrimeiro;
	Elemento* pUltimo;
	int len;

public:
	Lista() :
		pPrimeiro(nullptr), pUltimo(nullptr), len(0)
	{
	}

	~Lista()
	{
		clear();
	}

	int getLen() 
	{ 
		return len; 
	}

	TL* getItem(int posicao) 
	{
		if (posicao > len)
			return nullptr;

		Elemento* temp = pPrimeiro;

		for (int i = 0; i < posicao; i++)
		{
			temp = temp->getPProx(); //Só para diminuir um pouco o código, para posicao = 0 pula o loop e retorna o primeiro
		}

		if (temp != nullptr)
			return temp->getItem();
		return nullptr;
	}

	void push(TL* item) {
		Elemento* temp = new Elemento();
		temp->setItem(item);
		if (pPrimeiro == nullptr)
			pPrimeiro = temp;
		else 
			pUltimo->setPProx(temp);
		pUltimo = temp;
		len++;
	}

	void pop(TL* item) 
	{
		Elemento* temp = pPrimeiro;
		Elemento* tempAnt = nullptr;

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

	void clear() 
	{
		Elemento* temp = pPrimeiro;
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