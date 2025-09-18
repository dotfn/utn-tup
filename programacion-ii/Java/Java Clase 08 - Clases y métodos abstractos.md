# 📘 Clase 8 – Clases y Métodos Abstractos en Java

---

## 🔹 Clases abstractas – Concepto

- Son **similares a las clases concretas** (pueden tener atributos y métodos).  
- **No pueden instanciarse directamente** → no se crean objetos de ellas.  
- Se utilizan como **plantillas o modelos** para que otras clases hereden.  
- Definen **características y comportamientos comunes** de un conjunto de clases relacionadas.  

👉 Son el punto medio entre **interfaces** (puras) y **clases concretas**.

---

## 🔹 Cuándo usarlas

- Cuando queremos garantizar que las **subclases compartan atributos y métodos comunes**.  
- Cuando necesitamos que ciertas subclases **sobrescriban métodos específicos obligatoriamente**.  
- Cuando queremos **evitar que la superclase sea instanciada** directamente.  

---

## 🔹 Utilidad

- **Reutilización de código** → evita duplicidad en las subclases.  
- **Facilitan el polimorfismo** → permiten tratar objetos de subclases como instancias de la clase abstracta.  

```java
abstract class Figura {
    String color;

    Figura(String color) {
        this.color = color;
    }

    abstract double area(); // método abstracto
}
````

---

## 🔹 Creación y reglas

- Se definen con la palabra clave `abstract`.
    
- Aunque no pueden instanciarse, **pueden tener constructores** → se usan cuando la subclase llama a `super()`.
    

```java
abstract class Figura {
    String color;

    Figura(String color) {
        this.color = color;
    }
}
```

---

## 🔹 Métodos abstractos

- **No tienen implementación** (no cuerpo).
    
- Se declaran con la palabra clave `abstract`.
    
- Terminan con **`;`** en vez de `{}`.
    

```java
abstract class Figura {
    abstract double area();
}
```

---

### ¿Por qué usarlos?

- Definen un **contrato** → las subclases **deben implementar** los métodos abstractos.
    
- Se declaran abstractos cuando **aún no sabemos la implementación** exacta.
    

---

### Reglas de métodos abstractos

- Si una clase tiene métodos abstractos, **debe declararse abstracta**.
    
- Las subclases deben implementar todos los métodos abstractos con `@Override`.
    
- **Excepción**: si una subclase no los implementa, también debe declararse abstracta → la responsabilidad pasa a sus hijas.
    

```java
abstract class Figura {
    abstract double area();
}

class Circulo extends Figura {
    double radio;

    Circulo(double radio) {
        this.radio = radio;
    }

    @Override
    double area() {
        return Math.PI * radio * radio;
    }
}
```

---

## 🔹 Consideraciones

- No todo debe ser abstracto → una clase abstracta puede tener:
    
    - Métodos abstractos (obligan a sobrescribir).
        
    - Métodos concretos (ya implementados, opcionales de sobrescribir).
        
- Evitar **herencia demasiado profunda**, ya que complica la lectura y mantenimiento.
    

---

## 🔹 Errores comunes

❌ Intentar **instanciar una clase abstracta**:

```java
Figura f = new Figura(); // ERROR
```

❌ Olvidar sobrescribir los métodos abstractos → error de compilación.

❌ Darle cuerpo a un método abstracto → no permitido.

---

## 🔹 Ejemplo UML simplificado

```
Figura (abstract)
 ├── area(): double (abstract)
 └── color: String
     ↑
     └── Circulo
           ├── radio: double
           └── area(): double
```

---

# ✅ Observaciones

- Las **clases abstractas** son ideales cuando queremos definir una **base común con comportamiento parcial**.
    
- A diferencia de las **interfaces**, pueden tener **atributos y métodos implementados**.
    
- Usarlas evita duplicar lógica y fuerza a las subclases a cumplir un contrato.
    
- Una buena práctica: mantener la abstracción simple, sin herencias demasiado profundas.
    

---
