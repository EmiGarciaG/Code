<%@ page language="java" contentType="text/html; charset=UTF-8" pageEncoding="UTF-8"%>
<%@ page import ="es.uco.pw.p3.business.UsuarioDto,es.uco.pw.p3.data.dao.UsuarioDao, java.util.ArrayList, java.sql.Timestamp" %>
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
		<!-- Pagina de principal de los administradores-->
		<h3>
			¡Bienvenid@ <jsp:getProperty property="nombreUsuario" name="UsuarioBean"/>! La fecha actual es: <%= new java.util.Date() %>
		</h3>
		<h3>
			La fecha de su registro fue en <jsp:getProperty property="conexionUsuario" name="UsuarioBean"/>
		</h3>
	
		<!-- Redireccionar a Añadir Espectáculo -->
		<form method="get" action="/Practica3/mvc/vista/VistaAE.jsp">
		<fieldset>
    		<button class="AñadirEspectaculo" type="submit">Añadir Espectáculo</button>
		</form>	
	
		<!-- Redireccionar a Añadir Sesión -->
		<form method="get" action="/Practica3/mvc/vista/VistaAS.jsp">
    		<button class="AñadirSesion" type="submit">Añadir Sesión</button>
		</form>	
	
		<!-- Redireccionar a Modificar Sesión -->
		<form method="get" action="/Practica3/mvc/vista/VistaMS.jsp">
    		<button class="ModificarSesion" type="submit">Modificar Sesión</button>
		</form>	
	
		<!-- Redireccionar a Venta de Localidades -->
		<form method="get" action="/Practica3/mvc/vista/VistaVL.jsp">
    		<button class="VentaLocalidades" type="submit">Venta de Localidades</button>
		</form>	
	
		<!-- Redireccionar a Cancelar Espectáculo -->
		<form method="get" action="/Practica3/mvc/vista/VistaCE.jsp">
    		<button class="CancelarEspectaculo" type="submit">Cancelar Espectáculo</button>
		</form>	

		<!-- Redireccionar a Cancelar Sesión -->
		<form method="get" action="/Practica3/mvc/vista/VistaCS.jsp">
    		<button class="CancelarSesion" type="submit">Cancelar Sesión</button>
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
					<p>
						Nick: <%=lista.get(i).getNick()%></br>
			   			Permisos: <%=lista.get(i).getPermisos()%></br>
			   			Fecha registro: <%=lista.get(i).getFechaRegistro()%></br>
			   			Ultima Conexion: <%=lista.get(i).getFechaLogin()%>
					</p></br>
				<% 
			} 
		%>
</body>
</html>