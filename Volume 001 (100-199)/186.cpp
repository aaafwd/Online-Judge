/* @JUDGE_ID: 19899RK 186 C++ "By Anadan" */
// Trip Routing
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SZ 100

int N;
struct City {
  char name[32];
  int index;
} pt[SZ];

struct Route {
  char name[11];
  int value;
} map[SZ][SZ];
int e[SZ][SZ];

int getindex(char *p) {
  int i;
  for (i = 0; i < N; ++i) {
    if (strcmp(p, pt[i].name) == 0) return i;
  }
  strcpy(pt[N].name, p);
  pt[N].index = N;
  return N++;
}

void outprint(int i, int j) {
  while (e[i][j] != -1) {
    outprint(i, e[i][j]);
    i = e[i][j];
  }
  printf("%-20s %-20s %-10s %5d\n", pt[i].name, pt[j].name, map[i][j].name,
         map[i][j].value);
}

void consume_endline(char *p) {
  p += strlen(p) - 1;
  if (*p == '\n') *p = 0;
}

int main() {
  int i, j, k;
  char str[260], *p, *q;

  N = 0;
  for (i = 0; i < SZ; ++i) {
    for (j = 0; j < SZ; ++j) {
      map[i][j].value = e[i][j] = -1;
    }
  }

  while (fgets(str, sizeof(str), stdin)) {
    consume_endline(str);
    if (!str[0]) break;

    p = strtok(str, ",");
    i = getindex(p);
    p = strtok(NULL, ",");
    j = getindex(p);
    p = strtok(NULL, ",");
    q = strtok(NULL, ",");
    sscanf(q, "%d", &k);
    if (map[i][j].value == -1 || map[i][j].value > k) {
      map[i][j].value = k;
      strcpy(map[i][j].name, p);
    }
    if (map[j][i].value == -1 || map[j][i].value > k) {
      map[j][i].value = k;
      strcpy(map[j][i].name, p);
    }
  }

  for (k = 0; k < N; ++k) {
    for (i = 0; i < N; ++i) {
      if (i == k || map[i][k].value == -1) continue;
      for (j = 0; j < N; ++j) {
        if (j == k || map[k][j].value == -1) continue;
        if (map[i][j].value == -1 ||
            map[i][j].value > map[i][k].value + map[k][j].value) {
          map[i][j].value = map[i][k].value + map[k][j].value;
          e[i][j] = k;
        }
      }
    }
  }

  while (fgets(str, sizeof(str), stdin)) {
    consume_endline(str);
    p = strtok(str, ",");
    i = getindex(p);
    p = strtok(NULL, ",");
    j = getindex(p);

    printf("\n\n");
    printf("From                 To                   Route      Miles\n");
    printf("-------------------- -------------------- ---------- -----\n");
    outprint(i, j);
    printf("%-53s-----\n%-42sTotal      %5d\n", " ", " ", map[i][j].value);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
