/* @JUDGE_ID: 19899RK 274 C++ "By Anadan" */
// Cat and Mouse
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N, sc, sm;
char cat[100][100], mouse[100][100];
char mask[100];

void dowave_cat(int v) {
  int i = 0, j = 1, k, vertexes[100];

  mask[v] = 1;
  vertexes[0] = v;

  while (i < j) {
    v = vertexes[i++];
    for (k = 0; k < N; ++k) {
      if (cat[v][k] && mask[k] == 0) {
        mask[k] = 1;
        vertexes[j++] = k;
      }
    }
  }
}

int dfs(int v) {
  int k;

  mask[v] = 1;
  if (mouse[v][sm]) return 1;

  for (k = 0; k < N; ++k) {
    if (mouse[v][k] && mask[k] == 0)
      if (dfs(k)) return 1;
  }

  return 0;
}

int cyclic() {
  if (mask[sm]) return 0;
  return dfs(sm);
}

int dowave_mouse(int v) {
  int i = 0, j = 1, k, vertexes[100];
  char vmask[100];

  memset(vmask, 0, sizeof(vmask));

  vmask[v] = 1;
  vertexes[0] = v;

  while (i < j) {
    v = vertexes[i++];
    if (mask[v]) return 1;
    for (k = 0; k < N; ++k) {
      if (mouse[v][k] && vmask[k] == 0) {
        vmask[k] = 1;
        vertexes[j++] = k;
      }
    }
  }

  return 0;
}

int main() {
  int set, i, j;
  char str[128];

  scanf("%d", &set);
  while (set--) {
    memset(cat, 0, sizeof(cat));
    memset(mouse, 0, sizeof(mouse));
    scanf("%d%d%d\n", &N, &sc, &sm);
    --sc;
    --sm;

    while (fgets(str, sizeof(str), stdin) && sscanf(str, "%d%d", &i, &j) == 2 &&
           (i != -1 || j != -1)) {
      cat[i - 1][j - 1] = 1;
    }

    while (fgets(str, sizeof(str), stdin) && sscanf(str, "%d%d", &i, &j) == 2) {
      mouse[i - 1][j - 1] = 1;
    }

    memset(mask, 0, sizeof(mask));
    dowave_cat(sc);

    if (dowave_mouse(sm)) {
      putchar('Y');
    } else {
      putchar('N');
    }
    if (cyclic()) {
      puts(" Y");
    } else {
      puts(" N");
    }

    if (set) putchar('\n');
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
