-- Crear la base de datos
CREATE DATABASE PeliculasDB;
USE PeliculasDB;

-- Director
CREATE TABLE Director (
    id_director INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    fecha_nacimiento DATE,
    pais_origen VARCHAR(100)
);

-- Películas
CREATE TABLE Pelicula (
    id_pelicula INT AUTO_INCREMENT PRIMARY KEY,
    titulo VARCHAR(200) NOT NULL,
    anio INT,
    nacionalidad VARCHAR(100),
    idioma VARCHAR(50),
    es_color BOOLEAN,
    restriccion_edad VARCHAR(50),
    resumen TEXT,
    observaciones TEXT,
    id_director INT,
    FOREIGN KEY (id_director) REFERENCES Director(id_director)
);

-- Actores
CREATE TABLE Actor (
    id_actor INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    nacionalidad VARCHAR(100)
);

-- Relación Reparto (N:M)
CREATE TABLE Reparto (
    id_pelicula INT,
    id_actor INT,
    personaje VARCHAR(100),
    PRIMARY KEY (id_pelicula, id_actor),
    FOREIGN KEY (id_pelicula) REFERENCES Pelicula(id_pelicula),
    FOREIGN KEY (id_actor) REFERENCES Actor(id_actor)
);

-- Directores
INSERT INTO Director (nombre, fecha_nacimiento, pais_origen) VALUES
('Christopher Nolan', '1970-07-30', 'Reino Unido'),
('Quentin Tarantino', '1963-03-27', 'Estados Unidos');

-- Películas
INSERT INTO Pelicula (titulo, anio, nacionalidad, idioma, es_color, restriccion_edad, resumen, observaciones, id_director)
VALUES
('Inception', 2010, 'EE.UU.', 'Inglés', TRUE, 'PG-13', 'Un ladrón roba secretos a través de los sueños', 'Ganó 4 premios Oscar', 1),
('Pulp Fiction', 1994, 'EE.UU.', 'Inglés', TRUE, 'R', 'Historias criminales entrelazadas en Los Ángeles', 'Película de culto', 2);

-- Actores
INSERT INTO Actor (nombre, nacionalidad) VALUES
('Leonardo DiCaprio', 'EE.UU.'),
('Joseph Gordon-Levitt', 'EE.UU.'),
('John Travolta', 'EE.UU.'),
('Samuel L. Jackson', 'EE.UU.');

-- Reparto
INSERT INTO Reparto (id_pelicula, id_actor, personaje) VALUES
(1, 1, 'Dom Cobb'),
(1, 2, 'Arthur'),
(2, 3, 'Vincent Vega'),
(2, 4, 'Jules Winnfield');
