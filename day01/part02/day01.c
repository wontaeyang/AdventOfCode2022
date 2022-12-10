#include "day01.h"

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int main() {
  FILE* fp;
  char* line = NULL;
  size_t len = 0;
  ssize_t read;
  char* newline = "\n";

  fp = fopen("./input.txt", "r");
  if (fp == NULL) {
    printf("failed to read file\n");
    exit(1);
  }

  int current = 0;
  int top[3] = {0, 0, 0};

  while ((read = getline(&line, &len, fp)) != -1) {
    if (line[0] == '\n') {
      // add current total to top roster if current calories are bigger than the
      // lowest value of the roster
      if (current > top[2]) {
        top[2] = current;

        // Sort the array in order
        int i, j, tmp;
        for (i = 0; i < 3 - 1; i++) {
          for (j = i + 1; j < 3; j++) {
            if (top[i] < top[j]) {
              tmp = top[i];
              top[i] = top[j];
              top[j] = tmp;
            }
          }
        }

        printf("Sorted roster: %d, %d, %d\n", top[0], top[1], top[2]);
      }

      // reset current for next elf
      current = 0;
      continue;
    }

    // add to current elf total
    current += atoi(line);
  }

  printf("Top three elf total is %d\n", top[0] + top[1] + top[2]);

  fclose(fp);
  free(line);
}
