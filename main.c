#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void* func(void* ptr);

int main(int argc, char** argv) {
  // Thread handles
  pthread_t thread1, thread2;
  char *message1 = "Thread 1";
  char *message2 = "Thread 2";

  // Create threads
  int iret1 = pthread_create(&thread1, NULL, func, (void*) message1);
  int iret2 = pthread_create(&thread2, NULL, func, (void*) message2);

  pthread_join(thread1, NULL);
  pthread_join(thread2, NULL);

  printf("Thread 1 returns: %d\n", iret1);
  printf("Thread 2 returns: %d\n", iret2);
  
  return EXIT_SUCCESS;
}

void* func(void* ptr) {
  char* message;
  message = (char*) ptr;
  printf("%s \n", message);
}
