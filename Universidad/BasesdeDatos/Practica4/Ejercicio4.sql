SET SERVEROUTPUT ON;
DECLARE
  NOMBRE VOTANTES.NOMBRECOMPLETO%TYPE;
BEGIN
  SELECT REPLACE(NOMBRECOMPLETO, 'Jose', 'Pepe')
  INTO NOMBRE 
  FROM VOTANTES
  WHERE DNI=30983712;
  DBMS_OUTPUT.PUT_LINE(NOMBRE);
END;