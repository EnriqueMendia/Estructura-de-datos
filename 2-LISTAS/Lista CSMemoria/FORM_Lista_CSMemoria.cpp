//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FORM_Lista_CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

CSMemoria *M;
ListaCSM *L;
//---------------------------------------------------------------------------
void CSMemoria::Mostrar(int pri, int ult)
{
	int pos_x = 300;
	int pos_y = 100;
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

//---------------------------------------------------------------------------
void ListaCSM::Mostrar()
{
	int pos_x = 300, pos_y = 20;
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
	string cad = string(AnsiString(Edit1->Text).c_str());
	M->New_espacio(cad);
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
	L = new ListaCSM(M);
	Button4->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int e = StrToInt(Edit3->Text);
	L->inserta_primero(e);
	Edit3->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int e = StrToInt(Edit4->Text);
	L->inserta_ultimo(e);
	Edit4->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button7Click(TObject *Sender)
{
	M->Mostrar(0,30);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
	L->Mostrar();
}
//---------------------------------------------------------------------------

