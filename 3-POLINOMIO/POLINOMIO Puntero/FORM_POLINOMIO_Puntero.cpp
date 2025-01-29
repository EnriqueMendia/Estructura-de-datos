//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FORM_POLINOMIO_Puntero.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Polinomio *Px;
Polinomio *Qx;
Polinomio *Rx;

//---------------------------------------------------------------------------

void Polinomio::Mostrar()
{
	int posX = 300;
	int posY = 20;
	TCanvas *Canvas = Form1->Canvas;
	Canvas->Font->Size = 16;
	Canvas->Font->Color = clBlack;
	int ancho = Canvas->TextWidth("P(X) = ");
	int alto = Canvas->TextHeight("0");
	Canvas->Pen->Style = psClear;
	Canvas->Brush->Color = Form1->Color;
	Canvas->Rectangle(posX, posY, posX + ancho*(Numero_Terminos()+2), posY + alto);

	Canvas->Pen->Style = psSolid;

	if (!EsCero()) {
		Canvas->TextOut(posX, posY, "P(X) = ");

		Canvas->TextOut(posX + ancho, posY, IntToStr(Coeficiente(Exponente(1)))
						+"X^"+IntToStr(Exponente(1)));

		for (int i = 2; i <= Numero_Terminos(); i++) {

			if (Coeficiente(Exponente(i)) > 0) {
				Canvas->TextOut(posX + ancho*i, posY, "+ "+IntToStr(Coeficiente(Exponente(i)))
								+"X^"+IntToStr(Exponente(i)));
			}
			else {
				Canvas->TextOut(posX + ancho*i, posY, "- "+IntToStr(-1*Coeficiente(Exponente(i)))
								+"X^"+IntToStr(Exponente(i)));
			}

		}
	}

	else {
		Canvas->TextOut(posX, posY, "P(X) = 0");
	}
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Px = new Polinomio();
    ShowMessage("Polinomio Creado");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int coef = StrToInt(Edit1->Text);
	int exp = StrToInt(Edit2->Text);

	Px->Poner_Termino(coef, exp);

	Edit1->Text = "";
	Edit2->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
    Px->Mostrar();
}
//---------------------------------------------------------------------------
