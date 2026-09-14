#if !defined( SEMAPHORE_H )
#define SEMAPHORE_H

typedef struct sem_t_ * sem_t;


int sem_init(sem_t * sem, int pshared, unsigned int value);

int sem_destroy(sem_t * sem);


int sem_wait (sem_t * sem);


int sem_post (sem_t * sem);

#endif