/* @JUDGE_ID: 19899RK 120 C++ "By Anadan" */
// Stacks of Flapjacks
// Accepted (0.000 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <stdlib.h>

int N;
char stack[30], diams[30];

int sort_function(const void *a, const void *b) {
  if (*((char *)a) > *((char *)b)) return -1;
  return 1;
}

void swapp(int i) {
  char *p = stack, *q = stack + i;
  while (p < q) {
    *p ^= *q;
    *q ^= *p;
    *p ^= *q;
    ++p;
    --q;
  }
}

int main() {
  int i, off;
  char str[256], *p;

  while (fgets(str, sizeof(str), stdin)) {
    for (p = str; *p != '\n'; ++p);
    *p = 0;
    printf("%s\n", str);
    N = 0;
    p = str;
    while (sscanf(p, "%d%n", &i, &off) > 0) {
      stack[N] = diams[N] = (char)i;
      p += off;
      ++N;
    }
    qsort((void *)diams, N, sizeof(char), sort_function);

    p = diams;
    off = 0;
    while (N > 1) {
      for (i = 0; i < N; i++) {
        if (stack[i] == *p) break;
      }
      if (i < N - 1) {
        if (i) {
          swapp(i);
          printf("%d ", N - i + off);
        }
        swapp(N - 1);
        printf("%d ", off + 1);
      }
      --N;
      ++p;
      ++off;
    }

    printf("0\n");
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
