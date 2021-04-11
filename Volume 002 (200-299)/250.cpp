/* @JUDGE_ID: 19899RK 250 C++ "By Anadan" */
// Pattern Matching Prelims
// Accepted (0.000 seconds with low memory spent)

#include <cstdio>

const int kPow10s[] = {1,      10,      100,      1000,     10000,
                       100000, 1000000, 10000000, 100000000};

int FindCenterIndex(const int* arr, const int size) {
  int left = 0;
  int right = 0;
  for (int i = 0; i < size; ++i) right += arr[i];

  int index = 0;
  int min_diff = right - arr[0];
  for (int i = 0; i < size; ++i) {
    right -= arr[i];
    const int diff = (right > left) ? right - left : left - right;
    if (min_diff >= diff) {
      min_diff = diff;
      index = i;
    }
    left += arr[i];
  }
  return index;
}

int ToIntFor250(char* buffer) {
  if (!buffer[1]) buffer[2] = 0;
  buffer[1] = buffer[0];
  ++buffer;
  int result = 0;
  for (int i = 0; i < 5; ++i) {
    if (!buffer[i]) {
      result *= kPow10s[5 - i];
      break;
    }
    result = result * 10 + buffer[i] - '0';
  }
  return result;
}

int main() {
  char buffer[1024];
  int map[32][32], sum[32], tmp;
  int test_case = 0, rows, cols;
  while (std::scanf("%d%d", &rows, &cols) == 2) {
    if (rows == 0 && cols == 0) break;
    for (int i = 0; i < rows; ++i) {
      sum[i] = 0;
      for (int j = 0; j < cols; ++j) {
        std::scanf("%s", buffer);
        sum[i] += (map[i][j] = ToIntFor250(buffer));
      }
    }
    const int answer_row = FindCenterIndex(sum, rows);

    for (int j = 0; j < cols; ++j) sum[j] = 0;
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        sum[j] += map[i][j];
      }
    }
    const int answer_col = FindCenterIndex(sum, cols);

    std::printf("Case %d: center at (%d, %d)\n", ++test_case, answer_row + 1,
                answer_col + 1);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
