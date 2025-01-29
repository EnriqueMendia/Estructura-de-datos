//---------------------------------------------------------------------------

#ifndef UNIT_POLINOMIO_CSMemoriaH
#define UNIT_POLINOMIO_CSMemoriaH
//---------------------------------------------------------------------------

#include "UnitCSMemoria.h"

class Polinomio {

	private:
		//Atributos
            CSMemoria *M;
			Direccion Ptr_Poli;
			int Nt;

		//Métodos
			Direccion BuscarExponente(int Exp);
			Direccion BuscarTerminoN(int I);

	public:
		Polinomio(CSMemoria *F);
		bool EsCero();
		int Grado();
		int Coeficiente(int Exp);
		void AsignarCoeficiente(int Coef, int Exp);
		void Poner_Termino(int Coef, int Exp);
		int Numero_Terminos();
		int Exponente(int NroTer);

		void Mostrar(int posX, int posY);

		void Suma(Polinomio *P1, Polinomio *P2);
		void Resta(Polinomio *P1, Polinomio *P2);
		void Multiplicacion(Polinomio *P1, Polinomio *P2);
};

#endif
