/* @JUDGE_ID: 19899RK 173 C++ "By Anadan" */
// Network Wars
// Accepted (0.010 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

char map[26][26];

int main() {
  int ip, il, i, j, flag;
  char str[260], mp[26], ml[26], *p, *q;

  while (fgets(str, sizeof(str), stdin) && str[0] != '#') {
    p = str + strlen(str) - 1;
    if (*p == '\n') *p = 0;
    memset(map, 0, sizeof(map));
    q = strchr(str, '.');
    *q++ = 0;
    while (*q < 'A' || *q > 'Z') ++q;
    ip = *q++ - 'A';
    while (*q < 'A' || *q > 'Z') ++q;
    il = *q - 'A';

    p = strtok(str, ";.");
    while (p) {
      for (q = p + 2; *q; ++q) {
        map[*p - 'A'][*q - 'A'] = map[*q - 'A'][*p - 'A'] = 1;
      }
      p = strtok(NULL, ";.");
    }

    memset(mp, 0, sizeof(mp));
    memset(ml, 0, sizeof(ml));

    flag = 0;
    while (flag == 0) {
      mp[ip] = ml[il] = 1;
      if (ip == il) {
        if (flag) {
          putchar(' ');
        } else {
          flag = 1;
        }
        printf("Both annihilated in node %c", ip + 'A');
        break;
      }

      for (i = (ip + 1) % 26; i != ip; i = (i + 1) % 26) {
        if (map[ip][i] && mp[i] == 0 && ml[i] == 0) break;
      }

      for (j = (il + 25) % 26; j != il; j = (j + 25) % 26) {
        if (map[il][j] && ml[j] == 0) break;
      }

      if (i == ip) {
        if (flag) {
          putchar(' ');
        } else {
          flag = 1;
        }
        printf("Paskill trapped in node %c", ip + 'A');
      }

      if (j == il) {
        if (flag) {
          putchar(' ');
        } else {
          flag = 1;
        }
        printf("Lisper trapped in node %c", il + 'A');
      }

      if (mp[j] == 1) {
        if (flag) {
          putchar(' ');
        } else {
          flag = 1;
        }
        if (i == j) {
          printf("Both annihilated in node %c", j + 'A');
        } else {
          printf("Lisper destroyed in node %c", j + 'A');
        }
      }

      ip = i;
      il = j;
    }

    putchar('\n');
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
