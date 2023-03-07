#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include <sys/wait.h>

int x=0;
int main(int argc, char *argv[])
{
	int i;
	printf("fork program starting with pid %d\n",getpid());
	for(i=0;i<2;i++)
	{
		if(fork())
		{ x=x+5;}	
		else if(!fork())
		{	x=x+10;
			printf("My PID = %d and My PPID = %d and x value = %d\n",getpid(),getppid(),x);
			exit(0);
		}
		else
		{  x=x-2; }
	}
	x=x+15;
	printf("My PID = %d and My PPID = %d and x value = %d\n",getpid(),getppid(),x);
	while(wait(NULL)!=-1); 
	return 0;
}
