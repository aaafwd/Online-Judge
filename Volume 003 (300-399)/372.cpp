/* @JUDGE_ID: 19899RK 372 C++11 "By Anadan" */
// WhatFix Notation
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

std::string PrefixToPostfix(const char* start) {
  std::vector<std::string> stack;
  const char* end = start;
  while (*end && *end != '\n') ++end;
  for (--end; end >= start; --end) {
    if (*end == ' ') continue;
    if (std::strchr("$*/+-&|!", *end)) {
      assert(!stack.empty());
      std::string tmp = stack.back();
      stack.pop_back();
      if (!stack.empty()) {
        tmp += ' ';
        tmp += stack.back();
        stack.pop_back();
      }
      tmp += ' ';
      tmp += *end;
      stack.push_back(std::move(tmp));
    } else {
      assert('a' <= *end && *end <= 'z');
      std::string tmp;
      tmp += *end;
      stack.push_back(std::move(tmp));
    }
  }
  assert(stack.size() == 1);
  return stack.front();
}

int main() {
  char buffer[1024];
  while (std::fgets(buffer, sizeof(buffer), stdin)) {
    if (buffer[0] == 0 || buffer[0] == '\n') break;
    std::printf("INFIX   => %s", buffer);
    std::fgets(buffer, sizeof(buffer), stdin);
    std::printf("PREFIX  => %s", buffer);
    std::string postfix = PrefixToPostfix(buffer);
    std::printf("POSTFIX => %s\n", postfix.c_str());
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
