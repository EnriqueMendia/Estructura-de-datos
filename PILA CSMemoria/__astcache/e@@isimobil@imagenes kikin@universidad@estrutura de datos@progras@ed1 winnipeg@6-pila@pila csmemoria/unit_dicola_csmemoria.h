//---------------------------------------------------------------------------

#ifndef UNIT_DICOLA_CSMemoriaH
#define UNIT_DICOLA_CSMemoriaH
//---------------------------------------------------------------------------
#include "UnitCSMemoria.h"

class DiCola {
	private:
		CSMemoria *M;
		Direccion ini;
		Direccion fin;

	public:
		DiCola();
		DiCola(CSMemoria *F);
		bool Vacia();
		void Poner(TipoElemento E);
		void Sacar(TipoElemento &E);
		TipoElemento Primero();

		TipoElemento Ultimo();
		void Poner_Frente(TipoElemento E);
		void Sacar_Final(TipoElemento &E);

		void Mostrar();
};

#endif
