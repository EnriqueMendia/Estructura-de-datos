//---------------------------------------------------------------------------

#ifndef UNIT_COLA_VectorV2H
#define UNIT_COLA_VectorV2H
//---------------------------------------------------------------------------
#include <Vcl.h>
#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

typedef int Elemento;

class Cola {
	private:
		int V[MAX+1];
		int Ini, Fin;

		void Desplazar(int dir);

	public:
		Cola();
		bool Vacia();
		void Poner(Elemento E);
		void Sacar(Elemento &E);
		Elemento Primero();

        void Mostrar();
};

#endif
