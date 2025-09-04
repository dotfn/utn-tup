-- Crear la base de datos
CREATE DATABASE IF NOT EXISTS InventarioDB;
USE InventarioDB;

-- Crear la tabla Proveedor
CREATE TABLE Proveedor (
    id_proveedor INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    direccion VARCHAR(150),
    ciudad VARCHAR(100),
    provincia VARCHAR(100)
);

-- Crear la tabla PrecioCategoria
CREATE TABLE PrecioCategoria (
    categoria VARCHAR(50) PRIMARY KEY,
    precio DECIMAL(10,2) NOT NULL
);

-- Crear la tabla Pieza
CREATE TABLE Pieza (
    id_pieza INT AUTO_INCREMENT PRIMARY KEY,
    color VARCHAR(50),
    categoria VARCHAR(50),
    FOREIGN KEY (categoria) REFERENCES PrecioCategoria(categoria)
);

-- Crear la tabla Suministro
CREATE TABLE Suministro (
    id_proveedor INT,
    id_pieza INT,
    cantidad INT NOT NULL,
    PRIMARY KEY (id_proveedor, id_pieza),
    FOREIGN KEY (id_proveedor) REFERENCES Proveedor(id_proveedor),
    FOREIGN KEY (id_pieza) REFERENCES Pieza(id_pieza)
);
-- Insertar datos en la tabla Proveedor
INSERT INTO Proveedor (nombre, direccion, ciudad, provincia) VALUES
('Proveedor A', 'Calle 123', 'Ciudad A', 'Provincia A'),
('Proveedor B', 'Avenida 456', 'Ciudad B', 'Provincia B'),
('Proveedor C', 'Boulevard 789', 'Ciudad C', 'Provincia C');

-- Insertar datos en la tabla PrecioCategoria
INSERT INTO PrecioCategoria (categoria, precio) VALUES
('Categoria 1', 100.00),
('Categoria 2', 200.00),
('Categoria 3', 300.00);

-- Insertar datos en la tabla Pieza
INSERT INTO Pieza (color, categoria) VALUES
('Rojo', 'Categoria 1'),
('Verde', 'Categoria 2'),
('Azul', 'Categoria 3');

-- Insertar datos en la tabla Suministro
INSERT INTO Suministro (id_proveedor, id_pieza, cantidad) VALUES
(1, 1, 50),
(1, 2, 30),
(2, 1, 20),
(3, 3, 10);

SELECT 
    p.nombre AS proveedor,
    p.direccion,
    p.ciudad,
    p.provincia,
    pi.color,
    pi.categoria,
    pc.precio,
    s.cantidad
FROM Proveedor p
JOIN Suministro s ON p.id_proveedor = s.id_proveedor
JOIN Pieza pi ON s.id_pieza = pi.id_pieza
JOIN PrecioCategoria pc ON pi.categoria = pc.categoria
WHERE p.id_proveedor = 1;
