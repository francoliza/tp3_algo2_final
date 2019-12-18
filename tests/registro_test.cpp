#include "gtest-1.8.1/gtest.h"
#include "../src/Registro.h"

TEST(test, definir_registros){
	vector<NombreCampo> campos = {"nombre", "apellido","edad"};
	vector<Valor> valores = {"franco", "liza", "23"};

	Registro reg(campos);

	for (unsigned int i = 0; i < campos.size(); ++i){
		reg[campos[i]] = valores[i];
	}


    reg["edad"] = "99";
    reg.cambiarNombreCampo("edad","antiguedad");

	cout << reg["antiguedad"] << endl;


	reg.printRegistro();
}