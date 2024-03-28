#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

// chefs = threads
// stove  = shared data (+mutex)
pthread_mutex_t mutex_stove[4];
int stoveFuel[4] = {100, 100, 100, 100};

void* routine(void* args) 
{
	for (int i = 0; i < 10; i++) 
	{
		if(pthread_mutex_trylock(&mutex_stove[i]) == 0)
		{
			int fuelNeeded = (rand() % 30);
			if(stoveFuel[i] - fuelNeeded < 0) 
			{
				printf("Not enough fuel\n");
			}
			else
			{
				stoveFuel[i] -= fuelNeeded;
				usleep(500000); // simulate some work
				printf("Fuel left: %d\n", stoveFuel[i]);
			}
			pthread_mutex_unlock(&mutex_stove[i]);
			break;
		}
		else{
			if(i == 3)
			{
				printf("No stove available\n");
				usleep(300000);
				i = 0;
			}
		}
	}
}

int main(int ac, char *av[]) 
{
	pthread_t th[10];
	for (int i = 0; i < 10; i++) 
	{
		pthread_mutex_init(&mutex_stove[i], NULL);
	}
	for (int i = 0; i < 10; i++) 
	{	
		if(pthread_create(&th[i], NULL, &routine, NULL) != 0) 
			perror("pthread_create");
	}

	for (int i = 0; i < 10; i++) 
	{
		if(pthread_join(th[i], NULL) != 0)
			perror("pthread_join");
	}
	for (int i = 0; i < 10; i++) 
	{
		pthread_mutex_destroy(&mutex_stove[i]);
	}
	return 0;
}

