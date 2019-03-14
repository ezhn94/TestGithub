#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
	struct stat sb;
	
	if(argc!=2)
	{
		printf("USAGE: %s <pathname>\n", argv[0]);
	}
	if(stat(argv[1], &sb) == -1)
	{
		fprintf(stderr, "ERROR: stat()");
		return -1;
	}
	
	printf("====================================================\n");
	printf("FILE TYPE: ");
	switch(sb.st_mode & S_IFMT)
	{
	case S_IFBLK: 	printf("BLOCK DEVICE\n"); 	break;
	case S_IFCHR: 	printf("CHAR DEVICE\n");	break;
	case S_IFDIR: 	printf("DIRECTORY\n");		break;
	case S_IFIFO: 	printf("FIFO\n"); 			break;
	case S_IFLNK: 	printf("SYM LINK\n"); 		break;
	case S_IFREG: 	printf("REGULAR FILE\n"); 	break;
	case S_IFSOCK:	printf("SOCKET\n"); 		break;
	default:		printf("UNKNOWN\n");		break;
	}
	printf("I-NODE NUMBER:				%ld\n",				 (long)sb.st_ino);
	printf("MODE:						%lo (octal)\n",		 (unsigned long)sb.st_mode);
	printf("LINK COUNT:					%ld\n",				 (long)sb.st_nlink);
	printf("OWNERSHIP:					UID=%ld	GID=%ld\n",	 (long)sb.st_uid, (long)sb.st_gid);
	printf("PREFERREF I/O BLOCK SIZE:	%ld bytes\n",		 (long)sb.st_blksize);
	printf("FILE SIZE:					%lld bytes\n",		 (long long)sb.st_size);
	printf("BLOCKS ALLOCATED:			%lld\n",			 (long long)sb.st_blocks);
	printf("LAST STATUS CHANGE:			%s",				 ctime(&sb.st_ctime));
	printf("LAST FILE ACCESS:			%s",				 ctime(&sb.st_atime));
	printf("LAST FILE MODIFICATION:		%s",				 ctime(&sb.st_mtime));

	return 0;
}

