#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <array>
#include <tuple>
#include <memory>
using namespace std;


class Estudiante{

private:
    string name;
    vector<tuple<string, double>> clases;
    int legajo;

public:
    
    Estudiante(string name, vector<tuple<string, double>> classe, int legajo);
    
    bool operator<(const Estudiante& otro) const;
    friend ostream& operator<<(ostream& os, const Estudiante& est);

    vector<tuple<string, double>> getClases();
    string getName();
    float promedio();
    int getLegajo();

};

class Curso{

private:
    vector<shared_ptr <Estudiante>> estudiantes;
    int size; 
    string name;

public:     
    Curso(string name);
    Curso(const Curso& otro );
    string get_name();
    
    void set_name(const string& new_name);
    void print();
    bool search(int legajo);
    bool completo();
    void inscribir(shared_ptr <Estudiante> estudiante);
    void desinscribir(int legajo);

};

void menu(vector<Curso>* cursos, vector<shared_ptr <Estudiante>>* estudiantes);


