#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void* routine(void* arg) {
	int index = *(int* )arg;
	int sum = 0;
	for (int j = 0; j < 5; j++) {
		sum += primes[index + j];
	}
	*(int* )arg = sum;
	return arg;
}

int main(int ac, char *av[]) {
	pthread_t threads[2];
	int i;
	for (i = 0; i < 2; i++) {
		int *a = malloc(sizeof(int));
		*a = i * 5;
		if(pthread_create(&threads[i], NULL, &routine, a) != 0) {
			perror("pthread_create");
		}
	}
	int global_sum = 0;
	for (i = 0; i < 2; i++) {
		int* r;
		if(pthread_join(threads[i], (void**) &r) != 0){
			perror("pthread_join");
		}
		global_sum += *r;
		free(r);
	}
	printf("Sum of primes = %d\n", global_sum);
	return 0;
}
