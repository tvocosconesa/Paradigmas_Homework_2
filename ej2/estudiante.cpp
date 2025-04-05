#include "ej2.h"

Estudiante ::Estudiante( string name, vector<tuple<string, int>> clases, int legajo){
    if(legajo < 1 || legajo > 99999) throw "ERROR: Numero de legajo invalido";
    this -> name = name;
    this -> legajo = legajo;
    this -> clases = clases;
    cout << "Constructor llamado para:" << name << endl;
}
   
bool Estudiante::operator<(const Estudiante& otro) const {
    return name < otro.name; 
}

ostream& operator<<(ostream& os, const Estudiante& est) {
    os << est.name;  
    return os;
}

vector<tuple<string, int>> Estudiante:: getClases() {return clases;}

string Estudiante::getName() { return name; }

int Estudiante ::getLegajo() { return legajo; }

float Estudiante :: promedio(){
    int suma = 0;
    for (size_t i = 0; i < clases.size(); i++) {
        suma += get<1>(clases[i]);  
    }

    return static_cast<float>(suma) / clases.size();  

}