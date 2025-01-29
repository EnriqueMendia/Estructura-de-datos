//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FORM_COLA_Pila.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

CSMemoria *M;
Cola *Co, *La, *Tail;
Pila *S;
//---------------------------------------------------------------------------
void CSMemoria::Mostrar(int pri, int ult)
{
	int pos_x = 300;
	int pos_y = 200;
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
		float e;
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
		Canvas->TextOut(posX + ancho*i, posY + 7, FloatToStr(e));
		Poner(e);
		i++;
		while (!(Aux->Vacia())){
			Aux->Sacar(e);
			Canvas->TextOut(posX + ancho*i, posY + 7, ","+FloatToStr(e));
			Poner(e);
			i++;
		}
	}
}

void MostrarCola2(Cola *T)
{
	int posX = 300, posY = 70;

	TCanvas *Canvas = Form1->Canvas;

	Canvas->Font->Size = 10;
	Canvas->Font->Color = clBlack;

	int ancho = Canvas->TextWidth("00000");
	int alto = Canvas->TextHeight("0")*2;

	if (!T->Vacia()) {
		Cola *Aux = new Cola();
		int i = 0;
		float e;
		while (!T->Vacia()){
			T->Sacar(e);
			Aux->Poner(e);
			i++;
		}
		i = 0;
		while (!Aux->Vacia()){
			Aux->Sacar(e);
			T->Poner(e);
			i++;
		}
		i = 0;
		while (!T->Vacia()){
			T->Sacar(e);
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
		Canvas->TextOut(posX + ancho*i, posY + 7, FloatToStr(e));
		T->Poner(e);
		i++;
		while (!(Aux->Vacia())){
			Aux->Sacar(e);
			Canvas->TextOut(posX + ancho*i, posY + 7, ","+FloatToStr(e));
			T->Poner(e);
			i++;
		}
	}
}

void MostrarCola3(Cola *T)
{
	int posX = 300, posY = 120;

	TCanvas *Canvas = Form1->Canvas;

	Canvas->Font->Size = 10;
	Canvas->Font->Color = clBlack;

	int ancho = Canvas->TextWidth("00000");
	int alto = Canvas->TextHeight("0")*2;

	if (!T->Vacia()) {
		Cola *Aux = new Cola();
		int i = 0;
		float e;
		while (!T->Vacia()){
			T->Sacar(e);
			Aux->Poner(e);
			i++;
		}
		i = 0;
		while (!Aux->Vacia()){
			Aux->Sacar(e);
			T->Poner(e);
			i++;
		}
		i = 0;
		while (!T->Vacia()){
			T->Sacar(e);
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
		Canvas->TextOut(posX + ancho*i, posY + 7, FloatToStr(e));
		T->Poner(e);
		i++;
		while (!(Aux->Vacia())){
			Aux->Sacar(e);
			Canvas->TextOut(posX + ancho*i, posY + 7, ","+FloatToStr(e));
			T->Poner(e);
			i++;
		}
	}
}

void Concatenar(Cola *Cola1, Cola *Cola2, Cola *Cola3)
{
	float E;
	Cola *Aux = new Cola();

	while (!Cola1->Vacia()) {
		Cola1->Sacar(E);
		Aux->Poner(E);
	}
	while (!Aux->Vacia()) {
		Aux->Sacar(E);
		Cola3->Poner(E);
		Cola1->Poner(E);
	}

	while (!Cola2->Vacia()) {
		Cola2->Sacar(E);
		Aux->Poner(E);
	}
	while (!Aux->Vacia()) {
		Aux->Sacar(E);
		Cola3->Poner(E);
		Cola2->Poner(E);
	}
}

bool EsPalindrome(String cad)
{
	for (int i = 1; i <= cad.Length(); i++) {
		char Letra = cad[i];
		S->Meter(Letra);
        Co->Poner(Letra);
	}

	bool ok = true;

	while ((!Co->Vacia()) && (ok)) {
		float elemPila, elemCola;
		S->Sacar(elemPila);
		Co->Sacar(elemCola);
		if (elemPila != elemCola)
			ok = false;
	}

    return ok;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
    WindowState = wsMaximized;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Co->Mostrar();
	MostrarCola2(La);
	MostrarCola3(Tail);
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
	int dir = StrToInt(Edit2->Text);

	M->Delete_espacio(0);

	Edit2->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int elem = StrToInt(Edit3->Text);

	Co->Poner(elem);

	Edit3->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	M = new CSMemoria();
    S = new Pila(M);

	Button1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Co = new Cola(M);
	Button4->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	M->Mostrar(0,20);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button9Click(TObject *Sender)
{
	Concatenar(Co,La,Tail);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	int elem = StrToInt(Edit4->Text);

	La->Poner(elem);

	Edit4->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	La = new Cola(M);
    Button11->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	Tail = new Cola(M);
    Button12->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	if (EsPalindrome(Edit5->Text))
		ShowMessage("La Palabra: "+Edit5->Text+" -Es Palindrome");
	else
        ShowMessage("La Palabra: "+Edit5->Text+" -No Es Palindrome");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

