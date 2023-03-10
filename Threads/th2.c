#include<pthread.h> 
#include<stdio.h>
#include<asm/unistd.h>
int sum;
void *runner(void *param);
int main(int argc,char *argv[])
{
	sum=0; 
	pthread_t tid1, tid2;	
	pthread_attr_t attr; 
	pthread_attr_init(&attr); 
	pthread_create(&tid1,&attr,runner,argv[1]); 
	pthread_create(&tid2,&attr,runner,argv[2]); 
//	pthread_join(tid1,NULL); 
//	pthread_join(tid2,NULL); 
	printf("Main Thread: sum = %d \n",sum);
}

// runner function
void *runner ( void *param )
{ 	
	int upper=atoi(param);
 	int i; 
	if (upper>0) 
	{
		for ( i=1; i <= upper; i++ ) 
	   	{ 
			sum = sum + i;
	   	}
	}
	printf("New Thread: sum = %d \n",sum);
	pthread_exit(0);
}
