//---------------------------------------------------------------------------

#ifndef FUNCIONES_CONJUNTOH
#define FUNCIONES_CONJUNTOH
//---------------------------------------------------------------------------

#include "FORM_CONJUNTO_CSMemoria.h"

//FUNCIONES CON CONJUNTO
void CopiarConj(Conjunto *R, Conjunto *Copia);
void VaciarConj(Conjunto *V);
void UnionC(Conjunto *A, Conjunto *B, Conjunto *C);
void InterseccionC(Conjunto *A, Conjunto *B, Conjunto *C);
void ComplementoInter(Conjunto *A, Conjunto *B, Conjunto *C);

#endif
