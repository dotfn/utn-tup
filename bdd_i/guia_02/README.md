# Guía práctica adicional N°2:  
## Normalización

---

### 1. Tabla Original: Empleados_Proyectos

| EmpleadoID | NombreEmpleado | ProyectoID | NombreProyecto | FechaInicioProyecto | HorasAsignadas | Departamento |
|------------|----------------|------------|----------------|---------------------|----------------|--------------|
| 1          | Juan Pérez     | 101        | Sistema Ventas | 10/1/2023           | 40             | IT           |
| 2          | María López    | 102        | Red Sitio Web  | 15/1/2023           | 20             | Marketing    |
| 1          | Juan Pérez     | 103        | App Móvil      | 21/3/2023           | 25             | IT           |

#### Tareas:
a. Identifica las dependencias funcionales y convierte la tabla a la **1ra Forma Normal (1FN)**.  
b. Luego, identifica cualquier dependencia parcial y normaliza a la **2da Forma Normal (2FN)**.  
c. Finalmente, elimina cualquier dependencia transitiva para convertir la tabla a la **3ra Forma Normal (3FN)**.  

---

### 2. Tabla Original: Pedidos_Clientes

| PedidoID | ClienteID | NombreCliente | FechaPedido | ProductoID | NombreProducto | Cantidad | PrecioUnitario |
|----------|-----------|---------------|-------------|------------|----------------|----------|----------------|
| 1        | 101       | Carlos Gómez  | 24/6/2023   | 501        | Laptop         | 1        | 800            |
| 2        | 102       | Ana Torres    | 25/6/2023   | 502        | Smartphone     | 2        | 600            |
| 1        | 101       | Carlos Gómez  | 24/6/2023   | 503        | Teclado        | 5        | 20             |

#### Tareas:
a. Descompone la tabla para eliminar valores repetidos y conviértela a la **1ra Forma Normal (1FN)**.  
b. Normaliza para eliminar dependencias parciales, llevando la tabla a la **2da Forma Normal (2FN)**.  
c. Asegúrate de que no existan dependencias transitivas para llevar la tabla a la **3ra Forma Normal (3FN)**.  

---

### 3. Tabla Original: Cursos_Profesores_Estudiantes

| CursoID | NombreCurso   | ProfesorID | NombreProfesor | EstudianteID | NombreEstudiante | NotaFinal |
|---------|---------------|------------|----------------|--------------|------------------|-----------|
| 101     | Matemáticas   | 201        | Dr. Pérez      | 301          | Luis González    | 85        |
| 102     | Física        | 202        | Dra. García    | 302          | Laura Torres     | 90        |
| 101     | Matemáticas   | 201        | Dr. Pérez      | 303          | Marta Rodríguez  | 88        |

#### Tareas:
1. Asegúrate de que la tabla esté en la **1ra Forma Normal (1FN)** al eliminar cualquier grupo repetitivo.  
2. Normaliza la tabla a la **2da Forma Normal (2FN)** eliminando dependencias parciales.  
3. Finalmente, normaliza la tabla a la **3ra Forma Normal (3FN)** eliminando cualquier dependencia transitiva.  
