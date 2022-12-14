SET SERVEROUTPUT ON;
DECLARE
  DNI VOTANTES.DNI%TYPE;
  NOMBRE VOTANTES.NOMBRECOMPLETO%TYPE;
  APELLIDOS VOTANTES.NOMBRECOMPLETO%TYPE;
  PRIMERAPELLIDO VARCHAR(50);
BEGIN
  SELECT V.DNI, V.NOMBRECOMPLETO
  INTO DNI, NOMBRE
  FROM VOTANTES V
  WHERE V.FECHANACIMIENTO=(SELECT MIN(FECHANACIMIENTO) FROM VOTANTES);
  APELLIDOS:=SUBSTR(NOMBRE, INSTR(NOMBRE, ' ')+1);
  PRIMERAPELLIDO:=SUBSTR(APELLIDOS, 1, INSTR(APELLIDOS, ' ')-1);
  DBMS_OUTPUT.PUT_LINE(PRIMERAPELLIDO || ', con dni ' || DNI || ' es el votante con m?s edad');
END;