//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_COLA_Puntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Cola::Cola()
{
	Fin = nullptr;
	Ini = nullptr;
}

bool Cola::Vacia()
{
	return (Ini == nullptr);
}

void Cola::Poner(TipoElemento E)
{
	Direccion Aux = new Nodo;
	if (Aux != nullptr) {
		Aux->Elemento = E;
		Aux->Sig = nullptr;
		if (Vacia()) {
			Ini = Aux;
			Fin = Aux;
		}
		else{
			Fin->Sig = Aux;
			Fin = Aux;
        }
	}
	else
		throw new Exception("ERROR PONER: No existe espacio en memoria");
}

void Cola::Sacar(TipoElemento &E)
{
	if (!Vacia()) {
		E = Ini->Elemento;
		Direccion X = Ini;
		Ini = Ini->Sig;
		delete(X);
	}
	else
		throw new Exception("ERROR SACAR: Sin elementos en la cola");
}

TipoElemento Cola::Primero()
{
	if (!Vacia()) {
		return Ini->Elemento;
	}
	else
		throw new Exception("ERROR PRIMERO: Cola vacia");
}