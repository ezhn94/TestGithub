#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>

void pr_exit(int status)
{
		// 정상종료
		if(WIFEXITED(status))
				printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
		// 시그널에 의해 종료
		else if(WIFSIGNALED(status))
				printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status), WCOREDUMP(status) ? "(core file generated)" : "");
		// 시그널에 의해 STOP된 경우
		else if(WIFSTOPPED(status))
				printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}
int main()
{
		pid_t pid;
		int status;

		if((pid = fork())<0)	printf("fork error\n");
		else if(pid == 0) 		exit(7);

		if(wait(&status)==pid)	pr_exit(status);

		if((pid = fork())<0)	printf("fork error\n");
		else if(pid == 0)	abort();

		if(wait(&status) == pid)pr_exit(status);
		
		if((pid = fork())<0)	printf("fork error\n");
		else if(pid == 0)	status /= 0;

		if(wait(&status) == pid)pr_exit(status);
										
}
