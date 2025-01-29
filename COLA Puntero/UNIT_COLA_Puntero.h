//---------------------------------------------------------------------------

#ifndef UNIT_COLA_PunteroH
#define UNIT_COLA_PunteroH
//---------------------------------------------------------------------------
#include <Vcl.h>
#include <iostream>
#include <string>

using namespace std;

typedef int TipoElemento;

struct Nodo {
	TipoElemento Elemento;
	Nodo *Sig;
};

typedef Nodo* Direccion;

class Cola {
	private:
		Direccion Ini, Fin;

	public:
		Cola();
		bool Vacia();
		void Poner(TipoElemento E);
		void Sacar(TipoElemento &E);
		TipoElemento Primero();

        void Mostrar();
};


#endif
