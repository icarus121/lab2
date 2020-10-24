#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

void childTask()
{
	printf("child process => PPID= %d, PID=%d\n", getppid(), getpid());
}

void parentTask()
{
	printf("Parent process => PID=%d\n", getpid());
	printf("Waiting for child process to finish.\n");
}
void main()
{
	for (int i=0; i<13; i++)
	{
		char name;
		pid_t pid = fork();

		if(pid==0)
		{
			//char *name;
			//printf("child process => PPID=%d, PID=%d\n", getppid(), getpid());
			childTask();
			//wait(NULL);
			printf("Name:>");
			scanf("%c", &name);
			printf("name %c \n", name);
			exit(0);
		}
		else if(pid>0)
		{
			//printf("Parent process => PID=%d\n", getpid());
			wait(NULL);
			parentTask();
			//wait(NULL);
			//printf("Waiting for child processes to finish...\n");
			wait(NULL);
			printf("child process finished.\n");
			printf("Job is done. \n");
			//wait(NULL);
		}
		else
		{
			printf("Unable to create child process. \n");
		}
	}

	return;
}
