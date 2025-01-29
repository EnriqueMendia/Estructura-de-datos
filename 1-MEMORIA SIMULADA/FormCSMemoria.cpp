//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FormCSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

CSMemoria *M;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void CSMemoria::Mostrar(int pri, int ult)
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
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	string s = string(AnsiString(Edit1->Text).c_str());
	M->New_espacio(s);
	Edit1->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	if (Edit3->Text != "" && Edit4->Text != ""){
		if (StrToInt(Edit3->Text) < 0 || StrToInt(Edit4->Text) > MAX) {
			throw new Exception("Direcciones fuera de rango.");
		}
		M->Mostrar(StrToInt(Edit3->Text), StrToInt(Edit4->Text));
	}
	else
		ShowMessage("Direcciones no especificadas.");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	M->Delete_espacio(StrToInt(Edit2->Text));
	Edit2->Text = "";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int dir = StrToInt(Edit5->Text), valor = StrToInt(Edit7->Text);
	string id = string(AnsiString(Edit6->Text).c_str());
	M->Poner_dato(dir, id, valor);

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
	M = new CSMemoria();
	Button1->Enabled = false;
}
//---------------------------------------------------------------------------

