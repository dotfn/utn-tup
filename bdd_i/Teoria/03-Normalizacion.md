# 📚 Base de Datos I – Clase 3

## Normalización de Tablas

---

## 📝 Temas a Desarrollar

- Definición y objetivos
    
- Requisitos y reglas
    
- Primera Forma Normal (1FN)
    
- Segunda Forma Normal (2FN)
    
- Tercera Forma Normal (3FN)
    

---

## 🔎 ¿Qué es la Normalización?

La **normalización** es el proceso de organizar los datos en una base de datos para **reducir la redundancia** y **mejorar la integridad de los datos**.

### 🎯 Objetivos

- Eliminar duplicaciones.
    
- Reducir anomalías de inserción, actualización y eliminación.
    
- Facilitar la consistencia y mantenimiento de los datos.
    

### ✅ Beneficios

- Mejora la eficiencia en el almacenamiento.
    
- Simplifica el mantenimiento.
    
- Facilita consultas y actualizaciones.
    

---

## 📏 Requisitos de la Normalización

Para que una tabla esté correctamente normalizada debe cumplir con estas reglas:

- Cada tabla debe tener un **nombre único**.
    
- No puede haber **dos filas iguales**.
    
- No se permiten **duplicados**.
    
- Todos los valores en una columna deben ser **del mismo tipo de dato**.
    

---

## 📚 Reglas o Niveles de Normalización

Las formas normales más utilizadas son:

1. **Primera Forma Normal (1FN)**
    
2. **Segunda Forma Normal (2FN)**
    
3. **Tercera Forma Normal (3FN)**
    

> 🔎 Aunque existen niveles más avanzados (BCNF, 4FN, 5FN…), en la práctica la **3FN es suficiente** para la mayoría de los sistemas.

---

## 🔹 Primera Forma Normal (1FN)

**Definición:**  
Una tabla está en 1FN si cumple con:

- Todos los atributos tienen valores **atómicos (indivisibles)**.
    
- Cada columna contiene valores de **un único tipo de dato**.
    
- Cada registro es **único**.
    

---

### 📍 Ejemplo: Tabla no normalizada

| PedidoID | Cliente | Productos        | Cantidades |
| -------- | ------- | ---------------- | ---------- |
| 1        | Juan    | Teclado, Mouse   | 2, 1       |
| 2        | María   | Monitor          | 1          |
| 3        | Juan    | Teclado, Monitor | 1, 1       |

### ❌ Problemas

- No atomización de los campos (productos en una sola celda).
    
- No existe un registro único confiable.
    
- Dependencia parcial.
    

---

### ✅ Transformación a 1FN

| PedidoID | Cliente | Producto  | Cantidad |
|----------|---------|-----------|----------|
| 1        | Juan    | Teclado   | 2        |
| 1        | Juan    | Mouse     | 1        |
| 2        | María   | Monitor   | 1        |
| 3        | Juan    | Teclado   | 1        |
| 3        | Juan    | Monitor   | 1        |

---

## 🔹 Concepto de Dependencia Funcional

- Una **dependencia funcional** se representa como:
    
    ```
    X → Y
    ```
    
    Significa que el valor de `X` **determina** un único valor de `Y`.
    

Ejemplo:

- En una tabla de alumnos:
    
    ```
    DNI → Nombre
    ```
    
    Un DNI determina exactamente un nombre.
    

---

## 🔹 Segunda Forma Normal (2FN)

**Definición:**  
Una tabla está en 2FN si:

- Cumple con 1FN.
    
- Se eliminan dependencias parciales.
    
- Se crean tablas separadas para conjuntos de valores repetidos y se relacionan con **claves externas**.
    

---

### 📍 Ejemplo

De la tabla **Pedidos (1FN)** podemos separar:

**Tabla Pedido**

```plaintext
| PedidoID | ClienteID |
|----------|-----------|
| 1        | 101       |
| 2        | 102       |
| 3        | 101       |
```

**Tabla DetallePedido**

```plaintext
| PedidoID | Producto  | Cantidad |
|----------|-----------|----------|
| 1        | Teclado   | 2        |
| 1        | Mouse     | 1        |
| 2        | Monitor   | 1        |
| 3        | Teclado   | 1        |
| 3        | Monitor   | 1        |
```

---

## 🔹 Tercera Forma Normal (3FN)

**Definición:**  
Una tabla está en 3FN si:

- Cumple con 2FN.
    
- **No tiene dependencias transitivas**, es decir, cada columna no clave depende **solo de la clave primaria** y no de otras columnas.
    

---

### 📍 Ejemplo

En la tabla **Pedido**, si guardamos directamente el **Nombre del Cliente**, eso introduce dependencia transitiva:

```
PedidoID → ClienteID → NombreCliente
```

### ✅ Transformación a 3FN

**Tabla Pedido**

```plaintext
| PedidoID | ClienteID |
|----------|-----------|
| 1        | 101       |
| 2        | 102       |
| 3        | 101       |
```

**Tabla Cliente**

```plaintext
| ClienteID | Nombre   |
|-----------|----------|
| 101       | Juan     |
| 102       | María    |
```

**Tabla DetallePedido**

```plaintext
| PedidoID | Producto  | Cantidad |
|----------|-----------|----------|
| 1        | Teclado   | 2        |
| 1        | Mouse     | 1        |
| 2        | Monitor   | 1        |
| 3        | Teclado   | 1        |
| 3        | Monitor   | 1        |
```

---

## ❓ ¿Se puede seguir normalizando?

Sí. Existen formas más avanzadas como **BCNF, 4FN y 5FN**, pero en la mayoría de los sistemas **no son necesarias**.

---

## 💡 Observaciones Útiles

- Siempre es mejor **comenzar con la 1FN** y avanzar gradualmente.
    
- No sobre-normalizar: demasiadas tablas pueden volver el sistema complejo e ineficiente.
    
- Usar diagramas (DER) ayuda a visualizar dependencias y relaciones.
    

---

¿Querés que arme también un **esquema SQL de creación de tablas** con este ejemplo de pedidos, clientes y detalle de pedidos (ya en 3FN) para que quede como referencia práctica en el mismo archivo?