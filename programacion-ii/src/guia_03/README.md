# 3. Ejercitación Clase 4

## Partes de una clase

### 1) Modelo del objeto Empleado

Modele el objeto **Empleado** que posee las siguientes características: **dni**, **nombre**, **apellido** y **salario**. El mismo debe contar con la posibilidad de calcular el salario anual. A su vez, se requiere otro método que permita aumentar el salario dependiendo del porcentaje que se le pase por parámetro. Considere crear un método que facilite imprimir por pantalla las características del objeto de la siguiente forma:

```
Empleado[dni=?, nombre=?, apellido=?, salario=?]
```

En el `main`, realice las siguientes operaciones:
- a. Inicialice un empleado **Carlos Gutiérrez**, con dni **23456345** y salario inicial de **25000**.
- b. Inicialice un empleado **Ana Sánchez**, con dni **34234123** y salario inicial de **27500**.
- c. Imprima ambos objetos por pantalla.
- d. Aumente el salario del empleado Carlos en un **15%** e imprima en pantalla el salario anual del mismo.

---

### 2) Modelo del objeto Cuenta

Modele el objeto que representa una **cuenta en un banco**, con **identificador**, **nombre** y **balance**. Considere los getters, setters y constructores necesarios. Luego, realice los siguientes métodos:
- a. El método **crédito** que representa un depósito de dinero en la cuenta. Este método debe devolver el balance luego de la operación.
- b. El método **débito** que representa una sustracción de dinero de la cuenta. Este método debe devolver el balance luego de la operación. Si el dinero en la cuenta no es suficiente para cubrir la sustracción, se debe imprimir por pantalla un aviso sin permitir dicha sustracción.
- c. Un método que imprima por pantalla las características del objeto.

En el `main`, realice las siguientes operaciones:
1. Inicialice una cuenta con un monto inicial de **15000**.
2. Realice una operación de crédito de **2500**.
3. Realice una operación de compra de **1500**.
4. Realice una operación de compra de **30000**.
5. Imprima por pantalla los valores de la cuenta y verifique que el balance sea correcto.

---

### 3) Modelo del objeto ItemVenta

Modela un objeto **ItemVenta** que representa un ítem de venta en una tienda. Debe permitir realizar varias operaciones relacionadas con la gestión de ítems. La clase **ItemVenta** deberá tener como atributos: **identificador** (int), **descripcion** (String), **cantidad** (int) y **precioUnitario** (double). Los métodos a realizar son:
- Getters y setters para cada atributo.
- Un método **calcularPrecioTotal()** que devuelve el precio total (**precio unitario * cantidad**).
- Un método que devuelva una representación en cadena del ítem de venta en el formato:

```
ItemVenta[id=?, descripcion=?, cantidad=?, pUnitario=?, pTotal=?].
```

En el `main`, realiza las siguientes operaciones dentro de un `switch`:
1. Agregar ítem: Inicializa un objeto **ItemVenta** con valores proporcionados por el usuario.
2. Imprime el objeto usando el método correspondiente.
3. Permite al usuario ingresar una nueva cantidad y actualiza el atributo **cantidad** del ítem de venta.
4. Permite al usuario ingresar un nuevo **precio unitario** y actualiza el atributo **precioUnitario** del ítem de venta.
5. Imprime el precio total calculado por el método **calcularPrecioTotal()**.
6. Sale del programa.
