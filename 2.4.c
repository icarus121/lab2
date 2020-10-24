#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

char name[20];
void childTask()
{
	printf("Name:>");
	scanf("%20s", name);
	printf("Name %20s \n", name);
}

void parentTask()
{
	printf("Job is done. \n");
}
void main()
{
	for (int i=0; i<4; i++)
	{
		//char name[20];
		pid_t pid = fork();

		if(pid==0)
		{
			//char *name;
			wait(NULL);
			childTask();
			//parentTask();
			//wait(NULL);
			//printf("Name:>");
			//scanf("%20s", name);
			//printf("name %20s \n", name);
			return;
		}
		else /*if(pid>0)*/
		{
			wait(NULL);
			//childTask();
			//parentTask();
		}

			//wait(NULL);
			//parentTask();
			//wait(NULL);
			//printf("Job is done. \n");
			//wait(NULL);
			//exit(EXIT_SUCCESS);
	}
	//wait(NULL);
	parentTask();
	return;
}
