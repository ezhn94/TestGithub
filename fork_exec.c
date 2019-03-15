#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

void my_execv(const char *path, char *const argv[])
{
		int ret;
		pid_t pid;

		pid = fork();

		if(pid ==1)
		{
				printf("fork\n");
				exit(EXIT_FAILURE);
		}
		if(pid ==0)
		{
				ret = execv(path, argv);

				if(ret ==-1)
				{
						printf("execv\n");
						exit(EXIT_FAILURE);
				}
		}
		wait(NULL);
}
int main()
{
		char path[] = "/bin/ls";
		char *argv_ls[] = {"ls", "-al", NULL};
		
		my_execv(path, argv_ls);

		return 0;
}

		
