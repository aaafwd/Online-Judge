/* @JUDGE_ID: 19899RK 182 C++ "By Anadan" */
// Bonus Bonds
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

const int kPow10s[] = {1,      10,      100,      1000,      10000,
                       100000, 1000000, 10000000, 100000000, 1000000000};

void solve(char* str, int position, int distribution[10]) {
  const int region = str[2] - '0';
  str[2] = str[1];
  str[1] = str[0];
  const int seq = atoi(str + 1);

  if (position == 3) {
    for (int i = 0; i < 10; ++i) distribution[i] = 0;
    distribution[region] = seq;
  } else {
    if (position > 3) --position;  // => [1..9] left to right
    position = 10 - position;  // => [1..9] right to left
    int seq_low = seq % kPow10s[position];
    const int seq_high_per_digit = (seq - seq_low) / 10;
    const int pow10_low = kPow10s[position - 1];
    for (int i = 0; i < 10; ++i) {
      distribution[i] = seq_high_per_digit;
      if (seq_low >= pow10_low) {
        seq_low -= pow10_low;
        distribution[i] += pow10_low;
      } else {
        distribution[i] += seq_low;
        seq_low = 0;
      }
    }
  }
  if (region == 0 && distribution[0] > 0) {
    --distribution[0];
  }
}

int main() {
  char str[16];
  int distribution[10];
  int position;
  bool has_output = false;
  while (scanf("%s%d", str, &position) == 2) {
    if (position == 0) break;
    solve(str, position, distribution);

    if (has_output) putchar('\n');
    has_output = true;
    for (int i = 0; i < 10; ++i) {
      printf("%11d\n", distribution[i]);
    }
  }
  return 0;
}

