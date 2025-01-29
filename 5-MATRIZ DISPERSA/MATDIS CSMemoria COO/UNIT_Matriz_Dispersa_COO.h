//---------------------------------------------------------------------------

#ifndef UNIT_Matriz_Dispersa_COOH
#define UNIT_Matriz_Dispersa_COOH
//---------------------------------------------------------------------------

#include "UNIT_PILA_CSMemoria.h"
#include "UnitCSMemoria.h"

using namespace std;

typedef int Indice;
typedef int TipoElemento;
typedef int Direccion;

class MatD{
	private:
		CSMemoria* M;
		Direccion PtrMatD;
		int rep;
		int dimF;
		int dimC;

		Direccion PtrDato;

		bool EsValido(float fila, float col, TipoElemento valor);
		bool encontrarVacia(float &fila, float &columna);

	public:

		MatD();
		MatD(CSMemoria* F);
		void Dimensionar(int nf,int nc);
		int Dimension_Fila();
		int Dimension_Columna();
		void Poner(Indice f, Indice c, TipoElemento valor);
		TipoElemento Elemento(Indice f, Indice c);
		void Definir_Valor_Repetido(TipoElemento valor);

		Direccion Buscar(Indice f, Indice c);
		void Eliminar(Direccion dir);

		void Mostrar();

		void GuardarDato(Indice f, Indice c, Pila *R);
		void CargarDato(Pila *R);

		bool EsSudoku();
		String EsSudoku2();

		void Sudokear();

		void Backtrack(Pila *P, Pila *R);

};

//-----------COPIAR Y PEGAR EN EL CPP DEL FORMULARIO---------------//
/*void MatD::Mostrar()
{
	int posX = 350;
	int posY = 20;

	TCanvas *Canvas = Form1->Canvas;

	int alto = Canvas->TextHeight("0")*2;
	int ancho = Canvas->TextWidth("0")*5;

	Canvas->Pen->Width = 1;
	Canvas->Pen->Color = clRed;

	for (int fn = 0; fn <= dimF ; fn++) {
		Canvas->MoveTo(posX , posY + fn*alto );
		Canvas->LineTo(posX + ancho*dimC , posY + fn*alto );
	}

	for (int cn = 0; cn <= dimC ; cn++) {
		Canvas->MoveTo(posX + cn*ancho , posY );
		Canvas->LineTo(posX + cn*ancho , posY + dimF*alto );
	}

	for (Indice f = 1; f <= Dimension_Fila(); f++) {
		for (Indice c = 1; c <= Dimension_Columna(); c++) {
			Canvas->TextOut( posX + ancho/5 + (c-1)*ancho ,
							 posY + 10 + (f-1)*alto , Elemento(f,c));
		}
	}
}*/

#endif
