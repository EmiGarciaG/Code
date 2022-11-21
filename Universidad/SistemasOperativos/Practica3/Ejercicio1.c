#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

pthread_mutex_t mtx=PTHREAD_MUTEX_INITIALIZER;
int *v_point;

void *compra(void *arg){
	int aux;
	int v_size;
	v_size=*((int *)arg);
	int modelo=rand()%v_size;
	int cantidad=rand()%10+1;
	aux=pthread_mutex_lock(&mtx);
	if(aux!=0){
		printf("Error al bloquear el semaforo\n");
		pthread_exit(NULL);
	}
	if(cantidad>=v_point[modelo]){
		cantidad=v_point[modelo];
	}
	v_point[modelo]=v_point[modelo]-cantidad;
	printf("El cliente %lu ha comprado %d unidades del modelo %d\n", pthread_self(), cantidad, modelo);
	aux=pthread_mutex_unlock(&mtx);
	if(aux!=0){
		printf("Error al bloquear el semaforo\n");
		pthread_exit(NULL);
	}
	pthread_exit(NULL);
}

void *suministra(void *arg){
	int aux;
	int v_size;
	v_size=*((int *)arg);
	int modelo=rand()%v_size;
	int cantidad=rand()%10+1;
	aux=pthread_mutex_lock(&mtx);
	if(aux!=0){
		printf("Error al bloquear el semaforo\n");
		pthread_exit(NULL);
	}
	if(cantidad+v_point[modelo]>100){
		cantidad=100-v_point[modelo];
	}
	v_point[modelo]=v_point[modelo]+cantidad;
	printf("El proveedor %lu ha suministrado %d unidades del modelo %d\n", pthread_self(), cantidad, modelo);
	aux=pthread_mutex_unlock(&mtx);
	if(aux!=0){
		printf("Error al bloquear el semaforo\n");
		pthread_exit(NULL);
	}
	pthread_exit(NULL);
}
int main(int argc, char** argv){
	if(argc!=3){
		printf("Error, numero de argumentos\n");
		return EXIT_FAILURE;
	}
	int n=atoi(argv[1]);
	int m=atoi(argv[2]);
	int v[m];
	v_point=v;
	srand(time(NULL));
	printf("Stock inicial\n");
	for(int i=0; i<m; i++){
		v[i]=rand()%100+1;
		printf("Modelo %d: [%d]\n", i, v[i]);
	}
	pthread_t t_n[n], t_m[m];
	for(int i=0; i<n; i++){
		if(pthread_create(&t_n[i], NULL, compra, &m)!=0){
			perror("Error al crear las hebras\n");
			return EXIT_FAILURE;
		}
	}
	for(int i=0; i<m; i++){
		if(pthread_create(&t_m[i], NULL, suministra, &m)!=0){
			perror("Error al crear las hebras\n");
			return EXIT_FAILURE;
		}
	}
	printf("Esperando a las hebras de clientes y proveedores...\n");
	for(int i=0; i<n; i++){
		if((pthread_join(t_n[i], NULL))!=0){
			perror("Error al terminar las hebras\n");
			return EXIT_FAILURE;
		}
	}
	for(int i=0; i<m; i++){
		if((pthread_join(t_m[i], NULL))!=0){
			perror("Error al terminar las hebras\n");
			return EXIT_FAILURE;
		}
	}
	printf("Stock final\n");
	for(int i=0; i<m; i++){
		printf("Modelo %d: [%d]\n", i, v_point[i]);
	}
	return EXIT_SUCCESS;
}
