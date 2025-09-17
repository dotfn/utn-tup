# 📘 Clase 11 – Interfaces y `Comparable` en Java

---

## 🔹 ¿Qué es una interfaz?

- Es un **tipo de referencia** similar a una clase abstracta.  
- Define un **conjunto de métodos (sin implementación)** y **constantes**.  
- Sirve como un **contrato** que una clase debe cumplir al implementarla.  
- Las clases que implementan una interfaz **están obligadas** a proporcionar implementación para sus métodos.  

👉 Se utiliza para **definir comportamientos comunes en clases no relacionadas**.

---

## 🔹 Declaración de una interfaz

- Se usa la palabra reservada `interface`.  
- Los métodos no tienen cuerpo, solo la firma.  
- Implícitamente, todos los métodos son **`public` y `abstract`**.  
- Las constantes declaradas son implícitamente **`public static final`**.  

```java
interface Mascota {
    void jugar();
    void alimentar();
}
````

---

## 🔹 Implementación de una interfaz

- Una clase usa la palabra clave `implements` para aplicar una interfaz.
    
- Debe implementar todos los métodos definidos.
    

```java
class Perro implements Mascota {
    @Override
    public void jugar() {
        System.out.println("El perro juega con la pelota");
    }

    @Override
    public void alimentar() {
        System.out.println("El perro come croquetas");
    }
}
```

---

## 🔹 Interfaces y polimorfismo

- Una interfaz puede ser usada como **tipo de dato**.
    
- Permite trabajar con diferentes clases bajo un mismo contrato.
    

```java
public class Main {
    public static void main(String[] args) {
        Mascota m1 = new Perro();
        Mascota m2 = new Gato();

        m1.jugar();
        m2.jugar();
    }
}
```

👉 Esto permite manejar clases no relacionadas de forma uniforme.

---

## 🔹 Diferencias entre Interfaces y Clases Abstractas

|Característica|Interfaz|Clase Abstracta|
|---|---|---|
|Métodos|Solo abstractos (implícitamente públicos)|Abstractos y concretos|
|Variables de instancia|No permite|Sí permite|
|Constructores|No permite|Sí permite|
|Herencia|Puede implementar múltiples interfaces|Solo herencia simple|
|Uso recomendado|Para **contratos comunes** sin relación|Para compartir atributos y lógica parcial|

---

## 🔹 Herencia múltiple con interfaces

- Una clase puede implementar **varias interfaces**:
    

```java
class Robot implements Mascota, Serializable {
    @Override
    public void jugar() { System.out.println("El robot juega virtualmente"); }
    @Override
    public void alimentar() { System.out.println("El robot no necesita comida"); }
}
```

- Una interfaz puede **heredar de otras interfaces**:
    

```java
interface Animal {
    void mover();
}

interface Mascota extends Animal {
    void jugar();
}
```

---

## 🔹 Interfaces como tipo de dato

- Una interfaz define un **nuevo tipo de referencia**.
    
- Puede usarse en:
    
    - Declaración de variables.
        
    - Parámetros de métodos.
        
    - Valores de retorno.
        

👉 Ventajas:

- Aumenta la **flexibilidad** (código desacoplado).
    
- Garantiza que cualquier objeto asignado cumple con un contrato.
    

```java
void ensayar(InstrumentoMusical inst) {
    inst.tocar();
}
```

---

## 🔹 La interfaz `Comparable`

- Define el **orden natural** de los objetos.
    
- Es usada en colecciones (`TreeSet`, `TreeMap`) y algoritmos (`Arrays.sort()`, `Collections.sort()`).
    
- Método principal:
    

```java
public interface Comparable<T> {
    int compareTo(T o);
}
```

### Contrato de `compareTo`:

- Devuelve **< 0** → si el objeto actual es menor.
    
- Devuelve **0** → si son iguales.
    
- Devuelve **> 0** → si es mayor.
    

---

## 🔹 Ejemplo de `Comparable`

```java
class Persona implements Comparable<Persona> {
    private String nombre;
    private int edad;

    Persona(String nombre, int edad) {
        this.nombre = nombre;
        this.edad = edad;
    }

    @Override
    public int compareTo(Persona otra) {
        return Integer.compare(this.edad, otra.edad);
    }

    @Override
    public String toString() {
        return nombre + " (" + edad + ")";
    }
}

public class Main {
    public static void main(String[] args) {
        List<Persona> lista = Arrays.asList(
            new Persona("Ana", 25),
            new Persona("Luis", 30),
            new Persona("Sofía", 20)
        );

        Collections.sort(lista);
        System.out.println(lista);
    }
}
```

👉 Resultado: `[Sofía (20), Ana (25), Luis (30)]`.

---

# ✅ Observaciones

- Las **interfaces definen contratos**, lo que permite un diseño más flexible y desacoplado.
    
- A diferencia de las clases abstractas, **pueden implementarse múltiples interfaces**.
    
- Usar **interfaces como tipo de dato** permite aplicar polimorfismo sin forzar jerarquías rígidas.
    
- La interfaz `Comparable` es esencial para definir orden natural en colecciones.
    
- Buenas prácticas:
    
    - Diseñar código en función de interfaces, no de implementaciones.
        
    - Mantener el contrato de `compareTo` consistente con `equals()`.
        

---
