DROP TABLE AUDIT_TABLE;
CREATE TABLE AUDIT_TABLE(DATOS VARCHAR2(100 BYTE), TABLA VARCHAR2(100 BYTE));
-------------------------------------------------------------------------------
SET SERVEROUTPUT ON;
CREATE OR REPLACE TRIGGER TRIGGER1
AFTER UPDATE ON EVENTOS FOR EACH ROW
BEGIN
  INSERT INTO AUDIT_TABLE VALUES(:OLD.NOMBRE || ' ' || :NEW.NOMBRE, 'EVENTOS');
END;

UPDATE EVENTOS SET NOMBRE='Madrid2021' WHERE IDEVENTO=6;

--------------------------------------------------------------------------------
SET SERVEROUTPUT ON;
CREATE OR REPLACE TRIGGER TRIGGER2
BEFORE UPDATE ON LOCALIDADES FOR EACH ROW
BEGIN
  IF :NEW.NUMEROHABITANTES<1 OR :NEW.NUMEROHABITANTES>40000000 THEN
    :NEW.NUMEROHABITANTES:=:OLD.NUMEROHABITANTES;
  END IF;
END;

UPDATE LOCALIDADES SET NUMEROHABITANTES=0 WHERE IDLOCALIDAD=1;
--------------------------------------------------------------------------------
SET SERVEROUTPUT ON;
CREATE OR REPLACE TRIGGER TRIGGER3
BEFORE UPDATE ON CONSULTAS FOR EACH ROW
BEGIN
  IF :NEW.FECHA>SYSDATE THEN
    INSERT INTO AUDIT_TABLE VALUES('Hubo cambios en la fecha, de ' || :NEW.FECHA || ' a ' || SYSDATE, 'CONSULTAS');
    :NEW.FECHA:=SYSDATE;
  END IF;
END;

UPDATE CONSULTAS SET FECHA='22/4/2021' WHERE IDCONSULTA=1;
--------------------------------------------------------------------------------
SET SERVEROUTPUT ON;
ALTER TABLE VOTANTES ADD CONSTRAINT CHECK_TELEFONO CHECK(TELEFONO>=600000000 AND TELEFONO<=799999999);
INSERT INTO VOTANTES VALUES(45555555, 'Antonio Moya', 'Basicos', 'Estudiante', 'amoyano@uco.es', 5, '29/08/1999', 500000000);
--------------------------------------------------------------------------------
SET SERVEROUTPUT ON;
ALTER TABLE EVENTOS DISABLE CONSTRAINT CK_NOMBRE;
ALTER TABLE EVENTOS ADD CONSTRAINT CHECK_NOMBRE CHECK(SUBSTR(TIPO, -1, 1)='o' AND SUBSTR(TIPO, 1, 1)>='A' AND SUBSTR(TIPO, 1, 1)<='Z');
--------------------------------------------------------------------------------
SET SERVEROUTPUT ON;
CREATE OR REPLACE TRIGGER TRIGGER6
AFTER INSERT OR UPDATE ON VOTANTES FOR EACH ROW
BEGIN
    IF :NEW.SITUACIONLABORAL NOT LIKE 'Jubilado' AND (TRUNC(SYSDATE-:NEW.FECHANACIMIENTO)/365.25)>59
    THEN  INSERT INTO AUDIT_TABLE VALUES('Votante con dni' || :NEW.DNI || ' tiene mas de 59 a�os y no esta jubilado', 'CONSULTAS');
    END IF;
END;

INSERT INTO VOTANTES VALUES(31026810, 'Emilio', 'Superiores', 'Estudiante', 'emi@uco.es', 1, '29/08/1960', 610000000);