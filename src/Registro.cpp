#include "Registro.h"

Registro::Registro(vector<NombreCampo> campos) {
	pair<NombreCampo, Valor> tmp;
	//solo defino los campos de la tabla
	for(vector<NombreCampo>::iterator itCampo = campos.begin(); itCampo != campos.end(); itCampo++){
		tmp.first = *itCampo;
		tmp.second = "";
		datos.push_back(tmp);
	}
}

Registro::Registro(set<NombreCampo> campos) {
	pair<NombreCampo, Valor> tmp;
	//solo defino los campos de la tabla
	for(set<NombreCampo>::iterator itCampo = campos.begin(); itCampo != campos.end(); itCampo++){
		tmp.first = *itCampo;
		tmp.second = "";
		datos.push_back(tmp);
	}
}

vector< pair<NombreCampo, Valor> > Registro::listaRegistro(){
	return datos;
}

set<NombreCampo> Registro::campos() const { // O(1)
    set<NombreCampo> fields;
    auto it = datos.begin();
    for (unsigned int i = 0; i < datos.size(); ++i){
    	fields.insert((*it).first);
    	it++;
    }
    return fields;
}

void Registro::cambiarNombreCampo(NombreCampo viejo, NombreCampo nuevo) {
    for (auto it = datos.begin(); it != datos.end(); ++it) {
        if((*it).first == viejo){
            (*it).first = nuevo;
        }
    }

    for(set<NombreCampo>::iterator it = campos().begin(); it != campos().end(); ++it){
        if((*it) == viejo){
            campos().erase(it);
            campos().insert(nuevo);
        }
    }
}

set<Valor> Registro::valores() const {
	set<NombreCampo> value;
	auto it = datos.begin();
    for (unsigned int i = 0; i < datos.size(); ++i){
    	value.insert((*it).first);
    	it++;
    }
    return value;
}

//POR REFERENCIA HAY PROBLEMAS
Valor& Registro::operator[](const NombreCampo& campo) {

	Valor* res;
	//aca defino
	for (unsigned int i = 0; i < datos.size(); ++i){
		if(datos[i].first == campo){
			res = &(datos[i].second);	
		}
	}
	//devuelvo una referencia modificable de ser necesario para obviamante modificarlo(valga la redundancia)
	return *res;
}


void Registro::printRegistro(){
    for (unsigned int i = 0; i < datos.size(); ++i){
        cout << "campo: " << datos[i].first << ", valor: " << datos[i].second << endl;
    }
}

bool Registro::operator==(Registro reg) {
    return listaRegistro() == reg.listaRegistro();
}


bool Registro::campoDefinido(NombreCampo name){
    bool res = false;

    for (auto it = campos().begin(); it != campos().end(); ++it) {
        if((*it) == name){
            res = true;
        }
    }

    return res;
}

Registro Registro::concatenarRegistros(Registro reg1, Registro reg2) {

    set<NombreCampo> tot1 = reg1.campos();
    set<NombreCampo> tot2 = reg2.campos();

    set<NombreCampo> tot(tot1);
    for(auto it = tot2.begin(); it != tot2.end(); ++it){
        tot.insert(*it);
    }

    Registro tmp(tot);



    for(auto it = tot2.begin(); it != tot2.end(); ++it){
        tmp[*it] = reg2[*it];
    }
    for(auto it = tot1.begin(); it != tot1.end(); ++it){
        tmp[*it] = reg1[*it];
    }

    return tmp;
}

vector<NombreCampo> Registro::vectorCampos() const {
    vector<NombreCampo> res;
    auto it = datos.begin();
    for (unsigned int i = 0; i < datos.size(); ++i){
        res.push_back((*it).first);
        it++;
    }
    return res;
}

