#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <getopt.h>

//Menu de error-introduccion 
void opciones(){
    printf("Funcionamiento del programa: ./ejecutable -opcion parametro\n");
    printf("Opciones: \n");
    printf("        -h, --help->Imprimir opciones disponibles\n");
    printf("        -u, --user->Login del usuario/UID\n");
    printf("        -a, --active->Usuario actual\n");
    printf("        -m, --maingroup->Informacion del grupo principal\n");
    printf("        -g, --group->Nombre de grupo/GID\n");
    printf("        -s, --allgroups->Muestra info de todos los grupos del sistema\n");
    printf("Combinaciones posibles:\n");
    printf("    --help, junto con cualquiera (se ignoran las demás)\n");
    printf("    vacío\n");
    printf("    --user <usuario>\n");
    printf("    --active\n");
    printf("    --active --maingroup\n");
    printf("    --group <grupo>\n");
    printf("    --allgroups\n");
    exit(-1);
}
int main(int argc, char *argv[]) {
    //Variables del /etc/password-group
    char *lgn;
    struct passwd *pw;
    struct group *gr;
    //Getopt_long
    bool aflag=false;
    bool hflag=false;
    bool sflag=false;
    bool mflag=false;
    char *uvalue=NULL;
    char *gvalue=NULL;
    int c;
    if(argc<2){
        printf("Opción por defecto\n");
        if((lgn=getenv("USER"))==NULL || (pw=getpwnam(lgn))==NULL){
            printf(" Error al introducir el nombre del usuario\n");
            opciones();     
        }
        printf("Nombre: %s\n", pw->pw_gecos);   
        printf("Login: %s\n", pw->pw_name); 
        printf("Password: %s\n", pw->pw_passwd);                
        printf("UID: %d\n", pw->pw_uid);                
        printf("Home: %s\n", pw->pw_dir);               
        printf("Shell: %s\n", pw->pw_shell);                
        printf("Numero del grupo principal: %d\n", pw->pw_gid); 
        gr=getgrgid(pw->pw_gid);
        printf("Nombre de grupo principal: %s\n", gr->gr_name);
    }
    //Estructura a utilizar por getoptlong 
    static struct option long_options[] = {
        {"user", required_argument, NULL, 'u' },
        {"group", required_argument, NULL, 'g' },
        {"active", no_argument, NULL, 'a' },
        {"maingroup", no_argument, NULL, 'm' },
        {"allgroups", no_argument, NULL, 's' },
        {0, 0, 0, 0}
    };
    while((c=getopt_long(argc, argv, "h,s,a,m,g:u:", long_options, NULL))!=-1) {
        switch (c){
            //mprimir opciones disponibles
            case 'h':
                hflag=true;
            break;
            //Muestra info de todos los grupos del sistema
            case 's':
                sflag=true;
            break;
            //Usuario actual
            case 'a':            
                aflag=true;       
            break;
            //Informacion del grupo principal
            case 'm':
               mflag=true;     
            break;
            //Nombre de grupo
            case 'g': 
              gvalue=optarg;    
            break;
            //Login del usuario
            case 'u':
                uvalue=optarg;
            break; 
            //Caso de cualquier caracter        
            case '?':
               opciones();
            break;
            default:
                abort();
        }
    }
    //Control de errores de opciones
    if((sflag==true) && (mflag==true)){
        printf("Opciones simultaneas no disponibles: -s -m\n");
        opciones();
    }
    if((uvalue!=NULL) && (aflag==true)){
        printf("Opciones simultaneas no disponibles: -u -a\n");
        opciones();
    }
    if((uvalue!=NULL) && (sflag==true)){
        printf("Opciones simultaneas no disponibles: -u -s\n");
        opciones();
    }  
    if((uvalue!=NULL) && (gvalue!=NULL)){
        printf("Opciones simultaneas no disponibles: -u -g\n");
        opciones();
    } 
    if((gvalue!=NULL) && (mflag==true)){
        printf("Opciones simultaneas no disponibles: -g -m\n");
        opciones();
    } 
    if((sflag==true) && (mflag==true)){
        printf("Opciones simultaneas no disponibles: -s -m\n");
        opciones();
    } 
    if((sflag==true) && (aflag==true)){
        printf("Opciones simultaneas no disponibles: -s -a\n");
        opciones();
    } 
    if((mflag==true) && (aflag==false) && (uvalue==NULL)){
        printf("Opcion no disponible: -m\n");
        opciones();
    } 
    //Opciones
    if(hflag==true){
        opciones(); 
    } 
    //Lectura de los grupos del fichero /etc/group
    if(sflag==true){  
            char * line = NULL;
            size_t len = 0; 
            ssize_t read;
            char* token;           
            char delimitador[] = ":";           
            FILE * fp;           
            fp=fopen("/etc/group", "r");
            if(fp==NULL){
                exit(EXIT_FAILURE);
            } 
            while((read=getline(&line, &len, fp))!=-1){                
                token=strtok(line, delimitador);
                gr=getgrnam(token);
                printf("Nombre del grupo: %s.\n", gr->gr_name);
                printf("Identificador: %d\n",gr->gr_gid);
                printf("-----------------------------------\n");
            }
            if(line){
                free(fp);
            }
    }
    //Opciones seleccionadas
    if(aflag==true){
        if((lgn=getenv("USER"))==NULL || (pw=getpwnam(lgn))==NULL){
            printf(" Error al introducir el nombre del usuario\n");
            opciones();     
        }
        printf("Nombre: %s\n", pw->pw_gecos);   
        printf("Login: %s\n", pw->pw_name); 
        printf("Password: %s\n", pw->pw_passwd);                
        printf("UID: %d\n", pw->pw_uid);                
        printf("Home: %s\n", pw->pw_dir);               
        printf("Shell: %s\n", pw->pw_shell);                
        printf("Numero del grupo principal: %d\n", pw->pw_gid); 
        if(mflag==true){
            gr=getgrgid(pw->pw_gid);
            printf("Nombre del grupo principal: %s\n", gr->gr_name);
        }            
    }   
    if(uvalue!=NULL){
        char *endptr;
        strtol(uvalue, &endptr, 10);
        if(((*uvalue)!='\0') && ((*endptr)=='\0')){
            if((pw=getpwuid(atoi(uvalue)))==NULL){
                printf("Error al introducir el nombre-identificador del usuario\n");
                opciones(); 
            }
            else{
                printf("Nombre: %s\n", pw->pw_gecos); 
                printf("Login: %s\n", pw->pw_name);
                printf("Password: %s\n", pw->pw_passwd);
                printf("UID: %d\n", pw->pw_uid);
                printf("Home: %s\n", pw->pw_dir);
                printf("Shell: %s\n", pw->pw_shell);
                printf("Numero de grupo principal: %d\n", pw->pw_gid);
                if(mflag==true){
                    gr=getgrgid(pw->pw_gid);
                    printf("Nombre del grupo principal: %s\n", gr->gr_name);
                }
            }
        }
        else{
            if((lgn=uvalue)==NULL || (pw=getpwnam(lgn))==NULL){
                printf("Error al introducir el nombre-identificador del usuario\n");
                opciones(); 
            }
            else{
                printf("Nombre: %s\n", pw->pw_gecos); 
                printf("Login: %s\n", pw->pw_name);
                printf("Password: %s\n", pw->pw_passwd);
                printf("UID: %d\n", pw->pw_uid);
                printf("Home: %s\n", pw->pw_dir);
                printf("Shell: %s\n", pw->pw_shell);
                printf("Numero de grupo principal: %d\n", pw->pw_gid);
                if(mflag==true){
                    gr=getgrgid(pw->pw_gid);
                    printf("Nombre del grupo principal: %s\n", gr->gr_name);
                }
            }
        }     
    }
    if(gvalue!=NULL){
        char *endptr;
        strtol(gvalue, &endptr, 10);
        if(((*gvalue)!='\0') && ((*endptr)=='\0')){
            if((gr=getgrgid(atoi(gvalue)))==NULL){
                printf("Error al introducir el nombre-identificador del grupo\n");
                opciones();
            }
            else{
                printf("Numero de del grupo: %d\n", gr->gr_gid);
                printf("Nombre de grupo principal: %s\n", gr->gr_name);
            }
        } 
        else{
            if((lgn=gvalue)==NULL || (pw=getpwnam(lgn))==NULL){
                printf("Error al introducir el nombre-identificador del grupo\n");
                opciones();
            }
            else{
                printf("Numero de grupo principal: %d\n", pw->pw_gid);
                gr=getgrgid(pw->pw_gid);
                printf("Nombre de grupo principal: %s\n", gr->gr_name);
            }     
        } 
    }
    return 0;       
}