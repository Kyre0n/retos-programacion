/*
 * EJERCICIO:
 * - Muestra ejemplos de creación de todas las estructuras soportadas por defecto
 *   en tu lenguaje.
 * - Utiliza operaciones de inserción, borrado, actualización y ordenación.
 *
 * DIFICULTAD EXTRA (opcional):
 * Crea una agenda de contactos por terminal.
 * - Debes implementar funcionalidades de búsqueda, inserción, actualización
 *   y eliminación de contactos.
 * - Cada contacto debe tener un nombre y un número de teléfono.
 * - El programa solicita en primer lugar cuál es la operación que se quiere realizar,
 *   y a continuación los datos necesarios para llevarla a cabo.
 * - El programa no puede dejar introducir números de teléfono no numéricos y con más
 *   de 11 dígitos (o el número de dígitos que quieras).
 * - También se debe proponer una operación de finalización del programa.
 */

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <deque>
#include <list>
#include <string>
#include <cctype>


class Contacto {
    std::string _nombre, _telefono;
public:
    Contacto();             //Default constructor
    void setContacto(std::string nombre, std::string telefono);
    std::string getNombre();
    std::string getTelefono();
};

Contacto::Contacto(){
    _nombre = "";
    _telefono = "";
}

void Contacto::setContacto(std::string nombre, std::string telefono){
    _nombre = nombre;
    _telefono = telefono;
}

std::string Contacto::getNombre(){
    return _nombre;
}

std::string Contacto::getTelefono(){
    return _telefono;
}

bool isNumeric(std::string str){
    for (char c : str){
        if (!isdigit(c)){
            return false;
        }
    }
    return true;
}

void mostrarContenedor(std::vector<Contacto> agenda){
    int l = agenda.size();
    for ( int i = 0; i < l; i++){
        std::cout << "Nombre: " << agenda[i].getNombre() << "   Teléfono: " << agenda[i].getTelefono() << std::endl;
    }
}

template <typename t>
void mostrarContenedor(t& contenedor){
    
    for (int num : contenedor){
        std::cout << num << std::endl;
    }
}

void mostrarContacto(Contacto contacto){
    std::cout << "Nombre: " << contacto.getNombre() << "            Teléfono: " << contacto.getTelefono() << std::endl;
}


void usarArray(std::array<int, 5>& miArray){
    std::cout << "------------------Array------------------" << std::endl;
    miArray[0] = 30;
}



void usarVector(std::vector<int>& miVector){
    std::cout << "------------------Vector------------------" << std::endl;
    miVector.push_back(1);                                  //push_back añade al final del vector
    miVector.push_back(7);
    miVector.push_back(8);
    miVector.push_back(9);

    miVector.pop_back();                                    //pop_back elimina el último valor del vector

    miVector.insert(miVector.begin()+1, 4);                 //insert inserta un valor en la posición que le indiques

    miVector.erase(miVector.begin());                       //erase elimina un valor en la posición que le indiques

    miVector[0] = 9;                                        //Aquí cambio el valor de la primera posición del vector a 7

    std::sort(miVector.begin(), miVector.end());            //Ordena el vector de menor a mayor
}

void usarDeque(std::deque<int>& miDeque){
    std::cout << "------------------Deque------------------" << std::endl;
    miDeque.push_back(7);
    miDeque.push_front(4);
    miDeque.pop_back();
    miDeque.pop_front();
}

void usarList(std::list<int>& miList){
    std::cout << "------------------List------------------" << std::endl;
    miList.push_back(1);
}

void mostrarPrincipio(){
    std::cout << "\nBienvenido a tu agenda!\n\n Opciones:\n1: Buscar\n2: Insertar\n3: Actualizar\n4: Eliminar\n5: Mostrar agenda\nx: Salir" << std::endl;
    std::cout << "Selecciona una opción:" << std::endl;
}

bool comprobarTelefono(std::string telefono){
    if (telefono.length() > 11){
        std::cout << "El teléfono tiene más de 11 numeros!" << std::endl;
        return false;
    }
    if (!isNumeric(telefono)){
        std::cout << "El teléfono contiene otros caracteres a parte de números!" << std::endl;
        return false;
    }
    return true;
}

void insertarContacto(std::vector<Contacto>& agenda){
    std::string nombre, telefono;
    Contacto nuevoContacto;
    std::cout << "Escribe el nombre de la persona que quieres insertar en la agenda:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Escribe el teléfono:" << std::endl;
    std::getline(std::cin, telefono);
    if ( comprobarTelefono(telefono) ) {
        nuevoContacto.setContacto(nombre, telefono);
        agenda.push_back(nuevoContacto);
        std::cout << "Contacto añadido con éxito!" << std::endl;
    }
}

int encontrarContacto(std::vector<Contacto>& agenda, std::string nombre){
    int l = agenda.size();
    for ( int i = 0; i < l; i++ ){
        if (agenda[i].getNombre() == nombre){
            return i;
        }
    }
    return -1;
}

void buscarContacto(std::vector<Contacto>& agenda){
    int direccion;
    std::string nombre = "";
    std::cout << "Escribe el nombre exacto de la persona que quieres encontrar:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, nombre);
    direccion = encontrarContacto(agenda, nombre);
    if (direccion > -1){
        mostrarContacto(agenda[direccion]);
    } else {
        std::cout << "No se ha encontrado a nadie con ese nombre, debes introducir el nombre exacto para encontrarlo!" << std::endl;
    }   
}

void eliminarContacto(std::vector<Contacto>& agenda){
    int direccion;
    std::string nombre = "";
    std::cout << "Escribe el nombre exacto de la persona que quieres eliminar:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, nombre);
    direccion = encontrarContacto(agenda, nombre);
    if (direccion > -1){
        agenda.erase(agenda.begin() + direccion);
    } else {
        std::cout << "No se ha encontrado a nadie con ese nombre, debes introducir el nombre exacto para eliminarlo!" << std::endl;
    }   
}

void actualizarContacto(std::vector<Contacto>& agenda){
    int direccion;
    std::string nombre = "";
    std::string nuevoNombre = "";
    std::string nuevoTelefono = "";
    std::cout << "Escribe el nombre exacto de la persona que quieres modificar:" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, nombre);
    direccion = encontrarContacto(agenda, nombre);
    if (direccion > -1){
        std::cout << "Se va a actualizar el contacto" << agenda[direccion].getNombre() << "\nEscribe el nuevo nombre que quieres que tenga: " << std::endl;
        std::getline(std::cin, nuevoNombre);
        std::cout << "Escribe el nuevo teléfono que quieres que tenga: " << std::endl;
        std::getline(std::cin, nuevoTelefono);
        if(comprobarTelefono(nuevoTelefono)){
            agenda[direccion].setContacto(nuevoNombre, nuevoTelefono);
            std::cout << "Contacto modificado con éxito!" << std::endl;
        }
    } else {
        std::cout << "No se ha encontrado a nadie con ese nombre, debes introducir el nombre exacto para modificiarlo!" << std::endl;
    }   
}



int main(){

    
    int longitud = 0;

                                                                                                                                                                        //Array                     Esta era mi primera idea, pero la descarté por std::array ya que me parece mejor (me da más y al parecer es igual de rápido que un array normal en tiempo de ejecución)
                                                                                                                                                                        //int miArray[5] = {1, 2, 3, 4, 5};
                                                                                                                                                                        //longitud = sizeof(miArray) / sizeof(miArray[0]);
                                                                                                                                                                        //usarArray(miArray, longitud);
                                                                                                                                                                        //mostrarContenedor(miArray, longitud);
    //Array
    std::array<int, 5> miArray = {1, 2, 3, 4, 5};
    usarArray(miArray);
    mostrarContenedor(miArray);

    //Vector
    std::vector<int> miVector;
    std::vector<int> miInplaceVector(10);
    
    usarVector(miVector);
    mostrarContenedor(miVector);
    

    //Deque
    std::deque<int> miDeque = {7,8};
    usarDeque(miDeque);
    mostrarContenedor(miDeque);

    //List
    std::list<int> miList;
    usarList(miList);
    mostrarContenedor(miList);

    //Faltan más pero he entendido el concepto así que voy a seguir con el ejercicio complejo ya que crearlos solo para modificarlos sin ningún fin me parece aburrido




/* DIFICULTAD EXTRA (opcional):
 * Crea una agenda de contactos por terminal.
 * - Debes implementar funcionalidades de búsqueda, inserción, actualización
 *   y eliminación de contactos.
 * - Cada contacto debe tener un nombre y un número de teléfono.
 * - El programa solicita en primer lugar cuál es la operación que se quiere realizar,
 *   y a continuación los datos necesarios para llevarla a cabo.
 * - El programa no puede dejar introducir números de teléfono no numéricos y con más
 *   de 11 dígitos (o el número de dígitos que quieras).
 * - También se debe proponer una operación de finalización del programa.
 */

    char tecla = 'a';
    std::vector<Contacto> agenda;

    while (tecla != 'x'){

        mostrarPrincipio();
                                                                                                                    //tecla = std::cin.get(); Me daba problemas y vi que existia cin, la cual los arregló y me parece mejor utilizar esa función
        std::cin >> tecla;

        switch (tecla)
        {
        case '1':
            std::cout << "Buscar" << std::endl;
            buscarContacto(agenda);
            break;
        case '2':
            std::cout << "Insertar" << std::endl;
            insertarContacto(agenda);
            break;
        case '3':
            std::cout << "Actualizar" << std::endl;
            actualizarContacto(agenda);
            break;
        case '4':
            std::cout << "Eliminar" << std::endl;
            eliminarContacto(agenda);
            break;
        case '5':
            std::cout <<"Mostrar agenda" << std::endl;
            mostrarContenedor(agenda);
            break;
        case 'x':
            break;
        default:
            std::cout << "Selecciona una opcion valida!" << std::endl;
            break;
        }
    }


    return 0;
}

//Todos los contenedores de C++ están aquí: https://en.cppreference.com/w/cpp/container.html