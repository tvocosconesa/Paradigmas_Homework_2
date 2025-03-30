#include "ej2.h"

Estudiante ::Estudiante( string name, vector<tuple<string, int>> clases, int legajo){
    if(legajo < 1 || legajo > 99999) throw "ERROR: Numero de legajo invalido";
    this -> name = name;
    this -> legajo = legajo;
    this -> clases = clases;
    cout << "Constructor llamado para:" << name << endl;
}
   
Estudiante ::~Estudiante() {
    // cout << "Destructor llamado para Estudiante" << name << std::endl;
}

string Estudiante::getName() { return name; }

int Estudiante ::getLegajo() { return legajo; }

float Estudiante :: promedio(){
    int suma = 0;
    for (size_t i = 0; i < clases.size(); i++) {
        suma += get<1>(clases[i]);  
    }

    return static_cast<float>(suma) / clases.size();  

}