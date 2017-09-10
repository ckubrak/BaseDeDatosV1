#ifndef BaseDeDatos_H
#define BaseDeDatos_H

#include "Tabla.h"
#include "Restriccion.h"

typedef vector<Restriccion> Criterio;

class BaseDeDatos {

public:

  /// @generador
  /// @requiere sinRepetidos(second (v))
  // donde second es una funcion que arma un vector con los \pi_{2} del vector de pares v
	BaseDeDatos(vector< pair<Tabla,string> > v);//T

  /// @generador
  /// @requiere sinRepetidos(nombresDeLasTablas() ++ nombre)
	void agregarTabla(const Tabla& T, string nombre);//T

  /// @generador
  /// @requiere pertenece(nombre,nombresDeLasTablas)
	void agregarENTabla(string nombre, Registro r);//L

  // existe tabla a la que se le aplica el criterio, y(luego) criteriovalido para la bd, tabla y criterio
  /// @generador
  void agregarCriterio (Criterio c); //L



  /// @observador
	vector<Tabla> tablas() const;//L

  /// @observador
	vector<Criterio> criterios() const;//L

  /// @observador
  vector<string> nombresDeLasTablas() const;

  /// @observador
	int cantidadDeUsos(Criterio c) const;//L

  /// @observador
  /// @requiere pertenece(nombre,nombresDeLasTablas) \yLuego criterioValido(tablaCorrespondiente(nombre),c)
  Tabla busqueda(string nombre, Criterio c, bool b) const;




  /// @otra operacion
	bool insercionValida(const Tabla& T, Registro r);//L

  /// @otra operacion
	bool criterioValido(const Tabla& T, Criterio c) const;

  /// @otra operacion
	vector<Criterio> criteriosMasUsado() const;//L

  /// @otra operacion
  /// @requiere pertenece(campos,t.campos)
  /// @requiere pertenece(claves,t.claves)
  Tabla crearTabla(const Tabla t, const vector<string> campos, const vector<string> claves) const;

  friend bool operator==(const BaseDeDatos&, const BaseDeDatos&);

  /// @otra operacion
  /// @requiere criterioValido(t,c)
  Tabla filtrar(Tabla t, Criterio c, bool b) const;

  /// @otra operacion
  bool coincide( Registro r,  Criterio c) const;

  /// @otra operacion
  /// @requiere pertenece(nombre,nombresDeLasTablas)
  Tabla tablaCorrespondiente(string nombre)const;

private:

	vector<pair<Criterio, int> > _criterios;
	vector<pair<Tabla,string>> _tablas;
};


bool operator!=(const BaseDeDatos&, const BaseDeDatos&);


#endif
