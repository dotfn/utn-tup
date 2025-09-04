-- Crear la base de datos
CREATE DATABASE DepartamentoDB;
USE DepartamentoDB;


CREATE TABLE Departamento (
    id_departamento INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    director VARCHAR(100) NOT NULL
);

CREATE TABLE Empleado (
    id_empleado INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    categoria VARCHAR(50),
    dedicacion VARCHAR(50),
    id_departamento INT,
    FOREIGN KEY (id_departamento) REFERENCES Departamento(id_departamento)
);

-- Insertar datos en la tabla Departamento
INSERT INTO Departamento (nombre, director) VALUES
('Recursos Humanos', 'Ana Martínez'),
('Tecnologías de la Información', 'Luis Gómez'),
('Finanzas', 'Sofía Torres');

-- Insertar datos en la tabla Empleado
INSERT INTO Empleado (nombre, categoria, dedicacion, id_departamento) VALUES
('Pedro Sánchez', 'Administrativo', 'Tiempo Completo', 1),
('Laura Fernández', 'Desarrollador', 'Medio Tiempo', 2),
('Javier Ruiz', 'Contador', 'Tiempo Completo', 3),
('Clara López', 'Analista', 'Medio Tiempo', 2);
