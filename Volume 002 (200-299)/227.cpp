/* @JUDGE_ID: 19899RK 227 C++ "By Anadan" */
// Puzzle
// Accepted (0.000 seconds with low memory spent)

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main() {
  int i, c, x, y, set = 0;
  char puzzle[5][8], *p, error;

  while (1) {
    for (i = 0; i < 5; i++) {
      if (!fgets(puzzle[i], sizeof(puzzle[i]), stdin)) return 0;
      for (char *p = puzzle[i]; *p; ++p) {
        if (*p == '\n') {
          *p = 0;
          break;
        }
      }
    }
    if (puzzle[0][0] == 'Z' && puzzle[0][1] == 0) break;

    for (x = 0; x < 5; x++) {
      p = strchr(puzzle[x], ' ');
      if (p) {
        y = int(p - puzzle[x]);
        break;
      }
    }

    error = 0;
    while ((c = getchar()) != '0') {
      if (error) continue;

      switch (c) {
        case 'A':
          if (x == 0) {
            error = 1;
          } else {
            puzzle[x][y] = puzzle[x - 1][y];
            puzzle[--x][y] = ' ';
          }
          break;
        case 'B':
          if (x == 4) {
            error = 1;
          } else {
            puzzle[x][y] = puzzle[x + 1][y];
            puzzle[++x][y] = ' ';
          }
          break;
        case 'R':
          if (y == 4) {
            error = 1;
          } else {
            puzzle[x][y] = puzzle[x][y + 1];
            puzzle[x][++y] = ' ';
          }
          break;
        case 'L':
          if (y == 0) {
            error = 1;
          } else {
            puzzle[x][y] = puzzle[x][y - 1];
            puzzle[x][--y] = ' ';
          }
          break;
        default:
          if (c != ' ' && c != '\t' && c != '\n') error = 1;
          break;
      }
    }

    if (set) putchar('\n');
    printf("Puzzle #%d:\n", ++set);
    if (error) {
      printf("This puzzle has no final configuration.\n");
    } else {
      for (i = 0; i < 5; i++) {
        printf("%c %c %c %c %c\n", puzzle[i][0], puzzle[i][1], puzzle[i][2],
               puzzle[i][3], puzzle[i][4]);
      }
    }
    while (getchar() != '\n')
      ;
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
