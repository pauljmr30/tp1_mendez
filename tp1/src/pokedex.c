#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "pokedex.h"
#include "strings.h"

struct pokedex {
	size_t cantidad_pokemons;
	struct pokemon *pokemons;
	size_t capacidad;
};

struct pokedex *pokedex_crear()
{
	struct pokedex *pokedex =
		(struct pokedex *)malloc(sizeof(struct pokedex));

	if (pokedex == NULL) {
		return NULL;
	}

	pokedex->cantidad_pokemons = 0;
	pokedex->capacidad = 0;

	pokedex->pokemons = (struct pokemon *)malloc(
		sizeof(struct pokemon) * (pokedex->cantidad_pokemons));

	if (pokedex->pokemons == NULL) {
		free(pokedex);
		return NULL;
	}

	return pokedex;
}

size_t pokedex_cantidad_pokemones(struct pokedex *pokedex)
{
	if (pokedex == NULL) {
		return 0;
	}
	return pokedex->cantidad_pokemons;
}

const struct pokemon *pokedex_buscar_pokemon(struct pokedex *pokedex,
					     const char *nombre)
{
	if (pokedex == NULL) {
		return false;
	}

	struct pokemon *encontrado = NULL;

	for (size_t i = 0; i < pokedex->cantidad_pokemons; i++) {
		for (size_t j = 0; j < str_lenr(pokedex->pokemons[i].nombre, 0);
		     j++) {
			if (strings_iguales(nombre,
					    pokedex->pokemons[i].nombre)) {
				encontrado = (&pokedex->pokemons[i]);
			}
		}
	}
	return encontrado;
}

/*
    * pokedex debe tener todos los pokemon ordenados por nombre de forma creciente, salvo el ultimo pokemon
    *
    * Ordena por nombre, de forma creciente, el ultimo pokemon de pokedex
*/

void pokedex_ordenar_pokemons_alfabeticamente(struct pokedex *pokedex)
{
	if (pokedex == NULL) {
		return;
	}
	if (pokedex->cantidad_pokemons <= 1) {
		return;
	}
	size_t pokemons_no_ordenados = pokedex->cantidad_pokemons;
	while ((pokemons_no_ordenados > 1)) {
		struct pokemon pokemon_nombre_maximo = pokedex->pokemons[0];
		size_t posicion_maximo = 0;
		for (size_t i = 1; i < pokemons_no_ordenados; i++) {
			if (es_string_mayor_alfabeticamente(
				    pokemon_nombre_maximo.nombre,
				    pokedex->pokemons[i].nombre)) {
				pokemon_nombre_maximo = pokedex->pokemons[i];
				posicion_maximo = i;
			}
		}
		pokedex->pokemons[posicion_maximo] =
			pokedex->pokemons[pokemons_no_ordenados - 1];
		pokedex->pokemons[pokemons_no_ordenados - 1] =
			pokemon_nombre_maximo;
		pokemons_no_ordenados--;
	}
}

bool pokedex_agregar_pokemon(struct pokedex *pokedex, struct pokemon pokemon)
{
	if (pokedex == NULL) {
		return false;
	}
	if (pokemon.nombre == NULL) {
		return false;
	}

	struct pokemon *aux = (struct pokemon *)realloc(
		pokedex->pokemons,
		(pokedex->cantidad_pokemons + 1) * sizeof(struct pokemon));
	if (aux == NULL) {
		return false;
	}
	char *nombre_original = pokemon.nombre;
	pokemon.nombre = malloc(str_lenr(nombre_original, 0) + 1);
	if (pokemon.nombre == NULL) {
		return false;
	}
	pokedex->pokemons = aux;
	strcpy(pokemon.nombre, nombre_original);
	pokedex->pokemons[pokedex->cantidad_pokemons] = pokemon;
	pokedex->cantidad_pokemons++;

	return true;
}

size_t pokedex_iterar_pokemones(struct pokedex *pokedex,
				bool (*funcion)(struct pokemon *, void *),
				void *ctx)
{
	if (pokedex == NULL) {
		return 0;
	}
	size_t pokemones_iterados = 0;

	pokedex_ordenar_pokemons_alfabeticamente(pokedex);

	for (size_t i = 0; i < pokedex->cantidad_pokemons; i++) {
		if (!funcion(&pokedex->pokemons[pokemones_iterados], ctx)) {
			return pokemones_iterados + 1;

		} else {
			pokemones_iterados++;
		}
	}
	return pokemones_iterados;
}
void pokedex_destruir(struct pokedex *pokedex)
{
	if (pokedex == NULL)
		return;

	for (size_t i = 0; i < pokedex->cantidad_pokemons; i++) {
		free(pokedex->pokemons[i].nombre);
	}
	free(pokedex->pokemons);
	free(pokedex);
}