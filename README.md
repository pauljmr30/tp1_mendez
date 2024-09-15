Archivos Entregados
===================

[ 165]  .
|-- [2.1K]  Enunciado.md
|-- [1.9K]  README.md
|-- [1.1K]  ejemplo.c
|-- [  45]  ejemplos
|   |-- [  75]  correcto.txt
|   `-- [ 164]  pokedex.csv
|-- [  88]  img
|   |-- [ 32K]  algo2.svg
|   |-- [ 19K]  diagrama1.svg
|   |-- [9.9K]  diagrama2.svg
|   `-- [152K]  tp1_ejemplo.png
|-- [ 667]  makefile
|-- [1.1K]  pa2m.h
|-- [ 466]  pruebas_alumno.c
|-- [ 100]  src
|   |-- [2.2K]  csv.c
|   |-- [1.2K]  csv.h
|   |-- [3.7K]  pokedex.c
|   |-- [1.6K]  pokedex.h
|   |-- [ 884]  strings.c
|   `-- [ 554]  strings.h
`-- [4.3K]  tp1.c

4 directories, 19 files

[1;35mLinter
======
[0m
[1;32mLINTER OK[0m

[1;35mCompilación y pruebas
=====================[0m
rm -f *.o pruebas_chanutron pruebas_alumno
gcc -std=c99 -Wall -Wconversion -Wtype-limits -pedantic -Werror -O2 -g src/*.c pruebas.c -o pruebas_chanutron
rm -f pruebas.c
valgrind --leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=2 --show-leak-kinds=all --trace-children=yes ./pruebas_chanutron
==22894== Memcheck, a memory error detector
==22894== Copyright (C) 2002-2022, and GNU GPL'd, by Julian Seward et al.
==22894== Using Valgrind-3.22.0 and LibVEX; rerun with -h for copyright info
==22894== Command: ./pruebas_chanutron
==22894== 
[33;1m
Pruebas de apertura de CSV
==========================[37;1m
[32;1m✓ [37;1mAbrir un archivo inexistente devuelve NULL
[32;1m✓ [37;1mAbrir un archivo existente devuelve un puntero no nulo
==22895== 
==22895== HEAP SUMMARY:
==22895==     in use at exit: 0 bytes in 0 blocks
==22895==   total heap usage: 5 allocs, 5 frees, 5,072 bytes allocated
==22895== 
==22895== All heap blocks were freed -- no leaks are possible
==22895== 
==22895== For lists of detected and suppressed errors, rerun with: -s
==22895== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
[33;1m
Pruebas de lectura de CSV ejemplo
=================================[37;1m
[32;1m✓ [37;1mLeer linea del archivo de ejemplo devuelve 3 columnas
[32;1m✓ [37;1mEl entero leído es el esperado (1 <-> 1)
[32;1m✓ [37;1mEl string leído es el esperado (Pikachu <-> Pikachu)
[32;1m✓ [37;1mEl caracter leído es el esperado (E <-> E)
[32;1m✓ [37;1mLeer linea del archivo de ejemplo devuelve 3 columnas
[32;1m✓ [37;1mEl entero leído es el esperado (2 <-> 2)
[32;1m✓ [37;1mEl string leído es el esperado (Charmander <-> Charmander)
[32;1m✓ [37;1mEl caracter leído es el esperado (F <-> F)
[32;1m✓ [37;1mLeer linea del archivo de ejemplo devuelve 3 columnas
[32;1m✓ [37;1mEl entero leído es el esperado (5 <-> 5)
[32;1m✓ [37;1mEl string leído es el esperado (Larvitar <-> Larvitar)
[32;1m✓ [37;1mEl caracter leído es el esperado (R <-> R)
[32;1m✓ [37;1mLeer linea del archivo de ejemplo devuelve 3 columnas
[32;1m✓ [37;1mEl entero leído es el esperado (7 <-> 7)
[32;1m✓ [37;1mEl string leído es el esperado (Cacnea <-> Cacnea)
[32;1m✓ [37;1mEl caracter leído es el esperado (P <-> P)
[32;1m✓ [37;1mLeer linea del archivo de ejemplo devuelve 3 columnas
[32;1m✓ [37;1mEl entero leído es el esperado (8 <-> 8)
[32;1m✓ [37;1mEl string leído es el esperado (Togepi <-> Togepi)
[32;1m✓ [37;1mEl caracter leído es el esperado (N <-> N)
[32;1m✓ [37;1mLeer linea del archivo de ejemplo devuelve 3 columnas
[32;1m✓ [37;1mEl entero leído es el esperado (1 <-> 1)
[32;1m✓ [37;1mEl string leído es el esperado (Floatzel <-> Floatzel)
[32;1m✓ [37;1mEl caracter leído es el esperado (A <-> A)
[32;1m✓ [37;1mIntentar leer una línea más de la cuenta devuelve 0 columnas
==22896== 
==22896== HEAP SUMMARY:
==22896==     in use at exit: 0 bytes in 0 blocks
==22896==   total heap usage: 28 allocs, 28 frees, 8,806 bytes allocated
==22896== 
==22896== All heap blocks were freed -- no leaks are possible
==22896== 
==22896== For lists of detected and suppressed errors, rerun with: -s
==22896== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
[33;1m
Pruebas de lectura de CSV con trampa
====================================[37;1m
[32;1m✓ [37;1mLeer linea del archivo de ejemplo devuelve 2 columnas cuando la tercer funcion es nula
[32;1m✓ [37;1mLeer linea del archivo de ejemplo devuelve 3 columnas cuando los punteros son nulos (y la funcion de parseo no los usa)
[32;1m✓ [37;1mPuedo leer 15 campos de un archivo con lineas largas
[32;1m✓ [37;1mEl entero leído es el esperado (1 <-> 1)
[32;1m✓ [37;1mEl entero leído es el esperado (2 <-> 2)
[32;1m✓ [37;1mEl entero leído es el esperado (3 <-> 3)
[32;1m✓ [37;1mEl entero leído es el esperado (4 <-> 4)
[32;1m✓ [37;1mEl entero leído es el esperado (5 <-> 5)
[32;1m✓ [37;1mEl entero leído es el esperado (6 <-> 6)
[32;1m✓ [37;1mEl entero leído es el esperado (7 <-> 7)
[32;1m✓ [37;1mEl entero leído es el esperado (8 <-> 8)
[32;1m✓ [37;1mEl entero leído es el esperado (9 <-> 9)
[32;1m✓ [37;1mEl entero leído es el esperado (10 <-> 10)
[32;1m✓ [37;1mEl entero leído es el esperado (11 <-> 11)
[32;1m✓ [37;1mEl entero leído es el esperado (12 <-> 12)
[32;1m✓ [37;1mEl entero leído es el esperado (13 <-> 13)
[32;1m✓ [37;1mEl entero leído es el esperado (14 <-> 14)
[32;1m✓ [37;1mEl entero leído es el esperado (15 <-> 15)
[32;1m✓ [37;1mLeer una linea de un archivo nulo devuelve 0 columnas
[32;1m✓ [37;1mLeer una linea con 0 columnas devuelve 0 columnas
==22897== 
==22897== HEAP SUMMARY:
==22897==     in use at exit: 0 bytes in 0 blocks
==22897==   total heap usage: 35 allocs, 35 frees, 22,500 bytes allocated
==22897== 
==22897== All heap blocks were freed -- no leaks are possible
==22897== 
==22897== For lists of detected and suppressed errors, rerun with: -s
==22897== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
[33;1m
Pruebas de creacion de pokedex
==============================[37;1m
[32;1m✓ [37;1mCrear una pokedex devuelve un puntero no nulo
[32;1m✓ [37;1mLa pokedex creada tiene 0 pokemones
[32;1m✓ [37;1mBuscar un pokemon en una pokedex vacia devuelve NULL
[32;1m✓ [37;1mIterar una pokedex vacia devuelve 0 pokemones
[32;1m✓ [37;1mContar los pokemones de una pokedex vacia invoca 0 veces la funcion de iteracion
==22898== 
==22898== HEAP SUMMARY:
==22898==     in use at exit: 0 bytes in 0 blocks
==22898==   total heap usage: 3 allocs, 3 frees, 4,120 bytes allocated
==22898== 
==22898== All heap blocks were freed -- no leaks are possible
==22898== 
==22898== For lists of detected and suppressed errors, rerun with: -s
==22898== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
[33;1m
Prueba de agregado y busqueda de pokemon en la pokedex
======================================================[37;1m
==22899== Invalid read of size 1
==22899==    at 0x109FD0: strings_iguales (strings.c:17)
==22899==    by 0x109C78: pokedex_buscar_pokemon (pokedex.c:57)
==22899==    by 0x10BF8B: pokedexAgregarAgregaUnPokemon (pruebas.c:266)
==22899==    by 0x1097A5: main (pruebas.c:508)
==22899==  Address 0x4a73188 is 0 bytes after a block of size 8 alloc'd
==22899==    at 0x4846828: malloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==22899==    by 0x109E49: pokedex_agregar_pokemon (pokedex.c:123)
==22899==    by 0x10BACB: pokedexAgregarAgregaUnPokemon (pruebas.c:235)
==22899==    by 0x1097A5: main (pruebas.c:508)
==22899== 
[32;1m✓ [37;1mAgregar un pokemon a la pokedex vacía devuelve true
[32;1m✓ [37;1mLa pokedex tiene 1 pokemon
[32;1m✓ [37;1mBuscar un pokemon existente en la pokedex devuelve un pokemon
[32;1m✓ [37;1mEl nombre del pokemon encontrado es el esperado (Pikachu <-> Pikachu)
[32;1m✓ [37;1mEl tipo del pokemon encontrado es el esperado (E <-> E)
[32;1m✓ [37;1mLa fuerza del pokemon encontrado es la esperada (10 <-> 10)
[32;1m✓ [37;1mLa destreza del pokemon encontrado es la esperada (11 <-> 11)
[32;1m✓ [37;1mLa resistencia del pokemon encontrado es la esperada (12 <-> 12)
[32;1m✓ [37;1mBuscar un pokemon que no esta en la pokedex devuelve NULL
[32;1m✓ [37;1mIterar una pokedex con un pokemon devuelve 1 pokemon
[32;1m✓ [37;1mContar los pokemones de una pokedex con un pokemon invoca 1 vez la funcion de iteracion
==22899== 
==22899== HEAP SUMMARY:
==22899==     in use at exit: 0 bytes in 0 blocks
==22899==   total heap usage: 5 allocs, 5 frees, 4,152 bytes allocated
==22899== 
==22899== All heap blocks were freed -- no leaks are possible
==22899== 
==22899== For lists of detected and suppressed errors, rerun with: -s
==22899== ERROR SUMMARY: 14 errors from 1 contexts (suppressed: 0 from 0)
[33;1m
Pruebas de iteracion
====================[37;1m
[32;1m✓ [37;1mIterar una pokedex con 6 pokemones devuelve 6
[32;1m✓ [37;1mLa función se invoca 6 veces
[32;1m✓ [37;1mEl pokemon 0 es Cacnea -> Cacnea
[32;1m✓ [37;1mEl pokemon 1 es Charmander -> Charmander
[32;1m✓ [37;1mEl pokemon 2 es Floatzel -> Floatzel
[32;1m✓ [37;1mEl pokemon 3 es Larvitar -> Larvitar
[32;1m✓ [37;1mEl pokemon 4 es Pikachu -> Pikachu
[32;1m✓ [37;1mEl pokemon 5 es Togepi -> Togepi
[31;1m✗ [37;1mIterar una pokedex con 6 pokemones y detenerse en el tercero devuelve 3
[32;1m✓ [37;1mLa función se invoca 3 veces
==22900== 
==22900== HEAP SUMMARY:
==22900==     in use at exit: 0 bytes in 0 blocks
==22900==   total heap usage: 25 allocs, 25 frees, 4,966 bytes allocated
==22900== 
==22900== All heap blocks were freed -- no leaks are possible
==22900== 
==22900== For lists of detected and suppressed errors, rerun with: -s
==22900== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
[33;1m
Pruebas de pokedex con punteros nulos
=====================================[37;1m
[32;1m✓ [37;1mContar los pokemones de una pokedex nula devuelve 0
[32;1m✓ [37;1mAgregar un pokemon a una pokedex nula devuelve false
[32;1m✓ [37;1mBuscar un pokemon en una pokedex nula devuelve NULL
[32;1m✓ [37;1mIterar una pokedex nula devuelve 0 pokemones
[32;1m✓ [37;1mDestruir una pokedex nula no hace nada
[32;1m✓ [37;1mAgregar un pokemon con nombre nulo a la pokedex devuelve false
[32;1m✓ [37;1mLa pokedex tiene 0 pokemones
==22901== 
==22901== HEAP SUMMARY:
==22901==     in use at exit: 0 bytes in 0 blocks
==22901==   total heap usage: 3 allocs, 3 frees, 4,120 bytes allocated
==22901== 
==22901== All heap blocks were freed -- no leaks are possible
==22901== 
==22901== For lists of detected and suppressed errors, rerun with: -s
==22901== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
[33;1m
Ultimas pruebas
===============[37;1m
[32;1m✓ [37;1mAgregar 10 veces el mismo pokemon a la pokedex devuelve true las 10 veces
[32;1m✓ [37;1mLa pokedex tiene 10 pokemones
[32;1m✓ [37;1mBuscar un pokemon existente en la pokedex devuelve un pokemon
[32;1m✓ [37;1mIterar una pokedex con 10 pokemones devuelve 10
[32;1m✓ [37;1mCreo otra pokedex y agrego 10 pokemones con el mismo puntero a nombre (pero variando el contenido)
[32;1m✓ [37;1mLa pokedex tiene 10 pokemones
[32;1m✓ [37;1mBuscar encuentra el pokemon con el nombre esperado (poke0)
[32;1m✓ [37;1mBuscar encuentra el pokemon con el nombre esperado (poke1)
[32;1m✓ [37;1mBuscar encuentra el pokemon con el nombre esperado (poke2)
[32;1m✓ [37;1mBuscar encuentra el pokemon con el nombre esperado (poke3)
[32;1m✓ [37;1mBuscar encuentra el pokemon con el nombre esperado (poke4)
[32;1m✓ [37;1mBuscar encuentra el pokemon con el nombre esperado (poke5)
[32;1m✓ [37;1mBuscar encuentra el pokemon con el nombre esperado (poke6)
[32;1m✓ [37;1mBuscar encuentra el pokemon con el nombre esperado (poke7)
[32;1m✓ [37;1mBuscar encuentra el pokemon con el nombre esperado (poke8)
[32;1m✓ [37;1mBuscar encuentra el pokemon con el nombre esperado (poke9)
==22902== 
==22902== HEAP SUMMARY:
==22902==     in use at exit: 0 bytes in 0 blocks
==22902==   total heap usage: 35 allocs, 35 frees, 5,772 bytes allocated
==22902== 
==22902== All heap blocks were freed -- no leaks are possible
==22902== 
==22902== For lists of detected and suppressed errors, rerun with: -s
==22902== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
[37;1m
---------------------------------
96 pruebas corridas, 1 errores - D:
[0m==22894== 
==22894== HEAP SUMMARY:
==22894==     in use at exit: 0 bytes in 0 blocks
==22894==   total heap usage: 1 allocs, 1 frees, 4,096 bytes allocated
==22894== 
==22894== All heap blocks were freed -- no leaks are possible
==22894== 
==22894== For lists of detected and suppressed errors, rerun with: -s
==22894== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
make: *** [makefile-chanutron:8: valgrind] Error 2

[1;31m¡ERROR CORRIENDO VALGRIND! Revisa tu entrega, las pruebas de la CÁTEDRA no pasan.[0m
