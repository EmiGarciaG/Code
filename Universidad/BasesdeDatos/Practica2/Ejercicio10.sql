SELECT P.NOMBRECOMPLETO, COUNT(CD.PARTIDO) "CONTEO" FROM PARTIDOS P, CONSULTAS_DATOS CD
WHERE P.IDPARTIDO=CD.PARTIDO AND CD.RESPUESTA='Si' AND CD.CERTIDUMBRE>'0,8'
GROUP BY P.NOMBRECOMPLETO;
