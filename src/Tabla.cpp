#include "Tabla.h"
#include "utils.h"

using namespace std;

Tabla::Tabla(vector<string> campos, vector<string> claves, vector<Dato> tipos) :
        _campos(campos), _claves(claves), _tipos(tipos), _registros(vector<Registro>()) {}

void Tabla::agregarRegistro(Registro r) {
    _registros.push_back(r);
}

vector<string> Tabla::campos() const {
    return _campos;
}

vector<string> Tabla::claves() const {
    return _claves;
}

const Dato Tabla::tipoCampo(string campo) const {
    for (int i = 0; i < _campos.size(); ++i) {
        if (_campos[i] == campo) {
            return _tipos[i];
        }
    }
}

vector<Registro> Tabla::registros() const {
    return _registros;
}

bool operator==(const Tabla& t1, const Tabla& t2) {
    if (not seteq(t1.campos(), t2.campos())) {
        return false;
    } else if (not seteq(t1.claves(), t2.claves())) {
        return false;
    } else {
        vector<string> cs = t1.campos();
        for (int i = 0; i < cs.size(); ++i) {
            if (t1.tipoCampo(cs[i]).esNat() != t2.tipoCampo(cs[i]).esNat()) {
                return false;
            }
        }
        return seteq(t1.registros(), t2.registros());
    }
}

bool operator!=(const Tabla& t1, const Tabla& t2) {
    return not (t1 == t2);
}


bool Tabla::esta(string campo){
	int i = 0;
	while(i < _campos.size()){
		if(campo == _campos[i]){
			return true;
		}
		i++;
	}
	return false;
}



bool Tabla::mismosTipos(vector<string> campos , Registro r) {
	int i = 0;
	while(i < campos.size()){
		if(tipoCampo(campos[i]) != r.dato(campos[i])){
			return false;
		}
		i++;
	}
	return true;
}     


//registro, clave 
//conjunto(registro) de la tabla(supongo)
//la clave pasada esta en cada uno de los registros (por requiere)
//filtra por la clave, en los que coinciden el valor del registro pasado por parametro y algun registro del la tabla
vector<Registro> Tabla::filtrarRegistros(Registro r, string clave){
	vector<Registro> filtrados;
	int i = 0;
	Dato valor = r.dato(clave);
	while(i < _registros.size()){
		if(valor == _registros[i].dato(clave)){
			filtrados.push_back(_registros[i]);
		}
		i++;
	}
	return filtrados;
}


//los campos de r y los campos de la tabla coinciden y ademas tienen el mismo tipo 
bool Tabla::compatible(Registro r){
	int i = 0;
	if(r.campos().size() == _campos.size()){
		while(esta(r.campos()[i]) && r.dato(r.campos()[i]) != tipoCampo(r.campos()[i])){
			i++;
		}
	}
	return i == _campos.size();
}
