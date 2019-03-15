#include <stdio.h>		// printf()
#include <unistd.h>		// fork()
#include <sys/types.h>
#include <wait.h>

int main(void)
{
	pid_t pid;
	int x = 0;
	int status;

	x=1;

	if((pid=fork())==0)
	{	
		printf("pid = %ld, I am process %ld getppid =  %ld\n",(long)pid, (long)getpid(), (long)getppid());
		sleep(1);
		printf("DONE\n");
		return 0;	// 자식 프로세스는 if문을 빠져나가지 않고 끝난다.
	}
	else
		printf("pid = %ld, I am process %ld\n", (long)pid, (long)getpid());

	wait(&status);	// 자식 프로세스가 종료할때까지 기다린다.

	return 0;
}

