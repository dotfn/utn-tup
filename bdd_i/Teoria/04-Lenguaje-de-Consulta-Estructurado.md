# 📚 Base de Datos I – Clase 4

## Lenguaje de Consulta Estructurado (SQL)

---

## 📝 Temas a Desarrollar

- ¿Qué es SQL?
    
- Instalación de MySQL Workbench
    
- Tipos de datos en SQL
    
- Tipos de sentencias (DDL y DML)
    
- Conociendo MySQL Workbench
    
- Creando nuestra primera base de datos
    
- Modificando / Eliminando tablas
    

---

## 🔎 ¿Qué es SQL?

**SQL (Structured Query Language)** es un lenguaje de consultas que permite:

- Acceder
    
- Manipular
    
- Descargar datos de una base de datos
    

Se utiliza en la mayoría de empresas que manejan **bases de datos relacionales**.  
Es capaz de realizar **cálculos avanzados y álgebra**.  
Es, históricamente, el lenguaje de consultas más usado.

---

## 💻 Instalación de MySQL Workbench

- [📥 Link de descarga](https://dev.mysql.com/downloads/installer/)
    
- [📑 Guía de instalación](https://drive.google.com/file/d/1Hc9vmvdJf1q8YwemJ5gTgICeX61u390h/view)
    

> ⚠️ Observación: Es recomendable instalar también el **MySQL Server** junto con Workbench, ya que este último es solo el cliente gráfico.

---

## 🔠 Tipos de Datos en SQL

### 1. Cadenas de texto

- `CHAR(n)` → longitud fija
    
- `VARCHAR(n)` → longitud variable
    
- `TEXT` → texto largo
    

### 2. Numéricos

- `INT` / `INTEGER`
    
- `DECIMAL(p,s)`
    
- `FLOAT`
    
- `DOUBLE`
    

### 3. Fechas

- `DATE` (AAAA-MM-DD)
    
- `TIME` (HH:MM:SS)
    
- `DATETIME` (AAAA-MM-DD HH:MM:SS)
    
- `TIMESTAMP`
    

> 💡 Consejo: siempre elegir el tipo de dato más **ajustado a la necesidad** para optimizar el almacenamiento.

---

## 🛠️ Tipos de Sentencias en SQL

### 📌 Lenguaje de Definición de Datos (DDL)

Permite **crear y definir** bases de datos, campos e índices.

- `CREATE` → crear nuevas tablas, campos e índices.
    
- `DROP` → eliminar tablas e índices.
    
- `ALTER` → modificar tablas existentes.
    

📍 **Ejemplo DDL:**

```sql
CREATE TABLE Cliente (
  id INT AUTO_INCREMENT PRIMARY KEY,
  nombre VARCHAR(50) NOT NULL,
  email VARCHAR(100) UNIQUE
);
```

---

### 📌 Lenguaje de Manipulación de Datos (DML)

Permite **consultar y modificar** registros de las tablas.

- `SELECT` → consultar registros.
    
- `INSERT` → insertar nuevos datos.
    
- `UPDATE` → modificar datos existentes.
    
- `DELETE` → eliminar registros.
    

📍 **Ejemplo DML:**

```sql
INSERT INTO Cliente (nombre, email) 
VALUES ('Juan Perez', 'juanperez@mail.com');

SELECT * FROM Cliente;

UPDATE Cliente SET email = 'nuevo@mail.com' WHERE id = 1;

DELETE FROM Cliente WHERE id = 1;
```

---

## 🖥️ Conociendo MySQL Workbench

Es la herramienta que usaremos en las clases prácticas para:

- Modelar bases de datos (DER)
    
- Ejecutar consultas SQL
    
- Administrar usuarios, permisos y conexiones
    

---

## 🏗️ Creando Nuestra Primera Base de Datos

📍 **Ejemplo:**

```sql
CREATE DATABASE tienda;
USE tienda;
```

> ⚠️ Observación: siempre indicar con `USE` la base de datos con la que queremos trabajar.

---

## 📋 Definición y Creación de Tablas

En SQL podemos aplicar **restricciones (constraints)** a las columnas:

- `DEFAULT` → valor por defecto
    
- `PRIMARY KEY` → clave primaria
    
- `UNIQUE` → valores únicos
    
- `FOREIGN KEY` → clave foránea
    
- `NOT NULL` → no admite valores nulos
    
- `AUTO_INCREMENT` → incremento automático
    

📍 **Ejemplo con restricciones:**

```sql
CREATE TABLE Producto (
  id INT AUTO_INCREMENT PRIMARY KEY,
  nombre VARCHAR(100) NOT NULL,
  precio DECIMAL(10,2) NOT NULL DEFAULT 0.0,
  stock INT NOT NULL,
  categoria_id INT,
  FOREIGN KEY (categoria_id) REFERENCES Categoria(id)
);
```

---

## 🗑️ Consultas para Borrar y Actualizar Tablas

### DROP TABLE

Elimina una tabla **y todos sus registros asociados**.

📍 Ejemplo:

```sql
DROP TABLE Producto;
```

⚠️ Mucho cuidado al usar este comando: puede afectar otras tablas enlazadas mediante claves foráneas.

---

### ALTER TABLE

Permite **modificar una tabla ya creada**.

📍 Ejemplo:

```sql
ALTER TABLE Cliente ADD telefono VARCHAR(20);

ALTER TABLE Cliente MODIFY email VARCHAR(150);

ALTER TABLE Cliente DROP COLUMN telefono;
```

---

## 💡 Observaciones Útiles

- Siempre hacer **backups** antes de usar `DROP` o `ALTER`.
    
- SQL es **case-insensitive** para comandos (`SELECT`, `FROM`), pero no para datos (`'Juan'` ≠ `'juan'`).
    
- MySQL Workbench permite **visualizar resultados de las consultas** y exportarlos fácilmente.
    

---
