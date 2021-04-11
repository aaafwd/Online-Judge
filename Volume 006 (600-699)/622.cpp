/* @JUDGE_ID: 19899RK 622 C++ "By Anadan" */
// Grammar Evaluation
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int off;
char *cur, op[2];

double expression();

char *getnextparent(char *s) {
  int count = 1;

  while (count && *s) {
    if (*s == '(')
      ++count;
    else if (*s == ')')
      --count;
    ++s;
  }

  if (count) return NULL;
  return s - 1;
}

double factor() {
  char *p;
  double tmp;

  if (sscanf(cur, "%1s%n", op, &off) < 1) return -1.0;
  if (op[0] == '(') {
    cur += off;
    p = getnextparent(cur);
    if (p == NULL) return -1.0;
    *p++ = 0;
    tmp = expression();
    cur = p;
  } else {
    if (sscanf(cur, "%lf%n", &tmp, &off) < 1) return -1.0;
    p = cur;
    cur += off;
    while (off--) {
      if (*p < '0' || *p > '9') return -1.0;
      ++p;
    }
  }

  return tmp;
}

double component() {
  double res = 1.0, tmp;

  while (1) {
    tmp = factor();
    if (tmp < -0.5) return -1.0;
    res *= tmp;
    if (sscanf(cur, "%1s%n", op, &off) < 1) break;
    if (op[0] != '*') break;
    cur += off;
  }

  return res;
}

double expression() {
  double res = 0.0, tmp;

  while (1) {
    tmp = component();
    if (tmp < -0.5) return -1.0;
    res += tmp;
    if (sscanf(cur, "%1s%n", op, &off) < 1) break;
    if (op[0] != '+') break;
    cur += off;
  }

  return res;
}

int main() {
  int set;
  char str[256];
  double res;

  scanf("%d ", &set);
  while (set--) {
    cur = fgets(str, sizeof(str), stdin);
    char* end = cur + strlen(cur) - 1;
    if (*end == '\n') *end = 0;
    res = expression();
    while (*cur) {
      if (*cur++ != ' ') {
        res = -1.0;
        break;
      }
    }

    if (res < -0.5)
      printf("ERROR\n");
    else
      printf("%.0lf\n", res);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

