#include "BaseDeDatos.h"
#include "utils.h"

BaseDeDatos::BaseDeDatos (vector<pair<Tabla,string> > tablas)
  : _tablas(tablas) {};

void BaseDeDatos::agregarTabla(const Tabla &T, string nombre){
  for(unsigned int i = 0; i < tablas().size(); i++){
    if(!pertenece(nombre, nombresDeLasTablas()))
      _tablas.push_back(make_pair(T, nombre));
  }
}

void BaseDeDatos::agregarENTabla(Tabla& T, Registro r){
  if(insercionValida(T,r)) T.agregarRegistro(r);
}

vector<string> BaseDeDatos::nombresDeLasTablas() const{
  vector<string> nombres;
  for (unsigned int i = 0; i < _tablas.size(); i++){
    nombres.push_back(_tablas[i].second);
  }
  return nombres;
}

vector<Criterio> BaseDeDatos::criterios(){
  vector<Criterio> resultado;
  for (unsigned int i = 0; i < _criterios.size(); i++){
      resultado.push_back(_criterios[i].first);
  }
  return resultado;
}


vector<Tabla> BaseDeDatos::tablas() const{
  vector<Tabla> resultado;
  for (unsigned int i = 0; i < _tablas.size(); i++){
      resultado.push_back(_tablas[i].first);
  }
  return resultado;
}

int BaseDeDatos::cantidadDeUsos(Criterio c) const{
  for (unsigned int i = 0; i < _criterios.size(); i++){
    if (_criterios[i].first == c)
      return _criterios[i].second;
  }
  return 0;
}

void BaseDeDatos::criterioValido(const Tabla& T, Criterio c) const{
  
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


bool BaseDeDatos::insercionValida(const Tabla& T, Registro r){
  if(!seteq(T.campos(), r.campos())) return false;
  vector<string> claves = T.claves();
  vector<Registro> registros = T.registros();
  for(unsigned int i = 0; i < claves.size(); i++){
    for(unsigned int j = 0; j < registros.size(); j++){
      if(registros[j].dato(claves[i]) == r.dato(claves[i])){
        return false;
      }
    }
  }
  return true;
}


void BaseDeDatos::agregarCriterio(Criterio c){
  for (unsigned int i = 0; i < _criterios.size(); ++i){
    if (c == _criterios[i].first){
      _criterios[i].second++;
      return;
    } else {
      _criterios.push_back(make_pair(c,1));
    }
  }
}

bool operator==(const BaseDeDatos& bd1, const BaseDeDatos& bd2){
  if (not seteq(bd1.nombresDeLasTablas(), bd2.nombresDeLasTablas() ))
    return false;
  if (not seteq(bd1._tablas, bd2._tablas ))
      return false;
  if (not seteq(bd1._criterios, bd2._criterios ))
    return false;
  return true;
}


bool operator!=(const BaseDeDatos& bd1, const BaseDeDatos& bd2){
  return not (bd1==bd2);
}
