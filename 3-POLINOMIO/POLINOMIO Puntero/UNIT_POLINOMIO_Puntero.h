//---------------------------------------------------------------------------

#ifndef UNIT_POLINOMIO_PunteroH
#define UNIT_POLINOMIO_PunteroH
//---------------------------------------------------------------------------
#include <string>
#include <iostream>

using namespace std;

struct Nodo {
	int Coef;
	int Exp;
	Nodo* Sig;

};

constexpr std::nullptr_t NULO = nullptr;
typedef Nodo* Direccion;

class Polinomio {

	private:
		//Atributos
			Direccion Ptr_Poli;
			int Nt;

		//Métodos
			Direccion BuscarExponente(int Exp);
			Direccion BuscarTerminoN(int I);

	public:
		Polinomio();
		bool EsCero();
		int Grado();
		int Coeficiente(int Exp);
		void AsignarCoeficiente(int Coef, int Exp);
		void Poner_Termino(int Coef, int Exp);
		int Numero_Terminos();
		int Exponente(int NroTer);

		void Mostrar();

		void Suma(Polinomio *P1, Polinomio *P2);
		void Resta(Polinomio *P1, Polinomio *P2);
		void Multiplicacion(Polinomio *P1, Polinomio *P2);

		void Graficar_Polinomio();

};

#endif
