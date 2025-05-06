#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "utils.h"	  // cleanBuffer alternativa multisistema a fflush(stdin)
#include "platform.h" // Detecta Win/Linux
#define MAX_STR 50
#define MAX_PELICULAS 10
#define MAX_SUCURSALES 20
/// types
typedef struct
{
	char nombre[MAX_STR];
	char genero[MAX_STR];
	float duracion;
} CinePelicula;

typedef struct
{
	CinePelicula lista[MAX_PELICULAS];
	int length;
} CineCartelera;

typedef struct
{
	int id;
	char nombre[MAX_STR];
	char ubicacion[MAX_STR];
	CineCartelera cartelera;
} CineSucursal;

typedef struct
{
	CineSucursal lista[MAX_SUCURSALES];
	int length;
} CineSucursales;
/// PROTOTIPO
CineSucursal cargarSucursal();
CinePelicula cargarPelicula();
CineCartelera cargarCartelera();
void cargarSucursales(CineSucursales *sucursales);
void mostrarSucursal(CineSucursal sucursal);
/// CARGAR DATOS;
CineSucursal cargarSucursal()
{
	CineSucursal sucursal;
	printf("\n=> Ingrese los siguientes datos de la sucursal:\n");
	printf("ID(numerico): ");
	scanf(" %i", &sucursal.id);
	printf("Nombre: ");
	cleanBuffer();
	gets(sucursal.nombre);
	printf("Ubicacion: ");
	gets(sucursal.ubicacion);
	system(CLEAR);
	mostrarSucursal(sucursal);
	sucursal.cartelera = cargarCartelera();
	// cleanBuffer();
	return sucursal;
}
CinePelicula cargarPelicula()
{
	CinePelicula pelicula;
	printf("\n=> Ingrese los siguientes datos de la pelicula:\n");
	printf("Nombre: ");
	gets(pelicula.nombre);
	printf("Genero: ");
	gets(pelicula.genero);
	printf("Duracion: ");
	scanf(" %f", &pelicula.duracion);
	return pelicula;
}
CineCartelera cargarCartelera()
{
	CineCartelera cartelera;
	cartelera.length = 0;
	char seguirCargando = 's';
	printf("\n Peliculas en cartelera:");
	while (seguirCargando != 'n')
	{
		cartelera.lista[cartelera.length] = cargarPelicula();
		cartelera.length++;
		// SALIR DEL WHILE;
		printf("\nSeguir cargando peliculas? (s/n): ");
		scanf(" %c", &seguirCargando);
		cleanBuffer();
	}

	return cartelera;
}
void cargarSucursales(CineSucursales *sucursales)
{
	char cargarOtraSucursal = 's';
	while (cargarOtraSucursal != 'n')
	{
		sucursales->lista[sucursales->length] = cargarSucursal();
		sucursales->length++;
		// SALIR DEL WHILE;
		printf("\nCargar otra sucursal? (s/n): ");
		scanf(" %c", &cargarOtraSucursal);
		system(CLEAR);
	}
}
/// MOSTRAR DATOS;
void mostrarSucursal(CineSucursal sucursal)
{
	printf("| ID: %i | NOMBRE: %s | UBICACION: %s |", sucursal.id, sucursal.nombre, sucursal.ubicacion);
}
void mostrarPelicula(CinePelicula pelicula)
{
	printf("| NOMBRE: %s | GENERO: %s | DURACION: %.2f |", pelicula.nombre, pelicula.genero, pelicula.duracion);
}
void mostrarSucursales(CineSucursales sucursales)
{
	printf("\n== SUCURSALES ==\n");
	int sucursal = sucursales.length;
	for (int i = 0; i < sucursal; i++)
	{
		mostrarSucursal(sucursales.lista[i]);
		printf("\n");
	}
}
void mostrarCartelera(CineCartelera cartelera)
{
	int pelicula = cartelera.length;
	for (int i = 0; i < pelicula; i++)
	{
		mostrarPelicula(cartelera.lista[i]);
		printf("\n");
	}
}
// OBTENER SUCURSAL 2
CineSucursal getSucursalByID(CineSucursales *sucursales, int id)
{
	CineSucursal sucursal = {-1};
	for (int index = 0; index < sucursales->length; index++)
	{
		if (sucursales->lista[index].id == id)
		{
			return sucursales->lista[index];
		}
	}
	return sucursal;
}
CineCartelera groupByGenero(CineCartelera cartelera, char genero[MAX_STR])
{
	CineCartelera carteleraFiltrada;
	int cantidaDePeliculas = cartelera.length;
	for (int i = 0; i < cantidaDePeliculas; i++)
	{
		if (strcmp(cartelera.lista[i].genero, genero) == 0)
		{
			carteleraFiltrada.lista[i] = cartelera.lista[i];
			carteleraFiltrada.length++;
		}
	}
	return carteleraFiltrada;
}
// ORDENAR
int desplazarMayores(CineSucursales sucursales, int posicicon, int valorActual)
{

	// Desplazamos a la derecha mientras encontremos valores mayores
	while (posicicon >= 0 && sucursales.lista[posicicon].id > valorActual)
	{
		sucursales.lista[posicicon + 1] = sucursales.lista[posicicon];
		posicicon--;
	}

	// Retornamos la posición donde debe insertarse el valor
	return posicicon + 1;
}
void ordenarPorInsercion(CineSucursales *sucursales)
{
	// Comenzamos desde el segundo elemento (índice 1)
	for (int i = 1; i < sucursales->length; i++)
	{
		// Guardamos el valor actual
		int valorActual = sucursales->lista[i].id;

		// Desplazamos los elementos mayores
		int posicionInsercion = desplazarMayores(*sucursales, i - 1, valorActual);

		// Insertamos el valor en su posición correcta
		sucursales->lista[posicionInsercion].id = valorActual;
	}
}
// MENU
void menu(CineSucursales sucursales)
{
	system(CLEAR);
	int option;
	char volverAlMenu = 's';
	while (volverAlMenu != 'n')
	{
		printf("\n === TOOLS: === \n");
		printf("1 - Mostra todas las sucursales \n");
		printf("2 - Buscar sucursal por ID \n");
		printf("3 - Ordenar sucursales por ID\n");
		printf("> Elegir opcion: ");
		scanf(" %i", &option);
		cleanBuffer();
		system(CLEAR);
		switch (option)
		{
		case 1:
		{
			mostrarSucursales(sucursales);
			break;
		}
		case 2:
		{
			int idTarget;
			char generoFilter[MAX_STR];
			printf("\n Ingrese el id de la sucursal que desea buscar: ");
			scanf(" %i", &idTarget);
			cleanBuffer();
			CineSucursal sucursal = getSucursalByID(&sucursales, idTarget);
			if (sucursal.id != -1)
			{
				mostrarSucursal(sucursal);
				printf("\n");
				mostrarCartelera(sucursal.cartelera);
				printf("\nFiltrar por genero: ");
				printf("\n> Ingrese el genero que desea filtrar: ");
				gets(generoFilter);
				mostrarCartelera(groupByGenero(sucursal.cartelera, generoFilter));
			}
			else
			{
				printf("X_X [La sucursal no existe]");
			}
			break;
		}
		case 3:
			ordenarPorInsercion(&sucursales);
			mostrarSucursales(sucursales);
			break;
		case 4:
			int idTarget;
			printf("\nVamos a editar la cartelera.\n");
			mostrarSucursales(sucursales);
			printf("\nIngrese el ID de la sucursal que desea editar: ");
			scanf(" %i", &idTarget);
			for (int i = 0; i < getSucursalByID(&sucursales, idTarget).cartelera.length; i++)
			{
				getSucursalByID(&sucursales, idTarget).cartelera.lista[i].duracion = (float)21.2;
				mostrarPelicula(getSucursalByID(&sucursales, idTarget).cartelera.lista[i]);
			}
			break;
		default:
			printf("Opcion incorrecta :/");
			break;
		}
		/// SALIR DEL MENU;
		printf("\nVolver al menu? (s/n)");
		scanf(" %c", &volverAlMenu);
		system(CLEAR);
	}
}
int main()
{
	CineSucursales empresa;
	empresa.length = 0;
	char volverAlInicio = 's';
	while (volverAlInicio != 'n')
	{
		cargarSucursales(&empresa);
		menu(empresa);
		// SALIR DEL WHILE;
		printf("\nVolver a inicio? (s/n): ");
		scanf(" %c", &volverAlInicio);
		cleanBuffer();
		system(CLEAR);
	}

	return 0;
}