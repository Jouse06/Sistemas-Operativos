#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>

//Variables globales
int tickets = 1000;
int agentes[5];
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void * sellTickets(void *arg){
	int id = *(int*)arg;

	while(tickets > 0){
		pthread_mutex_lock(&lock);

		if(tickets > 0){
			tickets--;
			agentes[id]++;
		}

		pthread_mutex_unlock(&lock);
	}

	return NULL;
}

int main(){
	pthread_t threads[5];
	int id[5] = {0,1,2,3,4};

	for(int i = 0;i<5;i++){
		pthread_create(&threads[i],NULL,sellTickets,&id[i]);
	}

	for(int j=0;j<5;j++){
		pthread_join(threads[j],NULL);
	}

	for(int k=0;k<5;k++){
		printf("This agent sold %i tickets\n",agentes[k]);
	}

	
	return 0;
}
