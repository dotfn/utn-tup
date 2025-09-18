# 📘 Clase 2 – Introducción a Clases y Objetos, Scanner, Wrapper, String, StringBuilder y Arrays

---

## 🔹 Introducción a Clases y Objetos

- Una **clase** es un **plano** o plantilla que define atributos (datos) y métodos (comportamientos).  
- Un **objeto** es una instancia concreta de una clase.  

👉 Ejemplo:  
- **Clase** → plano de un automóvil.  
- **Objeto** → automóvil fabricado a partir del plano.  

### Estado de los objetos
- Los **atributos** definen las características.  
- El **estado** es la información actual almacenada en esos atributos.  
- El estado puede **cambiar a lo largo del tiempo**.  

```java
class Auto {
    String color;
    int velocidad;

    void acelerar() {
        velocidad += 10;
    }
}
````

---

## 🔹 Clase `Scanner`

Permite leer datos desde teclado, archivos u otras fuentes.

```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Ingrese un número: ");
        int n = sc.nextInt();
        System.out.println("Número ingresado: " + n);
        sc.close();
    }
}
```

### Métodos principales

- `nextLine()` → lee una línea completa.
    
- `nextInt()` → lee un entero.
    
- `nextDouble()` → lee un número con decimales.
    
- `nextBoolean()` → lee un booleano.
    
- `close()` → cierra el recurso.
    

⚠️ Problema común:  
Después de `nextInt()`, queda un salto de línea pendiente → usar `nextLine()` para consumirlo.

---

## 🔹 Clases Wrapper

- Cada tipo primitivo tiene su **clase envoltorio** (`wrapper`).
    
- Permiten usar métodos útiles y trabajar con colecciones (`Integer`, `Double`, etc.).
    

Ejemplos:

```java
Integer i = Integer.valueOf(123);
String s = i.toString();     // "123"
int j = i.intValue();        // 123
double d = i.doubleValue();  // 123.0
int k = Integer.parseInt("456"); // 456
```

👉 Métodos útiles:

- `parseInt()`, `parseDouble()` → convierten `String` a números.
    
- `toString()` → convierte a cadena.
    
- `intValue()`, `doubleValue()` → conversión entre tipos.
    

---

## 🔹 Clase `String`

- Una de las más usadas en Java.
    
- Representa **cadenas de caracteres**.
    
- Es una clase `final` → no puede heredarse.
    
- **Objetos inmutables**: no se pueden modificar una vez creados.
    

### Formas de crear un `String`

```java
String s1 = "Hola";
String s2 = new String("Hola");
```

### Comparación

- `==` → compara referencias.
    
- `equals()` → compara valores.
    
- `equalsIgnoreCase()` → ignora mayúsculas/minúsculas.
    
- `compareTo()` → devuelve número negativo, 0 o positivo según orden alfabético.
    

### Métodos principales

- `length()` → cantidad de caracteres.
    
- `toLowerCase()`, `toUpperCase()`.
    
- `trim()` → elimina espacios en extremos.
    
- `indexOf()`, `lastIndexOf()`.
    
- `substring(inicio, fin)` → devuelve parte de la cadena.
    
- `split(" ")` → divide en partes según separador.
    
- `startsWith()`, `endsWith()`.
    
- `charAt(posicion)`.
    
- `toCharArray()`.
    

```java
String frase = "Hola mundo Java";
String[] palabras = frase.split(" ");
for (String p : palabras) {
    System.out.println(p);
}
```

---

## 🔹 Clase `StringBuilder`

- Similar a `String`, pero **mutable** (se puede modificar sin crear nuevas instancias).
    
- Más eficiente en operaciones repetidas de concatenación.
    

Ejemplo:

```java
StringBuilder sb = new StringBuilder("Hola");
sb.append(" mundo");
System.out.println(sb); // Hola mundo
```

👉 Métodos comunes:

- `append()` → concatena.
    
- `insert()`, `delete()`.
    
- `reverse()` → invierte la cadena.
    
- `toString()` → convierte a `String`.
    

---

## 🔹 Arrays en Java

- Son **objetos que contienen múltiples elementos** del mismo tipo.
    
- Se accede por **índice (0-based)**.
    

### Declaración

```java
int[] numeros = new int[5]; // array de 5 enteros
```

### Inicialización abreviada

```java
int[] numeros = {1, 2, 3, 4, 5};
```

### Acceso

```java
numeros[0] = 10;
System.out.println(numeros[0]);
```

### Recorrido

```java
for (int i = 0; i < numeros.length; i++) {
    System.out.println(numeros[i]);
}

// For each
for (int n : numeros) {
    System.out.println(n);
}
```

👉 Ventajas del `for-each`:

- Simplicidad, legibilidad.  
    👉 Desventajas:
    
- No permite acceder al índice.
    
- No se puede modificar la colección mientras se itera.
    

---

# ✅ Observaciones

- **Scanner** es la puerta de entrada para interactuar con el usuario.
    
- Los **Wrapper** permiten aprovechar métodos y trabajar con colecciones genéricas.
    
- Los **String** son inmutables, lo que evita errores pero puede ser costoso en memoria → usar `StringBuilder` en operaciones intensivas.
    
- Los **Arrays** son básicos en Java y deben usarse con cuidado respecto a su tamaño fijo.
    
---
