#include "Diccionario.h"

Diccionario :: Diccionario(){

}

void Diccionario :: iniciar(){
    
}

int Diccionario :: pertenece(VERTICE parametro){
    int pertenece = 0;
    for(vector<VERTICE> :: iterator it = dic.begin(); it != dic.end(); it++){
        if(*it == parametro){
            pertenece = 1;
            it = dic.end();
        }
    }
    return pertenece;
}

void Diccionario :: agregar(VERTICE parametro){
    if(!pertenece(parametro)){
        dic.push_back(parametro);
    }
}

//FaltaPRobar
void Diccionario :: borrar(VERTICE parametro){
    for(vector<VERTICE> :: iterator it = dic.begin(); it != dic.end(); it++){
        if(*it == parametro){
            dic.erase(it);
            it = dic.end();
        }
    }
}