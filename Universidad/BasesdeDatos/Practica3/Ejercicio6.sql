SELECT C.VOTANTE, V.NOMBRECOMPLETO, COUNT(C.VOTANTE) "VECES" FROM CONSULTAS C, VOTANTES V
WHERE C.VOTANTE=V.DNI
GROUP BY C.VOTANTE, V.NOMBRECOMPLETO
HAVING COUNT(C.VOTANTE)>(SELECT AVG(COUNT(VOTANTE)) FROM CONSULTAS GROUP BY VOTANTE)
ORDER BY "VECES" DESC;