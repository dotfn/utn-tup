## Guía práctica adicional N°4: Inserción, modificación y eliminación de registros

### Descargar y abrir el Script SQL adjuntado en el campus

1. **Inserta tres registros en la tabla clientes con los campos nombre, email y telefono.**

   - Cliente 1: nombre = ‘Juan Perez’, email = ‘juan.perez@example.com’, telefono = ‘123456789’
   - Cliente 2: nombre = ‘Maria Lopez’, email = ‘maria.lopez@example.com’, telefono = ‘987654321’
   - Cliente 3: nombre = ‘Carlos Gomez’, email = ‘carlos.gomez@example.com’, telefono = ‘555555555’

2. **Inserta cinco registros en la tabla productos con los siguientes valores:**

   - Producto 1: nombre = ‘Laptop’, descripcion = ‘Laptop de alta gama’, precio = 1500.00, stock = 10
   - Producto 2: nombre = ‘Mouse’, descripcion = ‘Mouse inalámbrico’, precio = 25.00, stock = 50
   - Producto 3: nombre = ‘Teclado’, descripcion = ‘Teclado mecánico’, precio = 75.00, stock = 30
   - Producto 4: nombre = ‘Monitor’, descripcion = ‘Monitor 24 pulgadas’, precio = 200.00, stock = 20
   - Producto 5: nombre = ‘Impresora’, descripcion = ‘Impresora multifuncional’, precio = 120.00, stock = 15

3. **Inserta dos registros en la tabla pedidos con los siguientes valores:**

   - Pedido 1: cliente_id = 1, total = 1525.00
   - Pedido 2: cliente_id = 2, total = 295.00

4. **Inserta detalles para los pedidos anteriores en la tabla detalle_pedidos con los siguientes valores:**

   - Detalle 1: pedido_id = 1, producto_id = 1, cantidad = 1, precio_unitario = 1500.00
   - Detalle 2: pedido_id = 1, producto_id = 2, cantidad = 1, precio_unitario = 25.00
   - Detalle 3: pedido_id = 2, producto_id = 3, cantidad = 1, precio_unitario = 75.00
   - Detalle 4: pedido_id = 2, producto_id = 4, cantidad = 1, precio_unitario = 200.00
   - Detalle 5: pedido_id = 2, producto_id = 2, cantidad = 1, precio_unitario = 20.00

5. **Actualiza el teléfono de Juan Perez a 111111111.**

6. **Incrementa el precio de todos los productos en un 10%.**

7. **Elimina el producto Impresora.**

8. **Inserta un nuevo pedido para Carlos Gomez con los siguientes valores:**

   - Pedido 3: cliente_id = 3, total = 275.00

9. **Inserta detalles para el nuevo pedido en la tabla detalle_pedidos con los siguientes valores:**

   - Detalle 6: pedido_id = 3, producto_id = 3, cantidad = 1, precio_unitario = 75.00
   - Detalle 7: pedido_id = 3, producto_id = 4, cantidad = 1, precio_unitario = 200.00

10. **Elimina el cliente Maria Lopez.**
