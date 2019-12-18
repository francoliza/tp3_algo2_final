#include "gtest-1.8.1/gtest.h"
#include "../src/Consulta.h"

TEST(test1, test_consulta){
	Consulta c("select(from(personas), apellido, 'liza')");
	cout << "tipo consulta: " << c.tipo_consulta() << endl;
	cout << "nombre de campo1: " << c.campo1() << endl;
	cout << "valor: " << c.valor() << endl;
	cout << c.subconsulta1().tipo_consulta() << endl;
}	