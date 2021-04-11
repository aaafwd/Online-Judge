/* @JUDGE_ID: 19899RK 554 C++ "By Anadan" */
// Caesar Cypher
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sort_function(const void *a, const void *b) {
  return strcmp((char *)a, (char *)b);
}

int main() {
  int N, k, i, best_c, best_k;
  char dict[101][21], str[251], tmp[251], *p, *q;

  N = 0;
  while (scanf("%s ", dict[N]) == 1 && dict[N][0] != '#') ++N;
  fgets(str, sizeof(str), stdin);
  p = str + strlen(str) - 1;
  if (*p == '\n') *p = 0;

  best_c = -1;
  qsort(dict, N, sizeof(dict[0]), sort_function);
  for (k = 1; k <= 26; ++k) {
    for (p = str, q = tmp; *p; ++p, ++q) {
      if (*p == ' ')
        i = 0;
      else
        i = *p - 'A' + 1;
      i = (27 + i - k) % 27;
      if (i == 0)
        *q = ' ';
      else
        *q = 'A' + i - 1;
    }
    *q = 0;

    i = 0;
    p = strtok(tmp, " ");
    while (p) {
      if (bsearch(p, dict, N, sizeof(dict[0]), sort_function)) ++i;
      p = strtok(NULL, " ");
    }

    if (best_c < i) {
      best_c = i;
      best_k = k;
    }
  }

  for (p = str, q = tmp; *p; ++p, ++q) {
    if (*p == ' ')
      i = 0;
    else
      i = *p - 'A' + 1;
    i = (27 + i - best_k) % 27;
    if (i == 0)
      *q = ' ';
    else
      *q = 'A' + i - 1;
  }
  *q = 0;

  p = tmp;
  while (*p) {
    while (*p && *p == ' ') ++p;
    k = strlen(p);
    if (k == 0) break;
    if (k <= 60) {
      for (q = p + k - 1; *q == ' '; --q) *q = 0;
      printf("%s\n", p);
      break;
    }

    q = p + 60;
    while (*q != ' ') --q;
    for (char* r = q; *r == ' ' && r >= p; --r) *r = 0;
    printf("%s\n", p);
    p = q + 1;
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

