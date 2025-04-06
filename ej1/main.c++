#include "ej1.h"

using namespace std;

int main() {
    try {
        int option;
        cout << "        Reloj digital: " << endl;
        cout << "------------------------------" << endl;
        cout << "\n      Inicie su reloj:" << endl;
        cout << "------------------------------" << endl;
        cout << "   Opciones:" << endl;
        cout << " 1) Inicio default (00:00:00 a.m.): " << endl;
        cout << " 2) Inicio con solo hora (HH:00:00 a.m.): " << endl;
        cout << " 3) Inicio con hora y minutos (HH:MM:00 a.m.): " << endl;
        cout << " 4) Inicio con hora, minutos y segundos (HH:MM:SS a.m.): " << endl;
        cout << " 5) Inicio con todos los valores (HH:MM:SS am/pm): " << endl;
        cout << "\n Ingrese su opcion: ";
        cin >> option;
        cin.ignore();

        shared_ptr<Reloj> mireloj;  

        switch (option) {
            case 1:
                mireloj = make_shared<Reloj>();
                break;
            case 2: {
                int hs;
                cout << "Ingrese hora: ";
                cin >> hs;
                mireloj = make_shared<Reloj>(hs);
                break;
            }
            case 3: {
                int hs, min;
                cout << "Ingrese hora: ";
                cin >> hs;
                cout << "Ingrese minutos: ";
                cin >> min;
                mireloj = make_shared<Reloj>(hs, min);
                break;
            }
            case 4: {
                int hs, min, sec;
                cout << "Ingrese hora: ";
                cin >> hs;
                cout << "Ingrese minutos: ";
                cin >> min;
                cout << "Ingrese segundos: ";
                cin >> sec;
                mireloj = make_shared<Reloj>(hs, min, sec);
                break;
            }
            case 5: {
                int hs, min, sec;
                string nm;
                cout << "Ingrese hora: ";
                cin >> hs;
                cout << "Ingrese minutos: ";
                cin >> min;
                cout << "Ingrese segundos: ";
                cin >> sec;
                cout << "Seleccione a.m. o p.m.: ";
                cin >> nm;
                mireloj = make_shared<Reloj>(hs, min, sec, nm);
                break;
            }
            default:
                cout << "Opción inválida." << endl;
                return 1;
        }

        // Usás el reloj como puntero -> con flecha (->)
        cout << "\nEstado actual del reloj:\n";
        mireloj->mostrarHora();

        // Acá podés usar un bucle interactivo:
        char seguir;
        do {
            cout << "\nOpciones del menú:\n";
            cout << "1) Mostrar hora\n";
            cout << "2) Cambiar formato\n";
            cout << "3) Cambiar hora \n" ;
            cout << "4) Salir\n";
            cout << "Seleccione opción: ";
            int op;
            cin >> op;

            switch(op) {
                case 1:
                    mireloj->mostrarHora();
                    break;
                case 2:
                    mireloj->changeFormat();
                    break;
                
                case 3:
                    mireloj ->interfaceDeCambios();
                    break;
                case 4:
                    cout << "Saliendo...\n";
                    return 0;
                default:
                    cout << "Opción inválida.\n";
            }

            cout << "\n¿Desea continuar? (s/n): ";
            cin >> seguir;

        } while (seguir == 's' || seguir == 'S');

    } catch(const exception& e) {
        cerr << "Error: " << e.what() << '\n';
    }
}
