//
// Created by march on 07/08/17.
//

#include <iostream>
#include "Registro.h"
#include "Dato.h"

using namespace std;

Registro::Registro(vector<string> campos, vector<Dato> datos)
        : _campos(campos), _datos(datos) {};


Dato Registro::dato(string campo) const {
    for (int i = 0; i < _campos.size(); ++i) {
        if (_campos[i] == campo) {
            return _datos[i];
        }
    }
}

bool operator==(const Registro& r1, const Registro& r2) {
    r1._datos == r2._datos;
}