
#include "gtest/gtest.h"

#include "../src/BaseDeDatos.h"

#include "../src/utils.h"

using namespace std;


Tabla t({ "LU", "Año", "Nombre", "Carrera" },
        {"LU", "Año"},
        {datoNat(0), datoNat(0), datoStr(""), datoStr("")});

Tabla t2({ "Cod", "Carrera" },
         {"Cod"},
         {datoNat(0), datoStr("")});
BaseDeDatos bd ({make_pair( t,"Alumnos")});
BaseDeDatos bd2 ({make_pair( t,"Alumnos"),make_pair( t2,"Carreras")});

TEST(Zbd_test,crear){

  Tabla t({ "LU", "Año", "Nombre", "Carrera" },
          {"LU", "Año"},
          {datoNat(0), datoNat(0), datoStr(""), datoStr("")});
  Tabla t2({ "Cod", "Carrera" },
           {"Cod"},
           {datoNat(0), datoStr("")});
  BaseDeDatos bd ({make_pair( t2,"Alumnos")});
}

TEST(Zbd_test, igualdad){
  EXPECT_EQ(bd,bd);
  EXPECT_FALSE(bd == bd2);
}
TEST(Zbd_test,agregarTabla){
  EXPECT_EQ(bd,bd);
  BaseDeDatos bdtest = bd;
  EXPECT_NE(bdtest,bd2);
  bdtest.agregarTabla(t2, "Carreras");
  EXPECT_EQ(bdtest,bd2);
  bdtest.agregarTabla(t2, "Carreras"); // No lo deberia agregar xq esta repetido
  EXPECT_EQ(bdtest,bd2);

}

 TEST(Zbd_test, agregarENTabla){
   vector<string> campos = {"LU", "Año", "Nombre", "Carrera"};
   Registro r1(campos, {datoNat(181), datoNat(2017), datoStr("March"), datoStr("Comp")});
   BaseDeDatos bdtest = bd;
   EXPECT_EQ(bdtest.tablas()[0].registros().size(), 0);
   bdtest.agregarENTabla("Alumnos", r1);
   EXPECT_EQ(bdtest.tablas()[0].registros().size(), 1);
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

TEST(Zbd_test, agregarCriterio){
  BaseDeDatos bdtest = bd;
  EXPECT_EQ(bd.criterios().size(),0);
  Dato numDni = Dato (5,"",true); //DNI nat 5
  Restriccion dni = Restriccion("DNI", numDni, true);
  Criterio criterio = {dni};
  EXPECT_FALSE(pertenece(criterio,bdtest.criterios()));
  bdtest.agregarCriterio(criterio);
  EXPECT_TRUE(pertenece(criterio,bdtest.criterios()));
}

TEST(Zbd_test, criterioValido){
  BaseDeDatos bdtest = bd;
  Dato numLU = Dato (5,"",true); //LU nat 5
  Restriccion lu = Restriccion("LU", numLU, true);
  Criterio criterio = {lu};
  EXPECT_TRUE(bdtest.criterioValido(t,criterio));
}

TEST(Zbd_test, criterios){
  BaseDeDatos bdtest = bd;
  EXPECT_EQ(bdtest.criterios().size(),0);
  Dato numLU = Dato (5,"",true); //LU nat 5
  Restriccion lu = Restriccion("LU", numLU, true);
  Criterio criterio = {lu};
  bdtest.agregarCriterio(criterio);
  EXPECT_EQ(bdtest.criterios().size(),1);
  EXPECT_EQ(bdtest.criterios()[0],criterio);
}

TEST(Zbd_test, cantidadDeUsos){
  BaseDeDatos bdtest = bd;
  Dato numLU = Dato (5,"",true); //LU nat 5
  Restriccion lu = Restriccion("LU", numLU, true);
  Criterio criterio = {lu};
  EXPECT_EQ(bdtest.cantidadDeUsos(criterio), 0);


  bdtest.agregarCriterio(criterio);
  EXPECT_EQ(bdtest.cantidadDeUsos(criterio), 1);
  EXPECT_TRUE(pertenece(criterio,bdtest.criteriosMasUsado()));

  bdtest.agregarCriterio(criterio);
  EXPECT_EQ(bdtest.cantidadDeUsos(criterio), 2);
  EXPECT_TRUE(pertenece(criterio,bdtest.criteriosMasUsado()));

  Dato name = Dato (9,"Cristian",true); //LU nat 5
  Restriccion nombre  = Restriccion("Nombre", name, true);
  Criterio nom = {nombre};
  EXPECT_EQ(bdtest.cantidadDeUsos(nom), 0);
  bdtest.agregarCriterio(nom);
  EXPECT_EQ(bdtest.cantidadDeUsos(criterio), 2);
  EXPECT_EQ(bdtest.cantidadDeUsos(nom), 1);

  Criterio doble = {nombre, lu};
  bdtest.agregarCriterio(doble);
  EXPECT_EQ(bdtest.cantidadDeUsos(doble), 1);
  Criterio dobleAlReves = {lu, nombre};
  bdtest.agregarCriterio(dobleAlReves);
  EXPECT_EQ(bdtest.cantidadDeUsos(dobleAlReves), 1);
  EXPECT_TRUE(pertenece(criterio,bdtest.criteriosMasUsado()));
}

TEST(Zbd_test, criterioMasUsado){
}

TEST(Zbd_test, insercionValida){
}

TEST(Zbd_test, busqueda){

}
