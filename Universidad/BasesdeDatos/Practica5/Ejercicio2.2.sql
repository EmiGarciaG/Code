SET SERVEROUTPUT ON;
DECLARE
  CURSOR C IS 
  SELECT V.NOMBRECOMPLETO, DECODE(L.NOMBRE, 'Cordoba', 'Madrid', 'Montilla', 'Madrid', 'Baena', 'Madrid', L.NOMBRE) "CIUDADES" FROM VOTANTES V, LOCALIDADES L
  WHERE L.IDLOCALIDAD=V.LOCALIDAD;
BEGIN 
 FOR I IN C LOOP
    DBMS_OUTPUT.PUT_LINE(I.NOMBRECOMPLETO || ' es de ' || I.CIUDADES);
 END LOOP;
END;
