#ifndef __BASEDEDATOS_H__
#define __BASEDEDATOS_H__

#include <cassert>
#include <cstdlib>
#include <sstream>
#include <vector>
//OJO NO PISARSE CON LOS INCLUDES
#include "Tabla.h"
#include "Tipos.h"
#include "Consulta.h"
typedef vector<Registro> Respuesta;


class BaseDeDatos 
{
public:
	BaseDeDatos(); //Constructor, nueva base de datos
	//agregar Tabla funciona bien
	void crearTabla(NombreTabla tabla, vector<NombreCampo> camposTotales,
                    NombreCampo clave);

	Respuesta realizar_consulta(const Consulta& q);

private:

	string_map<Tabla> DiccTablas;
	
};

#endif /*__BASEDEDATOS_H__*/


