#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>
#include <sys/time.h> // getimeofday( ) 함수에서 사용

void access_perm(char *perm, mode_t mode)
{
		int i;
		char permchar[] ="rwx";
		memset(perm, '-',10);
		perm[10]='\0';

		if(S_ISDIR(mode))perm[0] ='d';
		else if(S_ISCHR(mode))perm[0] ='c';
		else if(S_ISBLK(mode))perm[0] ='b';
		else if(S_ISFIFO(mode))perm[0] ='p';
		else if(S_ISLNK(mode))perm[0] ='l';
		
		for(i=0;i<9;i++){
				if((mode<<i)&0x100)
						perm[i+1]=permchar[i%3];
		}
		if(mode&S_ISUID)perm[3]='s';
		if(mode&S_ISGID)perm[6]='s';
		if(mode&S_ISVTX)perm[9]='t';
}
int main(int argc, char *argv[])
{
		DIR *dp;
		struct stat statbuf;
		struct dirent *dent;
		struct passwd *my_passwd;
		struct group  *my_group;

		char perm[11];
		char pathname[80];
		int i, j;
		time_t UTCtime;

		struct tm *tm2;

		char buf2[BUFSIZ];
		struct timeval UTCtime_u;
		
		
		
		if(argc<2)exit(1);

		stat(argv[1], &statbuf);
		if(!S_ISDIR(statbuf.st_mode)){
				fprintf(stderr, "%s IS NOT DIRECTORY\n", argv[1]);
				exit(1);
		}
		if((dp=opendir(argv[1])) == NULL){
				perror("ERROR:");
				exit(1);
		}
		printf("LISTS OF DIRECTORY(%s):\n", argv[1]);
		
		while((dent=readdir(dp))!=NULL){

				tm2 = localtime(&(statbuf.st_mtime));	
				strftime(buf2, sizeof(buf2), "%m월 %e일 %H:%M", tm2);
				my_passwd = getpwuid(statbuf.st_uid);
				my_group  = getgrgid(statbuf.st_gid);
				sprintf(pathname,"%s/%s", argv[1], dent->d_name);
				lstat(pathname, &statbuf);
				access_perm(perm, statbuf.st_mode);
				printf("%s %8ld	%6s  %6s  %5s  %6s\n", perm, statbuf.st_size, my_passwd->pw_name, my_group->gr_name, buf2, dent->d_name);
		}
		closedir(dp);	
		return 0;
}
