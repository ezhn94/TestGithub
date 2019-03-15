#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <error.h>
#include <wait.h>


#define MYTIME 20

int main(void)
{

		pid_t pid;
		char *message;
		int n;
		int status;

		printf("fork program starting\n");
		pid = fork();

		switch(pid)
		{
				case -1:	perror("fork failed");
							exit(1);
				case 0:		message = "CHILD";
							n=3;
							break;
				default:	message = "PARENT";
							n=5;
							break;
		}
		for(; n>0;n--)
		{
				puts(message);
				sleep(1);				
		}
		if(pid>0)
		{
				printf("child proc state : ZOMBIE, about %d sec\n", MYTIME);
				sleep(MYTIME);
				wait(NULL);
		}
		exit(0);
}



