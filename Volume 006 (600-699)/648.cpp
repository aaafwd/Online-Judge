/* @JUDGE_ID: 19899RK 648 C++ "By Anadan" */
// Stamps (II)
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

int N, stamps[26], step, best_t, best_n, best_s[4], curr_s[4];
char mask[26], tie;

int sort_function(const void *a, const void *b) {
  if (*(int *)a < *(int *)b) return -1;
  return 1;
}

void generate(int n, int i, int total, int curr) {
  if (n == step) {
    if (curr) return;
    if (total > best_t) {
      curr = 1;
    } else if (total == best_t) {
      if (n < best_n) {
        curr = 1;
      } else if (n == best_n) {
        if (curr_s[n - 1] > best_s[n - 1]) {
          curr = 1;
        } else if (curr_s[n - 1] == best_s[n - 1]) {
          tie = 1;
          return;
        }
      }
    }

    if (curr) {
      tie = 0;
      best_n = n;
      best_t = total;
      for (i = 0; i < best_n; ++i) best_s[i] = curr_s[i];
    }

    return;
  }

  for (; i < N; ++i) {
    if (stamps[i] > curr) break;
    curr_s[n] = stamps[i];
    if (mask[i]) {
      generate(n + 1, i, total, curr - stamps[i]);
    } else {
      mask[i] = 1;
      generate(n + 1, i, total + 1, curr - stamps[i]);
      mask[i] = 0;
    }
  }
}

int main() {
  int i;

  while (1) {
    N = 0;
    while (scanf("%d", stamps + N) == 1 && stamps[N]) mask[N++] = 0;
    if (N == 0) break;
    qsort(stamps, N, sizeof(int), sort_function);

    while (scanf("%d", &i) == 1 && i) {
      best_t = 0;
      for (step = 1; step <= 4; ++step) {
        generate(0, 0, 0, i);
      }

      printf("%d ", i);
      if (best_t == 0) {
        printf("---- none\n");
      } else if (tie) {
        printf("(%d): tie\n", best_t);
      } else {
        printf("(%d):", best_t);
        for (i = 0; i < best_n; ++i) printf(" %d", best_s[i]);
        putchar('\n');
      }
    }
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
