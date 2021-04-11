/* @JUDGE_ID: 19899RK 148 C++ "By Anadan" */
// Anagram checker
// Accepted (0.060 seconds using as much as 492 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 2000

char phrase[64], letters[26], nonequalflag;
int res[20];
struct Dict {
  char str[32], letters[26];
  int flag;
} pt[SZ + 1];
int N, cur_true;

void outprint(int i, int n) {
  int j;

  for (j = 0; j < 26; ++j) {
    if (letters[j]) break;
  }
  if (j == 26) {
    if (nonequalflag == 0) {
      for (i = 0; i < n; ++i) {
        if (pt[res[i]].flag != cur_true) break;
      }
      if (i == n) return;
    }
    printf("%s =", phrase);
    for (i = 0; i < n; ++i) printf(" %s", pt[res[i]].str);
    putchar('\n');
    return;
  }

  for (; i < N; ++i) {
    for (j = 0; j < 26; ++j) {
      if (pt[i].letters[j] > letters[j]) break;
    }
    if (j < 26) continue;
    for (j = 0; j < 26; ++j) letters[j] -= pt[i].letters[j];
    res[n] = i;
    outprint(i, n + 1);
    for (j = 0; j < 26; ++j) letters[j] += pt[i].letters[j];
  }
}

int main() {
  int i, j;
  char *p;
  N = 0;

  while (fgets(pt[N].str, sizeof(pt[N].str), stdin) && pt[N].str[0] != '#') {
    memset(pt[N].letters, 0, 26);
    for (p = pt[N].str; *p; ++p) {
      if (*p == '\n') {
        *p = 0;
      } else {
        ++pt[N].letters[*p - 'A'];
      }
    }
    pt[N].flag = 0;
    ++N;
  }

  cur_true = 1;
  while (fgets(phrase, sizeof(phrase), stdin) && phrase[0] != '#') {
    memset(letters, 0, 26);
    for (p = phrase; *p; ++p) {
      if (*p == '\n') {
        *p = 0;
      } else if (*p != ' ') {
        ++letters[*p - 'A'];
      }
    }
    p = phrase;
    nonequalflag = 0;
    while (sscanf(p, "%s%n", pt[N].str, &i) == 1) {
      p += i;
      for (j = 0; j < N; ++j) {
        if (strcmp(pt[N].str, pt[j].str) == 0) break;
      }
      if (j < N) {
        pt[j].flag = cur_true;
      } else {
        nonequalflag = 1;
        break;
      }
    }

    outprint(0, 0);
    ++cur_true;
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
