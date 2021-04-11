/* @JUDGE_ID: 19899RK 338 C++11 "By Anadan" */
// Long Multiplication
// Accepted (0.010 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <string>
#include <vector>

void DoLongMultiplication(std::string num1, std::string num2,
                          std::vector<std::string>& results) {
  results.clear();
  results.reserve(num2.size() + 3);
  results.push_back(num1);
  results.push_back(num2);
  if (num1 == "0" || num2 == "0") {
    results.push_back("0");
    return;
  }
  std::reverse(num1.begin(), num1.end());
  std::reverse(num2.begin(), num2.end());
  for (int i = 0; i < num2.size(); ++i) {
    const int digit = num2[i] - '0';
    if (digit == 0) {
      results.push_back("");
      continue;
    }
    std::string middle;
    middle.reserve(num1.size() + 1);
    int carry_over = 0;
    for (int j = 0; j < num1.size(); ++j) {
      carry_over += digit * (num1[j] - '0');
      middle += '0' + (carry_over % 10);
      carry_over /= 10;
    }
    if (carry_over > 0) {
      assert(carry_over < 10);
      middle += '0' + carry_over;
    }
    results.push_back(std::move(middle));
  }
  std::string result;
  result.reserve(num1.size() + num2.size());
  int carry_over = 0;
  bool done = false;
  while (!done) {
    const int pos = result.size();
    for (int i = 2; i < results.size(); ++i) {
      const int index = pos + 2 - i;
      if (index < 0) break;
      if (index >= results[i].size()) {
        if (i + 1 == results.size()) done = true;
        continue;
      }
      carry_over += results[i][index] - '0';
    }
    result += '0' + (carry_over % 10);
    carry_over /= 10;
  }
  while (carry_over > 0) {
    result += '0' + (carry_over % 10);
    carry_over /= 10;
  }
  while (result.size() > 1 && result.back() == '0') {
    result.pop_back();
  }
  results.push_back(std::move(result));
  for (int i = 2; i < results.size(); ++i) {
    std::reverse(results[i].begin(), results[i].end());
  }
}

void PrintNumber(const std::string& number, const int total_length) {
  int padding_left = total_length - number.size();
  assert(padding_left >= 0);
  while (padding_left-- > 0) std::putchar(' ');
  std::puts(number.c_str());
}

void PrintHorizontalLine(int size, const int total_length) {
  int padding_left = total_length - size;
  assert(padding_left >= 0);
  while (padding_left-- > 0) std::putchar(' ');
  while (size-- > 0) std::putchar('-');
  std::putchar('\n');
}

void PrintResults(const std::vector<std::string>& results) {
  assert(results.size() > 2);
  int max_length = 0;
  for (const std::string& str : results) {
    if (max_length < str.size()) max_length = str.size();
  }
  PrintNumber(results[0], max_length);
  PrintNumber(results[1], max_length);
  PrintHorizontalLine(std::max(results[0].size(), results[1].size()),
                      max_length);
  int numbers_in_middle = 0;
  for (int i = 2; i + 1 < results.size(); ++i) {
    if (results[i].empty()) continue;
    if (++numbers_in_middle > 1) break;
  }
  if (numbers_in_middle > 1) {
    for (int i = 2; i + 1 < results.size(); ++i) {
      if (results[i].empty()) continue;
      PrintNumber(results[i], max_length + 2 - i);
    }
    PrintHorizontalLine(results.back().size(), max_length);
  }
  assert(!results.back().empty());
  PrintNumber(results.back(), max_length);
}

int main() {
  char buffer1[32], buffer2[32];
  std::vector<std::string> results;
  while (std::scanf("%s%s", buffer1, buffer2) == 2) {
    DoLongMultiplication(std::string(buffer1), std::string(buffer2), results);
    PrintResults(results);
    std::putchar('\n');
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
