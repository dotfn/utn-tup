import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

// Clase abstracta
abstract class Animal {
    abstract void hacerSonido();
}

// Clase que hereda de Animal
class Perro extends Animal {
    void hacerSonido() {
        System.out.println("¡Guau!");
    }
}

// Clase que hereda de Animal
class Gato extends Animal {
    void hacerSonido() {
        System.out.println("¡Miau!");
    }
}

// Interfaz
interface Operaciones {
    int sumar(int a, int b);
    int restar(int a, int b);
}

// Clase que implementa la interfaz
class Calculadora implements Operaciones {
    public int sumar(int a, int b) {
        return a + b;
    }

    public int restar(int a, int b) {
        return a - b;
    }
}

// Enumeración
enum Dias {
    LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
}

public class Examples {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Variables y operadores
        System.out.print("Ingrese el primer número: ");
        int a = scanner.nextInt();
        System.out.print("Ingrese el segundo número: ");
        int b = scanner.nextInt();
        System.out.println("Suma: " + (a + b));
        System.out.println("Resta: " + (a - b));

        // Clases y objetos
        Calculadora calc = new Calculadora();
        System.out.println("Suma usando Calculadora: " + calc.sumar(a, b));

        // Cadenas y arreglos
        scanner.nextLine(); // Limpiar el buffer
        System.out.print("Ingrese un saludo: ");
        String saludo = scanner.nextLine();
        String[] palabras = saludo.split(" ");
        System.out.println("Palabras en el saludo:");
        for (String palabra : palabras) {
            System.out.println(palabra);
        }

        // Herencia y polimorfismo
        Animal miPerro = new Perro();
        Animal miGato = new Gato();
        miPerro.hacerSonido();
        miGato.hacerSonido();

        // Encapsulamiento
        Persona persona = new Persona("Juan", 30);
        System.out.println("Nombre: " + persona.getNombre());
        System.out.println("Edad: " + persona.getEdad());

        // Uso de enumeraciones
        Dias dia = Dias.LUNES;
        System.out.println("Día de la semana: " + dia);

        // Colecciones
        List<String> lista = new ArrayList<>();
        lista.add("Elemento 1");
        lista.add("Elemento 2");
        System.out.println("Elementos de la lista:");
        for (String elemento : lista) {
            System.out.println(elemento);
        }

        Map<String, Integer> mapa = new HashMap<>();
        mapa.put("Uno", 1);
        mapa.put("Dos", 2);
        System.out.println("Elementos del mapa:");
        for (Map.Entry<String, Integer> entry : mapa.entrySet()) {
            System.out.println(entry.getKey() + ": " + entry.getValue());
        }

        // Manejo de excepciones
        try {
            System.out.println("División: " + dividir(a, 0));
        } catch (ArithmeticException e) {
            System.out.println("Error: " + e.getMessage());
        }

        // Manejo de archivos
        try {
            escribirArchivo("salida.txt", "Hola, archivo!");
            System.out.println("Archivo escrito correctamente.");
        } catch (Exception e) {
            System.out.println("Error al escribir el archivo: " + e.getMessage());
        }

        // Cerrar el objeto Scanner
        scanner.close();
    }

    // Método para dividir
    public static double dividir(int a, int b) {
        return a / b; // Puede lanzar ArithmeticException si b es 0
    }

    // Método para escribir en un archivo
    public static void escribirArchivo(String nombreArchivo, String contenido) throws Exception {
        java.nio.file.Files.write(java.nio.file.Paths.get(nombreArchivo), contenido.getBytes());
    }
}

// Clase para encapsulamiento
class Persona {
    private String nombre;
    private int edad;

    public Persona(String nombre, int edad) {
        this.nombre = nombre;
        this.edad = edad;
    }

    public String getNombre() {
        return nombre;
    }

    public int getEdad() {
        return edad;
    }
}
