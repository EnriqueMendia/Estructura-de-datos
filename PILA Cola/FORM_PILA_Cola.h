//---------------------------------------------------------------------------

#ifndef FORM_PILA_ColaH
#define FORM_PILA_ColaH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>

#include "UNIT_PILA_Cola.h"
#include "UNIT_DICOLA_CSMemoria.h"
#include "Funciones_Con_PILA.h"

//---------------------------------------------------------------------------
extern CSMemoria *M;
extern Pila *P;
extern Cola *CL;

class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TEdit *Edit1;
	TEdit *Edit2;
	TButton *Button8;
	TEdit *Edit3;
	TButton *Button9;
	TEdit *Edit4;
	TButton *Button10;
	TButton *Button11;
	TEdit *Edit5;
	TEdit *Edit6;
	TButton *Button12;
	TButton *Button13;
	TButton *Button14;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button6Click(TObject *Sender);
	void __fastcall Button8Click(TObject *Sender);
	void __fastcall Button9Click(TObject *Sender);
	void __fastcall Button7Click(TObject *Sender);
	void __fastcall Button10Click(TObject *Sender);
	void __fastcall Button12Click(TObject *Sender);
	void __fastcall Button13Click(TObject *Sender);
	void __fastcall Button14Click(TObject *Sender);
	void __fastcall Button11Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
