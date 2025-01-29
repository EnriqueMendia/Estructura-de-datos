//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_Lista_CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaCSM::ListaCSM()
{
	M = new CSMemoria();
	longitud = 0;
	PtrElementos = NULO;
}

ListaCSM::ListaCSM(CSMemoria *F)
{
	M = F;
	longitud = 0;
	PtrElementos = NULO;
}

Direccion ListaCSM::fin()
{
	if (vacia())
		throw new Exception("Lista Vacia");
	else{
		Direccion x = PtrElementos;
		Direccion PtrFin;
		while (x != NULO){
			PtrFin = x;
			x = M->Obtener_dato(x,"->sig");
		}
		return PtrFin;
	}
}

Direccion ListaCSM::primero()
{
	if (!vacia())
		return PtrElementos;

	else
		throw new Exception("Lista Vacia");
}

Direccion ListaCSM::siguiente(Direccion p)
{
	if (vacia())
		throw new Exception("Lista Vacia");

	else{
		if (p == fin())
			//throw new Exception("ERROR: Ultima Direccion");
            return NULO;
		else
			return M->Obtener_dato(p,"->sig");
	}
}

Direccion ListaCSM::anterior(Direccion p)
{
	if (vacia())
		throw new Exception("Lista Vacia");

	else{
		if (p == primero())
			throw new Exception("ERROR: Primera Direccion");

		else{
			Direccion x = PtrElementos;
			Direccion ant = NULO;
			while (x != NULO){
				if (x == p)
					return ant;

				ant = x;
				x = M->Obtener_dato(x,"->sig");
			}
			throw new Exception("ANTERIOR?");
		}
	}
}

bool ListaCSM::vacia()
{
	return (longitud == 0);
}

TipoElemento ListaCSM::recupera(Direccion p)
{
	if (vacia())
		throw new Exception("Lista Vacia");

	else
		return M->Obtener_dato(p,"->Elemento");
}

int ListaCSM::LONGITUD()
{
	return longitud;
}

void ListaCSM::inserta(Direccion p, TipoElemento E)
{
	Direccion x = M->New_espacio("Elemento,sig");
	if (x != NULO) {
		M->Poner_dato(x,"->Elemento",E);
		M->Poner_dato(x,"->sig",NULO);
		if (vacia()) {
			PtrElementos = x;
			longitud = 1;
		}

		else{
			longitud++;
			if (p == primero()) {
				M->Poner_dato(x,"->sig",p);
				PtrElementos = x;
			}

			else{
				Direccion ant = anterior(p);
				M->Poner_dato(ant,"->sig",x);
				M->Poner_dato(x,"->sig",p);
			}
		}
	}
	else
		throw new Exception("No existe espacio en Memoria");
}

void ListaCSM::inserta_primero(TipoElemento E)
{
	Direccion x = M->New_espacio("Elemento,sig");
	if (x != NULO) {
		M->Poner_dato(x,"->Elemento",E);
		M->Poner_dato(x,"->sig",PtrElementos);
		longitud++;
		PtrElementos = x;
	}
	else
		throw new Exception("No existe espacio en Memoria");
}

void ListaCSM::inserta_ultimo(TipoElemento E)
{
	Direccion x = M->New_espacio("Elemento,sig");
	if (x != NULO) {
		M->Poner_dato(x,"->Elemento",E);
		M->Poner_dato(x,"->sig",NULO);
		if (longitud != 0)
			M->Poner_dato(fin(),"->sig",x);

		else
			PtrElementos = x;

		longitud++;
	}
	else
		throw new Exception("No existe espacio en Memoria");
}

void ListaCSM::suprime(Direccion p)
{
	if (longitud == 0)
		throw new Exception("Lista Vacia");

	if (p == PtrElementos) {
		Direccion x = PtrElementos;
		PtrElementos = M->Obtener_dato(PtrElementos,"->sig");
		M->Delete_espacio(x);
	}

	else{
		Direccion ant = anterior(p);
		M->Poner_dato(ant,"->sig",siguiente(p));
		M->Delete_espacio(p);
	}

	longitud--;
}

void ListaCSM::modifica(Direccion p, TipoElemento E)
{
	if (longitud == 0)
		throw new Exception("Lista Vacia");

	M->Poner_dato(p,"->Elemento",E);
}

Direccion ListaCSM::localiza(TipoElemento E)
{
	if (vacia())
		return NULO;

	else{
		Direccion p = primero();
		while (p != NULO){
			TipoElemento elem = recupera(p);
			if (elem == E)
				return  p;

			p = siguiente(p);
		}
	}
	return NULO;
}

void ListaCSM::eliminaDato(TipoElemento E)
{
	if (!vacia()) {
		for (Direccion i = primero(); i != fin(); i = siguiente(i)) {
			if (recupera(i) == E) {
				suprime(i);
			}
		}

		if (recupera(fin()) == E) {
				suprime(fin());
		}
	}
	else
		throw new Exception("Lista Vacia");
}

void ListaCSM::anula()
{
	if (!vacia()) {
		while (PtrElementos != NULO)
			suprime(PtrElementos);
	}
	else
		throw new Exception("Lista Vacia");
}
