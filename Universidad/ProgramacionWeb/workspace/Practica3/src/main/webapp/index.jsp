<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<jsp:useBean  id="UsuarioBean" scope="session" class="es.uco.pw.p3.javabean.UsuarioBean"></jsp:useBean>
<!DOCTYPE html>
<html lang="es">
	<head>
		<%
		        String path = request.getContextPath();
		        String basePath = request.getScheme() + "://" + request.getServerName() + ":" +     
		        request.getServerPort() + path + "/";
		%>
		<base href="<%=basePath%>">
		<link href= "<%=basePath%>estilos.css" rel="stylesheet" type="text/css">
		<meta charset="UTF-8">
		<title>Inicio</title>
	</head>
	<body>
		<!-- Reinicio de las variables del UsuarioBean -->
		<jsp:setProperty property="nombreUsuario" value="" name="UsuarioBean"/>
		<jsp:setProperty property="apellidosUsuario" value="" name="UsuarioBean"/>
		<jsp:setProperty property="correoUsuario" value="" name="UsuarioBean"/>
		<jsp:setProperty property="nickUsuario" value="" name="UsuarioBean"/>
		<jsp:setProperty property="passwordUsuario" value="" name="UsuarioBean"/>
		<jsp:setProperty property="permisosUsuario" value="" name="UsuarioBean"/>
		
		<!-- Pagina de inicio de la aplicacion web -->
		<h2>Bienvenid@</h2>
		
		<div class="botones">
			<!-- Redireccionar a la vista de Inicio de Sesion -->
			<form method="get" action="/Practica3/mvc/vista/VistaIS.jsp">
    			<button class="IniciarSesion" type="submit">Iniciar Sesión</button>
			</form>
		
			<!-- Redireccionar a la vista de Registro de Usuario-->
			<form method="get" action="/Practica3/mvc/vista/VistaRU.jsp">
    			<button class="Registrarse" type="submit">Registrarse</button>
			</form>
		</div>
	</body>
</html>