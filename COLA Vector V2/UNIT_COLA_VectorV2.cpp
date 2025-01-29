//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_COLA_VectorV2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
void Cola::Desplazar(int dir)
{
	for (int i = dir; i < Fin; i++) {
		V[i] = V[i+1];
	}
}

//---------------------------------------------------------------------------
Cola::Cola()
{
	Fin = 0;
	Ini = 1;
}

bool Cola::Vacia()
{
	return (Ini > Fin);
}

void Cola::Poner(Elemento E)
{
	if (Fin < MAX) {
		Fin++;
		V[Fin] = E;
	}
}

void Cola::Sacar(Elemento &E)
{
	if (!Vacia()) {
		E = V[1];
		Desplazar(1);
		Fin--;
	}
}

Elemento Cola::Primero()
{
	if (!Vacia()) {
		return V[1];
	}
	else
        throw;
}