#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <array>
#include <tuple>
using namespace std;


class Estudiante{

private:
    string name;
    vector<tuple<string, int>> clases;
    int legajo;

public:
    // Constructor
    
    Estudiante(string name, vector<tuple<string, int>> classe, int legajo);
    ~Estudiante();    
    // Metodos
    string getName();
    float promedio();
    int getLegajo();

};

class Curso{

private:
    vector<Estudiante> estudiantes;
    int size; 

public:     
    Curso();
    
    void print();
    bool search(int legajo);
    bool completo();
    void inscribir(Estudiante Estudiante);
    void desinscribir(int legajo);

};




