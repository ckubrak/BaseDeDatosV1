#ifndef Restriccion_H
#define Restriccion_H

#include "Tabla.h"


class Restriccion {
 public:

  Restriccion(string campo, string valor, bool opcion );

 private:

  string _campo;
  string _valor;
  bool _opcion;
};

#endif
