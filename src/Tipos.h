#ifndef __TIPOS_H__
#define __TIPOS_H__

#include <iostream>
#include <string>
#include "modulos_basicos/string_map.h"
#include "modulos_basicos/linear_set.h"
#include "modulos_basicos/linear_set_iterators.h"


using namespace std;

enum TipoConsulta {
    FROM,       // consulta 0
    SELECT,     // consulta 1
    MATCH,      // consulta 2
    PROJ,       // consulta 3
    RENAME,     // consulta 4
    INTER,      // consulta 5
    UNION,      // consulta 6
    PRODUCT,    // consulta 7
};

typedef string NombreTabla;
typedef string NombreCampo;
typedef string Valor;

#define COMPLETAR(X)    { \
    cerr << "ERROR --- El método " #X " está incompleto." << endl; \
    exit(1); \
}

#endif /*__TIPOS_H__*/
