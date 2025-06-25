/*
 * EJERCICIO:
 * Implementa los mecanismos de introducción y recuperación de elementos propios de las
 * pilas (stacks - LIFO) y las colas (queue - FIFO) utilizando una estructura de array
 * o lista (dependiendo de las posibilidades de tu lenguaje).
 *
 * DIFICULTAD EXTRA (opcional):
 * - Utilizando la implementación de pila y cadenas de texto, simula el mecanismo adelante/atrás
 *   de un navegador web. Crea un programa en el que puedas navegar a una página o indicarle
 *   que te quieres desplazar adelante o atrás, mostrando en cada caso el nombre de la web.
 *   Las palabras "adelante", "atrás" desencadenan esta acción, el resto se interpreta como
 *   el nombre de una nueva web.
 * - Utilizando la implementación de cola y cadenas de texto, simula el mecanismo de una
 *   impresora compartida que recibe documentos y los imprime cuando así se le indica.
 *   La palabra "imprimir" imprime un elemento de la cola, el resto de palabras se
 *   interpretan como nombres de documentos.
 */

#include <iostream>
#include <stack>
#include <queue>
#include <string>

int opcionMenu();
void mostrarMenu();
void navegadorWeb();
void impresoraCompartida();

int main () {
    // Ejemplo de uso de la pila (stack)
    std::stack<std::string> pila;
    pila.push("Hola");
    pila.push("Mundo");
    pila.push("!");
    std::cout << "La cadena de la parte de arriba de la pila es: " << pila.top() << std::endl;
    pila.pop(); // Elimina el último elemento (¡)
    std::cout << "La cadena de la parte de arriba de la pila es: " << pila.top() << std::endl;

    // Ejemplo de uso de la cola (queue)
    std::queue<std::string> cola;
    cola.push("Hola");
    cola.push("Mundo");
    cola.push("!");
    std::cout << "La primera cadena de cola es: " << cola.front() << std::endl;
    std::cout << "La última cadena de la cola es: " << cola.back() << std::endl;
    cola.pop(); // Elimina el primer elemento (Hola)
    std::cout << "La primera cadena de cola es: " << cola.front() << std::endl;
    std::cout << "La última cadena de la cola es: " << cola.back() << std::endl;


/* DIFICULTAD EXTRA (opcional):
* - Utilizando la implementación de pila y cadenas de texto, simula el mecanismo adelante/atrás
*   de un navegador web. Crea un programa en el que puedas navegar a una página o indicarle
*   que te quieres desplazar adelante o atrás, mostrando en cada caso el nombre de la web.
*   Las palabras "adelante", "atrás" desencadenan esta acción, el resto se interpreta como
*   el nombre de una nueva web.
* - Utilizando la implementación de cola y cadenas de texto, simula el mecanismo de una
*   impresora compartida que recibe documentos y los imprime cuando así se le indica.
*   La palabra "imprimir" imprime un elemento de la cola, el resto de palabras se
*   interpretan como nombres de documentos.
*/
    while(true) {
        switch (opcionMenu())
        {
        case 1: // Navegador web
            navegadorWeb();
            break;
        case 2: // Impresora compartida
            impresoraCompartida();
            break;
        case 3: // Salir
            std::cout << "Saliendo del programa..." << std::endl;
            return 0;
            break;
        default:
            std::cout << "Opción no válida. Por favor, intente de nuevo." << std::endl;
            break;
        }
    }
    return 0;
}

int opcionMenu() {
    mostrarMenu();
    int opcion;
    std::cin >> opcion;
    std::cin.ignore(); // Limpiar el buffer de entrada
    return opcion;
}

void mostrarMenu() {
    std::cout << "Seleccione una opción: " << std::endl;
    std::cout << "1. Navegador web" << std::endl;
    std::cout << "2. Impresora compartida" << std::endl;
    std::cout << "3. Salir" << std::endl;
}

void navegadorWeb() {
    std::stack<std::string> atras; // Pila para las páginas que quedaron atrás
    std::stack<std::string> adelante; // Pila para las páginas que quedaron delante
    std::string paginaActual; // Página activa
    std::string entrada;
    while (true) {
        std::cout << "Página actual: " << paginaActual << std::endl;
        std::cout << "Ingrese la página web que desea visitar (o las opciones 'adelante', 'atras' o 'salir'): " << std::endl;
        std::getline(std::cin,entrada);
        if (entrada != "adelante" && entrada != "atras" && entrada != "salir") {
            if (!paginaActual.empty()) {
                atras.push(paginaActual); // Guardar la página actual en la pila de atrás
                paginaActual = entrada; // Actualizar la página actual
                while (!adelante.empty()) {
                    adelante.pop(); // Limpiar la pila de adelante al visitar una nueva página
                }
            }
            paginaActual = entrada; // Actualizar la página actual
        } else {
            if (entrada == "atras") {
                if (!atras.empty()) {
                    adelante.push(paginaActual); // Guardar la página actual en la pila de adelante
                    paginaActual = atras.top(); // Volver a la página anterior
                    atras.pop(); // Eliminar la última página de atrás
                } else {
                    std::cout << "No hay páginas atrás." << std::endl;
                }
            } else if (entrada == "adelante") {
                if (!adelante.empty()) {
                    atras.push(paginaActual); // Guardar la página actual en la pila de atrás
                    paginaActual = adelante.top(); // Ir a la página siguiente
                    adelante.pop(); // Eliminar la última página de adelante
                } else {
                    std::cout << "No hay páginas adelante." << std::endl;
                } 
            } else if (entrada == "salir") {
                std::cout << "Saliendo del navegador web..." << std::endl;
                return;
            }
        }
    }
}

void impresoraCompartida() {
    std::queue<std::string> colaImpresion; // Cola para los documentos a imprimir
    std::string entrada = "";
    while (true) {
        std::cout << "Ingresa el nombre del documento que deseas añadir a la cola de impresion o 'imprimir' para imprimir el siguiente documento (o 'salir' para terminar): " << std::endl;
        std::getline(std::cin, entrada);
        if (entrada != "imprimir" && entrada != "salir") {
            if (!entrada.empty()) {
                colaImpresion.push(entrada); // Añadir el documento a la cola
                std::cout << "Documento '" << entrada << "' añadido a la cola de impresión." << std::endl;
            } else {
                std::cout << "No se ha introducido un nombre de documento válido." << std::endl;
            }
        } else if (entrada == "imprimir") {
            if (!colaImpresion.empty()) {
                std::cout << "Documento impreso: " << colaImpresion.front() << std::endl;
                colaImpresion.pop(); // Imprimir el siguiente documento
            } else {
                std::cout << "No hay documentos en la cola para imprimir." << std::endl;
            }
        } else if (entrada== "salir") {
            std::cout << "Saliendo de la impresora compartida..." << std::endl;
            return;
        }
    }
}