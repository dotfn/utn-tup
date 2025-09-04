-- Crear la base de datos
CREATE DATABASE IF NOT EXISTS UniversidadDB;
USE UniversidadDB;

CREATE TABLE Persona (
    id_persona INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    direccion VARCHAR(150),
    telefono VARCHAR(50),
    email VARCHAR(100)
);

CREATE TABLE Departamento (
    id_departamento INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL
);

CREATE TABLE Centro (
    id_centro INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL
);

CREATE TABLE Titulacion (
    id_titulacion INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL
);

-- Profesores
CREATE TABLE Profesor (
    id_profesor INT PRIMARY KEY,
    dedicacion VARCHAR(50),
    id_departamento INT,
    FOREIGN KEY (id_profesor) REFERENCES Persona(id_persona),
    FOREIGN KEY (id_departamento) REFERENCES Departamento(id_departamento)
);

-- Alumnos
CREATE TABLE Alumno (
    id_alumno INT PRIMARY KEY,
    nro_expediente VARCHAR(50) UNIQUE,
    id_centro INT,
    id_titulacion INT,
    FOREIGN KEY (id_alumno) REFERENCES Persona(id_persona),
    FOREIGN KEY (id_centro) REFERENCES Centro(id_centro),
    FOREIGN KEY (id_titulacion) REFERENCES Titulacion(id_titulacion)
);

-- Personal administrativo
CREATE TABLE Personal (
    id_personal INT PRIMARY KEY,
    unidad_administrativa VARCHAR(100),
    categoria_profesional VARCHAR(50),
    FOREIGN KEY (id_personal) REFERENCES Persona(id_persona)
);

-- Relación N:M entre Profesor y Centro
CREATE TABLE Profesor_Centro (
    id_profesor INT,
    id_centro INT,
    PRIMARY KEY (id_profesor, id_centro),
    FOREIGN KEY (id_profesor) REFERENCES Profesor(id_profesor),
    FOREIGN KEY (id_centro) REFERENCES Centro(id_centro)
);

-- Persona
INSERT INTO Persona (nombre, direccion, telefono, email) VALUES
('Juan Pérez', 'Calle Falsa 123', '123456789', 'juan.perez@example.com'),
('María López', 'Avenida Siempre Viva 742', '987654321', 'maria.lopez@example.com'),
('Carlos García', 'Boulevard de los Sueños 456', '456789123', 'carlos.garcia@example.com');

-- Departamento
INSERT INTO Departamento (nombre) VALUES
('Matemáticas'),
('Ciencias Sociales'),
('Literatura');

-- Centro
INSERT INTO Centro (nombre) VALUES
('Centro de Estudios Avanzados'),
('Instituto de Ciencias Aplicadas');

-- Titulacion
INSERT INTO Titulacion (nombre) VALUES
('Ingeniería en Sistemas'),
('Licenciatura en Psicología'),
('Maestría en Educación');

-- Profesor
INSERT INTO Profesor (id_profesor, dedicacion, id_departamento) VALUES
(1, 'Tiempo Completo', 1),
(2, 'Medio Tiempo', 2);

-- Alumno
INSERT INTO Alumno (id_alumno, nro_expediente, id_centro, id_titulacion) VALUES
(1, 'EXP001', 1, 1),
(2, 'EXP002', 2, 2);

-- Personal
INSERT INTO Personal (id_personal, unidad_administrativa, categoria_profesional) VALUES
(1, 'Administración General', 'Administrativo'),
(2, 'Recursos Humanos', 'Asistente');

-- Profesor_Centro
INSERT INTO Profesor_Centro (id_profesor, id_centro) VALUES
(1, 1),
(2, 2);

