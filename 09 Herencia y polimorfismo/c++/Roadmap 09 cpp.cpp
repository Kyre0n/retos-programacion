/*
* EJERCICIO:
* Explora el concepto de herencia según tu lenguaje. Crea un ejemplo que
* implemente una superclase Animal y un par de subclases Perro y Gato,
* junto con una función que sirva para imprimir el sonido que emite cada Animal.
*
* DIFICULTAD EXTRA (opcional):
* Implementa la jerarquía de una empresa de desarrollo formada por Empleados que
* pueden ser Gerentes, Gerentes de Proyectos o Programadores.
* Cada empleado tiene un identificador y un nombre.
* Dependiendo de su labor, tienen propiedades y funciones exclusivas de su
* actividad, y almacenan los empleados a su cargo.
*/

#include <iostream>
#include <vector>



class Animal {
public:
    virtual void hacerSonido() const = 0; // Método virtual puro, se debe implementar en las subclases ya que sino dará error al compilar.
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Guau!" << std::endl;
    }
};

class Gato : public Animal {
public: void hacerSonido() const override {
        std::cout << "Miau!" << std::endl;
}
};

class Empleado {
    protected:
    // Atributos protegidos para que las subclases puedan acceder a ellos.
    // Esto es útil para evitar el uso de getters y setters en muchos casos.
    
    static std::atomic_uint32_t currentId; // Variable estática para asignar IDs únicos a los empleados.
    // Usamos std::atomic para que sea seguro en un entorno multihilo.
    uint32_t id;
    std::string nombre;
    std::string puesto;
    std::vector <std::string> cargosADisposicion; // Vector para almacenar empleados a cargo.
    public:
    Empleado() {
        // Constructor por defecto que asigna un ID único al empleado.
        //this->id = currentId++;
        //this->nombre = "Empleado sin nombre";
    } // Constructor que asigna un ID único y un nombre al empleado.
    virtual void funcionEmpleado() {
        std::cout << "Soy un empleado genérico." << std::endl;
    }
    virtual void mostrarInformacion() {
        std::cout << "ID: " << id << ", Nombre: " << nombre << ", Puesto: " << puesto << std::endl;
        std::cout << "Cargos a disposición: "; 
        for (const auto& cargo : cargosADisposicion) {
            std::cout << cargo << " ";
        }
        std::cout << std::endl;
    }
};

std::atomic_uint32_t Empleado::currentId{1}; // Empieza en 1, se puede cambiar el valor inicial
 // Variable global para asignar IDs únicos a los empleados.

class Gerente : public Empleado {
public:
    Gerente(const std::string& nombre) {
        // Constructor de Gerente, se puede inicializar el puesto o cualquier otra propiedad específica.
        this->id = currentId++;
        this->nombre = nombre;
        this->puesto = "Gerente";
        this->cargosADisposicion.push_back("Gerentes de proyecto");
        this->cargosADisposicion.push_back("Programadores");
        this->cargosADisposicion.push_back("Personal de limpieza");
    }
    void funcionEmpleado() {
        std::cout << "Soy un gerente y superviso a los empleados." << std::endl;
    }
    void mostrarInformacion() {
        std::cout << "ID: " << id << ", Nombre: " << nombre << ", Puesto: " << puesto << std::endl;
        std::cout << "Cargos a disposición: ";
        for (const auto& cargo : cargosADisposicion) {
            std::cout << cargo << " ";
        }
        std::cout << std::endl;
    }
};

class GerenteProyecto : public Empleado {
public:
    GerenteProyecto(const std::string& nombre) {
        // Constructor de Gerente de Proyecto, se puede inicializar el puesto o cualquier otra propiedad específica.
        this->id = currentId++;
        this->nombre = nombre;
        this->puesto = "Gerente de Proyecto";
        this->cargosADisposicion.push_back("Programadores");
    }
    void funcionEmpleado() {
        std::cout << "Soy un gerente de proyecto y coordino los proyectos." << std::endl;
    }
    void mostrarInformacion() {
        std::cout << "ID: " << id << ", Nombre: " << nombre << ", Puesto: " << puesto << std::endl;
        std::cout << "Cargos a disposición: ";
        for (const auto& cargo : cargosADisposicion) {
            std::cout << cargo << " ";
        }
        std::cout << std::endl;
    }
};

class Programador : public Empleado {
    public:
    Programador(const std::string& nombre) {
        // Constructor de Programador, se puede inicializar el puesto o cualquier otra propiedad específica.
        this->id = currentId++;
        this->nombre = nombre;
        this->puesto = "Programador";
        this->cargosADisposicion.push_back("Ninguno"); // Los programadores no tienen empleados a su cargo.
    }
    void funcionEmpleado() {
        std::cout << "Soy un programador y desarrollo software." << std::endl;
    }
    void mostrarInformacion() {
        std::cout << "ID: " << id << ", Nombre: " << nombre << ", Puesto: " << puesto << std::endl;
        std::cout << "Cargos a disposición: ";
        for (const auto& cargo : cargosADisposicion) {
            std::cout << cargo << " ";
        }
        std::cout << std::endl;
    }
};

class Limpieza : public Empleado {
    // No tiene un trabajo declarado, pero hereda de Empleado, para mostrar la opción por defecto de empleado.
    public:
    Limpieza(const std::string& nombre) {
        // Constructor de Programador, se puede inicializar el puesto o cualquier otra propiedad específica.
        this->id = currentId++;
        this->nombre = nombre;
    }
};

int main() {
    
    //Este es un ejemplo de herencia y polimorfismo en C++.

    //Este primer ejemplo está hecho con punteros dinámicos.
    //Por lo tanto, como hemos utilizado la palabra new, debemos liberar la memoria
    //con delete al final del programa.
    //Esto es una práctica común en C++ para evitar fugas de memoria.

    Animal* miAnimal1 = new Perro();
    Animal* miAnimal2 = new Gato();
    miAnimal1->hacerSonido(); // Imprime "Guau!"
    miAnimal2->hacerSonido(); // Imprime "Miau!"
    delete miAnimal1; // Liberar memoria
    delete miAnimal2; // Liberar memoria
    
    //En este ejemplo se puede hacer lo mismo pero sin crear punteros dinámicos
    //y usando objetos directamente.
    //Esto es más seguro y evita problemas de memoria.

    Perro miPerro;
    Gato miGato;

    miPerro.hacerSonido(); // Imprime "Guau!"
    miGato.hacerSonido(); // Imprime "Miau!"

    Animal* animales[] = { &miPerro, &miGato };

    for (const auto& animal : animales) {
        animal ->hacerSonido(); //Utilizamos "->" para acceder al método hacerSonido de cada objeto Animal ya que son punteros.
    }

    //Ejemplo de herencia con empleados.
    Gerente gerente("Juan Perez");
    Empleado* empleadoGerente = new Gerente("Jordi Hurtado"); // Creamos un puntero de tipo Empleado que apunta a un objeto Gerente.
    GerenteProyecto gerenteProyecto("Jose Maria");
    Programador programador("Ana Gomez");
    Limpieza limpieza("Jorge Martínez"); // Creamos un objeto de tipo Limpieza, que hereda de Empleado pero no tiene un trabajo específico.

    // Llamamos a la función funcionEmpleado de cada empleado.
    gerente.funcionEmpleado(); // Imprime "Soy un gerente y superviso a los empleados."
    empleadoGerente->funcionEmpleado(); // Imprime "Soy un gerente y superviso a los empleados."
    gerenteProyecto.funcionEmpleado(); // Imprime "Soy un gerente de proyecto y coordino los proyectos."
    programador.funcionEmpleado(); // Imprime "Soy un programador y desarrollo software."
    limpieza.funcionEmpleado(); // Imprime "Soy un empleado genérico."

    gerente.mostrarInformacion(); // Muestra información del gerente.
    empleadoGerente->mostrarInformacion(); // Muestra información del empleado gerente.
    gerenteProyecto.mostrarInformacion(); // Muestra información del gerente de proyecto.
    programador.mostrarInformacion(); // Muestra información del programador.
    
    delete empleadoGerente; // Liberar memoria del puntero dinámico.

    return 0;
}