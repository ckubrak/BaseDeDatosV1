#include "Restriccion.h"


Restriccion::Restriccion(string campo, Dato valor, bool opcion ):
  _campo(campo), _valor(valor), _opcion(opcion) {};


string Restriccion::campo(){
	return _campo;
}

Dato Restriccion::valor(){
	return _valor;
}

bool Restriccion::opcion(){
	return _opcion;
}
