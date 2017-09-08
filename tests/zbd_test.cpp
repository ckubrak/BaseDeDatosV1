
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
