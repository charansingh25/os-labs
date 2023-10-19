#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *func_for_thread(void *arg);

int i, n, j;
int main(){
    pthread_t t1;
    pthread_create(&t1, NULL, func_for_thread, NULL);
    //pthread_join(t1, NULL);
    printf("Entering main thread...\n");
    for(j=0; j<5; j++){
        printf("Main : %d\n", j+1);
        //sleep(1);
    }
}

void *func_for_thread(void *arg){

    printf("Entering thread...\n");
    for(i=0; i<5; i++){
        printf("thread : %d\n", i+1);
        //sleep(1);
    }
}