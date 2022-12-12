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
  int counter[52] = {};
  int linenumber = 0;

  while ((read = getline(&line, &len, fp)) != -1) {
    // track groups of 3
    int module = linenumber % 3;
    if (module == 0) {
      // reset the array on first of three
      memset(counter, 0, sizeof(counter));
    }

    for (int i = 0; i < strlen(line); i++) {
      // Skip new line character
      if (line[i] == '\n') {
        continue;
      }

      // Find ASCII digits and offset it to array index
      int digit = line[i];
      int arrayindex = 0;
      if (digit < 97) {
        arrayindex = digit - 65 + 26;
      }
      if (digit >= 97) {
        arrayindex = digit - 97;
      }

      // Track characters found twice in two segments divided by midpoint
      if (module == 0) {
        counter[arrayindex] = 1;
      }
      if (module == 1 && counter[arrayindex] == module) {
        counter[arrayindex] += 1;
      }
      if (module == 2 && counter[arrayindex] == module) {
        counter[arrayindex] += 1;
      }
    }

    /* Find overlap index */
    if (module == 2) {
      for (int i = 0; i < 52; i++) {
        if (counter[i] == 3) {
          total += (i + 1);
        }
      }
    }

    // Increment line count
    linenumber += 1;
  }

  printf("TOTAL is %d\n", total);
  fclose(fp);
  free(line);
  return 0;
}

