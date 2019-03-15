#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <wait.h>

int global=10;

int main(void)
{
		int i = 20;
		pid_t pid;
		int status;

		pid =fork();

		if(pid == 0)
		{
				global+=10;
				i+=10;
		}
		else
		{
				global+=100;
				i+=100;
		}
		wait(&status);
		printf("global = %d, i=%d\n", global, i);
}
