/* @JUDGE_ID: 19899RK 307 C++ "By Anadan" */
// Sticks
// Accepted (0.090 seconds with low memory spent)

#include <algorithm>
#include <cstdio>
#include <functional>
#include <vector>

bool CanAssembleSticks(const int kLen, const int kSticks, int index,
                       int len_left, int sticks_left, int* sticks) {
  if (sticks_left == 0) return true;
  if (len_left == 0) {
    len_left = kLen;
    index = 0;
  }
  for (; index < kSticks; ++index) {
    const int stick = sticks[index];
    if (stick < 0 || len_left < stick) continue;
    sticks[index] = -1;
    if (CanAssembleSticks(kLen, kSticks, index + 1, len_left - stick,
                          sticks_left - 1, sticks)) {
      return true;
    }
    sticks[index] = stick;
    // A new assembly must contain the first available stick.
    if (len_left == kLen) break;
    // If a final |stick| did not pass, no smaller combinations
    // |a+b+...+x == stick| will also pass.
    if (len_left == stick) break;
    // From sticks of equal size, choose only the first one.
    while (index + 1 < kSticks && sticks[index + 1] == stick) ++index;
  }
  return false;
}

int main() {
  int N;
  while (std::scanf("%d", &N) == 1) {
    if (N == 0) break;
    std::vector<int> sticks;
    int sum = 0;
    for (int i = 0; i < N; ++i) {
      int x = 0;
      std::scanf("%d", &x);
      sum += x;
      sticks.push_back(x);
    }
    std::sort(sticks.begin(), sticks.end(), std::greater<int>());

    // Fast heuristic for lower bound.
    int len = sticks[0];
    for (; len < sum; ++len) {
      if (sum % len) continue;
      bool is_possible_len = true;
      const int final_sticks_num = sum / len;
      for (int i = 0; i < N; ++i) {
        const int items_per_stick = len / sticks[i];
        const int min_sticks_num = (i / items_per_stick) + 1;
        if (final_sticks_num < min_sticks_num) {
          is_possible_len = false;
          break;
        }
      }
      if (is_possible_len) break;
    }

    for (; len < sum; ++len) {
      if (sum % len) continue;
      if (CanAssembleSticks(len, N, 0, len, N, sticks.data())) break;
    }
    printf("%d\n", len);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

