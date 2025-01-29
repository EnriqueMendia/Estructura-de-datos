//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FORM_CONJUNTO_CSMemoria.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

CSMemoria *M = nullptr;

Conjunto *A = nullptr;
Conjunto *B = nullptr;
Conjunto *C = nullptr;
//---------------------------------------------------------------------------
void CSMemoria::Mostrar(int pri, int ult)
{
	int pos_x = 300;
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
}

void Conjunto::Mostrar(int posX, int posY, AnsiString s)
{
	TCanvas *Canvas = Form1->Canvas;
	Canvas->Font->Size = 12;
	Canvas->Font->Color = clBlack;
	Canvas->Brush->Color = Form1->Color;

	int e[100], i, n = Cardinal();

	s = s + " {";
	if (!Vacio()) {
		for (i = Cardinal(); i > 0; i--) {
			while (true) {
				e[i] = Muestrea();
				if (Ordinal(e[i]) == 1) {
					break;
				}
			}
			Suprime(e[i]);
		}

		for (i = 1; i < n; i++) {
			Inserta(e[i]);
			s = s + " " + IntToStr(e[i]) + " ,";
		}
		Inserta(e[i]);
		s = s + " " + IntToStr(e[i]) + " }";
	}
	else
		s = s + " }";
	Canvas->TextOut(posX, posY, s);
}

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	WindowState = wsMaximized;
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
	AnsiString cad = Edit1->Text;
	M->New_espacio(cad.c_str());
	Edit1->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	int dir = StrToInt(Edit2->Text);
	M->Delete_espacio(dir);
	Edit2->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
    A = new Conjunto(M);
	Button4->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	B = new Conjunto(M);
	Button5->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	C = new Conjunto(M);
	Button6->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	AnsiString conj = Edit3->Text;
	int elem = StrToInt(Edit4->Text);
	if (conj == "A" || conj == "a") A->Inserta(elem);
	if (conj == "B" || conj == "b") B->Inserta(elem);
	if (conj == "C" || conj == "c") C->Inserta(elem);

	Edit4->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	AnsiString conj = Edit5->Text;

	if (conj == "A" || conj == "a") A->Mostrar(600, 20, "A");
	if (conj == "B" || conj == "b") B->Mostrar(600, 60, "B");
	if (conj == "C" || conj == "c") C->Mostrar(600, 100, "C");

	Edit5->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	M->Mostrar(0,25);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
    UnionC(A,B,C);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
    InterseccionC(A,B,C);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	ComplementoInter(A,B,C);
}
//---------------------------------------------------------------------------

