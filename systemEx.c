#include<stdio.h>
#include<stdlib.h>

int main()
{
		printf("RUNNING PS WITH SYSTEM\n");
		system("ps -ax&");
		printf("DONE.\n");

		exit(0);
}
