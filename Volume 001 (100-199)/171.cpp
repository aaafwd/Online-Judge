/* @JUDGE_ID: 19899RK 171 C++ "By Anadan" */
// Car Trialling
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int off;
char *cur, buf[81], tmp[81];

int nnn() {
  while (*cur == ' ' || *cur == '\t') ++cur;
  if (*cur < '0' || *cur > '9') return 0;

  while ('0' <= *cur && *cur <= '9') {
    while ('0' <= *cur && *cur <= '9') ++cur;
    while (*cur == ' ' || *cur == '\t') ++cur;
  }

  return 1;
}

int cas() {
  if (sscanf(cur, "%s%n", buf, &off) != 1) return 0;
  if (!strcmp(buf, "CAS")) {
    cur += off;
    return 1;
  } else if (!strcmp(buf, "CHANGE")) {
    cur += off;
    if (sscanf(cur, "%s%n", buf, &off) != 1) return 0;
    if (strcmp(buf, "AVERAGE")) return 0;
    cur += off;
    if (sscanf(cur, "%s%n", buf, &off) != 1) return 0;
    if (strcmp(buf, "SPEED")) return 0;
    cur += off;
    return 1;
  }
  return 0;
}

int change() {
  if (!cas()) return 0;
  if (sscanf(cur, "%s%n", buf, &off) != 1) return 0;
  if (strcmp(buf, "TO")) return 0;
  cur += off;
  if (!nnn()) return 0;
  if (sscanf(cur, "%s%n", buf, &off) != 1) return 0;
  if (strcmp(buf, "KMH")) return 0;
  cur += off;
  return 1;
}

int record() {
  if (sscanf(cur, "%s%s%n", buf, tmp, &off) != 2) return 0;
  if (!strcmp(buf, "RECORD") && !strcmp(tmp, "TIME")) {
    cur += off;
    return 1;
  }
  return 0;
}

int timekeeping() { return (record() || change()); }

int sword() {
  while (*cur == ' ' || *cur == '\t') ++cur;
  if (*cur != '.' && (*cur < 'A' || *cur > 'Z')) return 0;

  while ('A' <= *cur && *cur <= 'Z' || *cur == '.') {
    while ('A' <= *cur && *cur <= 'Z' || *cur == '.') ++cur;
    while (*cur == ' ' || *cur == '\t') ++cur;
  }

  return 1;
}

int where() {
  if (sscanf(cur, "%s%n", buf, &off) != 1) return 1;
  if (!strcmp(buf, "AT")) {
    cur += off;
    if (sscanf(cur, "%1s%n", buf, &off) != 1) return 0;
    if (buf[0] != '"') return 0;
    cur += off;
    if (!sword()) return 0;
    if (sscanf(cur, "%1s%n", buf, &off) != 1) return 0;
    if (buf[0] != '"') return 0;
    cur += off;
  }

  return 1;
}

int when() {
  if (sscanf(cur, "%s%n", buf, &off) != 1) return 0;
  if (!strcmp(buf, "FIRST") || !strcmp(buf, "SECOND") ||
      !strcmp(buf, "THIRD")) {
    cur += off;
    return 1;
  }
  return 0;
}

int direction() {
  if (sscanf(cur, "%s%n", buf, &off) != 1) return 0;
  cur += off;
  if (!strcmp(buf, "RIGHT") || !strcmp(buf, "LEFT")) return 1;
  return 0;
}

int how() {
  if (sscanf(cur, "%s%n", buf, &off) != 1) return 0;
  if (!strcmp(buf, "GO")) {
    cur += off;
    when();
    return 1;
  } else if (!strcmp(buf, "KEEP")) {
    cur += off;
    return 1;
  }

  return 0;
}

int directional() {
  if (!how()) return 0;
  if (!direction()) return 0;
  return where();
}

int navigational() {
  if (!directional()) return 0;

  while (sscanf(cur, "%s%s%n", buf, tmp, &off) == 2) {
    if (!strcmp(buf, "AND") && !strcmp(tmp, "THEN")) {
      cur += off;
      if (!directional()) return 0;
    } else {
      break;
    }
  }

  return 1;
}

int instruction(char *str) {
  int ret;

  if (navigational()) {
    if (sscanf(cur, "%s%n", buf, &off) == 1 && !strcmp(buf, "AND")) {
      cur += off;
      ret = timekeeping();
    } else {
      ret = 1;
    }
  } else {
    cur = str;
    ret = timekeeping();
  }

  while (*cur == ' ' || *cur == '\t') ++cur;
  if (*cur) return 0;
  return ret;
}

int main() {
  int set = 0;
  char str[128], *p;

  while (fgets(str, sizeof(str), stdin)) {
    p = str + strlen(str) - 1;
    if (*p == '\n') *p = 0;
    if (str[0] == '#' && str[1] == 0) break;
    printf("%3d. ", ++set);
    cur = str;
    if (instruction(str)) {
      p = strtok(str, " \t");
      printf("%s", p);
      p = strtok(NULL, " \t");
      while (p) {
        printf(" %s", p);
        p = strtok(NULL, " \t");
      }
      putchar('\n');
    } else {
      printf("Trap!\n");
    }
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
