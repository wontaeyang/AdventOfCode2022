#include "stdio.h"
#include "string.h"

int calculate(char* moves) {
  if (strcmp(moves, "A X\n") == 0) {
    return 1 + 3;
  }
  if (strcmp(moves, "A Y\n") == 0) {
    return 2 + 6;
  }
  if (strcmp(moves, "A Z\n") == 0) {
    return 3 + 0;
  }

  if (strcmp(moves, "B X\n") == 0) {
    return 1 + 0;
  }
  if (strcmp(moves, "B Y\n") == 0) {
    return 2 + 3;
  }
  if (strcmp(moves, "B Z\n") == 0) {
    return 3 + 6;
  }

  if (strcmp(moves, "C X\n") == 0) {
    return 1 + 6;
  }
  if (strcmp(moves, "C Y\n") == 0) {
    return 2 + 0;
  }
  if (strcmp(moves, "C Z\n") == 0) {
    return 3 + 3;
  }

  return 0;
}

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
    printf("Move is %s", line);
    printf("Score is %d\n", calculate(line));
    total += calculate(line);
    printf("Total is %d\n\n", total);
  }

  printf("TOTAL is %d\n", total);
}

