#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
sem_t readCountLock;    
sem_t resourceAccess;   
int readCount = 0;      
void* reader(void* arg) {
    int reader_id = *((int*)arg);
    sem_wait(&readCountLock);
    readCount++;
    if (readCount == 1) {
        sem_wait(&resourceAccess);}
    sem_post(&readCountLock);
    printf("Reader %d is reading the data.\n", reader_id);
    sem_wait(&readCountLock);
    readCount--;
    if (readCount == 0) {
        sem_post(&resourceAccess);}
    sem_post(&readCountLock);
    return NULL;}
void* writer(void* arg) {
    int writer_id = *((int*)arg);
    sem_wait(&resourceAccess);
    printf("Writer %d is writing the data.\n", writer_id);
    sem_post(&resourceAccess);
    return NULL;}
int main() {
    pthread_t readers[3], writers[3];
    int reader_ids[3] = {1, 2, 3};
    int writer_ids[3] = {1, 2, 3};
    sem_init(&readCountLock, 0, 1);  
    sem_init(&resourceAccess, 0, 1); 
    for (int i = 0; i < 3; i++) {pthread_create(&readers[i], NULL, reader, (void*)&reader_ids[i]);}
    for (int i = 0; i < 3; i++) {pthread_create(&writers[i], NULL, writer, (void*)&writer_ids[i]);}
    for (int i = 0; i < 3; i++) {pthread_join(readers[i], NULL);}
    for (int i = 0; i < 3; i++) {pthread_join(writers[i], NULL);}
    sem_destroy(&readCountLock);
    sem_destroy(&resourceAccess);
    return 0;}
