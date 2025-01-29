//---------------------------------------------------------------------------

#ifndef UNIT_COLA_CSMemoriaH
#define UNIT_COLA_CSMemoriaH
//---------------------------------------------------------------------------

#include "UnitCSMemoria.h"

typedef float TipoElementoC;
typedef int Direccion;

class Cola{
	private:
		CSMemoria *M;
		Direccion ini;
		Direccion fin;

	public:
		Cola();
		Cola(CSMemoria *F);
		bool Vacia();
		void Poner(TipoElementoC E);
		void Sacar(TipoElementoC &E);
		TipoElementoC Primero();

        void Mostrar();
};

#endif

