
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
}

 TEST(Zbd_test, agregarENTabla){
   vector<string> campos = {"LU", "Año", "Nombre", "Carrera"};
   Registro r1(campos, {datoNat(181), datoNat(2017), datoStr("March"), datoStr("Comp")});
   BaseDeDatos bdtest = bd;
   EXPECT_EQ(bdtest.tablas()[0].registros().size(), 0);
   bdtest.agregarENTabla("Alumnos", r1);
   EXPECT_EQ(bdtest.tablas()[0].registros().size(), 1);

 }
