#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main()
{
	int pc[2];
	int pp[2];
	pipe(pc);
	pipe(pp);
	
	pid_t process_id = fork(); //клонира процеса до сега
	if(process_id == 0)
	{
		//child code
		dup2(pp[0], STDIN_FILENO); //Change stdin
		dup2(pc[1], STDOUT_FILENO); //Change stdout
		execlp("bc", "bc", NULL); 
	}
	else
	{
		//parent code
		char *expression = "1+2";
		write(pp[1], expression, strlen(expression));
		char buff[100];
		read(pc[0], buff, 100);
		printf("%s\n", buff);
	}
	return 0;
}
