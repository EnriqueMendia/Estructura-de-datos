//---------------------------------------------------------------------------

#pragma hdrstop

#include "FUNCIONES.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)


//FUNCIONES CON MEMORIA
void Sumar(CSMemoria *F, int dir, string cad_id)
{
	F->Poner_dato(dir, cad_id, 5);
}


//FUNCIONES CON POLINOMIO
void Derivar(Polinomio *Pol, Polinomio *P1)
{
	for (int i = Pol->Numero_Terminos(); i > 0; i--) {
		int exp = Pol->Exponente(i);
		int coef = Pol->Coeficiente(exp);
        P1->Poner_Termino(coef*exp, exp-1);
	}
}

void Mostrar_Integral(Polinomio *Pol)
{
    AnsiString s = "";
	for (int i = Pol->Numero_Terminos(); i > 0; i--) {
		int ex = Pol->Exponente(i);
		int co = Pol->Coeficiente(ex);
		s = s+'('+IntToStr(co)+"X^"+IntToStr(ex+1)+")/"+IntToStr(ex+1)+'+';
	}
    Form1->Canvas->TextOut(300, 100, s+'C');
}

float Evaluar(Polinomio *Pol, float x)
{
	float r = 0;
	for (int i = 1; i <= Pol->Numero_Terminos(); i++) {
		int ex = Pol->Exponente(i);
		int co = Pol->Coeficiente(ex);
		r = r + (co*pow(x,ex));
	}
    return r;
}

AnsiString Truncar_Cad(float num, int cifras)
{
	AnsiString num_cad = FloatToStr(num), t = "";
	int pos = num_cad.Pos(',');
	if (pos > 0) {
		for (int i = 1; i <= pos+cifras; i++) {
			t += num_cad[i];
			if (i == num_cad.Length()) {
				break;
			}
		}
		num_cad = t;
	}
	return num_cad;
}

void EjeCartesiano()
{
	TCanvas *Canvas = Form1->Canvas;
	Canvas->Font->Size = 10;
	Canvas->Font->Color = clBlack;
	Canvas->Pen->Color = clBlack;

	//Lineas
	Canvas->MoveTo(EjeX-(cm*scale+scale/2), EjeY);
	Canvas->LineTo(EjeX+(cm*scale+scale/2), EjeY);
	Canvas->MoveTo(EjeX, EjeY-(cm*scale+scale/2));
	Canvas->LineTo(EjeX, EjeY+(cm*scale+scale/2));

	//Numeros
	int ancho = Canvas->TextWidth("00");
	int alto = Canvas->TextHeight("0");
	for (int i = 1; i <= cm; i++) {
		Canvas->MoveTo(EjeX+i*scale, EjeY);
		Canvas->LineTo(EjeX+i*scale, EjeY-alto);
		Canvas->TextOut(EjeX+i*scale-5, EjeY-alto*2, IntToStr(i));
		Canvas->MoveTo(EjeX-i*scale, EjeY);
		Canvas->LineTo(EjeX-i*scale, EjeY+alto);
		Canvas->TextOut(EjeX-i*scale-5, EjeY+alto, IntToStr(-i));
	}
	Canvas->MoveTo(EjeX, EjeY-scale);
	Canvas->LineTo(EjeX+ancho, EjeY-scale);
	Canvas->MoveTo(EjeX, EjeY+scale);
	Canvas->LineTo(EjeX-ancho, EjeY+scale);
	for (int i = 2; i <= cm; i++) {
		Canvas->MoveTo(EjeX, EjeY-i*scale);
		Canvas->LineTo(EjeX+ancho, EjeY-i*scale);
		Canvas->TextOut(EjeX+ancho, EjeY-i*scale-10, IntToStr(i));
		Canvas->MoveTo(EjeX, EjeY+i*scale);
		Canvas->LineTo(EjeX-ancho, EjeY+i*scale);
		Canvas->TextOut(EjeX-ancho*2, EjeY+i*scale-10, IntToStr(-i));
	}
}

void Graficar_Polinomio(Polinomio *Pol)
{
	TCanvas *Canvas = Form1->Canvas;
	Canvas->Font->Size = 10;
	Canvas->Pen->Color = clRed;
	Canvas->Pen->Width = 2;

	int max = cm*scale;
	float i;

	Canvas->MoveTo(EjeX,EjeY);
	for (i = 0; i <= cm*scale; i = i + 0.02) {
		float fx = Evaluar(Pol, i);
		if ((i*scale <= max) || (fx*scale <= max))
			Canvas->LineTo(EjeX+i*scale, EjeY-fx*scale);
		else
			break;
	}

	Canvas->MoveTo(EjeX,EjeY);
	for (i = 0; i >= -(cm*scale); i = i - 0.02) {
		float fx = Evaluar(Pol, i);
		if ((i*scale <= max) || (fx*scale <= max))
			Canvas->LineTo(EjeX+i*scale, EjeY-fx*scale);
		else
			break;
	}

}

float AbsolutoF(float e)
{
	if (e < 0) {
		e = pow(e,2)/(-e);
	}

	return e;
}

/*float Newton_Raphson(Polinomio *P1, float x)
{
	Polinomio *aux = new Polinomio(M);
	Derivar(P1, aux);
	while (!(Evaluar(P1,x) < 0.01 && Evaluar(P1, x) > -0.01)) {
		if (Evaluar(aux,x) != 0)
			x = x - (Evaluar(P1, x)/Evaluar(aux, x));
	}

	if (!aux->EsCero()) {
		for (int i = 1; i <= aux->Numero_Terminos(); i++) {
			aux->Poner_Termino(-aux->Coeficiente(aux->Exponente(i)), aux->Exponente(i));
		}
	}
	delete(aux);

	return x;
}*/


float Biseccion(Polinomio *P1, float a, float b)
{
	// Tolerancia para el criterio de parada
	const float tolerancia = 0.001;

	float c = 0.0; // Punto medio

	while (AbsolutoF(b-a) > tolerancia) {
		c = (a + b) / 2; // Calcular el punto medio
		float h_c = Evaluar(P1, c);

		if (h_c == 0.0 || AbsolutoF(c) < tolerancia) {
			// Encontramos la raíz exacta
			break;
		}

		// Decidir en qué subintervalo continuar
		if (Evaluar(P1,a) * h_c < 0) {
			b = c; // La raíz está en [a, c]
		} else {
			a = c; // La raíz está en [c, b]
		}
	}

	return c; // Aproximación de la raíz
}

void mostrarPunto(float x, float y)
{
	x = EjeX + (x*scale);
	y = EjeY - (y*scale);
	Form1->Canvas->Brush->Color = clBlue;
	Form1->Canvas->Ellipse(x-5, y-5, x+5,y+5);
}

void Interseccion(Polinomio *P1, Polinomio *P2)
{
	Polinomio *R = new Polinomio(M);
	AnsiString s;
	float a,b,c;
	R->Resta(P1,P2);
	for (int i = -cm; i <= cm; i++) {
		a = Evaluar(R, float(i));
		b = Evaluar(R, float(i+1));
		if (a*b < 0) {
			c = Biseccion(R,i,i+1);
			s = "( "+ Truncar_Cad(c,2) + " ; " + Truncar_Cad(Evaluar(P1, c),2) + " )";
		}
		else if ((a == 0) || (b == 0)) {
			if (a == 0)
				s = "( "+ IntToStr(i) + " ; " + Truncar_Cad(a,2) + " )";
			else
				s = "( "+ IntToStr(i+1) + " ; " + Truncar_Cad(b,2) + " )";
		}
        mostrarPunto( c , Evaluar(P1, c));
		ShowMessage( s );
	}

	if (!R->EsCero()) {
		for (int i = 1; i <= R->Numero_Terminos(); i++) {
			R->Poner_Termino(-R->Coeficiente(R->Exponente(i)), R->Exponente(i));
		}
	}
	delete(R);
}
