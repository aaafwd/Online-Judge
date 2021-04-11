/* @JUDGE_ID: 19899RK 261 C++ "By Anadan" */
// The Window Property
// Accepted (0.000 seconds with low memory spent)

#include <cstdio>
#include <unordered_set>

int FindOffendingPosition(char* buffer) {
  const int sym0 = buffer[0];
  int offending_position = -1;
  int size = 0;
  while (buffer[size] == sym0) buffer[size++] = '0';
  if (!buffer[size]) return -1;
  const int sym1 = buffer[size];
  while (buffer[size]) {
    if (buffer[size] == sym0) {
      buffer[size++] = '0';
    } else if (buffer[size] == sym1) {
      buffer[size++] = '1';
    } else {
      offending_position = size;
      break;
    }
  }

  std::unordered_set<uint64_t> patterns;
  for (int len = 2; len * 2 < size; ++len) {
    patterns.clear();
    uint64_t bits = 0;
    const uint64_t mask = (uint64_t(1) << len) - 1;
    for (int i = 0; i < size; ++i) {
      bits <<= 1;
      if (buffer[i] == '1') bits |= 1;
      bits &= mask;
      if (i + 1 >= len) {
        patterns.insert(bits);
        if (patterns.size() > len + 1) {
          offending_position = size = i;
          break;
        }
      }
    }
  }

  return offending_position;
}

int main() {
  char buffer[256];
  while (std::fgets(buffer, sizeof(buffer), stdin) && buffer[0] != '\n') {
    for (int i = 0; buffer[i]; ++i) {
      if (buffer[i] == '\n') {
        buffer[i] = 0;
        break;
      }
    }
    const int pos = FindOffendingPosition(buffer);
    if (pos == -1) {
      std::puts("YES");
    } else {
      std::printf("NO:%d\n", pos + 1);
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

