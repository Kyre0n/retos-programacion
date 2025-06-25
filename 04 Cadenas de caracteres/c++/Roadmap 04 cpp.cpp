/*
 * EJERCICIO:
 * Muestra ejemplos de todas las operaciones que puedes realizar con cadenas de caracteres
 * en tu lenguaje. Algunas de esas operaciones podrían ser (busca todas las que puedas):
 * - Acceso a caracteres específicos, subcadenas, longitud, concatenación, repetición,
 *   recorrido, conversión a mayúsculas y minúsculas, reemplazo, división, unión,
 *   interpolación, verificación...
 *
 * DIFICULTAD EXTRA (opcional):
 * Crea un programa que analice dos palabras diferentes y realice comprobaciones
 * para descubrir si son:
 * - Palíndromos
 * - Anagramas
 * - Isogramas
 */

#include <iostream>
#include <algorithm>
#include <string>
#include <map>


void comprobarPalindromos(std::string str, std::string str2);
bool comprobarAnagramas(std::string str, std::string str2);
int comprobarIsograma(std::string str);



void comprobarPalindromos(std::string str, std::string str2){
    int i = 0;
    for( std::string::reverse_iterator rit = str.rbegin(); rit != str.rend(); rit++ ){
            //std::cout << *rit << std::endl;
            if (*rit != str2.at(i)){
                std::cout << "Estas palabras no son palíndromas!" << std::endl;
                return;
            }
            i++;
        }
        std::cout << "Estas palabras son palíndromas entre ellas" << std::endl;
}


bool comprobarAnagramas(std::string str, std::string str2){
    std::map<char, int> cantidadLetras;
    for(char c : str){
        cantidadLetras[c]++;
    }
    

    for( auto const& [caracter, cantidad] : cantidadLetras ){
        for(char c : str2){
            if(caracter == c){
                cantidadLetras[caracter]--;
            }
        }
        
    }

    for( auto const& [caracter, cantidad] : cantidadLetras ){
        if (cantidad != 0){
            return false;
        }
    }
    return true;
}


int comprobarIsograma(std::string str){
    std::map<char, int> cantidadLetras;
    int contador = 0;
    for(char c : str){
        cantidadLetras[c]++;
        
    }
    contador = cantidadLetras.begin()->second;
    for( auto const& [caracter, cantidad] : cantidadLetras ){
        if( cantidad != cantidadLetras.begin()->second ){
            return -1; // Si hay alguna letra que no se repite igual que las demás, devuelve -1
        }
    }
    return cantidadLetras.begin()->second;
}


int main(){
    std::string str = "Hola Mundo!";
    std::string str2 = "Adios Mundo!";
    std::string unionStrings = "";

    std::cout << "La segunda letra del string es: " << str[1] << std::endl;
    std::cout << "La segunda letra del string es: " << str.at(1) << "\nAquí voy a mostrar desde el primer carácter hasta 4 carácteres más adelante: " << str.substr(0, 4) << std::endl;
    std::size_t pos = str.find("la");
    std::cout << "Aquí muestro desde donde ha encontrado la cadena la hasta el final del string: " << str.substr(pos) << std::endl;
    std::cout << "Aquí muestro el tamaño del string: " << str.length() << std::endl;
    std::cout << "Aquí muestro el tamaño máximo del string: " <<str.max_size() << std::endl;
    std::cout << "Aquí muestro el tamaño en memoria del string: " <<str.capacity() << std::endl;
    std::cout << "Aquí mira si el string está vacio y da 0 si es no y 1 si es que si: " <<str.empty() << std::endl;
    str.clear();
    std::cout << "Aquí mira si el string está vacio y da 0 si es no y 1 si es que si: " <<str.empty() << std::endl;
    str.append("Adios");
    str.append(" Mundo!");
    std::cout << str << std::endl;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    std::cout << str << std::endl;
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::cout << str << std::endl;
    str.replace(str.begin(), str.begin() + 5, "Hola");
    std::cout << str << std::endl;
    std::cout << "Aquí comparo una string con otra y da 0 si es igual y 1 si es diferente: " << str.compare(str2) << std::endl;
    std::cout << "Aquí comparo una string con otra y da 0 si es igual y 1 si es diferente: " << str.compare(str) << std::endl;
    str.pop_back();
    std::cout << "Aquí elimino el último carácter de la string: " << str << std::endl;
    str.shrink_to_fit();                //Con esta función haces que la memória que utiliza el string se solo la necesária para el contenido que tiene
    //std::cout << R"(Aquí estoy probando la interpolación poniendo las strings $str y $str2)" << std::endl;                                    // No funciona en C++ pero si en otros lenguajes como Python, JavaScript, etc.



/* DIFICULTAD EXTRA (opcional):
 * Crea un programa que analice dos palabras diferentes y realice comprobaciones
 * para descubrir si son:
 * - Palíndromos
 * - Anagramas
 * - Isogramas
 */

    
    std::cout << "Escribe una palabra o frase: " << std::endl;
    std::getline(std::cin, str);
    std::cout << "Escribe otra palabra o frase: " << std::endl;
    std::getline(std::cin, str2);
    std::cout << "Primera cadena: " << str << "         Segunda cadena: " << str2 << std::endl;
                                                                                                        //str.erase(std::remove_if(str.begin(), str.end(), ::isspace), str.end()); // Elimina los espacios en blanco de la cadena
                                                                                                        //str2.erase(std::remove_if(str2.begin(), str2.end(), ::isspace), str2.end()); // Elimina los espacios en blanco de la cadena
    std::string notAllowedChars = ",.;:!¿?\"´'()[]{}<>|\\/@#&%$=+-*^~` ";                               // Caracteres que se van a eliminar de las cadenas
    str.erase(std::remove_if(str.begin(), str.end(), [&](char c) { return notAllowedChars.find(c) != std::string::npos; }), str.end()); // Elimina los caracteres especiales de la cadena.      //std::string::npos es lo que devuelve string.find en caso de no encontrar el carácter, por lo que si lo encuentra devuelve un valor distinto de npos y se elimina el carácter
    str2.erase(std::remove_if(str2.begin(), str2.end(), [&](char c) { return notAllowedChars.find(c) != std::string::npos; }), str2.end());
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
    std::cout << "Primera cadena una vez quitados los carácteres que no nos interesan: " << str << "         Segunda cadena una vez quitados los carácteres que no nos interesan: " << str2 << std::endl;
    
    // Comprobar si son palíndromos;
    
    if (str.length() != str2.length()){                                                                         //Compruebo si las dos strings son igual de largos después de quitar todos los carácteres especiales.
        std::cout << "Estas palabras no son ni palíndromos ni anagramas entre ellas!" << std::endl;
    } else if(comprobarAnagramas(str, str2)){
        std::cout << "Estas palabras son anagramas entre ellas" << std::endl;
        comprobarPalindromos(str, str2);
        int nivelIsograma;
        if (nivelIsograma = comprobarIsograma(str)){
            std::cout << "La primera cadena y segunda cadena son isogramas de nivel " << nivelIsograma << std::endl;
        } else {
            std::cout << "Ni la primera ni la segunda cadena son isogramas" << std::endl;
        }
    } else {
        std::cout << "Estas palabras no son ni palíndromos ni anagramas entre ellas!" << std::endl;
    }
    
    int nivelIsograma;
    if (nivelIsograma = comprobarIsograma(str)){
        std::cout << "La primera cadena es un isograma de nivel " << nivelIsograma << std::endl;
    } else {
        std::cout << "La primera cadena no es un isograma" << std::endl;
    }

    if (nivelIsograma = comprobarIsograma(str2)){
        std::cout << "La segunda cadena es un isograma de nivel " << nivelIsograma << std::endl;
    } else {
        std::cout << "La segunda cadena no es un isograma" << std::endl;
    }
    
    return 0;
}