#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
  FILE* fp;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen("./input.txt", "r");
  if (fp == NULL) {
    printf("failed to read file\n");
    return 0;
  }

  int total = 0;

  while ((read = getline(&line, &len, fp)) != -1) {
    // track overlaps
    int track[100] = {};

    char* token;
    int itr = 0;
    int lengths[2] = {0, 0};
    while ((token = strsep(&line, ",")) != NULL) {
      int current = itr % 2;

      char* number;
      int rangeiter = 0;
      int range[2] = {0, 0};
      while ((number = strsep(&token, "-")) != NULL) {
        int index = rangeiter % 2;
        int num = atoi(number);
        range[index] = num;
        rangeiter += 1;
      }

      // loop through range
      for (int i = range[0]; i <= range[1]; i++) {
        track[i - 1] += 1;      // track overlap
        lengths[current] += 1;  // count length
      }

      itr += 1;  // increment iteration
    }

    // find out number of overlaps
    int overlaps = 0;
    for (int i = 0; i < 100; i++) {
      if (track[i] > 1) {
        overlaps += 1;
      }
    }

    if (overlaps >= lengths[0] || overlaps >= lengths[1]) {
      total += 1;
    }
  }

  printf("TOTAL is %d\n", total);
  fclose(fp);
  free(line);
  return 0;
}

