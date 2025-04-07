#include <iostream>
#include "ej4.h"

using namespace std;

int main() {
    
    auto caja = make_shared<CajaDeAhorro>("Juan", 1000);

    CuentaCorriente cuenta("Juan", 100, caja);

    cout << "\n== Estado inicial ==" << endl;
    caja->mostrarInfo();
    cuenta.mostrarInfo();

    cout << "\n== Intento de retiro de $50 desde cuenta corriente ==" << endl;
    cuenta.retirar(50); 
    cuenta.mostrarInfo();

    cout << "\n== Intento de retiro de $200 desde cuenta corriente ==" << endl;
    cuenta.retirar(200);  

    cout << "\n== Intento de retiro de $2000 desde cuenta corriente ==" << endl;
    cuenta.retirar(2000);  

    cout << "\n      == Resultado ==" << endl;
    caja->mostrarInfo();
    cuenta.mostrarInfo();

    cout << "deposito 100 en ambas cuentas" << endl;
    cuenta.depositar(100);
    caja->depositar(100);

    cout << "\n      == Resultado ==" << endl;
    cuenta.mostrarInfo();
    caja->mostrarInfo();

    return 0;
}
