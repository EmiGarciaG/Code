SELECT L.NOMBRE, L.NUMEROHABITANTES,P.COMUNIDAD FROM LOCALIDADES L, PROVINCIAS P
WHERE P.IDPROVINCIA=L.PROVINCIA AND P.IDPROVINCIA IN (1,2,3) AND L.NUMEROHABITANTES>(SELECT MIN(NUMEROHABITANTES) FROM LOCALIDADES
WHERE PROVINCIA='4');