#include "ej3.h"

class Enteros : public Numeros{
    private:    
        int value;

    public:

        Enteros(int v) : value(v) {}    

        int get_value() { return value; }

        shared_ptr<Numeros> suma(const shared_ptr<Numeros>& otro) const override {
            auto otroEntero = dynamic_pointer_cast<Enteros>(otro);
            
            if (otroEntero)  return std::make_shared<Enteros>(value + otroEntero->value);
    
            throw runtime_error("Error en la suma de Enteros");
        }

        shared_ptr<Numeros> resta(const shared_ptr<Numeros>& otro) const override{
            auto otroEntero = dynamic_pointer_cast<Enteros>(otro);
            if(otroEntero) return make_shared<Enteros>(value - otroEntero->value);

            throw runtime_error("Error en la resta de Enteros");
        }

        shared_ptr<Numeros> producto(const shared_ptr<Numeros>& otro) const override{
            auto otroEntero = dynamic_pointer_cast<Enteros>(otro);

            if(otroEntero) return make_shared<Enteros>(value * otroEntero->value);

            throw runtime_error("Error en el producto de Enteros");
        }


        void toString() const override{
            cout << to_string(value) << endl;
        }
};

class Reales : public Numeros{
    private:
    double value;

    public:

    Reales (double v) : value(v) {}

    double get_value(){return value; }


    shared_ptr<Numeros> suma(const shared_ptr<Numeros>& otro) const override{
        auto otroReal = dynamic_pointer_cast<Reales>(otro);

        if(otroReal) return make_shared<Reales>(value + otroReal->value);

        throw runtime_error("Error en la suma de Reales");
    }

    shared_ptr<Numeros> resta(const shared_ptr<Numeros>& otro) const override{
        auto otroReal = dynamic_pointer_cast<Reales>(otro);

        if(otroReal) return make_shared<Reales>(value - otroReal->value);

        throw runtime_error("Error en la resta de Reales");
    }

    shared_ptr<Numeros> producto(const shared_ptr<Numeros>& otro) const override{
        auto otroReal = dynamic_pointer_cast<Reales>(otro);
    
        if(otroReal) return make_shared<Reales>(value * otroReal->value);
    
        throw runtime_error("Error en el producto de Reales");
    }

    void toString() const override{
        cout << to_string(value) << endl;
    }
};


class Complejos : public Numeros{

    private:
    complex<double> value;

    public:

    Complejos(complex<double> v) : value(v) {}

    complex<double> get_value(){return value; }


    shared_ptr<Numeros> suma(const shared_ptr<Numeros>& otro) const override{
        auto otroComplejo = dynamic_pointer_cast<Complejos>(otro);
        if (otroComplejo) return make_shared<Complejos>(value + otroComplejo->value);

        throw runtime_error("Error en la suma de Complejos");
    }

    shared_ptr<Numeros> resta(const shared_ptr<Numeros>& otro) const override{
        auto otroComplejo = dynamic_pointer_cast<Complejos>(otro);
        if (otroComplejo) return make_shared<Complejos>(value - otroComplejo->value);

        throw runtime_error("Error en la resta de Complejos");
    }

    shared_ptr<Numeros> producto(const shared_ptr<Numeros>& otro) const override{
        auto otroComplejo = dynamic_pointer_cast<Complejos>(otro);
        if (otroComplejo) return make_shared<Complejos>(value * otroComplejo->value);

        throw runtime_error("Error en el producto de Complejos");
    }

    void toString() const override{
        string s = to_string(value.real()) + "+" + to_string(value.imag()) + "i";
        cout << s << endl;
    }
};
