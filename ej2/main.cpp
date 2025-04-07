#include "ej2.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    try {
        Curso matematica("Matematica");
        Curso economia("Economia");

        vector<Curso> cursos;
        

        auto estudiante1 = make_shared<Estudiante>("Juancito Rodriguez",
            vector<tuple<string, double>>{{"Analisis", 9.0}, {"Fisica", 7.6}}, 12345);
        auto estudiante2 = make_shared<Estudiante>("Maria Gonzalez",
            vector <tuple<string, double>>{{"Historia", 8.0}, {"Geografia", 7.5}}, 67890);
        auto estudiante3 = make_shared<Estudiante>("Carlos Perez",
            vector<tuple<string, double>>{{"Analisis", 6.0}, {"Programacion", 4.3}}, 54321);

        vector<shared_ptr<Estudiante>> estudiantes = { estudiante1, estudiante2, estudiante3 };

        std::cout << "Inscribiendo estudiantes..." << std::endl;
        matematica.inscribir(estudiante1);
        matematica.inscribir(estudiante2);
        matematica.inscribir(estudiante3);
        matematica.print();
        
        cursos.push_back(matematica);
        cursos.push_back(economia);
        
        
        
        menu(&cursos, &estudiantes);

    } catch (const std::exception& e) {
        std::cerr << "Se produjo una excepción: " << e.what() << std::endl;
    } catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;
    }

    return 0;
}
