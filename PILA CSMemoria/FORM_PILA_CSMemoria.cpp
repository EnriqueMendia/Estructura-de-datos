//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FORM_PILA_CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

CSMemoria *M = nullptr;
Pila *P = nullptr;

//---------------------------------------------------------------------------
void CSMemoria::Mostrar(int pri, int ult)
{
	int pos_x = 400;
	int pos_y = 20;
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
			case 0: Canvas->TextOut(pos_x + ancho*i, pos_y, "   DATO");
					Canvas->Brush->Color = clWhite;
					Canvas->Pen->Style = psClear;
					break;
			case 1: Canvas->TextOut(pos_x + ancho*i, pos_y, "     DIR");
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
		Canvas->Rectangle(pos_x + ancho*i, pos_y + 20,pos_x +ancho*(i+1), pos_y + 20+alto*(ult-pri+1));
		Canvas->Pen->Style = psSolid;
		Canvas->Brush->Style = bsClear;
		i++;
	}

	for (i = 1; i <= ult-pri; i++) {
		Canvas->MoveTo(pos_x + ancho, pos_y + 20+alto*i);
		Canvas->LineTo(pos_x + ancho*4, pos_y + 20+alto*i);
	}

	for (i = 0; i <= ult-pri; i++) {
		Canvas->TextOut(pos_x + 30, pos_y + 20+alto*i, pri+i);
		Canvas->TextOut(pos_x + 10 + ancho, pos_y + 20+alto*i, MEM[pri+i].dato);
		Canvas->TextOut(pos_x + 10 + ancho*2, pos_y + 20+alto*i, String(MEM[pri+i].id.c_str()));
		Canvas->TextOut(pos_x + 10 + ancho*3, pos_y + 20+alto*i, MEM[pri+i].link);
	}


	Canvas->TextOut(pos_x + 20, pos_y + 20+alto*(i+1), "LIBRE = "+IntToStr(Libre));
}

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
		float e;
		Sacar(e);
		Aux->Meter(e);
	}

	while (!Aux->Vacia()){
		float e;
		Aux->Sacar(e);
		Canvas->TextOut(posX + 10, posY + j*alto, e);
		Meter(e);
		j--;
	}

	delete(Aux);
}

void SWAP(Pila *&K, int Lug1, int Lug2)
{
	DiCola *Aux = new DiCola(M);
	float e;
	int i = 1;
	int Mayor = (Lug1>Lug2)?Lug1:Lug2;
	int Menor = (Lug1<Lug2)?Lug1:Lug2;
	while (i < Menor) {
		K->Sacar(e);
		Aux->Poner_Frente(e);
		i++;
	}
	K->Sacar(e);
	Aux->Poner(e);
	i++;

	while (i <= Mayor) {
		K->Sacar(e);
		Aux->Poner_Frente(e);
		i++;
	}

	i--;
	Aux->Sacar_Final(e);
	K->Meter(e);
	Aux->Sacar(e);
	Aux->Poner(e);

	while (!Aux->Vacia()) {
		i--;
		if (i == Menor) {
			Aux->Sacar_Final(e);
		}
		else {
			Aux->Sacar(e);
		}
		K->Meter(e);
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
	M = new CSMemoria();
	Button1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	string cadena = string(AnsiString(Edit1->Text).c_str());

	M->New_espacio(cadena);

	Edit1->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	P = new Pila(M);
	Button3->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	int elem = StrToInt(Edit2->Text);

	P->Meter(elem);

	Edit2->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	M->Mostrar(0,30);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	P->Mostrar();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	String s = Edit3->Text;

	Edit4->Text = P->InfijaToPostFija(s);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	String s = Edit4->Text;

	ShowMessage(P->EvaluarPostfija(s));

	Edit4->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button10Click(TObject *Sender)
{
	SWAP(P, StrToInt(Edit5->Text), StrToInt(Edit6->Text));
	Edit5->Text = "";
	Edit6->Text = "";
}
//---------------------------------------------------------------------------
