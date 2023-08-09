#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t semaphore;

void* thread(void* arg) {
    sem_wait(&semaphore);
    printf("\nEntered..\n");
    sleep(4);
    printf("\nJust Exiting...\n");
    sem_post(&semaphore);
    return NULL;
}

int main() {
    sem_init(&semaphore, 0, 1);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread, NULL);
    sleep(2);
    pthread_create(&t2, NULL, thread, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&semaphore);
    return 0;
}
