
package util;

import java.io.IOException;

public class ConsoleUtils {

    /**
     * Limpia la consola dependiendo del sistema operativo.
     */
    public static void clearConsole() {
        try {
            if (System.getProperty("os.name").contains("Windows")) {
                new ProcessBuilder("cmd", "/c", "cls").inheritIO().start().waitFor();
            } else {
                new ProcessBuilder("clear").inheritIO().start().waitFor();
            }
        } catch (IOException | InterruptedException ex) {
            System.out.println("Error al limpiar la consola.");
        }
    }

    /**
     * Imprime un mensaje en la consola con un formato específico.
     * 
     * @param message El mensaje a imprimir.
     */
    public static void printFormatted(String message) {
        System.out.println("=== " + message + " ===");
    }

    /**
     * Pausa la ejecución del programa durante un tiempo específico.
     * 
     * @param milliseconds Tiempo en milisegundos para pausar.
     */
    public static void pause(int milliseconds) {
        try {
            Thread.sleep(milliseconds);
        } catch (InterruptedException e) {
            System.out.println("Error al pausar la ejecución.");
        }
    }

}
