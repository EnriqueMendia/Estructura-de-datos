//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_Lista_CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaCSM::ListaCSM()
{
    m = new CSMemoria();
	longitud = 0;
	PtrElementos = NULO;
}

ListaCSM::ListaCSM(CSMemoria *f)
{
	m = f;
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
			x = m->Obtener_dato(x,"->sig");
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
			throw new Exception("ERROR: Ultima Direccion");

		else
			return m->Obtener_dato(p,"->sig");
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
				x = m->Obtener_dato(x,"->sig");
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
		return m->Obtener_dato(p,"->Elemento");
}

int ListaCSM::LONGITUD()
{
	return longitud;
}

void ListaCSM::inserta(Direccion p, TipoElemento E)
{
	Direccion x = m->New_espacio("Elemento,sig");
	if (x != NULO) {
		m->Poner_dato(x,"->Elemento",E);
		m->Poner_dato(x,"->sig",NULO);
		if (vacia()) {
			PtrElementos = x;
			longitud = 1;
		}

		else{
			longitud++;
			if (p == primero()) {
				m->Poner_dato(x,"->sig",p);
				PtrElementos = x;
			}

			else{
				Direccion ant = anterior(p);
				m->Poner_dato(ant,"->sig",x);
				m->Poner_dato(x,"->sig",p);
			}
		}
	}
	else
		throw new Exception("No existe espacio en Memoria");
}

void ListaCSM::inserta_primero(TipoElemento E)
{
	Direccion x = m->New_espacio("Elemento,sig");
	if (x != NULO) {
		m->Poner_dato(x,"->Elemento",E);
		m->Poner_dato(x,"->sig",PtrElementos);
		longitud++;
		PtrElementos = x;
	}
	else
		throw new Exception("No existe espacio en Memoria");
}

void ListaCSM::inserta_ultimo(TipoElemento E)
{
	Direccion x = m->New_espacio("Elemento,sig");
	if (x != NULO) {
		m->Poner_dato(x,"->Elemento",E);
		m->Poner_dato(x,"->sig",NULO);
		if (longitud != 0)
			m->Poner_dato(fin(),"->sig",x);

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
		PtrElementos = m->Obtener_dato(PtrElementos,"->sig");
		m->Delete_espacio(x);
	}

	else{
		Direccion ant = anterior(p);
		m->Poner_dato(ant,"->sig",siguiente(p));
		m->Delete_espacio(p);
	}

	longitud--;
}

void ListaCSM::modifica(Direccion p, TipoElemento E)
{
	if (longitud == 0)
		throw new Exception("Lista Vacia");

	m->Poner_dato(p,"->Elemento",E);
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
		for (Direccion i = PtrElementos; i != NULO; i = m->Obtener_dato(i,"->sig")) {
			if (m->Obtener_dato(i,"->Elemento") == E) {
				suprime(i);
			}
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
