#include "ej2.h"
#include <iostream>

int main() {
    try {
        // Crear un curso
        Curso curso;

        // Crear estudiantes
        Estudiante estudiante1("Juancito Rodriguez",{{"matematica", 9}, {"fisica", 7}}, 12345);
        Estudiante estudiante2("Maria Gonzalez", {{"historia", 8}, {"geografia", 7}}, 67890);        
        Estudiante estudiante3("Carlos Perez", {{"matematica", 6} , {"Programacion" , 4}} ,54321);

        //Inscribir estudiantes en el curso
        std::cout << "Inscribiendo estudiantes..." << std::endl;
        curso.inscribir(estudiante1);
        curso.inscribir(estudiante2);
        curso.inscribir(estudiante3);

        // Imprimir el estado del curso
        std::cout << "Estado del curso después de inscribir estudiantes:" << endl;
        curso.print();

        cout << "promedio de juantito: " << estudiante1.promedio() << endl;


        // Buscar un estudiante por su legajo
        int legajoBuscado = 12345;
        std::cout << "Buscando estudiante con legajo " << legajoBuscado << "..." << std::endl;
        if (curso.search(legajoBuscado)) {
            std::cout << "Estudiante con legajo " << legajoBuscado << " encontrado." << std::endl;
        } else {
            std::cout << "Estudiante con legajo " << legajoBuscado << " no encontrado." << std::endl;
        }

        // Verificar si el curso está completo
        std::cout << "¿El curso está completo? " << (curso.completo() ? "Sí" : "No") << std::endl;

        // Desinscribir un estudiante
        std::cout << "Desinscribiendo estudiante con legajo " << legajoBuscado << "..." << std::endl;
        curso.desinscribir(legajoBuscado);

        // Imprimir el estado del curso después de desinscribir
        std::cout << "Estado del curso después de desinscribir estudiantes:" << std::endl;
        curso.print();



       
    } catch (const std::exception& e) {
        std::cerr << "Se produjo una excepción: " << e.what() << std::endl;
    } catch (const char* msg) {
        std::cerr << "Error: " << msg << std::endl;
    }

    return 0;
}