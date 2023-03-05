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
void rec_handler(int signum); 

int main(){

    // create a shared memory in the main. 
    int shmid; 
    key_t key = IPC_PRIVATE; 
    int flag = SHM_R | SHM_W; 
    shmid = shmget(key , 1000 , flag | IPC_CREAT); 
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
    if(rpid == 0){
        // child process => recruiter
    
        // student process created right after
        pid_t spid = fork(); 
        if(spid == 0){
            // student child created by recruiter.
            signal(SIGUSR1 , student_handler); 
            // halt the child processes.
            pause(); 
            int* shms = shm; 
            int s1 = *shms; 
            shms++; 
            int s2 = *shms; 
            shms++;
            int mul = rand()%2; 
            int ans = (s1+s2)*mul; 
            *shms = ans;
            printf("Send kill to parent \n"); 
            sleep(1); 
            kill(getppid() , SIGUSR2); 
            exit(1);    
        }else if(spid == -1){
            perror("Fork"); 
            exit(1); 
        }else{
            signal(SIGUSR2 , rec_handler);
            int num1 = rand()%100; 
            int num2 = rand()%100;
            int* shmr = shm;  
            *shmr = num1;
            shmr++; 
            *shmr = num2;
            printf("Send kill to student \n"); 
            sleep(1);  
            int kp = kill(spid , SIGUSR1);
            if(kp == -1){
                perror("Kill Signal"); 
                exit(1); 
            }
            pause(); 
            shmr = shm; 
            int realAns = num1+num2; 
            int n1 = *shmr; 
            shmr++; 
            int n2 = *shmr; 
            shmr++; 
            int temp = *shmr; 
            printf("%d %d %d" , n1 , n2 ,temp); 
            if(temp == realAns){
                printf(" Not an Imposter \n"); 
            }else{
                printf(" Imposter \n"); 
            }
        }
        while(wait(NULL) != -1); 
    }
    while(wait(NULL) != -1); 
    shmdt((void*) shm); 
    shmctl(shmid , IPC_RMID , 0); 
    return 0; 
}

void student_handler(int signum){
    printf("Send Signal to student \n"); 
}

void rec_handler(int signum){
    printf("Send signal to recruiter \n"); 
}