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

void BaseDeDatos::agregarENTabla(string nombre, Registro r){
  for (unsigned int i = 0; i < _tablas.size(); ++i){
  	if(nombre == _tablas[i].second){
      if(insercionValida(_tablas[i].first,r)) {
        _tablas[i].first.agregarRegistro(r);
      }
  	}
  }
}

vector<string> BaseDeDatos::nombresDeLasTablas() const{
  vector<string> nombres;
  for (unsigned int i = 0; i < _tablas.size(); i++){
    nombres.push_back(_tablas[i].second);
  }
  return nombres;
}

vector<Criterio> BaseDeDatos::criterios() const{
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

bool BaseDeDatos::criterioValido(const Tabla& T, Criterio c) const{
  for(unsigned int j = 0; j < c.size(); j++){
    if (!pertenece(c[j].campo(),T.campos()))
      return false;
    if (c[j].valor().esNat()!=T.tipoCampo(c[j].campo()).esNat())
      return false;
  }
  return true;
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
  return masUsados;
}


bool BaseDeDatos::insercionValida(const Tabla& T, Registro r){
  if(!seteq(T.campos(), r.campos())) return false;
  for(unsigned int j = 0; j < T.registros().size(); j++){
    if(T.registros()[j] == r) return false;
  }
  return true;
}


void BaseDeDatos::agregarCriterio(Criterio c){
  for (unsigned int i = 0; i < _criterios.size(); ++i){
    if (c == _criterios[i].first){
      _criterios[i].second++;
      return;
    }
  }
  _criterios.push_back(make_pair(c,1));
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


Tabla BaseDeDatos::crearTabla(const Tabla t, const vector<string> campos, const vector<string> claves) const{
	vector<Dato> tipos;
		for(unsigned int k = 0; k <t.campos().size(); k++){
			vector<string> tCampos = t.campos();
			tipos.push_back(t.tipoCampo(tCampos[k]));
		}
	Tabla tNueva = Tabla(campos,claves,tipos);
	return tNueva;
}

Tabla BaseDeDatos::filtrar(Tabla t, Criterio c, bool b) const{
	if(criterioValido(t,c)){
		Tabla tNueva = crearTabla(t,t.campos(),t.claves());
		for(unsigned int i = 0; i < t.registros().size(); i++){
			Registro r = t.registros()[i];
			if(b == true && coincide(r,c)){
				tNueva.agregarRegistro(r);
			}else if(b == false && !coincide(r,c)){
				tNueva.agregarRegistro(r);
			}
		}
		return tNueva;
	}
}

bool BaseDeDatos::coincide(const Registro r, const Criterio c) const{
	for(unsigned int i = 0; i < c.size(); i++){
		for(unsigned int j = 0; j < r.campos().size(); j++){
			bool tiposIguales = r.dato(c[i].campo()).esNat() == c[i].valor().esNat();
			bool mismoValor = r.dato(c[i].campo()) == c[i].valor();
			if(!tiposIguales || !mismoValor){
				return false;
			}
		}
	}
	return true;
}



Tabla BaseDeDatos::busqueda(string nombre, Criterio c , bool b) {
	for (unsigned int i = 0; i < _tablas.size(); ++i){
  		if(nombre == _tablas[i].second){
	  		Tabla t = filtrar(_tablas[i].first, c, b);
	  		agregarCriterio(c);
  			return t;
  		}
  	}
}




Tabla BaseDeDatos::tablaCorrespondiente(string nombre)const{
	for(unsigned int i = 0; i < _tablas.size(); ++i){
		if(_tablas[i].second == nombre){
			return _tablas[i].first;
		}
	}
}


