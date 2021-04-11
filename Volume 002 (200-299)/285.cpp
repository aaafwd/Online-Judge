/* @JUDGE_ID: 19899RK 285 C++ "By Anadan" */
// Crosswords
// Accepted (0.000 seconds with low memory spent)

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <vector>

int main() {
  const int kMaxMapSize = 128;
  char buffer[1024 * 16], word[16];
  char map[kMaxMapSize][kMaxMapSize];
  int x, y, dx, dy, minx, maxx, miny, maxy;
  char ch;
  while (1) {
    for (int i = 0; i < kMaxMapSize; ++i) {
      std::memset(map[i], ' ', sizeof(map[i]));
    }
    minx = miny = kMaxMapSize;
    maxx = maxy = -1;
    buffer[0] = 0;
    while (std::fgets(buffer, sizeof(buffer), stdin) && buffer[0] != '#' &&
           buffer[0] != '\n') {
      if (std::sscanf(buffer, "%s %d %d %c", word, &x, &y, &ch) != 4) continue;
      --x;
      --y;
      dx = dy = 0;
      if (ch == 'u') {
        dy = -1;
      } else if (ch == 'd') {
        dy = 1;
      } else if (ch == 'r') {
        dx = 1;
      } else if (ch == 'l') {
        dx = -1;
      } else {
        continue;
      }
      minx = std::min(minx, x);
      maxx = std::max(maxx, x);
      miny = std::min(miny, y);
      maxy = std::max(maxy, y);
      for (const char* p = word; *p; ++p) {
        assert(x >= 0 && y >= 0);
        map[y][x] = *p;
        x += dx;
        y += dy;
      }
      x -= dx;
      y -= dy;
      minx = std::min(minx, x);
      maxx = std::max(maxx, x);
      miny = std::min(miny, y);
      maxy = std::max(maxy, y);
    }
    if (buffer[0] == 0 || buffer[0] == '\n') break;
    // std::scanf("%d %d\n", &x, &y);
    std::fgets(buffer, sizeof(buffer), stdin);
    std::sscanf(buffer, "%d", &x);
    std::fgets(buffer, sizeof(buffer), stdin);
    std::sscanf(buffer, "%d", &y);
    std::fgets(buffer, sizeof(buffer), stdin);

    if (x != maxx + 1 || y != maxy + 1) {
      std::puts("The solution is incorrect.");
    } else {
      char* p = buffer;
      for (int i = 0; buffer[i]; ++i) {
        if (buffer[i] != ' ') *p++ = buffer[i];
      }
      *p = 0;
      p = buffer;
      for (y = miny; y <= maxy; ++y) {
        for (x = minx; x <= maxx; ++x) {
          if (map[y][x] == ' ') continue;
          if (*p != map[y][x]) {
            *p = 0;
            y = maxy;
            break;
          }
          ++p;
        }
      }
      const bool correct = (*p == '$');
      std::puts(correct ? "The solution is correct."
                        : "The solution is incorrect.");
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
