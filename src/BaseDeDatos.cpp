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

bool BaseDeDatos::registroValido(const string campo, const Dato d, Restriccion r) const{
	if(campo != r.campo() || d.esNat() != r.valor().esNat()){
		return false;
	}
	return true;
}

bool BaseDeDatos::criterioValido(const Tabla& T, Criterio c) const{
  for(int i = 0; i < T.campos().size(); i++){
  	for(int j = 0; j < c.size(); j++){
  		if(!registroValido(T.campos()[i], T.tipoCampo(T.campos()[i]),c[j])){
  			return false;
  		}
  	}
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

}


bool BaseDeDatos::insercionValida(const Tabla& T, Registro r){
  if(!seteq(T.campos(), r.campos())) return false;
  vector<string> campos = T.campos();
  vector<Registro> registros = T.registros();
  for(unsigned int i = 0; i < campos.size(); i++){
    for(unsigned int j = 0; j < registros.size(); j++){
      if(registros[j].dato(campos[i]) == r.dato(campos[i])){
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


//filtrar toma una tabla con un criterio y un bool y filtra segun la condicion
Tabla BaseDeDatos::filtrar(Tabla t, Criterio c, bool b) const{
	if(criterioValido(t,c)){
		vector<Dato> tipos;
		for(unsigned int k = 0; k <t.campos().size(); k++){
			vector<string> tCampos = t.campos();
			tipos.push_back(t.tipoCampo(tCampos[k]));
		}
		Tabla tNueva = Tabla(t.campos(),t.claves(),tipos);
		/*
		for(int i = 0; i < t.campos().size(); i++){
			for(int j = 0; j < c.size(); j++){
				d.esNat() != r.valor().esNat()
				if(t.campos()[i] == c[j].campo() && t.tipoCampo(t.campos()[i]).esNat() == c[j].valor().esNat() && t.tipoCampo(t.campos()[i]) == c[j].valor() && b){
					//si b es true entonces los agregra
				}else{

				}
			}
		}*/
	}
}


Tabla BaseDeDatos::busqueda(string nombre, Criterio c , bool b) const{
	for (unsigned int i = 0; i < _tablas.size(); ++i){
  		if(nombre == _tablas[i].second){
	  		Tabla t = filtrar(_tablas[i].first, c, b);
  			return t;
  		}
  	}
}







