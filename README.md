# Paradigmas Homework 2
### Tomas Vocos Conesa


## Como correr el codigo.
Todos los ejercicios tienen un Makefile en su respectiva carpeta. En el mismo hice que se pueda correr el ej con el comando make run por terminal. una vez el codigo halla sido ejecutado y la operacion termine su ejecutable sera destruido automaticamente
pasos:
1. Abrir terminal 
2. Entrar a la carpeta deseada con cd ejn (n = num de ejercicio)
3. Ejecutar el codigo con make run 

# Ej1
Para este ejercicio usé tres archivos: 
- ej1.h : Header de mi ejercicio. En este archivo tengo establecida mi clase Reloj junto con la declaracion de sus atributos y metodos.
- reloj.c++ : En este archivo tengo las implementaciones de los metodos de mi clase Reloj
- main.c++ : En mi main hice un pequeño menu con para que el usuario pueda interactuar de forma directa con un objeto Reloj, y pueda probar todas sus funciones

## Class Reloj:
Mi clase reloj crea un objeto al cual uno le puede establecer una hora, modificarla, cambiar su formato, etc.

## Atributos:
- int hour: Hora establecida en el reloj 
- int min : minutos establecidos en el reloj 
- int sec : segundos establecidos en el reloj
- string nm: parte del dia (pm / am). notado nm por "notacion del meridiano"

## Metodos:
### Constructores:
el constructor Reloj::Reloj(): devuelve un objeto reloj con su hora setteada en 00:00:00 a.m. como una opcion predeterminada.
el constructor puede ser llamado vacio, solo con la hora, con hora y mins, hora mins y secs y hora mins secs y am o pm. las variables no aclaradas en cada caso se settean a 00 o a.m. por defecto.

### funciones:
- GetHour(), getMin(), getSec() y getMeridian() devuelven los correspondientes atributos del objeto Reloj.
- mostrarHora(): Muestra la hora formateada con ceros a la izquierda y el meridiano (a.m./p.m.).
- changeTime(int n, int change): Cambia hora, minutos o segundos según la opción elegida (n de 1 a 3). Valida el nuevo valor.
- changeTime(string change) :Cambia el meridiano a "a.m." o "p.m.".
- changeFormat() : Convierte el formato de 12 horas a 24 horas (solo suma 12 si es "p.m."), saca el a.m o p.m. y muestra la hora en este nuevo formato.
- interfaceDeCambios(): Interfaz por consola para que el usuario elija qué parte de la hora desea modificar e ingrese el nuevo valor.