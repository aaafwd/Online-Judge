/* @JUDGE_ID: 19899RK 163 C++ "By Anadan" */
// City Directions
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int a, s, d;
const char dirs[8][3] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
const int da[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ds[8] = {1, 1, 0, -1, -1, -1, 0, 1};

inline int boulevard(int xa, int xs, int xd) {
  if (xa == xs && (xd == 1 || xd == 5)) return 1;
  if (xa == -xs && (xd == 3 || xd == 7)) return 1;
  return 0;
}

int throughway(int xa, int xs, int xd) {
  if ((xa == 50 || xa == 0 || xa == -50) && (xd == 0 || xd == 4)) return 1;
  if ((xs == 50 || xs == 0 || xs == -50) && (xd == 2 || xd == 6)) return 1;
  return boulevard(xa, xs, xd);
}

int validpos(int xa, int xs, int xd) {
  if (xa < -50 || xa > 50 || xs < -50 || xs > 50) return 0;
  if (xd == 1 || xd == 5) {
    return (xa == xs || xa == xs + 50 || xa == xs - 50);
  } else if (xd == 3 || xd == 7) {
    return (xa == -xs || xa == -xs + 50 || xa == -xs - 50);
  } else if (xd == 0) {
    return (xs != 50);
  } else if (xd == 2) {
    return (xa != 50);
  } else if (xd == 4) {
    return (xs != -50);
  } else if (xd == 6) {
    return (xa != -50);
  }
  return 0;
}

inline int incircle(int xa, int xs) { return (!(xa % 50) && !(xs % 50)); }

void command(char *str) {
  int turn, xa, xs, xd;
  char *p;

  p = strtok(str, " ");
  if (p == NULL) return;
  if (strcmp(p, "TURN") == 0) {
    if ((p = strtok(NULL, " ")) == NULL) return;
    turn = 2;
    if (strcmp(p, "HALF") == 0) {
      turn = 1;
      p = strtok(NULL, " ");
    } else if (strcmp(p, "SHARP") == 0) {
      turn = 3;
      p = strtok(NULL, " ");
    }

    if (p == NULL) return;
    if (strcmp(p, "LEFT") == 0) {
      turn = 8 - turn;
    } else if (strcmp(p, "RIGHT")) {
      return;
    }
    if (strtok(NULL, " ") != NULL) return;

    xa = a + da[d];
    xs = s + ds[d];
    xd = (d + turn) & 7;

    if (!validpos(xa, xs, xd)) return;
    if (!incircle(xa, xs) && (throughway(a, s, d) ^ throughway(xa, xs, xd))) {
      if (boulevard(a, s, d) ^ boulevard(xa, xs, xd)) {
        if (turn != 5) return;
      } else {
        if (turn != 6) return;
      }
    }
  } else if (strcmp(p, "GO") == 0) {
    if ((p = strtok(NULL, " ")) == NULL) return;
    if (strcmp(p, "STRAIGHT") == 0) {
      if ((p = strtok(NULL, " ")) == NULL) return;
    }
    if (strtok(NULL, " ") != NULL) return;

    while (*p == '0') ++p;
    if (*p == 0 || strlen(p) > 2) return;

    turn = 0;
    while (*p) {
      if (*p < '0' || *p > '9') return;
      turn = turn * 10 + *p++ - '0';
    }

    xa = a + da[d] * turn;
    xs = s + ds[d] * turn;
    xd = d;
    if (!validpos(xa, xs, xd)) return;
  } else {
    return;
  }

  a = xa;
  s = xs;
  d = xd;
}

int getnumber(char *s) {
  int res = 0;

  while ('0' <= *s && *s <= '9') res = res * 10 + *s++ - '0';
  if (*s == 'W' || *s == 'S') res = -res;

  return res;
}

int main() {
  int i;
  char str[128];

  while (scanf("%s", str) == 1 && strcmp(str, "END")) {
    for (i = 0; i < 2; ++i) {
      if (str[0] == 'A') {
        a = getnumber(str + 1);
      } else {
        s = getnumber(str + 1);
      }
      scanf("%s", str);
    }

    if (str[0] == 'N') {
      if (str[1] == 0) {
        d = 0;
      } else if (str[1] == 'E') {
        d = 1;
      } else {
        d = 7;
      }
    } else if (str[0] == 'S') {
      if (str[1] == 0) {
        d = 4;
      } else if (str[1] == 'E') {
        d = 3;
      } else {
        d = 5;
      }
    } else if (str[0] == 'E') {
      { d = 2; }
    } else {
      d = 6;
    }

    while (getchar() != '\n');
    while (fgets(str, sizeof(str), stdin)) {
      char *p = str + strlen(str) - 1;
      if (*p == '\n') *p = 0;
      if (!strcmp(str, "STOP")) break;
      command(str);
    }

    if (throughway(a, s, d)) {
      puts("Illegal stopping place");
    } else {
      printf("A%d%c ", (a < 0) ? (-a) : (a), (a < 0) ? ('W') : ('E'));
      printf("S%d%c ", (s < 0) ? (-s) : (s), (s < 0) ? ('S') : ('N'));
      puts(dirs[d]);
    }
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
