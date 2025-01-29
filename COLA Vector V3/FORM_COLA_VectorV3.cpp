//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FORM_COLA_VectorV3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

Cola *CL;
//---------------------------------------------------------------------------
void Cola::Mostrar()
{
	int posX = 300, posY = 20;

	TCanvas *Canvas = Form1->Canvas;

	Canvas->Font->Size = 10;
	Canvas->Font->Color = clBlack;

	int ancho = Canvas->TextWidth("00000");
	int alto = Canvas->TextHeight("0")*2;

	if (!Vacia()) {
		Cola *Aux = new Cola();
		int i = 0;
		int e;
		while (!Vacia()){
			Sacar(e);
			Aux->Poner(e);
			i++;
		}
		i = 0;
		while (!Aux->Vacia()){
			Aux->Sacar(e);
			Poner(e);
			i++;
		}
		i = 0;
		while (!Vacia()){
			Sacar(e);
			Aux->Poner(e);
			i++;
		}

		Canvas->Pen->Style = psSolid;
		Canvas->Brush->Color = clYellow;
		Canvas->Ellipse(posX, posY, posX + ancho*2, posY + alto);
		Canvas->Pen->Style = psClear;
		Canvas->Rectangle(posX + ancho, posY, posX + ancho*(i+2), posY + alto);
		Canvas->Pen->Style = psSolid;
		Canvas->Brush->Color = Form1->Color;
		Canvas->Ellipse(posX + ancho*(i+1) , posY, posX + ancho*(i+3), posY + alto);
		Canvas->MoveTo(posX + ancho, posY);
		Canvas->LineTo(posX + ancho*(i+2), posY);
		Canvas->MoveTo(posX + ancho, posY + alto-1);
		Canvas->LineTo(posX + ancho*(i+2), posY + alto-1);
		Canvas->Pen->Style = psClear;
		Canvas->Rectangle(posX + ancho*(i+2), posY, posX + ancho*(i+3)+1, posY + alto+1);

		i = 1;
		Canvas->Brush->Style = bsClear;
		Aux->Sacar(e);
		Canvas->TextOut(posX + ancho*i, posY + 7, IntToStr(e));
		Poner(e);
		i++;
		while (!(Aux->Vacia())){
			Aux->Sacar(e);
			Canvas->TextOut(posX + ancho*i, posY + 7, ","+IntToStr(e));
			Poner(e);
			i++;
		}
	}
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	CL = new Cola();
    ShowMessage("Cola Creada");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    int elem = StrToInt(Edit1->Text);

	CL->Poner(elem);

	Edit1->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    CL->Mostrar();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

