#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
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

void mostrarMenu()
{
	printf("Funciones con pila: \n");
	for (int i = 0; i < 10; i++)
	{
		printf("Ejercicio %i.\n", i + 1);
	}
}

Pila crearPilaRandom(int largo)
{
	Pila miPila;
	inicpila(&miPila);
	int numeroR = numeroRandom(largo);
	for (int i = 0; i < largo; i++)
	{
		apilar(&miPila, numeroRandom(largo));
	}
	return miPila;
}

Pila pasarPila(Pila pilaOrigina)
{
	Pila nuevaPila;
	inicpila(&nuevaPila);

	while (!pilavacia(&pilaOrigina))
	{
		apilar(&nuevaPila, desapilar(&pilaOrigina));
	}
	return nuevaPila;
}

Pila PasarPilaMantenerOrden(Pila pilaOriginal)
{
	Pila miPila = pasarPila(pilaOriginal);
	miPila = pasarPila(miPila);
	return miPila;
}

Pila cargarPila(Pila miPila)
{
	char seguir = 's';
	int numero = 0;
	while (seguir == 's')
	{
		printf("\nIngrese el numero a cargar:");
		scanf("%i", &numero);
		apilar(&miPila, numero);
		printf("Desea cargar otro numero? (s/n)");
		limpiarBufferEntrada();
		scanf("%c", &seguir);
	}
	return miPila;
}

int buscarMenorElmento(Pila pilaOriginal)
{
	int menor = 999;
	int aux;
	while (!pilavacia(&pilaOriginal))
	{
		aux = desapilar(&pilaOriginal);
		if (aux <= menor)
		{
			menor = aux;
		}
	}
	return menor;
}

Pila eliminarElemento(Pila pilaOriginal, int elemento)
{
	int flag = 1;
	Pila auxPila;
	inicpila(&auxPila);
	Pila copiOriginal;
	copiOriginal = pasarPila(pilaOriginal);
	while (!pilavacia(&copiOriginal))
	{
		apilar(&auxPila, desapilar(&copiOriginal));
		// flag es para no eliminar solo un elemento
		// en caso de que el elemento es repetido :)
		if (tope(&auxPila) == elemento && flag != 0)
		{
			desapilar(&auxPila);
			flag = 0;
		}
	}
	return auxPila;
}

Pila insertarOrdenado(Pila pilaOrdenada, int numero)
{
	Pila pilaAux;
	inicpila(&pilaAux);

	while (!pilavacia(&pilaOrdenada) && tope(&pilaOrdenada) > numero)
	{
		apilar(&pilaAux, desapilar(&pilaOrdenada));
	}

	apilar(&pilaOrdenada, numero);

	while (!pilavacia(&pilaAux))
	{
		apilar(&pilaOrdenada, desapilar(&pilaAux));
	}

	return pilaOrdenada;
}

int sumarTopeAnterior(Pila miPila, int cantidad)
{
	Pila auxPila;
	inicpila(&auxPila);
	int suma = 0;
	for (int i = 0; i < cantidad; i++)
	{
		suma = suma + tope(&miPila);
		apilar(&auxPila, desapilar(&miPila));
	}
	return suma;
}

Pila ordenarPila(Pila pilaOriginal)
{
	Pila miPilaOrdena;
	inicpila(&miPilaOrdena);
	while (!pilavacia(&pilaOriginal))
	{
		int menor = buscarMenorElmento(pilaOriginal);
		apilar(&miPilaOrdena, menor);
		pilaOriginal = eliminarElemento(pilaOriginal, menor);
	}

	return miPilaOrdena;
}

int sumarValoresPila(Pila miPila)
{
	int suma = 0;
	while (!pilavacia(&miPila))
	{
		suma += desapilar(&miPila);
	}
	return suma;
}

int largoPila(Pila miPila)
{
	int contador = 0;
	while (!pilavacia(&miPila))
	{
		desapilar(&miPila);
		contador++;
	}
	return contador;
}

int transformaPilaDecimal(Pila miPila)
{
	miPila = pasarPila(miPila);
	int mult = 0;
	int suma = 0;
	while (!pilavacia(&miPila))
	{
		int posicion = 1;
		int largo = largoPila(miPila) - 1;
		int tope = desapilar(&miPila);
		for (int i = 0; i < largo; i++)
		{
			posicion = posicion * 10;
		}
		mult = posicion * tope;
		suma = suma + mult;
	}
	return suma;
}

float division(int num, int num2)
{
	return (float)num / (float)num2;
}

float calcularPromedio(Pila miPila)
{
	int sumaTotal = sumarValoresPila(miPila);
	int cantidad = largoPila(miPila);
	return division(sumaTotal, cantidad);
}

void ejercicio1()
{
	printf("Ejercicio 1:\nHacer una funcion que permita ingresar varios elementos a una pila, tanto como quiera el usuario. \n");
	Pila miPilaVacia;
	inicpila(&miPilaVacia);
	Pila miPilaCargada = cargarPila(miPilaVacia);
	mostrar(&miPilaCargada);
}

void ejercicio2()
{
	printf("Ejercicio 2\n Hacer una función que pase todos los elementos de una pila a otra.\n");
	Pila miPila = crearPilaRandom(10);
	Pila nuevaPila = pasarPila(miPila);
	printf("\nPila Original: \n");
	mostrar(&miPila);
	printf("Nueva Pila:\n");
	mostrar(&nuevaPila);
}

void ejercicio3()
{
	printf("Ejercicio 3\n Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.");
	Pila miPila = crearPilaRandom(10);
	Pila nuevaPila = PasarPilaMantenerOrden(miPila);
	printf("Pila Orginal: \n");
	mostrar(&miPila);
	printf("Nueva Pila:\n");
	mostrar(&nuevaPila);
}

void ejercicio4()
{
	printf("Ejercicio 4\nHacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.\n");
	Pila miRandomPila = crearPilaRandom(10);
	int menor = buscarMenorElmento(miRandomPila);
	printf("\nPILA ORIGINAL:");
	mostrar(&miRandomPila);
	printf("\nEl numero menor es: %i\n", menor);
	Pila pilaSinMenorElemento;
	inicpila(&pilaSinMenorElemento);
	pilaSinMenorElemento = eliminarElemento(miRandomPila, menor);
	mostrar(&pilaSinMenorElemento);
}

void ejercicio5()
{
	printf("Ejercicio 5\nHacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 4. (Ordenamiento por selección) ");
	Pila miPila;
	inicpila(&miPila);
	miPila = crearPilaRandom(10);
	printf("\n\nPILA ORIGINAL:");
	mostrar(&miPila);
	printf("PILA ORDENADA");
	miPila = ordenarPila(miPila);
	mostrar(&miPila);
}

void ejercicio6()
{
	printf("Ejercicio 6\nHacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta. ");
	int numero;
	Pila miPila;
	inicpila(&miPila);
	miPila = crearPilaRandom(10);
	miPila = ordenarPila(miPila);

	printf("\nPILA ORIGINAL: \n");
	mostrar(&miPila);

	printf("\nIngrese un numero a apilar: ");
	scanf("%i", &numero);

	miPila = insertarOrdenado(miPila, numero);

	printf("\nNUEVA PILA ORDENADA:\n");
	mostrar(&miPila);
}

void ejercicio7()
{
	printf("Ejercicio 7\nHacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.  (Ordenamiento por inserción)");
	printf("NO ENTENDI LA CONSIGNA :'(");
}

void ejercicio8()
{
	printf("Ejercicio 8\nHacer una función que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma,  sin alterar el contenido de la pila.");
	Pila miRandomPila;
	miRandomPila = crearPilaRandom(10);
	printf("\n\nPILA ORIGINAL:");
	mostrar(&miRandomPila);
	int suma = sumarTopeAnterior(miRandomPila, 2);
	printf("La suma de los elementos tope + anterior =  %i\n\n", suma);
}

void ejercicio9()
{
	printf("Ejercicio 9\n Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula el promedio invoca a las otras 3.");
	Pila miRandomPila;
	miRandomPila = crearPilaRandom(10);
	mostrar(&miRandomPila);

	float promedio = calcularPromedio(miRandomPila);
	int sumaTotal = sumarValoresPila(miRandomPila);
	int largo = largoPila(miRandomPila);
	printf("\nLa suma de todos los valores de la pila es: %i \n", sumaTotal);
	printf("El largo de la pila es: %i\n", largo);
	printf("El promedio de la suma de los elemento de la pila es: %.2f \n\n", promedio);
}

void ejercicio10()
{
	printf("Ejercicio 10:\nHacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal.");
	Pila miRandonPila;
	miRandonPila = crearPilaRandom(9);
	mostrar(&miRandonPila);
	int decimal = transformaPilaDecimal(miRandonPila);
	printf("La pila en decimal es: %i\n\n", decimal);
}

int main()
{
	char seguir = 's';
	int opcion = 0;
	while (seguir == 's')
	{
		mostrarMenu();
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
		case 10:
			ejercicio10();
			system(PAUSE);
		}
		printf("\nDesea probar otro ejercicio? (s/n)");
		limpiarBufferEntrada();
		scanf("%c", &seguir);
		system(CLEAR);
	}

	return 0;
}