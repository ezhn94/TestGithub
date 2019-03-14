#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1
int main(int argc, char **argv)
{
	int fd, len;
	int count = 0;
	int chk = 1;
	char buf[BUF_SIZE];

	fd = open(argv[1], O_RDONLY);
	if(fd == -1)
		printf("%s READ ERROR\n", argv[1]);
	
	while((len=read(fd, buf, sizeof(buf)))>0)
	{
		count++;
	}
	printf("%d\n", count);

	char buf2[100];

	FILE *fp = fopen(argv[1],"r");
	
	fgets(buf2, sizeof(buf2), fp);
	
	printf("%s\n", buf2);

	for(int i=0; i<count/2;i++)
	{
		printf("%c %c\n", buf2[i], buf2[count-2-i]);		
		if(buf2[i] == buf2[count-2-i])
		{
				chk*=1;
		}else
				chk*=0;
	}
	if(chk == 0)
	{
			printf("NO\n");
	}else
			printf("YES\n");

}
