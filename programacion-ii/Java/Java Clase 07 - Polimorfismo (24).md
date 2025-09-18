# 📘 Clase 7 – Polimorfismo en Java

---

## 🔹 ¿Qué es el polimorfismo?

- Es la capacidad de una **variable, método u objeto** de **tomar múltiples formas**.  
- Permite escribir programas **flexibles, genéricos, reutilizables y fáciles de extender**.  

👉 En POO, el polimorfismo es lo que da verdadero poder a la **herencia** y la **abstracción**.

---

## 🔹 Tipos de polimorfismo

1. **Polimorfismo estático** (sobrecarga de métodos).  
2. **Polimorfismo dinámico** (sobrescritura de métodos, variables polimórficas, sustitución).  

---

## 🔹 Polimorfismo estático – Sobrecarga de métodos

- Una clase puede tener varios métodos con el **mismo nombre** pero **diferentes parámetros**.  
- El tipo de retorno **no influye** en la sobrecarga.  
- El compilador decide **en tiempo de compilación** cuál método invocar.  

```java
class Calculadora {
    int sumar(int a, int b) { return a + b; }
    double sumar(double a, double b) { return a + b; }
    int sumar(int a, int b, int c) { return a + b + c; }
}

public class Main {
    public static void main(String[] args) {
        Calculadora calc = new Calculadora();
        System.out.println(calc.sumar(2, 3));        // 5
        System.out.println(calc.sumar(2.5, 3.1));    // 5.6
        System.out.println(calc.sumar(1, 2, 3));     // 6
    }
}
````

📌 También puede darse en clases hijas (se diferencia de la sobrescritura en que **cambia la lista de parámetros**).

---

## 🔹 Polimorfismo dinámico – Enlace dinámico

- Está ligado a:
    
    - **Herencia**
        
    - **Sobrescritura de métodos**
        
    - **Variables polimórficas**
        
    - **Sustitución**
        

### Sustitución y variables polimórficas

- Una variable de tipo **superclase** puede contener objetos de cualquier **subtipo**.
    
- Esto permite usar un mismo nombre de variable para múltiples formas.
    

```java
Animal a = new Perro();   // válido
Animal b = new Gato();    // válido

a.hacerSonido(); // Guau guau
b.hacerSonido(); // Miau
```

👉 Se ejecuta el método **según el tipo dinámico** del objeto en tiempo de ejecución, no según el tipo estático de la variable.

---

## 🔹 Relación entre sustitución, sobrescritura y polimorfismo dinámico

- **Sobrescritura** → redefine un método en la subclase con la misma firma.
    
- **Sustitución** → usar un objeto de una subclase donde se espera la superclase.
    
- **Polimorfismo dinámico** → el método que se ejecuta se decide **en tiempo de ejecución** según el tipo real del objeto.
    

---

## 🔹 Límite de la sustitución

- Solo se pueden invocar métodos **definidos en la superclase** (tipo estático).
    
- Aunque en tiempo de ejecución se use la versión sobrescrita de la subclase.
    

```java
Animal a = new Perro();
a.hacerSonido();  // válido (método definido en Animal, sobrescrito en Perro)
a.ladrar();       // ❌ error: "ladrar" no existe en Animal
```

---

## 🔹 Casting o enmascaramiento de tipos

Cuando necesitamos usar métodos específicos de la subclase que no existen en la superclase → **cast explícito**.

```java
Animal a = new Perro();
Perro p = (Perro) a; // casteo
p.ladrar();          // ahora sí válido
```

✔️ El objeto no cambia, solo la referencia.  
✔️ Si el tipo real no coincide → `ClassCastException`.  
✔️ Se recomienda comprobar con `instanceof`:

```java
if (a instanceof Perro) {
    ((Perro) a).ladrar();
}
```

---

## 🔹 Diferencias entre polimorfismo estático y dinámico

|Característica|Polimorfismo Estático (Sobrecarga)|Polimorfismo Dinámico (Sobrescritura)|
|---|---|---|
|Momento de decisión|Tiempo de compilación|Tiempo de ejecución|
|Parámetros|Diferentes|Mismos (misma firma)|
|Tipo de retorno|No influye|Debe ser igual o subtipo|
|Relación con herencia|No requiere|Requiere|

---

# ✅ Observaciones

- **El polimorfismo estático** mejora la legibilidad y reutilización, pero no depende de herencia.
    
- **El polimorfismo dinámico** es el que potencia la herencia, permitiendo sustituir subclases por superclases sin perder comportamiento específico.
    
- **Usar `instanceof` + casting con moderación**: abusar de esto rompe el principio de diseño polimórfico.
    
- Una buena práctica es diseñar **interfaces o clases abstractas** que permitan aprovechar sustitución y sobrescritura de forma natural.
    

---

