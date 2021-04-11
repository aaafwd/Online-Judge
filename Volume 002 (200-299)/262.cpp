/* @JUDGE_ID: 19899RK 262 C++ "By Anadan" */
// Transferable Voting
// Accepted (0.010 seconds with low memory spent)

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>

struct Votes {
  int ptr, count, votes[32];
} pt[1024];

void ConsumeEndLine(char *str) {
  while (*str && *str != '\n') ++str;
  *str = 0;
}

int main() {
  int test_cases, N, V, valid, off, i, j, vote[20], min, rest;
  char names[32][32], str[256], *p, mask[32];

  scanf("%d\n\n", &test_cases);
  while (test_cases--) {
    N = 0;
    while (fgets(str, sizeof(str), stdin) && str[0] && str[0] != '\n') {
      ConsumeEndLine(str);
      if (sscanf(str, "%d.", &i) != 1) break;
      assert(i == N + 1);
      for (p = str; *p != ' '; ++p) {
      }
      while (*p == ' ') ++p;
      strcpy(names[N++], p);
    }

    V = valid = 0;
    while (fgets(str, sizeof(str), stdin) && str[0] && str[0] != '\n') {
      pt[V].count = pt[V].ptr = 0;
      memset(mask, 0, N);
      ++valid;
      for (p = str; sscanf(p, "%d%n", &i, &off) > 0; p += off) {
        --i;
        if (i < 0 || i >= N || mask[i]) {
          --valid;
          pt[V].count = 0;
          break;
        }
        mask[i] = 1;
        pt[V].votes[pt[V].count++] = i;
      }
      ++V;
    }

    rest = N;
    memset(mask, 0, N);
    int non_empty_ballots = V;
    while (rest) {
      if (rest == 1) {
        for (i = 0; i < N; ++i) {
          if (!mask[i]) break;
        }
        printf("The winner of the election is %s.\n", names[i]);
        break;
      }

      for (i = 0; i < N; ++i) vote[i] = 0;
      for (i = 0; i < non_empty_ballots; ++i) {
        while (pt[i].ptr < pt[i].count) {
          const int candidate = pt[i].votes[pt[i].ptr];
          if (!mask[candidate]) {
            ++vote[candidate];
            break;
          }
          ++pt[i].ptr;
        }
        if (pt[i].ptr == pt[i].count) {
          std::swap(pt[i--], pt[--non_empty_ballots]);
        }
      }

      min = -1;
      for (i = 0; i < N; ++i) {
        if (mask[i]) continue;
        if (vote[i] * 2 > valid) break;
        if (min == -1 || min > vote[i]) min = vote[i];
      }
      if (i < N) {
        printf("The winner of the election is %s.\n", names[i]);
        break;
      }

      assert(min != -1);
      for (i = 0; i < N; ++i) {
        if (mask[i]) continue;
        if (vote[i] == min) {
          mask[i] = 1;
          --rest;
          printf("%s with %d votes is eliminated.\n", names[i], min);
        }
      }
    }

    if (rest == 0) printf("The election was indecisive.\n");
    printf("There were %d valid ballots and %d spoiled ballots.\n", valid,
           V - valid);

    if (test_cases) putchar('\n');
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
