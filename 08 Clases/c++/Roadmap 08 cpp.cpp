/*
* EJERCICIO:
* Explora el concepto de clase y crea un ejemplo que implemente un inicializador,
* atributos y una función que los imprima (teniendo en cuenta las posibilidades
* de tu lenguaje).
* Una vez implementada, créala, establece sus parámetros, modifícalos e imprímelos
* utilizando su función.
*
* DIFICULTAD EXTRA (opcional):
* Implementa dos clases que representen las estructuras de Pila y Cola (estudiadas
* en el ejercicio número 7 de la ruta de estudio)
* - Deben poder inicializarse y disponer de operaciones para añadir, eliminar,
*   retornar el número de elementos e imprimir todo su contenido.
*/

#include <iostream>
#include <stack>
#include <queue>

class Libro {
    std::string _titulo;
    std::string _autor;
    int _anioPublicacion;
public:
    // Constructor para inicializar los atributos
    Libro(const std::string& titulo, const std::string& autor, int anioPublicacion) {
        _titulo = titulo;
        _autor = autor;
        _anioPublicacion = anioPublicacion;
    }
    void setTitulo(const std::string& titulo) {
        _titulo = titulo;
    }
    void setAutor(const std::string& autor) {
        _autor = autor;
    }
    void setAnioPublicacion(int anioPublicacion) {
        _anioPublicacion = anioPublicacion;
    }
    void mostrarLibro() {
        std::cout << "Título: " << _titulo << ", Autor: " << _autor
                    << ", Año de Publicación: " << _anioPublicacion << std::endl;
    }
};

class Pila {
    std::stack<int> pilaEnteros; // Ejemplo de pila de enteros
public:
    Pila(){};
    void push(int valor) {
        pilaEnteros.push(valor);
    }
    void pop() {
        pilaEnteros.pop();
    }
    void size() {
        std::cout << "El tamaño de la pila es: " << pilaEnteros.size() << std::endl;
    }
    void print() {
        std::stack<int> temp = pilaEnteros; // Copia para no modificar la pila original
        for (0; 0 < temp.size(); 0) {
            std::cout << temp.top() << "\n";
            temp.pop();
        }
    }
};

class Cola {
    std::queue<std::string> colaCadenas; // Ejemplo de cola de cadenas
public:
    Cola(){};
    void push(std::string cadena) {
        colaCadenas.push(cadena);
    }
    void pop() {
        colaCadenas.pop();
    }
    void size() {
        std::cout << "El tamaño de la cola es: " << colaCadenas.size() << std::endl;
    }
    void print() {
        std::queue<std::string> temp = colaCadenas; // Copia para no modificar la cola original
        for (0; 0 < temp.size(); 0) {
            std::cout << temp.front() << "\n";
            temp.pop();
        }
    }
};

int main () {
    Libro libro1("Cien años de soledad", "Gabriel García Márquez", 1965);
    libro1.mostrarLibro();
    libro1.setAnioPublicacion(1967);
    libro1.mostrarLibro();

/* DIFICULTAD EXTRA (opcional):
* Implementa dos clases que representen las estructuras de Pila y Cola (estudiadas
* en el ejercicio número 7 de la ruta de estudio)
* - Deben poder inicializarse y disponer de operaciones para añadir, eliminar,
*   retornar el número de elementos e imprimir todo su contenido.
*/
    std::cout << "Ejemplo de Pila:\n";
    Pila pila;
    pila.push(10);
    pila.push(20);
    pila.push(30);
    pila.size();
    pila.print();
    pila.pop();
    pila.size();
    pila.print();

    std::cout << "Ejemplo de Cola:\n";
    Cola cola;
    cola.push("Hola");
    cola.push("Mundo");
    cola.push("!");
    cola.size();
    cola.print();
    cola.pop();
    cola.size();
    cola.print();
    return 0;
}