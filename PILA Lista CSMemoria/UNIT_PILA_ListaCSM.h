//---------------------------------------------------------------------------

#ifndef UNIT_PILA_ListaCSMH
#define UNIT_PILA_ListaCSMH
//---------------------------------------------------------------------------

#include "UNIT_Lista_CSMemoria.h"

typedef int TipoElemento;

class Pila{
	private:
		ListaCSM *L;

	public:
		Pila();
		Pila(ListaCSM *F);
		bool Vacia();
		void Meter(TipoElemento E);
		void Sacar(TipoElemento &E);
		TipoElemento Cima();

        void Mostrar();
};

#endif
