//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_Lista_Vector.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

ListaV::ListaV()
{
	longitud = 0;
}

Direccion ListaV::fin()
{
	if (!vacia())
		return longitud-1;

	else
		throw new Exception("Lista Vacia");
}

Direccion ListaV::primero()
{
	if (!vacia())
		return 0;

	else
		throw new Exception("Lista Vacia");
}

Direccion ListaV::siguiente(Direccion p)
{
	if (vacia())
		throw new Exception("Lista Vacia");

	else{
		if (p == longitud)
			throw new Exception("ERROR: Ultima Direccion");

		else
			return (p + 1);
	}
}

Direccion ListaV::anterior(Direccion p)
{
	if (vacia())
		throw new Exception("Lista Vacia");

	else{
		if (p == 0)
			throw new Exception("ERROR: Primera Direccion");

		else
			return (p - 1);
	}
}

bool ListaV::vacia()
{
	return (longitud == 0);
}

TipoElemento ListaV::recupera(Direccion p)
{
	if (vacia())    throw new Exception("Lista Vacia");

	else{
		if (!(p >= 0 && p < longitud))
			throw new Exception("ERROR: Direccion Fuera De Rango");

		else
			return elementos[p];
	}
}

int ListaV::LONGITUD()
{
	return longitud;
}

void ListaV::inserta(Direccion p, TipoElemento elemento)
{
	if (longitud == MAX)
		throw new Exception("Lista Llena");

	if (!(p >= 0 && p < longitud))
		throw new Exception("ERROR: Direccion Fuera De Rango");

	for (int i = longitud; i >= (p + 1); i--) {
		elementos[i] = elementos[i-1];
	}

	elementos[p] = elemento;
	longitud++;
}

void ListaV::inserta_primero(TipoElemento elemento)
{
	if (longitud == MAX)
		throw new Exception("Lista Llena");

	for (int i = longitud; i >= 1; i--) {
		elementos[i] = elementos[i-1];
	}

	elementos[0] = elemento;
	longitud++;
}

void ListaV::inserta_ultimo(TipoElemento elemento)
{
	if (longitud == MAX)
		throw new Exception("Lista Llena");

	else
		longitud++;
		elementos[longitud-1] = elemento;
}

void ListaV::suprime(Direccion p)
{
	if (vacia())
		throw new Exception("Lista Vacia");

	if (!(p >= 0 && p <= longitud))
		throw new Exception("ERROR: Direccion Fuera De Rango");

	for (int i = p; i < (longitud - 1); i++) {
		elementos[i] = elementos[i+1];
	}

	longitud--;
}

void ListaV::modifica(Direccion p, TipoElemento elemento)
{
	if (longitud == 0)
		throw new Exception("Lista Vacia");

	if (!(p >= 0 && p < longitud))
		throw new Exception("ERROR: Direccion Fuera De Rango");

	elementos[p] = elemento;
}

Direccion ListaV::localiza(TipoElemento E)
{
	if (!vacia()) {
		for (int i = 0; i < longitud; i++) {
			if (elementos[i] == E)
				return i;
		}
		throw new Exception("El Elemento no esta en la Lista");
	}
	else
		throw new Exception("Lista Vacia");
}

void ListaV::eliminaDato(TipoElemento E)
{
	if (!vacia()) {
		for (int i = 0; i < longitud; i++) {
			if (elementos[i] == E) {
				for (int j = i; j < longitud; j++) {
					elementos[j] = elementos[j+1];
				}
				longitud--;
			}
		}
	}
	else
		throw new Exception("Lista Vacia");
}

void ListaV::anula()
{
	longitud = 0;
}
