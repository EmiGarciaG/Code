SELECT P.NOMBRECOMPLETO, AVG(CD.CERTIDUMBRE) FROM PARTIDOS P, CONSULTAS_DATOS CD
WHERE P.IDPARTIDO=CD.PARTIDO AND CD.RESPUESTA='No'
GROUP BY P.NOMBRECOMPLETO
HAVING AVG(CD.CERTIDUMBRE)>'0,6';