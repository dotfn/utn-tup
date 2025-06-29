#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "platform.h"
/// COLORS
#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

/// UTILS -
float calPercentage(float total, float percentage)
{
	return (total * percentage) / (float)100;
}
/// A) PROBLEMAS SECUENCIALES -
void case1()
{
	// Una persona va a invertir su capital en un banco y desea saber cuánto dinero ganará después de un mes si el banco paga el 2% mensual.
	float capitalInicial;
	float interesObtenido;
	printf(GREEN "(^_^) " RESET "-> Ingrese el capital inicial: ");
	scanf(" %f", &capitalInicial);

	interesObtenido = calPercentage(capitalInicial, 2);
	printf("\n- RESUMEN-------------------\n");
	printf("- Capital inicial:----$%.2f\n", capitalInicial);
	printf("- El 2%% de ganancia:--$%.2f\n", interesObtenido);
	printf("- Capital final:------$%.2f", interesObtenido + capitalInicial);
}

void case2()
{
	// Una tienda ofrece un descuento del 15% sobre el total de la compra y un cliente desea saber cuánto deberá pagar finalmente por su compra.
	float precioSinDescuento;
	int descuento = 15;
	printf(GREEN "(^_^)" RESET " -> Ingrese el monto de su compra: ");
	scanf(" %f", &precioSinDescuento);
	float precioConDescuento = precioSinDescuento - calPercentage(precioSinDescuento, descuento);
	printf("\n- RESUMEN--------------------------------\n");
	printf("- Precio sin descuento:----------$%.2f\n", precioSinDescuento);
	printf("- Precio con descuento (-%i%%):---$%.2f", descuento, precioConDescuento);
}

void case3()
{
	// Un maestro desea saber qué porcentaje de hombres y de mujeres hay en un grupo de estudiantes.
	int mujeres;
	int hombres;
	int total;
	printf(GREEN "(^_^) ->\n" RESET);
	printf("• Ingrese total de estudiantes" MAGENTA " mujeres: " RESET);
	scanf(" %i", &mujeres);
	printf("• Ingrese total  de estudiantes" MAGENTA " hombres: " RESET);
	scanf(" %i", &hombres);
	total = mujeres + hombres;

	mujeres = mujeres * 100 / total;
	hombres = hombres * 100 / total;

	printf("\n- Resultado:====================== \n");
	printf("- Total de Estudiantes:---- %i \n", total);
	printf("- mujeres:----------------- %i%% \n", mujeres);
	printf("- homres:------------------ %i%%", hombres);
}

//// B) PROBLEMAS CONDICIONALES SELECTIVOS SIMPLES
void case4()
{
	// Determinar si un estudiante aprueba o reprueba un curso, sabiendo que aprobará si su promedio de tres calificaciones es mayor o igual a 7. Caso contrario reprueba.
	float grade1, grade2, grade3, average;

	printf(GREEN "(^_^)" RESET " -{ Ingresa las calificaciones de tus estudiantes! }\n");
	printf("- Calificaciones (ej: 2 6.3 9) : ");

	scanf("%f %f %f", &grade1, &grade2, &grade3);

	average = (grade1 + grade2 + grade3) / 3;

	if (average >= 7)
	{
		printf(GREEN "\n(^-^)" RESET " Aprovado - Promedio: " YELLOW "%.2f " RESET, average);
	}
	else
	{
		printf(RED "\n(x_x)" RESET " Desaprovado - Promedio: " YELLOW "%.2f " RESET, average);
	}
}

void case5()
{
	// 5. En un almacén se hace un 20% de descuento a los clientes cuya compra supere los $5.000. Se desea saber cuál será la cantidad que pagará una persona por su compra.
	float compra = 1;
	printf(YELLOW "\nIngrese -1 para salir \n\n" RESET);
	do
	{

		printf(GREEN "(^_^)" RESET " -{ Ingrese el valor de la comprar }\n\n");
		printf("- Compra: $");
		scanf(" %f", &compra);
		if (compra != -1)
		{
			if (compra > 5000)
			{
				printf("Aplica: " GREEN "[-20% OFF] \n" RESET);
				compra = compra - calPercentage(compra, 20);
			}

			printf("Total: " GREEN "$%.2f\n\n" RESET, compra);
		}
	} while (compra != -1);
}

void case6()
{
	/// 6. Un obrero necesita calcular su salario semanal, el cual se obtiene de la siguiente manera:
	/// si trabaja 40 horas o menos se le paga $300 por hora,
	/// si trabaja más de 40 horas se le paga $300 por cada una de las primeras 40 horas y $400 por cada hora extra.
	int horas;
	int hsBase = 40;
	int salarioTotal;
	int salarioBase = 300;
	int salarioExtra = 400;
	printf(GREEN "(^_^)" RESET "-{ Ingrese las horas trabajadas }\n");
	printf("- Horas: ");
	scanf(" %i", &horas);
	printf("\n- NOMINA----------------\n");
	if (horas > hsBase)
	{
		int hsExtra = horas - hsBase;
		salarioBase = hsBase * salarioBase;
		salarioExtra = hsExtra * salarioExtra;
		salarioTotal = salarioBase + salarioExtra;
		printf("- Salirio Base: $%i\n", salarioBase);
		printf("- Salario Extra: $%i\n", salarioExtra);
	}
	else
	{

		salarioTotal = salarioBase * horas;
	}
	printf("- Salario TOTAL: $%i", salarioTotal);
}

void case7()
{
	/// Desarrolle un algoritmo que lea dos números y los imprima en forma ascendente.
	int num1, num2;
	printf(GREEN "(^_^)" RESET " -{ Imprimire de forma ascendente cualquier convinacion }\n");
	printf("Ingrese dos numeros (ej- 4 63): ");
	scanf(" %i %i", &num1, &num2);
	if (num1 > num2)
	{
		printf(" %i - %i", num1, num2);
	}
	else
	{
		printf(" %i - %i", num2, num1);
	}
}

void case8()
{
	// 8. Hacer un algoritmo que calcule el total a pagar por la compra de camisas.
	// Si se compran tres camisas o más se aplica un descuento del 20% sobre el total de la compra,
	// y si son menos de tres camisas un descuento del 10%.
	int camisas = 0;
	printf(GREEN "(^_^)" RESET "-{ Vamos a calcular el descuento de las camisas }\n");
	printf("- Cantidad de camisas: ");
	scanf(" %i", &camisas);
	printf("- Aplicar: ");
	if (camisas > 3)
	{
		printf(GREEN "[-20%% OFF]" RESET);
	}
	else
	{
		printf(CYAN "[-10%% OFF]" RESET);
	}
}

/// C) PROBLEMAS CONDICIONALES SELECTIVOS COMPUESTOS
void case9()
{
	int num1, num2;
	/// 9. Leer 2 números.
	// Si son iguales, multiplicarlos;
	// si el primero es mayor que el segundo, restarlos; y si no, sumarlos.
	printf(GREEN "(^_^)" RESET " -{ Ingrese dos numeros }\n");
	printf("> (ej - 2 12) : ");
	scanf(" %i %i", &num1, &num2);
	printf(GREEN "\n-Respuesta: \n" RESET);
	if (num1 == num2)
	{
		printf("%i = %i", num1, num2);
		printf("%i * %i = %i", num1, num2, num1 * num2);
	}
	else if (num1 >= num2)
	{
		printf("%i >= %i\n", num1, num2);
		printf("%i - %i = %i", num1, num2, num1 - num2);
	}
	else
	{
		printf("%i <= %i\n", num1, num2);
		printf("%i + %i = %i", num1, num2, num1 + num2);
	}
}
void case10()
{
	/// 10. Leer tres números diferentes e imprimir el mayor de ellos.
	int input = -999;
	int bigger;
	printf(GREEN "(^_^)" RESET " -{ Voy a analizar cual de los 3 numero es mas grande }\n");
	for (int i = 0; i < 3; i++)
	{
		printf("- ingrese %in° > ", i + 1);
		scanf(" %i", &input);
		if (input > bigger)
		{
			bigger = input;
		}
	}
	printf(GREEN "\nRespuesta:\n" RESET);
	printf("El mayor es: %i", bigger);
}

//// D) PROBLEMAS CON REPETICIONES
void case11()
{
	/// 11. Calcular el promedio de un estudiante que tiene 7 calificaciones en la materia Programación A.
	printf(GREEN "(^_^) " RESET "-{ Vamos a calcular el promedio de tu estudiante }\n");
	printf("- Ingrese las calificaciones:\n");
	float input = 0;
	float acc = 0;
	const int MAX_NOTAS = 7;
	for (int i = 0; i < MAX_NOTAS; i++)
	{
		printf("- nota %i n°: ", i + 1);
		scanf(" %f", &input);
		acc += input;
	}
	float average = acc / (float)MAX_NOTAS;
	printf(GREEN "\nRespuesta:\n" RESET);
	printf("Promedio: %.2f", average);
}
void case12()
{
	/// 12. Leer 10 números y obtener su cubo y su cuarta.
	printf(GREEN "(^_^)" RESET " -{ Voy a cacular x² y x⁴ de 10 numeros}\n");
	int const MAX_NUM = 10;
	int input;
	for (int i = 0; i < MAX_NUM; i++)
	{
		printf("> Ingrese #%i: ", i + 1);
		scanf(" %i", &input);
		printf("%i² = %i\n", input, input * input);
		printf("%i⁴ = %i\n", input, input * input * input * input);
	}
}
void case13()
{
	/// 13. Leer 10 números e imprimir solamente los positivos.
	printf(GREEN "(^_^)" RESET " -{ Voy a leer 10 y voy a imprimir solo los positivos }\n");
	printf("Ingrese numero: \n");
	int const MAX_NUM = 10;
	int input;
	for (int i = 0; i < MAX_NUM; i++)
	{
		printf("> #%i: ", i + 1);
		scanf(" %i", &input);
		if (input % 2 == 0)
		{
			printf(GREEN "[ %i - Positivo]\n" RESET, input);
		}
	}
}
void case14()
{
	/// 14. Leer 15 números, convertirlos en positivos e imprimirlos.
	printf("😎 -{ Convertire cualquier numero en positivo }\n");
	int const MAX_NUM = 15;
	int input;
	printf("Ingrese numero: \n");
	for (int i = 0; i < MAX_NUM; i++)
	{
		printf("> #%i: ", i + 1);
		scanf(" %i", &input);
		if (input < 0)
		{
			input = input * -1;
			printf("> " RED "%i" RESET "\n", input);
		}
		else
		{
			printf("> " GREEN "%i" RESET "\n", input);
		}
	}
}
void case15()
{
	/// 15. Suponga que se tiene un conjunto de calificaciones de un grupo de 40 estudiantes.
	/// Realizar un algoritmo para calcular la calificación promedio y la calificación más baja de todo el grupo.
	int const MAX_STU = 10;
	float acc = 0;
	float input = 0;
	float min = 11;
	printf("😎 -{ Te voy a calcular el promedio de tus %i estudiantes y te cuento cual es la calificacion mas baja! }\n", MAX_STU);
	printf("\n- Ingrese las notas: \n");
	for (int i = 0; i < MAX_STU; i++)
	{
		printf("> #%i: ", i + 1);
		scanf(" %f", &input);
		acc = acc + input;
		if (input < min)
		{
			min = input;
		}
	}
	float average = acc / (float)MAX_STU;
	printf(GREEN "\nRespuesta:\n" RESET);
	printf("- Promedio: %.2f\n", average);
	printf("- Calificacion mas" RED " baja:" RESET " %.2f", min);
}
void case16()
{
	/// 16. Calcular e imprimir la tabla de multiplicar de un número cualquiera.
	/// Imprimir el multiplicando, el multiplicador y el producto.
	int input;
	printf("😎 -{ Imprimo la tabla de multiplicar de cualquier numero }\n\n");
	printf("> Ingrese un numero: ");
	scanf(" %i", &input);
	for (int i = 1; i < 10; i++)
	{
		printf(" %i * %i = %i\n", i, input, i * input);
	}
}
void showTP()
{
	printf(YELLOW "TRABAJO PRÁCTICO N° 1: Introducción a la Programación en C\n" RESET "\n");

	printf(BLUE "A) PROBLEMAS SECUENCIALES\n" RESET "\n");
	printf(YELLOW "1. " RESET "Una persona va a invertir su capital en un banco y desea saber cuánto dinero ganará después de un mes si el banco paga el 2%% mensual.\n\n");
	printf(YELLOW "2. " RESET "Una tienda ofrece un descuento del 15%% sobre el total de la compra y un cliente desea saber cuánto deberá pagar finalmente por su compra.\n\n");
	printf(YELLOW "3. " RESET "Un maestro desea saber qué porcentaje de hombres y de mujeres hay en un grupo de estudiantes.\n\n");

	printf(BLUE "B) PROBLEMAS CONDICIONALES SELECTIVOS SIMPLES\n" RESET "\n");
	printf(YELLOW "4. " RESET "Determinar si un estudiante aprueba o reprueba un curso, sabiendo que aprobará si su promedio de tres calificaciones es mayor o igual a 7. Caso contrario reprueba.\n\n");
	printf(YELLOW "5. " RESET "En un almacén se hace un 20%% de descuento a los clientes cuya compra supere los $5.000. Se desea saber cuál será la cantidad que pagará una persona por su compra.\n\n");
	printf(YELLOW "6. " RESET "Un obrero necesita calcular su salario semanal, el cual se obtiene de la siguiente manera: si trabaja 40 horas o menos se le paga $300 por hora, si trabaja más de 40 horas se le paga $300 por cada una de las primeras 40 horas y $400 por cada hora extra.\n\n");
	printf(YELLOW "7. " RESET "Desarrolle un algoritmo que lea dos números y los imprima en forma ascendente.\n\n");
	printf(YELLOW "8. " RESET "Hacer un algoritmo que calcule el total a pagar por la compra de camisas. Si se compran tres camisas o más se aplica un descuento del 20%% sobre el total de la compra, y si son menos de tres camisas un descuento del 10%%.\n\n");

	printf(BLUE "C) PROBLEMAS CONDICIONALES SELECTIVOS COMPUESTOS\n" RESET "\n");
	printf(YELLOW "9. " RESET "Leer 2 números. Si son iguales, multiplicarlos; si el primero es mayor que el segundo, restarlos; y si no, sumarlos.\n\n");
	printf(YELLOW "10. " RESET "Leer tres números diferentes e imprimir el mayor de ellos.\n\n");

	printf(BLUE "D) PROBLEMAS CON REPETICIONES\n" RESET "\n");
	printf(YELLOW "11. " RESET "Calcular el promedio de un estudiante que tiene 7 calificaciones en la materia Programación A.\n\n");
	printf(YELLOW "12. " RESET "Leer 10 números y obtener su cubo y su cuarta.\n\n");
	printf(YELLOW "13. " RESET "Leer 10 números e imprimir solamente los positivos.\n\n");
	printf(YELLOW "14. " RESET "Leer 15 números, convertirlos en positivos e imprimirlos.\n\n");
	printf(YELLOW "15. " RESET "Suponga que se tiene un conjunto de calificaciones de un grupo de 40 estudiantes. Realizar un algoritmo para calcular la calificación promedio y la calificación más baja de todo el grupo.\n\n");
	printf(YELLOW "16. " RESET "Calcular e imprimir la tabla de multiplicar de un número cualquiera. Imprimir el multiplicando, el multiplicador y el producto.\n" RESET);
}

int main()
{

	char volverAlMenu = 's';
	while (volverAlMenu != 'n')
	{
		int opcion;
		showTP();
		printf(RED "\nIngrese el numero de la consigna: " RESET);
		scanf("%i", &opcion);
		system(CLEAR);
		switch (opcion)
		{
		case 1:
			case1();
			break;
		case 2:
			case2();
			break;
		case 3:
			case3();
			break;
		case 4:
			case4();
			break;
		case 5:
			case5();
			break;
		case 6:
			case6();
			break;
		case 7:
			case7();
			break;
		case 8:
			case8();
			break;
		case 9:
			case9();
			break;
		case 10:
			case10();
			break;
		case 11:
			case11();
			break;
		case 12:
			case12();
			break;
		case 13:
			case13();
			break;
		case 14:
			case14();
			break;
		case 15:
			case15();
			break;
		case 16:
			case16();
			break;

		default:
		{
			system(CLEAR);
			printf(RED "\n(X_X) -[Opcion no valida]\n\n" RESET);
			break;
		}
		}
		printf(RED "\n-- END --" RESET);
		printf(YELLOW "\n\nVolver al menu? (s/n) " RESET);
		cleanBuffer();
		scanf("%c", &volverAlMenu);
		system(CLEAR);
	}
	return 0;
}
