#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	char *ps_argv[]={"ps","-ax",0};
	char *ps_envp[]={"PATH=/bin:/usr/bin", "TERM=console",0};
	printf("Program starts\n");
	pid=fork();
	if(pid<0)
	{
		printf("Program fails\n");
		exit(1);
	}
	else if(pid==0)
	{
		printf("In Child process to execute EXEC\n");
		execl("exe","exe",0);
//		execl("/bin/ps","ps","-ax",0);
//		execlp("ps","ps","-ax",0);
//		execle("/bin/ps","ps","-ax",0,ps_envp);
//		execv("/bin/ps",ps_argv);
//		execvp("ps",ps_argv);
//		execve("/bin/ps",ps_argv,ps_envp);
		printf("Exec failed!!\n");
		exit(5);
	}
	else
	{
		printf("From Parent process before wait\n");
		wait(NULL);
		printf("From Parent process after child exit\n");
	}
	return 0;
}
