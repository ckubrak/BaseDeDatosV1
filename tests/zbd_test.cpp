
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
  bdtest.agregarTabla(t2, "Carreras");
  EXPECT_EQ(bdtest,bd2);
}
