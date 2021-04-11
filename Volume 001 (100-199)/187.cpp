/* @JUDGE_ID: 19899RK 187 C++ "By Anadan" */
// Transaction Processing
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
struct Account {
  int id;
  char name[31];
} pt[100];

struct Transaction {
  int id;
  int money;
} tr[10];

int sort_function(const void *a, const void *b) {
  return ((Account *)a)->id - ((Account *)b)->id;
}

char *getaccount(int n) {
  Account tmp, *res;
  tmp.id = n;

  res = (Account *)bsearch(&tmp, pt, N, sizeof(Account), sort_function);
  return res->name;
}

void consume_endline(char *p) {
  p += strlen(p) - 1;
  if (*p == '\n') *p = 0;
}

int main() {
  char str[128];
  int i, j, k, index, balance, transaction, money;

  N = 0;
  while (fgets(str, sizeof(str), stdin)) {
    consume_endline(str);
    sscanf(str, "%3d", &i);
    if (i == 0) break;
    pt[N].id = i;
    strcpy(pt[N].name, str + 3);
    ++N;
  }

  qsort(pt, N, sizeof(Account), sort_function);

  index = balance = 0;
  while (fgets(str, sizeof(str), stdin)) {
    sscanf(str, "%3d%3d%d", &i, &j, &money);
    if (i == 0) break;
    if (index && transaction != i) {
      if (balance) {
        printf("*** Transaction %.3d is out of balance ***\n", transaction);
        for (k = 0; k < index; ++k) {
          printf("%.3d %-30s %10.2lf\n", tr[k].id, getaccount(tr[k].id),
                 double(tr[k].money) * 0.01);
        }

        printf("999 %-30s %10.2lf\n\n", "Out of Balance",
               double(-balance) * 0.01);
      }
      index = balance = 0;
    }

    transaction = i;
    tr[index].id = j;
    tr[index].money = money;
    balance += money;
    ++index;
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
