#include "ej4.h"

void CajaDeAhorro::retirar(double monto) {

    if (monto > balance) throw runtime_error ("Error: No se puede retirar mas dinero del que se encuentra en la cuenta");

    balance -= monto;
}

void CajaDeAhorro::depositar(double monto) {
    balance += monto;
}

void CajaDeAhorro :: mostrarInfo() {

    if (contador_info == 2){
        balance -= 20;
        contador_info == 0;
        cout << "Se an restado $20.0 del balance de \n la cuenta debido  a la cantidad de accesos \n solicitados a la info" << endl;
        cout << "-----------------------------------" << endl;

    }

    cout << "   Info de Caja de ahorro" << endl;
    cout << "---------------------------------------" << endl;
    cout << " - Balance: $" << fixed << setprecision(2) << balance << std::endl;
    cout << " - Titular de la cuenta: " << titular << endl;
    cout << "---------------------------------------" << endl;
}

void CuentaCorriente :: retirar(double monto) {

    if( balance >= monto) balance -= monto;

    else if (Cuenta_Vinculada && Cuenta_Vinculada->balance >= monto) {
        cout << "Dinero insuficiente en Cuenta Corriente." << endl;
        cout << "Procedo a retirar de caja de ahorro." << endl;
        Cuenta_Vinculada ->balance -= monto;
    }

    else cout << "Fondos insuficientes en ambas cuentas" << endl;
}



void CuentaCorriente::depositar(double monto) {
    balance += monto;
}

void CuentaCorriente :: mostrarInfo(){

    cout << "   Info de Cuenta Corriente" << endl;
    cout << "---------------------------------------" << endl;
    cout << " - Balance: $" << fixed << setprecision(2) << balance << std::endl;
    cout << " - Titular de la cuenta: " << titular << endl;
    cout << "---------------------------------------" << endl;
}
