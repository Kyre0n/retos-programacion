#include <iostream>

                                            /*
                                            using namespace std; Con esto puesto como salia en el sitio donde lo vi y lo copié, se puede poner cout sin necesidad de poner std::cout, pero
                                            puede acabar dando problemas si dos librerias implementan funciones con el mismo nombre, así que se recomienda no utilizarlo o utilizar el using
                                            en alguna función concreta como puede ser "using std::cout" para no repetir el std::
                                            */

                                            //using std::cout;  Esta forma si estaría bien ya que es complicado que cause errores pero prefiero no utilizar ninguno de momento para acostumbrarme.

int main() {

    char a = 'c';
    char16_t c16 = 'a';
    char32_t c32 = 'a';
    
    int i = 16;
    signed char sc = 8;
    short s = 16;
    long l = 32;
    long long ll = 64;

    unsigned char uc = 8;
    unsigned short us = 16;
    unsigned u = 16;
    unsigned long ul = 32;
    unsigned long long ull = 64;

    float f = 0.1;
    double d = 0.11;
    long double ld = 0.111;
    
    bool b = true;

    const int CI = 10;

    void;

    decltype(nullptr);

                                                    // La página web oficial es: https://isocpp.org/

                                                    // Así se comenta una línea de código en c++

                                                    /*  
                                                        Así se
                                                        comentan varias
                                                        líneas de código en c++
                                                    */

                                                    //Utilizar "cout" es lo mismo que utilizar std:cout si no has puesto "using namespace std" ya que estás accediendo 
    //std::printf("%d", i);                         Recomiendan no utilizar printf en c++ ya que puede dar errores, en vez de eso, utilizar cout
    //printf("%d", i);                              Recomiendan no utilizar printf en c++ ya que puede dar errores, en vez de eso, utilizar cout

    std::cout<<"Hola, c++!\nLos valores de las variables son: " <<  a << ", " << c16 << ", " <<  c32 << ", " <<  i << ", " <<  f << ", " <<  d << ", " <<  b << ", " <<  CI;

    return 0;
}