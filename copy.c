#include <stdio.h> //printf
#include <fcntl.h> //O_WRONLY
#include <unistd.h> //write(), close()

#define BUF_SIZE 1
//#define DEBUG

int main(int argc, char **argv)
{
#ifdef DEBUG
	printf("argc=%d\n", argc);
	printf("argv[1]=%s\n", argv[1]);
	printf("argv[2]=%s\n", argv[2]);
#endif

	int fd1, fd2, len;
	char buff[BUF_SIZE];
 
	fd1 = open(argv[1], O_RDONLY);		// OPEN FILE, FAIL-> return -1
	if(fd1 ==-1)
			printf("%s OPEN ERROR\n" ,argv[1]);

	fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644); 
	if(fd2 == -1)
			printf("%s OPEN ERROR\n", argv[2]);

	while((len=read(fd1, buff, sizeof(buff))) >0)
			write(fd2, buff, len);

	close(fd1);
	close(fd2);

	return 0;
}

