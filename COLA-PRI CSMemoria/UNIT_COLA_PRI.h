//---------------------------------------------------------------------------

#ifndef UNIT_COLA_PRIH
#define UNIT_COLA_PRIH
//---------------------------------------------------------------------------

#include "UNIT_COLA_CSMemoria.h"

const int MAXC = 3;

class ColaPri {
	private:
		Cola* VC;
		int* VF;
		int ColaAct;
		int Cant;

	public:
		ColaPri();
		bool Vacia();
		TipoElemento Primero();
		void Poner(TipoElemento E, int pri);
		void Asignar_Frecuencia_Prioridad(int frec, int pri);
		void Sacar(TipoElemento &E);
};

#endif
