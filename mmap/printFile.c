#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/io.h>
#include <sys/mman.h>

int main(int argc, char **argv)
{
	if(argc < 1)
	{
		printf("file name not specified when executing the program\n");
		return 0;
	}
	
	char *file_content; //Pointer to the content of the file
	struct stat file_stats; //Will store information about the size of the file
	
	int fd = open(argv[1], O_RDONLY); //Open the file

	if(fstat(fd, &file_stats)) //Extract information about the file
	{
		printf("Couldn't read the file size/fstat exited with an error\n");
		return 0;
	}

	file_content = (char *) mmap(0, file_stats.st_size, PROT_READ, MAP_PRIVATE, fd, 0); //Extract the content of the file
	
	printf("%s", file_content);

	return 0;
}
