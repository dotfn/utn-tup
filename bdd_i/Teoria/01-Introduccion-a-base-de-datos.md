
## 📌 Introducción

**Dato → Proceso → Información**

- **Dato**: elemento básico (ej: ventas diarias).
    
- **Proceso**: conjunto de acciones con inicio y fin (ej: sumar mensualmente).
    
- **Información**: resultado útil del procesamiento (ej: total vendido en agosto).
    

---

## 📂 Organización en Archivos

**Estructura**

```
Archivo → Registro → Campo
```

**Ejemplo**

- Archivo: `Empleados.dat`
    
- Registro: `Juan Pérez, 1234, RRHH`
    
- Campos: `Nombre, Legajo, Departamento`
    

### ❌ Inconvenientes

1. **Redundancia de datos**
    
    - Se repite información en distintos archivos.
        
    - Riesgo de inconsistencia.
        
    - Ejemplo: RRHH y Ventas cargan empleados por duplicado.
        
2. **Consistencia e Integridad**
    
    - Actualizaciones no sincronizadas → datos distintos para la misma entidad.
        
    - Ejemplo: “Pérez” en RRHH, “Peréz” en Ventas.
        
3. **Rigidez en la estructura**
    
    - Cambiar un campo obliga a modificar programas dependientes.
        
    - Ejemplo: agregar “correo electrónico” → reprogramar aplicaciones.
        

---

## 🗄️ Necesidad de una Base de Datos

**Antes:**

- Archivos independientes (RRHH, Ventas, Compras) con duplicación.
    

**Después:**

- Base de Datos Centralizada.
    
- Información única, actualizada en tiempo real.
    

---

## 📖 Definición

**Base de Datos (BD):**  
Conjunto organizado de datos relacionados entre sí, gestionados de forma eficiente, segura y sin redundancia.

**Características principales:**

- Datos coherentes y actualizados.
    
- Acceso concurrente multiusuario.
    
- Seguridad y control de accesos.
    
- Independencia entre datos y programas.
    

**Otras características:**

- Refleja relaciones y restricciones.
    
- Brinda acceso a datos históricos.
    
- Garantiza coherencia e integridad.
    

---
---

## ⚙️ DBMS (Sistema de Gestión de Bases de Datos)

**Definición.**  
Un **DBMS** es el conjunto de programas que administran y gestionan una base de datos, permitiendo que múltiples usuarios accedan a los mismos datos de forma segura y controlada; actúa como intermediario entre datos, usuarios y aplicaciones.

### Funciones principales

Funciones que todo DBMS debe cubrir (según el material base).

|Función|¿Para qué sirve?|Ejemplos típicos|
|---|---|---|
|**Definir datos**|Crear/alterar estructuras|Tablas, vistas, índices, tipos, restricciones|
|**Manipular datos**|Insertar, actualizar, borrar, consultar|`INSERT`, `UPDATE`, `DELETE`, `SELECT`|
|**Seguridad y permisos**|Control de acceso por usuarios/roles|Asignación/revocación de privilegios|
|**Integridad y consistencia**|Garantizar validez de la información|Restricciones, claves, checks, recuperabilidad|
|**Respaldo y recuperación**|Protección ante fallos/pérdidas|Backups, restore a punto consistente|
|**Acceso concurrente**|Coordinar múltiples usuarios a la vez|Bloqueos, control de concurrencia|
|**Transacciones**|Atomicidad de operaciones|`BEGIN … COMMIT/ROLLBACK`|

> El DBMS también mantiene **objetos del sistema** (usuarios/permisos, metadatos, estadísticas) además de los **objetos del usuario** (tablas, vistas, índices, procedimientos, funciones, triggers).

---

### Objetivos del DBMS

**Abstracción por niveles.**  
Organiza la información en **tres niveles** para separar cómo se almacenan los datos de cómo se usan.

| Nivel                | Qué describe                              | Quién lo usa  | Ejemplos                                             |
| -------------------- | ----------------------------------------- | ------------- | ---------------------------------------------------- |
| **Físico (interno)** | Almacenamiento real y acceso en disco     | Motor/DBA     | Archivos, páginas/bloques, índices, ubicación        |
| **Conceptual**       | Qué datos hay y relaciones entre ellos    | DBA/analistas | Esquema lógico, entidades, relaciones, restricciones |
| **Externo (vistas)** | Partes del sistema relevantes a un perfil | Usuarios/app  | Vistas específicas por área o rol                    |
|                      |                                           |               |                                                      |

**Independencia de datos.**

- **Física:** cambiar el **esquema físico** (bloques, longitud de registros, índices) **sin reescribir** programas de aplicación.
    
- **Lógica:** cambiar el **esquema conceptual** (campos, estructuras) **sin reescribir** programas.
    

**Calidad, seguridad y operación.**

| Objetivo                | Qué garantiza                                    | Mecanismos típicos                                 |
| ----------------------- | ------------------------------------------------ | -------------------------------------------------- |
| **Consistencia**        | Actualizaciones coherentes (sin contradicciones) | Reglas/constraints y lógica transaccional.         |
| **Seguridad**           | Protección frente a accesos indebidos y errores  | Permisos a usuarios/grupos; autenticación.         |
| **Integridad**          | Datos válidos y recuperables ante fallos         | Checks, claves, recuperación a estado consistente. |
| **Respaldo**            | Copias y restauración confiable                  | Backups/restore eficientes.                        |
| **Concurrencia**        | Acceso simultáneo sin inconsistencias            | Bloqueos, aislamiento, serialización.              |
| **Transacciones**       | Operaciones atómicas como unidad                 | `BEGIN/COMMIT/ROLLBACK`.                           |
| **Tiempo de respuesta** | Eficiencia en consultas/updates                  | Optimización de consultas y recursos.              |

---

### Concurrencia y Transacciones (mini guía operativa)

**Transacción = unidad atómica de trabajo.**  
Si falla, el sistema deja la BD como si no se hubiera ejecutado.

```sql
-- Transferencia de $1000 de la cuenta 1 a la 2
BEGIN TRANSACTION;

UPDATE cuentas SET saldo = saldo - 1000 WHERE id = 1;
UPDATE cuentas SET saldo = saldo + 1000 WHERE id = 2;

-- Si todo OK:
COMMIT;

-- Si algo falló:
-- ROLLBACK;
```

**Aislamiento (idea práctica).**  
Elegí el nivel de aislamiento apropiado para balancear integridad y rendimiento:

```sql
-- Ejemplo genérico de configuración de aislamiento
SET TRANSACTION ISOLATION LEVEL READ COMMITTED;
BEGIN TRANSACTION;
-- ... operaciones DML ...
COMMIT;
```

> El control de concurrencia evita efectos como lecturas sucias, no repetibles o fantasmas mediante bloqueos o protocolos de serialización (según motor). (Apoya el objetivo “control de la concurrencia”).

**Recuperación y respaldo.**  
El DBMS debe permitir **restaurar** la BD a un estado consistente conocido, a partir de **copias de seguridad**.

---

### Resumen operativo de DBMS

- **Puente** entre datos↔usuarios↔aplicaciones, con **múltiples funciones** críticas (definición, manipulación, seguridad, integridad, respaldo, concurrencia y transacciones).
    
- **Tres niveles** (físico, conceptual, externo) → **independencia** física y lógica.
    
- **Objetivos**: consistencia, seguridad, integridad, respaldo, concurrencia, transacciones, tiempo de respuesta.
    

---
---

## 👥 Usuarios de Bases de Datos

Un sistema de BD es utilizado por distintos perfiles, cada uno con un rol y nivel de acceso distinto.

|Tipo de Usuario|Rol principal|Ejemplos de tareas|
|---|---|---|
|**DBA (Administrador de BD)**|Configura, mantiene y protege la BD|Definir permisos, crear respaldos, optimizar consultas|
|**Programador de aplicaciones**|Desarrolla programas que acceden a la BD|CRUD en aplicaciones, reportes, integraciones|
|**Usuario final**|Usa aplicaciones para consultar/cargar datos|Alta de clientes, registrar ventas, generar reportes|

**Notas clave:**

- Cada usuario ve **solo una parte del sistema** (ej. vistas personalizadas).
    
- No todos necesitan conocer la estructura interna de la BD.
    
- Esto permite mayor **seguridad, eficiencia y simplicidad**.
    

---

## 💬 SQL (Structured Query Language)

**Definición:**  
Lenguaje estándar para **definir, manipular y administrar** datos en **bases de datos relacionales**.

- Es **declarativo**: se indica _qué_ hacer, no _cómo_.
    
- Estándar ANSI/ISO, con extensiones propias en cada motor (MySQL, SQL Server, Oracle, PostgreSQL).
    

**Principales funciones de SQL:**

1. Definir estructuras de datos (tablas, relaciones).
    
2. Manipular información almacenada.
    
3. Controlar accesos y permisos.
    
4. Gestionar transacciones.
    

---

### 🔑 Sub-lenguajes de SQL

| Sub-lenguaje | Nombre                       | Función principal            | Ejemplos                                        |
| ------------ | ---------------------------- | ---------------------------- | ----------------------------------------------- |
| **DDL**      | Data Definition Language     | Definición de estructuras    | `CREATE`, `ALTER`, `DROP`,`TRUNCATE`            |
| **DML**      | Data Manipulation Language   | Manipulación de datos        | `INSERT`, `UPDATE`, `DELETE`, `SELECT`, `MERGE` |
| **DCL**      | Data Control Language        | Control de accesos/seguridad | `GRANT`, `REVOKE`                               |
| **TCL**      | Transaction Control Language | Control de transacciones     | `COMMIT`, `ROLLBACK`, `SAVEPOINT`               |

---

### 📑 Ejemplos prácticos

**DDL – crear tabla**

```sql
CREATE TABLE empleados (
    legajo INT PRIMARY KEY,
    nombre VARCHAR(50),
    departamento VARCHAR(30)
);
```

**DML – insertar y consultar**

```sql
INSERT INTO empleados (legajo, nombre, departamento)
VALUES (1234, 'Juan Pérez', 'RRHH');

SELECT * FROM empleados WHERE departamento = 'RRHH';
```

**DCL – otorgar permisos**

```sql
GRANT SELECT, INSERT ON empleados TO usuario_rrhh;
```

**TCL – transacción básica**

```sql
BEGIN;

UPDATE cuentas SET saldo = saldo - 500 WHERE id = 1;
UPDATE cuentas SET saldo = saldo + 500 WHERE id = 2;

COMMIT;
```

---
---

## 🌐 Modelo Cliente-Servidor

**Definición:**  
Arquitectura que permite que **múltiples clientes** (aplicaciones o usuarios) accedan a una **base de datos centralizada** a través de un servidor que ejecuta el **DBMS**.

**Componentes principales:**

- **Servidor:**
    
    - Aloja la BD y el DBMS.
        
    - Controla seguridad, permisos y transacciones.
        
    - Administra acceso concurrente y realiza respaldos.
        
- **Cliente:**
    
    - Programas que consultan o modifican datos.
        
    - Ejemplo: Workbench, SQL Server Management Studio, aplicaciones web.
        
- **Software de interacción:**
    
    - Interfaces con el usuario (front-end).
        
- **Software de desarrollo:**
    
    - Herramientas para programadores (ej. frameworks, IDEs).
        

---

### 🔗 Relación Técnica – Operativa

Los niveles del DBMS se relacionan con los usuarios en este modelo:

|Nivel|Perspectiva|Herramientas típicas|
|---|---|---|
|**Físico**|Cómo se guardan los datos en disco|Motor DBMS|
|**Conceptual**|Cómo se modelan los datos|Esquemas, DBA|
|**Externo (vistas)**|Cómo los ven los usuarios finales|Workbench, aplicaciones|

**Idea clave:** el cliente ve solo la **vista externa**, mientras que el servidor administra el almacenamiento y la lógica interna.

---

## 📊 Modelos de Datos

**Definición:**  
Un **modelo de datos** es un conjunto de conceptos para describir:

- **Datos**
    
- **Relaciones**
    
- **Significado**
    
- **Reglas de consistencia**
    

**Tipos principales:**

1. **Modelos conceptuales (lógicos basados en objetos):**  
    Independientes de la tecnología. Ejemplos:
    
    - **Entidad-Relación**
        
    - Orientado a objetos
        
    - Binario
        
    - Semántico
        
2. **Modelos lógicos basados en registros:**  
    Determinan cómo se almacenan y manipulan los datos en un entorno informático. Ejemplos:
    
    - Jerárquico (IMS)
        
    - De red (Codasyl)
        
    - Relacional (Oracle, SQL Server, MySQL)
        

---
---

## 🔗 Modelo Entidad–Relación (E–R)

**Definición:**  
Modelo conceptual que representa el mundo real a través de:

- **Entidades**: objetos (reales o abstractos) de los que se guarda información.
    
- **Relaciones**: asociaciones entre entidades.
    
- **Atributos**: propiedades que describen entidades o relaciones.
    

---

### 🧩 Entidades

- **Fuertes:** existen por sí mismas.
    
    - Ej: _Alumnos, Empleados, Departamentos_.
        
- **Débiles:** dependen de otra entidad.
    
    - Ej: _Hijos de empleados_.
        

---

### 🧾 Atributos

Tipos principales:

- **Atómicos:** indivisibles.
    
    - Ej: _nombre, ciudad_.
        
- **Compuestos:** se dividen en partes más pequeñas.
    
    - Ej: _dirección → calle, número, piso_.
        
- **Multivaluados:** múltiples valores posibles.
    
    - Ej: _varios teléfonos_.
        
- **Derivados:** se calculan a partir de otros.
    
    - Ej: _edad derivada de fecha_nacimiento_.
        
- **Clave:** identifican de forma única a una entidad.
    
    - Ej: _DNI, legajo_.
        
- **Nulos:** sin valor o desconocidos.
    

Ejemplo en tabla:

|Entidad|Atributos|
|---|---|
|Cliente|id_cliente (PK), nombre, domicilio, teléfono(s), edad (derivada), email (opcional)|

---

### 🔗 Relaciones

- **Grado:** número de entidades involucradas.
    
    - Binaria (2): _Cliente – Pedido_.
        
    - Ternaria (3): _Cliente – Pago – Pedido_.
        
- **Cardinalidad:** número de ocurrencias posibles entre entidades.
    
    - 1:1 → un paciente tiene un único diagnóstico.
        
    - 1:N → una sala tiene varios pacientes, cada paciente está en una sala.
        
    - N:N → autores y libros (_un autor escribe varios libros y un libro puede tener varios autores_).
        

**Ejemplo N:N → tabla intermedia**

```sql
CREATE TABLE Autor (
    id_autor INT PRIMARY KEY,
    nombre VARCHAR(50)
);

CREATE TABLE Libro (
    id_libro INT PRIMARY KEY,
    titulo VARCHAR(100)
);

CREATE TABLE Escribe (
    id_autor INT,
    id_libro INT,
    PRIMARY KEY (id_autor, id_libro),
    FOREIGN KEY (id_autor) REFERENCES Autor(id_autor),
    FOREIGN KEY (id_libro) REFERENCES Libro(id_libro)
);
```

---

### ⚖️ Participación

- **Total:** todas las ocurrencias participan.
    
    - Ej: _cada empleado pertenece a un departamento_.
        
- **Parcial:** solo algunas ocurrencias participan.
    
    - Ej: _algunos empleados supervisan a otros_.
        

---

### 🔑 Claves

- **Superclave:** conjunto de atributos que identifican unívocamente una entidad.
    
- **Clave candidata:** superclave mínima (puede haber varias).
    
- **Clave primaria:** la clave candidata elegida como identificador único.
    

---

### 🏥 Ejemplo práctico – Hospital

**Entidades:**

- Paciente (nro_registro, nombre, teléfono, diagnóstico)
    
- Personal (legajo, nombre, teléfono, categoría)
    
- Sala (nombre, cantidad_camas)
    

**Relaciones:**

- _Personal trabaja en Sala_ (1:N).
    
- _Pacientes internados en Sala_ (1:N).
    

**Restricciones:**

- Cada empleado trabaja en **una única sala**.
    
- En una sala trabajan **varios empleados**.
    
- Un paciente está en **una sola sala**, pero en una sala hay **muchos pacientes**.
    

---
---

## ➡️ Transformación de DER a Tablas

El paso de un **Modelo Entidad–Relación (E–R)** al **modelo relacional** permite implementar la BD en un DBMS.

### 1. Entidades

- **Entidad → Tabla**
    
- **Atributos → Columnas**
    
- **Clave primaria → PRIMARY KEY**
    

```sql
CREATE TABLE Paciente (
    nro_registro INT PRIMARY KEY,
    nombre VARCHAR(50),
    telefono VARCHAR(20),
    diagnostico VARCHAR(100)
);
```

---

### 2. Relaciones 1:N

**Caso:** un empleado pertenece a un departamento.

- Se propaga la **clave primaria** de la entidad "1" como **clave foránea** en la entidad "N".
    

```sql
CREATE TABLE Departamento (
    id_dpto INT PRIMARY KEY,
    nombre VARCHAR(50)
);

CREATE TABLE Empleado (
    legajo INT PRIMARY KEY,
    nombre VARCHAR(50),
    id_dpto INT,
    FOREIGN KEY (id_dpto) REFERENCES Departamento(id_dpto)
);
```

📌 **Principios prácticos**:

- Si existe riesgo de **valores nulos**, conviene crear una tabla aparte en lugar de propagar la clave.
    
- Si la relación puede evolucionar a **N:N** o tiene atributos propios → se recomienda **tabla nueva**.
    

---

### 3. Relaciones N:N

**Caso:** autores y libros.

- Se crea una **tabla intermedia** con las claves de ambas entidades.
    
- La **clave primaria** es la concatenación de las claves foráneas.
    

```sql
CREATE TABLE Autor (
    id_autor INT PRIMARY KEY,
    nombre VARCHAR(50)
);

CREATE TABLE Libro (
    id_libro INT PRIMARY KEY,
    titulo VARCHAR(100)
);

CREATE TABLE Escribe (
    id_autor INT,
    id_libro INT,
    PRIMARY KEY (id_autor, id_libro),
    FOREIGN KEY (id_autor) REFERENCES Autor(id_autor),
    FOREIGN KEY (id_libro) REFERENCES Libro(id_libro)
);
```

---

### 4. Relaciones 1:1

**Caso:** un paciente tiene un test diagnóstico.

- Opción 1: propagar la clave en una de las tablas.
    
- Opción 2: crear tabla intermedia (más flexible si puede crecer).
    

```sql
CREATE TABLE Paciente (
    dni INT PRIMARY KEY,
    nombre VARCHAR(50),
    apellido VARCHAR(50)
);

CREATE TABLE TestDiagnostico (
    codigo INT PRIMARY KEY,
    vto DATE
);

CREATE TABLE RegistroPacienteTest (
    dni_paciente INT,
    codigo_test INT,
    PRIMARY KEY (dni_paciente, codigo_test),
    FOREIGN KEY (dni_paciente) REFERENCES Paciente(dni),
    FOREIGN KEY (codigo_test) REFERENCES TestDiagnostico(codigo)
);
```

---

### ✅ Resumen de reglas

|Tipo de elemento|Transformación|
|---|---|
|**Entidad**|Tabla|
|**Atributo**|Columna|
|**Clave primaria**|PRIMARY KEY|
|**Relación 1:N**|Clave foránea o tabla nueva|
|**Relación N:N**|Tabla intermedia|
|**Relación 1:1**|Clave foránea o tabla nueva según el caso|

---
---
