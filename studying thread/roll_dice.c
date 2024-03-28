#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>


void* roll_dice(void* arg) {
	int value = (rand() % 6) + 1;
	int* result = malloc(sizeof(int));
	*result = value;
	sleep(2);
	printf("Rolled a %d\n", value);
	pthread_exit((void*) result);
}

int main(int ac, char *av[]) {
	int* res;
	srand(time(NULL));
	pthread_t th;
	if(pthread_create(&th, NULL, &roll_dice, NULL) != 0) 
	{
		return 1;
	}
	pthread_exit(0);
	if(pthread_join(th, (void**) &res) != 0)
	{
		return 2;
	}
	printf("Result: = %d\n", *res);
	free(res);
	return 0;
}
