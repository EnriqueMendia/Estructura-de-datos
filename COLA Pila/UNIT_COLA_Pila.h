//---------------------------------------------------------------------------

#ifndef UNIT_COLA_PilaH
#define UNIT_COLA_PilaH
//---------------------------------------------------------------------------

#include "UNIT_PILA_CSMemoria.h"

typedef float TipoElementoT;
typedef int Direccion;

class Cola{
	private:
		Pila *P;

	public:
		Cola();
		Cola(CSMemoria *F);
		bool Vacia();
		void Poner(TipoElementoT E);
		void Sacar(TipoElementoT &E);
		TipoElementoT Primero();

		void Mostrar();
};

#endif

