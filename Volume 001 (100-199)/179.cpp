/* @JUDGE_ID: 19899RK 179 C++ "By Anadan" */
// Code Breaking
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int len;
char text[170], cypher1[170], cypher2[170], m1[256], m2[256], perm[80][80];
char map[80], revmap[80];

int setperm(char *s, char *p, int len) {
  int i, j, flagzero;
  static char mask[80], *q;

  // Modification perm[80][80]
  // If contradiction arise - return 1;

  for (i = 0; s[i]; ++i) {
    memset(mask, 0, len);
    q = p;
    while ((q = strchr(q, s[i])) != NULL) {
      mask[int(q - p)] = 1;
      ++q;
    }

    flagzero = 0;
    for (j = 0; j < len; ++j) {
      perm[i][j] &= mask[j];
      if (perm[i][j]) flagzero = 1;
    }
    if (flagzero == 0) return 1;
  }

  return 0;  // Ok
}

int setmap(int p) {
  int i, j;

  memset(revmap, -1, p);
  for (i = 0; i < p; ++i) {
    for (j = 0; j < p; ++j) {
      if (perm[i][j]) break;
    }
    map[i] = j;
    if (revmap[j] != -1) return 1;
    revmap[j] = i;
    for (++j; j < p; ++j) {
      if (perm[i][j]) break;
    }
    if (j < p) return 1;
  }
  return 0;  // Ok
}

int isperiod(int p) {
  int i, j;
  char c1, c2;

  memset(perm, 1, sizeof(perm));
  for (i = 0; i + p <= len; i += p) {
    c1 = text[i + p];
    c2 = cypher1[i + p];
    text[i + p] = 0;
    cypher1[i + p] = 0;

    j = setperm(text + i, cypher1 + i, p);
    text[i + p] = c1;
    cypher1[i + p] = c2;

    if (j) return 0;
  }

  if (setmap(p)) return 0;

  if (i != len) {
    // Checking the end of messages text[] & cypher1[]
    for (p = 0; i + p < len; ++p) {
      if (text[i + p] != cypher1[map[p]]) return 0;
    }
  }

  return 1;  // Ok
}

void consume_endline(char *p) {
  p += strlen(p) - 1;
  if (*p == '\n') *p = 0;
}

int main() {
  int period, i, j, sum;

  while (fgets(text, sizeof(text), stdin) &&
         fgets(cypher1, sizeof(cypher1), stdin) &&
         fgets(cypher2, sizeof(cypher2), stdin) && text[0] != '#') {
    consume_endline(text);
    consume_endline(cypher1);
    consume_endline(cypher2);
    sum = 0;
    len = strlen(text);
    memset(m1, 0, sizeof(m1));
    memset(m2, 0, sizeof(m2));
    for (period = 1; period <= len; ++period) {
      ++m1[text[period - 1]];
      ++m2[cypher1[period - 1]];
      if (text[period - 1] != cypher1[period - 1]) {
        if (m1[text[period - 1]] <= m2[text[period - 1]]) {
          --sum;
        } else {
          ++sum;
        }
        if (m2[cypher1[period - 1]] <= m1[cypher1[period - 1]]) {
          --sum;
        } else {
          ++sum;
        }
      }

      if (sum == 0 && isperiod(period)) break;
    }

    if (period <= len) {
      /* Doing inverse permutation to cyphertext2 */
      len = strlen(cypher2);
      for (i = 0; i + period <= len; i += period) {
        for (j = 0; j < period; ++j) {
          text[i + revmap[j]] = cypher2[i + j];
        }
      }

      if (i != len) {
        for (j = len; j < i + period; ++j) cypher2[j] = '?';
        cypher2[i + period] = 0;
        for (j = 0; j < period; ++j) {
          text[i + revmap[j]] = cypher2[i + j];
        }
        text[i + period] = 0;
      } else {
        text[i] = 0;
      }
      puts(text);
    } else {
      puts(cypher2);
    }
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
