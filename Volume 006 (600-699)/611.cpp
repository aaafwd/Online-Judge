/* @JUDGE_ID: 19899RK 611 C++ "By Anadan" */
// Parallel Deadlock
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct CPU {
  int N, sp;
  char stack[100][30], blocked, blk[26];
} pt[26];
char curr[26];
int finish[26], msg[26][26];

int main() {
  int set, i, j, k, N, t;
  char str[81], *p, *q, changed;

  scanf("%d\n\n", &set);
  while (set--) {
    memset(curr, 0, 26);

    scanf("%d\n", &N);
    for (i = 0; i < N; ++i) {
      scanf("%s %d\n", str, &k);
      j = int(str[0] - 'A');
      curr[j] = 1;
      finish[j] = 0;
      pt[j].N = k;
      pt[j].sp = 0;
      pt[j].blocked = 0;

      for (k = 0; k < pt[j].N; ++k) {
        q = fgets(str, sizeof(str), stdin);
        for (p = pt[j].stack[k]; *q && *q != '\n'; ++q) {
          if ('A' <= *q && *q <= 'Z') *p++ = *q;
        }
        *q = 0;
        *p = 0;
      }
    }

    memset(msg, 0, sizeof(msg));

    t = 1;
    changed = 1;
    while (changed) {
      changed = 0;
      for (i = 0; i < 26; ++i) {
        if (!curr[i] || finish[i]) continue;
        if (pt[i].blocked || pt[i].sp == pt[i].N) continue;

        changed = 1;
        j = pt[i].sp++;
        if (pt[i].stack[j][0] == 'B') {  // blocking
          memset(pt[i].blk, 0, 26);
          if (pt[i].stack[j][1] == 'S') {  // send
            pt[i].blocked = 1;
            for (p = pt[i].stack[j] + 2; *p; ++p) {
              ++msg[i][*p - 'A'];
              pt[i].blk[*p - 'A'] = 1;
            }
          } else {  // receive
            pt[i].blocked = -1;
            for (p = pt[i].stack[j] + 2; *p; ++p) {
              --msg[*p - 'A'][i];
              pt[i].blk[*p - 'A'] = 1;
            }
          }
        } else {                           // non-blocking
          if (pt[i].stack[j][1] == 'S') {  // send
            for (p = pt[i].stack[j] + 2; *p; ++p) {
              ++msg[i][*p - 'A'];
            }
          } else {  // receive
            for (p = pt[i].stack[j] + 2; *p; ++p) {
              --msg[*p - 'A'][i];
            }
          }
        }
      }

      // remove blocked CPU and check changed
      for (i = 0; i < 26; ++i) {
        if (!curr[i] || finish[i]) continue;
        if (pt[i].blocked == 1) {  // send
          for (j = 0; j < 26; ++j) {
            if (!pt[i].blk[j]) continue;
            if (msg[i][j] > 0) break;
          }
          if (j == 26) {
            pt[i].blocked = 0;
            changed = 1;
          }
        } else if (pt[i].blocked == -1) {  // receive
          for (j = 0; j < 26; ++j) {
            if (!pt[i].blk[j]) continue;
            if (msg[j][i] < 0) break;
          }
          if (j == 26) {
            pt[i].blocked = 0;
            changed = 1;
          }
        }
      }

      // check if finished
      for (i = 0; i < 26; ++i) {
        if (!curr[i] || finish[i]) continue;
        if (pt[i].blocked) continue;
        if (pt[i].sp == pt[i].N) {
          for (j = 0; j < 26; ++j) {
            if (!curr[j]) continue;
            if (msg[i][j] > 0 || msg[j][i] < 0) break;
          }

          if (j == 26) {
            finish[i] = t;
            changed = 1;
          }
        }
      }

      ++t;
    }

    // output result
    for (i = 0; i < 26; ++i) {
      if (!curr[i]) continue;
      if (finish[i]) {
        printf("%c finishes at t=%d\n", 'A' + i, finish[i]);
      } else {
        memset(pt[i].blk, 0, 26);
        for (j = 0; j < 26; ++j) {
          if (!curr[j]) continue;
          if (msg[i][j] > 0 || msg[j][i] < 0) pt[i].blk[j] = 1;
        }

        for (j = 0; j < 26; ++j) {
          if (pt[i].blk[j]) break;
        }
        printf("%c never finishes because of %c", 'A' + i, 'A' + j);
        for (++j; j < 26; ++j) {
          if (pt[i].blk[j]) printf(" and %c", 'A' + j);
        }
        putchar('\n');
      }
    }

    if (set) putchar('\n');
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
