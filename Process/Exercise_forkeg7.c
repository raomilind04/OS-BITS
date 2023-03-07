#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include <sys/wait.h>

int x;
int main(int argc, char *argv[])
{
	int i;
	x=1923;
	printf("Parent is %d\n\n",getpid());
	for(i=0;i<2;i++)
	{
		if(fork())
		{ x=x+10;}	
		else if(fork())
		{
			x=x+x;
		}
		else if(!fork())
		{
			x=x-30;
			while(wait(NULL)!=-1); 
			printf("PID = %d, PPID = %d, x=%d Check EXIT\n",getpid(),getppid(),x);
			exit(0);
		}
		else
		{
			x=x-50;
			while(wait(NULL)!=-1); 
			printf("PID = %d, PPID = %d, x=%d Check exec\n",getpid(),getppid(),x);
			execl("/bin/ls","ls",(char *)0);
			x=x+40;
		}
		
	}
	while(wait(NULL)!=-1); 
	x=x-2;
	printf("PID = %d, PPID = %d, x=%d Check END\n",getpid(),getppid(),x);
	return 0;
}
