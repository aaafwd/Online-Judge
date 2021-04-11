/* @JUDGE_ID: 19899RK 293 C++ "By Anadan" */
// Bits
// Accepted (0.000 seconds with low memory spent)

#include <cctype>
#include <cstdio>

int GetSmallestBits(int x) {
  int result = 0;
  --x;
  while (x) {
    ++result;
    x >>= 1;
  }
  return result;
}

int GetNextChar() {
  int x;
  while ((x = std::getchar()) != EOF) {
    if (!std::isspace(x)) return x;
  }
  return x;
}

// Assumes no spaces between words.
int GetNextWord(char* buf = 0) {
  int x;
  while ((x = std::getchar()) != EOF) {
    if (std::isspace(x)) continue;
    if (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z')) {
      if (buf) *buf++ = x;
    } else {
      break;
    }
  }
  if (buf) *buf = 0;
  return x;
}

int ParseType() {
  const char ch = GetNextChar();
  int result = 0;
  if (ch == '{') {
    while (GetNextWord() == ':') {
      result += ParseType();
    }
  } else if (ch == 'a') {
    int L, H;
    std::scanf("rray [ %d .. %d ] of ", &L, &H);
    result = ParseType();
    result *= (H - L + 1);
  } else if (ch == 's') {
    std::scanf("tring ( %d )", &result);
    result *= 7;
  } else if (ch == '(') {
    do {
      ++result;
    } while (GetNextWord() == ',');
    result = GetSmallestBits(result);
  } else if (ch == '[') {
    int L, H;
    std::scanf("%d .. %d ]", &L, &H);
    result = GetSmallestBits(H - L + 1);
  }
  return result;
}

int main() {
  char buffer[512];
  int test_cases = 0;
  std::scanf("%d\n", &test_cases);
  while (test_cases--) {
    GetNextWord(buffer);
    const int bits = ParseType();
    std::printf("A \"%s\" message requires %d bits.\n", buffer, bits);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
