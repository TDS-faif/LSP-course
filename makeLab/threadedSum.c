#include <pthread.h>
#include "calcsum.h"
void* sum_in_thread(void *arguments)
{
	int result;
	int *array_of_the_integers;
	array_of_the_integers = arguments;
	
	result = calc_sum(array_of_the_integers[0], array_of_the_integers[1]);
	printf("%d\n", result);
	return NULL;
}
int main()
{
	int ret;
	int numbers_to_sum[2];
	fscanf(stdin, "%d %d", &numbers_to_sum[0], &numbers_to_sum[1]);
	
	pthread_t id;
	ret = pthread_create(&id, NULL, &sum_in_thread, numbers_to_sum);
    if(ret == 0)
	{
		printf("Creating the thread was successful\n");
		pthread_join(id, NULL);
	}
	else
	{
		printf("Creating the thread was not successful\n");
	}
	return 0;
}

