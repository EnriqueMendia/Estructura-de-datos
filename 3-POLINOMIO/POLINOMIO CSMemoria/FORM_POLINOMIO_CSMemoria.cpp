//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FORM_POLINOMIO_CSMemoria.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

CSMemoria *M;

Polinomio *Px;
Polinomio *Qx;
Polinomio *Rx;

//---------------------------------------------------------------------------
void CSMemoria::Mostrar(int pri, int ult)
{
	int pos_x = 300;
	int pos_y = 100;
	TCanvas *Canvas = Form1->Canvas;
	Canvas->Font->Size = 10;
    Canvas->Font->Style = TFontStyles();
	Canvas->Font->Color = clBlack;
	int ancho = Canvas->TextWidth("1234567890");
	int alto = Canvas->TextHeight("0");
	int i = 0;
    Canvas->Pen->Color = clBlack;
	Canvas->Pen->Width = 1;
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

void Polinomio::Mostrar(int posX, int posY)
{
	TCanvas *Canvas = Form1->Canvas;
	Canvas->Font->Size = 16;
    Canvas->Font->Style = TFontStyles() << fsBold;
	Canvas->Font->Color = clBlack;
	int ancho = Canvas->TextWidth("P(X) = ");
	int alto = Canvas->TextHeight("0");
	Canvas->Pen->Style = psClear;
	Canvas->Brush->Color = Form1->Color;
	Canvas->Rectangle(posX, posY, posX + ancho*(Numero_Terminos()+2), posY + alto);

	Canvas->Pen->Style = psSolid;

	if (!EsCero()) {
		AnsiString pol = "P(X) =";
		for (int i = Numero_Terminos(); i > 0; i--) {
			int exp = Exponente(i);
			int coef = Coeficiente(exp);
			if (i == Numero_Terminos())
				pol = pol + " " + IntToStr(coef) + "X^" + IntToStr(exp);
			else {
				if (coef > 0)
					pol = pol + " + " + IntToStr(coef) + "X^" + IntToStr(exp);
				else
                    pol = pol + " - " + IntToStr(-coef) + "X^" + IntToStr(exp);
			}
		}
		Canvas->TextOut(posX, posY, pol);
	}

	else {
		Canvas->TextOut(posX, posY, "P(X) = 0");
	}
}

//---------------------------------------------------------------------------
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
	Px = new Polinomio(M);
	Qx = new Polinomio(M);
    Rx = new Polinomio(M);
	Button4->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int coef = StrToInt(Edit3->Text);
	int exp = StrToInt(Edit4->Text);

	Px->Poner_Termino(coef, exp);

	Edit3->Text = "";
	Edit4->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Px->Mostrar(300, 20);
    Qx->Mostrar(300, 60);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	M->Mostrar(0, 25);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	Derivar(Px, Qx);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	float x = StrToFloat(Edit5->Text);
	x = Evaluar(Px, x);
	ShowMessage(Truncar_Cad(x,2));
	Edit5->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
	EjeCartesiano();
	Graficar_Polinomio(Px);
	Graficar_Polinomio(Qx);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
    Interseccion(Px , Qx);
}
//---------------------------------------------------------------------------

