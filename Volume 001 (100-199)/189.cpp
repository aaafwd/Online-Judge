/* @JUDGE_ID: 19899RK 189 C++ "By Anadan" */
// Pascal Program Lengths
// Accepted (0.000 seconds with low memory spent)

#include <ctype.h>
#include <stdio.h>
#include <string.h>

char comment;

int parse(char *str) {
  int res = 0;

  while (*str) {
    if (comment) {
      while (*str) {
        if (*str++ == '}') {
          comment = 0;
          break;
        }
      }
      continue;
    }

    if (*str == '{') {
      ++str;
      comment = 1;
      continue;
    }

    if (*str == '\'') {
      ++str;
      ++res;
      while (1) {
        while (*str++ != '\'');
        if (*str == '\'') {
          ++str;
        } else {
          break;
        }
      }
      continue;
    }

    if (*str == '_' || isalpha(*str)) {
      ++str;
      ++res;
      while (*str == '_' || isalnum(*str)) ++str;
      continue;
    }

    if (isdigit(*str)) {
      ++str;
      ++res;

      while (*str && isdigit(*str)) ++str;
      if (*str == '.') {
        ++str;
        while (*str && isdigit(*str)) ++str;
      }
      if (*str == 'e' || *str == 'E') {
        ++str;
        if (*str == '-' || *str == '+') ++str;
        while (*str && isdigit(*str)) ++str;
      }
      continue;
    }

    if (*str == '$') {
      ++str;
      ++res;
      while (isxdigit(*str)) ++str;
      continue;
    }

    if (strchr("+-*/=@^([", *str)) {
      ++str;
      ++res;
      continue;
    }

    if (*str == '<') {
      ++str;
      ++res;
      if (*str == '=' || *str == '>') ++str;
      continue;
    }

    if (*str == '>') {
      ++str;
      ++res;
      if (*str == '=') ++str;
      continue;
    }

    if (*str == ':' && *(str + 1) == '=') {
      ++res;
      str += 2;
      continue;
    }

    ++str;
  }

  return res;
}

void consume_endline(char* p) {
  for (; *p; ++p) {
    if (*p == '\n') {
      *p = 0;
      break;
    }
  }
}

int main() {
  int res;
  char str[1024];

  while (fgets(str, sizeof(str), stdin)) {
    res = 0;
    comment = 0;

    while (str[0] != '~' || str[1] != '~') {
      consume_endline(str);
      res += parse(str);
      if (!fgets(str, sizeof(str), stdin)) return 0;
    }

    consume_endline(str);
    printf("Program by %s contains %d units.\n", str + 2, res);
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
