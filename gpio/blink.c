#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("You need to specify how many time the LED will blink\n");
		printf("Specify that as an argument when launching the program\n");
		return 0;
	}
	int fd, i = atoi(argv[1]);
	unsigned char buff[2] = {'0', '1'};

	if((fd = open("/sys/class/gpio/gpio23/value", O_RDWR)) == -1)
	{
		printf("Can't open the file descriptor\n");
		return 0;
	}

	while(i > 0)
	{
		write(fd, buff, 1);
		sleep(1);
		write(fd, buff + 1, 1);
		sleep(1);
		--i;
	}
	return 0;
}
