#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void mystery(short arr[], int len) {
  printf("%d ", len);
  printf("%d\n", sizeof(arr));
}

int main() {
  short nums[] = {1, 2, 3, 99, 100};
  printf("%d ", sizeof(nums));

  mystery(nums, sizeof(nums)/sizeof(short));

  return 0;
}
