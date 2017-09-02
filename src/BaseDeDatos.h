#ifndef BaseDeDatos_H
#define BaseDeDatos_H

#include "Tabla.h"
#include "Restriccion.h"

typedef vector<Restriccion> Criterio;

class BaseDeDatos {

public: 

	BaseDeDatos(vector< pair<Tabla,string> > v);

	void agregarTabla(const Tabla& T, string nombre);

	void agregarENTabla(Tabla& T, Registro r);

	bool insercionValida(const Tabla& T, Registro r);

	void insercion(Tabla& T, Registro r);

	void criterioValido(const Tabla& T, Criterio c);

	Criterio criterioMasUsado();

	vector<Tabla> tablas();

	int cantidadDeUsos(Criterio c);


private:

	vector<pair<Criterio, int> > _criterios;
	vector<pair<Tabla,string>> _tablas;
};


	bool operator==(const BaseDeDatos&, const BaseDeDatos&);


#endif
