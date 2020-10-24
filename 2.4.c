#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	for (int i=0; i<13; i++)
	{
		pid_t pid = fork();

		if(pid==0)
		{
			char name;
			printf("child process => PPID=%d, PID=%d\n", getppid(), getpid());
			printf("Name:>");
			scanf("%d", &name);
			printf("%d\n", name);
			exit(0);
		}
		else
		{
			printf("Parent process => PID=%d\n", getpid());
			printf("Waiting for child processes to finish...\n");
			wait(NULL);
			printf("child process finished.\n");
		}
	}

	return EXIT_SUCCESS;
}
