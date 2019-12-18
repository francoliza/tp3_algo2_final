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
    /*
    if (q.tipo_consulta() == FROM) {

        //res = diccTablas[q.nombre_tabla()].registrosTotales();

    }else if(q.tipo_consulta() == SELECT){


        sub1 = consultar(q.subconsulta1());

        for(Registro reg : sub1){
            if(reg[q.campo1()] == q.valor()){
                res.push_back(reg);
            }
        }

    }else if(q.tipo_consulta() == MATCH){
        sub1 = consultar(q.subconsulta1()); 
        for(Registro reg : sub1){
            if(reg[q.campo1()] == reg[q.campo2()]){
                res.push_back(reg);
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
        sub1 = consultar(q.subconsulta1());
        Respuesta sub2 = consultar(q.subconsulta2());


        for(Registro reg1 : sub1){
            for(Registro reg2 : sub2){

                if(q.subconsulta1().tipo_consulta() == FROM && q.subconsulta2().tipo_consulta() == FROM){
                    if(reg1 == reg2){
                        res.push_back(reg1);
                    }
                }else{
                    NombreCampo c1 = q.subconsulta1().campo1();
                    NombreCampo c2 = q.subconsulta2().campo1();
                    Valor v1 = q.subconsulta1().valor();
                    Valor v2 = q.subconsulta2().valor();

                    if(reg1[c1] == v1 && reg1[c2] == v2){
                        res.push_back(reg1);
                    }
                    if(reg2[c1] == v1 && reg2[c2] == v2){
                        res.push_back(reg2);
                    }
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
    */

    return res;
}