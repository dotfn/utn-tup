CREATE TABLE Veterinario (
    matricula INT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    telefono VARCHAR(20)
);

CREATE TABLE Dueno (
    id_dueño INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    telefono VARCHAR(20),
    email VARCHAR(100)
);

CREATE TABLE Paciente (
    id_paciente INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(100) NOT NULL,
    edad INT,
    especie VARCHAR(50),
    id_dueño INT,
    FOREIGN KEY (id_dueño) REFERENCES Dueno(id_dueño)
);

CREATE TABLE Visita (
    id_visita INT AUTO_INCREMENT PRIMARY KEY,
    fecha DATE,
    motivo VARCHAR(100),
    diagnostico TEXT,
    id_paciente INT,
    matricula_vet INT,
    FOREIGN KEY (id_paciente) REFERENCES Paciente(id_paciente),
    FOREIGN KEY (matricula_vet) REFERENCES Veterinario(matricula)
);
