#include "ej2.h"


Curso:: Curso(string name){
    vector<shared_ptr<Estudiante>> estudiantes;
    this ->name = name;
    this -> estudiantes = estudiantes;
    this ->size = 0;
}

Curso::Curso(const Curso& otro): estudiantes(otro.estudiantes), size(otro.size), name(otro.name) {}


string Curso::  get_name(){ return name; }

void Curso::set_name(const string& new_name) { name = new_name; }

bool Curso :: search(int legajo){
    if( legajo < 1 || legajo > 99999) throw "ERROR: legajo ingresado invalido";

    for(int i = 0 ; i < this->size; i++){
        if (this->estudiantes[i]->getLegajo() == legajo) return true;
    }
    
    return false;
}


bool Curso:: completo(){
    if (this->size >= 20 ) return true;

    return false;
}

void Curso :: inscribir(shared_ptr<Estudiante> estudiante){

    estudiantes.push_back(estudiante);
    this ->size++;
}

void Curso:: desinscribir(int legajo){

    for (auto i = estudiantes.begin(); i != estudiantes.end(); ++i) {
        if ((*i) -> getLegajo() == legajo) {
            estudiantes.erase(i); 
            --size;                
            return;                
        }
    }
}


void Curso:: print(){

    std::sort(this->estudiantes.begin(), this->estudiantes.end(), 
    [](const std::shared_ptr<Estudiante>& e1, const std::shared_ptr<Estudiante>& e2) { // comparo por nombre
        return *e1 < *e2; 
    }
    );

    cout << "------------------------------------" << endl;
    cout << " Estado actual del curso " << this->name << ':' << endl; 
    cout << "------------------------------------" << endl;
    
    if (estudiantes.empty()) { cout << " El curso se encuentra vacio" << endl;} 
    for (int i = 0 ; i < this ->size ; i++) {       // imprimo los estudiantes ordenados
        cout << " - " << *estudiantes[i] << endl;
    }
}
