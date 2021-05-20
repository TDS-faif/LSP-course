#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/*
 * The program performs a binary search for a word inside a file
 * The complicated part about the program is finding the word
 * inside the file based on a pointer pointed at a random char in the word.
 * To solve this a structure containing data about the word is implemented.
 */

struct wordData
{
	size_t start; //Position at which the word begins
	size_t end; //Position at which the word ends
	size_t len; //Length of the word
};
typedef struct wordData wd_t;

void locateWord(wd_t *wd, char *file, size_t pos); //Function to fill in the wordData structure

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("In order to execute the program successfuly you have to specify the word you are searching for followed by \"1\" depending on if you want debug mode to be activated. It will show every word the program went through until it found the searched word. This debug feature acts as a proof/example of how fast and efficient binary search is.\n");
		printf("For example if you want to launch the program searching for the word \"word\" with debug mode activated you launch: ./bin_search word 1\n");
		return 0;
	}
	
	char *file_content;
	struct stat file_stats;
	int fd = open("/usr/share/dict/cracklib-small", O_RDONLY);
	if(fstat(fd, &file_stats)) //Extract information about the file
	{
		printf("Couldn't read the file size/fstat exited with an error\n");
		printf("Change the name of the file on line %d of the code if you are not using manjaro linux!!!\n", __LINE__-4);
		return 0;
	}
	file_content = (char *) mmap(0, file_stats.st_size, PROT_READ, MAP_SHARED, fd, 0); //Extract the content of the file

	size_t mid = file_stats.st_size / 2; //Start from the middle
	
	//The currently identified boundaries of the interval are tracked with possibleMin and possibleMax
	size_t possibleMin = 0, possibleMax = file_stats.st_size - 1;
	
	wd_t wd;
	int ans;
	char *word = (char*) malloc(1);
	
	//If the boundaries cross this means that the interval in which the word might be located is empty and the word can't be found in the file
	while(possibleMin < possibleMax)
	{
		locateWord(&wd, file_content, mid);
		word = (char *) realloc(word, wd.len+1);
		strncpy(word, file_content + wd.start, wd.len);
		word[wd.len] = 0;
		if(argc > 2 && !strcmp(argv[2], "1"))
		{
			printf("%s\n", word);
		}
		ans = strncmp(word, argv[1], wd.len);
		if(ans > 0) //The word is in the lower half of the current boundaries
		{
			possibleMax = wd.start-1;
			mid = (mid + possibleMin) / 2;
		}
		else if(ans < 0) //The word is in the upper half of the current boundaries
		{
			possibleMin = wd.end+1;
			mid = (mid + possibleMax) / 2;
		}
		else
		{
			printf("The word \"%s\" was found located between positions [%ld] and [%ld]\n", argv[1], wd.start, wd.end-1);
			free(word);
			return 0;
		}
	}
	free(word);
	printf("The searched word \"%s\" wasn't found\n", argv[1]);
	return 0;
}

//Find the start and end of the word currently pointed to
void locateWord(wd_t *wd, char *file, size_t pos)
{
	char c = file[pos]; //Get the current symbol pointed to
	int right = 0, left = 0; //Find how far left and right the word extends
	while(c != '\n') //If new line is found, then the end of the word is here
	{
		++right; //Move one position to the right
		c = file[pos + right];
	}
	wd->end = pos + right;
	
	do
	{
		++left; //Move one position to the left
		if(pos-left == 0) //If the beginning of the file is reached then this is the first word this is where it starts
		{
			left = pos + 1; //The word extends for the entire length of the file from the beginning to the current position
			break;
		}
		c = file[pos - left];
	}
	while(c != '\n');
	
	wd->start = pos - left + 1; //Since left is pointing to the new line at the beginning of the word, the first char in the word is left+1
	wd->len = wd->end - wd->start;
} 
