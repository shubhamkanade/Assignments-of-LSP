#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int counter;

void* trythis(void* arg)
{
	unsigned long i = 0;
	counter += 1;
	printf("\n Job %d has started\n", counter);

	for (i = 0; i < 1000; i++)
		;
	printf("\n Job %d has finished\n", counter);

	return NULL;
}

int main()
{
	int i = 0;
	int TID;

	while (i < 2) {
		TID = pthread_create(&(tid[i]), NULL, &trythis, NULL);
		if (TID != 0)
			printf("\nThread can't be created ");
		i++;
	}

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);

	return 0;
}
