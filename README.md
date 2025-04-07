# Paradigmas Homework 2
### Tomas Vocos Conesa

---

## Como correr el codigo.
Todos los ejercicios tienen un `Makefile` en su respectiva carpeta. En el mismo hice que se pueda correr el ej con el comando `make run` por terminal. una vez el codigo halla sido ejecutado y la operacion termine su ejecutable sera destruido automaticamente  
pasos:
1. Abrir terminal  
2. Entrar a la carpeta deseada con `cd ejn` (n = num de ejercicio)  
3. Ejecutar el codigo con `make run`  

---

# Ej1:
Para este ejercicio usé tres archivos: 
- `ej1.h` : Header de mi ejercicio. En este archivo tengo establecida mi clase `Reloj` junto con la declaracion de sus atributos y metodos.
- `reloj.c++` : En este archivo tengo las implementaciones de los metodos de mi clase `Reloj`
- `main.c++` : En mi `main` hice un pequeño menu con para que el usuario pueda interactuar de forma directa con un objeto `Reloj`, y pueda probar todas sus funciones

## Class Reloj:
Mi clase `Reloj` crea un objeto al cual uno le puede establecer una hora, modificarla, cambiar su formato, etc.

## Atributos:
- `int hour`: Hora establecida en el reloj  
- `int min` : minutos establecidos en el reloj  
- `int sec` : segundos establecidos en el reloj  
- `string nm`: parte del dia (`pm` / `am`). notado `nm` por "notacion del meridiano"

## Metodos:

### Constructores:
el constructor `Reloj::Reloj()` devuelve un objeto `Reloj` con su hora setteada en `00:00:00 a.m.` como una opcion predeterminada.  
el constructor puede ser llamado vacio, solo con la hora, con hora y `mins`, `hora mins y secs` y `hora mins secs` y `am o pm`. las variables no aclaradas en cada caso se settean a `00` o `a.m.` por defecto.

### funciones:
- `GetHour()`, `getMin()`, `getSec()` y `getMeridian()` devuelven los correspondientes atributos del objeto `Reloj`.
- `mostrarHora()`: Muestra la hora formateada con ceros a la izquierda y el meridiano (`a.m.`/`p.m.`).
- `changeTime(int n, int change)`: Cambia hora, minutos o segundos según la opción elegida (n de 1 a 3). Valida el nuevo valor.
- `changeTime(string change)`: Cambia el meridiano a `"a.m."` o `"p.m."`.
- `changeFormat()`: Convierte el formato de 12 horas a 24 horas (solo suma 12 si es `"p.m."`), saca el `a.m` o `p.m.` y muestra la hora en este nuevo formato.
- `interfaceDeCambios()`: Interfaz por consola para que el usuario elija qué parte de la hora desea modificar e ingrese el nuevo valor.

---

# Ej2:
En este ejercicio implementé las clases `Curso` y `Estudiantes` para poder hacer un sistema de gestion de alumnos y clases. Cuando una vez ejecutado el archivo se van a crear algunos cursos y estudiantes, y se va a abrir un menu para darle la posibilidad al usuario de mostrar cursos, buscar estudiantes y obtener sus datos, crear estudiantes y cursos nuevos, inscribir y desinscribir estudiatnes, etc.

### Relacion entre las clases:
La clase `Curso` y `Estudiante` tienen una relacion de tipo *Agregacion* ya que hay un objeto que funciona como un "whole" (`Curso`) y otros los cuales son partes que conforman el mismo (`Estudiantes`). Asimismo tambien por el hecho de que no hay una dependencia total entre las clases, el ciclo de vida de un objeto no depende del otro, Puede haber un estudiante sin curso y un curso sin estudiantes.

### Copia de curso:
A la hora de crear un nuevo `Curso` doy la opcion de que este este basado en otro curso preexistente. De esta manera si los cursos estan relacionados o comparte alumnos con otro todos los alumnos de un curso van a parar a este nuevo. Para esto hago una *shallow copy* del curso. No se crean nuevas instancias de los objetos `Estudiante`, sino que ambos cursos comparten punteros a los mismos estudiantes. Esto se logra utilizando `shared_ptr`, de manera que los vectores de estudiantes de ambos cursos apuntan a los mismos objetos en memoria. 

## Archivos:
- `ej2.h` : Header donde tengo declaradas mis clases y sus metodos  
- `Curso.cpp` : Implementaciones de los metodos de mi clase `Curso`  
- `estudiante.cpp` : Implementaciones de los metodos de mi clase `Estudiante`  
- `menu.cpp` : funcion de menu para poder interactuar con las funcionalidades de los `Cursos` y `Estudiantes`.  
- `main.cpp` : Hardcodeo de algunos alumnos y cursos para usar al correr el codigo, junto con vectores para almacenar los estudiantes y cursos totales, y llama a el menu.

---

# Ej3:
En este ejercicio creo una clase de tipo interfaz `Numero` en base a la cual se van a crear tres sub-clases que salen de la misma y comparten sus metodos virtuales. Las sub clases representan distintos tipos de numeros: `Enteros`, `Reales` y `Complejos`. debido a que poseen caracteristicas distintas tuve que operar con los mismos y declarar sus atributos de maneras diferentes. Todos tienen un atributo `value`, el cual dependiendo de la clase tiene distinto `type`:  
`Enteros -> int` , `Reales -> double` y `Complejos -> complex<double>`.  
En el caso de los complejos utilicé la libreria `complex` para poder operar mas comodamente con los mismos.

## Archivos:
- `ej3.h` : El header del ejercicio, aca tengo declarada la interfaz `Numeros`.  
- `clases.cpp` : En este archivo se encuentran las declaraciones e implementaciones de las subclases de numeros. Como este ejercicio se enfoca mayormente en la implementacion de estas decidi que el archivo source incluyera sus declaraciones e implementaciones completas.  
- `main.cpp`: En el `main` tengo un par de ejemplos con cada subclase donde muestro los resultados de operaciones con el metodo `toString`.

---

# Ej4:
En este ejercicio tengo una clase abrstracta `CuentaGeneral` de la cual derivan dos clases `CuentaCorriente` y `CajaDeAhorro`. mediante estas simulo un sistema bancario en el cual puedo depositar y retirar dinero de las distintas cuentas. `CajaDeAhorro` y `CuentaCorriente` son `friends`, de esta manera puedo desde la cuenta corriente acceder a la caja de ahorro si es que no tengo suficiente dinero para retirar en la cuenta corriente.

### Atributos:
- atributos `titular` y `balance`:  Son los prinicipales de las cuentas se encuentran de manera privada. Esto se debe a que en el caso de que el usuario quiera ver quien es el titular de la cuenta o el balance de la misma tiene la funcion `mostrarInfo`.  
- `Contador_info`:  `CajaDeAhorro` tiene un contador para ir monitoreando la cantidad de veces que se accede a la info de la cuenta, esto me ayuda a la hora de restarle $20 al balance cuando esto se hace mas de 2 veces. Este atributo es privado ya que es algo del funcionamiento interno del sistema y no deberia ser algo de acceso publico para el usuario.  
- `Cuenta_Vinculada`: La `CuentaCorriente` tiene acceso a su respectiva `CajaDeAhorro` mediante este atributo, el cual es un `shared_ptr` a la misma. Este atributo tambien es privado ya que la unica situacion en la cual el usuario tiene que acceder a la caja de ahorro mediante la cuenta corriente es cuando no hay mas dinero en la cuenta corriente y se quiere retirar dinero. Este es un caso que es tenido en cuenta internamente en el metodo de retirar dinero, por lo tanto no es necesario que el usuario tenga acceso a este atributo.

## Archivos:
- `ej4.h`: Header del ejercicio, aca se declaran las tres clases, sus metodos y atributos  
- `implementaciones.cpp`: En este archivo tengo todas las implementaciones de los metodos de las clases  
- `main.cpp`: Al ser ejecutado muestra ejemplos del funcionamiento del codigo con depositos, retiros, etc.
