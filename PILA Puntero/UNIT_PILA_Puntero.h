//---------------------------------------------------------------------------

#ifndef UNIT_PILA_PunteroH
#define UNIT_PILA_PunteroH
//---------------------------------------------------------------------------

#include <string>
#include <iostream>
#include <Vcl.h>

typedef int TipoElemento;

struct Nodo{
	TipoElemento Elemento;
	Nodo* Sig;
};

typedef Nodo* Direccion;

class Pila{
	private:
		Direccion Tope;

	public:
		Pila();
		bool Vacia();
		void Meter(TipoElemento E);
		void Sacar(TipoElemento &E);
		TipoElemento Cima();

        void Mostrar();
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
