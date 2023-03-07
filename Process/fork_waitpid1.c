#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<stdlib.h>
#include<sys/types.h>
#include<signal.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t var1;
	int status, termret,var2;
	
	//for(var2=0; var2<3;var2++)
	//{
		var1=fork();
		if(var1<0)
		{
			perror("fork failed\n");
			exit(1);
		}
		else if(var1==0)
		{
			kill(getpid(),SIGSTOP);
			printf("I am in Child process with PID %d, I am exiting\n",getpid());
			//exit(2);
			return 2;
		}
		else
		{
			printf("I am in Parent process with PID %d\n",getpid());
		}	 
		termret=waitpid(var1,&status,WUNTRACED); 
		printf("Child with PID %d received signal\n",termret);
		kill(var1,SIGCONT);
		
		termret=waitpid(var1,&status,0); 
		printf("Child with PID %d received signal, exit status is %d\n",termret,(status/256));
	//}
	
	return 0;
}
