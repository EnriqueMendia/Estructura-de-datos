//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_PILA_Puntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Pila::Pila()
{
	Tope = nullptr;
}

bool Pila::Vacia()
{
	return (Tope == nullptr);
}

void Pila::Meter(TipoElemento E)
{
	Direccion aux = new Nodo;
	if (aux != nullptr) {
		aux->Elemento = E;
		aux->Sig = Tope;
		Tope = aux;
	}
	else
		throw new Exception("ERROR: NO EXISTE ESPACIO EN MEMORIA");
}

void Pila::Sacar(TipoElemento &E)
{
	if (Vacia())
		throw new Exception("ERROR: PILA VACIA");

	else{
		Direccion x = Tope;
		E = Tope->Elemento;
		Tope = Tope->Sig;
		delete(x);
	}
}

TipoElemento Pila::Cima()
{
	if (Vacia())
		throw new Exception("ERROR: PILA VACIA");

	else
		return Tope->Elemento;
}