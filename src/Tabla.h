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

    bool esta(string campo);
    //bool esta(string campo , Registro r) const;

    // @otras operaciones
    /// @todo preguntar si el vector de campo lo paso por parametro o lo saco de la tabla
    bool mismosTipos(vector<string> campos , Registro r) ;//const;

    // @otras operaciones
    bool compatible(Registro r);

    // @otras operaciones
    bool puedoInsertar(Registro r) const;


    // @otras operaciones
    /// @todo preguntar si el vector de campo lo paso por parametro o lo saco de la tabla
    bool hayCoincidencia(Registro r) const;

    // @otras operaciones
    /// @todo preguntar si el vector de registro lo paso por parametro o lo saco de la tabla
    vector<Registro> filtrarRegistros(Registro r, string clave) ;//const;




private:

    vector<string> _campos;
    vector<string> _claves;
    vector<Dato> _tipos;
    vector<Registro> _registros;

};

bool operator==(const Tabla&, const Tabla&);
bool operator!=(const Tabla&, const Tabla&);


#endif //TABLA_H
