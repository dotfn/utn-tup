-- 1. Crear tabla Customers
CREATE TABLE Customers (
    CustomerID INT AUTO_INCREMENT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL, 
    LastName VARCHAR(50) NOT NULL,
    Email VARCHAR(100) UNIQUE,
    DateOfBirth DATE
);

-- 2. Crear tabla Orders
CREATE TABLE Orders (
    OrderID INT AUTO_INCREMENT PRIMARY KEY,
    OrderDate DATE NOT NULL,
    CustomerID INT,                     
    TotalAmount DECIMAL(10, 2) NOT NULL,        			   -- Monto total del pedido
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID)  -- Relación con la tabla Customers
);

-- 3. Crear tabla Products
CREATE TABLE Products (
    ProductID INT AUTO_INCREMENT PRIMARY KEY,
    ProductName VARCHAR(100) NOT NULL,   
    Price DECIMAL(10, 2) NOT NULL CHECK (Price > 0),
    StockQuantity INT NOT NULL CHECK (StockQuantity >= 0)
);

-- 4. Agregar columna PhoneNumber a la tabla Customers
ALTER TABLE Customers
ADD PhoneNumber VARCHAR(15) UNIQUE;  -- Número de teléfono único del cliente

-- 5. Hacer ProductName único en la tabla Products
ALTER TABLE Products
ADD CONSTRAINT unique_product_name UNIQUE (ProductName);  -- Asegura que no haya nombres de productos duplicados

-- 6. Crear tabla OrderDetails
CREATE TABLE OrderDetails (
    OrderID INT,
    ProductID INT,
    Quantity INT NOT NULL CHECK (Quantity > 0), 			 -- Cantidad del producto en el pedido, debe ser mayor a 0
    PRIMARY KEY (OrderID, ProductID),        				 -- Clave primaria compuesta por OrderID y ProductID
    FOREIGN KEY (OrderID) REFERENCES Orders(OrderID),  		 -- Relación con la tabla Orders
    FOREIGN KEY (ProductID) REFERENCES Products(ProductID)   -- Relación con la tabla Products
);

-- 7. Eliminar columna PhoneNumber de la tabla Customers
ALTER TABLE Customers
DROP COLUMN PhoneNumber;

-- 8. Modificar tipo de dato de Price en la tabla Products
ALTER TABLE Products
MODIFY Price DECIMAL(12, 2) NOT NULL;

-- 9. Renombrar tabla Customers a Clients
RENAME TABLE Customers TO Clients;

-- 10. Eliminar la tabla OrderDetails
DROP TABLE OrderDetails;
