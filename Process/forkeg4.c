#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>

int x=0;
int main(int argc, char *argv[])
{
	int i;
	printf("fork program starting with pid %d\n",getpid());
	for(i=0;i<3;i++)
	{
		fork();
		x=x+5;
	//	printf("My pid is %d\n",getpid());
	}
	printf("My PID = %d and My PPID = %d and x value = %d\n",getpid(),getppid(),x);
//	printf("I am %d.... outside the loop\n",getpid());
	while(wait(NULL)!=-1); 
	return 0;
}
