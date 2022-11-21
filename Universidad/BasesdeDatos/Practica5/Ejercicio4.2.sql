SET SERVEROUTPUT ON;
DECLARE
  CURSOR C IS
  SELECT VOTANTE, COUNT(VOTANTE) VECES FROM CONSULTAS
  GROUP BY VOTANTE
  ORDER BY VECES DESC;
  MEDIA FLOAT;
BEGIN
  SELECT AVG(COUNT(VOTANTE)) INTO MEDIA FROM CONSULTAS 
  GROUP BY VOTANTE;
  FOR AROV IN C LOOP
    IF AROV.VECES>MEDIA THEN
    DBMS_OUTPUT.PUT_LINE(AROV.VOTANTE || ' ha participado ' || AROV.VECES || ' veces ');
    END IF;
  END LOOP;
END;