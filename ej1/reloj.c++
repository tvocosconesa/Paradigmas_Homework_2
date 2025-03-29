#include "ej1.h"
#include <iostream>

Reloj::Reloj() : hour(0), min(0), sec(0), nm("a.m.") {}


Reloj::Reloj(int hour) : min(0), sec(0), nm("a.m.") {
    if (hour < 0 || hour >= 12) throw runtime_error("ERROR: Invalid hour inserted");
    this->hour = hour;
}


Reloj::Reloj(int hour, int min) : sec(0), nm("a.m.") {
    if (hour < 0 || hour >= 12) throw runtime_error("ERROR: Invalid hour inserted");
    if (min < 0 || min >= 60) throw runtime_error ( "ERROR: Invalid min inserted");
    this->hour = hour;
    this->min = min;
}


Reloj::Reloj(int hour, int min, int sec) : nm("a.m.") {
    if (hour < 0 || hour >= 12) throw runtime_error("ERROR: Invalid hour inserted");
    if (min < 0 || min >= 60) throw  runtime_error("ERROR: Invalid min inserted");
    if (sec < 0 || sec >= 60) throw runtime_error("ERROR: Invalid sec inserted");
    this->hour = hour;
    this->min = min;
    this->sec = sec;
}


Reloj::Reloj(int hour, int min, int sec, std::string nm) {
    if (hour < 0 || hour >= 12) throw runtime_error("ERROR: Invalid hour inserted");
    if (min < 0 || min >= 60) throw runtime_error("ERROR: Invalid min inserted");
    if (sec < 0 || sec >= 60) throw runtime_error("ERROR: Invalid sec inserted");
    if (nm != "a.m." && nm != "p.m.") throw runtime_error("ERROR: Invalid meridian position inserted");
    this->hour = hour;
    this->min = min;
    this->sec = sec;
    this->nm = nm;
}


int Reloj::getHour() { return hour; }

int Reloj::getMin() { return min; }

int Reloj::getSec() { return sec; }

string Reloj::getMeridian() { return nm; }

void Reloj::mostrarHora() const {
    cout << "Hora: " 
         << setw(2) << setfill('0') << hour << ":" 
         << setw(2) << setfill('0') << min << ":" 
         << setw(2) << setfill('0') << sec << " " 
         << nm << endl;
}

void  Reloj::changeTime(int n, int change){
    if (n > 4 || n < 1) throw runtime_error("ERROR: invalid option inserted");

    switch(n){

        case 1: 
            if (change < 0 || change >= 12) throw runtime_error("ERROR: Invalid hour inserted");
            hour = change;
            break;
        
        case 2: 
            if ( change < 0 || change >= 60) throw runtime_error("ERROR: Invalid min inserted");
            min = change;
            break;
      
        case 3: 
            if (change < 0 || change >= 60) throw runtime_error("ERROR: Invalid sec inserted");
            sec = change; 
            break;
    }
}

void Reloj:: changeTime(int n, string change){
    if(change != "a.m." && change != "p.m.") throw runtime_error("ERROR: Invalid nm inserted");
    nm = change;
}

void Reloj:: changeFormat(){
    if (nm == "p.m.") hour = hour + 12;
    cout << "Hora: " 
         << setw(2) << setfill('0') << hour << ":" 
         << setw(2) << setfill('0') << min << ":" 
         << setw(2) << setfill('0') << sec << " "
         << endl;

}

void Reloj::interface (){
    int option;
    cout << "What would you want to do? : \n 1) Change setted time \n 2) Print time \n ---> ";

    cin >> option;
    cin.ignore();
    if (option != 1 && option != 2) throw runtime_error("ERROR: Invalid option inserted ");
    
    if (option == 1){
        int n;
        cout << "Time change! select what would you like yo change: \n 1) Hour \n 2) minutes \n 3) seconds \n 4) meridiem positions (am / pm) \n ---> ";
        
        cin >> n;
        cin.ignore();

        if(n == 4){
            string change;
            cout << "Insert your change: \n --->";
            cin >> change;
            cin.ignore();
            changeTime(n, change);

        }
        else{
            int change;
            cout << "Insert your change: \n --->";
            cin >> change;
            cin.ignore();
            changeTime(n, change);
        } 
    }

}
