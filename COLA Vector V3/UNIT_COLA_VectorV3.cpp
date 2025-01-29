//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_COLA_VectorV3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
int Cola::Siguiente(int dir)
{
	return ((dir % MAX)+1);
}

//---------------------------------------------------------------------------
Cola::Cola()
{
	Fin = 0;
	Ini = 1;
}

bool Cola::Vacia()
{
	return (Siguiente(Fin) == Ini);
}

void Cola::Poner(Elemento E)
{
	if (Siguiente(Siguiente(Fin)) != Ini) {
		Fin = Siguiente(Fin);
		V[Fin] = E;
	}
}

void Cola::Sacar(Elemento &E)
{
	if (!Vacia()) {
		E = V[Ini];
		Ini = Siguiente(Ini);
	}
}

Elemento Cola::Primero()
{
	if (!Vacia()) {
		return V[Ini];
	}
	else
        throw;
}
