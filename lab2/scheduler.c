#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){

	int n;
	//printf("Enter number of processes : ");
	//scanf("%d\n", &n);
    pid_t pid[5];
    for (int i = 0; i<5; i++){
        pid[i] = fork();
        if ( pid[i] == 0){  
            printf("[child] pid %d from [parent] pid %d\n",getpid(),getppid());
            //kill(getpid(), SIGSTOP);
            exit(0);
        }
    }
}
