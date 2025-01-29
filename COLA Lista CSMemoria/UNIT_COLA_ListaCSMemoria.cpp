//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_COLA_ListaCSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Cola::Cola()
{
	L = new ListaCSM();
}

Cola::Cola(ListaCSM *F)
{
	L = F;
}

bool Cola::Vacia()
{
	return L->vacia();
}

void Cola::Poner(Elemento E)
{
	L->inserta_ultimo(E);
}

void Cola::Sacar(Elemento &E)
{
	E = L->recupera(L->primero());
	L->suprime(L->primero());
}

Elemento Cola::Primero()
{
	return L->recupera(L->primero());
}