#include "gtest/gtest.h"
#include "../src/Tabla.h"
#include <vector>
#include <string>

using namespace std;

class TablaTests : public ::testing::Test {

protected:
    TablaTests() : t({"LU", "Año", "Nombre", "Carrera"},
                     { "LU", "Año" },
                     { datoNat(0), datoNat(0), datoStr(""), datoStr("")}),
                   t2({"Cod", "Carrera"},
                      {"Cod"},
                      {datoNat(0), datoStr("")}) {};

    Tabla t;
    Tabla t2;

};

TEST(tabla_test, crear) {
    Tabla t({ "LU", "Año", "Nombre", "Carrera" },
            {"LU", "Año"},
            {datoNat(0), datoNat(0), datoStr(""), datoStr("")});
    Tabla t2({ "Cod", "Carrera" },
             {"Cod"},
             {datoNat(0), datoStr("")});
};

TEST_F(TablaTests, campos) {
    EXPECT_EQ(t.campos(), vector<string>({"LU", "Año", "Nombre", "Carrera"}));
    EXPECT_EQ(t2.campos(), vector<string>({"Cod", "Carrera"}));
};

TEST_F(TablaTests, claves) {
    EXPECT_EQ(t.claves(), vector<string>({"LU", "Año"}));
    EXPECT_EQ(t2.claves(), vector<string>({"Cod"}));
}

TEST_F(TablaTests, tipoCampo) {
    EXPECT_EQ(t.tipoCampo("LU").esNat(), true);
    EXPECT_EQ(t.tipoCampo("LU").esString(), false);
    EXPECT_EQ(t.tipoCampo("Nombre").esNat(), false);
    EXPECT_EQ(t.tipoCampo("Nombre").esString(), true);
}

template <class T>
bool vector_contiene(vector<T> v, T e) {
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == e) {
            return true;
        }
    }
    return false;
}

TEST_F(TablaTests, registros) {
    Tabla t3({}, {}, {});
    EXPECT_EQ(t3.registros().size(), 0);

    vector<string> campos = {"LU", "Año", "Nombre", "Carrera"};
    Registro r1(campos, {datoNat(181), datoNat(2017), datoStr("March"), datoStr("Comp")});
    Registro r2(campos, {datoNat(182), datoNat(2015), datoStr("Ariana"), datoStr("Mate")});
    Registro r3(campos, {datoNat(12), datoNat(2005), datoStr("Juan"), datoStr("Biol")});

    EXPECT_EQ(t.registros().size(), 0);
    t.agregarRegistro(r1);
    EXPECT_EQ(t.registros().size(), 1);
    EXPECT_EQ(t.registros().front(), r1);
    t.agregarRegistro(r2);
    EXPECT_EQ(t.registros().size(), 2);
    EXPECT_TRUE(vector_contiene(t.registros(), r1));
    EXPECT_TRUE(vector_contiene(t.registros(), r2));
    EXPECT_FALSE(vector_contiene(t.registros(), r3));
    t.agregarRegistro(r3);
    EXPECT_EQ(t.registros().size(), 3);
    EXPECT_TRUE(vector_contiene(t.registros(), r1));
    EXPECT_TRUE(vector_contiene(t.registros(), r2));
    EXPECT_TRUE(vector_contiene(t.registros(), r3));
}
