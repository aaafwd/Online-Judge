/* @JUDGE_ID: 19899RK 269 C++ "By Anadan" */
// Counting Patterns
// Accepted (0.100 seconds with low memory spent)

#include <cstdio>
#include <vector>

inline int abs(int x) { return x < 0 ? -x : x; }

bool VerifyDirect(const int* pattern, const int N, int offset) {
  const int sign = (pattern[offset] < 0) ? -1 : 1;
  for (int i = 0; i < N; ++i) {
    const int diff = pattern[i] - sign * pattern[offset];
    if (diff != 0) return diff > 0;
    if (++offset == N) offset = 0;
  }
  return true;
}

bool VerifyReversed(const int* pattern, const int N, int offset) {
  const int sign = (pattern[offset] < 0) ? -1 : 1;
  for (int i = 0; i < N; ++i) {
    const int diff = pattern[i] - sign * pattern[offset];
    if (diff != 0) return diff > 0;
    if (--offset < 0) offset = N - 1;
  }
  return true;
}

bool Verify(const int* pattern, const int N) {
  for (int offset = 0; offset < N; ++offset) {
    if (!VerifyReversed(pattern, N, offset)) return false;
  }
  for (int offset = 1; offset < N; ++offset) {
    if (!VerifyDirect(pattern, N, offset)) return false;
  }
  return true;
}

void Generate(const int index, const int N, const int K, int sum, int* current,
              std::vector<std::vector<int>>* patterns) {
  if (index == N) {
    if (Verify(current, N)) patterns->push_back({current, current + N});
    return;
  }
  int maxValue = (index == 0) ? K : current[0];
  int minValue = (index == 0) ? 0 : -maxValue;
  // Quick heuristic on minValue and maxValue.
  if (index > 1) {
    if (current[index - 1] == maxValue) {
      maxValue = current[1];
    } else if (current[index - 1] == -maxValue) {
      minValue = -current[1];
    }
  }
  for (int value = minValue; value <= maxValue; ++value) {
    current[index] = value;

    // Condition on the (sum == 0) at the end.
    if (abs(sum + value) > current[0] * (N - index - 1)) continue;

    // Condition that the reversed (maybe sign-flipped) is less.
    if (index > 1 && !VerifyReversed(current, index + 1, index)) continue;

    Generate(index + 1, N, K, sum + value, current, patterns);
  }
}

void FastOutput(const std::vector<std::vector<int>>& patterns) {
  const int size = patterns.size();
  char buffer[1024 * 4];
  char* p = buffer;
  int count = 0;
  for (int i = 0; i < size; ++i) {
    if (count) *p++ = '\n';
    *p++ = '(';
    const int* pattern = patterns[i].data();
    const int pattern_size = patterns[i].size();
    for (int j = 0; j < pattern_size; ++j) {
      if (j) *p++ = ',';
      int x = *pattern++;
      if (x < 0) {
        x = -x;
        *p++ = '-';
      }
      if (x > 9) {
        *p++ = '1';
        x -= 10;
      }
      *p++ = '0' + x;
    }
    *p++ = ')';
    if (++count == 100) {
      *p = 0;
      std::puts(buffer);
      count = 0;
      p = buffer;
    }
  }
  if (count) {
    *p = 0;
    std::puts(buffer);
  }
}

int main() {
  int N, K;
  bool has_output = false;
  int current[16];
  std::vector<std::vector<int>> patterns;
  patterns.reserve(1024 * 74);
  while (std::scanf("%d%d", &N, &K) == 2) {
    if (has_output) std::putchar('\n');
    has_output = true;

    patterns.clear();
    Generate(0, N, K, 0, current, &patterns);

    int size = patterns.size();
    std::printf("%d\n", size);
    FastOutput(patterns);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
