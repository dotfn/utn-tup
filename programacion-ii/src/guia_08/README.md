# 8. Ejercitacion Clase 12: Colecciones List

1. Supongamos que estás desarrollando un programa para gestionar una tienda de libros. Cada libro tiene un título, un autor, un precio, y el año de publicación. El programa debe permitir realizar las siguientes operaciones:
   - Agregar un nuevo libro al inventario.
   - Eliminar un libro del inventario.
   - Mostrar todos los libros en el inventario.
   - Buscar un libro por su título.
   - Actualizar el precio de un libro.
   - Calcular el precio total de todos los libros en el inventario.
   - Contar el número total de libros en el inventario.
   - Encontrar el libro más caro y el más barato en el inventario.

   Pensar qué estructuras de datos vista (ArrayList, LinkedList, Stack, etc.) nos conviene para implementar las operaciones anteriores.

   **Consideraciones adicionales:**
   - Crea una clase **Libro** que tenga atributos para el título, autor, precio y año de publicación.
   - Asegúrate de agregar validaciones de entrada para garantizar que los datos ingresados por el usuario sean válidos.

2. Se nos pide armar un programa similar a Spotify que nos permitirá administrar nuestras listas de reproducción. Para ello deberemos generar una clase **Canción** la cual posee un nombre, la duración de la canción, género (el cual solo podrá ser **ROCK**, **TRAP**, **JAZZ**, **HIP HOP**, **POP**, **METAL** y **CLASICA**), el Álbum al que pertenece y a veces un artista invitado si es que tiene.

   **Álbum** posee el año en que fue publicado, un título y conoce su Artista. **Artista** a su vez posee un nombre, su edad y la nacionalidad.

   A. Armar un **ArrayList** de canciones.

   B. Crear una interfaz llamada **Reproducción**, que tendrá los siguientes métodos:
   - **Reproducir:** Debe mostrar la canción en reproducción, junto con el nombre del álbum, género y nombre del artista junto con el artista invitado si es que hay.
   - **AñadirCancion:** recibe una canción por parámetro y la guarda en la lista en reproducción.
   - **EliminarCancion:** mostrará las canciones de la lista en reproducción y permitirá elegir una para eliminar.
   - **VerMiLista:** Nos permite ver nuestra lista de reproducción.

   C. Crear una clase llamada **ListaBasica** que implementa la interfaz del punto 2. Posee como atributo nombre, y un objeto de tipo **Fila** llamado **miLista** donde se guardarán las canciones. Los métodos **eliminarCancion** y **cambiarCancion** no deben permitirle al usuario eliminar o cambiar de canción, sino que deben decirle el siguiente mensaje: “Para acceder a estas opciones, compre el paquete PREMIUM”. El método **Reproducir** solo reproducirá la primera canción de la fila y la enviará al final de la misma.

   D. Crear una clase llamada **ListaPremium** que implementa la interfaz del punto 2. **Premium** posee como atributo nombre y una **LinkedList** llamada **miLista** donde se guardarán las canciones. Esta clase debe poder implementar todos los métodos de la interfaz. El método **Reproducir** mostrará la lista de reproducción donde deberá elegir la canción a reproducir.

   E. Crear un menú para interactuar con nuestra lista de reproducción permitiéndonos utilizar la funcionalidad de la interfaz (reproducir, añadir, eliminar, listar). Estando en reproducción, debería apretar la letra “p” para pausar la canción y regresar al menú principal.
