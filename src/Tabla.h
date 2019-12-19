#ifndef __TABLA_H__
#define __TABLA_H__
//NOTA IMPORTANTE: SOLO IMPORTAR STRING MAP SOLO DONDE LO USAMOS Y EN EL .H
#include <cassert>
#include <cstdlib>
#include <sstream>
#include <vector>
#include "Registro.h"
#include "Tipos.h"
using namespace std;
typedef string_map< vector< Registro> > DiccValores;
//Vamos a llamar a la clase TABLA desde el clase BASE DE DATOS
//En vez de conjunto linal, mejor tal vez seria un vector, eso simplificaria muchas cosas
class Tabla
{
public:
	// Crea una nueva tabla
	Tabla();
	Tabla(NombreTabla tabla, vector<NombreCampo> camposTot, NombreCampo clave);

	vector<Registro> registrosTotales();
	void insertarRegistro(Registro reg);
	NombreTabla nombre();
	NombreCampo campoClave();
	vector<NombreCampo> camposTotales(); // para este estaria bueno tener un iterador sobre las claves de string_map<DiccValores> campos
    vector< Registro > registros(NombreCampo campo, Valor nombre_valor);
	void cambiar_campo(NombreCampo viejo, NombreCampo nuevo);
	string_map<DiccValores> DiccCampos();
	//~Tabla();
private:

	NombreTabla nombre_tabla;
	NombreCampo campo_clave;
	vector<NombreCampo> campos_totales; //ESPERA
	vector<Registro> _registros; 		// Esto no entiendo muy bien pero bueno
	string_map<DiccValores> campos; 	// Las claves con campos, tranquilamente tambien se podria definir en insertar registro, su significado son diccionario que dado un valor nos devuelve el itarador al registro
};


#endif /*__TABLA_H__*/
