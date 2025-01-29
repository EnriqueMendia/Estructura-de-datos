//---------------------------------------------------------------------------

#ifndef UNIT_PILA_CSMemoriaH
#define UNIT_PILA_CSMemoriaH
//---------------------------------------------------------------------------
#include "UnitCSMemoria.h"

typedef int Direccion;
typedef float TipoElementoP;

class Pila{
	private:
		CSMemoria *M;
		Direccion Tope;

	public:
		Pila();
		Pila(CSMemoria *F);
		bool Vacia();
		void Meter(TipoElementoP E);
		void Sacar(TipoElementoP &E);
		TipoElementoP Cima();

		void Mostrar();

		int PrioridadInfija(char c);
		int Prioridadpila(char c);
		float Evalua(float Op1, char Operador, float Op2);

		String InfijaToPostFija(String infija);
		float EvaluarPostfija(String ExpPostfija);
};

//------------COPIAR Y PEGAR EN EL CPP DEL FORMULARIO---------------//
/*void Pila::Mostrar()
{
	int posX = 300;
	int posY = 20;
	int cantP = 20;
	TCanvas *Canvas = Form1->Canvas;

	Canvas->Font->Size = 10;
	Canvas->Font->Color = clBlack;

	int ancho = Canvas->TextWidth("uUSUARIOo");
	int alto = Canvas->TextHeight("0");

	Canvas->Pen->Width = 1;

	TColor Coral = (TColor) RGB(255,180,100);

	Canvas->Brush->Color = Coral;
	Canvas->Rectangle(posX, posY, posX + ancho, posY + alto*cantP);
	Canvas->Brush->Color = clLime;
	Canvas->Rectangle(posX, posY + alto*cantP, posX + ancho, posY + alto*cantP + alto);

	Canvas->Brush->Style = bsClear;
	Canvas->TextOut(posX + 10, posY + alto*cantP, "Usuario");

	for (int i = 1; i < cantP; i++) {
		Canvas->MoveTo(posX, posY + alto*i);
		Canvas->LineTo(posX + ancho, posY + alto*i);
	}

	int j = cantP-1;
	Pila *Aux = new Pila();

	while (!Vacia()){
		int e;
		Sacar(e);
		Aux->Meter(e);
	}

	while (!Aux->Vacia()){
		int e;
		Aux->Sacar(e);
		Canvas->TextOut(posX + 10, posY + j*alto, e);
		Meter(e);
		j--;
	}

	delete(Aux);
}*/

#endif
