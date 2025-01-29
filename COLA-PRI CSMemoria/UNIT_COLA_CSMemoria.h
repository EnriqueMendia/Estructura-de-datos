//---------------------------------------------------------------------------

#ifndef UNIT_COLA_CSMemoriaH
#define UNIT_COLA_CSMemoriaH
//---------------------------------------------------------------------------

#include "UnitCSMemoria.h"

class Cola{
	private:
		CSMemoria *M;
		Direccion ini;
		Direccion fin;

	public:
		Cola();
		Cola(CSMemoria *F);
		bool Vacia();
		void Poner(TipoElemento E);
		void Sacar(TipoElemento &E);
		TipoElemento Primero();

        void Mostrar();
};

#endif

