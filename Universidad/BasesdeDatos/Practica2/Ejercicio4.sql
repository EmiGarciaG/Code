SELECT VOTANTES.NOMBRECOMPLETO, LOCALIDADES.NOMBRE FROM VOTANTES, LOCALIDADES
WHERE VOTANTES.LOCALIDAD=LOCALIDADES.IDLOCALIDAD AND LOCALIDADES.NUMEROHABITANTES>'300000';