#include "Tabla.h"

Tabla::Tabla() {}
//lo dejamos así por ahora
Tabla::Tabla(NombreTabla tabla, vector<NombreCampo> camposTot, NombreCampo clave) {
	nombre_tabla = tabla;
	campo_clave = clave;
	copy(camposTot.begin(),camposTot.end(),back_inserter(campos_totales)); //copia por referencia los iteradores O(1)
	// ¿es necesario definir un registro de momento?, al parecer no pero podes guardar sus campos
	//campos(camposTotales.begin(), camposTotales.end()); // me guarde sus campos, jé
	//al parecer ya está

    DiccValores aux;

    for(NombreCampo n : camposTot){
        campos[n] = aux;
    }
};

void Tabla::cambiar_campo(NombreCampo viejo, NombreCampo nuevo){
    for (unsigned int i = 0; i < campos_totales.size(); ++i) {
        if(campos_totales[i] == viejo){
            campos_totales[i] = nuevo;
        }
    }
}


NombreCampo Tabla::campoClave(){
	return campo_clave;
}

NombreTabla Tabla::nombre(){
	return nombre_tabla;
}

vector<NombreCampo> Tabla::camposTotales(){
	return campos_totales;
}

//voy agregando registros
void Tabla::insertarRegistro(Registro reg){ //no es necesario el nombre de la tabla acá pues soy la tabla en sí

    _registros.push_back(reg);

	Valor value;
	NombreCampo field;

	for (NombreCampo n : reg.campos()){
	    if(campos[n].count(reg[n]) == 1){
	        campos[n][reg[n]].push_back(reg);
	    }else{
	        vector<Registro> res;
	        res.push_back(reg);
	        campos[n][reg[n]] = res;
	    }
	}

}


vector< Registro > Tabla::registros(NombreCampo campo, Valor nombre_valor){
	return (campos[campo])[nombre_valor];
}

vector<Registro> Tabla::registrosTotales(){
	return _registros;
}

string_map<DiccValores> Tabla::DiccCampos() {
    return campos;
}
