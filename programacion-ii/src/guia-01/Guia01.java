
public class Guia01 {
    public static void main(String[] args) {
        System.out.println("\n===== Ejercicio 01 =====\n");
        ejercicio01();
        System.out.println("\n===== Ejercicio 02 =====\n");
        ejercicio02();
        System.out.println("\n===== Ejercicio 03 =====\n");
        ejercicio03();
    }

    public static void ejercicio01() {
        int numN = 0;
        double numA = 89.212;
        char numC = 'a';

        System.out.println("numN: " + numN + "\nnumA: " + numA + "\nnumC: " + numC + "\n");
        System.out.println("numN + numA = " + (numN + numA));
        System.out.println("numA - numN = " + (numA - numN));
        System.out.println("numC (ASCII) = " + (int) numC);
    }

    public static void ejercicio02() {

        int numX = 10, numY = 5;
        double numN = 3.5, numM = 2.0;

        System.out.println("numX + numY = " + (numX + numY));
        System.out.println("numN + numM = " + (numN + numM));
        System.out.println("numX - numY = " + (numX - numY));
        System.out.println("numN - numM = " + (numN - numM));
        System.out.println("numX * numN = " + (numX * numN));
        System.out.println("numN / numM = " + (numN / numM));
    }

    public static void ejercicio03() {
        int A = 1, B = 2, C = 3, D = 4, aux = 0;
        System.out.println("*_* -{ Antes }");
        System.err.println("A: " + A + "\nB: " + B + "\nC: " + C + "\nD: " + D);
        aux = B;
        B = C;
        C = A;
        A = D;
        D = aux;
        System.out.println("\n0_0 -{ Despues }");

        System.err.println("A: " + A + "\nB: " + B + "\nC: " + C + "\nD: " + D);

    }
}
