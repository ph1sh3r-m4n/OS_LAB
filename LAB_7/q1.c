#include <pthread.h>  
#include <semaphore.h>  
#include <stdlib.h>     
#include <stdio.h>      
#include <unistd.h>     
#define MAX_BUFFER_SIZE 5
int buffer[MAX_BUFFER_SIZE];
int in = 0;  
int out = 0; 
sem_t empty, full, mutex;
void* producer(void* arg) {
    int item;
    while (1) {
        item = rand() % 100;
        printf("Produced: %d\n", item);
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[in] = item;
        in = (in + 1) % MAX_BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&full);
        sleep(1);}}
void* consumer(void* arg) {
    int item;
    while (1) {
        sem_wait(&full);
        sem_wait(&mutex);
        item = buffer[out];
        out = (out + 1) % MAX_BUFFER_SIZE;
        sem_post(&mutex);
        sem_post(&empty);
        printf("Consumed: %d\n", item);
        sleep(1);}}
int main() {
    pthread_t prod, cons;
    sem_init(&empty, 0, MAX_BUFFER_SIZE); 
    sem_init(&full, 0, 0);                
    sem_init(&mutex, 0, 1);               
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    return 0;}
