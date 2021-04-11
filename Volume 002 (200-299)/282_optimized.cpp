/* @JUDGE_ID: 19899RK 282 C++ "By Anadan" */
// Rename
// Accepted (0.010 seconds with low memory spent)

#include <cctype>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

void ExtractPrefixSuffix(char* str, char** prefix, char** suffix,
                         int* prefix_len, int* suffix_len) {
  *prefix = str - 1;
  for (char* p = str; *p; ++p) {
    if (std::isspace(*p)) {
      *prefix = p;
    } else if (*p == '*') {
      ++(*prefix);
      *prefix_len = p - *prefix;
      *p++ = 0;
      *suffix = p;
      while (*p && !std::isspace(*p)) ++p;
      *p = 0;
      *suffix_len = p - *suffix;
      break;
    }
  }
}

int main() {
  char buffer[1024];
  std::vector<std::string> files;
  char *prefix1, *suffix1, *prefix2, *suffix2;
  int prefix1_len, suffix1_len, prefix2_len, suffix2_len;
  while (1) {
    files.clear();
    while (std::scanf("%s\n", buffer) == 1) {
      if (std::strcmp(buffer, "end") == 0) break;
      files.push_back(buffer);
    }
    if (files.empty()) break;
    while (std::fgets(buffer, sizeof(buffer), stdin) && buffer[0] != 'e') {
      std::fputs(buffer, stdout);
      ExtractPrefixSuffix(buffer, &prefix1, &suffix1, &prefix1_len,
                          &suffix1_len);
      ExtractPrefixSuffix(suffix1 + suffix1_len + 1, &prefix2, &suffix2,
                          &prefix2_len, &suffix2_len);
      const int min_len = prefix1_len + suffix1_len;
      for (int i = 0; i < files.size(); ++i) {
        std::string& file = files[i];
        const int len = file.size();
        const char* data = file.data();
        if (len >= min_len && std::strncmp(data, prefix1, prefix1_len) == 0 &&
            std::strcmp(data + len - suffix1_len, suffix1) == 0) {
          std::printf("mv %s %s", data, prefix2);
          for (int i = prefix1_len; i < len - suffix1_len; ++i) {
            std::putchar(data[i]);
          }
          std::puts(suffix2);
        }
      }
    }
    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
