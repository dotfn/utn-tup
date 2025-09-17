
# 📘 Clase 12 – Colecciones en Java: `Collection`, `List`, `Queue`, `ArrayList`, `Vector`, `Stack`, `LinkedList` y `Comparable`

---

## 🔹 API `Collection`

La **API Collection** es un conjunto de interfaces y clases para **almacenar y manipular conjuntos de objetos**.

### Ventajas
- Proporciona **métodos y operaciones comunes** para cualquier colección.  
- **Reduce esfuerzos** de programación: incluye algoritmos de búsqueda, inserción, eliminación y ordenación.  
- Ofrece **implementaciones de alta performance**.  
- Fomenta la **reutilización del software**.  

👉 Ejemplo: olvidarse de implementar ordenamientos manuales gracias a `Collections.sort()`.

---

## 🔹 Interfaz `Collection`

- Es la **raíz de todas las interfaces de colecciones** (`Set`, `List`, `Queue`).  
- Define las **operaciones básicas** comunes.  
- No se pueden crear objetos de tipo `Collection` directamente (es una interfaz).  

### Métodos de instancia principales
- `add(E e)`  
- `remove(Object o)`  
- `size()`  
- `isEmpty()`  
- `contains(Object o)`  
- `iterator()`  
- `clear()`  
- `addAll(Collection c)`  
- `toArray()`

### Métodos estáticos principales
- `Collections.addAll(lista, e1, e2...)`  
- `Collections.copy(destino, origen)`  
- `Collections.frequency(c, obj)`  
- `Collections.max(c)` / `Collections.min(c)`  
- `Collections.reverse(lista)`

---

## 🔹 Interfaz `List`

- Representa una **colección ordenada y secuencial**.  
- Permite **acceder mediante índices**.  
- Acepta **elementos duplicados**.  

### Implementaciones comunes
- `ArrayList`  
- `LinkedList`  
- `Vector`  
- `Stack`

### Métodos principales (además de los de `Collection`)
- `add(int index, E element)`  
- `remove(int index)`  
- `get(int index)`  
- `set(int index, E element)`  
- `indexOf(Object o)`  
- `lastIndexOf(Object o)`  
- `subList(int inicio, int fin)`  
- `listIterator()`

---

## 🔹 `ArrayList`

- Similar a un array, pero **dinámico**.  
- **No necesita tamaño inicial**: crece automáticamente.  

### Ventajas
- Acceso rápido por índice.  
- Estructura dinámica.  

### Desventajas
- **Añadir/eliminar en medio es lento** (se deben mover elementos).  
- No está sincronizado → cuidado con multihilos.  

### Ejemplo
```java
ArrayList<String> lista = new ArrayList<>();
lista.add("A");
lista.add("B");
lista.add(1, "C"); // Inserta en índice 1
System.out.println(lista); // [A, C, B]
````

---

## 🔹 `Vector`

- Similar a `ArrayList`, pero **sincronizado** (seguro en multihilos).
    
- Redimensionamiento distinto: **duplica** su tamaño.
    

```java
Vector<Integer> v = new Vector<>(10, 5);
v.add(1);
v.add(2);
System.out.println(v.elementAt(0)); // 1
```

---

## 🔹 `Stack`

- Subclase de `Vector`.
    
- Implementa una **pila (LIFO)**.
    

### Operaciones principales

- `push()` → agrega en la cima.
    
- `pop()` → elimina el último elemento.
    
- `peek()` → consulta el último.
    
- `empty()` → verifica si está vacía.
    
- `search(obj)` → devuelve la posición de un elemento.
    

```java
Stack<String> pila = new Stack<>();
pila.push("A");
pila.push("B");
System.out.println(pila.pop()); // B
```

---

## 🔹 `LinkedList`

- Basada en una **lista doblemente enlazada**.
    
- Implementa `List` y también `Deque` (doble cola).
    

### Comparación `LinkedList` vs `ArrayList`

- **ArrayList** → mejor para búsquedas por índice.
    
- **LinkedList** → mejor para inserciones/eliminaciones frecuentes.
    

### Métodos propios

- `addFirst(e)`, `addLast(e)`
    
- `getFirst()`, `getLast()`
    
- `removeFirst()`, `removeLast()`
    

```java
LinkedList<String> ll = new LinkedList<>();
ll.add("A");
ll.addFirst("B");
System.out.println(ll); // [B, A]
```

---

## 🔹 Interfaz `Comparable`

- Permite definir el **orden natural** de los objetos.
    
- Usada en estructuras como `TreeSet`, `TreeMap`, y algoritmos como `sort()`.
    

### Método único

```java
int compareTo(T o)
```

- Devuelve:
    
    - `< 0` si el objeto actual es menor.
        
    - `0` si son iguales.
        
    - `> 0` si es mayor.
        

### Ejemplo

```java
class Persona implements Comparable<Persona> {
    String nombre;
    int edad;

    Persona(String n, int e) { nombre = n; edad = e; }

    @Override
    public int compareTo(Persona p) {
        return Integer.compare(this.edad, p.edad);
    }
}

List<Persona> lista = new ArrayList<>();
lista.add(new Persona("Ana", 25));
lista.add(new Persona("Luis", 30));
Collections.sort(lista);
```

---

## 🔹 Interfaz `Queue`

- Representa una **cola FIFO** (first in – first out).
    
- Elementos se agregan por un extremo y se sacan por el otro.
    

### Métodos principales

- `offer(E e)` → inserta si hay espacio.
    
- `poll()` → obtiene y elimina el primero.
    
- `peek()` → obtiene el primero sin eliminarlo.
    

```java
Queue<String> cola = new LinkedList<>();
cola.offer("A");
cola.offer("B");
System.out.println(cola.poll()); // A
```

---

# ✅ Observaciones

- La API `Collection` abstrae detalles y facilita la programación con estructuras de datos.
    
- `List` → orden y acceso por índice.
    
- `ArrayList` vs `LinkedList`: elegir según si se prioriza acceso aleatorio o inserciones frecuentes.
    
- `Vector` y `Stack` están sincronizados, pero hoy se recomienda usar alternativas de `java.util.concurrent`.
    
- `Comparable` es clave para ordenar objetos personalizados.
    
- `Queue` implementa colas, fundamentales en programación concurrente y estructuras de datos.
    

---
