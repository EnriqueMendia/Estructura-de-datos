//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FORM_PILA_ListaPTR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Pila *P;
ListaPtr *L;

//-------------------------------------------------------------------------
void ListaPtr::Mostrar()
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
}
//----------------------------------------------------------------------------
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

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	L = new ListaPtr();

	P = new Pila(L);

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
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	L->Mostrar();
}
//---------------------------------------------------------------------------
