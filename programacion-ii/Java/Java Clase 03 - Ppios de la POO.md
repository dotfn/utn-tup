# 📘 Clase 3 – Principios de la Programación Orientada a Objetos

---

## 🔹 ¿Qué es la Programación Orientada a Objetos (POO)?

- Es un **paradigma de programación**, no un lenguaje ni una IDE.  
- Se centra en **objetos**, que son **instancias de clases**.  
- Los objetos contienen:
  - **Datos** → atributos o campos.  
  - **Comportamiento** → métodos o procedimientos.  
- A diferencia de la programación procedural (basada en funciones y scripts), la POO se enfoca en **objetos e interacciones**.

👉 Su propósito: **resolver problemas identificando entidades principales** y modelándolas en clases.

---

## 🔹 Ventajas de la POO

- **Modularidad** → organiza el código en componentes independientes y reutilizables.  
- **Abstracción** → concentra en lo esencial, ocultando detalles irrelevantes.  
- **Reutilización de código** → gracias a la herencia.  
- **Flexibilidad y mantenibilidad** → el código es más fácil de modificar y mantener.  

---

## 🔹 Los 4 Pilares de la POO

### 1. Abstracción
Proceso de identificar lo esencial y generalizar entidades.  

✔️ Pasos:
- Seleccionar características relevantes.  
- Ignorar detalles secundarios.  
- Identificar comportamientos comunes.  
- Definir entidades en su forma más esencial.  

```java
abstract class Figura {
    abstract double area();
}

class Circulo extends Figura {
    double radio;
    Circulo(double radio) { this.radio = radio; }

    @Override
    double area() { return Math.PI * radio * radio; }
}
````

🔎 **Ventajas**:

- Simplifica el diseño de sistemas complejos.
    
- Facilita el mantenimiento y comprensión del código.
    
- Incrementa la modularidad y reutilización.
    

---

### 2. Encapsulamiento

- Los **datos** y **comportamientos** de un objeto se agrupan en su núcleo.
    
- Se controla el acceso a los atributos mediante **modificadores de acceso**.
    
- Se promueve el uso de **métodos getters y setters** para interactuar con los datos.
    

```java
class CuentaBancaria {
    private double saldo;

    public double getSaldo() {
        return saldo;
    }

    public void depositar(double monto) {
        if (monto > 0) saldo += monto;
    }
}
```

---

### 3. Herencia

- Permite que una clase (hija) **herede atributos y métodos** de otra (padre).
    
- Facilita el **polimorfismo** y la organización jerárquica.
    

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
```

✔️ Ventajas:

- Evita duplicación de código.
    
- Permite crear tipos especializados a partir de clases generales.
    

---

### 4. Polimorfismo

- Capacidad de un mismo método tener **distintos comportamientos** según el objeto.
    

```java
Animal a1 = new Perro();
Animal a2 = new Gato();

a1.hacerSonido(); // Guau guau
a2.hacerSonido(); // Miau
```

- También puede aplicarse en métodos sobrecargados:
    

```java
class Calculadora {
    int sumar(int a, int b) { return a + b; }
    double sumar(double a, double b) { return a + b; }
}
```

---

## 🔹 Observaciones clave

- La **POO no es un lenguaje**, sino una forma de pensar el código.
    
- Los **4 pilares (abstracción, encapsulamiento, herencia y polimorfismo)** deben aplicarse en conjunto para lograr código más claro y flexible.
    
- En el diseño orientado a objetos, siempre es recomendable **buscar cohesión alta y bajo acoplamiento** (tema retomado en clases posteriores).
    

---
