//---------------------------------------------------------------------------

#ifndef FUNCIONESH
#define FUNCIONESH
//---------------------------------------------------------------------------

#include "FORM_POLINOMIO_CSMemoria.h"

//---------------------------------------------------------------------------
//FUNCIONES CON MEMORIA
void Sumar(CSMemoria *F, int dir, string cad_id);

//FUNCIONES CON POLINOMIO

const int EjeX = 1000, EjeY = 300;
const int scale = 30;
const int cm = 8;

void Derivar(Polinomio *Pol, Polinomio *P1);
void Mostrar_Integral(Polinomio *Pol);
AnsiString Truncar_Cad(float num, int cifras);
float Evaluar(Polinomio *Pol, float x);
void EjeCartesiano();
void Graficar_Polinomio(Polinomio *Pol);
float AbsolutoF(float e);
//float Newton_Raphson(Polinomio *P1, float x);
float Biseccion(Polinomio *P1, float a, float b);
void mostrarPunto(float x, float y);
void Interseccion(Polinomio *P1, Polinomio *P2);

#endif
