SET SERVEROUTPUT ON;
CREATE OR REPLACE TRIGGER TRIGGER1
AFTER UPDATE ON EVENTOS FOR EACH ROW
BEGIN
  INSERT INTO AUDIT_TABLE VALUES(:OLD.NOMBRE || ' ' || :NEW.NOMBRE, 'EVENTOS');
END;

UPDATE EVENTOS SET NOMBRE='Madrid2021' WHERE IDEVENTO=6;