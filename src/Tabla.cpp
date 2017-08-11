#include <assert.h>
#include "Tabla.h"
#include "Registro.h"
#include <vector>

using namespace std;

Tabla::Tabla(vector<string> campos, vector<string> claves, vector<Dato> tipos) :
        _campos(campos), _claves(claves), _tipos(tipos), _registros(vector<Registro>()) {}

void Tabla::agregarRegistro(Registro r) {
    _registros.push_back(r);
}

vector<string> Tabla::campos() const {
    return _campos;
}

vector<string> Tabla::claves() const {
    return _claves;
}

const Dato Tabla::tipoCampo(string campo) const {
    for (int i = 0; i < _campos.size(); ++i) {
        if (_campos[i] == campo) {
            return _tipos[i];
        }
    }
}

vector<Registro> Tabla::registros() const {
    return _registros;
}