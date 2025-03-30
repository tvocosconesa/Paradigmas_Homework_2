#include "ej2.h"


Curso:: Curso(){
    vector<Estudiante> estudiantes;

    this -> estudiantes = estudiantes;
    this ->size = 0;
}

bool Curso :: search(int legajo){
    if( legajo < 1 || legajo > 99999) throw "ERROR: legajo ingresado invalido";

    for(int i = 0 ; i < this->size; i++){
        if (this->estudiantes[i].getLegajo() == legajo) return true;
    }
    
    return false;
}

bool Curso:: completo(){
    if (this->size >= 20 ) return true;

    return false;
}

void Curso :: inscribir(Estudiante estudiante){

    this->estudiantes.push_back(estudiante);
    this ->size++;
}

void Curso:: desinscribir(int legajo){

    for (auto i = estudiantes.begin(); i != estudiantes.end(); ++i) {
        if (i->getLegajo() == legajo) {
            estudiantes.erase(i); 
            --size;                
            return;                
        }
    }
}


void Curso:: print(){
    std::sort(this->estudiantes.begin(), this->estudiantes.end(), 
        []( Estudiante& e1,  Estudiante& e2) {
            return e1.getName() < e2.getName();
        }
    );

    // Imprimir los estudiantes ordenados
    for (int i = 0 ; i < this ->size ; i++) {
        std::cout << estudiantes[i].getName() << std::endl;
    }
}