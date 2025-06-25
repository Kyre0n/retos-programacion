/*
 * EJERCICIO:
 * Entiende el concepto de recursividad creando una función recursiva que imprima
 * números del 100 al 0.
 *
 * DIFICULTAD EXTRA (opcional):
 * Utiliza el concepto de recursividad para:
 * - Calcular el factorial de un número concreto (la función recibe ese número).
 * - Calcular el valor de un elemento concreto (según su posición) en la 
 *   sucesión de Fibonacci (la función recibe la posición).
 */

#include <iostream>

 void contarDesdeHasta(int desde, int hasta) {
    if (desde < hasta) {
        contarDesdeHasta(desde, hasta - 1); // Llamada recursiva con el número  decrementado.
    } else if (desde > hasta) {
        contarDesdeHasta(desde, hasta + 1); // Llamada recursiva con el número incrementado.
    }
    std::cout << hasta << std::endl; // Imprime el número actual
 }

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1); // Llamada recursiva para calcular el factorial
    } else {
        return n;
    }
}

int valorFibonacci(int n) {
    if (n <= 1) {
        return n; // Base de la recursividad: los dos primeros números de Fibonacci son 0 y 1
    } else {
        return valorFibonacci(n - 1) + valorFibonacci(n - 2); // Llamada recursiva para calcular el valor de Fibonacci
    }
}

int main() {
    contarDesdeHasta(100, 0); // Llamada a la función recursiva para imprimir números del 100 al 0

/* DIFICULTAD EXTRA (opcional):
 * Utiliza el concepto de recursividad para:
 * - Calcular el factorial de un número concreto (la función recibe ese número).
 * - Calcular el valor de un elemento concreto (según su posición) en la 
 *   sucesión de Fibonacci (la función recibe la posición).
 */

    int numFactorial = factorial(5); // Ejemplo de cálculo del factorial de 5
    std::cout << "El factorial de 5 es: " << numFactorial << std::endl;

    int numeroFibonacci = valorFibonacci(7); // Ejemplo de cálculo del valor de Fibonacci en la posición 7
    std::cout << "El valor de Fibonacci en la posición número 7 es: " << numeroFibonacci << std::endl;

    return 0;
}