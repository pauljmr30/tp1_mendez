#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "src/pokedex.h"
#include "src/csv.h"
#include "src/strings.h"

struct tipos_pokemon {
	size_t cantidad_tipo_agua;
	size_t cantidad_tipo_fuego;
	size_t cantidad_tipo_planta;
	size_t cantidad_tipo_roca;
	size_t cantidad_tipo_electrico;
	size_t cantidad_tipo_normal;
	size_t cantidad_tipo_lucha;
};

struct tipos_pokemon *inicializar_tipos_pokemon()
{
	struct tipos_pokemon *tipos =
		(struct tipos_pokemon *)malloc(sizeof(struct tipos_pokemon));
	if (tipos == NULL) {
		return NULL;
	}
	tipos->cantidad_tipo_agua = 0;
	tipos->cantidad_tipo_fuego = 0;
	tipos->cantidad_tipo_planta = 0;
	tipos->cantidad_tipo_roca = 0;
	tipos->cantidad_tipo_electrico = 0;
	tipos->cantidad_tipo_normal = 0;
	tipos->cantidad_tipo_lucha = 0;

	return tipos;
}

bool leer_int(const char *str, void *ctx)
{
	return sscanf(str, "%d", (int *)ctx) == 1;
}

bool leer_char(const char *str, void *ctx)
{
	*(char *)ctx = str[0];
	return true;
}

bool crear_nuevo_string(const char *string, void *ctx)
{
	char *nuevo = malloc(str_lenr(string, 0) + 1);
	if (nuevo == NULL)
		return false;
	strcpy(nuevo, string);
	*(char **)ctx = nuevo;
	return true;
}

/*
    * Agrega el pokemon recibido a un archivo txt recibido en ctx
*/
bool guardar_pokemon(struct pokemon *pokemon, void *ctx)
{
	FILE *archivo_txt = (FILE *)ctx;

	fprintf(archivo_txt,
		"Nombre: %s, Tipo: %c, Fuerza: %i, Destreza: %i, Resistencia: %i \n",
		pokemon->nombre, pokemon->tipo, pokemon->fuerza,
		pokemon->destreza, pokemon->resistencia);
	return true;
}
/*
    * De acuerdo al tipo del pokemon recibido, suma la cantidad de este tipo en el struct
        tipos_pokemon recibido en ctx
*/
bool contar_tipos(struct pokemon *pokemon, void *ctx)
{
	struct tipos_pokemon *tipos = (struct tipos_pokemon *)ctx;
	switch (pokemon->tipo) {
	case TIPO_AGUA:
		tipos->cantidad_tipo_agua++;
		break;
	case TIPO_FUEGO:
		tipos->cantidad_tipo_fuego++;
		break;
	case TIPO_PLANTA:
		tipos->cantidad_tipo_planta++;
		break;
	case TIPO_ROCA:
		tipos->cantidad_tipo_roca++;
		break;
	case TIPO_ELECTRICO:
		tipos->cantidad_tipo_electrico++;
		break;
	case TIPO_NORMAL:
		tipos->cantidad_tipo_normal++;
		break;
	case TIPO_LUCHA:
		tipos->cantidad_tipo_lucha++;
		break;
	}
	return true;
}
/*
    * Guarda los datos de los pokemones de la pokedex en un archivo txt, junto con las cantidades totales de cada tipo de pokemon
*/
void guardar_pokemones_txt(struct pokedex *pokedex, const char *nombre_archivo,
			   struct tipos_pokemon *tipos)
{
	FILE *archivo_txt = fopen(nombre_archivo, "w");
	if (archivo_txt == NULL) {
		printf("Error al abrir el archivo de salida\n");
		return;
	}
	pokedex_iterar_pokemones(pokedex, guardar_pokemon, archivo_txt);
	pokedex_iterar_pokemones(pokedex, contar_tipos, tipos);
	fprintf(archivo_txt,
		"Cantidad de pokemones de cada tipo:\nAgua: %li\nFuego: %li\nPlanta: %li\nRoca: %li\nElectrico: %li\nNormal: %li\nLucha: %li",
		tipos->cantidad_tipo_agua, tipos->cantidad_tipo_fuego,
		tipos->cantidad_tipo_planta, tipos->cantidad_tipo_roca,
		tipos->cantidad_tipo_electrico, tipos->cantidad_tipo_normal,
		tipos->cantidad_tipo_lucha);

	fclose(archivo_txt);
}

int main(int argc, char *argv[])
{
	struct archivo_csv *archivo = abrir_archivo_csv("pokemones.csv", ';');

	if (archivo == NULL) {
		printf("ERROR al intentar abrir el archivo.\n");
		return 1;
	}
	struct pokedex *pokedex = pokedex_crear();
	if (pokedex == NULL) {
		printf("ERROR al crear la pokedex\n");
		return 1;
	}
	bool (*funciones[5])(const char *, void *) = { crear_nuevo_string,
						       leer_char, leer_int,
						       leer_int, leer_int };
	char *nombre = NULL;
	char tipo;
	int fuerza, destreza, resistencia;

	void *contextos[] = { &nombre, &tipo, &fuerza, &destreza,
			      &resistencia };
	printf("Leyendo lineas ...\n");
	while (leer_linea_csv(archivo, 5, funciones, contextos) > 0) {
		printf("%s %c %i %i %i\n", nombre, tipo, fuerza, destreza,
		       resistencia);
		struct pokemon pokemon = {
			.nombre = nombre,
			.tipo = tipo,
			.fuerza = fuerza,
			.destreza = destreza,
			.resistencia = resistencia,
		};

		if (!pokedex_agregar_pokemon(pokedex, pokemon)) {
			printf("Error al agregar el pokemon a la pokedex\n");
		}
		free(nombre);
	}
	struct tipos_pokemon *tipos = inicializar_tipos_pokemon();
	cerrar_archivo_csv(archivo);
	guardar_pokemones_txt(pokedex, "pokemones.txt", tipos);
	pokedex_destruir(pokedex);
	free(tipos);

	return 0;
}
