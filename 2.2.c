#include <stdlib.h>	/*needed to define exit*/
#include <unistd.h>	/*needed for fork() and getpid()*/
#include <stdio.h>	/*needed for printf()*/


int main(int argrc, char **argv)
{
	int pid;	/*process ID*/

	switch (pid = fork())
	{
		case 0:	/*a fork return 0 to the child*/
			printf("I am the child process:pid=%d\n", getpid());
			break;

		default:	/*a fork returns a pid to the parent*/
			
			printf("I am the parent process: pid=%d. child pid=%d\n", getpid(), pid);
			break;

		case -1:	/*something went wrong*/
			perror("fork");
			exit(1);
	}

	exit(0);
}
