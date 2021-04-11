/* @JUDGE_ID: 19899RK 279 C++ "By Anadan" */
// Spin
// Accepted (0.000 seconds with low memory spent)

#include <cstdio>

constexpr int kMaxLen = 30;

int main() {
  unsigned int A[kMaxLen];
  A[0] = 1;
  for (int i = 1; i < kMaxLen; ++i) {
    A[i] = (A[i - 1] + i) * 2 + 1;
  }

  char orientation[64];
  bool invert[64];
  int test_cases, N, offset;
  std::scanf("%d", &test_cases);
  while (test_cases--) {
    std::scanf("%d%s%d", &N, orientation, &offset);
    offset = N - offset;

    invert[0] = (orientation[0] == 'v');
    for (int i = 1; i < N; ++i) {
      if (invert[i - 1]) {
        invert[i] = (orientation[i] != 'v');
      } else {
        invert[i] = (orientation[i] == 'v');
      }
    }
    for (int i = N - 1; i >= 0; --i) {
      if (orientation[i] == 'v') {
        if (invert[i]) offset = -offset;
        break;
      }
    }

    unsigned int result = 0;
    int left = 0;
    for (; left < N; ++left) {
      if (orientation[left] == 'v') break;
    }
    for (int i = N - 1; i > left; --i) {
      if (orientation[i] != 'v') continue;
      const int j = N - 1 - i;
      if (i - 1 == left) {
        result += A[j] + 2 * j + 3;
        left = N;
      } else if (invert[i]) {
        result += A[j];
      } else {
        result += A[j] + 2 * j + 3;
        if (orientation[i - 1] == 'h') {
          orientation[i - 1] = 'v';
        } else {
          orientation[i - 1] = 'h';
        }
        invert[i - 1] = !invert[i - 1];
      }
    }
    if (left < N) {
      const int j = N - 1 - left;
      result += A[j] + N + 1 - offset;
    } else {
      result += N + 1 - offset;
    }
    std::printf("%u\n", result);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
