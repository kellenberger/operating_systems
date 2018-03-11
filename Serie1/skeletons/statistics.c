/* gcc -Wall -pthread statistics.c */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int max;
int min;
float avg;
int len;

void *average(void *val) {
	int *array = (int *)val;
	avg = 0;
	int i;
	for (i = 0; i < len; i++)
	{
		avg += array[i];
	}
	avg /= len;
	return NULL;
}

void *minimum(void *val) {
	int *array = (int *)val;
	min = array[0];
	int i;
	for (i = 1; i < len; i++)
	{
		if(min > array[i])
		{
			min = array[i];
		}
	}
	return NULL;
}

void *maximum(void *val) {
	int *array = (int *)val;
	max = array[0];
	int i;
	for (i = 1; i < len; i++)
	{
		if(max < array[i])
		{
			max = array[i];
		}
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	int *array; // use this to store the command line parameters as integers
	pthread_t thread0;
	pthread_t thread1;
	pthread_t thread2;

	if (argc < 3) {
		printf("You have to supply at least 2 integers as arguments!\n");
		return 0;
	}

	len = argc -1;
	array = (int*)calloc(len,sizeof(int));

	int i;
	for (i = 0; i < len; i++)
	{
	   array[i] = atoi(argv[i+1]);
	}

	pthread_create(&thread0, NULL, average, array);
	pthread_create(&thread1, NULL, minimum, array);
	pthread_create(&thread2, NULL, maximum, array);

	pthread_join(thread0, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	printf("Average: %f\n" , avg);
	printf("Maximum: %i\n" , max);
	printf("Minimum: %i\n" , min);

	return 0;
}
