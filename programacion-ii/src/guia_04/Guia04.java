package guia_04;

import guia_04.Entities.Libro;

import java.util.Scanner;

public class Guia04 {

    private static void ejercicio1(Scanner sc){
        System.out.println("EJERCICIO 1");
        System.out.println("^_^ -{ "+ "Vamos a practicar geometria"+" }");
        System.out.println("- Ingrese el radio de un circulo ");
        System.out.print("> ");
        double radio = sc.nextDouble();
        System.out.println("\n-Longitud (2*PI*radio) = "+ (2 * Math.PI * radio));
        System.out.println("-Area (PI * radio^2) = " + (Math.PI*Math.pow(radio, 2)));
    }

    private static void ejercicio2(Scanner sc){
        System.out.println("EJERCICIO 2");
        System.out.println("^_^ -{ "+ "Vamos a practicar geometria"+" }");
        System.out.print("Ingrese el valor del cateto a: \n> ");
        double a = sc.nextDouble();

        System.out.print("Ingrese el valor del cateto b: \n> ");
        double b = sc.nextDouble();

        double hipotenusa = Math.sqrt(Math.pow(a, 2) + Math.pow(b, 2));

        System.out.printf("La hipotenusa es: %.2f%n", hipotenusa);

    }

    private static void ejercicio3(Scanner sc){
        System.out.println("EJERCICIO 3");
        System.out.println("^_^ -{ Vamos a practicar geometria }");
        double radio = sc.nextDouble();
        double volumen = (4.0)/(3.0) * Math.PI * Math.pow(radio, 3);
        System.out.println("Volumen (4/3 * PI * radio^3) = " + volumen);
    }

    private static void ejercicio4(Scanner sc){
        System.out.println("EJERCICIO 4");
        Libro libro1 = new Libro("El Quijote", "Miguel de Cervantes", 500, 10);
        Libro libro2 = new Libro("Cien Años de Soledad", "Gabriel Garcia Marquez", 700, 5);
        System.out.println("\n========= C ==========");
        System.out.println(libro1);
        System.out.println(libro2);
        System.out.println("\n========= D ==========");

        if ((!libro1.venderLibros(3))) {
            System.out.println("NO HAY STOCK SUFICIENTE");
        } else {
            System.out.println("Vendido");
        }
        System.out.println("\n========= E ==========");
        System.out.println(libro1);
        System.out.println("\n========= F ==========");
        if(!libro2.venderLibros(8)){
            System.out.println("NO HAY STOCK SUFICIENTE");
        }else {
            System.out.println("Vendido");

        }
        System.out.println("\n========= G ==========");
        libro2.incrementarStock(5);
        System.out.println("\n========= H ==========");
        System.out.println(libro2);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int option;
        do {
            System.out.println("\n=====================");
            System.out.println("=======GUIA 04=======");
            System.out.println("1 - Ejercicio 1");
            System.out.println("2 - Ejercicio 2");
            System.out.println("3 - Ejercicio 3");
            System.out.println("3 - Ejercicio 4");
            System.out.println("0 - Salir");
            System.out.print("> ");
            option = sc.nextInt();
            sc.nextLine();
            System.out.println("\n=====================");
            System.out.println("=====================");

            switch (option){
                case 0 -> System.out.println("Saliendo...");
                case 1 -> ejercicio1(sc);
                case 2 -> ejercicio2(sc);
                case 3 -> ejercicio3(sc);
                case 4 -> ejercicio4(sc);
                default -> System.err.println("Opcion incorrecta");
            }
            System.out.println("\nVOLVER AL MENU?");
            System.out.println("1: VOLVER \n2: SALIR");
            option = sc.nextInt();
            sc.nextLine();
        }while (option != 0);
    }}