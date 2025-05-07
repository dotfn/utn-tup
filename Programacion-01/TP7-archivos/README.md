### 📘 Trabajo Práctico N° 7: Archivos
---

#### ✅ Consigna general

* En cada ejercicio, el archivo debe **abrirse y cerrarse dentro de cada función**.
* La variable de tipo `FILE*` debe ser **local** a la función.
* Se puede pasar por parámetro una variable de tipo `char[30]` con el nombre del archivo (por ejemplo: `"archivo.bin"` o `"alumnos.dat"`), o trabajar con una constante declarada.

---

#### 🧩 Parte 1: Operaciones con datos primitivos

Utilizando datos primitivos (`int`, `char`, `float`, etc), elija un tipo de dato y realice las siguientes funciones:

1. Una función que **agregue un elemento al final** de un archivo.
2. Una función que **muestre por pantalla** el contenido de un archivo.
3. Una función que **retorne la cantidad de registros** que contiene un archivo.

---

#### 🧩 Parte 2: Trabajar con estructuras

Se utilizará la siguiente estructura:

```c
typedef struct {
    int legajo;
    char nombreYapellido[30];
    int edad;
    int anio; // Año que cursa
} stAlumno;
```

---

#### 🧪 Funciones requeridas

4. Crear una función que **cargue un archivo de alumnos**.

   * Verificar si el archivo ya existe.
   * Si no existe, cargar el archivo con 5 datos.
   * Cerrar el archivo dentro de la función.

5. Crear una función que **muestre por pantalla los registros** de un archivo de alumnos.

   * Modularizar.

6. Crear una función que **permita agregar de a un elemento al final** del archivo.

   * Abrir el archivo, pedir los datos por consola (llenar una variable `stAlumno`), escribir y cerrar.

7. Crear una función que **pase a una pila** los números de legajo de los alumnos **mayores de edad**.

8. Crear una función que **cuente la cantidad de alumnos mayores a una edad específica** (recibida por parámetro).

9. Crear una función que **muestre los nombres de todos los alumnos dentro de un rango de edad** (por ejemplo, entre 17 y 25 años).

   * El rango debe recibirse por parámetro.
   * Modularizar.

10. Crear una función que **muestre los datos del alumno de mayor edad**.

    * Modularizar.

11. Crear una función que **retorne la cantidad de alumnos que cursan un año determinado**.

    * El año buscado se pasa por parámetro.

12. Crear una función que:

    * Reciba como parámetro un **arreglo de tipo alumno** y lo **copie en el archivo**.
    * Otra función que **pase los elementos del archivo a un arreglo**, **filtrando** los estudiantes de un año en particular.

13. Crear una función que **retorne la cantidad de registros** que tiene el archivo.

    * Utilizar `fseek` y `ftell`.
    * Puede pensarse para uso genérico (cualquier tipo de archivo).

14. Dado un archivo con **al menos 10 registros**, hacer una función que:

    * **Muestre el contenido de un registro específico**, cuyo número (entre 0 y 9) se pase por parámetro.
    * Controlar **no sobrepasar los límites** del archivo.

15. Crear una o varias funciones que **modifiquen un registro existente** en el archivo.

    * Permitir modificar **uno o todos los campos** de la estructura.
    * Sobrescribir el registro en el archivo.

16. Crear una función que **invierta los elementos del archivo**.

    * **No se puede usar otro archivo auxiliar ni un arreglo auxiliar**.
    * Puede utilizar variables `stAlumno` auxiliares.

---

#### 🧪 Función principal

17. Crear una **función principal (`main`)** que:

    * Pruebe el funcionamiento de **todos los incisos anteriores**.
    * Implemente un **menú de opciones** para ejecutar cada una de las funciones.
    * Cuidar la **correcta declaración y el ámbito** de las variables.

---
