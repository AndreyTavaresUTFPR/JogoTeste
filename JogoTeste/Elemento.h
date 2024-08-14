#pragma once
template <class TE> class Elemento
{
private:
	Elemento<TE>* pProx;
	TE* item;

public:
	Elemento();
	~Elemento();

	Elemento<TE>* getPProx() { return pProx; }
	TE* getItem() { return item; }

	void setPProx(Elemento<TE>* pProx) { this->pProx = pProx; }
	void setItem(TE* item) { this->item = item; }

};


template<class TE>
inline Elemento<TE>::Elemento()
{
	pProx = nullptr;
	item = nullptr;
}


template<class TE>
inline Elemento<TE>::~Elemento()
{
	//pProx = nullptr;
	//item = nullptr;
}
