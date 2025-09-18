# 📘 Clase 6 – Herencia en Java

---

## 🔹 ¿Qué es la herencia?

- Es una forma de **reutilización de software**.  
- Una clase nueva (**subclase / hija**) **absorbe atributos y métodos** de otra clase existente (**superclase / padre**).  
- La subclase puede **agregar atributos y métodos propios** y **sobrescribir** comportamientos heredados.  

👉 Permite crear **estructuras jerárquicas de clases** en forma de árbol.

---

## 🔹 Terminología básica

- **Superclase / Clase padre / Clase base** → la clase de la cual se hereda.  
- **Subclase / Clase hija / Clase derivada** → la clase que hereda.  
- **extends** → palabra reservada para heredar de una clase.  
- **super** → se usa en la subclase para acceder al constructor o métodos de la superclase.  
- **Sobrescritura de métodos** → redefinir un método heredado.  

---

## 🔹 Reglas de la herencia

- Una superclase puede tener varias subclases.  
- Una subclase solo puede tener **una superclase** (herencia simple).  
- Es posible la **herencia multinivel** (A → B → C).  
- Todas las clases en Java heredan implícitamente de **`java.lang.Object`**, salvo que se indique otra superclase.  

---

## 🔹 Ventajas de la herencia

1. **Evita duplicidad de código**  
   Ejemplo: clase `Persona` con atributos comunes (`nombre`, `dni`, `email`) que luego heredan `Estudiante` y `Profesor`.  

2. **Mantenibilidad y extensión**  
   Cambios en la superclase se propagan a las subclases.  
   Es posible **ampliar funcionalidad sin modificar lo ya existente**.  

3. **Modularidad y estructura jerárquica clara**  
   El código se organiza mejor.  

4. **Uso de API**  
   Java ofrece muchas clases listas para usar o extender.  

---

## 🔹 Sobrescritura de métodos

- La subclase redefine un método heredado para ajustar su comportamiento.  
- La versión de la subclase reemplaza a la de la superclase.  

### Reglas:
- La **firma** (nombre + parámetros + tipo de retorno) debe ser la misma.  
- El modificador de acceso puede ser **igual o más permisivo**, nunca más restrictivo.  
- El tipo de retorno debe ser el mismo, o un subtipo (covarianza).  

### Ejemplo con `@Override`
```java
class Animal {
    void hacerSonido() {
        System.out.println("Sonido genérico");
    }
}

class Perro extends Animal {
    @Override
    void hacerSonido() {
        System.out.println("Guau guau");
    }
}
````

---

## 🔹 La palabra reservada `super`

Se usa para:

- **Llamar a métodos de la superclase** → `super.metodo()`.
    
- **Invocar constructores de la superclase** → `super()`.
    

### Reglas con constructores

- El **constructor de la subclase debe invocar al constructor de la superclase** como primera sentencia.
    
- Si no se escribe, el compilador agrega `super()` implícito (requiere que la superclase tenga un constructor sin parámetros).
    
- Si la superclase solo define constructores con parámetros, la subclase debe llamarlos explícitamente.
    

---

## 🔹 Ejemplo de herencia y constructores

```java
class Animal {
    String nombre;

    Animal(String nombre) {
        this.nombre = nombre;
        System.out.println("Animal creado");
    }
}

class Perro extends Animal {
    Perro(String nombre) {
        super(nombre); // llamada al constructor de Animal
        System.out.println("Perro creado");
    }
}
```

---

## 🔹 Herencia y modificadores de acceso

- Una subclase puede acceder a miembros **public** y **protected** de la superclase.
    
- **No puede acceder directamente a atributos privados** → se accede mediante getters y setters.
    

```java
class Persona {
    private String nombre;
    protected int edad;

    public String getNombre() { return nombre; }
    public void setNombre(String n) { this.nombre = n; }
}

class Estudiante extends Persona {
    void imprimir() {
        // System.out.println(nombre); ❌ no permitido (es private)
        System.out.println(edad);   // ✔ permitido (es protected)
    }
}
```

---

## 🔹 Clases `final` y herencia

- Una clase marcada como `final` no puede heredarse.
    

```java
final class Constante {}

class Hija extends Constante {} // ❌ error de compilación
```

---

# ✅ Observaciones

- La **herencia debe usarse con criterio**: abusar de ella puede generar jerarquías rígidas y poco flexibles.
    
- Cuando sea posible, preferir **composición** antes que herencia (principio de diseño conocido como _"prefer composition over inheritance"_).
    
- Usar **`@Override` siempre** al sobrescribir, mejora la legibilidad y evita errores.
    
- Recordar que todas las clases heredan implícitamente de `Object`, lo que provee métodos como `toString()`, `equals()`, `hashCode()`.
    

---
