#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if(execl("/usr/bin/ls", "ls", "-al", NULL) == -1) {
        fprintf(stderr, "execve error: %s\n", strerror(errno));
        return 1;
    }
    /* ls 명령어 binary로 실행로직이 교체되었으므로 이후의 로직은 절대 실행되지 않습니다. */
    printf("this is ls.\n");
    return 0;
}


// --------------------------------------------------------------------

/*
실행방법

sample1 -al <enter>

결과는 ls -al 한 것과 같음.
*/



