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
		<title>Página Principal</title>
	</head>
	<body>
		<!-- Pagina de principal de los espectadores-->
		<h3>
			¡Bienvenid@ <jsp:getProperty property="nombreUsuario" name="UsuarioBean"/>! La fecha actual es: <%= new java.util.Date() %>
		</h3>
		<h3>
			La fecha de su registro fue en <jsp:getProperty property="conexionUsuario" name="UsuarioBean"/>
		</h3>
	
		<!-- Redireccionar a Buscar Espectáculo -->
		<form method="get" action="/Practica3/mvc/vista/VistaBE.jsp">
		<fieldset>
    		<button class="BuscarEspectaculo" type="submit">Buscar Espectáculo</button>
		</form>	
	
		<!-- Redireccionar a Publicar Crítica de un Espectáculo -->
		<form method="get" action="/Practica3/mvc/vista/VistaPC.jsp">
    		<button class="PublicarCritica" type="submit">Publicar Crítica de un Espectáculo</button>
		</form>	
	
		<!-- Redireccionar a Eliminar una Crítica -->
		<form method="get" action="/Practica3/mvc/vista/VistaBC.jsp">
    		<button class="EliminarCritica" type="submit">Eliminar una Crítica</button>
		</form>	
	
		<!-- Redireccionar a Valorar una Crítica -->
		<form method="get" action="/Practica3/mvc/vista/VistaVC.jsp">
    		<button class="ValorarCritica" type="submit">Valorar una Crítica</button>
		</form>	
	
		<!-- Redireccionar a Consultar Número de Localidades Libres para una Sesión -->
		<form method="get" action="/Practica3/mvc/vista/VistaCL.jsp">
    		<button class="ConsultarNumeroLocalidades" type="submit">Consultar Número de Localidades Libres para una Sesión</button>
		</form>	
	
		<!-- Redireccionar a Modificar Datos -->
		<form method="get" action="/Practica3/mvc/vista/VistaMD.jsp">
    		<button class="ModificarDatos" type="submit">Modificar Datos</button>
		</form>
	
		<!-- Redireccionar al Index -->
		<form method="get" action="/Practica3/index.jsp">
    		<button class="Desconectar" type="submit">Desconectar</button>
    		</fieldset>
		</form>	
	</body>
</html>