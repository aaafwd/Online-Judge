/* @JUDGE_ID: 19899RK 158 C++ "By Anadan" */
// Calendar
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 1000

int indexx;
struct Date {
  int dd, mm, pr, i;
  char *str;
} pt[SZ];
int mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int dd, mm;
char printed = 0;

char *_strdup(char *p) { return strcpy((char *)malloc(strlen(p) + 1), p); }

int sort_function(const void *a, const void *b) {
  Date *da = (Date *)a, *db = (Date *)b;
  if (da->mm < db->mm) return -1;
  if (da->mm > db->mm) return 1;
  if (da->dd < db->dd) return -1;
  if (da->dd > db->dd) return 1;
  if (da->pr > db->pr) return -1;
  if (da->pr < db->pr) return 1;
  if (da->i < db->i) return -1;
  return 1;
}

int getdays(int d1, int m1, int d2, int m2) {
  int res = 0;

  --m1;
  --m2;
  while (m1 != m2 || d1 != d2) {
    ++d1;
    if (d1 > mdays[m1]) {
      ++m1;
      d1 = 1;
    }

    if (m1 > 11) m1 = 0;
    ++res;
  }

  return res;
}

int sort_function2(const void *a, const void *b) {
  Date *da = (Date *)a, *db = (Date *)b;

  if (da->dd == dd && da->mm == mm && db->dd == dd && db->mm == mm) {
    if (da->i < db->i) return -1;
    return 1;
  }
  if (da->dd == dd && da->mm == mm) return -1;
  if (db->dd == dd && db->mm == mm) return 1;

  if (da->mm == 12 && db->mm == 1) return -1;
  if (da->mm == 1 && db->mm == 12) return 1;
  if (da->mm < db->mm) return -1;
  if (da->mm > db->mm) return 1;
  if (da->dd < db->dd) return -1;
  if (da->dd > db->dd) return 1;

  if (da->pr > db->pr) return -1;
  if (da->pr < db->pr) return 1;
  if (da->i < db->i) return -1;
  return 1;
}

void outprint() {
  int i, N = 0, ddays;
  Date result[1000];

  for (i = 0; i < indexx; ++i) {
    ddays = getdays(dd, mm, pt[i].dd, pt[i].mm);
    if (ddays > 7) continue;
    ddays = pt[i].pr - ddays + 1;
    if (ddays <= 0) continue;
    result[N].dd = pt[i].dd;
    result[N].mm = pt[i].mm;
    result[N].pr = ddays;
    result[N].i = pt[i].i;
    result[N].str = pt[i].str;
    ++N;
  }

  if (printed) {
    putchar('\n');
  } else {
    printed = 1;
  }
  printf("Today is:%3d%3d\n", dd, mm);
  qsort(result, N, sizeof(Date), sort_function2);
  for (i = 0; i < N; ++i) {
    printf("%3d%3d ", result[i].dd, result[i].mm);
    if (result[i].dd == dd && result[i].mm == mm) {
      printf("*TODAY*");
    } else {
      ddays = 0;
      while (result[i].pr--) putchar('*'), ++ddays;
      while (ddays++ < 7) putchar(' ');
    }
    printf(" %s\n", result[i].str);
  }
}

int main() {
  int yy, pr, off;
  char str[260], ch[2], *p;

  indexx = 0;
  scanf("%d\n", &yy);
  if (!(yy & 3)) ++mdays[1];
  while (fgets(str, sizeof(str), stdin) && str[0] != '#') {
    p = str + strlen(str) - 1;
    if (*p == '\n') *p = 0;
    sscanf(str, "%s%n", ch, &off);
    p = str + off;
    if (ch[0] == 'A') {
      sscanf(p, "%d %d %d%n", &dd, &mm, &pr, &off);
      p += off;
      while (*p == ' ') ++p;
      pt[indexx].dd = dd;
      pt[indexx].mm = mm;
      pt[indexx].pr = pr;
      pt[indexx].str = _strdup(p);
      pt[indexx].i = indexx;
      indexx++;
    } else if (ch[0] == 'D') {
      break;
    } else {
      return 1;
    }
  }

  qsort(pt, indexx, sizeof(Date), sort_function);
  do {
    p = str + strlen(str) - 1;
    if (*p == '\n') *p = 0;
    sscanf(str, "%*s %d %d", &dd, &mm);
    outprint();
  } while (fgets(str, sizeof(str), stdin) && str[0] != '#');

  return 0;
}
/* @END_OF_SOURCE_CODE */
