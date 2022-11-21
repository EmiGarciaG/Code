<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<jsp:useBean  id="UsuarioBean" scope="session" class="es.uco.pw.p2.javabean.UsuarioBean"></jsp:useBean>
<!DOCTYPE html>
<html lang="es">
<head>
<meta charset="UTF-8">
<title>Página Principal</title>
</head>
<body>
	<!-- Pagina de principal de los espectadores-->
	<h3>
		¡Bienvenido <jsp:getProperty property="nombreUsuario" name="UsuarioBean"/>! La fecha actual es: <%= new java.util.Date() %>
	</h3>
		<!-- Redireccionar buscar espectaculo -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaBO.jsp">
    	<button type="submit">Buscar espectaculo</button>
	</form>	
	
		<!-- Redireccionar Publicar Critica de un Espectaculo -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaPCE.jsp">
    	<button type="submit">Publicar Critica de un Espectaculo</button>
	</form>	
	
			<!-- Redireccionar Eliminar una critica -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaEC.jsp">
    	<button type="submit">Eliminar una critica</button>
	</form>	
	
			<!-- Redireccionar Valorar una critica -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaVC.jsp">
    	<button type="submit">Valorar una critica</button>
	</form>	
	
		<!-- Redireccionar Consultar numero de localidades libres de una sesion -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaCNL.jsp">
    	<button type="submit">Consultar numero de localidades libres para una sesion</button>
	</form>	
	
		<!-- Redireccionar Consultar proximo expectaculo con sesiones disponibles -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaCS.jsp">
    	<button type="submit">Consultar proximo espextaculo con sesiones disponibles</button>
	</form>	
	
	<!-- Redireccionar a la vista de Modificar Datos -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaMD.jsp">
    	<button type="submit">Modificar Datos</button>
	</form>
	
	<!-- Redireccionar al inicio y cierre de sesión -->
	<form method="get" action="/Ejercicio2/index.jsp">
    	<button type="submit">Desconectar</button>
	</form>	
</body>
</html>