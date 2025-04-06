#ifndef RELOJ_H
#define RELOJ_H
#include <iostream>
#include <memory>  
#include <string>
#include <iomanip>
using namespace std;

class Reloj {
private:
    int hour;
    int min;
    int sec;
    string nm;

public:
    // Declaración de constructores
    Reloj();
    Reloj(int hour);
    Reloj(int hour, int min);
    Reloj(int hour, int min, int sec);
    Reloj(int hour, int min, int sec, std::string nm);
    
    // Declaración de métodos
    int getHour();
    int getMin();
    int getSec();
    string getMeridian();
    void interfaceDeCambios();
    void changeTime(int n , int change);
    void changeTime(string change);
    void changeFormat();
    void mostrarHora() const;
};

#endif
