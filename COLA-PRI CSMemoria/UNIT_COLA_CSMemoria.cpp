//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_COLA_CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Cola::Cola()
{
	M = new CSMemoria();
	ini = NULO;
	fin = NULO;
}

Cola::Cola(CSMemoria *F)
{
	M = F;
	ini = NULO;
	fin = NULO;
}

bool Cola::Vacia()
{
	return (ini == NULO);
}

void Cola::Poner(TipoElemento E)
{
	Direccion aux = M->New_espacio("Elemento,Sig");
	if (aux != NULO) {
		M->Poner_dato(aux,"->Elemento",E);
		M->Poner_dato(aux,"->Sig",NULO);
		if (Vacia()) {
			ini = aux;
			fin = aux;
		}
		else{
			M->Poner_dato(fin,"->Sig",aux);
			fin = aux;
		}
	}
	else
		throw new Exception("ERROR: NO EXISTE ESPACIO EN MEMORIA");
}

void Cola::Sacar(TipoElemento &E)
{
	if (!Vacia()) {
		E = M->Obtener_dato(ini,"->Elemento");
		Direccion X = ini;
		ini = M->Obtener_dato(ini,"->Sig");
		M->Delete_espacio(X);
	}
	else
		throw new Exception("ERROR: COLA VACIA");
}

TipoElemento Cola::Primero()
{
	if (Vacia())
		throw new Exception("ERROR: COLA VACIA");

	else
		return M->Obtener_dato(ini,"->Elemento");
}
