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
    int linelength = strlen(line);
    int midpointindex = (linelength - 1) / 2;

    int counter[52] = {};
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
      if (i < midpointindex) {
        counter[arrayindex] = 1;
      } else {
        if (counter[arrayindex] == 1) {
          counter[arrayindex] += 1;
        }
      }
    }

    // Find overlap index
    for (int i = 0; i < 52; i++) {
      if (counter[i] == 2) {
        total += (i + 1);
      }
    }
  }

  printf("TOTAL is %d\n", total);
  fclose(fp);
  free(line);
  return 0;
}

