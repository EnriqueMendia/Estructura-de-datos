//---------------------------------------------------------------------------

#ifndef UNIT_Lista_VectorH
#define UNIT_Lista_VectorH
//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <vcl.h>

using namespace std;

const int MAX = 50;
const int NULO = -1;

typedef int Direccion;
typedef int TipoElemento;

class ListaV {
	private:
		TipoElemento elementos[MAX];
		int longitud;

	public:
		ListaV();
		Direccion fin();
		Direccion primero();
		Direccion siguiente(Direccion p);
		Direccion anterior(Direccion p);
		bool vacia();
		TipoElemento recupera(Direccion p);
		int LONGITUD();
		void inserta(Direccion p, TipoElemento elemento);
		void inserta_primero(TipoElemento elemento);
		void inserta_ultimo(TipoElemento elemento);
		void suprime(Direccion p);
		void modifica(Direccion p, TipoElemento elemento);

		Direccion localiza(TipoElemento E);
		void eliminaDato(TipoElemento E);
		void anula();

        void Mostrar();
};

//------------------------Copiar y Pegar en CPP del formulario--------------//

/*void ListaV::Mostrar()
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
