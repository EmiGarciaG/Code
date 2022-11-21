SELECT SUBSTR(V.NOMBRECOMPLETO, 1, INSTR(NOMBRECOMPLETO, ' ')) "NOMBRE", V.LOCALIDAD, P.COMUNIDAD FROM VOTANTES V, PROVINCIAS P, LOCALIDADES L
WHERE L.IDLOCALIDAD=V.LOCALIDAD AND L.PROVINCIA=P.IDPROVINCIA AND V.LOCALIDAD IN (1,3,9);