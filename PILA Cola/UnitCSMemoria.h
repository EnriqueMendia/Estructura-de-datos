//---------------------------------------------------------------------------

#ifndef UnitCSMemoriaH
#define UnitCSMemoriaH
//---------------------------------------------------------------------------
#include <string>
#include <iostream>
#include <vcl.h>


using namespace std;

const int MAX = 10000;
const int NULO = -1;

typedef int TipoDato;
typedef int Direccion;
typedef float TipoElemento;

struct NodoM{
	TipoDato dato;
	string id;
	Direccion link;
};

class CSMemoria{
	private:
		NodoM *MEM;
		Direccion Libre;

	public:
		CSMemoria();
		Direccion New_espacio(string cadena);
		void Delete_espacio(Direccion dir);
		int Espacio_disponible();
		int Espacio_ocupado();
		void Poner_dato(Direccion dir, string cadena_id, TipoDato valor);
		TipoDato Obtener_dato(Direccion dir, string cadena_id);
		bool dir_libre(Direccion dir);
		void Mostrar(int pri, int ult);
};

//---Copiar y Pegar en el .cpp del formulario---//

/*void CSMemoria::Mostrar(int pri, int ult)
{
	int pos_x = 400;
	int pos_y = 10;
	TCanvas *Canvas = Form1->Canvas;
	Canvas->Font->Size = 10;
	Canvas->Font->Color = clBlack;
	int ancho = Canvas->TextWidth("1234567890");
	int alto = Canvas->TextHeight("0");
	int i = 0;
	Canvas->Pen->Style = psClear;
	Canvas->Brush->Color = Form1->Color;
	Canvas->Rectangle(pos_x, pos_y, pos_x + ancho*4 + 2, pos_y + alto*(ult-pri+5));
	Canvas->Brush->Style = bsClear;
	while (i<4){
		switch (i) {
			case 0: Canvas->TextOut(pos_x + ancho*i, pos_y, "    DIR");
					Canvas->Brush->Color = clWhite;
					Canvas->Pen->Style = psClear;
					break;
			case 1: Canvas->TextOut(pos_x + ancho*i, pos_y, "    DATO");
					Canvas->Brush->Color = clLime;
					break;
			case 2: Canvas->TextOut(pos_x + ancho*i, pos_y, "      ID");
					Canvas->Brush->Color = clYellow;
					break;
			case 3: Canvas->TextOut(pos_x + ancho*i, pos_y, "    LINK");
					Canvas->Brush->Color = clYellow;
					break;
		default:
			break;
		}
		Canvas->TextOut(pos_x + ancho*i, pos_y, "");
		Canvas->Rectangle(pos_x + ancho*i, pos_y + alto,pos_x +ancho*(i+1), pos_y + alto+alto*(ult-pri+1));
		Canvas->Pen->Style = psSolid;
		Canvas->Brush->Style = bsClear;
		i++;
	}

	for (i = 1; i <= ult-pri; i++) {
		Canvas->MoveTo(pos_x + ancho, pos_y + alto*(i+1));
		Canvas->LineTo(pos_x + ancho*4, pos_y + alto*(i+1));
	}

	for (i = 0; i <= ult-pri; i++) {
		Canvas->TextOut(pos_x + 30, pos_y + alto*(i+1), pri+i);
		Canvas->TextOut(pos_x + 10 + ancho, pos_y + alto*(i+1), MEM[pri+i].dato);
		Canvas->TextOut(pos_x + 10 + ancho*2, pos_y + alto*(i+1), String(MEM[pri+i].id.c_str()));
		Canvas->TextOut(pos_x + 10 + ancho*3, pos_y + alto*(i+1), MEM[pri+i].link);
	}


	Canvas->TextOut(pos_x + 20, pos_y + 20+alto*(i+1), "LIBRE = "+IntToStr(Libre));
}*/

#endif
