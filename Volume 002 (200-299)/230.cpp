/* @JUDGE_ID: 19899RK 230 C++ "By Anadan" */
// Borrowers
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SZ 300

struct Book {
  char *title, *author;
  int i;
} pt[SZ], pt_tl[SZ];
char lib[SZ], ret[SZ];
int N;

inline char *_strdup(char *s) {
  return strcpy((char *)malloc(strlen(s) + 1), s);
}

int sort_function(const void *a, const void *b) {
  int i = strcmp(((Book *)a)->author, ((Book *)b)->author);
  if (i) return i;
  return strcmp(((Book *)a)->title, ((Book *)b)->title);
}

int sort_function_tl(const void *a, const void *b) {
  return strcmp(((Book *)a)->title, ((Book *)b)->title);
}

int getindex(char *s) {
  Book tmp, *p;
  int i;
  tmp.title = s;

  p = (Book *)bsearch(&tmp, pt_tl, N, sizeof(Book), sort_function_tl);
  i = int((char *)p - (char *)pt_tl) / sizeof(Book);
  return pt_tl[i].i;
}

void shelve() {
  int i, prev = -1;

  for (i = 0; i < N; ++i) {
    if (ret[i]) {
      if (prev == -1) {
        printf("Put \"%s\" first\n", pt[i].title);
      } else {
        printf("Put \"%s\" after \"%s\"\n", pt[i].title, pt[prev].title);
      }
      lib[i] = 1;
      ret[i] = 0;
    }

    if (lib[i]) prev = i;
  }

  puts("END");
}

int main() {
  int i, nums[SZ];
  char str[256], *p;

  N = 0;
  while (fgets(str, sizeof(str), stdin) && str[0] != 'E') {
    for (p = str; *p; ++p) {
      if (*p == '\n') {
        *p = 0;
        break;
      }
    }
    p = strchr(str + 1, '"');
    *p++ = 0;
    pt[N].title = _strdup(str + 1);
    while (*p++ != 'b')
      ;
    ++p;
    while (*p == ' ' || *p == '\t') ++p;
    pt[N].author = _strdup(p);

    pt_tl[N].title = pt[N].title;
    pt_tl[N].author = pt[N].author;
    pt_tl[N].i = pt[N].i = N;

    ++N;
  }
  qsort(pt, N, sizeof(Book), sort_function);
  qsort(pt_tl, N, sizeof(Book), sort_function_tl);
  memset(lib, 1, N);
  memset(ret, 0, N);

  for (i = 0; i < N; ++i) nums[pt[i].i] = i;
  for (i = 0; i < N; ++i) pt_tl[i].i = nums[pt_tl[i].i];

  while (fgets(str, sizeof(str), stdin) && str[0] != 'E') {
    for (p = str; *p; ++p) {
      if (*p == '\n') {
        *p = 0;
        break;
      }
    }
    if (str[0] == 'S') {
      shelve();
    } else {
      p = strchr(str, '"') + 1;
      *strchr(p, '"') = 0;
      i = getindex(p);

      if (str[0] == 'B') {
        lib[i] = 0;
      } else {
        ret[i] = 1;
      }
    }
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

