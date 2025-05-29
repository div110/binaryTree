#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct array {
  uint16_t size;
  uint16_t last;
  int *data;
};

int append(struct array *array, int64_t value) {

  if (array->size == array->last) {
    array->size = array->size * 2;
    array->data = realloc(array->data, array->size * sizeof(int));
  }
  array->data[array->last] = value;
  array->last++;

  return 0;
}

void printArray(struct array *array) {
  for (int i = 0; i < array->last; i++) {
    printf("%d|", array->data[i]);
  }
  for (int i = 0; i < array->size - array->last; i++) {
    printf("_|");
  }
  printf("\n");
}

void initArray(struct array *myArray) {
  myArray->data = malloc(2 * sizeof(int));
  myArray->size = 2;
  myArray->last = 0;
  printf("array initialized\n");
}

int main() {

  struct array myArray;
  initArray(&myArray);
  printArray(&myArray);
  append(&myArray, 1);
  append(&myArray, 2);
  append(&myArray, 4);
  append(&myArray, 8);
  append(&myArray, 16);
  append(&myArray, 1);
  append(&myArray, 2);
  append(&myArray, 4);
  append(&myArray, 8);
  append(&myArray, 16);
  printArray(&myArray);
  printf("size: %d\nlast: %d\n", myArray.size, myArray.last);

  return 0;
}
