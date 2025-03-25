#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
#ifdef _WIN32
#define PAUSE "pause"
#else
#define PAUSE "read -p 'Presione Enter para continuar...' var"
#endif

void limpiarBufferEntrada()
{
	int c;
	while ((c = getchar()) != '\n' && c != EOF)
		;
}

int numeroRandom(int fin)
{
	return rand() % fin + 1;
}

float generarNumeroRandomFloat(float min, float max)
{
	float random = ((float)rand() / RAND_MAX);
	return min + random * (max - min);
}

void mostrarMenu(int cantidad)
{
	printf("Ejercicios con Arreglos: \n");
	for (int i = 0; i < cantidad; i++)
	{
		printf("Ejercicio n. %i.\n", i + 1);
	}
}

int cargarArregloUsuario(int miArreglo[], int dimension)
{
	int dato;
	int largo = 0;
	char condicional = 's';
	while (condicional != 'n' && largo <= dimension)
	{
		printf("\n*Ingrese un numero a cargar en el arreglo: ");
		scanf("%i", &dato);
		miArreglo[largo] = dato;
		largo++;
		limpiarBufferEntrada();
		printf("*Cargar otro? (s/n): ");
		scanf("%c", &condicional);
	}
	return largo;
}

void imprimirArreglo(int miArreglo[], int largo)
{
	printf("\n^-^ -[El arreglo contiene:] \n");
	for (int i = 0; i < largo; i++)
	{
		if (i < 10)
		{
			printf("      index: 0%i ---> valor: %i \n", i, miArreglo[i]);
		}
		else
		{
			printf("      index: %i ---> valor: %i \n", i, miArreglo[i]);
		}
	}
	printf("\n");
}
void imprimirFLoatArreglo(float miArreglo[], int largo)
{
	printf("\n^-^ -[El arreglo contiene:] \n");
	for (int i = 0; i < largo; i++)
	{
		if (i < 10)
		{
			printf("      index: 0%i ---> valor: %.2f \n", i, miArreglo[i]);
		}
		else
		{
			printf("      index: %i ---> valor: %.2f \n", i, miArreglo[i]);
		}
	}
	printf("\n");
}
void crearRandomArray(int miArray[], int *lenght)
{
	(*lenght) = numeroRandom(*lenght - 1);
	printf("^_^' -[Solo cargue %i (RANDOM) elementos validos]\n", *lenght);
	for (int i = 0; i <= *lenght; i++)
	{
		miArray[i] = numeroRandom(10);
	}
}

void crearRandomFloatArray(float miArray[], int *lenght)
{
	(*lenght) = numeroRandom(*lenght - 1);
	printf("^_^' -[Solo cargue %i (RANDOM) elementos validos]\n", *lenght);
	for (int i = 0; i <= *lenght; i++)
	{
		miArray[i] = generarNumeroRandomFloat(0.01, 0.1);
	}
}

int sumarArray(int miArray[], int lenght)
{
	int suma = 0;
	for (int i = 0; i < lenght; i++)
	{
		suma += miArray[i];
	}
	return suma;
}

float sumarFloatArray(float miArray[], int lenght)
{
	float suma = 0;
	for (int i = 0; i < lenght; i++)
	{
		suma += miArray[i];
	}
	return suma;
}
void arrayToPila(int myArray[], int validos, Pila *myPila)
{
	for (int i = 0; i < validos; i++)
	{
		apilar(myPila, myArray[i]);
	}
}

/// Resolucion Ejercicios.
void ejercicio1()
{
	printf("Ejercicio 1\n-Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo (o pueden utilizar como puntero válidos). \n");
	int dimension = 99;
	int miArreglo[dimension];
	int largo = cargarArregloUsuario(miArreglo, dimension);
	printf("\n\n^-^ -[La cantidad de elementos validos es: %i]", largo);
	printf("\n^-^ -[Dimension total del arreglo es: %i] \n\n", dimension);
	imprimirArreglo(miArreglo, largo);
}

void ejercicio2()
{
	printf("Ejercicio 2\n-Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y los muestre por pantalla. \n");
	printf("\n*Ingrese el largo maximo que desea que tenga el arreglo: ");
	int largo;
	scanf("%i", &largo);
	int miArreglo[largo];
	crearRandomArray(miArreglo, &largo);

	imprimirArreglo(miArreglo, largo);
}

void ejercicio3()
{
	printf("Ejercicio 3\n-Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule la suma de sus elementos.");
	printf("\n\n*Ingrese el largo maximo que desea que tenga el arreglo: ");
	int maxLargo;
	scanf("%i", &maxLargo);
	int miArreglo[maxLargo];
	crearRandomArray(miArreglo, &maxLargo);

	imprimirArreglo(miArreglo, maxLargo);
	int suma = sumarArray(miArreglo, maxLargo);
	printf("^-^ -[La suma de los valores del array es: %i]\n\n", suma);
}

void ejercicio4()
{
	printf("Ejercicio 4\n-Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.\n\n");
	Pila myPila;
	int validos = numeroRandom(8);
	int myArray[validos];
	inicpila(&myPila);
	printf("=_=! -[La dimension de la pila sera: %i]\n\n", validos);
	crearRandomArray(myArray, &validos);
	imprimirArreglo(myArray, validos);
	arrayToPila(myArray, validos, &myPila);
	printf("¨-¨ -{LA PILA +/-}");
	mostrar(&myPila);
}

void ejercicio5()
{
	printf("Ejercicio 5\n-Realizar una función que sume los elementos de un arreglo de números reales (float) de dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este tipo de dato asociado al arreglo)\n\n");
	int dimension = 100;
	float myArray[dimension];
	printf("@_@  -[La dimension total del arreglo es: %i]\n", dimension);
	crearRandomFloatArray(myArray, &dimension);
	imprimirFLoatArreglo(myArray, dimension);
	float suma = sumarFloatArray(myArray, dimension);
	printf("^-^ -[La suma del valor de los elementos validos es: %f]\n\n", suma);
}

void ejercicio6()
{
	printf("Ejercicio 6\n Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.\n");
}

void ejercicio7()
{
	printf("Ejercicio 7\n Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.\n");
}

void ejercicio8()
{
	printf("Ejercicio 8\n Realizar una función que obtenga el máximo carácter de un arreglo dado.\n");
}

void ejercicio9()
{
	printf("Ejercicio 9\n Realizar una función que determine si un arreglo es capicúa.\n");
}

void ejercicio10()
{
	printf("Ejercicio 10\n Realizar una función que invierta los elementos de un arreglo. (sin utilizar un arreglo auxiliar)\n");
}

void ejercicio11()
{
	printf("Ejercicio 11\n Ordenar un arreglo según los siguientes métodos: Selección.\n");
}

void ejercicio12()
{
	printf("Ejercicio 12\n Ordenar un arreglo según los siguientes métodos: Inserción.\n");
}

void ejercicio13()
{
	printf("Ejercicio 13\n Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de los dos primeros intercalados, de manera que quede un arreglo también ordenado alfabéticamente.\n");
}

void ejercicio14()
{
	printf("Ejercicio 14\n Dado el vector {1,5,6,7,8} escribir un programa que genere otro vector con la suma del contenido de todos los elementos anteriores al índice actual: {1,6,12,19,27}.\n");
}

int main()
{
	srand(time(NULL));
	char seguir = 's';
	int opcion = 0;
	while (seguir != 'n')
	{
		mostrarMenu(14);
		printf("Ingrese el numero de ejercicio: ");
		scanf("%i", &opcion);
		system(CLEAR);

		switch (opcion)
		{
		case 1:
			ejercicio1();
			system(PAUSE);
			break;
		case 2:
			ejercicio2();
			system(PAUSE);
			break;
		case 3:
			ejercicio3();
			system(PAUSE);
			break;
		case 4:
			ejercicio4();
			system(PAUSE);
			break;
		case 5:
			ejercicio5();
			system(PAUSE);
			break;
		case 6:
			ejercicio6();
			system(PAUSE);
			break;
		case 7:
			ejercicio7();
			system(PAUSE);
			break;
		case 8:
			ejercicio8();
			system(PAUSE);
			break;
		case 9:
			ejercicio9();
			system(PAUSE);
			break;
		case 10:
			ejercicio10();
			system(PAUSE);
			break;
		case 11:
			ejercicio11();
			system(PAUSE);
			break;
		case 12:
			ejercicio12();
			system(PAUSE);
			break;
		case 13:
			ejercicio13();
			system(PAUSE);
			break;
		case 14:
			ejercicio14();
			system(PAUSE);
			break;
		default:
			printf("(*_*) Opción no válida. Por favor, elige una opción del 1 al 14.\n");
			system(PAUSE);
			break;
		}

		printf("\n(^_^)* ?");
		printf("\nDesea probar otro ejercicio? (s/n) ");
		limpiarBufferEntrada();
		scanf("%c", &seguir);
		system(CLEAR);
	}

	return 0;
}
