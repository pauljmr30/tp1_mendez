#include "pa2m.h"
#include <string.h>
#include "src/csv.h"
#include "src/pokedex.h"

void abrirUnArchivoInexistenteDebeRetornarNull()
{
	struct archivo_csv *archivo =
		abrir_archivo_csv("noexiste/noexiste/noexiste/no", ';');
	pa2m_afirmar(archivo == NULL, "El archivo no existe y se retorna NULL");
}

void buscarPokemonEnPokedexVaciaDebeRetornarNull()
{
	struct pokedex *pokedex = pokedex_crear();
	const struct pokemon *resultado =
		pokedex_buscar_pokemon(pokedex, "Pikachu");
	pa2m_afirmar(resultado == NULL,
		     "Buscar en una pokedex vacía retorna NULL");
	pokedex_destruir(pokedex);
}
void buscarPokemonInexistenteDebeRetornarNull()
{
	struct pokedex *pokedex = pokedex_crear();

	struct pokemon pikachu = { "Pikachu", 'E', 55, 40, 35 };
	pokedex_agregar_pokemon(pokedex, pikachu);

	const struct pokemon *resultado =
		pokedex_buscar_pokemon(pokedex, "Charmander");
	pa2m_afirmar(resultado == NULL,
		     "Buscar un Pokémon inexistente retorna NULL");

	pokedex_destruir(pokedex);
}
void buscarPokemonExistenteDebeRetornarPokemon()
{
	struct pokedex *pokedex = pokedex_crear();

	struct pokemon pikachu = { "Pikachu", 'E', 55, 40, 35 };
	struct pokemon charmander = { "Charmander", 'F', 52, 43, 39 };
	pokedex_agregar_pokemon(pokedex, pikachu);
	pokedex_agregar_pokemon(pokedex, charmander);

	const struct pokemon *resultado =
		pokedex_buscar_pokemon(pokedex, "Pikachu");
	pa2m_afirmar(resultado != NULL &&
			     strcmp(resultado->nombre, "Pikachu") == 0,
		     "Buscar un Pokémon existente retorna el Pokémon correcto");

	pokedex_destruir(pokedex);
}

void agregarPokemonAPokedexNulaDebeRetornarFalse()
{
	struct pokemon pikachu = { "Pikachu", 'E', 55, 40, 35 };
	bool resultado = pokedex_agregar_pokemon(NULL, pikachu);
	pa2m_afirmar(resultado == false,
		     "No se puede agregar un Pokémon a una Pokedex nula");
}
void agregarPokemonConNombreNullDebeRetornarFalse()
{
	struct pokemon pikachu = { NULL, 'E', 55, 40, 35 };
	struct pokedex *pokedex = pokedex_crear();
	bool resultado = pokedex_agregar_pokemon(pokedex, pikachu);
	pa2m_afirmar(resultado == false,
		     "No se puede agregar un Pokémon sin nombre");
	pokedex_destruir(pokedex);
}
void agregarPokemonIgualCincoVecesDevuelveTrue()
{
	struct pokemon pikachu = { "Pikachu", 'E', 55, 40, 35 };
	struct pokedex *pokedex = pokedex_crear();
	size_t i = 0;
	bool resultado = true;
	while (i < 5) {
		resultado = pokedex_agregar_pokemon(pokedex, pikachu);
		if (resultado == false) {
			i += 5;
			resultado = false;
		}
		i++;
	}
	pa2m_afirmar(resultado,
		     "Devolver el mismo Pokémon 5 veces debe devolver true");
	pokedex_destruir(pokedex);
}

bool detenerseEnTercerPokemon(struct pokemon *pokemon, void *contador)
{
	int *contador_iteraciones = contador;
	(*contador_iteraciones)++;

	if (*contador_iteraciones == 3) {
		return false;
	}

	return true;
}

void iterarPokedexConSeisPokemonesDetenerseEnTerceroDevuelveTres()
{
	struct pokedex *pokedex = pokedex_crear();

	struct pokemon pikachu = { "Pikachu", 'E', 1, 1, 1 };
	struct pokemon charmander = { "Charmander", 'F', 2, 2, 2 };
	struct pokemon squirtle = { "Squirtle", 'A', 3, 3, 3 };
	struct pokemon bulbasaur = { "Bulbasaur", 'P', 4, 4, 5 };
	struct pokemon eevee = { "Eevee", 'N', 6, 6, 6 };
	struct pokemon meowth = { "Meowth", 'N', 7, 7, 7 };

	pokedex_agregar_pokemon(pokedex, pikachu);
	pokedex_agregar_pokemon(pokedex, charmander);
	pokedex_agregar_pokemon(pokedex, squirtle);
	pokedex_agregar_pokemon(pokedex, bulbasaur);
	pokedex_agregar_pokemon(pokedex, eevee);
	pokedex_agregar_pokemon(pokedex, meowth);

	int contador = 0;
	size_t pokemones_iterados = pokedex_iterar_pokemones(
		pokedex, detenerseEnTercerPokemon, &contador);

	pa2m_afirmar(
		pokemones_iterados == 3,
		"Iterar una pokedex con 6 pokemones y detenerse en el tercero devuelve 3");
	pa2m_afirmar(contador == 3, "La función se invoca 3 veces");

	pokedex_destruir(pokedex);
}

void pokedeAgregarAgregaUnPokemon()
{
	struct pokedex *pokedex = pokedex_crear();
	struct pokemon pikachu = { "Pikachu", 'E', 55, 40, 35 };
	pa2m_afirmar(pokedex_agregar_pokemon(pokedex, pikachu),
		     "Agregar un Pokémon a pokedex");
	pokedex_destruir(pokedex);
}
void agregarUnPokemonALaPokedexDebeIncrementarLaCantidadDePokemones()
{
	struct pokedex *pokedex = pokedex_crear();

	struct pokemon pikachu = { "Pikachu", 'E', 55, 40, 35 };

	pa2m_afirmar(pokedex_agregar_pokemon(pokedex, pikachu),
		     "Agregar un Pokémon a la pokedex devuelve true");
	pa2m_afirmar(
		pokedex_cantidad_pokemones(pokedex) == 1,
		"La cantidad de Pokémon en la Pokédex es 1 después de agregar");

	const struct pokemon *pokemon_encontrado =
		pokedex_buscar_pokemon(pokedex, "Pikachu");
	pa2m_afirmar(pokemon_encontrado != NULL &&
			     strcmp(pokemon_encontrado->nombre,
					     "Pikachu") == 0,
		     "El Pokémon agregado está correctamente en la pokedex");

	pokedex_destruir(pokedex);
}
int main()
{
	pa2m_nuevo_grupo("Pruebas de archivos CSV");
	abrirUnArchivoInexistenteDebeRetornarNull();
	pa2m_nuevo_grupo("Pruebas de pokedex\n");

	buscarPokemonEnPokedexVaciaDebeRetornarNull();
	buscarPokemonInexistenteDebeRetornarNull();
	buscarPokemonExistenteDebeRetornarPokemon();
	printf("\n");
	agregarPokemonAPokedexNulaDebeRetornarFalse();
	agregarPokemonConNombreNullDebeRetornarFalse();
	agregarPokemonIgualCincoVecesDevuelveTrue();
	printf("\n"),
	iterarPokedexConSeisPokemonesDetenerseEnTerceroDevuelveTres();
	pokedeAgregarAgregaUnPokemon();
	agregarUnPokemonALaPokedexDebeIncrementarLaCantidadDePokemones();

	return pa2m_mostrar_reporte();
}
