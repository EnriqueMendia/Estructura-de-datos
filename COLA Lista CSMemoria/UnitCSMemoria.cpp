//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitCSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int Numero_Ids(string cadena)
{
	int ids = 1;
	while (cadena.length() != 0){
		if (cadena[0] == ',') {
			ids++;
		}
		cadena.erase(0,1);
	}
	return ids;
}

string Obtener_Id(string cadena, int num)
{
	string c_id = "";
	int i = 1;
	while (i <= num){
		if (i == num) {
			c_id = c_id + cadena[0];
			if (cadena[1] == ',' || cadena.length() == 1) i++;
		}

		if (cadena[0] == ',') {
			i++;
		}

		cadena.erase(0,1);
	}
	return c_id;
}

void Eliminar_flecha(string &cadena)
{
	if (cadena[0] == '-' && cadena[1] == '>'){
		cadena.erase(0,2);
	}
	else{
		throw new Exception("Simbolo [ -> ] no encontrado");
	}
}

CSMemoria::CSMemoria()
{
	MEM = new NodoM[MAX];
	for (int i = 0; i < MAX; i++) {
		MEM[i].link = i + 1;
		MEM[i].dato = 0;
		MEM[i].id = "";
	}
	MEM[MAX].link = -1;
	MEM[MAX].dato = 0;
	MEM[MAX].id = "";
	Libre = 0;
}

int CSMemoria::New_espacio(string cadena)
{
	int cant = Numero_Ids(cadena);
	int DIR = Libre;
	int D = Libre;
	for (int i = 1; i < cant; i++) {
		MEM[D].id = Obtener_Id(cadena, i);
		D = MEM[D].link;
	}
	Libre = MEM[D].link;
	MEM[D].link = -1;
	MEM[D].id = Obtener_Id(cadena, cant);

    return DIR;
}

void CSMemoria::Delete_espacio(int dir)
{
	if (dir_libre(dir))
		throw new Exception("ERROR: ESA DIRECCION YA ESTA LIBRE");

	int X = dir;
	while (MEM[X].link != -1)
		X = MEM [X].link;

	MEM[X].link = Libre;
	Libre = dir;

}

int CSMemoria::Espacio_disponible()
{
	int X = Libre;
	int C = 0;    // CONTADOR
	while (X != -1){
		C++;
		X=MEM[X].link;
	}
	return C;
}

int CSMemoria::Espacio_ocupado()
{
	int C = MAX + 1;
	C = C - Espacio_disponible();
	return C;
}

void CSMemoria::Poner_dato(int dir, string cadena_id, int valor)
{
	int Z = dir;
	Eliminar_flecha(cadena_id);
	while (Z != NULO){
		if (MEM[Z].id == cadena_id)
			   MEM[Z].dato = valor;

		Z=MEM[Z].link;
	}
}

int CSMemoria::Obtener_dato(int dir, string cadena_id)
{
	int Z = dir;
	Eliminar_flecha(cadena_id);
	while (Z != NULO){
		if (MEM[Z].id == cadena_id)
			return MEM[Z].dato;

		Z=MEM[Z].link;
	}
	throw new Exception("Direccion o ID incorrecto.");
}

bool CSMemoria::dir_libre(int dir)
{
	int X = Libre;
	bool C = false;    // BANDERA
	while ((X != -1) && (C == false)){
		if (X == dir) C = true;

		X=MEM[X].link;
	}
	return C;
}
