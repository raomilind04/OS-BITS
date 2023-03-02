#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<sys/types.h>
int main(int argc, char *argv[])
{
	printf("Process with PID=%d is executing\n",getpid());
	printf("My Parent ID is =%d \n",getppid());

	
	return 4;
}
