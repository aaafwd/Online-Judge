/* @JUDGE_ID: 19899RK 292 C++11 "By Anadan" */
// Presentation Error
// Accepted (0.000 seconds with low memory spent)

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>

struct Output {
  std::vector<std::string> lines;
  std::vector<std::string> essentials;
};

void TrimRight(char* str) {
  char* last_char = str;
  for (char* p = str; *p; ++p) {
    if (!std::isspace(*p)) last_char = p + 1;
  }
  *last_char = 0;
}

void ScanfOutput(const int N, const bool is_jury, Output* out) {
  char buffer[96];
  out->lines.clear();
  out->essentials.clear();
  for (int i = 0; i < N; ++i) {
    std::fgets(buffer, sizeof(buffer), stdin);
    TrimRight(buffer);
    if (is_jury) {
      char* last_char = buffer;
      char* arg_begin = 0;
      for (char* p = buffer; *p; ++p) {
        if (!arg_begin && *p == '[') {
          arg_begin = last_char;
        } else if (arg_begin && *p == ']') {
          *last_char = 0;
          if (last_char != arg_begin) {
            out->essentials.push_back(
                std::string(arg_begin, last_char - arg_begin));
          }
          arg_begin = 0;
        } else {
          *last_char++ = *p;
        }
      }
      *last_char = 0;
    }
    out->lines.push_back(std::string(buffer));
  }
  while (!out->lines.empty() && out->lines.back().empty()) {
    out->lines.pop_back();
  }
}

bool Accepted(const Output& jury, const Output& out) {
  const int size = jury.lines.size();
  if (size != out.lines.size()) return false;
  for (int i = 0; i < size; ++i) {
    if (jury.lines[i] != out.lines[i]) return false;
  }
  return true;
}

bool PresentationError(Output& jury, Output& out) {
  for (auto& line : out.lines) {
    for (auto& ch : line) ch = std::toupper(ch);
  }
  int last_line = 0;
  int last_pos = 0;
  for (auto& essential : jury.essentials) {
    for (auto& ch : essential) ch = std::toupper(ch);
    while (last_line < out.lines.size()) {
      last_pos = out.lines[last_line].find(essential, last_pos);
      if (last_pos != std::string::npos) {
        last_pos += essential.size();
        break;
      }
      last_pos = 0;
      ++last_line;
    }
    if (last_line >= out.lines.size()) return false;
  }
  return true;
}

int main() {
  int test_cases, N, M;
  Output jury, out;
  std::scanf("%d\n", &test_cases);
  while (test_cases--) {
    std::scanf("%d%d", &N, &M);
    while (1) {
      int x = std::getchar();
      if (x == EOF || x == '\n') break;
    }
    ScanfOutput(N, true, &jury);
    ScanfOutput(M, false, &out);
    if (Accepted(jury, out)) {
      std::puts("Accepted");
    } else if (PresentationError(jury, out)) {
      std::puts("Presentation Error");
    } else {
      std::puts("Wrong Answer");
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
