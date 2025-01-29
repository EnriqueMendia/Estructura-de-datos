//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_DICOLA_CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

DiCola::DiCola()
{
	M = new CSMemoria();
	ini = NULO;
	fin = NULO;
}

DiCola::DiCola(CSMemoria *F)
{
	M = F;
	ini = NULO;
	fin = NULO;
}

bool DiCola::Vacia()
{
	return (ini == NULO);
}

void DiCola::Poner(TipoElemento E)
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

void DiCola::Sacar(TipoElemento &E)
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

TipoElemento DiCola::Primero()
{
	if (Vacia())
		throw new Exception("ERROR: COLA VACIA");

	else
		return M->Obtener_dato(ini,"->Elemento");
}

TipoElemento DiCola::Ultimo()
{
	if (Vacia())
		throw new Exception("ERROR: COLA VACIA");

	else
		return M->Obtener_dato(fin,"->Elemento");
}

void DiCola::Poner_Frente(TipoElemento E)
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
			M->Poner_dato(aux,"->Sig",ini);
			ini = aux;
		}
	}
	else
		throw new Exception("ERROR: NO EXISTE ESPACIO EN MEMORIA");
}

void DiCola::Sacar_Final(TipoElemento &E)
{
	if (!Vacia()) {
		E = M->Obtener_dato(fin,"->Elemento");
		Direccion X = fin;
		if (ini == fin) {
			ini = NULO;
			fin = NULO;
		}
		else {
			Direccion aux = ini;
			while (M->Obtener_dato(aux,"->Sig") != fin) {
				aux = M->Obtener_dato(aux,"->Sig");
			}
			fin = aux;
			M->Poner_dato(fin, "->Sig", NULO);
		}

		M->Delete_espacio(X);
	}
	else
		throw new Exception("ERROR: COLA VACIA");
}
