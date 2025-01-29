//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_COLA_Pila.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Cola::Cola()
{
	P = new Pila();
}

Cola::Cola(CSMemoria *F)
{
	P = new Pila(F);
}

bool Cola::Vacia()
{
	return P->Vacia();
}

void Cola::Poner(TipoElementoT E)
{
	Pila *aux = new Pila();
	while (!P->Vacia()) {
		float f;
		P->Sacar(f);
		aux->Meter(f);
	}
	P->Meter(E);
	while (!aux->Vacia()) {
		float f;
		aux->Sacar(f);
		P->Meter(f);
	}
}

void Cola::Sacar(TipoElementoT &E)
{
	if (!Vacia()) {
		P->Sacar(E);
	}
	else
		throw new Exception("ERROR: COLA VACIA");
}

TipoElementoT Cola::Primero()
{
	if (Vacia())
		throw new Exception("ERROR: COLA VACIA");

	else {
		P->Cima();
	}
}
