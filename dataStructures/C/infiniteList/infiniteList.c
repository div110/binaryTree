#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct array {
  uint16_t size;
  uint16_t free;
  int *data;
};

int append(struct array *array, int64_t value) { return 0; }

int main() {

  struct array array1;
  array1.size = 5;
  array1.free = 5;
  array1.data = NULL;
  append(&array1, 5);

  return 0;
}
