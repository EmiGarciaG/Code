SET SERVEROUTPUT ON;
DECLARE
  CURSOR VOT IS
  SELECT V.DNI,V.NOMBRECOMPLETO, V.LOCALIDAD FROM VOTANTES V;
  COUNTER NUMBER:=0;
BEGIN
 FOR I IN VOT LOOP
    IF SUBSTR(I.DNI,LENGTH(I.DNI),LENGTH(I.DNI))=I.LOCALIDAD+1 
    THEN
        DBMS_OUTPUT.PUT_LINE(I.NOMBRECOMPLETO);
        COUNTER:=COUNTER+1;
    END IF;
 END LOOP;
  DBMS_OUTPUT.PUT_LINE('Hay un total de '||COUNTER||' votantes');
END;