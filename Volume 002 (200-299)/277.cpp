/* @JUDGE_ID: 19899RK 277 C++ "By Anadan" */
// Cabinets
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Catalog {
  int code;
  char name[16];
  char desc[16];
  char ext[26];
  int price;
} pt[1500];

int main() {
  int N, set, i, j, k;
  char str[96], *p, *q;

  scanf("%d\n\n", &set);
  while (set--) {
    N = -1;
    while (fgets(str, sizeof(str), stdin)) {
      for (p = str; *p; ++p) {
        if (*p == '\n') {
          *p = 0;
          break;
        }
      }
      if (str[0] == 0) break;
      ++N;

      p = str;
      pt[N].price = 0;
      pt[N].name[0] = pt[N].desc[0] = pt[N].ext[0] = 0;

      q = strchr(p, ',');
      if (q) *q++ = 0;
      sscanf(str, "%d", &pt[N].code);
      if (q == NULL || *q == 0) continue;

      p = q;
      q = strchr(p, ',');
      if (q) *q++ = 0;
      strcpy(pt[N].name, p);
      if (q == NULL || *q == 0) continue;

      p = q;
      q = strchr(p, ',');
      if (q) *q++ = 0;
      strcpy(pt[N].desc, p);
      if (q == NULL || *q == 0) continue;

      p = q;
      q = strchr(p, ',');
      if (q) *q++ = 0;
      strcpy(pt[N].ext, p);
      if (q == NULL || *q == 0) continue;

      sscanf(q, "%d", &pt[N].price);
    }

    printf("Item Id,Item Desc,Item Price\n");
    for (j = -1, i = 0; i <= N; ++i) {
      if (i) {
        if (pt[i].code == pt[i - 1].code) {
          if (j == -1) j = i - 1;
        } else {
          j = -1;
        }
      }

      sprintf(str, "%.3d%s", pt[i].code, pt[i].desc);
      if (strlen(str) > 13) continue;
      if (pt[i].name[0] == 0) {
        if (j == -1 || pt[j].name[0] == 0) continue;
        k = j;
      } else {
        k = i;
      }

      printf("%s,", str);
      if (pt[i].ext[0] == 0) {
        printf("%s", pt[k].name);
      } else {
        sprintf(str, "%s-%s", pt[k].name, pt[i].ext);
        str[30] = 0;
        printf("%s", str);
      }

      printf(",%.2lf\n", 0.01 * double(pt[i].price));
    }

    if (set) putchar('\n');
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
