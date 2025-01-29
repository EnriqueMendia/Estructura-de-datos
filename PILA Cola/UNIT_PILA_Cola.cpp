//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_PILA_Cola.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Pila::Pila()
{
	T = new Cola();
}

Pila::Pila(Cola *F)
{
	T = F;
}

bool Pila::Vacia()
{
	return (T->Vacia());
}

void Pila::Meter(TipoElemento E)
{
	Cola *aux = new Cola();
	while (!T->Vacia()) {
		float elem;
		T->Sacar(elem);
		aux->Poner(elem);
	}
	T->Poner(E);
	while (!aux->Vacia()) {
		float elem;
		aux->Sacar(elem);
		T->Poner(elem);
	}
}

void Pila::Sacar(TipoElemento &E)
{
	if (Vacia())
		throw new Exception("ERROR: PILA VACIA");

	else
		T->Sacar(E);
}

TipoElemento Pila::Cima()
{
	if (Vacia())
		throw new Exception("ERROR: PILA VACIA");

	else
		return T->Primero();
}
