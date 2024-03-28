#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

pthread_mutex_t mutex;
//loc the single mutex and print a message when the mutex is locked and unlocked

void* routine(void* arg) {
	if(pthread_mutex_trylock(&mutex) == 0)
	{
		printf("Thread locked the mutex\n");
		sleep(1);
		pthread_mutex_unlock(&mutex);
	}
	else
	{
		printf("Thread failed to lock the mutex\n");
	}
}

int main(int ac, char *av[]) {
	pthread_t threads[4];
	int i;
	for (i = 0; i < 4; i++) 
		if(pthread_create(&threads[i], NULL, &routine, NULL) != 0) {
			perror("pthread_create");
		}
	for (i = 0; i < 4; i++) {
		if(pthread_join(threads[i], NULL) != 0){
			perror("pthread_join");
		}
	}
}