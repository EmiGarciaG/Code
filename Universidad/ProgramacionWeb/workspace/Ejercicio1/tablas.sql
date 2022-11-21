CREATE TABLE USUARIO(
ID_USUARIO INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
CORREO VARCHAR(40) NOT NULL,
NICK VARCHAR(40) NOT NULL,
CONTRASEÑA VARCHAR( 40 ) NOT NULL,
NOMBRE VARCHAR(40) NOT NULL,
APELLIDOS VARCHAR(40) NOT NULL,
PERMISOS VARCHAR(40) NOT NULL,
FECHA_ULTIMA_CONEXION TIMESTAMP NULL,
FECHA_REGISTRO TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP
) ENGINE = InnoDB;

CREATE TABLE CRITICA(
ID_CRITICA INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
ID_USUARIO INT NOT NULL,
TITULO VARCHAR(40) NOT NULL,
DESCRIPCION VARCHAR(100) NOT NULL,
VALORACION INT NOT NULL,

CONSTRAINT FK_ID_USUARIO,
FOREIGN KEY (ID_USUARIO) REFERENCES USUARIO(ID_USUARIO)
ON UPDATE CASCADE
ON DELETE CASCADE

) ENGINE = InnoDB;

CREATE TABLE VALORACION(
ID_VALORACION INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
ID_CRITICA INT NOT NULL,
ID_USUARIO INT NOT NULL,
VALORACION INT NOT NULL,

CONSTRAINT FK_ID_USUARIO,
FOREIGN KEY (ID_USUARIO) REFERENCES USUARIO(ID_USUARIO)
ON UPDATE CASCADE
ON DELETE CASCADE,

CONSTRAINT FK_ID_CRITICA,
FOREIGN KEY (ID_CRITICA) REFERENCES CRITICA(ID_CRITICA)
ON UPDATE CASCADE
ON DELETE CASCADE

) ENGINE = InnoDB;

CREATE TABLE ESPECTACULO(
ID_ESPECTACULO INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
TITULO VARCHAR(40) NOT NULL,
DESCRIPCION VARCHAR(100) NOT NULL,
CATEGORIA VARCHAR(40) NOT NULL,
LOCALIDADES INT NOT NULL
) ENGINE = InnoDB;

CREATE TABLE SESIONES_PUNTUAL(
ID_SESIONES INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
ID_ESPECTACULO INT NOT NULL,
FECHA DATE NOT NULL,
HORA TIME NOT NULL,
VENTAS INT NOT NULL,

CONSTRAINT FK_ID_ESPECTACULO,
FOREIGN KEY (ID_ESPECTACULO) REFERENCES ESPECTACULO(ID_ESPECTACULO)
ON UPDATE CASCADE
ON DELETE CASCADE

) ENGINE = InnoDB;

CREATE TABLE SESIONES_PASE_MULTIPLE(
ID_SESIONES INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
ID_ESPECTACULO INT NOT NULL,
FECHA DATE NOT NULL,
HORA TIME NOT NULL,
VENTAS INT NOT NULL,

CONSTRAINT FK_ID_ESPECTACULO,
FOREIGN KEY (ID_ESPECTACULO) REFERENCES ESPECTACULO(ID_ESPECTACULO)
ON UPDATE CASCADE
ON DELETE CASCADE

) ENGINE = InnoDB;

CREATE TABLE ESPECTACULO_TEMPORADA(
ID_ESPECTACULO INT NOT NULL,
FECHA_INICIO DATE NOT NULL,
FECHA_FINAL DATE NOT NULL,
DIA_SEMANA VARCHAR(40) NOT NULL,

CONSTRAINT FK_ID_ESPECTACULO,
FOREIGN KEY (ID_ESPECTACULO) REFERENCES ESPECTACULO(ID_ESPECTACULO)
ON UPDATE CASCADE
ON DELETE CASCADE

) ENGINE = InnoDB;

CREATE TABLE SESIONES_TEMPORADA(
ID_SESIONES INT PRIMARY KEY NOT NULL AUTO_INCREMENT,
ID_ESPECTACULO INT NOT NULL,
FECHA DATE NOT NULL,
HORA TIME NOT NULL,
VENTAS INT NOT NULL,

CONSTRAINT FK_ID_ESPECTACULO,
FOREIGN KEY (ID_ESPECTACULO) REFERENCES ESPECTACULO(ID_ESPECTACULO)
ON UPDATE CASCADE
ON DELETE CASCADE

) ENGINE = InnoDB;