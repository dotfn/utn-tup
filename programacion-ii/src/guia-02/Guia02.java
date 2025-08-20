import java.util.Scanner;
import util.ConsoleUtils;

public class Guia02 {
    public static void main(String[] args) {
        ConsoleUtils.clearConsole();
        Scanner input = new Scanner(System.in);
        int opcion;

        do {
            System.out.println("===== Menú de Ejercicios =====");
            System.out.println("1. Ejercicio 01");
            System.out.println("2. Ejercicio 02");
            System.out.println("3. Ejercicio 03");
            System.out.println("4. Ejercicio 04");
            System.out.println("5. Ejercicio 05");
            System.out.println("6. Ejercicio 06");
            System.out.println("7. Ejercicio 07");
            System.out.println("8. Ejercicio 08");
            System.out.println("9. Ejercicio 09");
            System.out.println("9. Ejercicio 10");
            System.out.println("9. Ejercicio 11");
            System.out.println("9. Ejercicio 12");
            System.out.println("9. Ejercicio 13");
            System.out.println("9. Ejercicio 14");

            System.out.println("0. Salir");
            System.out.print("Seleccione una opción: ");
            opcion = input.nextInt();
            ConsoleUtils.clearConsole();
            switch (opcion) {
                case 1:
                    System.out.println("\n===== Ejercicio 01 =====\n");
                    ejercicio01(input);
                    break;
                case 2:
                    System.out.println("\n===== Ejercicio 02 =====\n");
                    ejercicio02(input);
                    break;
                case 3:
                    System.out.println("\n===== Ejercicio 03 =====\n");
                    ejercicio03(input);
                    break;
                case 4:
                    System.out.println("\n===== Ejercicio 04 =====\n");
                    ejercicio04(input);
                    break;
                case 5:
                    System.out.println("\n===== Ejercicio 05 =====\n");
                    ejercicio05(input);
                    break;
                case 6:
                    System.out.println("\n===== Ejercicio 06 =====\n");
                    ejercicio06(input);
                    break;
                case 7:
                    System.out.println("\n===== Ejercicio 07 =====\n");
                    ejercicio07(input);
                    break;
                case 8:
                    System.out.println("\n===== Ejercicio 08 =====\n");
                    ejercicio08(input);
                    break;
                case 9:
                    System.out.println("\n===== Ejercicio 09 =====\n");
                    ejercicio09(input);
                    break;
                case 10:
                    System.out.println("\n===== Ejercicio 10 =====\n");
                    ejercicio10(input);
                    break;
                case 11:
                    System.out.println("\n===== Ejercicio 11 =====\n");
                    ejercicio11(input);
                    break;
                case 12:
                    System.out.println("\n===== Ejercicio 12 =====\n");
                    ejercicio12(input);
                    break;
                case 13:
                    System.out.println("\n===== Ejercicio 13 =====\n");
                    ejercicio13(input);
                    break;
                case 14:
                    System.out.println("\n===== Ejercicio 14 =====\n");
                    ejercicio14(input);
                    break;
                case 0:
                    System.out.println("Saliendo del programa...");
                    break;
                default:
                    System.out.println("Opción no válida. Intente de nuevo.");
            }
            System.out.println("\n^_^* -{ Volver al menu? } ");
            System.out.println("1. Volver");
            System.out.println("0. Salir");
            System.err.printf("> ");
            opcion = input.nextInt();
            ConsoleUtils.clearConsole();

        } while (opcion != 0);

        input.close();
    }

    public static void ejercicio01(Scanner input) {
        System.out.printf("Ingrese un numero (N): ");
        int N = input.nextInt();
        System.out.println("N + 77 = " + (N + 77));
        System.out.println("N - 3 = " + (N - 3));
        System.out.println("N * 2 = " + (N * 2));
    }

    public static void ejercicio02(Scanner input) {
        System.out.println("^-^ -{ Ingresa un numero y te dire si es par o inpar }");
        System.out.printf("> ");
        int A = input.nextInt();
        System.out.println("El numero " + A + " es: " + (A % 2 == 0 ? "PAR" : "IMPAR"));
    }

    public static void ejercicio03(Scanner input) {
        System.out.println("^-^ -{ Ingresa un numero y te dire si es positivo o negativo }");
        System.out.printf("> ");
        int B = input.nextInt();
        System.err.println("El numero " + B + " es: " + (B >= 1 ? "POSITIVO" : "NEGATIVO"));
    }

    public static void ejercicio04(Scanner input) {
        System.out.println("^_^ -{ Te muestro el valor ASCII del primer caracter }");
        System.out.printf("> ");
        String text = input.next();
        char firstCharacter = text.charAt(0);
        System.out.println("Ingresaste " + text);
        System.out.println("           ^-> " + firstCharacter + " = " + (int) firstCharacter);
    }

    public static void ejercicio05(Scanner input) {
        System.out.println("^-^ -{ Voy a hacer un par de calculos, ahora te cuento :P }");
        System.out.printf("Ingresa un numero -> ");
        int C = input.nextInt();
        System.err.println("El numero " + C + " " + (C >= 1 ? "POSITIVO" : "NEGATIVO"));
        System.out.println("El numero " + C + " " + (C % 2 == 0 ? "PAR" : "IMPAR"));
        System.out.println("El numero " + C + " " + (C % 5 == 0 ? "SI " : "NO") + " es multiplo de 5");
        System.out.println("El numero " + C + " " + (C % 10 == 0 ? "SI" : "NO") + " es multiplo de 10");
        System.err.println("El numero " + C + " " + (C >= 100 ? "SI" : "NO") + " es mayor que 100");
    }

    public static void ejercicio06(Scanner input) {
        System.out.println("^-^ -{ Como te llamas?}");
        System.out.printf("> ");
        String name = input.next();
        System.out.println("^_^ -{ Hola, buenos dias " + name + " }");
    }

    public static void ejercicio07(Scanner input) {
        System.out.println("^_^ -{ Ingrese la velocidad a la que va (Km/h) }");
        System.out.printf("> ");
        float velocidadKm = input.nextFloat();
        float velocidadMS = velocidadKm * 1000 / 3600;
        System.out.println("^-^ -{ Sabia que puedo convertir Km/h a m/s ? }");
        System.err.println(velocidadKm + "Km/h = " + velocidadMS + "m/s");
    }

    public static void ejercicio08(Scanner input) {
        System.out.println("^_^ -{ Te voy a hacer un truco }");
        int num;
        do {
            ConsoleUtils.clearConsole();
            System.out.printf("- Ingresa un numero de tres cifras: \n> ");
            num = input.nextInt();
        } while (num < 100 || num > 999);
        String numStr = Integer.toString(num);
        for (int i = 0; i < numStr.length(); i++) {
            System.out.println("Pos " + (i + 1) + "-> " + (numStr.charAt(i)));
        }
    }

    public static void ejercicio09(Scanner input) {
        System.out.println("^_^ -{ Te voy a hacer un truco }");
        int num;
        do {
            ConsoleUtils.clearConsole();
            System.out.printf("- Ingresa un numero de cinco cifras: \n> ");
            num = input.nextInt();
        } while (num < 10000 || num > 99999);
        String numStr = Integer.toString(num);
        for (int i = 0; i < numStr.length(); i++) {
            if (i % 2 != 0) {
                System.out.println((numStr.charAt(i)));
            }
        }
    }

    public static void ejercicio10(Scanner input) {
        System.out.println("^_^  -{ Vamos a saber si entendes como colocar la hora correctamente }\n");
        int H, M, S;
        boolean invalid = false;
        do {
            System.out.println("Ingrese la hora con el sistema \"militar\"");
            System.out.printf("Hs: ");
            H = input.nextInt();
            System.out.printf("m: ");
            M = input.nextInt();
            System.out.printf("s: ");
            S = input.nextInt();
            if (H < 0 || H > 23 || M < 0 || M > 59 || S < 0 || S > 59) {
                invalid = true;
                System.out.println("\nX_X -{ Ingresaste mal la hora }\n");
            } else {
                invalid = false;
                System.out.println("*_* -{Hora válida: " + H + ":" + M + ":" + S + "}");
            }
        } while (invalid);

    }

    public static void ejercicio11(Scanner input) {

        System.out.print("Ingrese su nombre: ");
        String nombre = input.nextLine();

        System.out.print("Ingrese su edad: ");
        int edad = input.nextInt();

        System.out.print("Ingrese su salario: ");
        double salario = input.nextDouble();

        if (edad < 16) {
            System.out.println(nombre + ", no tiene edad para trabajar.");
        } else if (edad >= 19 && edad <= 50) {
            double nuevoSalario = salario * 1.05; // Aumento del 5%
            System.out.println(nombre + ", su salario ajustado es: " + nuevoSalario);
        } else if (edad >= 51 && edad <= 60) {
            double nuevoSalario = salario * 1.10; // Aumento del 10%
            System.out.println(nombre + ", su salario ajustado es: " + nuevoSalario);
        } else if (edad > 60) {
            double nuevoSalario = salario * 1.15; // Aumento del 15%
            System.out.println(nombre + ", su salario ajustado es: " + nuevoSalario);
        }

    }

    public static void ejercicio12(Scanner input) {
        System.out.println("^_^ -{ Vamos a sacar el promedio de una lista de numeros }");
        int[] numeros = { 10, 20, 30, 40, 50 };
        double average = calcArrayAverage(numeros);
        System.out.print("\n12Ejemplo: ");
        for (int num : numeros) {
            System.out.print(" | " + num);
        }
        System.out.println("\nEl promedio del arreglo es: " + average);
        System.out.println("\n^-^ -{ Ahora te toca a vos }");

        System.out.print("Ingrese la cantidad de números: ");
        int length = input.nextInt();
        int[] inputNumeros = new int[length];
        for (int i = 0; i < inputNumeros.length; i++) {
            System.out.print("#" + (i + 1) + ": ");
            inputNumeros[i] = input.nextInt();
        }

        average = calcArrayAverage(inputNumeros);
        System.out.println("El promedio del arreglo es: " + average);

    }

    public static void ejercicio13(Scanner input) {
        System.out.println("^-^ -{ Voy a hacer la sumatoria de los naturales previos al numero que me pases }");
        System.out.print("Ingrese un número natural: ");
        int numero = input.nextInt();

        if (numero < 0) {
            System.out.println("Por favor, ingrese un número natural (0 o mayor).");
        } else {
            int suma = 0;

            for (int i = 1; i <= numero; i++) {
                suma += i;
            }
            System.out.println("La suma de los números naturales hasta " + numero + " es: " + suma);
        }
    }

    public static void ejercicio14(Scanner input) {
        double[] temperaturas = new double[20];
        System.out.println("^_^ -{ Me dicen Storm }");
        System.out.println("Ingrese 20 temperaturas correspondientes a un mes:");
        for (int i = 0; i < 20; i++) {
            System.out.print("Temperatura " + (i + 1) + ": ");
            temperaturas[i] = input.nextDouble();
        }

        double maximo = temperaturas[0];
        double minimo = temperaturas[0];
        double suma = 0;

        for (double temperatura : temperaturas) {
            if (temperatura > maximo) {
                maximo = temperatura;
            }
            if (temperatura < minimo) {
                minimo = temperatura;
            }
            suma += temperatura;
        }

        double promedio = suma / temperaturas.length;

        System.out.println("Temperatura máxima: " + maximo);
        System.out.println("Temperatura mínima: " + minimo);
        System.out.println("Promedio de temperaturas: " + promedio);
    }

    /// Funciones aux
    public static double calcArrayAverage(int[] array) {
        int acc = 0;
        for (int num : array) {
            acc += num;
        }
        return (double) acc / array.length;
    }
}
