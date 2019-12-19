#include "BaseDeDatos.h"

BaseDeDatos::BaseDeDatos() {}

void BaseDeDatos::crearTabla(NombreTabla tabla, vector<NombreCampo> camposTotales,
                        NombreCampo clave) {
    //
    Tabla nuevaTabla(tabla,camposTotales,clave);
    diccTablas[tabla] = nuevaTabla;                 //agrego por referencias 
}

Respuesta BaseDeDatos::consultar(const Consulta& q){

	Respuesta res;
    vector< vector<Registro>::iterator > it_vector;
    Respuesta sub1;
    Respuesta sub2;

    

    return res;
}