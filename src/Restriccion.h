#ifndef Restriccion_H
#define Restriccion_H

#include "Dato.h"

//

//typedef typename vector<Restriccion> Criterio;

//template<class T>

class Restriccion {
 public:

    Restriccion(string campo, Dato valor, bool opcion );
    string campo() const;
    Dato valor() const;
    bool opcion() const;

 private:


  string _campo;
  Dato _valor;
  bool _opcion;
};


bool operator==(const Restriccion&, const Restriccion&);
bool operator!=(const Restriccion&, const Restriccion&);


#endif
