#include <pthread.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

void *tellMe() {

  for (u_int8_t i = 0; i < 250000; i++) {
    printf("i = %d\n", i);
  }
  return NULL;
}

int main() {

  pthread_t secondThread;

  for (u_int8_t j = 0; j < 250000; j++) {
    printf("j = %d\n", j);
  }

  pthread_create(&secondThread, NULL, tellMe, NULL);
  pthread_join(secondThread, NULL);
  return 0;
}
