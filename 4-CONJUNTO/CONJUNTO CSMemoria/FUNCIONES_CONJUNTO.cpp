//---------------------------------------------------------------------------

#pragma hdrstop

#include "FUNCIONES_CONJUNTO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void CopiarConj(Conjunto *R, Conjunto *Copia)
{
	int e[100], i, n = R->Cardinal();

	for (i = R->Cardinal(); i > 0; i--) {
		while (true) {
			e[i] = R->Muestrea();
			if (R->Ordinal(e[i]) == 1) {
				break;
			}
		}
		R->Suprime(e[i]);
	}

	for (i = 1; i <= n; i++) {
		R->Inserta(e[i]);
		Copia->Inserta(e[i]);
	}
}

void VaciarConj(Conjunto *V)
{
	int e;
	while (!V->Vacio()) {
		e = V->Muestrea();
		V->Suprime(e);
	}
}

void UnionC(Conjunto *A, Conjunto *B, Conjunto *C)
{
	VaciarConj(C);
	Conjunto *X = new Conjunto();
	Conjunto *Y = new Conjunto();
	CopiarConj(A,X);
	CopiarConj(B,Y);
	int elem;
	while (!X->Vacio()) {
		elem = X->Muestrea();
		C->Inserta(elem);
		X->Suprime(elem);
	}
	while (!Y->Vacio()) {
		elem = Y->Muestrea();
		C->Inserta(elem);
		Y->Suprime(elem);
	}
	delete(X);
	delete(Y);
}

void InterseccionC(Conjunto *A, Conjunto *B, Conjunto *C)
{
	VaciarConj(C);
	Conjunto *X = new Conjunto();
	CopiarConj(A,X);

	while (!X->Vacio()) {
		int e = X->Muestrea();
		X->Suprime(e);
		if (A->Pertenece(e) && B->Pertenece(e)) {
			C->Inserta(e);
		}
	}

	delete(X);
}

void ComplementoInter(Conjunto *A, Conjunto *B, Conjunto *C)
{
	VaciarConj(C);
	Conjunto *X = new Conjunto();
	Conjunto *Y = new Conjunto();
	UnionC(A,B,X);
	InterseccionC(A,B,Y);

	while (!X->Vacio()) {
		int e = X->Muestrea();
		X->Suprime(e);
		if (!Y->Pertenece(e)) {
			C->Inserta(e);
		}
	}

	delete(X);
	delete(Y);
}