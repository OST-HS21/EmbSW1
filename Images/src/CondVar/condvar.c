/******************************************************************************
* FILE: condvar.c
* DESCRIPTION:
*   Example code for using Pthreads condition variables.  The main thread
*   creates three threads.  Two of those threads increment a "count" variable,
*   while the third thread watches the value of "count".  When "count" reaches
*   a predefined limit (countLimit), the waiting thread is signaled by one of the
*   incrementing threads. The waiting thread "awakens" and then modifies
*   count. The program continues until the incrementing threads reach
*   maxCount. The main program prints the final value of count.
* SOURCE: Adapted from example code in "Pthreads Programming", B. Nichols
*   et al. O'Reilly and Associates. 
* LAST REVISED: 10/14/10  Blaise Barney
*               04/05/2016 Reto Bonderer              
******************************************************************************/
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

enum {maxCount = 10,
      numThreads = 3,
      countLimit = 12};

volatile static int    count = 0;
static pthread_mutex_t countMutex;
static pthread_cond_t  countThresholdCv;

void* incCount(void* t);
void* watchCount(void* t); 

void* incCount(void* t) {
  int myId = *(int*)t;

  printf("Starting incCount(): thread %d\n", myId);

  for (int i = 0; i < maxCount; ++i) {
    pthread_mutex_lock(&countMutex);
    ++count;

    // Check the value of count and signal waiting thread when condition is
    // reached.  Note that this occurs while mutex is locked. 
    while (count == countLimit) {
      printf("threshold reached. ");
      pthread_cond_signal(&countThresholdCv);
      printf("Just sent signal.\n");
    }
    
    pthread_mutex_unlock(&countMutex);

    // Do some work so threads can alternate on mutex lock
    sleep(1);
  }
  pthread_exit(0);
}

void* watchCount(void* t) {
  int myId = *(int*)t;

  pthread_mutex_lock(&countMutex);
  while (count < countLimit) {
    printf("going into wait...\n");
    pthread_cond_wait(&countThresholdCv, &countMutex);
    printf("condition signal received.\n");
    printf("updating the value of count...\n");
    count += 125;
    printf("count now = %d.\n", count);
  }
  pthread_mutex_unlock(&countMutex);
  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  int            t[numThreads] = {1, 2, 3};
  pthread_t      threads[numThreads];
  pthread_attr_t attr;

  // Initialize mutex and condition variable objects
  pthread_mutex_init(&countMutex, 0);
  pthread_cond_init (&countThresholdCv, 0);

  // For portability, explicitly create threads in a joinable state 
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
  pthread_create(&threads[0], &attr, watchCount, (void*)&t[0]);
  pthread_create(&threads[1], &attr, incCount, (void*)&t[1]);
  pthread_create(&threads[2], &attr, incCount, (void*)&t[2]);

  // Wait for all threads to complete
  for (int i = 0; i < numThreads; ++i) {
    pthread_join(threads[i], 0);
  }

  // Clean up and exit
  pthread_attr_destroy(&attr);
  pthread_mutex_destroy(&countMutex);
  pthread_cond_destroy(&countThresholdCv);
  pthread_exit(0);
}

