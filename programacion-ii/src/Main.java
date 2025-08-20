import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int opcion;
        
        do {
            // Mostrar el menú
            System.out.println("----- Menú -----");
            System.out.println("1. Sumar");
            System.out.println("2. Restar");
            System.out.println("3. Multiplicar");
            System.out.println("4. Dividir");
            System.out.println("5. Salir");
            System.out.print("Seleccione una opción: ");
            
            // Leer la opción del usuario
            opcion = scanner.nextInt();

            // Procesar la opción seleccionada
            switch (opcion) {
                case 1:
                    realizarOperacion(scanner, "sumar");
                    break;
                case 2:
                    realizarOperacion(scanner, "restar");
                    break;
                case 3:
                    realizarOperacion(scanner, "multiplicar");
                    break;
                case 4:
                    realizarOperacion(scanner, "dividir");
                    break;
                case 5:
                    System.out.println("Saliendo del programa...");
                    break;
                default:
                    System.out.println("Opción no válida. Intente de nuevo.");
            }
        } while (opcion != 5);

        // Cerrar el objeto Scanner
        scanner.close();
    }

    // Método para realizar operaciones
    private static void realizarOperacion(Scanner scanner, String operacion) {
        System.out.print("Ingrese el primer número: ");
        double num1 = scanner.nextDouble();
        System.out.print("Ingrese el segundo número: ");
        double num2 = scanner.nextDouble();
        double resultado;

        switch (operacion) {
            case "sumar":
                resultado = num1 + num2;
                System.out.println("Resultado de la suma: " + resultado);
                break;
            case "restar":
                resultado = num1 - num2;
                System.out.println("Resultado de la resta: " + resultado);
                break;
            case "multiplicar":
                resultado = num1 * num2;
                System.out.println("Resultado de la multiplicación: " + resultado);
                break;
            case "dividir":
                if (num2 != 0) {
                    resultado = num1 / num2;
                    System.out.println("Resultado de la división: " + resultado);
                } else {
                    System.out.println("Error: División por cero.");
                }
                break;
        }
    }
}
