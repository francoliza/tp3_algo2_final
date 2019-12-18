#ifndef __REGISTRO_H__
#define __REGISTRO_H__

#include <set>
#include <list>
#include <vector>
#include <utility> 
#include "Tipos.h"

using namespace std;

class Registro {
public:
    Registro(vector<NombreCampo> campos);
    Registro(set<NombreCampo> campos);
    set<NombreCampo> campos() const; 				// no hay campos repetidos
    vector<NombreCampo> vectorCampos() const;
    Valor& operator[](const NombreCampo& campo); 	// muy importante, devulve una referencia modificable
    //bool operator==(Registro reg);
    Registro concatenarRegistros(Registro reg1, Registro reg2);
    bool campoDefinido(NombreCampo name);
	//---------------------SOLO PARA TEST
	set<Valor> valores() const;
	vector< pair<NombreCampo, Valor> > listaRegistro();
	void cambiarNombreCampo(NombreCampo viejo, NombreCampo nuevo);
    void printRegistro();
private:
	vector< pair<NombreCampo, Valor> > datos;
};

#endif /*__REGISTRO_H__*/
