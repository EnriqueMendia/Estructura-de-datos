//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_PILA_ListaPTR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Pila::Pila()
{
	L = new ListaPtr();
}

Pila::Pila(ListaPtr *F)
{
	L = F;
}

bool Pila::Vacia()
{
	return L->vacia();
}

void Pila::Meter(TipoElemento E)
{
	L->inserta_primero(E);
}

void Pila::Sacar(TipoElemento &E)
{
	E = L->recupera(L->primero());
	L->suprime(L->primero());
}

TipoElemento Pila::Cima()
{
	return L->recupera(L->primero());
}
