//---------------------------------------------------------------------------

#ifndef UNIT_CONJUNTO_CSMemoriaH
#define UNIT_CONJUNTO_CSMemoriaH
//---------------------------------------------------------------------------

#include "UnitCSMemoria.h"

typedef int Elemento;

// Nodo
// 		dato     Entero,
// 		Sig      Puntero a Nodo
// fin definicion

class Conjunto {
	private:
		CSMemoria *M;
		int cant;
		Direccion PtrConj;

	public:
        Conjunto();
		Conjunto(CSMemoria *F);
		bool Vacio();
		bool Pertenece(Elemento E);
		void Inserta(Elemento E);
		int Cardinal();
		int Ordinal(Elemento E);
		void Suprime(Elemento E);
		Elemento Muestrea();

		void Mostrar(int posX, int posY, AnsiString s);
};
//------------------COPIAR Y PEGAR EN EL CPP DEL FORMULARIO-----------------//
/*void Conjunto::Mostrar(int posX, int posY, AnsiString s)
{
	TCanvas *Canvas = Form1->Canvas;
	Canvas->Font->Size = 12;
	Canvas->Font->Color = clBlack;
	Canvas->Brush->Color = Form1->Color;

	int e[100], i, n = Cardinal();

	s = s + " {";
	if (!Vacio()) {
		for (i = Cardinal(); i > 0; i--) {
			while (true) {
				e[i] = Muestrea();
				if (Ordinal(e[i]) == 1) {
					break;
				}
			}
			Suprime(e[i]);
		}

		for (i = 1; i < n; i++) {
			Inserta(e[i]);
			s = s + " " + IntToStr(e[i]) + " ,";
		}
		Inserta(e[i]);
		s = s + " " + IntToStr(e[i]) + " }";
	}
	else
		s = s + " }";
	Canvas->TextOut(posX, posY, s);
}*/

#endif
