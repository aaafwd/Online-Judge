/* @JUDGE_ID: 19899RK 185 C++ "By Anadan" */
// Roman Numerals
// Accepted (Run Time: 0.010)

#include <stdio.h>
#include <string.h>

const char kRomanDigits[] = "IXCMVLD";

// I 1     V 5
// X 10    L 50
// C 100   D 500
// M 1000
int parseRoman(char* str) {
  int result = 0;
  int last = 0;
  for (; *str; ++str) {
    int digit = 0;
    switch (*str) {
      case 'I':
        digit = 1;
        break;
      case 'X':
        digit = 10;
        break;
      case 'C':
        digit = 100;
        break;
      case 'M':
        digit = 1000;
        break;
      case 'V':
        digit = 5;
        break;
      case 'L':
        digit = 50;
        break;
      case 'D':
        digit = 500;
        break;
      default:
        return -1;
    }
    if (last < digit) {
      result -= last * 2;
    }
    last = digit;
    result += digit;
  }
  return result;
}

int romanToArabic(const char* roman, const int* mapping) {
  int result = 0;
  while (*roman) {
    result = result * 10 + mapping[*roman++ - '0'];
  }
  return result;
}

int getArabicSumsImpl(const char* a, const char* b, const char* c,
                      const char* maskRoman, char* maskArabic, int* mapping,
                      int index) {
  while (index < 7 && !maskRoman[index]) ++index;
  if (index == 7) {
    const int sum = romanToArabic(a, mapping) + romanToArabic(b, mapping);
    return (sum == romanToArabic(c, mapping)) ? 1 : 0;
  }
  const char ch = '0' + index;
  int result = 0;
  for (int k = 0; k < 10; ++k) {
    if (maskArabic[k]) continue;
    if (k == 0 && (a[0] == ch || b[0] == ch || c[0] == ch)) continue;
    maskArabic[k] = 1;
    mapping[index] = k;
    result +=
        getArabicSumsImpl(a, b, c, maskRoman, maskArabic, mapping, index + 1);
    if (result > 1) return result;
    mapping[index] = 0;
    maskArabic[k] = 0;
  }
  return result;
}

void reindex(char* a, char* maskRoman) {
  while (*a) {
    const int index = strchr(kRomanDigits, *a) - kRomanDigits;
    maskRoman[index] = 1;
    *a++ = '0' + index;
  }
}

int getArabicSums(char* a, char* b, char* c) {
  char maskRoman[7] = {0};
  reindex(a, maskRoman);
  reindex(b, maskRoman);
  reindex(c, maskRoman);
  char maskArabic[10] = {0};
  int mapping[7] = {0};
  return getArabicSumsImpl(a, b, c, maskRoman, maskArabic, mapping, 0);
}

int main() {
  char a[16], b[16], c[16];
  while (scanf("%[IXCMVLD] + %[IXCMVLD] = %[IXCMVLD] ", a, b, c) > 0) {
    if (parseRoman(a) + parseRoman(b) == parseRoman(c)) {
      printf("Correct ");
    } else {
      printf("Incorrect ");
    }
    int sums = getArabicSums(a, b, c);
    if (sums == 0) {
      printf("impossible\n");
    } else if (sums == 1) {
      printf("valid\n");
    } else {
      printf("ambiguous\n");
    }
  }
  return 0;
}

