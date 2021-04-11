/* @JUDGE_ID: 19899RK 268 C++ "By Anadan" */
// Double Trouble
// Accepted (0.000 seconds with low memory spent)

#include <cstdio>
#include <vector>

void FindDoubleTroubleNumberReversed(const int base, const int last,
                                     std::vector<int>* result) {
  int sum = 0;
  int current = last;
  result->clear();
  while (1) {
    result->push_back(current);
    sum += current * 2;
    current = sum % base;
    sum /= base;
    if (current == last && sum == 0) break;
  }
}

bool IsLessReversed(const std::vector<int>& a, const std::vector<int>& b) {
  if (a.size() != b.size()) {
    return a.size() < b.size();
  }
  for (int i = a.size() - 1; i >= 0; --i) {
    if (a[i] != b[i]) {
      return a[i] < b[i];
    }
  }
  return false;
}

int main() {
  const int kPrecalcLast[201] = {
      0,  0,  1,   1,  1,  3,   1,  1,  5,   1,  1,  7,   1,  5,  9,
      1,  1,  11,  5,  1,  13,  1,  1,  15,  1,  7,  17,  1,  11, 19,
      1,  1,  21,  13, 1,  23,  1,  1,  25,  11, 1,  27,  1,  17, 29,
      1,  13, 31,  19, 1,  33,  1,  1,  35,  1,  1,  37,  1,  23, 39,
      17, 11, 41,  25, 1,  43,  1,  19, 45,  1,  1,  47,  13, 29, 49,
      1,  1,  51,  31, 1,  53,  23, 1,  55,  1,  13, 57,  1,  25, 59,
      1,  1,  61,  37, 11, 63,  1,  1,  65,  1,  1,  67,  29, 41, 69,
      19, 1,  71,  43, 31, 73,  13, 1,  75,  1,  1,  77,  1,  47, 79,
      1,  1,  81,  35, 19, 83,  1,  23, 85,  1,  37, 87,  1,  53, 89,
      1,  1,  91,  55, 1,  93,  1,  1,  95,  41, 17, 97,  1,  59, 99,
      13, 43, 101, 61, 1,  103, 1,  1,  105, 1,  29, 107, 19, 65, 109,
      47, 1,  111, 67, 1,  113, 11, 49, 115, 1,  1,  117, 1,  71, 119,
      1,  19, 121, 73, 1,  123, 53, 1,  125, 29, 1,  127, 1,  55, 129,
      1,  23, 131, 79, 1,  133};

  int base;
  std::vector<int> best, result;
  while (std::scanf("%d", &base) == 1) {
    if (base <= 200) {
      FindDoubleTroubleNumberReversed(base, kPrecalcLast[base], &best);
    } else {
      FindDoubleTroubleNumberReversed(base, 1, &best);
      for (int i = 2; i < base; ++i) {
        FindDoubleTroubleNumberReversed(base, i, &result);
        if (IsLessReversed(result, best)) best.swap(result);
      }
    }

    std::printf("For base %d the double-trouble number is\n", base);
    for (int i = best.size() - 1; i >= 0; --i) {
      std::printf("%d ", best[i]);
    }
    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
