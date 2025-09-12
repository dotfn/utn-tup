## Ejercitación Clase 8
### Clases y métodos abstractos

---

### Sobre esta guía:
Lea atentamente cada uno de los enunciados y antes de llevar a código cada ejercicio, realice en papel o con la ayuda de algún software, el correspondiente diagrama de UML, detallando los atributos, métodos y constructores que considere necesarios. Una vez terminado, escriba el código y ejecute las pruebas que se detallan.

---

### Enunciados:

1. **Modela un sistema que gestione los datos de los empleados de una empresa.**
   - Se contará con una clase padre **Empleado** de la cual no se podrán crear objetos. Cada empleado tiene un nombre y un método **calcularPago()** que debe ser implementado de manera específica para cada tipo de empleado (utilizando polimorfismo).
   - Implementa las siguientes clases hijas de la clase **Empleado**:
     - **EmpleadoTiempoCompleto**
     - **EmpleadoPorHoras**
     - **EmpleadoAcomision**
     - **EmpleadoContratista**
   - Los empleados a tiempo completo tienen años de antigüedad y un sueldo básico. En ellos, el método **calcularPago()** debe retornar ese salario mensual más el monto extra que corresponda por antigüedad, el cual será:
     - Menos de dos años: salario base.
     - De 2 a 5 años: 5% más.
     - De 6 a 10 años: 10% más.
     - De 11 a 15 años: 15% más.
     - Más de 15 años: 20% más.
   - Para los empleados por horas, el método **calcularPago()** debe retornar un salario calculado según las horas trabajadas y el precio que se le paga la hora a dicho empleado.
   - Los empleados contratistas son empleados contratados para proyectos específicos (su trabajo comienza y termina con dicho proyecto). El método **calcularPago()** debe retornar un salario calculado según el número de horas trabajadas y la tarifa por hora asignada a ese proyecto.
   - El pago de los empleados a comisión se obtiene multiplicando la cantidad de clientes captados por la comisión correspondiente a cada tipo de cliente. Si el monto por los clientes captados no llega a un monto mínimo (que es igual para todos los empleados a comisión y asciende a **$800.000**), el empleado cobrará esta cantidad mínima.
   - Permite al usuario realizar las operaciones necesarias mediante un menú.

2. **Evaluar cuál será la salida por pantalla:**
   ```java
   public abstract class A {
       public abstract void dinamica();
       public void estatica() {
           System.out.println("Método estático de la clase A");
       }
   }
   public class B extends A {
       public void dinamica() {
           System.out.println("Método dinámico de clase B");
       }
   }
   public class C extends A {
       public void dinamica() {
           System.out.println("Método dinámico de clase C");
       }
   }
   public class Ligadura {
       static public void main(String [] ar){
           A a;
           B b = new B();
           C c = new C();
           System.out.print("Métodos llamados con objeto b desde");
           System.out.println(" referencia de la clase A");
           a = b;
           a.dinamica();
           a.estatica();
           System.out.print("Métodos llamados con objeto c desde");
           System.out.println(" referencia de la clase A");
           a = c;
           a.dinamica();
           a.estatica();
       }
   }
   ```
   - **¿Cuál es la salida por pantalla?**

3. **TestFlujo:** En la siguiente jerarquía de herencia existen llamadas a métodos en los que se debe tener claro el concepto de polimorfismo. Escribe cuál sería el resultado de la ejecución del siguiente código:
   ```java
   abstract class Flujo {
       abstract public void escribe(char c);
       public void escribe(String s) {
           for (int i = 0; i < s.length(); i++) {
               System.out.println("Escribe de Flujo ....");
               escribe(s.charAt(i));
           }
       }
       public void escribe(int i) {
           escribe("" + i);
       }
   }
   class Disco extends Flujo {
       public void escribe(char c) {
           System.out.println("Escribe de disco " + c);
       }
   }
   class DiscoFlexible extends Disco {
       public void escribe(String s) {
           System.out.println("Escribe de Disco Flexible...");
           super.escribe(s);
       }
   }
   public class TestFlujo {
       public static void main(String a[]) {
           DiscoFlexible dc = new DiscoFlexible();
           Flujo f = dc;
           f.escribe("ab");
       }
   }
   ```

### 4. Detecta los dos errores que presenta este código y explica por qué no es correcto:
```java
abstract class A {
    int i;
    A(int i) {
        this.i = i;
    }
}
class B extends A {
    void metodo() {
        System.out.println(i);
    }
}
class Cuestion {
    public static void main(String[] args) {
        A[] v = new A[10];
        for (int i = 0; i < 10; i++) {
            v[i] = new B();
            v[i].metodo();
        }
    }
}
```

---

### Errores en el código:

1. **Error de constructor no llamado:**
   - La clase **B** extiende de la clase abstracta **A**, que tiene un constructor que requiere un parámetro entero. Sin embargo, en la clase **B**, no se está llamando al constructor de la clase padre **A**. Esto generará un error de compilación porque el compilador no puede encontrar un constructor por defecto en la clase **A**. Para corregir esto, se debe agregar un constructor en la clase **B** que llame al constructor de **A** utilizando `super(i)`.

2. **Error de método no definido:**
   - En el método `metodo()` de la clase **B**, se intenta llamar a `System.out.println(i);`. Sin embargo, el método `metodo()` no está definido en la clase **A** como un método que se pueda invocar desde un objeto de tipo **A**. Esto generará un error de compilación porque el método `metodo()` no es parte de la interfaz de la clase **A**. Para solucionarlo, se puede definir el método `metodo()` en la clase **A** como un método abstracto o proporcionar una implementación en la clase **A**.

---

### Resumen de la salida esperada:
- Para el ejercicio 2, la salida por pantalla del código proporcionado sería:
  ```
  Métodos llamados con objeto b desde referencia de la clase A
  Método dinámico de clase B
  Método estático de la clase A
  Métodos llamados con objeto c desde referencia de la clase A
  Método dinámico de clase C
  Método estático de la clase A
  ```

- Para el ejercicio 3, la salida del código sería:
  ```
  Escribe de Flujo ....
  Escribe de disco a
  Escribe de Flujo ....
  Escribe de disco b
  ```

Si necesitas más detalles sobre algún punto específico o tienes más preguntas, no dudes en decírmelo.