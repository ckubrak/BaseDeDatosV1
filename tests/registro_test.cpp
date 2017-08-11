#include "gtest/gtest.h"
#include "../src/Dato.h"
#include "../src/Registro.h"
#include <vector>

using namespace std;

TEST(registro_test, generadores) {
    Registro({"LU", "Año", "Nombre", "Carrera"}, {datoNat(182), datoNat(18), datoStr("March"), datoStr("Computacion")});
    Registro({}, {});
}

TEST(registro_test, observadores) {
    Registro r({"LU", "Año", "Nombre", "Carrera"}, {datoNat(182), datoNat(18), datoStr("March"), datoStr("Computacion")});

    EXPECT_EQ(r.dato("LU").esNat(), true);
    EXPECT_EQ(r.dato("LU").esString(), false);
    EXPECT_EQ(r.dato("LU").valorNat(), 182);
    EXPECT_EQ(r.dato("Nombre").esNat(), false);
    EXPECT_EQ(r.dato("Nombre").esString(), true);
    EXPECT_EQ(r.dato("Nombre").valorStr(), "March");
}

// TODO: Test ==