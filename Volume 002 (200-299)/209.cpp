/* @JUDGE_ID: 19899RK 209 C++ "By Anadan" */
// Triangular Vertices
// Accepted (0.020 seconds using as much as 404 kbytes)

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

long getlen(long a, long b) {
  long n1, n2, d1, d2;
  double tmp;

  if (a > b) {
    a ^= b;
    b ^= a;
    a ^= b;
  }
  tmp = double(a);
  n1 = (long)ceil(0.5 * (sqrt(8.0 * tmp + 1.0) - 1.0));
  tmp = double(b);
  n2 = (long)ceil(0.5 * (sqrt(8.0 * tmp + 1.0) - 1.0));
  if (n1 == n2) return (b - a);
  d1 = ((n2 - n1) * (n1 + n2 - 1)) >> 1;
  d2 = d1 + n2 - n1;
  if ((b - a == d1) || (b - a == d2)) return (n2 - n1);
  return -1L;
}

int sort_function(const void *a, const void *b) {
  if (*((long *)a) > *((long *)b)) return 1;
  return -1;
}

int main() {
  char str[256], *p, solved;
  int index, off;
  long vert[6], size;

  while (fgets(str, sizeof(str), stdin) && str[0] != '\n') {
    for (p = str, index = 0; index < 6; index++) {
      if (sscanf(p, "%ld%n", &vert[index], &off) <= 0) break;
      p += off;
      printf("%ld ", vert[index]);
    }
    solved = 0;
    switch (index) {
      case 3: {
        long t1, t2;
        t1 = getlen(vert[0], vert[1]);
        if (t1 < 1) break;
        if (t1 != getlen(vert[1], vert[2])) break;
        if (t1 != getlen(vert[0], vert[2])) break;
        puts("are the vertices of a triangle");
        solved = 1;
        break;
      }
      case 4: {
        int a = 0, i = 0;
        long t[6];
        if ((t[0] = getlen(vert[0], vert[1])) < 1) a++;
        if ((t[1] = getlen(vert[0], vert[2])) < 1) a++, i = 1;
        if ((t[2] = getlen(vert[0], vert[3])) < 1) a++, i = 2;
        if ((t[3] = getlen(vert[1], vert[2])) < 1) a++, i = 3;
        if ((t[4] = getlen(vert[1], vert[3])) < 1) a++, i = 4;
        if ((t[5] = getlen(vert[2], vert[3])) < 1) a++, i = 5;
        if (a != 1) break;
        if (i) {
          t[0] ^= t[i];
          t[i] ^= t[0];
          t[0] ^= t[i];
        }
        for (a = 1; a < 5; a++) {
          if (t[a] != t[a + 1]) break;
        }
        if (a != 5) break;
        puts("are the vertices of a parallelogram");
        solved = 1;
        break;
      }
      case 6: {
        long t1, t2;
        qsort((void *)vert, 6, sizeof(long), sort_function);
        if ((t1 = getlen(vert[0], vert[1])) < 1) break;
        if (t1 != getlen(vert[1], vert[3])) break;
        if (t1 != getlen(vert[3], vert[5])) break;
        if (t1 != getlen(vert[4], vert[5])) break;
        if (t1 != getlen(vert[2], vert[4])) break;
        if (t1 != getlen(vert[0], vert[2])) break;
        if ((t2 = getlen(vert[0], vert[5])) < 1) break;
        if (t2 != (t1 << 1)) break;
        if (t2 != getlen(vert[1], vert[4])) break;
        if (t2 != getlen(vert[2], vert[3])) break;
        puts("are the vertices of a hexagon");
        solved = 1;
        break;
      }
    }
    if (!solved) puts("are not the vertices of an acceptable figure");
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
