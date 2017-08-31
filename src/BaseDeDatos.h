#ifndef BaseDeDatos_H
#define BaseDeDatos_H

#include "Tabla.h"

typedef vector<Restriccion> Criterio;

class BaseDeDatos {
public: 

	BaseDeDatos(vector<Tabla> v);

	void agregarTabla(const Tabla& T, string nombre);

	bool insercionValida(const Tabla& T, Registro r);

	void insercion(Tabla& T, Registro r);

	void criterioValido(const Tabla& T, Criterio c);

	Criterio criterioMasUsado();


private:

	vector<Criterio> _criterios;
	vector<Tabla> _tablas ;


};

#endif
