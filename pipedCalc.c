#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
int main(int argc, char **argv)
{
	char expression[100];
	sprintf(expression, "%s\n", argv[1]);
	int pipe_child[2];
	int pipe_parent[2];
	pipe(pipe_child);
	pipe(pipe_parent);
	
	pid_t process_id = fork(); //клонира процеса до сега
	if(process_id == 0)
	{
		//child code
		dup2(pipe_parent[0], STDIN_FILENO); //Change stdin
		dup2(pipe_child[1], STDOUT_FILENO); //Change stdout
		execlp("bc", "bc", NULL); 
	}
	else
	{
		//parent code
		write(pipe_parent[1], expression, strlen(expression));
		char buffer_to_store_answer[1000];
		read(pipe_child[0], buffer_to_store_answer, 1000);
		printf("%s\n", buffer_to_store_answer);
	}
	return 0;
}
