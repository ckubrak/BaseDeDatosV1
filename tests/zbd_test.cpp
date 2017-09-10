
#include "gtest/gtest.h"

#include "../src/BaseDeDatos.h"

#include "../src/utils.h"

using namespace std;

//tabla donde sus campos son Lu Año Nombre Carrero
//claves son LU Año
//los tipos de los campos son el tercer vector    make

Tabla t({ "LU", "Año", "Nombre", "Carrera" }, {"LU", "Año"},{datoNat(0), datoNat(0), datoStr(""), datoStr("")});
Tabla t2({ "Cod", "Carrera" },{"Cod"},{datoNat(0), datoStr("")});
//Registro({"LU", "Año", "Nombre", "Carrera"}, {datoNat(182), datoNat(18), datoStr("March"), datoStr("Computacion")});
Registro r({"A", "B", "C"}, {datoNat(1), datoNat(2), datoNat(3)});

//base de dato se crea con una vector de pares, donde el primero es la tabla y el segundo el nombre de la tabla
BaseDeDatos bd ({make_pair( t,"Alumnos")});
BaseDeDatos bd2 ({make_pair( t,"Alumnos"),make_pair( t2,"Carreras")});

vector<string> campos = {"LU", "Año", "Nombre", "Carrera"};
vector<string> campos2 = { "Cod", "Carrera" };

//registros de tabla1
Registro reg1(campos, {datoNat(181), datoNat(2017), datoStr("March"), datoStr("Comp")});

Registro reg2(campos, {datoNat(191), datoNat(2017), datoStr("Feb"), datoStr("Comp")});

Registro reg3(campos, {datoNat(141), datoNat(2016), datoStr("March"), datoStr("Comp")});

Registro reg4(campos, {datoNat(93), datoNat(215), datoStr("Feb"), datoStr("Comp")});

Registro reg5(campos, {datoNat(161), datoNat(217), datoStr("March"), datoStr("Comp")});

Registro reg6(campos, {datoNat(11), datoNat(217), datoStr("Feb"), datoStr("Comp")});

Registro reg7(campos, {datoNat(1), datoNat(216), datoStr("March"), datoStr("Comp")});

Registro reg8(campos, {datoNat(9), datoNat(215), datoStr("Feb"), datoStr("Comp")});
//Registros de tabla2

Registro regN11(campos2, {datoNat(191), datoStr("Comp")});

Registro regN12(campos2, {datoNat(191), datoStr("Geo")});

Registro regN13(campos2, {datoNat(21), datoStr("Comp")});

Registro regN14(campos2, {datoNat(41), datoStr("Geo")});

Registro regN15(campos2, {datoNat(51), datoStr("Comp")});

Registro regN16(campos2, {datoNat(61), datoStr("Geo")});

Registro regN17(campos2, {datoNat(5), datoStr("cinco")});

Registro regN18(campos2, {datoNat(81), datoStr("Geo")});

Dato numDniN = Dato (5,"",true);
Restriccion dniN = Restriccion("DNI", numDniN, true);
Criterio criterioDniN = {dniN};

Dato numLUN1 = Dato (5,"",true);
Dato numLUN2 = Dato (8,"",true);
Restriccion restriccionlu1 = Restriccion("Cod", numLUN1, true);
Restriccion  restriccionlu2 = Restriccion("Cod", numLUN2, true);
Criterio criterioN1 = {restriccionlu1};
Criterio criterioN2 = {restriccionlu2};
Dato datNoValido = Dato (3,"kaka",false);
Restriccion  restriccionNoValida = Restriccion("E", datNoValido , true);
Criterio criterioNoValido = {restriccionNoValida};
Criterio criterioVacio = {};

TEST(Zbd_test,crear){

  Tabla t({ "LU", "Año", "Nombre", "Carrera" },{"LU", "Año"},{datoNat(0), datoNat(0), datoStr(""), datoStr("")});
  Tabla t2({ "Cod", "Carrera" },{"Cod"},{datoNat(0), datoStr("")});

  BaseDeDatos bd ({make_pair( t2,"Alumnos")});
}

TEST(Zbd_test, igualdad){
  EXPECT_EQ(bd,bd);
  EXPECT_FALSE(bd == bd2);
  BaseDeDatos bdtest = bd2;
  EXPECT_EQ(bdtest,bd2);
  EXPECT_NE(bdtest,bd);
}

TEST(Zbd_test,agregarTabla){
  EXPECT_EQ(bd,bd);
  //bdtest tiene los mismo elemtos que bd
  BaseDeDatos bdtest = bd;
  //bdtest no es igual bd2
  EXPECT_NE(bdtest,bd2);
  //en bdtest se agrega la tabla carreras
  bdtest.agregarTabla(t2, "Carreras");
  //dbtest es igual a bd2
  EXPECT_EQ(bdtest,bd2);
  //bdtest tiene las mismas tablas 
  bdtest.agregarTabla(t2, "Carreras"); // No lo deberia agregar xq esta repetido
  EXPECT_EQ(bdtest,bd2);

}

 TEST(Zbd_test, agregarENTabla){
 	//crea un vector de nombres(campos)
   vector<string> campos = {"LU", "Año", "Nombre", "Carrera"};
   //define un registro con los deto del registro
   Registro r1(campos, {datoNat(181), datoNat(2017), datoStr("March"), datoStr("Comp")});
   BaseDeDatos bdtest = bd;
   //bdtest es la tabla creada que tiene cero elementos
   EXPECT_EQ(bdtest.tablas()[0].registros().size(), 0);
   //dado el nombre de la tabla, agrega el registro a esa tabla
   bdtest.agregarENTabla("Alumnos", r1);
   //tablaño del vector registros es 1
   EXPECT_EQ(bdtest.tablas()[0].registros().size(), 1);
   //el primer registro, es el que acabo de agregar
   EXPECT_EQ(bdtest.tablas()[0].registros()[0], r1);
 }


TEST(Zbd_test, nombresDeLasTalas){
  BaseDeDatos bdtest = bd;
  EXPECT_EQ(bd.nombresDeLasTablas(),bd.nombresDeLasTablas());
  vector<string> nombres = bd.nombresDeLasTablas();
  bdtest.agregarTabla(t2, "Carreras");
  nombres.push_back("Carreras");
  EXPECT_EQ(bdtest.nombresDeLasTablas(),nombres);
}


TEST(Zbd_test, tablas){
  BaseDeDatos bdtest = bd;
  vector<Tabla> tablasTest {t};
  EXPECT_TRUE(seteq(bdtest.tablas(),tablasTest));
  tablasTest.push_back(t2);
  bdtest.agregarTabla(t2, "Carreras");
  EXPECT_TRUE(seteq(bdtest.tablas(),tablasTest));
  EXPECT_FALSE(seteq(bd.tablas(),tablasTest));
}

TEST(Zbd_test, insercionValida){
  BaseDeDatos bdtest = bd;
  Tabla tablaTest = t2;
  bdtest.agregarTabla(tablaTest, "Carreras");
  EXPECT_FALSE(bdtest.insercionValida(tablaTest, reg7));
  EXPECT_TRUE(bdtest.insercionValida(tablaTest, regN18));
  bdtest.agregarENTabla("Carreras", regN18);
  EXPECT_TRUE(bdtest.insercionValida(tablaTest, regN18));
  EXPECT_FALSE(bdtest.insercionValida(bdtest.tablaCorrespondiente("Carreras"), regN18));
}

TEST(Zbd_test, agregarCriterio){
  BaseDeDatos bdtest = bd;
  //cantidad de criterios usados en la base de datos es 0
  EXPECT_EQ(bd.criterios().size(),0);
  //se crea un dato 
  Dato numDni = Dato (5,"",true); //DNI nat 5
  //se crea una restriccion con el dato
  Restriccion dni = Restriccion("DNI", numDni, true);
  //se crea un criterio con la restriccion
  Criterio criterio = {dni};
  //el criterio no pertenece a los criterios de bdtest
  EXPECT_FALSE(pertenece(criterio,bdtest.criterios()));
  //se agrega el criterio en base de datos
  bdtest.agregarCriterio(criterio);
  //el criterio pertenece a la lista de criterio de la base de datos
  EXPECT_TRUE(pertenece(criterio,bdtest.criterios()));
}
TEST(Zbd_test, criterioValido){
  BaseDeDatos bdtest = bd;
  Dato numLU = Dato (5,"",true);
  Restriccion luv = Restriccion("LU", numLU, true);
  Criterio criterioV = {luv};
  EXPECT_TRUE(bdtest.criterioValido(t,criterioV));
  Dato numLUN2 = Dato (8,"",true);
  Restriccion restriccionF = Restriccion("Cod", numLUN1, true);
  Criterio criterioF = {restriccionF};
  EXPECT_FALSE(bdtest.criterioValido(t,criterioF));
}

TEST(Zbd_test, coinciden){
  BaseDeDatos bdtest = bd;
  Tabla tnueva = t2;  
  bdtest.agregarTabla(tnueva,"Carreras");
  bdtest.agregarENTabla("Carreras", regN17);
  bdtest.agregarENTabla("Carreras", regN18);


  EXPECT_FALSE(bdtest.coincide(regN18,criterioN2)); 
  EXPECT_TRUE(bdtest.coincide(regN17,criterioN1));

}


TEST(Zbd_test, filtrar){

  BaseDeDatos bdtest = bd;
  Tabla tnueva({ "Cod", "Carrera" },{"Cod"},{datoNat(0), datoStr("")});
  bdtest.agregarTabla(t2, "Carreras");
  bdtest.agregarENTabla("Carreras", regN17);
  bdtest.agregarENTabla("Carreras", regN18);
  EXPECT_NE(bdtest.tablaCorrespondiente("Carreras") , t2);
  Tabla tFiltrada = bdtest.filtrar(bdtest.tablaCorrespondiente("Carreras"),criterioN1, true);
  int f =0;
  EXPECT_NE(tFiltrada , tnueva);
  EXPECT_NE(tFiltrada , t2);
}


TEST(Zbd_test, busqueda){
  BaseDeDatos bdtest = bd;
  bdtest.agregarTabla(t2, "Carreras");
  //agrega en la tabla t2 el dato 5 
  bdtest.agregarENTabla("Carreras", regN17);
    //crea la tabla tnueva con los elementos de t2
  Tabla tnueva = t2;
  //agrega tabla nueva
  bdtest.agregarTabla(tnueva, "CarrerasN");
  //busca en carreras filtrando con el criterioN2
  Tabla tBusqueda1 = bdtest.busqueda("Carreras", criterioN1, false);
  EXPECT_TRUE(bdtest.criterios().size() == 1);
  Tabla tBusqueda2 = bdtest.busqueda("Carreras", criterioN2, false);
  EXPECT_TRUE(bdtest.criterios()[0] == criterioN1);
  EXPECT_TRUE(bdtest.criterios().size() == 2);
  EXPECT_TRUE(bdtest.criterios()[1] == criterioN2);
  Tabla tBusqueda3 = bdtest.busqueda("Carreras", criterioN1, false);
  EXPECT_TRUE(bdtest.cantidadDeUsos(criterioN1) == 2);
  EXPECT_TRUE(bdtest.cantidadDeUsos(criterioN2) == 1);
  EXPECT_NE(tBusqueda1 , tBusqueda2);
  EXPECT_EQ(tBusqueda1, tBusqueda3);
  vector<Criterio> criteriosB;
  EXPECT_TRUE(pertenece(criterioN1 ,bdtest.criteriosMasUsado()));
  EXPECT_FALSE(pertenece(criterioN2 ,bdtest.criteriosMasUsado()));
}







