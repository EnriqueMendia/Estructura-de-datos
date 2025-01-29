//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_Matriz_Dispersa_COO.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//--------------------------------------------------------------------------

Direccion MatD::Buscar(Indice f, Indice c)
{
	Direccion x = PtrMatD;

	while (x != NULO){
		if ((M->Obtener_dato(x,"->Fila") == f) && (M->Obtener_dato(x,"->Col") == c)) {
			return x;
		}
		x = M->Obtener_dato(x,"->Sig");
	}

	return NULO;
}

void MatD::Eliminar(Direccion dir)
{
	if (PtrMatD != dir) {
		Direccion x = PtrMatD;
		while (M->Obtener_dato(x,"->Sig") != dir){
			x = M->Obtener_dato(x,"->Sig");
		}

		M->Poner_dato(x,"->Sig", M->Obtener_dato(dir,"->Sig"));
		M->Delete_espacio(dir);
	}
	else{
		PtrMatD = M->Obtener_dato(PtrMatD,"->Sig");
		M->Delete_espacio(dir);
	}
}

//--------------------------------------------------------------------------
MatD::MatD()
{
	M = new CSMemoria();
	PtrMatD = NULO;
	dimF = 0;
	dimC = 0;
	rep = 0;

	PtrDato = NULO;
}

MatD::MatD(CSMemoria* F)
{
	M = F;
	PtrMatD = NULO;
	dimF = 0;
	dimC = 0;
	rep = 0;

	PtrDato = NULO;
}

void MatD::Dimensionar(int nf,int nc)
{
	dimF = nf;
	dimC = nc;
}

int MatD::Dimension_Fila()
{
	return dimF;
}

int MatD::Dimension_Columna()
{
	return dimC;
}

void MatD::Poner(Indice f, Indice c, TipoElemento valor)
{
	Direccion dir = Buscar( f , c );
	if (dir == NULO) {
		if(valor != rep){
			Direccion x = M->New_espacio("Fila,Col,Dato,Sig");

			if (x != NULO) {
				M->Poner_dato(x,"->Fila",f);
				M->Poner_dato(x,"->Col",c);
				M->Poner_dato(x,"->Dato",valor);
				M->Poner_dato(x,"->Sig",PtrMatD);
				PtrMatD = x;
			}
			else
				throw new Exception("ERROR: NO EXISTE ESPACIO EN MEMORIA");
		}
	}
	else{
		M->Poner_dato(dir,"->Dato",valor);
		if (valor == rep) {
		   Eliminar(dir);
		}
	}
}

TipoElemento MatD::Elemento(Indice f, Indice c)
{
	if (PtrMatD == NULO) {
        return rep;
	}

	if (((f >= 1) && (f <= dimF)) && ((c >= 1) && (c <= dimC))) {
		Direccion dir = Buscar( f , c );
		if (dir != NULO) {
			return M->Obtener_dato(dir,"->Dato");
		}
		else{
			return rep;
		}
	}
	else
		throw new Exception("ERROR: INDICES FUERA DE RANGO");
}

void MatD::Definir_Valor_Repetido(TipoElemento valor)
{
	if (PtrMatD != NULO) {
		if (valor != rep) {
			for (Indice f = 1; f <= dimF; f++) {
				for (Indice c = 1; c <= dimC; c++) {
					if (Elemento( f , c ) == valor) {
						Direccion dir = Buscar(f,c);
						Eliminar(dir);
					}
				}
			}
		}
	}

	rep = valor;
}

void MatD::GuardarDato(Indice f, Indice c, Pila *R)
{
	R->Meter(float(f));
	R->Meter(float(c));
	R->Meter(float(Elemento(f,c)));
}

void MatD::CargarDato(Pila *R)
{
	float f,c,E;
	R->Sacar(E);
	R->Sacar(c);
	R->Sacar(f);
	Poner(int(f),int(c),int(E));
}

bool MatD::EsSudoku()
{
	for (int i = 1; i <= dimF; i++) {
	bool encontrado[10] = {false,false,false,false,false,false,false,false,false,false};
		for (int j = 1; j <= dimC; j++) {
			int valor = Elemento(i,j);
			if (valor >= 0) {
				if (encontrado[valor]) {
					return false;
				}
				encontrado[valor] = true;
			}
		}
	}

	for (int j = 1; j <= dimC; j++) {
	bool encontrado[10] = {false,false,false,false,false,false,false,false,false,false};
		for (int i = 1; i <= dimF; i++) {
			int valor = Elemento(i,j);
			if (valor >= 0) {
				if (encontrado[valor]) {
					return false;
				}
				encontrado[valor] = true;
			}
		}
	}

	for (int iniFila = 1; iniFila <= dimF - 2; iniFila = iniFila + 3) {
		for (int iniCol = 1; iniCol <= dimC - 2; iniCol = iniCol + 3) {
			bool encontrado[10] = {false,false,false,false,false,false,false,false,false,false};
			for (int i = iniFila; i <= iniFila + 2; i++) {
				for (int j = iniCol; j <= iniCol + 2; j++) {
					int valor = Elemento(i,j);
					if (valor >= 0) {
						if (encontrado[valor]) {
							return false;
						}
						encontrado[valor] = true;
					}
				}
			}
		}
	}

	return true;
}

String MatD::EsSudoku2()
{
	for (int i = 1; i <= dimF; i++) {
		bool encontrado[10] = {false,false,false,false,false,false,false,false,false,false};
		for (int j = 1; j <= dimC; j++) {
			int valor = Elemento(i,j);
			if (valor >= 0) {
				if (encontrado[valor]) {
					return "ERROR EN LA FILA "+IntToStr(i)+"\n"+"Elemento repetido en ["+i+"]["+j+"]";
				}
				encontrado[valor] = true;
			}
		}
	}

	for (int j = 1; j <= dimC; j++) {
		bool encontrado[10] = {false,false,false,false,false,false,false,false,false,false};
		for (int i = 1; i <= dimF; i++) {
			int valor = Elemento(i,j);
			if (valor >= 0) {
				if (encontrado[valor]) {
					return "ERROR EN LA COLUMNA "+IntToStr(j)+"\n"+"Elemento repetido en ["+i+"]["+j+"]";
				}
				encontrado[valor] = true;
			}
		}
	}

	for (int iniFila = 1; iniFila <= dimF - 2; iniFila = iniFila + 3) {
		for (int iniCol = 1; iniCol <= dimC - 2; iniCol = iniCol + 3) {
			bool encontrado[10] = {false,false,false,false,false,false,false,false,false,false};
			for (int i = iniFila; i <= iniFila + 2; i++) {
				for (int j = iniCol; j <= iniCol + 2; j++) {
					int valor = Elemento(i,j);
					if (valor >= 0) {
						if (encontrado[valor]) {
							return "ERROR EN LA SUBM \n Elemento repetido en ["+IntToStr(i)+"]["+j+"]";;
						}
						encontrado[valor] = true;
					}
				}
			}
		}
	}

	return "";
}

void MatD::Sudokear()
{
	short int sudoku[9][9] = {
		{5, 3, 0, 0, 7, 0, 0, 0, 0},
		{6, 0, 0, 1, 9, 5, 0, 0, 0},
		{0, 9, 8, 0, 0, 0, 0, 6, 0},
		{8, 0, 0, 0, 6, 0, 0, 0, 3},
		{4, 0, 0, 8, 0, 3, 0, 0, 1},
		{7, 0, 0, 0, 2, 0, 0, 0, 6},
		{0, 6, 0, 0, 0, 0, 2, 8, 0},
		{0, 0, 0, 4, 1, 9, 0, 0, 5},
		{0, 0, 0, 0, 8, 0, 0, 7, 9}
	};

	for (int i = 0; i < dimF; i++) {
		for (int j = 0; j < dimC; j++) {
			Poner(i+1, j+1, sudoku[i][j]);
		}
	}
}

bool MatD::EsValido(float fila, float col, TipoElemento valor)
{
	int f = int(fila), c = int(col);
	for (int x = 1; x <= dimC; x++) {
		if (Elemento(f,x) == valor)
			return false;
	}

	for (int x = 1; x <= dimF; x++) {
		if (Elemento(x,c) == valor)
			return false;
	}

	int inicioFila = (f-1) - (f-1) % 3, inicioColumna = (c-1) - (c-1) % 3;
	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if ((i+inicioFila <= dimF) && (j+inicioColumna <= dimC)) {
				if (Elemento(i+inicioFila, j+inicioColumna) == valor)
					return false;
			}
		}
	}
	return true;
}

bool MatD::encontrarVacia(float &fila, float &columna) {
	for (fila = 1; fila <= dimF; fila++) {
		for (columna = 1; columna <= dimC; columna++) {
			if (Elemento(fila,columna) == 0)
				return true;
		}
	}
	return false;
}

void MatD::Backtrack(Pila *P, Pila *R)
{
	int fr = rep;
	Definir_Valor_Repetido(0);
	float fila = 0, columna = 0;
	bool colocado = true;
	float num;
	while (true) {
		if (encontrarVacia(fila, columna)) {
			if (colocado) {
				num = 1;
			}else
				num++;
			colocado = false;
			while (num <= 9) {
				if (EsValido(fila, columna, num)) {
					//GuardarDato(fila, columna, R);
					Poner(fila, columna, num);
					P->Meter(fila);
					P->Meter(columna);
					P->Meter(num);
					//Mostrar();
					//M->Mostrar(0,35);
					colocado = true;
					break;
				}
				num++;
			}
			if (!colocado) {
				if (P->Vacia()) {
					Definir_Valor_Repetido(fr);
					throw new Exception("No hay solución"); // No hay solución
				}
				P->Sacar(num);
				P->Sacar(columna);
				P->Sacar(fila);
				Poner(fila, columna, 0);
				//Mostrar();
				//M->Mostrar(0,35);
			}
		} else {
			Definir_Valor_Repetido(fr);
			throw new Exception("Resuelto"); // Resuelto
		}
	}
}
