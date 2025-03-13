#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crearMenu(){
    printf("TRABAJO PRACTICO N. 1 - FUNCIONES SIN PILAS\n");
    for (int i = 0; i<7; i++){
        printf("Ejercicio n. %i\n", i + 1);
    }
}

int numeroRandom(int fin){
    return rand()%fin;
}
int getNumeroMayor(int num1, int num2, int num3){
    if(num1 > num2 && num1>num3){
        return num1;
    }
    if(num2 > num3 && num2>num3){
        return num2;
    }
    return num3;
}
int getNumeroMenor(int num1, int num2, int num3){
    if(num1 < num2 && num1<num3){
        return num1;
    }
    if(num2 < num3 && num2<num3){
        return num2;
    }
    return num3;
}
int getMayorMenor(int num1, int num2, int num3){
    printf("\nEl mayor es %i \n", getNumeroMayor(num1,num2,num3));
    printf("El menor es %i \n", getNumeroMenor(num1,num2,num3));
}
int sumaMenoresN(int num){
    int acumulador = 0;
    for(int i = 1 ; i < num; i++){
        acumulador += i;
    }
    return acumulador;
}
int mostrarTablaMultiplicar(int num){
    printf("\nLa tabla de multiplicar del %i\n", num);

    for( int i = 1 ; i < num + 1; i++){
        printf("%i x %i ---- %i\n", i, num, num * i);
    }
}
int sumar(int num1, int num2){
    return num1 + num2;
}
int restar(int num1, int num2){
    return num1 - num2;
}
int multiplicar(int num1,int num2){
    return num1 * num2;
}
float dividir(int num1, int num2){
    return (float)num1/(float)num2;
}
int convertirNegativo(int num){
    return num * -1;
}
void mostrarValores( int *num1, int *num2){
    printf("\n primer numero: %i \n segundo numero: %i \n", num1, num2);
}
int main()
{
    char control = 's';
    int opcion = 0;
    srand(time(NULL));
    while(control == 's'){

        crearMenu();
        printf("Seleccione un ejercicio: ");
        fflush(stdin);
        scanf("%i", &opcion);
        system("cls");
        switch(opcion) {
            case 1:{
                printf("Desarrollar una funci�n que devuelva un valor RANDOM en el rango de 0 a 100.\n");
                printf("Numero random : %d \n", numeroRandom(100));
                system("pause");
                system("cls");
                break;
            }
            case 2:{
                int num12, num22, num32;
                printf("Dise�e una funci�n que reciba 3 n�meros enteros y muestre el mayor y el menor.\n");
                printf("Ingrese el primer numero: ");
                scanf("%i", &num12);
                printf("\nIngrese el segundo numero: ");
                scanf("%i", &num22);
                printf("\nIngrese el tercer numero: ");
                scanf("%i", &num32);
                getMayorMenor(num12, num22, num32);
                system("pause");
                system("cls");
                break;
            }
            case 3:{
                int num;
                printf("Dise�e una funci�n que reciba un n�mero entero N y realice la suma de los n�meros enteros positivos menores que N y lo retorne. N es un dato ingresado por el usuario en el main.\n");
                printf("\nIngrese un numero entero positivo: ");
                scanf("%i", &num);
                if(num > 0 ){
                    printf("\nLa suma de los enteros positivos menores que %i es: %i\n",num, sumaMenoresN(num));
                }
                printf("\nEl numero ingresado no es valido\n");
                system("pause");
                system("cls");
                break;
            }
            case 4:{
                int num;
                printf("Desarrollar una funci�n que muestre la tabla de multiplicar de un n�mero entero recibido por par�metro.\n");
                printf("Ingrese un numero entero positivo: ");
                scanf("%i", &num);
                if ( num > 0 ){
                    mostrarTablaMultiplicar(num);
                }
                printf("Numero no valido");
                system("pause");
                system("cls");
                break;
            }
            case 5:{
                int control = 's';
                int opcion;
                int num1, num2;
                printf("Realice una peque�a calculadora, utilizando funciones (una funci�n de suma, una de multiplicaci�n, una de resta, una de divisi�n�).\n");
                while(control == 's'){
                    printf("Seleccione una operacion:\n");
                    printf("1-sumar\n");
                    printf("2-restar\n");
                    printf("3-multiplicar\n");
                    printf("4-dividir\n");
                    scanf("%i", &opcion);
                    system("cls");
                    switch(opcion){
                        case 1: {
                            printf("ingrese el primer numero a sumar: ");
                            scanf("%i", &num1);
                            printf("ingrese el segundo numero: ");
                            scanf("%i", &num2);
                            printf("%i + %i = %i \n", num1, num2, sumar(num1,num2));
                            system("pause");
                            system("cls");
                        }
                        case 2: {
                            printf("ingrese el primer numero a restar: ");
                            scanf("%i", &num1);
                            printf("ingrese el segundo numero: ");
                            scanf("%i", &num2);
                            printf("%i - %i = %i \n", num1, num2, restar(num1,num2));
                            system("pause");
                            system("cls");
                        }
                        case 3: {
                            printf("ingrese el primer numero a multiplicar: ");
                            scanf("%i", &num1);
                            printf("ingrese el segundo numero: ");
                            scanf("%i", &num2);
                            printf("%i * %i = %i \n", num1, num2, multiplicar(num1,num2));
                            system("pause");
                            system("cls");
                        }
                        case 4: {
                            printf("ingrese el primer numero a dividir: ");
                            scanf("%i", &num1);
                            printf("ingrese el segundo numero: ");
                            scanf("%i", &num2);
                            printf("%i / %i = %.2f \n", num1, num2, dividir(num1,num2));
                            system("pause");
                            system("cls");
                        }
                        default:
                            printf("Opcion invalida :(\n");
                    }
                }
                system("pause");
                system("cls");
                break;
            }
            case 6:{
                int num;
                printf("Realizar una funci�n que reciba un n�mero positivo entero por par�metro por referencia, y cambie su signo a negativo.\n");
                printf("Ingrese un numero entero positivo: ");
                scanf("%i", &num);
                if ( num > 0 ){
                    printf("\nEl negativo de %i es : %i \n", num, convertirNegativo(num));
                }
                printf("\n %i que ingresaste ya es negativo :p\n", num);
                system("pause");
                system("cls");
                break;
            }
            case 7:{
                int num1, num2;
                printf("Realizar una funci�n que reciba dos n�meros enteros por par�metro por referencia y cargue sus valores el usuario dentro de la funci�n.\n");
                printf("\n ingrese el primero numero: ");
                scanf("%i", &num1);
                printf("\n ingrese el segundo numero: ");
                scanf("%i", &num2);
                mostrarValores(num1, num2);
                system("pause");
                system("cls");
                break;
            }
            default:
                printf("Opcion incorrecta\n");
                system("pause");
                system("cls");
        }
        printf("Desea probar otro ejercicio? (s/n)\n");
        fflush(stdin);
        scanf("%c", &control);
        system("cls");
    };
    return 0;
}
