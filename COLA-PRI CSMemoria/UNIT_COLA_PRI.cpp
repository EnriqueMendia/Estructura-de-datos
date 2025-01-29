//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_COLA_PRI.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ColaPri::ColaPri()
{
	ColaAct = 0;
	Cant = 0;
	VC = new Cola[MAXC+1];
	VF = new int[MAXC+1];
	for (int i = 1; i <= MAXC; i++) {
		VF[i] = 1;
	}
}

bool ColaPri::Vacia()
{
	for (int i = 1; i <= MAXC; i++) {
		if (!VC[i].Vacia()) {
			return false;
		}
	}
	return true;
}

TipoElemento ColaPri::Primero()
{
	if (!Vacia()) {
		if (!VC[ColaAct].Vacia()) {
			return VC[ColaAct].Primero();
		}
		else {
			ColaAct = (ColaAct+1) % (MAXC+1);
			if (ColaAct == 0) ColaAct++;
			Cant = 0;
            Primero();
        }
	}
}

void ColaPri::Poner(TipoElemento E, int pri)
{
	VC[pri].Poner(E);
}

void ColaPri::Asignar_Frecuencia_Prioridad(int frec, int pri)
{
	VF[pri] = frec;
}

void ColaPri::Sacar(TipoElemento &E)
{
	if (!Vacia()) {
		if (!VC[ColaAct].Vacia()) {
			if (Cant < VF[ColaAct]) {
				Cant++;
				VC[ColaAct].Sacar(E);
				if (Cant == VF[ColaAct]) {
					ColaAct++;
					Cant = 0;
				}
			}
		}
		else {
			ColaAct = (ColaAct+1) % (MAXC+1);
			if (ColaAct == 0) ColaAct++;
			Cant = 0;
			Sacar(E);
		}
	}
}
