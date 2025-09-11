### 1. Tabla Original: Empleados_Proyectos

| EmpleadoID | NombreEmpleado | ProyectoID | NombreProyecto | FechaInicioProyecto | HorasAsignadas | Departamento |
|------------|----------------|------------|----------------|---------------------|----------------|--------------|
| 1          | Juan Pérez     | 101        | Sistema Ventas | 10/1/2023           | 40             | IT           |
| 2          | María López    | 102        | Red Sitio Web  | 15/1/2023           | 20             | Marketing    |
| 1          | Juan Pérez     | 103        | App Móvil      | 21/3/2023           | 25             | IT           |

---

### a. Identificación de Dependencias Funcionales y Conversión a 1ra Forma Normal (1FN)

**Dependencias Funcionales:**
- **EmpleadoID** → **NombreEmpleado, Departamento**
- **ProyectoID** → **NombreProyecto, FechaInicioProyecto, HorasAsignadas**
- **EmpleadoID, ProyectoID** → **NombreEmpleado, NombreProyecto, FechaInicioProyecto, HorasAsignadas, Departamento**

**Conversión a 1FN:**
Para cumplir con la 1FN, cada celda debe contener un solo valor y no debe haber grupos repetidos. La tabla original ya cumple con esta condición, pero se puede mejorar la estructura separando la información de empleados y proyectos.

**Tabla en 1FN:**

| EmpleadoID | NombreEmpleado | ProyectoID | NombreProyecto | FechaInicioProyecto | HorasAsignadas | Departamento |
|------------|----------------|------------|----------------|---------------------|----------------|--------------|
| 1          | Juan Pérez     | 101        | Sistema Ventas | 10/1/2023           | 40             | IT           |
| 2          | María López    | 102        | Red Sitio Web  | 15/1/2023           | 20             | Marketing    |
| 1          | Juan Pérez     | 103        | App Móvil      | 21/3/2023           | 25             | IT           |

---

### b. Identificación de Dependencias Parciales y Conversión a 2da Forma Normal (2FN)

**Dependencias Parciales:**
- **EmpleadoID** → **NombreEmpleado, Departamento**
- **ProyectoID** → **NombreProyecto, FechaInicioProyecto, HorasAsignadas**

Para convertir a 2FN, debemos eliminar las dependencias parciales. Esto implica crear tablas separadas para empleados y proyectos.

**Tablas en 2FN:**

**Tabla Empleados:**

| EmpleadoID | NombreEmpleado | Departamento |
|------------|----------------|--------------|
| 1          | Juan Pérez     | IT           |
| 2          | María López    | Marketing    |

**Tabla Proyectos:**

| ProyectoID | NombreProyecto | FechaInicioProyecto | HorasAsignadas |
|------------|----------------|---------------------|----------------|
| 101        | Sistema Ventas | 10/1/2023           | 40             |
| 102        | Red Sitio Web  | 15/1/2023           | 20             |
| 103        | App Móvil      | 21/3/2023           | 25             |

**Tabla Asignaciones:**

| EmpleadoID | ProyectoID |
|------------|------------|
| 1          | 101        |
| 2          | 102        |
| 1          | 103        |

---

### c. Eliminación de Dependencias Transitivas y Conversión a 3ra Forma Normal (3FN)

**Dependencias Transitivas:**
No hay dependencias transitivas en las tablas de empleados y proyectos, ya que cada atributo depende únicamente de la clave primaria.

**Tablas en 3FN:**
Las tablas ya están en 3FN, ya que no hay dependencias transitivas.

**Tabla Final de Empleados:**

| EmpleadoID | NombreEmpleado | Departamento |
|------------|----------------|--------------|
| 1          | Juan Pérez     | IT           |
| 2          | María López    | Marketing    |

**Tabla Final de Proyectos:**

| ProyectoID | NombreProyecto | FechaInicioProyecto | HorasAsignadas |
|------------|----------------|---------------------|----------------|
| 101        | Sistema Ventas | 10/1/2023           | 40             |
| 102        | Red Sitio Web  | 15/1/2023           | 20             |
| 103        | App Móvil      | 21/3/2023           | 25             |

**Tabla Final de Asignaciones:**

| EmpleadoID | ProyectoID |
|------------|------------|
| 1          | 101        |
| 2          | 102        |
| 1
