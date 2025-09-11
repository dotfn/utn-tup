-- Usamos la base de datos
USE comercio;

-- 1. Insertar tres clientes
INSERT INTO clientes (nombre, email, telefono) VALUES
('Juan Perez', 'juan.perez@example.com', '123456789'),
('Maria Lopez', 'maria.lopez@example.com', '987654321'),
('Carlos Gomez', 'carlos.gomez@example.com', '555555555');

-- 2. Insertar cinco productos
INSERT INTO productos (nombre, descripcion, precio, stock) VALUES
('Laptop', 'Laptop de alta gama', 1500.00, 10),
('Mouse', 'Mouse inalámbrico', 25.00, 50),
('Teclado', 'Teclado mecánico', 75.00, 30),
('Monitor', 'Monitor 24 pulgadas', 200.00, 20),
('Impresora', 'Impresora multifuncional', 120.00, 15);

-- 3. Insertar dos pedidos
INSERT INTO pedidos (cliente_id, fecha_pedido, total) VALUES
(1, CURDATE(), 1525.00),
(2, CURDATE(), 295.00);

-- 4. Insertar detalles de pedidos
INSERT INTO detalle_pedidos (pedido_id, producto_id, cantidad, precio_unitario) VALUES
(1, 1, 1, 1500.00),
(1, 2, 1, 25.00),
(2, 3, 1, 75.00),
(2, 4, 1, 200.00),
(2, 2, 1, 20.00);

-- 5. Actualizar teléfono de Juan Perez
UPDATE clientes
SET telefono = '111111111'
WHERE nombre = 'Juan Perez';

-- 6. Incrementar el precio de todos los productos en un 10%
UPDATE productos
SET precio = precio * 1.10;

-- 7. Eliminar el producto Impresora
DELETE FROM productos
WHERE nombre = 'Impresora';

-- 8. Insertar pedido para Carlos Gomez
INSERT INTO pedidos (cliente_id, fecha_pedido, total) VALUES
(3, CURDATE(), 275.00);

-- 9. Insertar detalles de ese pedido
INSERT INTO detalle_pedidos (pedido_id, producto_id, cantidad, precio_unitario) VALUES
(3, 3, 1, 75.00),
(3, 4, 1, 200.00);

-- 10. Eliminar cliente Maria Lopez
DELETE FROM clientes
WHERE nombre = 'Maria Lopez';
