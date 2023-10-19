#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *func_for_thread(void *arg);
int data[2] = {10, 5};
int summ = 0;
int i, n, j;
int main(){
    pthread_t t1;
    void *result;

    pthread_create(&t1, NULL, func_for_thread, (void*)data);
    pthread_join(t1, &result);
    printf("Entering main thread...\n");
    
    printf("The result is : %d\n", *(&result));
}

void *func_for_thread(void *arg){

    
    printf("Entering thread...\n");
    
    int *x = arg;

    summ = x[0] + x[1];
    pthread_exit(&summ); 

}