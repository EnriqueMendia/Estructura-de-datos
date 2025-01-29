//---------------------------------------------------------------------------

#ifndef UNIT_COLA_ListaCSMemoriaH
#define UNIT_COLA_ListaCSMemoriaH
//---------------------------------------------------------------------------

#include "UNIT_Lista_CSMemoria.h"

typedef int Elemento;

class Cola {
	private:
		ListaCSM *L;

	public:
		Cola();
		Cola(ListaCSM *F);
		bool Vacia();
		void Poner(Elemento E);
		void Sacar(Elemento &E);
		Elemento Primero();

        void Mostrar();
};

#endif
