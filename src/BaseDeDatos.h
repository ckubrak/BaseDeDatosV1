#ifndef BaseDeDatos_H
#define BaseDeDatos_H

#include "Tabla.h"


class BaseDeDatos {
public: 

	BaseDeDatos(vector<Tabla> v);

	void agregarTabla(const Tabla& T, string nombre);

	bool insercionValida(const Tabla&, Registro r);

	void insercion( Tabla&, Registro r);

	void criterioValido( const Tabla&, Criterio c);

	vector<Criterio> criterioMasUsado();


private:

	vector<Criterio> _criterios;
	vector<Tabla> _tablas ;


};

#endif
