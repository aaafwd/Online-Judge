/* @JUDGE_ID: 19899RK 283 C++ "By Anadan" */
// Compress
// Accepted (0.000 seconds with low memory spent)

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <functional>

// Wrong problem statement, should accept all characters.
const int kMaxChars = 256;  // 26 + 26 + 5;
int freq[kMaxChars];
int freq_accum_sum[kMaxChars];
int min_bits[kMaxChars];

int GetBitsNum(const int index) {
  if (index >= kMaxChars || !freq_accum_sum[index]) return 0;
  if (min_bits[index]) return min_bits[index];
  int result = 0;
  int current_min_bits;
  int next_min_bits;
  for (int bits = 1, offset = 1;; ++bits, offset = 2 * offset + 1) {
    const int next_index = index + offset;
    if (next_index + 1 >= kMaxChars || !freq_accum_sum[next_index + 1]) {
      next_min_bits = 0;
      current_min_bits = freq_accum_sum[index] * bits;
    } else {
      next_min_bits = GetBitsNum(next_index);
      current_min_bits = freq_accum_sum[index] * bits + next_min_bits;
    }
    if (result == 0 || result > current_min_bits) {
      result = current_min_bits;
    }
    if (!next_min_bits) break;
  }
  min_bits[index] = result;
  return result;
}

int main() {
  char buffer[1024];
  int test_cases, lines;
  std::scanf("%d\n", &test_cases);
  while (test_cases--) {
    std::fgets(buffer, sizeof(buffer), stdin);
    std::sscanf(buffer, "%d", &lines);
    std::memset(freq, 0, sizeof(freq));
    std::memset(min_bits, 0, sizeof(min_bits));
    while (lines > 0) {
      std::fgets(buffer, sizeof(buffer), stdin);
      for (char* p = buffer; *p; ++p) {
        if (*p == '\n') {
          --lines;
          break;
        }
        ++freq[*p];
        if (*p == '$') {
          --lines;
          break;
        }
      }
    }
    std::sort(freq, freq + kMaxChars, std::greater<int>());
    for (int i = kMaxChars - 1; i >= 0; --i) {
      freq_accum_sum[i] = freq[i];
      if (i + 1 < kMaxChars) {
        freq_accum_sum[i] += freq_accum_sum[i + 1];
      }
    }
    printf("%d\n", GetBitsNum(0));
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

