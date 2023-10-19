#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
void *fun1();
void *fun2();
int shared=1; //shared variable

sem_t s;
int main()
{
    sem_init(&s, 0, 1);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, fun1, NULL);
    pthread_create(&thread2, NULL, fun2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2,NULL);
    printf("Final value of shared is %d\n",shared); //prints the last updated value of shared variable
}

void *fun1()
{
    int x;
    //
    sem_wait(&s);
    //
    x=shared;//thread one reads value of shared variable

    printf("Thread1 reads the value of shared variable as %d\n",x);
    
    x++; //thread one increments its value
    
    printf("Local updation by Thread1: %d\n",x);
    sleep(1);

    shared=x; //thread one updates the value of shared variable
    
    printf("Value of shared variable updated by Thread1 is: %d\n",shared);

    sem_post(&s);
}
void *fun2()
{
    int y;
    //
    sem_wait(&s);
    //

    y=shared;//thread two reads value of shared variable

    printf("Thread2 reads the value as %d\n",y);
    y--; //thread two increments its value

    printf("Local updation by Thread2: %d\n",y);
    sleep(1);
    
    shared=y; //thread one updates the value of shared variable

    printf("Value of shared variable updated by Thread2 is: %d\n",shared);
    sem_post(&s);
}