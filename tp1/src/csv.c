#include "csv.h"
#include "strings.h"
#include <stdio.h>
#include <string.h>

struct archivo_csv {

    char separador;
    FILE* archivo;
};

struct archivo_csv *abrir_archivo_csv(const char *nombre_archivo,
				      char separador)
{
    struct archivo_csv *archivo = malloc(sizeof(struct archivo_csv));

    if(archivo == NULL)
        return NULL;
        
    archivo->archivo = fopen(nombre_archivo, "r");

    if(archivo->archivo == NULL){
        free(archivo);
        return NULL;
    }
    archivo->separador = separador;

	return archivo;
}

char *extraer_columna(const char *linea, char separador, size_t *inicio)
{
	size_t j = *inicio;
	size_t posicion_valida = 0;
	int tamaño_columna = -1;
	size_t longitud_linea = str_lenr(linea, 0);
	char* columna = NULL;

	for (size_t i = (*inicio); i <= longitud_linea; i++) {
		(linea[i] !=32)?(tamaño_columna++):(tamaño_columna+0);
		if ((linea[i] == separador || linea[i] == 10 || i == longitud_linea) && (tamaño_columna != 0)) {
			size_t longitud = (i - j);
			*inicio = i + 1;
			columna = malloc((size_t)tamaño_columna + 1);
			if(columna == NULL){
                return columna;
            }
            for (size_t k = 0; k < longitud; k++) {
				if(!((linea[j + k]) == 32)){
					columna[posicion_valida] = linea[j+k];
					posicion_valida++; 
				}
			}
			columna[posicion_valida] = 0;
			return columna;
		}
	}
	return NULL;
}


size_t leer_linea_csv(struct archivo_csv *archivo, size_t columnas,
		      bool (*funciones[])(const char *, void *), void *ctx[])
{
    char linea[1024];
    if((fgets(linea, sizeof(linea), archivo->archivo)) == NULL)
        return 0;


    size_t columnas_leidas = 0;
    size_t inicio = 0;
    while(columnas_leidas < columnas){
        char *columna = extraer_columna(linea, archivo->separador, &inicio);
        if(columna == NULL){
           
           break; 
        }
        if(funciones[columnas_leidas](columna,ctx[columnas_leidas])){
            columnas_leidas++;
        }
        else{
            free(columna);
            break;
        }
        free(columna);
    }
	return columnas_leidas;
}

void cerrar_archivo_csv(struct archivo_csv *archivo)
{

    if(archivo!=NULL){
        fclose(archivo->archivo);
        free(archivo);
    }

}
