#ifndef __DRIVER_H__
#define __DRIVER_H__

#include <fstream>
#include <vector>
#include "Registro.h"
#include "Consulta.h"
#include "Tabla.h"

//ver si despues lo ponemos en tipos.h
typedef vector<Registro> Respuesta;

class Driver {
public:
    // Deben completar los siguientes métodos para invocar a la
    // implementación de la base de datos.

    Driver();

    void crearTabla(NombreTabla tabla,
                    vector<NombreCampo> campos,
                    NombreCampo clave);
    void insertarRegistro(NombreTabla tabla, Registro r);
    // Respuesta es simplemente un vector de registros
    Respuesta consultar(const Consulta& q);

    // El método leerDataset está provisto por la cátedra.
    //
    // Crea una tabla llamada <dataset>
    // y la llena con datos leídos desde un archivo ubicado
    // en el directorio datos/<dataset>.txt
    //
    // El archivo debe estar en formato CSV(*).
    // La primera línea contiene los campos separados por comas.
    // La clave es el primer campo (primera columna de la tabla).
    // Las líneas restantes contienen los registros.
    //
    // (*) El formato CSV soportado es muy básico,
    // por ejemplo no hay ninguna manera de incluir comas en
    // los campos.
    void leerDataset(string dataset);
private:
    //
    // COMPLETAR con la representación privada.
    // De momento es igual que la representacion de tabla
    //*****************************************************
    //van en este orden
        
    string_map<Tabla> DiccTablas;   // por cada tabla te da mucha información

    //NOS OLVIDAMOS UN POCO DE ESTO
    //NombreTabla nombre_tabla;
    //NombreCampo campo_clave;
    //vector<Registro> registros; // Esto no entiendo muy bien pero bueno
    //DiccValores Valores;    //por cada valor de campo defino un conjunto de iteradores
    //string_map<DiccValores> campos; // Las claves con campos, tranquilamente tambien se podria definir en insertar registro, su significado son diccionario que dado un valor nos devuelve el itarador al registro
    //*****************************************************
    bool _leerLinea(ifstream& is, vector<string>& valores) const;
};

#endif /*__DRIVER_H__*/
