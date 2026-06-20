#include <stdio.h>
#include <wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>

int cinta[10];

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

sem_t empty,full;

void *trabajador(void *arg){
	while(1){
	   sem_wait(&empty);
	   pthread_mutex_lock(&lock);

	   printf("Esclavo pone caramelo\n");

	   pthread_mutex_unlock(&lock);
	   sem_post(&full);

	   sleep(1);
	}
}

void *consumidor(void *arg){
	while(1){
	  sem_wait(&full);
	  pthread_mutex_lock(&lock);

	  printf("Coge caramelo\n");

	  pthread_mutex_unlock(&lock);
	  sem_post(&empty);
	}
}

int main(){
	sem_init(&empty,0,10);
	sem_init(&full,0,0);

	pthread_t trabajadores[3];
	pthread_t consumidores[2];

	int idTrabajador[3] = {0,1,2};
	int idConsumidor[2] = {0,1};

	for(int i=0;i<3;i++){
		pthread_create(&trabajadores[i],NULL,trabajador,&idTrabajador[i]);
	}

	for(int j=0;j<2;j++){
		pthread_create(&consumidores[j],NULL,consumidor,&idConsumidor[j]);
	}

	for(int k=0;k<3;k++){
		pthread_join(trabajadores[k],NULL);
	}

	for(int k=0;k<3;k++){
		pthread_join(consumidores[k],NULL);
	}

	return 0;
}

