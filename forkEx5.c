#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <error.h>
#include <wait.h>

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
							n=5;
							break;
				default:	message = "PARENT";
							n=3;
							break;
		}
		for(; n>0;n--)
		{
				puts(message);
				sleep(1);				
		}
		wait(&status);
		exit(0);
}



