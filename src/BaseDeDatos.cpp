#include "BaseDeDatos.h"

BaseDeDatos::BaseDeDatos (vector<pair<Tabla,string> > tablas)
  : _tablas(tablas) {};

void BaseDeDatos::agregarTabla(const Tabla &T, string nombre){
  _tablas.push_back(make_pair(T, nombre));
}

vector<Tabla> BaseDeDatos::tablas() const{
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

vector<Criterio> BaseDeDatos::criteriosMasUsado() const {
  vector<Criterio> masUsados;
  masUsados.push_back(_criterios[0].first);
  int cantVeces = _criterios[0].second;

  for (unsigned int i = 0; i < _criterios.size(); ++i){
    if (_criterios[i].second == cantVeces)
      masUsados.push_back(_criterios[i].first);

    if (_criterios[i].second > cantVeces){
      masUsados.clear();
      masUsados.push_back(_criterios[i].first);
      cantVeces = _criterios[i].second;
    }
  }
}
