#include<pthread.h>
#include<stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include<semaphore.h>
#include<unistd.h>

void *func1();
void *func2();

sem_t s;
int x;
int data[2];


int main()
{
    sem_init(&s,0,0);
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, func1, NULL);
    pthread_create(&thread2, NULL, func2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2,NULL);

    char file[200];


    printf("Entering Main thread...\n");

    data[1]=open("/home/Desktop/mine/lab5/data.txt",  O_RDONLY);


    printf("Data (stored in file) : ");
    x = read(data[1], file, 200); // printing the file stored in file

    file[x] = '\0';
    printf("%s", file);
}

void *func1()
{

    printf("Thread 1 (entering)...\n");

    data[0]=open("/home/Desktop/mine/lab5/data.txt",  O_CREAT | O_RDWR); //opens data.txt in read and write mode 

    sem_post(&s); 

    printf("File created\n");

    printf("Thread 1 (exit)\n\n");

}

void *func2()
{
    sem_wait(&s); 


    printf("Thread 2 (entering)...\n");
    char result[200];
    
    printf("Content (to be stored in file) : \n");
    x = read(0, result,200); // take data from user and store it in the file

    write(data[0], result, x);

    sem_post(&s);

    printf("Thread 2 (exit)\n\n");

}