SELECT CONCAT(CONCAT(A.NOMBRE, ' va antes que '), B.NOMBRE) FROM LOCALIDADES A, LOCALIDADES B
WHERE A.IDLOCALIDAD=B.IDLOCALIDAD-1;