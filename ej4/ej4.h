#include <iostream>
#include <string>
#include <array>
#include <iomanip>
#include <tuple>
#include <memory>
#include <vector>
using namespace std;

class Cuenta_general { 

    private:
    double balance;
    string titular;

    public:
    void depositar(double monto){
        balance += monto;
    };

    virtual void retirar(double monto)  = 0;
    virtual void mostrarInfo()  = 0;
};

class CajaDeAhorro : public Cuenta_general{
    friend class CuentaCorriente;

    private:
    double balance;
    string titular;
    int contador_info; // contador de la cntidad de veces que accedo a mosrtar info
    public:

    CajaDeAhorro(string titular , double balance): titular(titular) , balance(balance) , contador_info(0) {}

    void depositar(double monto) ;
    void retirar(double monto ) override;
    void mostrarInfo() override;

};

class CuentaCorriente : public Cuenta_general{
    friend class CajaDeAhorro;

    private:
    double balance;
    string titular;
    shared_ptr<CajaDeAhorro> Cuenta_Vinculada;

    public:
    CuentaCorriente(string titular , double balance, shared_ptr<CajaDeAhorro> caja): titular(titular) , balance(balance), Cuenta_Vinculada(caja) {}
    void depositar(double monto);
    void retirar(double monto ) override;
    void mostrarInfo() override;
};