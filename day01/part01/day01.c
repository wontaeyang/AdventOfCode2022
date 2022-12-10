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

  int best = 0;
  int calories = 0;

  while ((read = getline(&line, &len, fp)) != -1) {
    if (line[0] == '\n') {
      if (calories > best) {
        best = calories;
      }
      printf("This elf is carrying %d\n", calories);
      calories = 0;
    }
    calories += atoi(line);
  }

  printf("Best is %d\n", best);

  fclose(fp);
  free(line);
}
