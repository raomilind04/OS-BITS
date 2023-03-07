#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

void student_handler(int signum); 

int main(){

    // create a shared memory in the main.
    int shmid; 
    key_t key = IPC_PRIVATE; 
    int flag = SHM_R | SHM_W; 
    shmid = shmget(key , 1024 , flag | IPC_CREAT); 
    if(shmid < 0){
        perror("shmid"); 
        exit(1); 
    }
    int* shm; 
    shm = (int*)shmat(shmid , NULL , 0); 
    if(shm == (int*)-1){
        perror("shm"); 
        exit(1); 
    }

    //setting seed value for the random number. 
    srand(time(0)); 

    //creating different processes. 

    pid_t rpid = fork(); 
    if(rpid == -1){
        perror("fork"); 
        exit(1); 
    }
    if(rpid == 0){
        // child process => recruiter
        // student process created right after
        pid_t spid = fork(); 
        if(spid == -1){
            perror("fork"); 
            exit(1); 
        }
        if(spid == 0){
            // kill(getpid() , SIGSTOP); 
            // sleep(1); 

            signal(SIGUSR1 , student_handler);
            // halt the child processes.
            pause(); 
            // kill(getpid() , SIGSTOP); 
            int* shms = shm; 
            int s1 = *shms; 
            shms++; 
            int s2 = *shms; 
            shms++;
            int mul = rand()%2; 
            int ans = (s1+s2)*mul;
            exit(ans); 
        }else{
            int num1 = rand()%20; 
            int num2 = rand()%20;
            int* shmr = shm;  
            *shmr = num1;
            shmr++; 
            *shmr = num2;
            int ans = num1+num2; 
            
            // kill(spid , SIGCONT); 
            printf("Send kill to student \n"); 
            sleep(1);  
            int kp = kill(spid , SIGUSR1);
            if(kp == -1){
                perror("Kill Signal"); 
                exit(1); 
            }
            printf("%d %d " , num1 , num2); 
            int status , retVal; 
            retVal = waitpid(spid , &status , 0); 
            printf("%d" , status/256); 
            if(ans == (status/256)){
                printf(" Not an imposeter \n"); 
            }else{
                printf(" Imposeter \n"); 
            }
        }
        
    }
    while(wait(NULL) != -1); 
    shmdt((void*) shm); 
    shmctl(shmid , IPC_RMID , 0); 
    return 0; 
}

void student_handler(int signum){
    printf("Send Signal to student \n"); 
}
