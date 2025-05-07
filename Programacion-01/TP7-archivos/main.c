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
} Student;

// Agrega un alumno al final del archivo
void addStudent(char fileName[], Student student)
{
	FILE *pFile = fopen(fileName, "ab");
	if (pFile != NULL)
	{
		fwrite(&student, sizeof(Student), 1, pFile);
		fclose(pFile);
	}
	else
	{
		printf("Error al abrir el archivo para agregar.\n");
	}
}

// Cuenta registros
int contarRegistros(char fileName[])
{
	FILE *pFile = fopen(fileName, "rb");
	int cantidad = 0;
	if (pFile != NULL)
	{
		fseek(pFile, 0, SEEK_END);
		long tam = ftell(pFile);
		cantidad = tam / sizeof(Student);
		fclose(pFile);
	}
	else
	{
		printf("No se pudo abrir el archivo para contar.\n");
	}
	return cantidad;
}

// Carga un alumno desde consola
Student getStudentInput()
{
	Student student;
	printf("Ingrese legajo: ");
	scanf("%d", &student.legajo);
	// fflush(stdin);
	printf("Ingrese nombre y apellido: ");
	cleanBuffer();
	gets(student.fullname);
	printf("Ingrese edad: ");
	scanf("%d", &student.edad);

	printf("Ingrese año que cursa: ");
	scanf("%d", &student.anio);

	printf("\n");
	return student;
}

// Carga el archivo con 5 alumnos desde consola si no existe
void initializeFile(char fileName[])
{
	FILE *pFile = fopen(fileName, "rb");
	if (pFile != NULL)
	{
		printf("El archivo ya existe. No se cargan datos.\n");
		fclose(pFile);
		return;
	}

	pFile = fopen(fileName, "wb");
	if (pFile == NULL)
	{
		printf("Error al crear el archivo.\n");
		return;
	}

	for (int i = 0; i < 5; i++)
	{
		printf("Alumno #%d:\n", i + 1);
		Student student = getStudentInput();
		fwrite(&student, sizeof(Student), 1, pFile);
	}

	fclose(pFile);
	printf("Archivo creado y cargado con 5 alumnos ingresados por el usuario.\n");
}

// Muestra alumno individual (modular)
void showStudent(Student student)
{
	printf("Legajo: %d\nNombre: %s\nEdad: %d\nAnio: %d\n\n",
		   student.legajo,
		   student.fullname,
		   student.edad,
		   student.anio);
}

// Muestra el archivo usando función modular
void showFile(char fileName[])
{
	FILE *pFile = fopen(fileName, "rb");
	Student student;
	if (pFile != NULL)
	{
		while (fread(&student, sizeof(Student), 1, pFile))
		{
			showStudent(student);
		}
		fclose(pFile);
	}
	else
	{
		printf("No se pudo abrir el archivo para lectura.\n");
	}
}

int main()
{

	initializeFile(FILE_NAME);
	showFile(FILE_NAME);

	printf("Cantidad de registros: %d\n", contarRegistros(FILE_NAME));
	system(PAUSE);
	system(CLEAR);
	printf("\n--- Agregar un nuevo alumno al final ---\n");
	Student newStudent = getStudentInput();
	addStudent(FILE_NAME, newStudent);
	system(PAUSE);
	system(CLEAR);
	printf("\n--- Archivo después de agregar ---\n");
	showFile(FILE_NAME);

	return 0;
}
