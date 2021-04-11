/* @JUDGE_ID: 19899RK 257 C++ "By Anadan" */
// Palinwords
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int palinword(const char* word) {
  const int len = strlen(word);
  int prev_left = -1;
  int prev_right = -1;
  for (int i = 0; i < len; ++i) {
    int left = i;
    int right = i;
    while (left > 0 && word[left - 1] == word[i]) --left;
    while (right + 1 < len && word[right + 1] == word[i]) ++right;
    i = right;

    while (left > 0 && right + 1 < len && word[left - 1] == word[right + 1]) {
      --left;
      ++right;
    }
    if (right - left < 2) continue;
    if (prev_left == -1) {
      prev_left = left;
      prev_right = right;
      continue;
    }
    int a = (left + right) / 2;
    int b = (prev_left + prev_right) / 2;
    while (a >= left && b >= prev_left) {
      if (word[a] != word[b]) return 1;
      --a;
      --b;
    }
    if (prev_right - prev_left < right - left) {
      prev_left = left;
      prev_right = right;
    }
  }
  return 0;
}

int main() {
  char str[512];
  while (scanf("%s", str) > 0) {
    if (palinword(str)) {
      printf("%s\n", str);
    }
  }
  return 0;
}

