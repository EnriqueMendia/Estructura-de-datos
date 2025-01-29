//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_PILA_Vector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Pila::Pila()
{
	Tope = 0;
}

bool Pila::Vacia()
{
	return (Tope == 0);
}

void Pila::Meter(TipoElemento E)
{
	if (Tope < MAX) {
		Tope++;
		Elementos[Tope] = E;
	}
}

void Pila::Sacar(TipoElemento &E)
{
	if (!Vacia()) {
		E = Elementos[Tope];
		Tope--;
	}
	else
		throw new Exception("ERROR: PILA VACIA");
}

TipoElemento Pila::Cima()
{
	if (!Vacia()) {
		return Elementos[Tope];
	}
	else
        throw new Exception("ERROR: PILA VACIA");
}
