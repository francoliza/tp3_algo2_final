#include "gtest-1.8.1/gtest.h"
#include "../src/Registro.h"

TEST(test_registro, operador_igual){
    vector<NombreCampo> campos1 = {"nombre", "apellido","edad"};
    vector<Valor> valores1 = {"franco", "liza", "23"};
    vector<NombreCampo> campos2 = {"nombre", "apellido","años"};
    vector<Valor> valores2 = {"franco", "crego", "24"};

    Registro reg1(campos1);
    Registro reg2(campos1);
    Registro reg3(campos2);

    for (unsigned int i = 0; i < campos1.size(); ++i) {
        reg1[campos1[i]] = valores1[i];
        reg2[campos1[i]] = valores2[i];
        reg3[campos2[i]] = valores1[i];
    }

    ASSERT_FALSE(reg1 == reg2);
    ASSERT_FALSE(reg1 == reg3);
    ASSERT_FALSE(reg3 == reg2);
    ASSERT_TRUE(reg1 == reg1);
}