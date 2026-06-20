#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t palillos[5];

void *filosofo(void *arg){
	int id = *(int*)arg;
	int left = id;
	int right = (id + 1) % 5;

	while(1){
	if(id == 4){
		pthread_mutex_lock(&palillos[right]);
		pthread_mutex_lock(&palillos[left]);
	} else {
		pthread_mutex_lock(&palillos[left]);
		pthread_mutex_lock(&palillos[right]);
	}

	printf("Filosofo %d esta comiendo...\n",id);
	sleep(2);

	pthread_mutex_unlock(&palillos[left]);
	pthread_mutex_unlock(&palillos[right]);
		}
	return NULL;
}


int main(){
	for(int i=0;i<5;i++){
		pthread_mutex_init(&palillos[i],NULL);
	}

	int id[5] = {0,1,2,3,4};

	pthread_t sofos[5];

	for(int j=0;j<5;j++){
	        pthread_create(&sofos[j],NULL,filosofo,&id[j]);
	}

	for(int k=0;k<5;k++){
	        pthread_join(sofos[k],NULL);
	}
	return 0;
}
