#include "ej2.h"

void menu(vector<Curso>* cursos, vector< shared_ptr < Estudiante>>* estudiantes){
    int option;
        
    do{
        cout << "\n";
        cout << "                   Menú                  " << endl;
        cout << " ----------------------------------------" << endl;
        cout << " 1) Mostrar cursos" << endl;
        cout << " 2) Crear curso nuevo" << endl;
        cout << " 3) Crear alumno nuevo" << endl;  
        cout << " 4) Incribir alumno a un curso" << endl;
        cout << " 5) Desinscribir alumno de un curso" << endl;
        cout << " 6) Mostrar alumnos de un curso" << endl;
        cout << " 7) Verificar si esta completo un curso" << endl;
        cout << " 8) Buscar alumno" << endl;
        cout << " 9) Finalizar operacion" << endl;
        cout << " ----------------------------------------" << endl;
        cout << "Ingrese su opcion: ";
        cin >> option;
        cout << "\n";
        switch (option){
        
            case 1:

                cout << "            Cursos" << endl;
                cout << "------------------------------\n" << endl;

                for (int i = 0 ; i < cursos->size(); i++){ cout << i+1 << ") " << (*cursos)[i].get_name() << endl;}

                break;
            case 2:{ // crear curso nuevo 
                string name;
                string option;
                cout << "      creación de curso" << endl;
                cout << "------------------------------\n";
                cout << "Ingrese el nombre de su nuevo curso: ";
                getline(cin >> ws , name);
                cin.ignore();

                cout << "\n Este nuevo curso comparte alumnos con otro? (si / no): ";
                getline(cin >> ws , option);
                cin.ignore();
                if (option == "si") {
                    int selected;
                    cout << "Cursos:" << endl;
                    cout << "------------------------------" << endl;
                    for (int i = 0 ; i < cursos->size(); i++){ cout << i+1 << ") " << (*cursos)[i].get_name() << endl;}
                    cout << "Seleccione un curso: ";
                    cin >> selected;
                    
                    Curso new_curso = (*cursos)[selected-1];
                    new_curso.set_name(name);
                    cursos->push_back(new_curso);
                }
                
                else{
                    Curso new_curso(name);
                    cursos->push_back(new_curso);
                }
                
                break;
            }
            case 3:{    //crear alumno nuevo 
                string name;
                int legajo;
                int nro_materias;
                vector<tuple < string, double>> clases;
                cout << "\n Ingrese el nombre del nuevo alumno:" ;
                getline(cin >> ws, name);

                cout << "\n Ingrese el numero de legajo del nuevo alumno:" ;
                cin >> legajo;
                cin.ignore();
                
                cout << "\n Cuantas materias tiene ya cursadas este alumno?:" ;
                cin >> nro_materias;
                cin.ignore();

                for(int i = 0 ; i < nro_materias ; i++){
                    string clase;
                    double nota;
                    cout << "ingrese el nombre de la clase nro " << i+1 << ": " << endl;
                    getline(cin >> ws, clase);
                    
                    cout << "Ingrese la nota final en esta clase: " << endl;
                    cin >> nota;
                    cin.ignore();

                    clases.push_back(make_tuple(clase, nota));
                }
                auto estudiante = make_shared<Estudiante>(name ,clases, legajo);
                estudiantes->push_back(estudiante);
                cout << "Estudiante agregado: " << estudiante->getName() << ", Legajo: " << estudiante->getLegajo() << endl;

                
                break;
            }
            case 4:{ // inscribir alumno al curso 
                int option;
                int legajo;
                cout << "          Inscripcion:";
                cout << "------------------------------\n";
                cout << "Cursos: \n";
                for (int i = 0 ; i < cursos->size(); i++){ cout << i+1 << ") " << (*cursos)[i].get_name() << endl;}
                cout << "\n Seleccione el curso al cual desea inscribir un alumno: ";
                cin >> option;
                cin.ignore();
                if ((*cursos)[option-1].completo()) {
                    cout << "El curso esta lleno, no es posible ingresar al alumno en este momento" << endl;
                    break;
                }
                cout << "Ingrese el legajo del estudiante al que desea inscribir: ";
                cin >> legajo;
                if ((*cursos)[option-1].search(legajo)){cout << "El alumno ya se encuentra inscripto al curso." << endl; break;}

                for(int i = 0 ; i < estudiantes->size(); i++){
                    if ((*estudiantes)[i]->getLegajo() == legajo){
                        (*cursos)[option-1].inscribir((*estudiantes)[i]);
                    };
                }

                break;
            }
            case 5:{
                int option;
                int legajo;
                cout << "        Desinscripción:" << endl;
                cout << "------------------------------\n";
                cout << "Cursos: \n";
                for (int i = 0 ; i < cursos->size(); i++){ cout << i+1 << ") " << (*cursos)[i].get_name() << endl;}
                cout << "\n Seleccione el curso del cual desea desinscribir un alumno: ";
                cin >> option;
                cin.ignore();
                cout << "\n Ingrese el legajo del alumno el cual desea desinscribir: ";
                cin >> legajo;
                cin.ignore();

                if (!(*cursos)[option-1].search(legajo)) { cout << "El alumno no se encuentra en el curso seleccionado"; break;}

                (*cursos)[option-1].desinscribir(legajo);
                             

                break;
            }
            case 6: {   // mostrar alumnos de un curso
                if (cursos->empty()) {
                    cout << "No hay cursos disponibles para mostrar." << endl;
                    break;
                }
            
                int n;
                cout << "      Seleccione un curso:" << endl;
                cout << "------------------------------" << endl;
                for (int i = 0; i < cursos->size(); i++) { 
                    cout << i+1 << ") " << (*cursos)[i].get_name() << endl;
                }
                cout << "---> ";
                cin >> n;
            
                if (cin.fail() || n < 1 || n > cursos->size()) {
                    cin.clear(); 
                    cin.ignore(); 
                    cout << "Opción inválida. Por favor, seleccione un curso válido." << endl;
                    break;
                }
            
                (*cursos)[n-1].print();
                break;
            }
                
            case 7: 
                int m;
                cout << " Seleccione un curso: " << endl;
                cout << "------------------------------" << endl;
                for (int i = 0 ; i < cursos->size(); i++){ cout << i+1 << ") " << (*cursos)[i].get_name() << endl;}
                cout << "--->";
                cin >> m;

             
               if ((*cursos)[m-1].completo()) cout << "El curso está lleno. " << endl;
                
                else cout << "El curso no está lleno" << endl;

                break;
            case 8:  {// Buscar alumno 
                int legajo;
                bool found = false;  

                cout << "     Busqueda de alumno:" << endl;
                cout << "------------------------------" << endl;
                cout << " Ingrese el legajo del alumno buscado: ";
                cin >> legajo;
                cin.ignore();

                for (int i = 0 ; i < estudiantes->size() ; i++){
                    if ((*estudiantes)[i]->getLegajo() == legajo){
                        cout << "\n Estudiante: encontrado" << endl;
                        cout << "\n   Perfil estudiantil:" << endl;
                        cout << "------------------------------" << endl;
                        cout << " - Nombre: " << (*estudiantes)[i]->getName() << endl;  // ERROR: Antes imprimías 'legajo' en lugar del nombre
                        cout << " - Legajo: " << (*estudiantes)[i]->getLegajo() << endl;
                        cout << "\nMaterias ya cursadas: " << endl;
                        cout << "-----------------------" << endl;
                
                        
                        vector<tuple<string, double>> clases = (*estudiantes)[i]->getClases();
                        if (clases.size() > 0 ){
                            for (int j = 0 ; j < clases.size() ; j++ ){ 
                                cout << j+1 << ") " << get<0>(clases[j]) << ": " << get<1>(clases[j]) << endl;
                            }
                            cout << "Promedio general: " << (*estudiantes)[i]->promedio() << endl;
                            cout << "\n";
                        }

                        else{
                            cout << "El alumno no tiene materias cerradas, no hay notas cargadas" << endl;
                        }
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    cout << "-------------------------------------------------" << endl;
                    cout << "El alumno buscado no existe en la base de datos" << endl;
                    cout << "-------------------------------------------------" << endl;
                }
                break;
            }
            }

    } while (option != 9);

    cout << "------------------------------ \n";
    cout << "    Programa Finalizado."      << endl;
    cout << "------------------------------";

}