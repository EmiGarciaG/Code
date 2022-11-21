SET SERVEROUTPUT ON;
DECLARE
  TYPE TABLA_HASH IS TABLE OF INT INDEX BY VARCHAR2(100);
  CONTEO TABLA_HASH;
  MAXIMO NUMBER;
  APELLIDO VARCHAR2(100);
  KEY VARCHAR2(100);
  KEY2 VARCHAR2(100);
  CURSOR C IS
  SELECT SUBSTR(NOMBRECOMPLETO, INSTR(NOMBRECOMPLETO, ' ')+1, INSTR(NOMBRECOMPLETO, ' ', 1, 2)-INSTR(NOMBRECOMPLETO, ' ') -1)P, 
  SUBSTR(NOMBRECOMPLETO, INSTR(NOMBRECOMPLETO, ' ', 1, 2)+1)S FROM VOTANTES;
BEGIN
  FOR I IN C LOOP
    IF NOT CONTEO.EXISTS(I.P) THEN
      CONTEO(I.P):=1;
    ELSE
      CONTEO(I.P):=CONTEO(I.P)+1;
    END IF;
  END LOOP;
  FOR I IN C LOOP
   IF NOT CONTEO.EXISTS(I.S) THEN
      CONTEO(I.S):=1;
    ELSE
      CONTEO(I.S):=CONTEO(I.S)+1;
    END IF;
  END LOOP;
  KEY:=CONTEO.LAST;
  MAXIMO:=CONTEO(KEY);
  APELLIDO:=KEY;
  KEY2:=CONTEO.FIRST;
  WHILE KEY IS NOT NULL LOOP
    IF CONTEO(KEY2)<CONTEO(KEY) THEN
        MAXIMO:=CONTEO(KEY);
        APELLIDO:=KEY;
    END IF;
    KEY:=CONTEO.PRIOR(KEY);
    KEY2:=CONTEO.NEXT(KEY2);
  END LOOP;
  DBMS_OUTPUT.PUT_LINE(APELLIDO || ' es el apellido mas repetido, n� de ocurrencias: ' || MAXIMO);
  KEY:=CONTEO.FIRST;
  WHILE KEY IS NOT NULL LOOP
    DBMS_OUTPUT.PUT_LINE(KEY || '--->' || CONTEO(KEY));
    KEY:=CONTEO.NEXT(KEY);
  END LOOP;
END;
----------------------------------------------------------------------------------------------------------------
DROP TABLE VIP;
CREATE TABLE VIP(
  DNI NUMBER(8) PRIMARY KEY,
  NOMBRECOMPLETO VARCHAR2(64),
  PRESTACION NUMBER(5) NOT NULL,
  FECHANACIMIENTO DATE NOT NULL,
  EMAIL VARCHAR2(32) NOT NULL
);
---------------------------------------------------------------------------------------------------------------
ALTER TABLE VIP ADD CONSTRAINT nombreyfecha CHECK(SUBSTR(NOMBRECOMPLETO,1,1)='A' AND FECHANACIMIENTO>TO_DATE('1/1/1993','DD/MM/YY') OR FECHANACIMIENTO<TO_DATE('1/1/1960','DD/MM/YY'));
INSERT INTO VIP VALUES(31326800, 'EMILIO', 1, '28/04/1975', 'EMAIL');