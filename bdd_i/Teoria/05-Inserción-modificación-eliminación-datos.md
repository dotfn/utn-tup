# 📚 Base de Datos I – Clase 5

## Inserción, modificación y eliminación de datos

---

## 📝 Temas a Desarrollar

- Insertando registros en nuestras tablas
    
- Actualizando registros
    
- Eliminando registros
    

---

## 🔹 Insertar Registros en una Tabla

### 📌 Comando: `INSERT INTO`

Se utiliza para añadir registros a una tabla.

👉 Los valores deben respetar **el mismo orden de los atributos** definidos en el `CREATE TABLE`.

### ✅ Opción 1: Insertando todos los valores

```sql
INSERT INTO Cliente 
VALUES (1, 'Juan Perez', 'juan@mail.com', '2025-09-10');
```

### ✅ Opción 2: Insertando en columnas específicas

```sql
INSERT INTO Cliente (nombre, email) 
VALUES ('María Gómez', 'maria@mail.com');
```

> 💡 Observación: si la tabla tiene una columna `AUTO_INCREMENT`, no es necesario especificarla en el `INSERT`.

---

## 🔹 Actualizar Registros en una Tabla

### 📌 Comando: `UPDATE`

Permite modificar los valores de uno o más registros seleccionados.

```sql
UPDATE Cliente 
SET email = 'nuevo@mail.com' 
WHERE id = 1;
```

⚠️ Importante: **Siempre usar `WHERE`**.  
Si se omite, se actualizarán **todos los registros** de la tabla.

---

## 🔹 Borrar Registros en una Tabla

### 📌 Comando: `DELETE`

Elimina registros de una tabla.

```sql
DELETE FROM Cliente 
WHERE id = 2;
```

- Si no se incluye `WHERE`, se borrarán **todos los registros**.
    
- La tabla queda vacía pero sigue existiendo en la base de datos.
    

---

## 🔹 Uso de `ON DELETE CASCADE`

Cuando existe una **relación con clave foránea**, se puede usar esta opción para mantener la **integridad referencial**.

Ejemplo:

```sql
CREATE TABLE Fabricante (
  id_fabricante INT PRIMARY KEY,
  nombre VARCHAR(100)
);

CREATE TABLE Producto (
  id_producto INT PRIMARY KEY,
  nombre VARCHAR(100),
  id_fabricante INT,
  FOREIGN KEY (id_fabricante) REFERENCES Fabricante(id_fabricante) ON DELETE CASCADE
);
```

### 🔄 Funcionamiento

- Si eliminamos un fabricante, automáticamente se eliminan todos sus productos asociados.
    

```sql
DELETE FROM Fabricante WHERE id_fabricante = 1;
```

Esto borrará también todos los productos vinculados a `id_fabricante = 1`.

---

## ✅ Ventajas de `ON DELETE CASCADE`

- Mantenimiento automático de la **integridad referencial**.
    
- Código más limpio (no requiere múltiples `DELETE`).
    

---

## ⚠️ Consideraciones

- Usar con **precaución**: puede eliminar muchos registros en cascada.
    
- Tener en cuenta la **dependencia de múltiples tablas**: un solo `DELETE` en la tabla principal puede afectar gran parte de la base de datos.
    

---

## 💡 Observaciones Útiles

- Antes de borrar datos importantes, hacer un **backup**.
    
- En bases de datos críticas, es recomendable desactivar `ON DELETE CASCADE` y manejar manualmente los borrados.
    
- Practicar siempre con tablas de prueba antes de aplicarlo en entornos productivos.
    

---
