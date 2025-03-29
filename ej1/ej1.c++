#include "ej1.h"

int main(){
    
    try{
        
        Reloj mi_reloj(11, 24, 30 , "a.m.");
        mi_reloj.mostrarHora();
        mi_reloj.mostrarHora();
        mi_reloj.interface();
        mi_reloj.mostrarHora();
        mi_reloj.changeFormat();


    }
    
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }
    
}



    