//---------------------------------------------------------------------------

#pragma hdrstop

#include "UNIT_PILA_CSMemoria.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

Pila::Pila()
{
	M = new CSMemoria();
	Tope = NULO;
}

Pila::Pila(CSMemoria *F)
{
	M = F;
	Tope = NULO;
}

bool Pila::Vacia()
{
	return (Tope == NULO);
}

void Pila::Meter(TipoElemento E)
{
	Direccion aux = M->New_espacio("Elemento,Sig");
	if (aux != NULO) {
		M->Poner_dato(aux,"->Elemento",E);
		M->Poner_dato(aux,"->Sig",Tope);
		Tope = aux;
	}
	else
		throw new Exception("ERROR: NO EXISTE ESPACIO EN MEMORIA");
}

void Pila::Sacar(TipoElemento &E)
{
	if (Vacia())
		throw new Exception("ERROR: PILA VACIA");

	else{
		Direccion x = Tope;
		E = M->Obtener_dato(Tope,"->Elemento");
		Tope = M->Obtener_dato(Tope,"->Sig");
		M->Delete_espacio(x);
	}
}

TipoElemento Pila::Cima()
{
	if (Vacia())
		throw new Exception("ERROR: PILA VACIA");

	else
		return M->Obtener_dato(Tope,"->Elemento");
}

int Pila::PrioridadInfija(char c)
{
	int prioridadInfija;
	if (c == '^') {
		prioridadInfija = 4;
	} else if (c == '*' || c == '/') {
		prioridadInfija = 2;
	} else if (c == '+' || c == '-') {
		prioridadInfija = 1;
	} else if (c == '(') {
		prioridadInfija = 5;
	} else {
		// Puedes manejar el caso de un car�cter no v�lido aqu�
		prioridadInfija = 0; // O alg�n otro valor para indicar error
	}
	return prioridadInfija;
}

int Pila::Prioridadpila(char c)
{
	int prioridadpila;
	if (c == '^') {
		prioridadpila = 3;
	} else if (c == '*' || c == '/') {
		prioridadpila = 2;
	} else if (c == '+' || c == '-') {
		prioridadpila = 1;
	} else if (c == '(') {
		prioridadpila = 0;
	} else {
		// Puedes manejar el caso de un car�cter no v�lido aqu�
		prioridadpila = -1; // O alg�n otro valor para indicar error
	}
	return prioridadpila;
}

String Pila::InfijaToPostFija(String infija)
{
	String postfija;
    postfija = "";
    String numeroActual = ""; // Para almacenar n�meros completos

    for (int i = 1; i <= infija.Length(); ++i) {
        char c = infija[i]; // C++ Builder usa 1-based indexing

        // Si es un d�gito, lo a�adimos al n�mero actual
        if (c >= '0' && c <= '9') {
            numeroActual += c; // Construye el n�mero completo
        }
        else {
            // Si hemos encontrado un operador o par�ntesis y hay un n�mero completo, lo a�adimos
            if (numeroActual.Length() > 0) {
				postfija += numeroActual + " "; // Agregar el n�mero a la postfija con un espacio
				numeroActual = ""; // Reiniciar n�mero
            }

            // Si es un operador o par�ntesis
            if (c == '^' || c == '*' || c == '/' || c == '+' || c == '-' || c == '(') {
                bool salir = false;
                while (!salir) {
                    if (Vacia() || PrioridadInfija(c) > Prioridadpila(Cima())) {
                        Meter(c); // Mete el operador en la pila
                        salir = true;
                    } else {
                        float aux;
                        Sacar(aux); // Saca el operador de la pila
                        postfija += char(aux); // Agrega a la expresi�n postfija
                    }
                }
            }
            // Si encontramos un par�ntesis derecho
            else if (c == ')') {
                float aux;
                do {
                    Sacar(aux); // Saca un operador de la pila
                    if (aux != '(') {
                        postfija += char(aux); // Agrega a la expresi�n postfija
                    }
                } while (aux != '('); // Hasta encontrar un par�ntesis izquierdo
            }
        }
    }

    // Si al final hay un n�mero pendiente, lo agregamos a la postfija
    if (numeroActual.Length() > 0) {
		postfija += numeroActual + " "; // Agregar el n�mero a la postfija
    }

    // Vaciar la pila en la expresi�n postfija
    while (!Vacia()) {
        float aux;
        Sacar(aux);
        postfija += char(aux);
    }

	return postfija; // Retorna la expresi�n postfija
}

float Pila::EvaluarPostfija(String ExpPostfija)
{
	String num="";
	// Llamar al constructor de la pila P
	for (int i = 1; i <= ExpPostfija.Length(); ++i) {

		char c = ExpPostfija[i]; // C++ Builder usa 1-based indexing
		if (c== ' ') {
		  Meter(StrToFloat(num));
		  Mostrar();
		  M->Mostrar(0,30);
		  ShowMessage(num);
		  num="";
		}
		// Si es un operando
		if (c >= '0' && c <= '9') {
			// Convertir el car�cter a n�mero y meter en la pila
			num +=c;
			//Meter(float(c - '0')); // Asumiendo que p.meter acepta Real
		}
		// Si es un operador
		else if (c!=' '){
			String p= "";
			float Op2, Op1;
			Sacar(Op2); // Saca el segundo operando
			Mostrar();
			 M->Mostrar(0,30);
			p=FloatToStr(Op2);
			ShowMessage(p);
			Sacar(Op1); // Saca el primer operando
			Mostrar();
			 M->Mostrar(0,30);
			p=FloatToStr(Op1);
			ShowMessage(p);
			char sim_operacion = c;
			float Z = Evalua(Op1, sim_operacion, Op2); // Eval�a la operaci�n
			Meter(Z); // Mete el resultado en la pila
			Mostrar();
			M->Mostrar(0,30);
			ShowMessage(Z);
		}

	}
	// Al final la pila queda con un �nico elemento que es el resultado de la evaluaci�n
	float ret;
	Sacar(ret);
	Mostrar();
	M->Mostrar(0,30);
	return ret; // Retorna el resultado
}

float Pila::Evalua(float Op1, char Operador, float Op2)
{
	if (Operador == '^') {
		return pow(Op1, Op2); // Calcula Op1^Op2
	}
	if (Operador == '*') {
		return Op1 * Op2;
	}
	if (Operador == '/') {
		return Op1 / Op2;
	}
	if (Operador == '+') {
		return Op1 + Op2;
	}
	if (Operador == '-') {
		return Op1 - Op2;
	}
	return 0; // Valor por defecto en caso de operador no v�lido
}
