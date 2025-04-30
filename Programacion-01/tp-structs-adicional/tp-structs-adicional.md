# TP Adicional Structs:

Una cadena de Cines nos pidió llevar un registro de sus sucursales:

```c
typedef struct{
    int id;
    char nombre[50];
    char ubicacion[100];
    Pelicula cartelera[10];
    int validosCartel;
}CineSucursal;
```

La Struct Película está compuesta de un nombre, un género, y una duración.

1) Primero haremos la carga de datos, por lo que vamos a diseñar una función que nos cargue una película, y otra que nos cargue la sucursal (con las películas en cartelera).

2) Mostrar el arreglo de sucursales cargado previamente. Con las funciones correspondientes para modularizar.

3) Buscar una sucursal por medio de su ID y luego mostrar sus datos (incluyendo la cartelera).

4) Utilizando la función del ejercicio 3, realizar un filtro por género de la película. Solo debemos mostrar los datos que cumplan con el filtro, no es necesario guardarlos.

5) Ordenar el arreglo de sucursales de menor a mayor por su id, se puede usar inserción o selección.

6) Como la cartelera normalmente se va actualizando, Usaremos la función del ejercicio 3 nuevamente, y haremos una función que cargue nuevamente la cartelera, es decir, empezar la cartelera desde la pos 0 del arreglo.

7) Eliminar una Película de la Cartelera. Permitir que el usuario indique una sucursal por ID y un nombre de película para eliminarla de la cartelera (desplazando el array para no dejar huecos).

8) Promedio de Duración de Películas de una Sucursal. Dada una sucursal (elegida por ID), calcula el promedio de duración de sus películas.

9) Listar Todas las Películas de Todas las Sucursales. Crear una función que liste todas las películas existentes (sin repetir sucursales, sólo nombres de películas con su género y duración).

10) Ordenar las Películas de una Sucursal por Duración. Dentro de una sucursal, ordenar las películas de menor a mayor duración (usar método de inserción o selección).

11) Buscar una Película en Todas las Sucursales. Pedir el nombre de una película y mostrar en qué sucursales está disponible.

12) Encontrar el género más común en una Sucursal. En una sucursal específica, determinar cuál es el género de películas más repetido.
