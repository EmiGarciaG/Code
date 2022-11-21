SET SERVEROUTPUT ON;
DECLARE
  FECHAACTUAL VARCHAR(50):=CURRENT_DATE;
BEGIN
  DBMS_OUTPUT.PUT_LINE('Hola Mundo, hoy es '||FECHAACTUAL);
END;
---------------------------------------------------------------
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
  DBMS_OUTPUT.PUT_LINE(PRIMERAPELLIDO || ', con dni ' || DNI || ' es el votante con m�s edad');
END;
---------------------------------------------------------------
SET SERVEROUTPUT ON;
DECLARE
  NOMBRE VOTANTES.NOMBRECOMPLETO%TYPE;
  MYEMAIL VOTANTES.EMAIL%TYPE;
  MYDNI NUMBER := 30983712;
BEGIN
  SELECT NOMBRECOMPLETO, EMAIL 
  INTO NOMBRE, MYEMAIL 
  FROM VOTANTES 
  WHERE DNI=MYDNI;
  DBMS_OUTPUT.PUT_LINE(NOMBRE||' con correo: '|| MYEMAIL);
END;
---------------------------------------------------------------
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
---------------------------------------------------------------
SET SERVEROUTPUT ON;
DECLARE
  FECHAMIN VOTANTES.FECHANACIMIENTO%TYPE;
  FECHAMAX VOTANTES.FECHANACIMIENTO%TYPE;
  NOMBREMIN VOTANTES.NOMBRECOMPLETO%TYPE;
  NOMBREMAX VOTANTES.NOMBRECOMPLETO%TYPE;
  DIFERENCIA NUMBER(2);
BEGIN
  SELECT A.FECHANACIMIENTO, A.NOMBRECOMPLETO, B.FECHANACIMIENTO, B.NOMBRECOMPLETO
  INTO FECHAMIN, NOMBREMIN, FECHAMAX, NOMBREMAX
  FROM VOTANTES A, VOTANTES B
  WHERE A.FECHANACIMIENTO=(SELECT MIN(FECHANACIMIENTO) FROM VOTANTES)
  AND B.FECHANACIMIENTO=(SELECT MAX(FECHANACIMIENTO) FROM VOTANTES); 
  DIFERENCIA:=ROUND((FECHAMAX-FECHAMIN)/365);
  DBMS_OUTPUT.PUT_LINE('Persona con m�s edad: ' || NOMBREMIN ||' ' || FECHAMIN);
  DBMS_OUTPUT.PUT_LINE('Persona con menos edad: ' || NOMBREMAX ||' ' || FECHAMAX);
  DBMS_OUTPUT.PUT_LINE('La diferencia es: ' || DIFERENCIA || ' a�os');
END;
---------------------------------------------------------------
SET SERVEROUTPUT ON;
DECLARE
  CURSOR C IS 
  SELECT CD.CERTIDUMBRE, P.NOMBRECOMPLETO, CD.RESPUESTA
  FROM CONSULTAS_DATOS CD, PARTIDOS P
  WHERE P.IDPARTIDO=CD.PARTIDO
  ORDER BY CD.CERTIDUMBRE DESC;
  MEDIA NUMBER:=0;
  COUNTER NUMBER:=0;
BEGIN
  FOR ROW IN C LOOP 
    MEDIA:=MEDIA+ROW.CERTIDUMBRE;
    COUNTER:=COUNTER+1;
  END LOOP;
  MEDIA:=ROUND(MEDIA/COUNTER, 3);
  DBMS_OUTPUT.PUT_LINE('La media de la certidumbre es: ' || MEDIA);
  FOR ROW IN C LOOP
    IF ROW.RESPUESTA='Si' 
      AND ROW.CERTIDUMBRE>MEDIA
      THEN
      DBMS_OUTPUT.PUT_LINE(ROW.NOMBRECOMPLETO|| ' ' || ROW.CERTIDUMBRE);
    END IF;
  END LOOP;
END;