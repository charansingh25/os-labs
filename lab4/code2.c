#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main(){
    int i, n;
    void * shared_memory;
    char buff[100], input[100];
    int shmid;

    shmid = shmget((key_t)2345, 1024, 0666|IPC_CREAT);

    printf("Key of shared memory si %d\n", shmid);

    shared_memory = shmat(shmid, NULL, 0);

    printf("Process attached at %p\n", shared_memory);
    printf("Data recieved from shared memory is %s\n", (char *) shared_memory);
    
}