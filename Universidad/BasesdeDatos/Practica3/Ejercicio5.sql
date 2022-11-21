SELECT C.VOTANTE, V.NOMBRECOMPLETO, COUNT(C.VOTANTE) "VECES" FROM CONSULTAS C, VOTANTES V
WHERE C.VOTANTE=V.DNI
GROUP BY C.VOTANTE, V.NOMBRECOMPLETO
ORDER BY "VECES" DESC;
