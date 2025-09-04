-- Crear la base de datos
CREATE DATABASE RestauranteDB;
USE RestauranteDB;

-- Categorías de platos
CREATE TABLE Categoria (
    id_categoria INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    descripcion TEXT,
    encargado VARCHAR(100)
);

-- Platos
CREATE TABLE Plato (
    id_plato INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    descripcion TEXT,
    dificultad VARCHAR(50),
    foto VARCHAR(200),
    precio DECIMAL(10,2) NOT NULL,
    id_categoria INT,
    FOREIGN KEY (id_categoria) REFERENCES Categoria(id_categoria)
);

-- Ingredientes
CREATE TABLE Ingrediente (
    id_ingrediente INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    unidad_medida VARCHAR(50),
    cantidad_actual DECIMAL(10,2)
);

-- Receta (N:M Plato ↔ Ingrediente)
CREATE TABLE Receta (
    id_plato INT,
    id_ingrediente INT,
    cantidad_requerida DECIMAL(10,2) NOT NULL,
    PRIMARY KEY (id_plato, id_ingrediente),
    FOREIGN KEY (id_plato) REFERENCES Plato(id_plato),
    FOREIGN KEY (id_ingrediente) REFERENCES Ingrediente(id_ingrediente)
);
-- Categorías
INSERT INTO Categoria (nombre, descripcion, encargado) VALUES
('Entradas', 'Platos ligeros para comenzar', 'Carlos López'),
('Platos Principales', 'Platos fuertes de la carta', 'María García'),
('Postres', 'Dulces y postres variados', 'Lucía Torres');

-- Platos
INSERT INTO Plato (nombre, descripcion, dificultad, foto, precio, id_categoria) VALUES
('Ensalada César', 'Lechuga, pollo, queso parmesano y aderezo César', 'Fácil', 'ensalada.jpg', 2500, 1),
('Bife de Chorizo', 'Corte de carne vacuna acompañado de papas fritas', 'Media', 'bife.jpg', 7500, 2),
('Tiramisú', 'Postre italiano con café y cacao', 'Difícil', 'tiramisu.jpg', 3000, 3);

-- Ingredientes
INSERT INTO Ingrediente (nombre, unidad_medida, cantidad_actual) VALUES
('Lechuga', 'gr', 500),
('Pollo', 'gr', 1000),
('Queso Parmesano', 'gr', 300),
('Aderezo César', 'ml', 200),
('Carne vacuna', 'gr', 2000),
('Papas', 'gr', 1500),
('Café', 'ml', 500),
('Cacao', 'gr', 200),
('Mascarpone', 'gr', 400);

-- Recetas
INSERT INTO Receta (id_plato, id_ingrediente, cantidad_requerida) VALUES
(1, 1, 100), 
(1, 2, 150), 
(1, 3, 50),  
(1, 4, 30),  

(2, 5, 300), 
(2, 6, 200), 

(3, 7, 100), 
(3, 8, 20),  
(3, 9, 150); 
