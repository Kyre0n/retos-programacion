#include <iostream>

/*
 * EJERCICIO:
 * - Crea ejemplos utilizando todos los tipos de operadores de tu lenguaje:
 *   Aritméticos, lógicos, de comparación, asignación, identidad, pertenencia, bits...
 *   (Ten en cuenta que cada lenguaje puede poseer unos diferentes)
 * - Utilizando las operaciones con operadores que tú quieras, crea ejemplos
 *   que representen todos los tipos de estructuras de control que existan
 *   en tu lenguaje:
 *   Condicionales, iterativas, excepciones...
 * - Debes hacer print por consola del resultado de todos los ejemplos.
 *
 * DIFICULTAD EXTRA (opcional):
 * Crea un programa que imprima por consola todos los números comprendidos
 * entre 10 y 55 (incluidos), pares, y que no son ni el 16 ni múltiplos de 3.
 *
 * Seguro que al revisar detenidamente las posibilidades has descubierto algo nuevo.
 */

void main ()
{

    int a = 0;                                          //Aquí estoy crando la variable y con un operador de asignación simple (=) le estoy diciendo que tiene valor 0

    //Ejemplos de tipos de operadores, hay más operadores en cada tipo, pero para no hacerlo muy pesado:

    //Un operador de asignación ()=+), el cual le suma 1 al valor y luego lo asigna:
    a =+ 1;
    std::cout << a << "\n";

    //Un operador de incremento/decremento puede ser (--), el cual le resta 1 al valor;
    a--;
    std::cout << a << "\n";

    //Un operador aritmético puede ser (*) y se utiliza para multiplicar dos valores
    a = a*a;
    std::cout << a << "\n";

    //Una variable lógica puede ser (!), que sirve para representar un NOT, aunque sirve para booleans, con un integer también funciona
    a = !a;
    std::cout << a << "\n";

    //Un operador de comparación puede ser (!=) y sirve para ver si son distintos y devuelve un boolean
    a = a != a;
    std::cout << a << "\n";

    //Un operador de acceso a miembros puede ser (&) y sirve para acceder a la dirección en memoria de la variable
    std::cout << &a << "\n";

    //El operador de llamada de función es el típico (a(a,b...)) por ejemplo con un printf
    printf("%d",a);

    //El operador de coma es (,) y se utiliza para ejecutar más de una expresión donde la gramática solo permite 1
    //(No confundir con la coma que se utiliza al poner argumentos en una función por ejemplo donde se separan igual pero se esperan esa cantidad de valores)
    //Ejemplo de la página:
 
    // comma is often used to execute more than one expression
    // where the language grammar allows only one expression:
 
    // * in the third component of the for loop
    for (int i = 0, j = 10; i <= j; ++i, --j)
    //            ^list separator      ^comma operator
        std::cout << "i = " << i << " j = " << j << '\n';
 
    // * in a return statement
    // return log("an error!"), -1;
 
    // * in an initializer expression
    // MyClass(const Arg& arg)
    // : member{ throws_if_bad(arg), arg }
 
    // etc.
 
    // comma operators can be chained; the result of the last
    // (rightmost) expression is the result of the whole chain:
    int n = 1;
    int m = (++n, std::cout << "n = " << n << '\n', ++n, 2 * n);
 
    // m is now 6
    std::cout << "m = " << (++m, m) << '\n';


    //Y el último tipo de operador de c++ aparte de los que catalogan en cppreference como especiales es el condicional y tiene la estructura (x ? y : z)
    //Es col·loquialmente llamado condicional ternario y sirve para dar un resultado u otro dependiendo si el valor es positivo o negativo
    a ? a : a;
    std::cout << a << "\n";

    //A parte de estos, estan los operadores especiales como por ejemplo "sizeof", "new", "delete", "typeid"...
    
    /*
    La lista entera de operadores especiales:

    static_cast converts one type to another related type
    dynamic_cast converts within inheritance hierarchies
    const_cast adds or removes cv-qualifiers
    reinterpret_cast converts type to unrelated type
    C-style cast converts one type to another by a mix of static_cast, const_cast, and reinterpret_cast
    new creates objects with dynamic storage duration
    delete destructs objects previously created by the new expression and releases obtained memory area
    sizeof queries the size of a type
    sizeof... queries the size of a pack (since C++11)
    typeid queries the type information of a type
    noexcept checks if an expression can throw an exception (since C++11)
    alignof queries alignment requirements of a type (since C++11) 
    */


    //Ahora voy a ejemplificar cada tipo estructuras de control que existen en c++:

    //La estructura secuencial es la estructura que ejecuta las instrucciones en el orden que se encuentran en el código, sin realizar saltos ni repeticiones (como es por defecto el codigo, entiendo):

    std::cout << "Hola, "; 
    std::cout << "mundo!";

    //La estructura condicional, toma decisiones en función de condiciones (if, if-else, switch, consteval, consteval-else):

    if (1 == !a) 
    {
        a=1;
    } 
    else 
    {
        a=0;
    }
    std::cout << &a << "\n";

    //La estructura iterativa(bucles) permiten repetir un bloque de código varias veces (while, do-while, for, range for):
    int i = 0;
    while (i < 5)
    {
        std::cout << i;
        i++;
    }

    //La estructura de salto transfiere el punto donde continua ejecutando el código a otra parte incondicionalmente (break, continue, return, goto):

    for(i = 0; i < 10; i++)
    {
        std::cout << i << "\n";
        if (i == 7) break;
    }

    std::cout << "\n\n\n";

    //Hay algunos más como el statement de aserción que parece que sirve para declarar que es true, el de definición, que es como se declaran las funciones y tal, el try para
    //capturar excepciones lanzadas cuando se ejecutan otros statements, bloques atómicos y sincronizados y substatements

    
    //try
    //{
    //    /* code */
    //}
    //catch(const std::exception& e)
    //{
    //    std::cerr << e.what() << '\n';
    //}


    //Ejercicio extra:
    //* DIFICULTAD EXTRA (opcional):
    //* Crea un programa que imprima por consola todos los números comprendidos
    //* entre 10 y 55 (incluidos), pares, y que no son ni el 16 ni múltiplos de 3.

    for (i = 10; i <= 55; i++)
    {
        if (i % 2 == 0 && i != 16 && i % 3 == 0)
        {
            std::cout << i << "\n";
        }
        
    }

}

//Referéncia a la web de información: https://en.cppreference.com/w/cpp/language/expressions.html#Operators