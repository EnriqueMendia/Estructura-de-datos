//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FORM_Lista_Puntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
void ListaPtr::Mostrar()
{
	TCanvas *Canvas = Form1->Canvas;
	Canvas->Font->Size = 24;
	String list = "";
	int LF = Canvas->TextWidth("< ");

	Canvas->Font->Color = clRed;
	Canvas->TextOut(300, 100, "< ");

	if (!vacia()) {
		for (Direccion i = primero(); i != fin(); i = siguiente(i)) {
			list = list + IntToStr(recupera(i))+" , ";
		}
		list = list + IntToStr(recupera(fin()));
		Canvas->TextOut(300+LF, 100, list);
	}

	LF = LF + Canvas->TextWidth(list);
	Canvas->TextOut(300+LF, 100, " >");
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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
	int elem = StrToInt(Edit1->Text);
	L->inserta_primero(elem);
	Edit1->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int elem = StrToInt(Edit2->Text);
	L->inserta_ultimo(elem);
	Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Repaint();
	L->Mostrar();
}
//---------------------------------------------------------------------------

