#ifndef Restriccion_H
#define Restriccion_H

#include "Dato.h"

//

//typedef typename vector<Restriccion> Criterio;

//template<class T>

class Restriccion {
 public:

  // @generador
    Restriccion(string campo, Dato valor, bool opcion );

    // @observador
    string campo() const;

    // @observador
    Dato valor() const;

    // @observador
    bool opcion() const;

 private:


  string _campo;
  Dato _valor;
  bool _opcion;
};


bool operator==(const Restriccion&, const Restriccion&);
bool operator!=(const Restriccion&, const Restriccion&);


#endif
