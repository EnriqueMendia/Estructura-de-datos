//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_Lista_Puntero.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaPtr::ListaPtr()
{
	longitud = 0;
	PtrElementos = nullptr;
}

Direccion ListaPtr::fin()
{
	if (vacia())
		throw new Exception("Lista Vacia");

	else{
		Direccion x = PtrElementos;
		Direccion PtrFin;
		while (x != nullptr){
			PtrFin = x;
			x = x->sig;
		}
		return PtrFin;
	}
}

Direccion ListaPtr::primero()
{
	if (!vacia())
		return PtrElementos;

	else
		throw new Exception("Lista Vacia");
}

Direccion ListaPtr::siguiente(Direccion p)
{
	if (vacia())
		throw new Exception("Lista Vacia");

	else{
		if (p == fin())
			throw new Exception("ERROR: Ultima Direccion");

		else
			return p->sig;
	}
}

Direccion ListaPtr::anterior(Direccion p)
{
	if (vacia())
		throw new Exception("Lista Vacia");

	else{
		if (p == primero())
			throw new Exception("ERROR: Primera Direccion");

		else{
			Direccion x = PtrElementos;
			Direccion ant = nullptr;
			while (x != nullptr){
				if (x == p)
					return ant;

				ant = x;
				x = x->sig;
			}
			throw new Exception("ANTERIOR?");
		}
	}
}

bool ListaPtr::vacia()
{
	return (longitud == 0);
}

TipoElemento ListaPtr::recupera(Direccion p)
{
	if (vacia())
		throw new Exception("Lista Vacia");
	else
		return p->elemento;
}

int ListaPtr::LONGITUD()
{
	return longitud;
}

void ListaPtr::inserta(Direccion p, TipoElemento E)
{
	Direccion x = new Nodo();
	if (x != nullptr) {
		x->elemento = E;
		x->sig = nullptr;
		if (vacia()) {
			PtrElementos = x;
			longitud = 1;
		}
		else{
			longitud++;
			if (p == primero()){
				x->sig = p;
				PtrElementos = x;
			}
			else{
				Direccion ant = anterior(p);
				ant->sig = x;
				x->sig = p;
			}
		}
	}
	else
		throw new Exception("No existe espacio en memoria");
}

void ListaPtr::inserta_primero(TipoElemento E)
{
	Direccion x = new Nodo;
	if (x != nullptr) {
		x->elemento = E;
		x->sig = PtrElementos;
		longitud++;
		PtrElementos = x;
	}
	else
		throw new Exception("No existe espacio en memoria");
}

void ListaPtr::inserta_ultimo(TipoElemento E)
{
	Direccion x = new Nodo;
	if (x != nullptr) {
		x->elemento = E;
		x->sig = nullptr;

		if (longitud != 0)
			fin()->sig = x;
		else
			PtrElementos = x;

		longitud++;
	}
	else
		throw new Exception("No existe espacio en memoria");
}

void ListaPtr::suprime(Direccion p)
{
	if (longitud == 0)
		throw new Exception("Lista Vacia");

	if (p == primero()) {
		Direccion x = PtrElementos;
		PtrElementos = PtrElementos->sig;
		delete(x);
	}
	else{
		Direccion ant = anterior(p);
		ant->sig = siguiente(p);
		delete(p);
	}
	longitud--;
}

void ListaPtr::modifica(Direccion p, TipoElemento E)
{
	if (vacia())
		throw new Exception("Lista Vacia");

	p->elemento = E;
}

Direccion ListaPtr::localiza(TipoElemento E)
{
	if (!vacia()) {
		for (Direccion i = PtrElementos; i != nullptr; i = i->sig ) {
			if (i->elemento == E)
				return i;
		}
		throw new Exception("El Elemento no esta en la Lista");
	}
	else
		throw new Exception("Lista Vacia");
}

void ListaPtr::eliminaDato(TipoElemento E)
{
	if (!vacia()) {
		for (Direccion i = PtrElementos; i != nullptr; i = i->sig) {
			if (i->elemento == E) {
				suprime(i);
			}
		}
	}
	else
		throw new Exception("Lista Vacia");
}

void ListaPtr::anula()
{
	if (!vacia()) {
		while (PtrElementos != nullptr)
			suprime(PtrElementos);
	}
	else
		throw new Exception("Lista Vacia");
}
