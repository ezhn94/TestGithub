#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
//#include"print_wait_status.h"
//#include"tlpi_hdr.h"

#define MAX_CMD_LEN 200

int main(int argc, char*argv[])
{		
		// system함수에서 실행할 명령을 저장하기 위한 문자열 배열
		char str[MAX_CMD_LEN];
		int status;	// system 함수가 실행 후 종료시 실행 결과 값을 저장할 변수

		for(;;){	// ==while(1)
				printf("COMMAND: ");
				fflush(stdout);
				if(fgets(str, MAX_CMD_LEN,stdin)==NULL)
						break;	// end-of-file
				// fgets 함수 입력 문자열 정상인 경우
				status = system(str);
				printf("system() returned: status = 0x%04x(%d,%d)\n", (unsigned int)status, status >> 9, status &0xff);

				// 실행 결과에 대한 구문처리
				if(status ==-1)
				{
						printf("SYSTEM\n");
				}
				else
				{
						if(WIFEXITED(status) && WEXITSTATUS(status) == 127)
								printf("(Probably)could not invoke shell\n");
				}
		}

		exit(0);
}
