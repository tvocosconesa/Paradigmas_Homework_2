#include "ej2.h"
#include <iostream>
#include <vector>
#include <memory>

int main() {
    try {
        // Crear cursos
        Curso matematica("Matematica");
        Curso economia("Economia");

        vector<Curso> cursos;
        

        // Crear estudiantes
        auto estudiante1 = make_shared<Estudiante>("Juancito Rodriguez",
            vector<tuple<string, int>>{{"Analisis", 9}, {"Fisica", 7}}, 12345);
        auto estudiante2 = make_shared<Estudiante>("Maria Gonzalez",
            vector <tuple<string, int>>{{"Historia", 8}, {"Geografia", 7}}, 67890);
        auto estudiante3 = make_shared<Estudiante>("Carlos Perez",
            vector<tuple<string, int>>{{"Analisis", 6}, {"Programacion", 4}}, 54321);

        std::vector<std::shared_ptr<Estudiante>> estudiantes = { estudiante1, estudiante2, estudiante3 };

        // Inscribir estudiantes en el curso
        std::cout << "Inscribiendo estudiantes..." << std::endl;
        matematica.inscribir(estudiante1);
        matematica.inscribir(estudiante2);
        matematica.inscribir(estudiante3);
        matematica.print();
        
        cursos.push_back(matematica);
        cursos.push_back(economia);
        // Llamar a menu con referencias para evitar copias
        menu(&cursos, &estudiantes);

    } catch (const std::exception& e) {
        std::cerr << "Se produjo una excepción: " << e.what() << std::endl;
    } catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;
    }

    return 0;
}
