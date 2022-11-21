<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<%@ page import ="es.uco.pw.p2.business.UsuarioDto, es.uco.pw.p2.data.dao.UsuarioDao, java.util.ArrayList, java.sql.Timestamp" %>
<jsp:useBean  id="UsuarioBean" scope="session" class="es.uco.pw.p2.javabean.UsuarioBean"></jsp:useBean>
<!DOCTYPE html>
<html lang="es">
<head>
<meta charset="UTF-8">
<title>Página Principal</title>
</head>
<body>
	<!-- Pagina de principal de los administradores-->
	<h3>
		¡Bienvenido <jsp:getProperty property="nombreUsuario" name="UsuarioBean"/>! La fecha actual es: <%= new java.util.Date() %>
	</h3>
	
	<!-- Redireccionar añadir espectaculo -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaAE.jsp">
    	<button type="submit">Añadir espectaculo</button>
	</form>	
	
		<!-- Redireccionar Cancelar espectaculo -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaBE.jsp">
    	<button type="submit">Cancelar espectaculo</button>
	</form>	
	
		<!-- Redireccionar Venta de localidades -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaVL.jsp">
    	<button type="submit">Venta Localidades</button>
	</form>	
	
			<!-- Redireccionar Añadir Sesion -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaAS.jsp">
    	<button type="submit">Añadir Sesion</button>
	</form>	
	
			<!-- Redireccionar Modificar Sesion -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaMS.jsp">
    	<button type="submit">Modificar Sesion</button>
	</form>	
	
		<!-- Redireccionar Cancelar sesion -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaCS.jsp">
    	<button type="submit">Cancelar Sesion</button>
	</form>	
	
	<!-- Redireccionar a la vista de Modificar Datos -->
	<form method="get" action="/Ejercicio2/mvc/vista/VistaMD.jsp">
    	<button type="submit">Modificar Datos</button>
	</form>
	
	<!-- Redireccionar al inicio y cierre de sesión -->
	<form method="get" action="/Ejercicio2/index.jsp">
    	<button type="submit">Desconectar</button>
	</form>	
	
	<!-- Listar usuarios de la base de datos, mostrando su nick, permisos y fecha de última conexión -->
	<h2>Últimas conexiones</h2>
	<%
	String file=application.getInitParameter("properties");
	java.io.InputStream properties=application.getResourceAsStream(file);
	ArrayList <String> credentials=new ArrayList<String>();
	credentials.add(session.getServletContext().getInitParameter("url"));
	credentials.add(session.getServletContext().getInitParameter("user"));
	credentials.add(session.getServletContext().getInitParameter("password"));
	
	ArrayList<UsuarioDto> lista=new ArrayList<UsuarioDto>();
	UsuarioDao listadao=new UsuarioDao();
	lista=listadao.listOfUsers(properties, credentials);
	for(int i=0; i<lista.size(); i++){
		%>
			<p>Nick: <%=lista.get(i).getNick()%></br>
			   Permisos: <%=lista.get(i).getPermisos()%></br>
			   UltimaConexion: <%=lista.get(i).getFechaLogin()%>
			</p></br>
		<% 
	} 
	%>
</body>
</html>