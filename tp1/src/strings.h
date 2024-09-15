#ifndef STRINGS_H
#define STRINGS_H

#include <stdlib.h>
#include <stdbool.h>

/*
    * Recibe una cadena y un contador inicializado en 0
    * 
    * Devuelve la cantidad de caracteres de la cadena
*/
size_t str_lenr(const char *cadena, size_t contador);

/*
    * Devuelve true si las cadenas son iguales, false
        caso contrario
*/
bool strings_iguales(const char *cadena1, const char *cadena2);

/*
    Devuelve true si la cadena2 es mayor a la cadena1
*/
bool es_string_mayor_alfabeticamente(char *cadena1, char *cadena2);

#endif // STRINGS_H
