#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "utils.h"	  // cleanBuffer alternativa multisistema a fflush(stdin)
#include "platform.h" // Detecta Win/Linux
#define MAX_ALUMNOS 10
typedef struct
{
	int matricula;
	char nombre[30];
	char genero; // m, f, o
} StAlumno;

/// 1 - Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
StAlumno cargarAlumno()
{
	StAlumno alumno;

	printf("\nIngrese datos del alumno.\n");

	printf("Ingrese matrícula: ");
	scanf("%i", &alumno.matricula);

	printf("Ingrese nombre: ");
	cleanBuffer();
	gets(alumno.nombre);
	char temp;
	do
	{
		printf("Ingrese género (m, f, o): ");
		scanf(" %c", &temp);
		cleanBuffer();
		if (temp == 'm' || temp == 'f' || temp == 'o')
		{
			alumno.genero = temp;
			break; // Salir del bucle si el género es válido
		}
		else
		{
			printf("Género no válido. ");
		}
	} while (1); // Bucle hasta que se ingrese un género válido

	return alumno;
}
void cargarAlumnos(StAlumno alumnos[], int *alumnosCargados)
{
	char seguirCargando = 's';

	while (seguirCargando != 'n' && *alumnosCargados < MAX_ALUMNOS)
	{
		alumnos[*alumnosCargados] = cargarAlumno(); // Cargar un alumno
		(*alumnosCargados)++;

		printf("¿Seguir cargando? (s/n): ");
		scanf(" %c", &seguirCargando);
		cleanBuffer();
	}
}

// funcion 2. mostrar
void mostrarAlumno(StAlumno alumno)
{
	printf("\nMatricula: %i | Nombre: %s | Genero: %c ", alumno.matricula, alumno.nombre, alumno.genero);
}
void mostrarListaAlumnos(StAlumno alumnos[], int alumnosCargados)
{
	printf("\n -- LISTADO DE ALUMNOS --\n");

	for (int i = 0; i < alumnosCargados; i++)
	{
		StAlumno alumno = alumnos[i];
		mostrarAlumno(alumno);
	}
}

/// 3
int buscarMatricula(StAlumno alumnos[], int alumnosCargados, int target)
{
	for (int index = 0; index < alumnosCargados; index++)
	{
		if (alumnos[index].matricula == target)
		{
			return index;
		}
	}
	return -1;
}

void mostrarAlumnosPorMatricula(StAlumno alumnos[], int alumnosCargados)
{
	int matricula;
	printf("\nIngrese matricula a buscar: ");
	scanf("%i", &matricula);
	int alumnoIndex = buscarMatricula(alumnos, alumnosCargados, matricula);
	if (alumnoIndex >= 0)
	{
		mostrarAlumno(alumnos[alumnoIndex]);
	}
	else
	{
		printf("No se encontro el Alumno.\n");
	}
}
/// 4
/// LO DIFERENTE ESTA EN COMO BUSCAMOS EL MENOR ELEMETO
int buscarPosMenor(StAlumno arr[], int inicio, int validos)
{
	int posMenor = inicio;
	for (int i = inicio + 1; i < validos; i++)
	{
		if (arr[i].matricula < arr[posMenor].matricula)
		{
			posMenor = i;
		}
	}
	return posMenor;
}

void intercambioAlumnos(StAlumno *a, StAlumno *b)
{
	StAlumno aux = *a;
	*a = *b;
	*b = aux;
}

void ordenarSeleccionAlumnos(StAlumno arr[], int validos)
{
	int i, posMenor;
	for (i = 0; i < validos - 1; i++)
	{
		posMenor = buscarPosMenor(arr, i, validos);
		if (posMenor != i)
		{
			intercambioAlumnos(&arr[i], &arr[posMenor]);
		}
	}
}
/// 5
void mostrarAlumnosPorGenero(StAlumno alumnos[], int alumnosCargados)
{
	printf("Mostrar Alumnos por Genero");
	char temp;
	do
	{
		printf("\nIngrese género (m, f, o): ");
		scanf(" %c", &temp); // Espacio antes de %c para ignorar caracteres de nueva línea
		cleanBuffer();
		if (temp == 'm' || temp == 'f' || temp == 'o')
		{
			break; // Salir del bucle si el género es válido
		}
		else
		{
			printf("\nGénero no válido. \n");
		}
	} while (1); // Bucle hasta que se ingrese un género válido

	for (int i = 0; i < alumnosCargados; i++)
	{
		if (alumnos[i].genero == temp)
		{
			mostrarAlumno(alumnos[i]);
		}
	}
}
/// 6
void insertarAlumnoOrdenadoPorMatricula(StAlumno arr[], int *validos, StAlumno nuevo)
{
	int i = *validos - 1;
	if (*validos >= MAX_ALUMNOS)
	{
		printf("No se pueden cargar mas alumnos :/\n");
		return;
	}
	// Desplazamos hacia la derecha para hacer lugar
	while (i >= 0 && arr[i].matricula > nuevo.matricula)
	{
		arr[i + 1] = arr[i];
		i--;
	}

	// Insertamos el nuevo alumno en la posición correcta
	arr[i + 1] = nuevo;
	(*validos)++;
}
// 7
void insertarOrdenadoAlumno(StAlumno arr[], int *validos, StAlumno nuevo)
{
	int i = *validos - 1;

	// Desplazamos hacia la derecha para hacer lugar
	while (i >= 0 && arr[i].matricula > nuevo.matricula)
	{
		arr[i + 1] = arr[i];
		i--;
	}

	// Insertamos el nuevo alumno en la posición correcta
	arr[i + 1] = nuevo;
	(*validos)++;
}
void showTools()
{
	printf("1 - Mostrar lista de alumnos cargada\n");					// 2
	printf("2 - Mostrar dato de un alumno seguin su Matricula\n");		// 3
	printf("3 - ORDENAR (Seleccion) lista de alumnos por Matricula\n"); // 4
	printf("4 - Mostrar datos segun su genero\n");						// 5
	printf("5 - INSERTAR ORDENADO por matricula\n");					// 6
	printf("6 - ORDENAR (Seleccion) lista de alumnos por Nombre\n");	// 7
	printf("7 - Contar alumnos por genero\n");
}
int main()
{
	StAlumno alumnos[MAX_ALUMNOS];
	int alumnosCargados = 0;
	char volverAlInicio = 's';
	while (volverAlInicio != 'n')
	{
		int opcion;
		printf("Vamos a cargar alumnos a la lista.");
		cargarAlumnos(alumnos, &alumnosCargados);
		system(CLEAR);
		showTools();
		printf("Seleccione una opcion: ");
		scanf("%i", &opcion);
		system(CLEAR);
		switch (opcion)
		{
		case 1:
			mostrarListaAlumnos(alumnos, alumnosCargados);
			break;
		case 2:
			mostrarAlumnosPorMatricula(alumnos, alumnosCargados);
			break;
		case 3:
			ordenarSeleccionAlumnos(alumnos, alumnosCargados);
			printf("Alumnos Ordenados por Seleccion");
			mostrarListaAlumnos(alumnos, alumnosCargados);
			break;
		case 4:
			mostrarAlumnosPorGenero(alumnos, alumnosCargados);
			break;
		case 5:
		{
			printf("Vamos a cargar un alumno en Orden por matricula");
			StAlumno nuevoAlumno = cargarAlumno();
			insertarAlumnoOrdenadoPorMatricula(alumnos, &alumnosCargados, nuevoAlumno);
		}
		}
		/// Condicion para salir del while.
		printf("\nVolver al inicio? (s/n): ");
		scanf("%c", &volverAlInicio);
		cleanBuffer();
		system(CLEAR);
	}
	return 0;
}