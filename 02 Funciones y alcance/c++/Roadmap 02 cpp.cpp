/*
 * EJERCICIO:
 * - Crea ejemplos de funciones básicas que representen las diferentes
 *   posibilidades del lenguaje:
 *   Sin parámetros ni retorno, con uno o varios parámetros, con retorno...
 * - Comprueba si puedes crear funciones dentro de funciones.
 * - Utiliza algún ejemplo de funciones ya creadas en el lenguaje.
 * - Pon a prueba el concepto de variable LOCAL y GLOBAL.
 * - Debes hacer print por consola del resultado de todos los ejemplos.
 *   (y tener en cuenta que cada lenguaje puede poseer más o menos posibilidades)
 *
 * DIFICULTAD EXTRA (opcional):
 * Crea una función que reciba dos parámetros de tipo cadena de texto y retorne un número.
 * - La función imprime todos los números del 1 al 100. Teniendo en cuenta que:
 *   - Si el número es múltiplo de 3, muestra la cadena de texto del primer parámetro.
 *   - Si el número es múltiplo de 5, muestra la cadena de texto del segundo parámetro.
 *   - Si el número es múltiplo de 3 y de 5, muestra las dos cadenas de texto concatenadas.
 *   - La función retorna el número de veces que se ha impreso el número en lugar de los textos.
 *
 * Presta especial atención a la sintaxis que debes utilizar en cada uno de los casos.
 * Cada lenguaje sigue una convenciones que debes de respetar para que el código se entienda.
 */

#include <iostream>

int global = 100;                   //Esta es una variable creada globalmente

void usarFuncionSinRetorno(){
        std::cout << "A esta función no se le pasan parametros ni esta retorna nada" << std::endl;
    }

    void usarFuncionConParametros(int *a, int *b){
        //En esta función muestro la dirección en memória pasada por referéncia y les cambio el valor a las variables sin devolverlas con return
        std::cout << a << std::endl << b <<std::endl;
        *a = 10;
        *b = 20;
    }

    int usarFuncionConRetorno(int a){
        a = 100;
        std::cout << "Esta es una variable global: " << global << std::endl;
        return a;
    }

    int imprimirMultiplosDe3O5(){
        int cantidad = 0;
        for ( int i = 0; i <= 100; i++ ){
            
            std::cout << i;

            if ( i % 3 == 0 && i % 5 == 0 ){

                std::cout << " es múltiplo de 3 y de 5" << std::endl;

            } else if ( i % 3 == 0 )
            {
                std::cout << " es múltiplo de 3" << std::endl;

            } else if ( i % 5 == 0 )
            {
                std::cout << " es múltiplo de 5" << std::endl;
            } else {
                std::cout << std::endl;
                continue;
            }
            cantidad++;
        }
        return cantidad;
    }



int main(){
    
    int a = 0;                      //Estas son variables creadas localmente
    int b = 1;


    usarFuncionSinRetorno();
    
    usarFuncionConParametros(&a, &b);
    std::cout << a << std::endl << b << std::endl;

    a = usarFuncionConRetorno(a);
    std::cout << a << std::endl;

    //En c++ no se puede crear una función dentro de una función a excepción de una función Lambda. Ejemplo:
    
    auto sumar = [](int x, int y) -> int {
        return x + y;
    };

    std::cout << "La suma de 7 y 8 es: " << sumar(7, 8) << std::endl;

    //Ya he utilizado funciones que vienen en c++ como por ejemplo cout pero voy a probar esta:
    int minimo = std::min(8, 4);
    std::cout << "El valor más bajo de los dos es: " << minimo << std::endl;



    /*
    * DIFICULTAD EXTRA (opcional):
    * Crea una función que reciba dos parámetros de tipo cadena de texto y retorne un número.
    * - La función imprime todos los números del 1 al 100. Teniendo en cuenta que:
    *   - Si el número es múltiplo de 3, muestra la cadena de texto del primer parámetro.
    *   - Si el número es múltiplo de 5, muestra la cadena de texto del segundo parámetro.
    *   - Si el número es múltiplo de 3 y de 5, muestra las dos cadenas de texto concatenadas.
    *   - La función retorna el número de veces que se ha impreso el número en lugar de los textos.
    *
    * Presta especial atención a la sintaxis que debes utilizar en cada uno de los casos.
    * Cada lenguaje sigue una convenciones que debes de respetar para que el código se entienda.
    */

    int cantidadNumerosImpresos = imprimirMultiplosDe3O5();
    std::cout << "La cantidad de números impresos ha sido: " << cantidadNumerosImpresos;


    return 0;
}   