#ifndef BaseDeDatos_H
#define BaseDeDatos_H

#include "Tabla.h"
#include "Restriccion.h"

typedef vector<Restriccion> Criterio;

class BaseDeDatos {

public:

  /// @generador
	BaseDeDatos(vector< pair<Tabla,string> > v);//T

  /// @generador
	void agregarTabla(const Tabla& T, string nombre);//T

  /// @generador @otra op
	void agregarENTabla(string nombre, Registro r);//L

  /// @otra operacion
	bool insercionValida(const Tabla& T, Registro r);//L

  /// @otra operacion
	bool criterioValido(const Tabla& T, Criterio c) const;

  /// @otra operacion
	vector<Criterio> criteriosMasUsado() const;//L

  /// @observador
	vector<Tabla> tablas() const;//L

  /// @otra operacion
	int cantidadDeUsos(Criterio c) const;//L

  /// @otra operacion 
  bool restriccionValida(const string campo, const Dato d, Restriccion r) const;

	vector<Criterio> criterios() const;//L

  void agregarCriterio (Criterio c); //L

  vector<string> nombresDeLasTablas() const;

  friend bool operator==(const BaseDeDatos&, const BaseDeDatos&);

  Tabla busqueda(string nombre, Criterio c, bool b) const;

  Tabla filtrar(Tabla t, Criterio c, bool b) const;

private:

	vector<pair<Criterio, int> > _criterios;
	vector<pair<Tabla,string>> _tablas;
};


bool operator!=(const BaseDeDatos&, const BaseDeDatos&);


#endif
