CREATE TABLE Habitacion (
    nro_habitacion INT PRIMARY KEY,
    tipo ENUM('suite','doble','simple') NOT NULL,
    valor_noche DECIMAL(10,2) NOT NULL
);

CREATE TABLE Cliente (
    id_cliente INT AUTO_INCREMENT PRIMARY KEY,
    nombre VARCHAR(50) NOT NULL,
    apellido VARCHAR(50) NOT NULL,
    dni VARCHAR(20) UNIQUE NOT NULL,
    edad INT,
    telefono VARCHAR(20),
    email VARCHAR(100)
);

CREATE TABLE Reserva (
    id_reserva INT AUTO_INCREMENT PRIMARY KEY,
    fecha_ingreso DATE NOT NULL,
    fecha_salida DATE NOT NULL,
    id_cliente INT,
    nro_habitacion INT,
    FOREIGN KEY (id_cliente) REFERENCES Cliente(id_cliente),
    FOREIGN KEY (nro_habitacion) REFERENCES Habitacion(nro_habitacion)
);

CREATE TABLE Servicio (
    id_servicio INT AUTO_INCREMENT PRIMARY KEY,
    nombre_personal VARCHAR(100),
    categoria ENUM('limpieza','mantenimiento','otro') NOT NULL,
    fecha DATE NOT NULL,
    gasto DECIMAL(10,2),
    nro_habitacion INT,
    FOREIGN KEY (nro_habitacion) REFERENCES Habitacion(nro_habitacion)
);
