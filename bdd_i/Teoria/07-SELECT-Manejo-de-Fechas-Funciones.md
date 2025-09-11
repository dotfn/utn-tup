# 📚 Base de Datos I – Clase 7

## SELECT, Manejo de Fechas y Funciones


---

## 📝 Temas a Desarrollar

- Cláusula `SELECT`
    
- Operadores relacionales y lógicos
    
- Consultas y filtrado de registros
    
- Manejo de fechas
    
- Operadores de SQL
    
- Funciones de agregación
    

---

## 🔹 Mostrar y Filtrar Registros de una Tabla

### 📌 Comando: `SELECT`

La sentencia `SELECT` permite:

- Mostrar registros de la base de datos.
    
- Seleccionar una o varias columnas.
    
- Consultar una o varias tablas.
    

📍 **Ejemplo básico:**

```sql
SELECT nombre, email 
FROM Cliente;
```

📍 **Traer todos los registros:**

```sql
SELECT * 
FROM Cliente;
```

---

### 📌 `SELECT DISTINCT`

Se utiliza para traer solo **valores únicos**.

📍 Ejemplo:

```sql
SELECT DISTINCT ciudad 
FROM Cliente;
```

---

## 🔹 Operadores Relacionales

- `=` (igual)
    
- `<>` o `!=` (distinto)
    
- `<` (menor)
    
- `<=` (menor o igual)
    
- `>` (mayor)
    
- `>=` (mayor o igual)
    

📍 Ejemplo:

```sql
SELECT * 
FROM Producto 
WHERE precio >= 100;
```

---

## 🔹 Operadores Lógicos

- `AND` → todas las condiciones deben cumplirse
    
- `OR` → basta con que una condición se cumpla
    
- `NOT` → niega la condición
    

📍 Ejemplo:

```sql
SELECT * 
FROM Producto
WHERE precio > 100 AND stock > 5;
```

---

## 🔹 Manejo de Fechas

### 📌 Tipos de datos

- `DATE` → solo fecha (AAAA-MM-DD)
    
- `TIME` → solo hora (HH:MM:SS)
    
- `DATETIME` → fecha y hora
    

### 📌 Inserción de datos

```sql
INSERT INTO Pedido (fecha) 
VALUES (NOW());   -- fecha y hora actual
```

### 📌 Funciones comunes

- `CURDATE()` → fecha actual
    
- `CURTIME()` → hora actual
    
- `NOW()` → fecha y hora actual
    
- `DATE()` → extrae la parte de fecha de un `DATETIME`
    
- `DATEDIFF(f1,f2)` → diferencia en días entre dos fechas
    

📍 Ejemplo:

```sql
SELECT DATEDIFF('2025-12-31', CURDATE()) AS dias_restantes;
```

---

## 🔹 Operadores Propios de SQL

### 1. `BETWEEN`

Selecciona valores dentro de un rango.

```sql
SELECT * FROM Producto 
WHERE precio BETWEEN 50 AND 150;
```

---

### 2. `IN` / `NOT IN`

Comprueba si un valor pertenece a un conjunto.

```sql
SELECT * FROM Cliente 
WHERE ciudad IN ('Rosario','Córdoba');
```

---

### 3. `LIKE` / `NOT LIKE`

Busca un patrón en un texto.

- `%` → cualquier cantidad de caracteres
    
- `_` → un solo carácter
    

```sql
SELECT * FROM Cliente 
WHERE nombre LIKE 'Mar%';   -- nombres que comienzan con "Mar"
```

---

### 4. `ORDER BY`

Ordena los resultados.

```sql
SELECT * FROM Producto 
ORDER BY precio DESC;
```

---

### 5. `AS`

Asigna un alias temporal.

```sql
SELECT nombre AS Cliente, email AS Correo 
FROM Cliente;
```

---

### 6. `LIMIT`

Restringe la cantidad de resultados.

```sql
SELECT * FROM Producto 
LIMIT 5;
```

---

### 7. `ROUND`

Redondea decimales.

```sql
SELECT ROUND(precio, 2) AS precio_redondeado 
FROM Producto;
```

---

## 🔹 Funciones de Agregación

Agrupan valores de varias filas y devuelven un valor único.

- `MAX(columna)` → valor máximo
    
- `MIN(columna)` → valor mínimo
    
- `COUNT(columna)` → cantidad de filas
    
- `SUM(columna)` → suma de valores
    
- `AVG(columna)` → promedio
    

📍 Ejemplos:

```sql
SELECT MAX(precio) FROM Producto;
SELECT MIN(precio) FROM Producto;
SELECT COUNT(*) FROM Cliente;
SELECT SUM(stock) FROM Producto;
SELECT AVG(precio) FROM Producto;
```

---

## 💡 Observaciones Útiles

- Siempre usar **`WHERE`** en `UPDATE` o `DELETE` para evitar modificar/borrar todo.
    
- `DISTINCT` puede afectar el rendimiento en tablas muy grandes.
    
- `ORDER BY` sin `ASC/DESC` ordena por defecto en **ascendente**.
    
- Las funciones de agregación suelen usarse junto con `GROUP BY`.
    

---

