#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
		pid_t pid;
		char *message;
		int n;
		int exit_code;
		printf("fork program starting\n");
		pid = fork();
		switch(pid)
		{
				case -1: printf("fork failed\n");
						 exit(1);
				case 0: message = "this is the child";
						n = 5;
						exit_code = 37;
						break;
				default: message = "this is parent";
						 n = 3;
						 exit_code = 0;
						 break;
		}
		for(;n>0;n--)
		{
				puts(message);
				sleep(1);
		}

		if(pid !=0)
		{
				int stat_val;
				pid_t child_pid;

				child_pid=wait(&stat_val);
				printf("child has finished: PID = %d\n", child_pid);
				if(WIFEXITED(stat_val))
						printf("child exited with code %d\n", WEXITSTATUS(stat_val));
				else
						printf("child terminated abnormally\n");
		}
		exit(exit_code);
}
