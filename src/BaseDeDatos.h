#ifndef BaseDeDatos_H
#define BaseDeDatos_H

#include "Tabla.h"
#include "Restriccion.h"

typedef vector<Restriccion> Criterio;

class BaseDeDatos {

public:

  /// @generador
	BaseDeDatos(vector< pair<Tabla,string> > v);//L

  /// @generador
	void agregarTabla(const Tabla& T, string nombre);//L

  /// @generador @otra op
	void agregarENTabla(Tabla& T, Registro r);//L

  /// @otra operacion
	bool insercionValida(const Tabla& T, Registro r);//L

  /// @otra operacion
	void criterioValido(const Tabla& T, Criterio c) const;

  /// @otra operacion
	vector<Criterio> criteriosMasUsado() const;//L

  /// @observador
	vector<Tabla> tablas() const;//L

  /// @otra operacion
	int cantidadDeUsos(Criterio c) const;//L

	vector<Criterio> criterios();//L

	vector<pair<Criterio, int> > criteriosConUsos() const;

	vector<pair<Tabla,string>> tablasConNombres() const;

  void agregarCriterio (Criterio c);

private:

	vector<pair<Criterio, int> > _criterios;
	vector<pair<Tabla,string>> _tablas;
};


bool operator==(const BaseDeDatos&, const BaseDeDatos&);
bool operator!=(const BaseDeDatos&, const BaseDeDatos&);


#endif
