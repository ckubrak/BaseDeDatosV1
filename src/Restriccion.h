#ifndef Restriccion_H
#define Restriccion_H


template<typename T>
class Restriccion {
 public:

    Restriccion(string campo, T valor, bool opcion );
    string campo();
    T valor();
    bool esNat();

 private:


  string _campo;
  T _valor;
  bool _opcion;
};

template<typename T>
string Restriccion::campo(){
	return _campo;
}

template<typename T>
T Restriccion::valor(){
	return _valor;
}

template<typename T>
bool Restriccion::esNat(){
	return _opcion;
}

#endif
