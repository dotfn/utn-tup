#include <stdio.h>
#include <stdlib.h>

void crearMenu(int inicio, int fin){
    for(inicio; inicio <= fin; inicio++){
        printf(" - Ejercicio n. %i\n", inicio);
    }
}
float calcularInteres(float capitalInicial){
    return capitalInicial * 0.02;
}
int main()
{
    int opcion;
    char corte = 's';
    while(corte == 's'){
        printf("TRABAJO PRACTICO N. 0 - INTRODUCCION A LA PROGRAMACION EN C\n");
        printf("A) PROBLEMAS SECUENCIALES\n");
        crearMenu(1,3);
        printf("B) PROBLEMAS CONDICIIONES SELECTIVOS SIMPLES\n");
        crearMenu(4,8);
        printf("C) PROBLEMAS CONDICIONES SELECTIVOS COMPUESTOS\n");
        crearMenu(9,10);
        printf("D) PROBLEMAS CON REPETICIONES\n");
        crearMenu(11,16);
        printf("Seleciones un ejercicio: ");
        scanf("%i", &opcion);
        system("cls");
        switch(opcion){
            case 1:{
                float capitalInicial;
                float interesObtenido;

                printf("Una persona va a invertir su capital en un banco y desea saber cuánto dinero ganará después de un mes si el banco paga el 2% mensual.\n");
                printf("Ingrese el capital inicial:");
                scanf("%f",  &capitalInicial);

                interesObtenido = calcularInteres(capitalInicial);

                printf("- Su capital inicial: %.2f\n", capitalInicial);
                printf("- El 2 por ciento de ganancia: %.2f\n", calcularInteres(capitalInicial) );
                printf("- Su capital final sera: %.2f\n", interesObtenido + capitalInicial);
                system("pause");
                system("cls");
                break;
            }
            case 2:{
                printf("Una tienda ofrece un descuento del 15% sobre el total de la compra y un cliente desea saber cuánto deberá pagar finalmente por su compra.\n");

                system("pause");
                system("cls");
                break;
            }
            case 3:{
                printf("Un maestro desea saber qué porcentaje de hombres y de mujeres hay en un grupo de estudiantes.\n");

                system("pause");
                system("cls");
                break;
            }
            case 4:{
                printf("Determinar si un estudiante aprueba o reprueba un curso, sabiendo que aprobará si su promedio de tres calificaciones es mayor o igual a 7. Caso contrario reprueba.\n");
                system("pause");
                system("cls");
                break;
            }
            case 5:{
                printf("En un almacén se hace un 20% de descuento a los clientes cuya compra supere los $5.000. Se desea saber cuál será la cantidad que pagará una persona por su compra.\n");
                system("pause");
                system("cls");
                break;
            }
            case 6:{
                printf("Un obrero necesita calcular su salario semanal, el cual se obtiene de la siguiente manera: si trabaja 40 horas o menos se le paga $300 por hora, si trabaja más de 40 horas se le paga $300 por cada una de las primeras 40 horas y $400 por cada hora extra.\n");
                system("pause");
                system("cls");
                break;
            }
            case 7:{
                printf("Desarrolle un algoritmo que lea dos números y los imprima en forma ascendente.\n");
                system("pause");
                system("cls");
                break;
            }
            case 8:{
                printf("Hacer un algoritmo que calcule el total a pagar por la compra de camisas. Si se compran tres camisas o más se aplica un descuento del 20%% sobre el total de la compra, y si son menos de tres camisas un descuento del 10%%.\n");
                system("pause");
                system("cls");
                break;
            }
            case 9:{
                printf("Leer 2 números. Si son iguales, multiplicarlos, si el primero es mayor que el segundo, restarlos, y si no, sumarlos.\n");
                system("pause");
                system("cls");
                break;
            }
            case 10:{
                printf("Leer tres números diferentes e imprimir el mayor de ellos.\n");
                system("pause");
                system("cls");
                break;
            }
            case 11:{
                printf("Calcular el promedio de un estudiante que tiene 7 calificaciones en la materia Programación A.\n");
                system("pause");
                system("cls");
                break;
            }
            case 12:{
                printf("Leer 10 números y obtener su cubo y su cuarta.\n");
                system("pause");
                system("cls");
                break;
            }
            case 13:{
                printf("Leer 10 números e imprimir solamente los positivos.\n");
                system("pause");
                system("cls");
                break;
            }
            case 14:{
                printf("Leer 15 números, convertirlos en positivos e imprimirlos.\n");
                system("pause");
                system("cls");
                break;
            }
            case 15:{
                printf("Suponga que se tiene un conjunto de calificaciones de un grupo de 40 estudiantes. Realizar un algoritmo para calcular la calificación promedio y la calificación más baja de todo el grupo.\n");
                system("pause");
                system("cls");
                break;
            }
            case 16:{
                printf("Calcular e imprimir la tabla de multiplicar de un número cualquiera. Imprimir el multiplicando, el multiplicador y el producto.\n");
                system("pause");
                system("cls");
                break;
            }
            default:{
                printf("Opción no válida.\n");
                system("pause");
                system("cls");
                break;
            }
        }
        printf("Desea probar otro ejercicio? (s/n)\n");
        fflush(stdin);
        scanf("%c", &corte);
        system("cls");
    }
    return 0;
}
