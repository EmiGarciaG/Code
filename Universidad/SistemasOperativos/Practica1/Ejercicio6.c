#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int numero_timbres;
void manejador_alarma(int signal){
    printf("ALARM!!!\n");
    numero_timbres++;
}
int main(){
    numero_timbres=0;
    signal(SIGALRM, &manejador_alarma);
    int longitud_alarma[]={5,3,1,1};
    for(int i=0; i<4; i++){
        alarm(longitud_alarma[i]);
        while(numero_timbres<=i){
            printf("%d\n", numero_timbres);
            sleep(1);
        }
    }
    kill(getpid(), SIGKILL);
    return 0;
}
