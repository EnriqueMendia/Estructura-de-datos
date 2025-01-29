//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "FORM_Matriz_Dispersa_CSR.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

CSMemoria *M;
MatD *MD;
Pila *P, *R;

//---------------------------------------------------------------------------
void CSMemoria::Mostrar(int pri, int ult)
{
	int pos_x = 1000;
	int pos_y = 0;
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
			case 0: Canvas->TextOut(pos_x + ancho*i, pos_y, "   DIR");
					Canvas->Brush->Color = clWhite;
					Canvas->Pen->Style = psClear;
					break;
			case 1: Canvas->TextOut(pos_x + ancho*i, pos_y, "   DATO");
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
		Canvas->MoveTo(pos_x + ancho, pos_y + alto+alto*i);
		Canvas->LineTo(pos_x + ancho*4, pos_y + alto+alto*i);
	}

	for (i = 0; i <= ult-pri; i++) {
		Canvas->TextOut(pos_x + 30, pos_y + alto+alto*i, pri+i);
		Canvas->TextOut(pos_x + 10 + ancho, pos_y + alto+alto*i, MEM[pri+i].dato);
		Canvas->TextOut(pos_x + 10 + ancho*2, pos_y + alto+alto*i, String(MEM[pri+i].id.c_str()));
		Canvas->TextOut(pos_x + 10 + ancho*3, pos_y + alto+alto*i, MEM[pri+i].link);
	}


	Canvas->TextOut(pos_x + 20, pos_y + alto+alto*(i+1), "LIBRE = "+IntToStr(Libre));
}

void MatD::Mostrar()
{
	int posX = 500;
	int posY = 20;

	TCanvas *Canvas = Form1->Canvas;

    Canvas->Font->Size = 10;
	Canvas->Font->Color = clBlack;

	int alto = Canvas->TextHeight("0")*2;
	int ancho = Canvas->TextWidth("0")*5;

	Canvas->Pen->Width = 0;
	Canvas->Pen->Color = clBlack;

	if ((dimF == 9) && (dimC == 9)) {
		for (int i = 0; i <= 2; i++){
			for (int j = 0; j <= 2; j++) {
				if (((i+j)%2) == 0)
					Canvas->Brush->Color = clYellow;
				else
					Canvas->Brush->Color = clGray;
				Canvas->Pen->Style = psClear;
				Canvas->Rectangle(posX+ancho*3*j, posY+alto*3*i,
								  posX+ancho*3*(j+1), posY+alto*3*(i+1));
			}
		}
	}else{
		Canvas->Pen->Style = psClear;
		Canvas->Brush->Color = Form1->Color;
		Canvas->Rectangle(posX, posY, posX + ancho*dimC + 2, posY + alto*dimF+2);
	}
	Canvas->Pen->Style = psSolid;
	Canvas->Pen->Width = 1;
	Canvas->Brush->Style = bsClear;

	for (int fn = 0; fn <= dimF ; fn++) {
		Canvas->MoveTo(posX , posY + fn*alto );
		Canvas->LineTo(posX + ancho*dimC , posY + fn*alto );
	}

	for (int cn = 0; cn <= dimC ; cn++) {
		Canvas->MoveTo(posX + cn*ancho , posY );
		Canvas->LineTo(posX + cn*ancho , posY + dimF*alto );
	}

	for (Indice f = 1; f <= Dimension_Fila(); f++) {
		for (Indice c = 1; c <= Dimension_Columna(); c++) {
			Canvas->TextOut( posX + ancho/5 + (c-1)*ancho ,
							 posY + 10 + (f-1)*alto , Elemento(f,c));
		}
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
	string cadena = string(AnsiString(Edit1->Text).c_str());
	M->New_espacio(cadena);

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
	MD = new MatD(M);
	Button4->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
	int Rows = StrToInt(Edit3->Text);
	int Cols = StrToInt(Edit4->Text);

	MD->Dimensionar( Rows , Cols );

	Edit3->Text = "";
	Edit4->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
	int valor = StrToInt(Edit5->Text);

	MD->Definir_Valor_Repetido(valor);

	Edit5->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
	int Row = StrToInt(Edit6->Text);
	int Col = StrToInt(Edit7->Text);
	int x = StrToInt(Edit8->Text);

	MD->GuardarDato(Row, Col , R);
	MD->Poner( Row , Col , x);

	Edit6->Text = "";
	Edit7->Text = "";
	Edit8->Text = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
	MD->Mostrar();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button11Click(TObject *Sender)
{
	MD->CargarDato(R);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button10Click(TObject *Sender)
{
	/*bool S = MD->EsSudoku();
	if (S)
		ShowMessage("La Matriz SI cumple con las Condiciones de Sudoku");
	else
		ShowMessage("La Matriz NO cumple con las Condiciones de Sudoku");
	*/
	if (!(MD->EsSudoku2() == ""))
		ShowMessage(MD->EsSudoku2());
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
	for (int i = 1; i <= MD->Dimension_Fila(); i++) {
		for (int j = 1; j <= MD->Dimension_Columna(); j++) {
			MD->GuardarDato(i,j,R);
		}
	}
	MD->Sudokear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	M->Mostrar(0,35);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button14Click(TObject *Sender)
{
	P = new Pila(M);
	R = new Pila(M);
	Button14->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
    MD->Backtrack(P, R);
}
//---------------------------------------------------------------------------

