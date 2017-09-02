#include "Restriccion.h"


Restriccion::Restriccion(string campo, Dato valor, bool opcion ):
  _campo(campo), _valor(valor), _opcion(opcion) {};


string Restriccion::campo () const{
	return _campo;
}

Dato Restriccion::valor () const{
	return _valor;
}

bool Restriccion::opcion () const{
	return _opcion;
}

bool operator==(const Restriccion& r1, const Restriccion& r2){
  if (r1.campo() != r2.campo())
    return false;
  if (r1.valor() != r2.valor())
    return false;
  if (r1.opcion() != r2.opcion())
    return false;
  return true;
}
bool operator!=(const Restriccion& r1, const Restriccion& r2){
  return not (r1 == r2);
}
