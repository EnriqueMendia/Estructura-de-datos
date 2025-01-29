//---------------------------------------------------------------------------

#ifndef UNIT_Lista_PunteroH
#define UNIT_Lista_PunteroH
//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <vcl.h>

using namespace std;

//const int nullptr = NULL;   // si esta en la version 11, comente la constante

typedef int TipoElemento;

struct Nodo {
	TipoElemento elemento;
	Nodo* sig;
};

typedef Nodo* Direccion;

class ListaPtr {
	private:
		Direccion PtrElementos;
		int longitud;

	public:
		ListaPtr();
		Direccion fin();
		Direccion primero();
		Direccion siguiente(Direccion p);
		Direccion anterior(Direccion p);
		bool vacia();
		TipoElemento recupera(Direccion p);
		int LONGITUD();
		void inserta(Direccion p, TipoElemento E);
		void inserta_primero(TipoElemento E);
		void inserta_ultimo(TipoElemento E);
		void suprime(Direccion p);
		void modifica(Direccion p, TipoElemento E);

		Direccion localiza(TipoElemento E);
		void eliminaDato(TipoElemento E);
		void anula();

		void Mostrar();
};

//------------------------Copiar y Pegar en CPP del formulario--------------//

/*void ListaPtr::Mostrar()
{
	int pos_x = 700, pos_y = 20;
	TCanvas *Canvas = Form1->Canvas;
	Canvas->Font->Size = 24;
	String list = "";
	int LF = Canvas->TextWidth("< ");
	int alto = Canvas->TextHeight("0");
	Canvas->Brush->Color = Form1->Color;
	Canvas->Pen->Style = psClear;
	Canvas->Rectangle(pos_x, pos_y, pos_x + LF*3*LONGITUD(), pos_y + alto);

	Canvas->Font->Color = clRed;
	Canvas->TextOut(pos_x, pos_y, "< ");

	if (!vacia()) {
		for (Direccion i = primero(); i != fin(); i = siguiente(i)) {
			list = list + IntToStr(recupera(i))+" , ";
		}
		list = list + IntToStr(recupera(fin()));
		Canvas->TextOut(pos_x + LF, pos_y, list);
	}

	LF = LF + Canvas->TextWidth(list);
	Canvas->TextOut(pos_x + LF, pos_y, " >");
    Canvas->Pen->Style = psSolid;
}*/

#endif
