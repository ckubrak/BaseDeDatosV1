#ifndef BaseDeDatos_H
#define BaseDeDatos_H

#include "Tabla.h"
#include "Restriccion.h"

typedef vector<Restriccion> Criterio;

class BaseDeDatos {

public: 

  /// @generador
	BaseDeDatos(vector< pair<Tabla,string> > v);

  /// @generador
	void agregarTabla(const Tabla& T, string nombre);

  /// @generador @otra op
	void agregarENTabla(Tabla& T, Registro r);

  /// @otra operacion
	bool insercionValida(const Tabla& T, Registro r);

  /// @otra operacion
	void insercion(Tabla& T, Registro r);

  /// @otra operacion
	void criterioValido(const Tabla& T, Criterio c);

  /// @otra operacion
	Criterio criterioMasUsado();

  /// @observador
	vector<Tabla> tablas();

  /// @otra operacion
	int cantidadDeUsos(Criterio c);


private:

	vector<pair<Criterio, int> > _criterios;
	vector<pair<Tabla,string>> _tablas;
};


	bool operator==(const BaseDeDatos&, const BaseDeDatos&);


#endif
