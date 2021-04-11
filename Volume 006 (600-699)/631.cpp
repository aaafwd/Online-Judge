/* @JUDGE_ID: 19899RK 631 C++ "By Anadan" */
// Microzoft Calendar
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int max_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char months[5][10] = {"Sun", "Water", "Forest", "Mountains", "Money"};
const char weeks[6][7] = {"First",  "Second", "Third",
                          "Fourth", "Fifth",  "Sixth"};

int isleap(int yy) {
  if (yy % 4) return 0;
  if (yy % 100) return 1;
  if (yy % 400) return 0;
  return 1;
}

int getdays(int dd, int mm, int yy) {
  int i, res = 365;

  --yy;
  res *= yy;
  res += yy / 4 - yy / 100 + yy / 400;

  --mm;
  max_days[1] = 28 + isleap(yy + 1);
  for (i = 0; i < mm; ++i) {
    res += max_days[i];
  }

  res += dd - 1;
  return res;
}

int getyear(int& days) {
  int yy = 1;

  while (days > 365) {
    days -= 365 + isleap(yy++);
  }

  if (days == 365 && !isleap(yy)) {
    days = 0;
    ++yy;
  }

  return yy;
}

void outputdate(int days, int yy) {
  if (days >= 360) {
    printf("Feast %d-%d", days - 359, yy);
  } else {
    if (days < 180) {
      printf("Gill-");
    } else {
      printf("Bates-");
      days -= 180;
    }
    printf("%s-", months[days / 36]);
    days %= 36;
    printf("%s-%d-%d", weeks[days / 6], (days % 6) + 1, yy);
  }
}

int main() {
  int yy, mm, dd, nulldate, days;
  char str[81];

  nulldate = getdays(25, 6, 1998);
  while (fgets(str, sizeof(str), stdin)) {
    for (char* p = str; *p; ++p) {
      if (*p == '\n') *p = 0;
    }
    if (!strcmp(str, "END")) break;
    if (sscanf(str, "%d-%d-%d", &yy, &mm, &dd) == 3) {
      days = getdays(dd, mm, yy) - nulldate;
      if (days >= 0) {
        yy = getyear(days);
        outputdate(days, yy);
        putchar('\n');
      } else {
        days = -days - 1;
        yy = getyear(days);
        days = 364 + isleap(yy) - days;
        outputdate(days, yy);
        printf("bd\n");
      }
    } else {
      printf("Enter date in old format\n");
    }
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
