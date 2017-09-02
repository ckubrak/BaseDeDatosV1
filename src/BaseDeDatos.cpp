#include "BaseDeDatos.h"

BaseDeDatos::BaseDeDatos (vector<pair<Tabla,string> > tablas)
  : _tablas(tablas) {};

void BaseDeDatos::agregarTabla(const Tabla &T, string nombre){
  _tablas.push_back(make_pair(T, nombre));
}

vector<Tabla> BaseDeDatos::tablas()const{
  vector<Tabla> resultado;
  for (unsigned int i = 0; i < _tablas.size(); ++i){
      resultado.push_back(_tablas[i].first);
  }
  return resultado;
}

int BaseDeDatos::cantidadDeUsos(Criterio c) const{
  for (unsigned int i = 0; i < _criterios.size(); ++i){
    if (_criterios[i].first == c)
      return _criterios[i].second;
  }
  return 0;
}


