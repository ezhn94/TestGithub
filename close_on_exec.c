#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <stdio.h>

#define DEBUG

int main()
{
		int fd;
		int val;

		fd = open("exec_copy.txt", O_CREAT|O_TRUNC,0644);

		val = fcntl(fd, F_GETFD, 0);	// GET FD_CLOEXEC

#ifdef DEBUG
		if(val & FD_CLOEXEC)
				printf("close-on-exec bit on\n");
		else
				printf("close-on-exec bit off\n");
#endif
		val |= FD_CLOEXEC;				// MODIFY FD_CLOEXEC		

#ifdef DEBUG
		if(val & FD_CLOEXEC)
				printf("AFTER: close-on-exec bit on\n")
		else
				printf("AFTER: close-on-exec bit off\n")
#endif
		fcntl(fd, F_SETFD, val);		// SET FD_CLOEXEC

		// loop program exec
		execl("./loop", "./loop", (char*)0);

		return 0;
}
