#include <stdio.h>

#include "strings.h"

size_t str_lenr(const char *cadena, size_t contador)
{
	if (cadena[contador] == 0)
		return contador;
	return str_lenr(cadena, contador + 1);
}

bool strings_iguales(const char *string1, const char *string2)
{
	bool son_iguales = true;
	for (size_t i = 0; i < str_lenr(string1, 0); i++) {
		if (string1[i] != string2[i]) {
			son_iguales = false;
		}
	}
	return son_iguales;
}

bool es_string_mayor_alfabeticamente(char *string_comparado,
				     char *string_comparador)
{
	bool es_mayor = false;
	size_t iterador = 0;

	while (!es_mayor && iterador < str_lenr(string_comparado, 0)) {
		if (string_comparado[iterador] < string_comparador[iterador]) {
			es_mayor = true;
		} else if (string_comparado[iterador] >
			   string_comparador[iterador]) {
			iterador = str_lenr(string_comparado, 0) + 1;
		}
		iterador++;
	}

	return es_mayor;
}