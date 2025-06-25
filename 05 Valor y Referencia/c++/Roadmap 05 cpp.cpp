/*
 * EJERCICIO:
 * - Muestra ejemplos de asignación de variables "por valor" y "por referencia", según
 *   su tipo de dato.
 * - Muestra ejemplos de funciones con variables que se les pasan "por valor" y 
 *   "por referencia", y cómo se comportan en cada caso en el momento de ser modificadas.
 * (Entender estos conceptos es algo esencial en la gran mayoría de lenguajes)
 *
 * DIFICULTAD EXTRA (opcional):
 * Crea dos programas que reciban dos parámetros (cada uno) definidos como
 * variables anteriormente.
 * - Cada programa recibe, en un caso, dos parámetros por valor, y en otro caso, por referencia.
 *   Estos parámetros los intercambia entre ellos en su interior, los retorna, y su retorno
 *   se asigna a dos variables diferentes a las originales. A continuación, imprime
 *   el valor de las variables originales y las nuevas, comprobando que se ha invertido
 *   su valor en las segundas.
 *   Comprueba también que se ha conservado el valor original en las primeras.
 */

#include <iostream>

int asignarPorValor(int a, int b);
void asignarPorReferencia(int& a, int& b);
std::tuple<int, int> intercambioPorValor(int varValorOriginal1, int varValorOriginal2);
std::tuple<int, int> intercambioPorReferencia(int& varReferenciaOriginal1, int& varReferenciaOriginal2);

int main(){

    // Asignación por valor
    int a = 10;
    int b = 20;
    int c = a; // c recibe el valor de a
    c = 50; // Modificar c no afecta a a
    std::cout << "Asignación por valor: a = " << a << ", c = " << c << std::endl;

    // Asignación por referencia
    int& refA = a; // refA es una referencia a a
    refA = 40; // Modificar refA afecta a a
    std::cout << "Asignación por referencia: a = " << a << ", refA = " << refA << std::endl;

    // Función con parámetros por valor
    int resultadoPorValor = asignarPorValor(a, b);
    std::cout << "Valor de a: " << a << ", valor de b: " << b << "\nResultado de asignarPorValor(a, b): " << resultadoPorValor << std::endl; // No se han modificado los valores de las variables originales

    // Función con parámetros por referencia
    asignarPorReferencia(a, b);
    std::cout << "Después de asignarPorReferencia: a = " << a << ", b = " << b << std::endl; // Se han modificado los valores de las variables originales
    
/* DIFICULTAD EXTRA (opcional):
 * Crea dos programas que reciban dos parámetros (cada uno) definidos como
 * variables anteriormente.
 * - Cada programa recibe, en un caso, dos parámetros por valor, y en otro caso, por referencia.
 *   Estos parámetros los intercambia entre ellos en su interior, los retorna, y su retorno
 *   se asigna a dos variables diferentes a las originales. A continuación, imprime
 *   el valor de las variables originales y las nuevas, comprobando que se ha invertido
 *   su valor en las segundas.
 *   Comprueba también que se ha conservado el valor original en las primeras.
 */

    int varValorOriginal1 = 10;
    int varValorOriginal2 = 20;
    int varValorResultado1 = 0;
    int varValorResultado2 = 0;

    int varReferenciaOriginal1 = 30;
    int varReferenciaOriginal2 = 40;
    int varReferenciaResultado1 = 0;
    int varReferenciaResultado2 = 0;

    std::tie(varValorResultado1, varValorResultado2) = intercambioPorValor(varValorOriginal1, varValorOriginal2);
    std::cout << "Valores originales: varValorOriginal1 = " << varValorOriginal1  // No se modifica el valor original, solo se intercambian los valores locales
              << ", varValorOriginal2 = " << varValorOriginal2 << std::endl;
    std::cout << "Valores intercambiados: varValorResultado1 = " << varValorResultado1
              << ", varValorResultado2 = " << varValorResultado2 << std::endl;

    std::tie(varReferenciaResultado1, varReferenciaResultado2) = intercambioPorReferencia(varReferenciaOriginal1, varReferenciaOriginal2);
    std::cout << "Valores originales: varReferenciaOriginal1 = " << varReferenciaOriginal1  // Si se modifica el valor original al intercambiar los valores al pasar por referencia
              << ", varReferenciaOriginal2 = " << varReferenciaOriginal2 << std::endl;
    std::cout << "Valores intercambiados: varReferenciaResultado1 = " << varReferenciaResultado1
              << ", varReferenciaResultado2 = " << varReferenciaResultado2 << std::endl;

    return 0;
}

int asignarPorValor(int a, int b) {
    a = 30; // Modifica el valor de a, pero no afecta al original
    std::cout << "Dentro de asignarPorValor: a = " << a << ", b = " << b << std::endl;
    return a + b; // Suma los valores y retorna el resultado
}

void asignarPorReferencia(int& a, int& b) {
    a = 60; // Modifica el valor de a, afectando al original
    b = 80; // Modifica el valor de b, afectando al original
    std::cout << "Dentro de asignarPorReferencia: a = " << a << ", b = " << b << std::endl;
}

std::tuple<int, int> intercambioPorValor(int varValorOriginal1, int varValorOriginal2) {
    // Intercambia los valores por valor
    int temp = varValorOriginal1;
    varValorOriginal1 = varValorOriginal2;
    varValorOriginal2 = temp;
    return std::make_tuple(varValorOriginal1, varValorOriginal2);
}

std::tuple<int, int> intercambioPorReferencia(int& varReferenciaOriginal1, int& varReferenciaOriginal2) {
    // Intercambia los valores por valor
    int temp = varReferenciaOriginal1;
    varReferenciaOriginal1 = varReferenciaOriginal2;
    varReferenciaOriginal2 = temp;
    return std::make_tuple(varReferenciaOriginal1, varReferenciaOriginal2);
}