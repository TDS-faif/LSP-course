#include <stdio.h>
#include <pthread.h>

void *captureDeviceEvents(void *arguments);

int main(void)
{
	int ret;
	char eventname[20];
	pthread_t id[22];
	for(int i = 0; i < 22; i++)
	{
		sprintf(eventname, "event%d", i);
		ret = pthread_create(&id[i], NULL, &captureDeviceEvents, eventname);
		if(ret == 0)
		{
			printf("Creating thread %d was successful\n", i);
		}
		else
		{
			printf("Creating the thread %d was not successful\n", i);
		}
	}
	return 0;
}

void *captureDeviceEvents(void *argument)
{
	char *dev = argument;
	
	return NULL;
}
