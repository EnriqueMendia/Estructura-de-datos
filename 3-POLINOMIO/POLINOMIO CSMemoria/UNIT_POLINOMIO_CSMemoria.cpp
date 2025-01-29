//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_POLINOMIO_CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Direccion Polinomio::BuscarExponente(int Exp)
{
	Direccion Dir = Ptr_Poli;

	if (Dir != NULO) {
		Direccion dirEx = NULO;

		while (Dir != NULO && dirEx == NULO) {
			if (M->Obtener_dato(Dir, "->Exp") == Exp) {
				dirEx = Dir;
			}
			Dir = M->Obtener_dato(Dir, "->Sig");
		}

		return dirEx;
	} else {
		return Dir;
	}
}

Direccion Polinomio::BuscarTerminoN(int I)
{
	Direccion Dir = Ptr_Poli;

	if (Dir != NULO) {
		Direccion dirTer = NULO;
		int Nt = 0;

		while (Dir != NULO && dirTer == NULO) {
			Nt += 1;
			if (Nt == I) {
				dirTer = Dir;
			}
			Dir = M->Obtener_dato(Dir, "->Sig");
		}

		return dirTer;
	} else {
		// Lanza una excepción o maneja el caso donde no existen términos
		throw runtime_error("No existen términos.");
	}
}

//---------------------------------------------------------------------------
Polinomio::Polinomio(CSMemoria *F)
{
	M = F;
	Nt = 0;
	Ptr_Poli = NULO;
}

bool Polinomio::EsCero()
{
	return (Nt == 0);
}

int Polinomio::Grado()
{
	Direccion Dir = Ptr_Poli;

	if (Dir != NULO) {
		int MaxG = M->Obtener_dato(Dir, "->Exp");

		while (Dir != NULO) {
			if (M->Obtener_dato(Dir, "->Exp") > MaxG) {
				MaxG = M->Obtener_dato(Dir, "->Exp");
			}
			Dir = M->Obtener_dato(Dir, "->Sig");
		}

		return MaxG;
	} else {
		// Lanza una excepción o maneja el caso donde no existe ningún término
		throw std::runtime_error("No existe ningún término en el polinomio.");
	}
}

int Polinomio::Coeficiente(int Exp)
{
	Direccion Dir = BuscarExponente(Exp);

	if (Dir != NULO) {
		return M->Obtener_dato(Dir, "->Coef");
	} else {
		// Lanza una excepción o maneja el caso donde no existe ese término
		throw std::runtime_error("No existe ese término en el polinomio.");
	}
}

void Polinomio::AsignarCoeficiente(int Coef, int Exp)
{
	Direccion Dir = BuscarExponente(Exp);

	if (Dir != NULO) {
		M->Poner_dato(Dir, "->Coef", Coef);

		if (Coef == 0) {
			// Lógica para eliminar el nodo `Dir`
			M->Delete_espacio(Dir);
		}
	} else {
		// Maneja el caso donde no existe ese término
		throw std::runtime_error("No existe ese término en el polinomio.");
	}
}

void Polinomio::Poner_Termino(int Coef, int Exp)
{
	Direccion existe = BuscarExponente(Exp);

	if (existe == NULO) {
		Direccion aux = M->New_espacio("Coef,Exp,Sig");

		if (aux != NULO) {
			M->Poner_dato(aux, "->Coef", Coef);
			M->Poner_dato(aux, "->Exp", Exp);
			M->Poner_dato(aux, "->Sig", Ptr_Poli);
			Ptr_Poli = aux;
			Nt++;
		} else {
			// Manejo de error por falta de espacio en memoria
			throw std::runtime_error("Error: no hay espacio en memoria.");
		}
	} else {
		int NuevoCoef = M->Obtener_dato(existe, "->Coef") + Coef;
		M->Poner_dato(existe, "->Coef", NuevoCoef);

		if (NuevoCoef == 0) {
			// Lógica para eliminar el nodo si `NuevoCoef` es 0
			M->Delete_espacio(existe);
			Nt--;
		}
	}
}

int Polinomio::Numero_Terminos()
{
	return Nt;
}

int Polinomio::Exponente(int NroTer)
{
	Direccion dir = BuscarTerminoN(NroTer);

	if (dir != NULO) {
		return M->Obtener_dato(dir, "->Exp");
	} else {
		// Maneja el caso donde no existe ese término
		throw std::runtime_error("No existe ese término en el polinomio.");
	}
}

void Polinomio::Suma(Polinomio *P1, Polinomio *P2)
{
	if (!EsCero()) {
		for (int i = 1; i <= Numero_Terminos(); i++) {
			Poner_Termino(-Coeficiente(Exponente(i)), Exponente(i));
		}
	}

	// Sumar los términos de p1
	for (int i = 1; i <= P1->Numero_Terminos(); ++i) {
		int ex = P1->Exponente(i);
		int co = P1->Coeficiente(ex);
		Poner_Termino(co, ex);
	}

	// Sumar los términos de p2
	for (int i = 1; i <= P2->Numero_Terminos(); ++i) {
		int ex = P2->Exponente(i);
		int co = P2->Coeficiente(ex);
		Poner_Termino(co, ex);
	}
}

void Polinomio::Resta(Polinomio *P1, Polinomio *P2)
{
    if (!EsCero()) {
		for (int i = 1; i <= Numero_Terminos(); i++) {
			Poner_Termino(-Coeficiente(Exponente(i)), Exponente(i));
		}
	}

	// Añadir los términos de p1
	for (int i = 1; i <= P1->Numero_Terminos(); ++i) {
		int ex = P1->Exponente(i);
		int co = P1->Coeficiente(ex);
		Poner_Termino(co, ex);
	}

	// Restar los términos de p2
	for (int i = 1; i <= P2->Numero_Terminos(); ++i) {
		int ex = P2->Exponente(i);
		int co = P2->Coeficiente(ex) * -1;
		Poner_Termino(co, ex);
	}
}

void Polinomio::Multiplicacion(Polinomio *P1, Polinomio *P2)
{
    if (!EsCero()) {
		for (int i = 1; i <= Numero_Terminos(); i++) {
			Poner_Termino(-Coeficiente(Exponente(i)), Exponente(i));
		}
	}

	// Iterar sobre cada término de p1
	for (int i = 1; i <= P1->Numero_Terminos(); ++i) {
		int ex1 = P1->Exponente(i);
		int co1 = P1->Coeficiente(ex1);

		// Iterar sobre cada término de p2
		for (int j = 1; j <= P2->Numero_Terminos(); ++j) {
			int ex2 = P2->Exponente(j);
			int co2 = P2->Coeficiente(ex2);

			// Multiplicar coeficientes y sumar exponentes
			int nuevoCoef = co1 * co2;
			int nuevoEx = ex1 + ex2;

			// Añadir el término resultante al polinomio
			Poner_Termino(nuevoCoef, nuevoEx);
		}
	}
}
