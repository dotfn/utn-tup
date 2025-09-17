# 📘 Clase 9 – La clase `Object` en Java

---

## 🔹 La clase `Object`

- Es la **clase padre de todas las clases en Java**.  
- Toda clase hereda implícitamente de `Object`.  
- **Universalidad**: todas las clases tienen un conjunto mínimo de métodos.  
- **Polimorfismo**: cualquier objeto puede tratarse como tipo `Object`.  

👉 Esto permite, por ejemplo, almacenar cualquier objeto en una colección de tipo `Object[]`.

---

## 🔹 Métodos principales de `Object`

| Método       | Descripción |
|--------------|-------------|
| `getClass()` | Retorna un objeto `Class` con información de la clase (nombre, superclase, interfaces). No puede sobrescribirse (`final`). |
| `equals()`   | Compara este objeto con otro. Por defecto, compara referencias (identidad). Puede sobrescribirse para comparar valores. |
| `hashCode()` | Devuelve un número entero usado en colecciones basadas en tablas hash. Debe ser consistente con `equals()`. |
| `toString()` | Retorna una representación en cadena del objeto. Por defecto, nombre de clase + hash. Se sobrescribe para dar información más útil. |

---

## 🔹 El método `equals()`

- **Por defecto** compara referencias (si apuntan al mismo objeto en memoria).  
- **Sobrescritura**: se redefine para comparar **contenido** en vez de referencias.  

### Cuándo sobrescribirlo
✔ Cuando queremos comparar valores (ejemplo: dos `Persona` con mismo DNI deben ser iguales).  
❌ No cuando cada instancia debe ser única (ejemplo: enums).  

### Cómo sobrescribirlo correctamente
1. Comprobar si la referencia es al mismo objeto (`==`).  
2. Verificar que no sea `null` y que sea del mismo tipo (`instanceof`).  
3. Castear al tipo correcto.  
4. Comparar atributos significativos.  

```java
@Override
public boolean equals(Object o) {
    if (this == o) return true;
    if (!(o instanceof Persona)) return false;
    Persona p = (Persona) o;
    return dni == p.dni && nombre.equals(p.nombre);
}
````

---

## 🔹 El método `hashCode()`

- Relacionado con estructuras como `HashSet`, `HashMap`.
    
- **Regla fundamental**:
    
    - Si `a.equals(b) == true`, entonces `a.hashCode() == b.hashCode()`.
        
    - Si `a.equals(b) == false`, pueden tener el mismo hash (colisión), pero se recomienda minimizarlas.
        

### Sobrescritura básica

```java
@Override
public int hashCode() {
    return Objects.hash(dni, nombre);
}
```

✔ Siempre sobrescribir `hashCode()` cuando se sobrescribe `equals()`.

---

## 🔹 El método `toString()`

- Por defecto: `"NombreClase@hashcodeHex"`.
    
- Sobrescribirlo para mostrar información significativa.
    

```java
@Override
public String toString() {
    return "Persona{dni=" + dni + ", nombre='" + nombre + "'}";
}
```

---

## 🔹 Ejemplo integral

```java
class Persona {
    private int dni;
    private String nombre;

    public Persona(int dni, String nombre) {
        this.dni = dni;
        this.nombre = nombre;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Persona)) return false;
        Persona p = (Persona) o;
        return dni == p.dni && nombre.equals(p.nombre);
    }

    @Override
    public int hashCode() {
        return Objects.hash(dni, nombre);
    }

    @Override
    public String toString() {
        return "Persona{dni=" + dni + ", nombre='" + nombre + "'}";
    }
}
```

---

## 🔹 Referencias polimórficas y `Object`

- Una referencia `Object` puede apuntar a cualquier objeto.
    

```java
Object o1 = new Persona(123, "Ana");
Object o2 = new String("Hola");
```

- Problema: al tratar todo como `Object`, se pierde la “esencia” del objeto (sus métodos propios).
    

---

## 🔹 Casting (casteo de tipos)

- Para recuperar el tipo original se usa **casting**.
    
- Riesgo: si el objeto no es del tipo esperado → `ClassCastException`.
    

```java
Object o = new Persona(456, "Luis");

// Casting explícito
Persona p = (Persona) o;
System.out.println(p.getNombre());
```

---

## 🔹 Uso de `instanceof`

- Para evitar errores en el casting:
    

```java
if (o instanceof Persona) {
    Persona p = (Persona) o;
    System.out.println(p.getNombre());
}
```

---

# ✅ Observaciones

- **`Object` es la raíz de todo en Java**: conocer sus métodos es clave para trabajar con colecciones y polimorfismo.
    
- Siempre que se sobrescriba `equals()`, **también sobrescribir `hashCode()`**.
    
- **Sobrescribir `toString()`** mejora la depuración y el logging.
    
- El uso de `Object` como referencia genérica es poderoso pero puede ocultar el verdadero tipo → se recomienda acompañarlo de `instanceof`.
    

---
