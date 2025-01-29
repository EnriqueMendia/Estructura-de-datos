//---------------------------------------------------------------------------

#ifndef UNIT_PILA_ListaPTRH
#define UNIT_PILA_ListaPTRH
//---------------------------------------------------------------------------

#include "UNIT_Lista_Puntero.h"

typedef int TipoElemento;

class Pila{
	private:
		ListaPtr *L;

	public:
		Pila();
		Pila(ListaPtr *F);
		bool Vacia();
		void Meter(TipoElemento E);
		void Sacar(TipoElemento &E);
		TipoElemento Cima();

        void Mostrar();
};

#endif
