# 📘 Clase 10 – La clase `enum` en Java

---

## 🔹 ¿Qué es un `enum`?

- `enum` es una **palabra reservada** que define un **tipo especial de clase**.  
- Siempre extiende de `java.lang.Enum`.  
- **Restringe los valores posibles** que puede tomar una variable.  
- Garantiza un **tipo seguro** → una variable `enum` solo puede tomar valores definidos dentro de la enumeración.  

👉 Ideal cuando se conoce de antemano un conjunto fijo de valores.

---

## 🔹 Ventajas de usar `enum`

- Documenta la **lista de valores válidos** de forma explícita.  
- Evita comportamientos inesperados al recibir valores inválidos.  
- Verificación en **tiempo de compilación**.  
- Se comporta como un **singleton por constante**: cada valor tiene una única instancia en la JVM.  

---

## 🔹 Declaración básica de un `enum`

```java
enum Dia {
    LUNES, MARTES, MIERCOLES, JUEVES, VIERNES, SABADO, DOMINGO
}

public class Main {
    public static void main(String[] args) {
        Dia d = Dia.LUNES;
        System.out.println(d); // LUNES
    }
}
````

📌 Convención: los valores de un `enum` se escriben en **MAYÚSCULAS**.

---

## 🔹 `enum` con campos y constructores

- Un `enum` puede tener **atributos, constructores y métodos**.
    
- El constructor siempre es **privado** (implícitamente).
    
- Cada constante puede tener **estado y comportamiento**.
    

```java
enum Color {
    ROJO("Rojo fuerte"),
    VERDE("Verde claro"),
    AZUL("Azul profundo");

    private final String descripcion;

    // Constructor
    private Color(String descripcion) {
        this.descripcion = descripcion;
    }

    public String getDescripcion() {
        return descripcion;
    }
}

public class Main {
    public static void main(String[] args) {
        System.out.println(Color.ROJO.getDescripcion()); // Rojo fuerte
    }
}
```

---

## 🔹 Métodos en `enum`

- Puede incluir métodos **concretos** o **abstractos**.
    
- Si un método es abstracto, cada constante debe implementarlo.
    

```java
enum Operacion {
    SUMA {
        @Override
        public int aplicar(int a, int b) { return a + b; }
    },
    RESTA {
        @Override
        public int aplicar(int a, int b) { return a - b; }
    };

    public abstract int aplicar(int a, int b);
}

public class Main {
    public static void main(String[] args) {
        System.out.println(Operacion.SUMA.aplicar(3, 4)); // 7
    }
}
```

---

## 🔹 Métodos automáticos de `Enum`

Al declarar un `enum`, el compilador agrega automáticamente:

- `values()` → retorna un array con todas las constantes en orden de declaración.
    
- `ordinal()` → retorna la posición (0-based).
    
- `name()` → retorna el nombre en forma de `String`.
    

```java
for (Dia d : Dia.values()) {
    System.out.println(d + " en posición " + d.ordinal());
}
```

---

## 🔹 Uso en `switch`

Los `enum` son ideales en `switch` gracias a su **naturaleza limitada**:

```java
Dia dia = Dia.VIERNES;

switch (dia) {
    case LUNES: System.out.println("Inicio de semana"); break;
    case VIERNES: System.out.println("Casi fin de semana"); break;
    case SABADO: case DOMINGO:
        System.out.println("Es fin de semana");
        break;
}
```

---

## 🔹 Comparación con `==`

- Cada constante de un `enum` es **única** → se puede comparar con `==`.
    
- También funciona con `equals()`, pero `==` es suficiente y más seguro.
    

```java
Dia d1 = Dia.LUNES;
Dia d2 = Dia.LUNES;

System.out.println(d1 == d2); // true
```

⚠️ Si la referencia es `null` y se usa `==`, no hay problema.  
Pero si se llama a `equals()` sobre `null` → lanza `NullPointerException`.

---

# ✅ Observaciones

- Los `enum` no solo reemplazan a las **constantes tradicionales (`final static`)**, sino que las mejoran con tipado seguro.
    
- Es posible enriquecerlos con **atributos, métodos y comportamientos personalizados**.
    
- Usarlos mejora la legibilidad y previene errores por valores inválidos.
    
- Son muy útiles en **switch**, **APIs públicas** y para modelar **estados o conjuntos finitos de valores**.
    

---

```

¿Querés que también te prepare un **ejemplo UML** mostrando un `enum` con atributos y métodos, como `Color` con su campo `descripcion` y `getDescripcion()`?
```