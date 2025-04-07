#include "clases.cpp"
int main() {
    // Test con Enteros
    shared_ptr<Numeros> e1 = make_shared<Enteros>(5);
    shared_ptr<Numeros> e2 = make_shared<Enteros>(3);

    auto e_suma = dynamic_pointer_cast<Enteros>(e1->suma(e2));
    auto e_resta = dynamic_pointer_cast<Enteros>(e1->resta(e2));
    auto e_producto = dynamic_pointer_cast<Enteros>(e1->producto(e2));

    cout << "Enteros: 5 y 3 " << endl; 
    cout << "Suma: " << e_suma->toString() << endl;
    cout << "Resta: " << e_resta->toString() << endl;
    cout << "Producto: " << e_producto->toString() << endl;

    // Test con Reales
    shared_ptr<Numeros> r1 = make_shared<Reales>(5.5);
    shared_ptr<Numeros> r2 = make_shared<Reales>(2.0);

    auto r_suma = dynamic_pointer_cast<Reales>(r1->suma(r2));
    auto r_resta = dynamic_pointer_cast<Reales>(r1->resta(r2));
    auto r_producto = dynamic_pointer_cast<Reales>(r1->producto(r2));

    cout << "\nReales: 5.5 y 2.0 " << endl;;
    cout << "Suma: " << r_suma->toString() << endl;
    cout << "Resta: " << r_resta->toString() << endl;
    cout << "Producto: " << r_producto->toString() << endl;

    // Test con Complejos
    shared_ptr<Numeros> c1 = make_shared<Complejos>(complex<double>(1.0, 2.0));  //  -> 1 + 2i
    shared_ptr<Numeros> c2 = make_shared<Complejos>(complex<double>(3.0, -1.0)); //  -> 3 - i

    auto c_suma = dynamic_pointer_cast<Complejos>(c1->suma(c2));
    auto c_resta = dynamic_pointer_cast<Complejos>(c1->resta(c2));
    auto c_producto = dynamic_pointer_cast<Complejos>(c1->producto(c2));

    cout << "\nComplejos: (1+2i) y (3-i) " << endl;
    cout << "Suma: " << c_suma->toString() << endl;
    cout << "Resta: " << c_resta->toString() << endl;
    cout << "Producto: " << c_producto->toString() << endl;

    return 0;
}