#include "gtest-1.8.1/gtest.h"
#include "../src/Tabla.h"

TEST(test_1, tabla_tests){
	cout << "/////////TABLA-TEST/////////" << endl;
	NombreTabla datos = "datos personales";
	NombreCampo clave = "apellido";

	vector<NombreCampo> campos = {"nombre", "apellido","edad"};
	vector<Valor> valores = {"franco", "liza", "23"};
	
	Registro reg(campos); //defino los campos del Registro

	Tabla nuevaTabla(datos, campos, clave); //DEFINO LA TABLA

	nuevaTabla.insertarRegistro(valores);

}