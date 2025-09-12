# 4. Ejercitación Clase 5: Static y Math

1. Realizar un programa que lee por teclado el valor del radio de una circunferencia, calcula y muestra
por pantalla la longitud y el área de la circunferencia. Cálculo de longitud: 2 * PI * radio, cálculo de
área: PI * radio^2. Usar la clase Math.

2. Realizar un programa que lea la longitud de los catetos de un triángulo rectángulo y calcule la
longitud de la hipotenusa según el teorema de Pitágoras. Usar la clase Math.

3. Realizar un programa que calcula el volumen de una esfera. El valor de radio se debe pedir por
teclado. Cálculo: volumen = 4/3 * PI * radio^3. Usar la clase Math.

4. Modela un objeto Libro que tenga las siguientes características: id (único y autoincremental), título,
autor, precio y cantidad de copias disponibles.
En dicha clase implementa los siguientes métodos:
- Un constructor que inicialice el Libro con su título, autor, precio y cantidad de copias. El id debe
ser asignado automáticamente.
- Métodos getters y setters para cada atributo, excepto el id, que solo tendrá un getter.
- Un método que permita vender una cierta cantidad de copias de un libro, disminuyendo la
cantidad disponible. Si no hay suficientes copias, debe mostrar un mensaje indicando que la
operación no es posible.
- Un método que permita incrementar la cantidad de copias disponibles en el inventario.
- Un método que imprima por pantalla los detalles del libro en el siguiente formato: 

```markdown
    Libro[id=?,título=?, autor=?, precio=?, copias disponibles=?]
```

En el main, realiza las siguientes operaciones:

a. Inicializa un libro con el título "El Quijote", autor "Miguel de Cervantes", precio 500, y 10
copias disponibles.
b. Inicializa otro libro con el título "Cien Años de Soledad", autor "Gabriel García Márquez",
precio 700, y 5 copias disponibles.  
c. Imprime los detalles de ambos libros.  
d. Vende 3 copias del primer libro.  
e. Imprime los detalles del primer libro.  
f. Intenta vender 8 copias del segundo libro.  
g. Incrementa en 5 la cantidad de copias disponibles del segundo libro.  
h. Imprime los detalles del segundo libro.

