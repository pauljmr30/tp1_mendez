<div align="right">
<img width="32px" src="img/algo2.svg">
</div>

# TP1

## Alumno: (Paul Mena) - (110893) - (pmena@fi.uba.ar)

- Para compilar:

```bash
gcc tp1.c src/pokedex.c src/csv.c -o tp1 -ggdb -O0 -std=c99 -Wall -Wconversion -Wtype-limits -Werror -I src
```

- Para ejecutar:

```bash
./tp1
```

- Para ejecutar con valgrind:
```bash
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=2 ./tp1 2>&1
```

---


##  Funcionamiento

Funcionamiento General
El programa recibe un archivo .csv con informacion de los pokemon a procesar.
Se abre el archivo en modo lectura en una estructura arhivo_csv.
Se inicializa una pokedex 

Funciones y procedimientos

Pokedex.c

* pokedex_crear: Asigna memoria para struct pokedex con malloc e inicializa sus campos; la memoria para el vector de pokemons es dinamica y depende la cantidad de los mismos, inicia en 0 bytes.
Todas las operaciones de la función son O(1) => pokedex_crear es O(1).

* pokedex_cantidad_pokemones: Complejidad O(1).
  
* pokedex_buscar_pokemon: Mediante strcmp(), compara el nombre ingresado con el de cada pokemon.
La funcion es O(n*m), ya que tiene un ciclo for(O(n) en el peor de los casos), strcmp(O(m) en el peor de los casos) y uno esta dentro del otro. 

*  pokedex_agregar_pokemon: Por cada pokemon que se agrega, reasgina memoria al vector pokemons de pokedex mediante un realloc aplicado a un vector de pokemons auxiliar, que de apuntar a una direcciòn valida, se le asigna esa dirección al vector pokemons. Finalmente, se copia los datos del pokemon agregado, en la ultima posicion del vector pokemons.
  La funcion es O(n+m), ya que contiene realloc(O(n)) y strlen(O(n)).

*  pokedex_iterar: La funcion es O(n*2) debido al ordenamiento de pokemons que tiene.
  
*  pokedex_destruir: Su complejidad es O(n) debido a que el ciclo iterará todos los pokemons de pokedex.

    Diagrama de struct pokedex *pokedex:
<div align="center">
<img width="70%" src="img/structpokedex.png">
</div>

Csv.c

*  abrir_archivo_csv: Su complejidad es O(1), ya que tanto el malloc usado, como la apertura de archivos, tienen esta complejidad.

*  extraer_columna: A partir de una linea de texto, extrae cada columna delimitada por un separador, usa el parametro *inicio, para que luego de extraer cada columna, guarda en inicio la posicion desde la que se va a procesar la siguiente columna.
Su complejidad es O(n), ya que el primer bucle solo recorre la linea hasta un valor de corte, y el segundo bucle solo copia los valores validos en la columna a retornar. 
  
*  leer_linea_csv: Aplica, a cada columna, cada funcion recibida con su contexto; y libera la memoria ocupada por la columna, luego de aplicarle la funcion correspondiente.
Su complejidad computacional es O(n*m), ya que extraer_columna es O(n) y se encuentra dentro de un bucle que iterará en cuanto columnas haya O(m). 
*  cerrar_archivo_csv: Su complejidad es O(1), ya que todas sus operaciones lo son.

  Diagrama de struct archivo_csv *archivo
<div align="center">
<img width="70%" src="img/structarchivo.png">
</div>

Una funcion de tp1.c

*  guardar_pokemon: Escribe los datos de los pokemons recibidos en pokedex, en un archivo txt, mediante el uso de pokedex_iterar_pokemones y aplicar las funciones: guardar_pokemon y contar tipos. Su complejidad es O(n) ya que emplea dos iteraciones O(n) por separado.


