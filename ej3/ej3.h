#include <iostream>
#include <complex>
#include <string>
#include <iomanip>
#include <array>
#include <tuple>
#include <memory>
using namespace std;

class Numeros{
    public:
    virtual shared_ptr<Numeros> suma(const shared_ptr <Numeros>& otro) const = 0;
    virtual shared_ptr<Numeros> resta(const shared_ptr<Numeros>& otro) const = 0;
    virtual shared_ptr<Numeros> producto(const shared_ptr<Numeros>& otro) const = 0;

    virtual void toString() const = 0;
};

