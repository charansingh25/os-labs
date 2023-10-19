#include<pthread.h>
#include<stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>
#include<semaphore.h>
#include<unistd.h>

void *T1();
void *T2();

sem_t s;
int n, fd[2];


int main()
{
sem_init(&s,0,0);
pthread_t thread1, thread2;
pthread_create(&thread1, NULL, T1, NULL);
pthread_create(&thread2, NULL, T2, NULL);
pthread_join(thread1, NULL);
pthread_join(thread2,NULL);

char c[100];


printf("Entering Main thread...\n");

fd[1]=open("/home/Desktop/mine/lab5/data.txt",  O_RDONLY);


printf("The data stored in the file is : ");
n = read(fd[1], c,100); // printing the file stored in file

c[n] = '\0';
printf("%s", c);
}

void *T1()
{
// using process syncrenisation using semaphores to run thread 1 firstly.

printf("Entering Thread 1...\n");

fd[0]=open("/home/Desktop/mine/lab5/data.txt",  O_CREAT | O_RDWR); //opens data.txt in read and write mode and the file descriptor is saved in integer fd.

sem_post(&s); // signals the semephore for thread 2.

printf("File created\n");

printf("Exiting Thread 1\n\n");

}

void *T2()
{
sem_wait(&s); //  semaphore check wait condition.


printf("Entering Thread 2...\n");
  char data[100];
 
  printf("Enter contents to store in file : \n");
    n = read(0, data, 100); // take data from user and store it in the file

    write(fd[0], data, n);

sem_post(&s); // signals semaphore again.

printf("Exiting Thread 2\n\n");

}