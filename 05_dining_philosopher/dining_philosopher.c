// Dining Philosopher Program

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t forks[N];
sem_t room;

void *philosopher(void *arg)
{
    int id = *(int *)arg;

    while (1)
    {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1);

        printf("Philosopher %d is hungry.\n", id);

        // Allow only 4 philosophers to try to pick forks
        sem_wait(&room);

        // Pick left fork
        sem_wait(&forks[id]);

        // Pick right fork
        sem_wait(&forks[(id + 1) % N]);

        printf("Philosopher %d is eating...\n", id);
        sleep(2);

        // Put down forks
        sem_post(&forks[id]);
        sem_post(&forks[(id + 1) % N]);

        printf("Philosopher %d finished eating.\n", id);

        sem_post(&room);
    }

    return NULL;
}

int main()
{
    pthread_t philosophers[N];
    int id[N];

    // Initialize forks
    for (int i = 0; i < N; i++)
    {
        sem_init(&forks[i], 0, 1);
    }

    // Only 4 philosophers can compete for forks
    sem_init(&room, 0, N - 1);

    // Create philosopher threads
    for (int i = 0; i < N; i++)
    {
        id[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &id[i]);
    }

    // Wait for threads
    for (int i = 0; i < N; i++)
    {
        pthread_join(philosophers[i], NULL);
    }

    return 0;
}
