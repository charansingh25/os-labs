#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

pthread_t producer_t, consumer_t;

sem_t buf_mutex;
sem_t empty_ct;
sem_t fill_ct;


int* buff; // Buffer pointer
int buf_pos = -1;
int buf_size; // Size of the buffer

int produce(pthread_t self) {

    int product = 1 + rand() % 40;
    printf("Producer (product): %d\n", product);
    return product;
}

void consume(int product, pthread_t self) {
    printf("Consumer (product): %d\n", product);
    printf("Buffer contents: %d\n", buff[buf_pos]);
}

void *producer(void *args) {
    int i = buf_size;
    int j = 0;
    while (j<i) {

        int product = produce(pthread_self());

        sem_wait(&empty_ct);
        sem_wait(&buf_mutex);
        
        buff[buf_pos] = product;
        
        sem_post(&buf_mutex);
        sem_post(&fill_ct);
        
        sleep(1 + rand() % 5);
        j++;
    }
    return NULL;
}

void *consumer(void *args) {
    int i = buf_size;
    int j = 0;
    int product;
    while (j<i) {
        
        sem_wait(&fill_ct);
        sem_wait(&buf_mutex);
        
        product = buff[buf_pos];
        
        consume(product, pthread_self());
        sem_post(&buf_mutex);
        sem_post(&empty_ct);
        sleep(1 + rand() % 5);

        j++;
    }

    return NULL;
}

int main(void) {

    srand(time(NULL));
   
    sem_init(&buf_mutex, 0, 1);
    sem_init(&fill_ct, 0, 0);
    sem_init(&empty_ct, 0, 1);

    
    printf("Enter buffer size: ");
    scanf("%d", &buf_size);
    buff = (int*)malloc(buf_size * sizeof(int)); // Allocate the buffer

    pthread_create(&producer_t, NULL, producer, NULL);
    pthread_create(&consumer_t, NULL, consumer, NULL);

    pthread_join(producer_t, NULL);
    pthread_join(consumer_t, NULL);

    free(buff); 
    return 0;
}