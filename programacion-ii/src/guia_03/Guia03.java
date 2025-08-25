package guia_03;

import java.util.Scanner;

import util.ConsoleUtils;

public class Guia03 {
    /// 01
    public static class Empleado {
        private long dni;
        private String name;
        private String lastName;
        private float salary;

        public Empleado(long dni, String name, String lastName, float salary) {
            this.dni = dni;
            this.name = name;
            this.lastName = lastName;
            this.salary = salary;
        }

        public long getDni() {
            return dni;
        }

        public void setDni(long dni) {
            this.dni = dni;
        }

        public String getLastName() {
            return lastName;
        }

        public void setLastName(String lastName) {
            this.lastName = lastName;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public float getSalary() {
            return salary;
        }

        public void setSalary(float salary) {
            this.salary = salary;
        }

        public void showEmpleado() {
            System.out.println("DNI = " + this.dni);
            System.out.println("NOMBRE = " + this.name);
            System.out.println("APELLIDO = " + this.lastName);
            System.out.println("SALARIO = " + this.salary);
        }

        public float getAnnualSalary() {
            return this.salary * 12f;
        }

        public void applyIncrease(float percent) {
            this.salary = this.salary * (1f + percent / 100f);

        }
    }

    /// 02
    public static class bankAccount {
        private int id;
        private String name;
        private long balance;

        public bankAccount(int id, String name, long balance) {
            this.id = id;
            this.name = name;
            this.balance = balance;
        }

        public long getId() {
            return id;
        }

        public void setId(int id) {
            this.id = id;
        }

        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public long getBalance() {
            return balance;
        }

        public void setBalance(long balance) {
            this.balance = balance;
        }

        public long credito(long amount) {
            this.balance += amount;
            return this.balance;
        }

        // PREGUNTAR - 2b *********************
        public long debito(long amount) {
            if (this.balance < amount) {
                System.err.println("X_X -{ Saldo insuficiente }");
                return this.balance;
            } else {
                this.balance -= amount;
                return this.balance;
            }
        }

        public void showAccount() {
            System.out.println("Cuenta {");
            System.out.println("  id: " + id);
            System.out.println("  nombre: " + name);
            System.out.println("  balance: " + balance);
            System.out.println("}");
        }
    }

    /// 03
    public static class itemVenta {
        private int id;
        private String description;
        private int count;
        private double unitPrice;

        public itemVenta(int id, String description, double unitPrice, int count) {
            this.id = id;
            this.description = description;
            this.count = count;
            this.unitPrice = unitPrice;
        }

        public int getId() {
            return id;
        }

        public void setId(int id) {
            this.id = id;
        }

        public String getDescription() {
            return description;
        }

        public void setDescription(String description) {
            this.description = description;
        }

        public double getUnitPrice() {
            return unitPrice;
        }

        public void setUnitPrice(double unitPrice) {
            this.unitPrice = unitPrice;
        }

        public int getCount() {
            return count;
        }

        public void setCount(int count) {
            this.count = count;
        }

        public double calculateTotalPrice() {
            double totalPrice = 0;
            totalPrice = unitPrice * count;
            return totalPrice;
        }

        public void getTicket() {
            double totalPrice = this.calculateTotalPrice();
            System.out
                    .println(
                            "ItemVenta:\n[\n id= " + id + ", \n descripcion= " + description + ", \n cantidad= " + count
                                    + ", \n pUnitario= " + unitPrice + ", \n pTotal= " + totalPrice + " \n]");

        }
    }

    public static void ejercicio1(Scanner sc) {
        Empleado carlos = new Empleado(23456345L, "Carlos", "Gutiérrez", 25000f);
        Empleado ana = new Empleado(34234123L, "Ana", "Sánchez", 27500f);

        System.out.println("\nEmpleado 1 \n");
        carlos.showEmpleado();
        System.out.println("\nEmpleado 2 \n");
        ana.showEmpleado();
        //
        System.out.print("Ingrese porcentaje de aumento: ");
        float pct = sc.nextFloat();
        carlos.applyIncrease(pct);
        System.out.println("Salario después del aumento: " + carlos.getSalary());
        System.out.println("Salario anual: " + carlos.getAnnualSalary());
    }

    public static void ejercicio2(Scanner sc) {
        bankAccount account = new bankAccount(1, "Pedro", 15000);

        account.credito(2500);
        account.debito(1500);
        account.debito(30000);
        account.showAccount();
    }

    public static void ejercicio3(Scanner sc) {
        System.out.println("------- Cargar Ticket -------");
        System.err.print("ID: ");
        int id = sc.nextInt();
        sc.nextLine();
        System.out.print("Descripcion: ");
        String description = sc.nextLine();
        System.out.print("Precio x Unidad: ");
        double unitPrice = sc.nextDouble();
        System.out.print("Cantidad: ");
        int count = sc.nextInt();
        System.out.println("--------- Fin Ticket --------");
        itemVenta item = new itemVenta(id, description, unitPrice, count);

        ///
        int menuOption;
        do {
            System.out.println("1- Imprimir Ticket");
            System.out.println("2- Actualizar Cantida");
            System.out.println("3- Actualizar precio");
            System.out.println("4- Imprimir total");
            System.out.println("0- Salir");
            menuOption = sc.nextInt();
            switch (menuOption) {
                case 1:
                    System.out.println("********* TICKET **********");
                    item.getTicket();
                    System.out.println("*********** FIN ***********");
                    break;
                case 2:
                    System.out.println("*********** Actualizar Cantidad ***********");
                    System.out.print("Ingrese una nueva cantidad: ");
                    int newCount = sc.nextInt();
                    sc.nextLine();
                    item.setCount(newCount);
                    break;
                case 3:
                    System.out.println("*********** Actualizar Precio del Producto ***********");
                    System.out.print("Ingrese una nueva precio($): ");
                    int newPrice = sc.nextInt();
                    sc.nextLine();
                    item.setUnitPrice(newPrice);
                    break;
                case 4:
                    System.out.println("*********** Precio total ***********");
                    double totalPrice = item.calculateTotalPrice();
                    System.out.println("Precio total: " + totalPrice);
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
            menuOption = sc.nextInt();
            ConsoleUtils.clearConsole();
        } while (menuOption != 0);
    }

    public static void main(String[] args) {
        ConsoleUtils.clearConsole();
        Scanner sc = new Scanner(System.in);
        int menuOption = 0;
        do {
            System.err.println("========== MENU ==========");
            System.out.println("1 - EJERCICIO 01   ");
            System.out.println("2 - EJERCICIO 02");
            System.out.println("3 - EJERCICIO 03");
            System.out.println("0 - Salir ");
            System.out.print("Opcion > ");
            menuOption = sc.nextInt();
            ConsoleUtils.clearConsole();
            switch (menuOption) {
                case 1:
                    ejercicio1(sc);
                    break;
                case 2:
                    ejercicio2(sc);
                    break;
                case 3:
                    ejercicio3(sc);
                    break;
                case 0:
                    System.out.println("Saliendo del programa.");
                    break;
                default:
                    System.err.println("Opcion ivalida");
                    break;

            }

            System.out.println("\n^_^* -{ Volver al menu? } ");
            System.out.println("1. Volver");
            System.out.println("0. Salir");
            System.err.printf("> ");
            menuOption = sc.nextInt();
            ConsoleUtils.clearConsole();
        } while (menuOption != 0);
        sc.close();
    }
}
