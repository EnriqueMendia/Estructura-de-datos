//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FORM_PILA_Puntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Pila *P;
//---------------------------------------------------------------------------
void Pila::Mostrar()
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
}
//-----------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	P = new Pila();
    ShowMessage("PILA CREADA");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int elem = StrToInt(Edit1->Text);

	P->Meter(elem);

    Edit1->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    P->Mostrar();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	delete(P);
	Close();
}
//---------------------------------------------------------------------------
