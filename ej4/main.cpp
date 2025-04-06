#include <iostream>
#include "ej4.h"

using namespace std;

int main() {
    // Crear una caja de ahorro con $1000
    auto caja = make_shared<CajaDeAhorro>("Juan", 1000);

    // Crear una cuenta corriente con $100 y vincularla con la caja de ahorro
    CuentaCorriente cuenta("Juan", 100, caja);

    cout << "\n== Estado inicial ==" << endl;
    caja->mostrarInfo();
    cuenta.mostrarInfo();

    cout << "\n== Intento de retiro de $50 desde cuenta corriente ==" << endl;
    cuenta.retirar(50);  // Debería restar de cuenta corriente

    cout << "\n== Intento de retiro de $200 desde cuenta corriente ==" << endl;
    cuenta.retirar(200);  // Debería usar la caja de ahorro

    cout << "\n== Intento de retiro de $2000 desde cuenta corriente ==" << endl;
    cuenta.retirar(2000);  // No debería poder

    cout << "\n== Estado final ==" << endl;
    caja->mostrarInfo();
    cuenta.mostrarInfo();

    cout << "deposito 100 en ambas cuentas" << endl;
    cuenta.depositar(100);
    caja->depositar(100);

    cout << "Resultado:" << endl;
    cuenta.mostrarInfo();
    caja->mostrarInfo();

    return 0;
}
