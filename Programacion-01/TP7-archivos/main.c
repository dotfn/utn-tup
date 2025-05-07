#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"
#include "utils.h"	  // cleanBuffer alternativa multisistema a fflush(stdin)
#include "platform.h" // Detecta Win/Linux
#define FILE_NAME "alumnos.dat"
#define STRING_SIZE 30
// Typedefs
typedef struct
{
	int legajo;
	char fullname[30];
	int edad;
	int anio; // año que cursa
} stAlumno;

// Agrega un alumno al final del archivo
void agregarAlumnoAlFinal(char nombreArchivo[], stAlumno alumno)
{
	FILE *archivo = fopen(nombreArchivo, "ab");
	if (archivo != NULL)
	{
		fwrite(&alumno, sizeof(stAlumno), 1, archivo);
		fclose(archivo);
	}
	else
	{
		printf("Error al abrir el archivo para agregar.\n");
	}
}

// Muestra el contenido del archivo
void mostrarArchivo(char nombreArchivo[])
{
	FILE *archivo = fopen(nombreArchivo, "rb");
	stAlumno alumno;
	if (archivo != NULL)
	{
		while (fread(&alumno, sizeof(stAlumno), 1, archivo))
		{
			printf("Legajo: %d\nNombre: %s\nEdad: %d\nAnio: %d\n\n",
				   alumno.legajo, alumno.fullname, alumno.edad, alumno.anio);
		}
		fclose(archivo);
	}
	else
	{
		printf("No se pudo abrir el archivo para lectura.\n");
	}
}

// Cuenta registros
int contarRegistros(char nombreArchivo[])
{
	FILE *archivo = fopen(nombreArchivo, "rb");
	int cantidad = 0;
	if (archivo != NULL)
	{
		fseek(archivo, 0, SEEK_END);
		long tam = ftell(archivo);
		cantidad = tam / sizeof(stAlumno);
		fclose(archivo);
	}
	else
	{
		printf("No se pudo abrir el archivo para contar.\n");
	}
	return cantidad;
}

// Carga un alumno desde consola
stAlumno cargarAlumnoPorConsola()
{
	stAlumno alumno;
	printf("Ingrese legajo: ");
	scanf("%d", &alumno.legajo);
	// fflush(stdin);
	printf("Ingrese nombre y apellido: ");
	cleanBuffer();
	gets(alumno.fullname);
	printf("Ingrese edad: ");
	scanf("%d", &alumno.edad);

	printf("Ingrese año que cursa: ");
	scanf("%d", &alumno.anio);

	printf("\n");
	return alumno;
}

// Carga el archivo con 5 alumnos desde consola si no existe
void cargarArchivoInicial(char nombreArchivo[])
{
	FILE *archivo = fopen(nombreArchivo, "rb");
	if (archivo != NULL)
	{
		printf("El archivo ya existe. No se cargan datos.\n");
		fclose(archivo);
		return;
	}

	archivo = fopen(nombreArchivo, "wb");
	if (archivo == NULL)
	{
		printf("Error al crear el archivo.\n");
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("Alumno #%d:\n", i + 1);
		stAlumno alumno = cargarAlumnoPorConsola();
		fwrite(&alumno, sizeof(stAlumno), 1, archivo);
	}

	fclose(archivo);
	printf("Archivo creado y cargado con 5 alumnos ingresados por el usuario.\n");
}

// Muestra alumno individual (modular)
void mostrarAlumno(stAlumno alumno)
{
	printf("Legajo: %d\nNombre: %s\nEdad: %d\nAnio: %d\n\n",
		   alumno.legajo,
		   alumno.fullname,
		   alumno.edad,
		   alumno.anio);
}

// Muestra el archivo usando función modular
void mostrarArchivoModular(char nombreArchivo[])
{
	FILE *archivo = fopen(nombreArchivo, "rb");
	stAlumno alumno;
	if (archivo != NULL)
	{
		while (fread(&alumno, sizeof(stAlumno), 1, archivo))
		{
			mostrarAlumno(alumno);
		}
		fclose(archivo);
	}
	else
	{
		printf("No se pudo abrir el archivo para lectura.\n");
	}
}

int main()
{

	cargarArchivoInicial(FILE_NAME);
	mostrarArchivoModular(FILE_NAME);

	printf("Cantidad de registros: %d\n", contarRegistros(FILE_NAME));

	printf("\n--- Agregar un nuevo alumno al final ---\n");
	stAlumno nuevo = cargarAlumnoPorConsola();
	agregarAlumnoAlFinal(FILE_NAME, nuevo);

	printf("\n--- Archivo después de agregar ---\n");
	mostrarArchivo(FILE_NAME);

	return 0;
}
