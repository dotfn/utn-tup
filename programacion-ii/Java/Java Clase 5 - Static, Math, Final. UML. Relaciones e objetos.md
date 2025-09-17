# 📘 Clase 5 – Static, Math, Final. UML y Relaciones entre Objetos

---

## 🔹 Miembros `static`

Los **atributos y métodos estáticos** en Java son miembros de una clase que:

- Son **compartidos por todas las instancias**.
- Se accede a ellos **sin necesidad de crear un objeto**.

Se declaran con el modificador `static`.

### ✔️ Ventajas
- **Acceso sin instancia** → Se accede desde la clase directamente.
- **Recurso compartido** → El estado es común a todas las instancias.

---

### Métodos regulares (`non-static`)
- Requieren una **instancia** de la clase para invocarse.  
- Pertenecen a objetos específicos.  

```java
class Persona {
    String nombre;

    void saludar() {
        System.out.println("Hola, soy " + nombre);
    }
}

public class Main {
    public static void main(String[] args) {
        Persona p = new Persona();
        p.nombre = "Nicolás";
        p.saludar(); // Hola, soy Nicolás
    }
}
````

---

### Métodos `static`

- No dependen de una instancia.
    
- Se llaman con la clase:
    

```java
class Utilidades {
    static void mostrarInfo() {
        System.out.println("Método static llamado");
    }
}

public class Main {
    public static void main(String[] args) {
        Utilidades.mostrarInfo(); // correcto
    }
}
```

⚠️ **Restricciones**:

- No pueden usar variables de instancia.
    
- No pueden invocar métodos regulares.
    
- No usan `this` ni `super`.
    

---

## 🔹 Clase `Math`

Clase predefinida en Java con métodos estáticos para operaciones matemáticas.

Ejemplos:

```java
int mayor = Math.max(10, 25);       // 25
int menor = Math.min(10, 25);       // 10
double raiz = Math.sqrt(16);        // 4.0
double potencia = Math.pow(2, 3);   // 8.0
double aleatorio = Math.random();   // entre 0 y 1
```

---

## 🔹 Variables estáticas (`static`)

- Pertenecen a la clase, no a una instancia.
    
- Se accede con `Clase.atributo`.
    

```java
class Ballena {
    static int poblacion = 0;

    Ballena() {
        poblacion++;
    }
}

public class Main {
    public static void main(String[] args) {
        new Ballena();
        new Ballena();
        new Ballena();
        System.out.println("Población: " + Ballena.poblacion); // 3
    }
}
```

---

## 🔹 Constantes (`final`)

- Una vez asignado un valor, no cambia.
    
- Por convención → en **MAYÚSCULAS**.
    

```java
class CuentaBancaria {
    final String NUMERO_CUENTA;

    CuentaBancaria(String numero) {
        NUMERO_CUENTA = numero;
    }
}
```

---

## 🔹 `final` en variables, métodos y clases

- **Variable `final`** → inmutable.
    
- **Método `final`** → no se puede sobrescribir.
    
- **Clase `final`** → no se puede heredar.
    

```java
// Variable final
final int LIMITE = 100;

// Método final
class Vehiculo {
    final void frenar() {
        System.out.println("Frenando...");
    }
}

// Clase final
final class Constante {}
```

---

## 🔹 UML – Lenguaje Unificado de Modelado

Sirve para **documentar y visualizar** sistemas.  
En **diagramas de clase** se representan:

- Clases
    
- Atributos
    
- Métodos
    
- Relaciones
    

### Notación

- `+` public
    
- `-` private
    
- `#` protected
    
- `~` default
    

Ejemplo de atributo en UML:  
`- nombre: String = "Juan"`

Ejemplo de método en UML:  
`+ getNombre(): String`

---

## 🔹 Relaciones entre objetos

### Asociación

Relación general “usa un...”.  
Ej: `Auto` usa `Ruta`.  
Se dibuja con **línea simple**.

### Dependencia

Relación temporal → “necesita un...”.  
Se dibuja con **línea punteada con flecha**.

### Agregación

El todo tiene partes, pero **pueden existir por separado**.  
Ej: `Celular` y `Chip`.  
Se representa con **diamante vacío**.

### Composición

El todo necesita las partes y **no pueden existir por separado**.  
Ej: `Celular` y `Batería`.  
Se representa con **diamante relleno**.

### Herencia

Una clase hereda de otra → “es un...”.  
Se representa con **triángulo hueco hacia la superclase**.

---

## 🔹 Cohesión vs Acoplamiento

- **Alta cohesión** → cada clase cumple una responsabilidad clara.
    
- **Bajo acoplamiento** → las clases dependen lo menos posible entre sí.
    

👉 Meta: **máxima cohesión, mínimo acoplamiento.**

---

# ✅ Observaciones

- Los **miembros `static`** son útiles, pero **no deben abusarse**, ya que reducen la orientación a objetos.
    
- Las **constantes `final static`** son una práctica estándar para valores inmutables globales.
    
- En UML, más importante que el dibujo es **pensar las relaciones correctas** entre objetos.
    
- Cohesión y acoplamiento son conceptos clave para mantener **código limpio y escalable**.
    

---