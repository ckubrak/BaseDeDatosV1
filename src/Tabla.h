#ifndef TABLA_H
#define TABLA_H

#include <string>
#include "Dato.h"
#include "Registro.h"

using namespace std;

class Tabla {

public:

    // @generador
    Tabla(vector<string> campos, vector<string> claves, vector<Dato> tipos);

    // @generador
    void agregarRegistro(Registro r);

    // @observador
    vector<string> campos() const;

    // @observador
    const Dato tipoCampo(string campo) const;

    // @observador
    vector<string> claves() const;

    // @observador
    vector<Registro> registros() const;

private:

    vector<string> _campos;
    vector<string> _claves;
    vector<Dato> _tipos;
    vector<Registro> _registros;

};


#endif //TABLA_H
