#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "utils.h"	  // cleanBuffer alternativa multisistema a fflush(stdin)
#include "platform.h" // Detecta Win/Linux
#define MAX_STR 50
#define MAX_PELICULAS 10
#define MAX_SUCURSALES 20
typedef struct
{
	char nombre[MAX_STR];
	char genero[MAX_STR];
	float duracion;
} Pelicula;

typedef struct
{
	int id;
	char nombre[MAX_STR];
	char ubicacion[MAX_STR];
	Pelicula cartelera[MAX_PELICULAS];
	int cartelerasCargadas;
} CineSucursal;

typedef struct
{
	CineSucursal sucursales[MAX_SUCURSALES];
	int sucursalesCargadas;
} CineSucursales;
// HELPERS
void mostrarSucursal(CineSucursal cine);
// 1
Pelicula cargarPeliculaM();
CineSucursal cargarSucursalM();
void cargarCartelera(CineSucursal *nuevaSucursal);
void cargarSucursales(CineSucursales *sucursales);
void mostrarPelicula(Pelicula pelicula);
void mostrarCartelera(Pelicula peliculas[], int max);
void mostrarDATA(CineSucursales data);
int main()
{
	CineSucursales cineSucursales = {
		.sucursalesCargadas = 0,
		.sucursales = {{0}},
	};
	char volverAlInicio = 's';
	while (volverAlInicio != 'n')
	{
		cargarSucursales(&cineSucursales);
		mostrarDATA(cineSucursales);
		// CORTE WHILE
		printf("\n Volver al inicio? (s/n): ");
		scanf(" %c", &volverAlInicio);
		cleanBuffer();
		system(CLEAR);
	}

	return 0;
}
// HELPERS
void mostrarSucursal(CineSucursal cine)
{
	printf("\n| CINE : %i | NOMBRE: %s | UBICACION : %s|\n", cine.id, cine.nombre, cine.ubicacion);
}
// 1
Pelicula cargarPeliculaM()
{
	Pelicula nuevaPelicula;
	printf("> Ingrese los datos de la pelicula:\n");

	printf("• Nombre: ");
	gets(nuevaPelicula.nombre);

	printf("• Genero: ");
	gets(nuevaPelicula.genero);

	printf("• Duracion: ");
	scanf(" %f", &nuevaPelicula.duracion);

	return nuevaPelicula;
}
CineSucursal cargarSucursalM()
{
	CineSucursal nuevaSucursal;
	int *index = &nuevaSucursal.cartelerasCargadas;
	printf("> Ingrese los datos de la sucursal:\n");
	printf("• ID (numerico): ");
	scanf(" %i", &nuevaSucursal.id);
	printf("• Nombre: ");
	cleanBuffer();
	gets(nuevaSucursal.nombre);
	printf("• Ubicacion: ");
	gets(nuevaSucursal.ubicacion);
	system(CLEAR);
	printf("^_^ - [Vamos a cargar las peliculas de la sucursal]\n");
	mostrarSucursal(nuevaSucursal);
	cargarCartelera(&nuevaSucursal);

	return nuevaSucursal;
}
void cargarCartelera(CineSucursal *nuevaSucursal)
{
	char seguirCargando = 's';
	while (seguirCargando != 'n')
	{
		if (nuevaSucursal->cartelerasCargadas < MAX_PELICULAS)
		{
			nuevaSucursal->cartelera[nuevaSucursal->cartelerasCargadas] = cargarPeliculaM();
			nuevaSucursal->cartelerasCargadas++;
		}
		else
		{
			printf("No se pueden agregar más películas a la cartelera.\n");
		}
		// SALIR DEL WHILE
		printf("Seguir cargando Peliculas? (s/n): ");
		scanf(" %c", &seguirCargando);
		cleanBuffer();
	}
}
void cargarSucursales(CineSucursales *sucursales)
{
	char seguirCargando = 's';
	while (seguirCargando != 'n' && sucursales->sucursalesCargadas < MAX_SUCURSALES)
	{
		int index = sucursales->sucursalesCargadas;
		printf("^_^ - [Vamos a cargar una sucursal de Cine]\n");
		sucursales->sucursales[index] = cargarSucursalM();
		index++; // Incrementar el contador de sucursales cargadas
		sucursales->sucursalesCargadas = index;
		mostrarSucursal(*sucursales->sucursales);
		// SALIR DEL WHILE
		printf("\n> Cargar otra sucursal? (s/n): ");
		scanf(" %c", &seguirCargando);
		cleanBuffer();
		system(CLEAR);
	}
}
void mostrarPelicula(Pelicula pelicula)
{
	printf("\n| NOMBRE: %s | GENERO: %s | DURACION: %.2f |", pelicula.nombre, pelicula.genero, pelicula.duracion);
}
void mostrarCartelera(Pelicula peliculas[], int max)
{
	for (int i = 0; i < max; i++)
	{
		mostrarPelicula(peliculas[i]);
	}
}
void mostrarDATA(CineSucursales data)
{
	for (int i = 0; i < data.sucursalesCargadas; i++)
	{
		printf("===============");
		mostrarSucursal(data.sucursales[i]);
		mostrarCartelera(data.sucursales[i].cartelera, data.sucursales[i].cartelerasCargadas);
		printf("===============");
	}
}
