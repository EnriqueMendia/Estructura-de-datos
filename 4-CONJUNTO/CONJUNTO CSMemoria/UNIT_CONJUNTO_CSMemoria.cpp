//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_CONJUNTO_CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Conjunto::Conjunto()
{
    M = new CSMemoria();
	cant = 0;
	PtrConj = NULO;
}

Conjunto::Conjunto(CSMemoria *F)
{
	M = F;
	cant = 0;
	PtrConj = NULO;
}

bool Conjunto::Vacio()
{
	return (cant == 0);
}

bool Conjunto::Pertenece(Elemento E)
{
	bool resp = false;
	Direccion pc = PtrConj;
	while (pc != NULO) {

		if (M->Obtener_dato(pc, "->Dato") == E) {
			resp = true;
			pc = NULO;
		}

		else
			pc = M->Obtener_dato(pc, "->Sig");
	}

	return resp;
}

void Conjunto::Inserta(Elemento E)
{
	if (!Pertenece(E)) {
		Direccion dir = M->New_espacio("Dato,Sig");
		if (dir != NULO) {
			M->Poner_dato(dir,"->Dato", E);
			M->Poner_dato(dir,"->Sig", PtrConj);
			PtrConj = dir;
			cant++;
		}
		else
			throw new Exception("ERROR: NO EXISTE ESPACIO EN MEMORIA");
	}
}

int Conjunto::Cardinal()
{
	return cant;
}

int Conjunto::Ordinal(Elemento E)
{
	int resp = 0;
	Direccion pc = PtrConj;
	while (pc != NULO) {
		resp++;
		if (M->Obtener_dato(pc, "->Dato") == E)
			return resp;
		else
			pc = M->Obtener_dato(pc, "->Sig");
	}
	throw;
}

void Conjunto::Suprime(Elemento E)
{
	if (Pertenece(E)) {
		Direccion Dir = NULO;
		if (M->Obtener_dato(PtrConj,"->Dato") == E) {
			Dir = PtrConj;
			PtrConj = M->Obtener_dato(PtrConj,"->Sig");
		}
		else{
			Direccion pc = PtrConj;
			Direccion sig = M->Obtener_dato(pc,"->Sig");
			while (pc != NULO) {
				if (M->Obtener_dato(sig,"->Dato") == E) {
					Dir = sig;
					Direccion x = M->Obtener_dato(sig,"->Sig");
					M->Poner_dato(pc,"->Sig",x);
                    pc = NULO;
				}
				else {
					pc = sig;
					sig = M->Obtener_dato(pc,"->Sig");
				}
			}
		}
		cant--;
		M->Delete_espacio(Dir);
	}
}

Elemento Conjunto::Muestrea()
{
	if (cant > 0) {
		Direccion Lugar = 0;
		Direccion LugarBuscado = rand() % cant + 1; // numero al azar >=1 y <= cant
		Direccion pc = PtrConj;
		while (pc != NULO) {
			Lugar++;
			if (LugarBuscado == Lugar)
				return M->Obtener_dato(pc, "->Dato");
			else
				pc = M->Obtener_dato(pc, "->Sig");
		}
		throw new Exception("MUESTREA?");
	}
	else
		throw new Exception("ERROR: CONJUNTO VACIO");
}
