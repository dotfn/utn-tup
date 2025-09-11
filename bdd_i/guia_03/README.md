# Guía práctica adicional N°3:  
## Creación y modificación de tablas  

1. Crea una tabla llamada **Customers** con las siguientes columnas:  
   - **CustomerID**: Entero, clave primaria, autoincrementable.  
   - **FirstName**: Texto de hasta 50 caracteres, no nulo.  
   - **LastName**: Texto de hasta 50 caracteres, no nulo.  
   - **Email**: Texto de hasta 100 caracteres, único.  
   - **DateOfBirth**: Fecha.  

2. Crea una tabla llamada **Orders** con las siguientes columnas:  
   - **OrderID**: Entero, clave primaria, autoincrementable.  
   - **OrderDate**: Fecha, no nula.  
   - **CustomerID**: Entero, clave foránea que referencia a **CustomerID** de la tabla **Customers**.  
   - **TotalAmount**: Decimal con dos decimales, no nulo.  

3. Crea una tabla llamada **Products** con las siguientes columnas:  
   - **ProductID**: Entero, clave primaria, autoincrementable.  
   - **ProductName**: Texto de hasta 100 caracteres, no nulo.  
   - **Price**: Decimal con dos decimales, no nulo, debe ser mayor a 0.  
   - **StockQuantity**: Entero, no nulo, debe ser mayor o igual a 0.  

4. Agrega una columna **PhoneNumber** a la tabla **Customers**, que sea de tipo texto con hasta 15 caracteres y única.  

5. Modifica la tabla **Products** para que el nombre del producto sea único.  

6. Crea una tabla llamada **OrderDetails** con las siguientes columnas:  
   - **OrderID**: Entero, clave foránea que referencia a **OrderID** de la tabla **Orders**.  
   - **ProductID**: Entero, clave foránea que referencia a **ProductID** de la tabla **Products**.  
   - **Quantity**: Entero, no nulo, debe ser mayor a 0.  
   - Define una clave primaria compuesta por **OrderID** y **ProductID**.  

7. Elimina la columna **PhoneNumber** de la tabla **Customers**.  

8. Modifica el tipo de dato de la columna **Price** en la tabla **Products** para que sea **DECIMAL(12, 2)**.  

9. Renombra la tabla **Customers** a **Clients**.  

10. Elimina la tabla **OrderDetails**.  
