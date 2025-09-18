# 📘 Clase 4 – Diseño de Clases y Encapsulamiento

---

## 🔹 Diseño de clases

Cuando queremos resolver un problema con POO, el punto de partida es **diseñar las clases**.

### Pasos iniciales
1. **Identificar conceptos relevantes**  
   - Buscar sustantivos en el análisis → posibles clases.  
   - Ej: `Cliente`, `Producto`, `Pedido`.  

2. **Reconocer características y acciones**  
   - **Atributos** → buscar adjetivos. Ej: `pedido urgente`.  
   - **Métodos** → buscar verbos. Ej: `realizar un pedido`.  

3. **Agrupación y refinamiento**  
   - Sustantivos → clases.  
   - Verbos → métodos.  
   - Adjetivos → atributos.  

4. **Definir responsabilidades y alcance** de cada clase.  

5. **Analizar comunicación** entre objetos.  

⚠️ **Nota**: No todos los sustantivos son clases. Algunos pueden ser atributos. El diseño inicial se refina con el tiempo.

---

## 🔹 Métodos

- Son bloques de código que se ejecutan cuando se llaman.  
- Pueden recibir parámetros, procesar datos y devolver un resultado.  
- Mejoran la reutilización y organización del programa.  

```java
public class Calculadora {
    public int sumar(int a, int b) {
        return a + b;
    }
}
````

### Estructura de un método

- **Modificadores de acceso**: `public`, `private`, `protected`, `default`.
    
- **Tipo de retorno**: `int`, `double`, `void`, objetos, etc.
    
- **Nombre**: verbo en minúscula.
    
- **Parámetros**: valores de entrada.
    
- **Cuerpo**: instrucciones.
    
- **return**: devuelve el resultado (si aplica).
    

---

## 🔹 Objetos como parámetros

Cuando se pasa un objeto a un método:

- Se pasa **una referencia**, no una copia.
    
- Los cambios dentro del método afectan al objeto original.
    

```java
class Persona {
    String nombre;
}

class Main {
    static void cambiarNombre(Persona p) {
        p.nombre = "Carlos";
    }

    public static void main(String[] args) {
        Persona a = new Persona();
        a.nombre = "Ana";
        cambiarNombre(a);
        System.out.println(a.nombre); // Carlos
    }
}
```

---

## 🔹 Constructores

- Método especial que inicializa objetos.
    
- Se ejecuta automáticamente al usar `new`.
    
- Tiene el mismo nombre que la clase.
    
- No tiene tipo de retorno.
    

```java
class Libro {
    String titulo, autor;

    // Constructor con 2 parámetros
    public Libro(String titulo, String autor) {
        this.titulo = titulo;
        this.autor = autor;
    }

    // Constructor con 1 parámetro
    public Libro(String titulo) {
        this.titulo = titulo;
        this.autor = null;
    }
}
```

### Constructor por defecto

- Si no definimos ninguno, Java crea uno vacío.
    
- Si definimos al menos uno, el por defecto **no se genera**.
    

---

## 🔹 La palabra clave `this`

- Se refiere al objeto actual.
    
- Distingue entre atributos y variables locales con el mismo nombre.
    

```java
class Persona {
    String nombre;

    Persona(String nombre) {
        this.nombre = nombre;
    }
}
```

---

## 🔹 Memoria en Java: Heap y Stack

- **Stack** → almacena variables locales y referencias.
    
- **Heap** → almacena objetos creados con `new`.
    
- Las variables de tipo primitivo se copian.
    
- Los objetos se asignan como **referencias compartidas**.
    

```java
Persona a = new Persona("Ana");
Persona b = a; // Ambas referencias apuntan al mismo objeto
```

### Garbage Collector

- Libera memoria automáticamente cuando un objeto no tiene referencias.
    

---

## 🔹 Atributos

- Se inicializan automáticamente con valores por defecto:
    
    - numéricos → `0`
        
    - flotantes → `0.0`
        
    - char → `'\u0000'`
        
    - boolean → `false`
        
    - objetos → `null`
        

---

## 🔹 Modificadores de acceso

Definen la visibilidad de atributos, métodos y clases:

- `public` → accesible desde cualquier clase.
    
- `private` → accesible solo dentro de la clase.
    
- `protected` → accesible desde el mismo paquete y subclases.
    
- `default` → accesible desde el mismo paquete.
    

👉 **Buenas prácticas**:

- Usar `private` en atributos.
    
- Usar `public` en métodos necesarios.
    
- Usar `protected` para reutilización en subclases.
    

---

## 🔹 Encapsulamiento

- Oculta los atributos, expone solo métodos de acceso controlado.
    
- Protege la integridad de los datos.
    
- Mejora la seguridad, mantenibilidad y validación.
    

### Ejemplo con setters y getters

```java
class Gato {
    private String nombre;
    private int edad;

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getEdad() {
        return edad;
    }

    public void setEdad(int edad) {
        if (edad > 0) this.edad = edad;
    }
}
```

---

## 🔹 Ventajas del encapsulamiento

- **Control de acceso** → evita inconsistencias.
    
- **Validación** → asegura valores válidos.
    
- **Mantenibilidad** → cambios internos no rompen el código externo.
    
- **Seguridad** → esconde detalles innecesarios.
    

---

# ✅ Observaciones

- **El diseño de clases comienza con el análisis semántico** del problema: sustantivos → clases, verbos → métodos, adjetivos → atributos.
    
- Los **constructores sobrecargados** dan flexibilidad en la creación de objetos.
    
- El uso de **this** evita ambigüedad en parámetros.
    
- Recordar que los **objetos en Java son referencias**.
    
- Siempre aplicar **encapsulamiento** para proteger datos y mejorar la calidad del código.
    
---
