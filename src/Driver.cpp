
#include <cassert>
#include <cstdlib>
#include <sstream>

#include "Driver.h"

Driver::Driver() {

}

void Driver::crearTabla(NombreTabla tabla, vector<NombreCampo> camposTotales,
                        NombreCampo clave) {
    //
    Tabla nuevaTabla(tabla,camposTotales,clave);
    DiccTablas[tabla] = nuevaTabla;                 //agrego por referencias 


}

void Driver::insertarRegistro(NombreTabla tabla, Registro r) {
    if(DiccTablas.count(tabla) == 0) {
        NombreCampo clave = r.listaRegistro()[0].first; //el primero es el campo clave
        crearTabla(tabla, r.vectorCampos(), clave);
        DiccTablas[tabla].insertarRegistro(r);
    }else{
        DiccTablas[tabla].insertarRegistro(r);
    }
}

Respuesta Driver::consultar(const Consulta& q) {

    Respuesta res;
    vector< vector<Registro>::iterator > it_vector;
    Respuesta sub1;
    Respuesta sub2;

    if (q.tipo_consulta() == FROM) {
        res = DiccTablas[q.nombre_tabla()].registrosTotales(); //O(t)

    }else if(q.tipo_consulta() == SELECT){

        if(q.subconsulta1().tipo_consulta() == FROM) {
            Tabla t = DiccTablas[q.subconsulta1().nombre_tabla()];
            //string_map<DiccValores> dc = t.DiccCampos();
            //DiccValores dv = dc.
            res = t.registros(q.campo1(), q.valor());


        }else{
            //Cuando la sub-consulta no es FROM
            sub1 = consultar(q.subconsulta1());

            for(Registro r : sub1){
                if(r[q.campo1()] == q.valor()){
                    res.push_back(r);
                }
            }
        }


    }else if(q.tipo_consulta() == MATCH){


        if(q.subconsulta1().tipo_consulta() == PRODUCT){
            if(q.subconsulta1().subconsulta1().tipo_consulta() == FROM && q.subconsulta1().subconsulta2().tipo_consulta() == FROM){
                //JOIN
                Tabla t1 = DiccTablas[q.subconsulta1().subconsulta1().nombre_tabla()];
                Tabla t2 = DiccTablas[q.subconsulta1().subconsulta2().nombre_tabla()];
                DiccValores campo1 = t1.DiccCampos()[t1.campoClave()];
                DiccValores campo2 = t2.DiccCampos()[t2.campoClave()];
                if(campo1.size() < campo2.size()){
                    vector<Registro> vecR = t1.registrosTotales();
                    for(unsigned int i = 0; i<vecR.size(); i++){
                        if(campo2.count(vecR[i][t1.campoClave()])==1){
                            Registro r1 = campo1[vecR[i][t1.campoClave()]][0];
                            Registro r2 = campo2[vecR[i][t1.campoClave()]][0];
                            Registro reg = r1.concatenarRegistros(r1,r2);
                            res.push_back(reg);
                        }
                    }
                }else{
                    vector<Registro> vecR = t2.registrosTotales();
                    for(unsigned int i = 0; i<vecR.size(); i++){
                        if(campo1.count(vecR[i][t2.campoClave()])==1){
                            Registro r1 = campo1[vecR[i][t2.campoClave()]][0];
                            Registro r2 = campo2[vecR[i][t2.campoClave()]][0];
                            Registro reg = r1.concatenarRegistros(r2,r1);
                            res.push_back(reg);
                        }
                    }
                }
            }else {
                sub1 = consultar(q.subconsulta1());
                for (Registro reg : sub1) {
                    if (reg[q.campo1()] == reg[q.campo2()]) {
                        res.push_back(reg);
                    }
                }
            }
        }else{
            sub1 = consultar(q.subconsulta1());
            for (Registro reg : sub1) {
                if (reg[q.campo1()] == reg[q.campo2()]) {
                    res.push_back(reg);
                }
            }
        }
    }else if(q.tipo_consulta() == PROJ){
            sub1 = consultar(q.subconsulta1());

            for(Registro reg : sub1){
                Registro tmp(q.conj_campos());
                for(auto it=q.conj_campos().begin(); it != q.conj_campos().end();++it){
                        tmp[*it] = reg[*it];
                }
                res.push_back(tmp);
            }


    }else if(q.tipo_consulta() == RENAME){
        sub1 = consultar(q.subconsulta1());


        for (Registro reg : sub1) {
            reg.cambiarNombreCampo(q.campo1(),q.campo2());
            res.push_back(reg);
        }

    }else if(q.tipo_consulta() == INTER){

        if(q.subconsulta1().tipo_consulta() == FROM && q.subconsulta2().tipo_consulta() == FROM) {
            Tabla t1 = DiccTablas[q.subconsulta1().nombre_tabla()];
            Tabla t2 = DiccTablas[q.subconsulta2().nombre_tabla()];
            DiccValores campo1 = t1.DiccCampos()[t1.campoClave()];
            DiccValores campo2 = t2.DiccCampos()[t2.campoClave()];
            if (campo1.size() < campo2.size()) {
                vector<Registro> vecR = t1.registrosTotales();
                for (unsigned int i = 0; i < vecR.size(); ++i) {
                    if (campo2.count(vecR[i][t1.campoClave()]) == 1) {
                        Registro r1 = campo1[vecR[i][t1.campoClave()]][0];
                        Registro r2 = campo2[vecR[i][t1.campoClave()]][0];
                        if (r1 == r2) {
                            res.push_back(r1);
                        }
                    }
                }
            } else {
                vector<Registro> vecR = t2.registrosTotales();
                for (unsigned int i = 0; i < vecR.size(); ++i) {
                    if (campo1.count(vecR[i][t2.campoClave()]) == 1) {
                        Registro r1 = campo1[vecR[i][t2.campoClave()]][0];
                        Registro r2 = campo2[vecR[i][t2.campoClave()]][0];
                        if (r1 == r2) {
                            res.push_back(r1);
                        }
                    }
                }
            }
        }
        sub1 = consultar(q.subconsulta1());
        sub2 = consultar(q.subconsulta2());
        for (unsigned int i = 0; i < sub1.size(); ++i) {
            for (unsigned int j = 0; j < sub2.size(); ++j) {
                if(sub1[i] == sub2[j]){
                    res.push_back(sub1[i]);
                }
            }
        }
    }else if(q.tipo_consulta() == UNION){
        res = consultar(q.subconsulta1());
        sub2 = consultar(q.subconsulta2());
        res.insert(res.end(), sub2.begin(), sub2.end());
        
    }else if(q.tipo_consulta() == PRODUCT){

        sub1 = consultar(q.subconsulta1());
        sub2 = consultar(q.subconsulta2());

        for(Registro reg1 : sub1){
            for(Registro reg2 : sub2){
                res.push_back(reg2.concatenarRegistros(reg1,reg2));
            }
        }
    }

    return res;
}

void Driver::leerDataset(string dataset) {
    ifstream is("datos/" + dataset + ".txt");
    
    vector<NombreCampo> campos;
    _leerLinea(is, campos);
    crearTabla(dataset, campos, campos[0]); //CREO LA TABLA CON SU NOMBRE Y SUS CAMPOS, Y CAMPO[0] ES EL CAMPO CLAVE

    int linea = 1;
    while (!is.eof()) {
        vector<Valor> valores;
        if (!_leerLinea(is, valores)) {
            break;
        }
        if (campos.size() != valores.size()) {
            cerr << "Error leyendo dataset: " << dataset << endl;
            cerr << "El registro en la linea " << linea
                 << " tiene " << valores.size() << " campos"
                 << " pero la tabla declara " << campos.size() << " campos."
                 << endl;
            exit(1);
        }
        Registro reg(campos); // agregado, faltaba definir los campos del registro.
        for (size_t i = 0; i < campos.size(); i++) {
            reg[campos[i]] = valores[i];
        }
        //para la tabla "dataset" le asigno el registro reg
        insertarRegistro(dataset, reg);
    }
}

bool Driver::_leerLinea(ifstream& is, vector<string>& valores) const {
    string linea;
    if (!getline(is, linea)) {
        return false;
    }

    istringstream isl(linea);
    string valor;
    while (getline(isl, valor, ',')) {
        valores.push_back(valor);
    }
    return true;
}

