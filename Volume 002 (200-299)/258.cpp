/* @JUDGE_ID: 19899RK 258 C++ "By Anadan" */
// Mirror Maze
// Accepted (0.010 seconds with low memory spent)

#define NDEBUG

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

const int kSteps[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

struct Point {
  // dir: { ↑ → ↓ ← }
  //      { 0 1 2 3  }
  // 0^1, 0^3 => 1, 3
  // 1^1, 1^3 => 0, 2
  // 2^1, 2^3 => 3, 1
  // 3^1, 3^3 => 2, 0
  int x, y, dir;
};

int columns, rows;
char map[64][64], mask[4][64][64];
std::vector<Point> queue1, queue2, next_queue;

void RotateMirrorsOnPrevPath(const int queue_num, int x, int y, int prev_dir) {
  while (map[y][x] == '/' || map[y][x] == '\\') {
    if (mask[prev_dir ^ 3][y][x] == queue_num) {
      map[y][x] = '/';
      prev_dir ^= 1;
    } else if (mask[prev_dir ^ 1][y][x] == queue_num) {
      map[y][x] = '\\';
      prev_dir ^= 3;
    } else {
      break;
    }
    const int dx = kSteps[prev_dir][0];
    const int dy = kSteps[prev_dir][1];
    do {
      x += dx;
      y += dy;
    } while (map[y][x] == '.');
  }
}

void RotateMirrors() {
  queue1.clear();
  queue2.clear();
  for (int i = 0; i < rows; ++i) {
    if (map[i][0] == '.') queue1.push_back({0, i, 1});
    if (map[i][columns - 1] == '.') queue1.push_back({columns - 1, i, 3});
  }
  for (int j = 0; j < columns; ++j) {
    if (map[0][j] == '.') queue1.push_back({j, 0, 2});
    if (map[rows - 1][j] == '.') queue1.push_back({j, rows - 1, 0});
  }
  assert(queue1.size() == 2);
  queue2.push_back(queue1.back());
  queue1.pop_back();

  for (int dir = 0; dir < 4; ++dir) {
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < columns; ++j) {
        mask[dir][i][j] = 0;
      }
    }
  }

  const int x1 = queue1[0].x;
  const int y1 = queue1[0].y;
  const int x2 = queue2[0].x;
  const int y2 = queue2[0].y;
  map[y1][x1] = map[y2][x2] = '*';

  int queue_num;
  std::vector<Point>* queue;
  while (!queue1.empty() || !queue2.empty()) {
    if (queue2.empty() || (!queue1.empty() && queue1.size() < queue2.size())) {
      queue = &queue1;
      queue_num = 1;
    } else {
      queue = &queue2;
      queue_num = 3;
    }
    next_queue.clear();
    while (!queue->empty()) {
      const int ox = queue->back().x;
      const int oy = queue->back().y;
      const int dir = queue->back().dir;
      const int dx = kSteps[dir][0];
      const int dy = kSteps[dir][1];
      queue->pop_back();
      int x = ox;
      int y = oy;
      while (1) {
        x += dx;
        y += dy;
        if (map[y][x] == '*') break;
        if (map[y][x] == '.') continue;
        if (!mask[dir][y][x] && mask[dir ^ 2][y][x] != queue_num) {
          mask[dir][y][x] = queue_num;
          next_queue.push_back({x, y, dir ^ 1});
          next_queue.push_back({x, y, dir ^ 3});
        }
        // Check for a meeting point.
        int other_dir = -1;
        if (mask[dir ^ 1][y][x] == (queue_num ^ 2)) {
          other_dir = dir ^ 1;
        } else if (mask[dir ^ 3][y][x] == (queue_num ^ 2)) {
          other_dir = dir ^ 3;
        }
        if (other_dir != -1) {
          RotateMirrorsOnPrevPath(queue_num ^ 2, x, y, dir);
          RotateMirrorsOnPrevPath(queue_num, ox, oy, dir ^ 2);
          map[y1][x1] = map[y2][x2] = '.';
          return;
        }
        break;
      }
    }
    queue->swap(next_queue);
  }
  map[y1][x1] = map[y2][x2] = '.';
}

int main() {
  queue1.reserve(1024);
  queue2.reserve(1024);
  next_queue.reserve(1024);
  map[0][0] = 0;
  while (std::scanf("%d %d", &columns, &rows) == 2 && columns != -1) {
    if (map[0][0]) std::putchar('\n');
    for (int i = 0; i < rows; ++i) std::scanf("%s", map[i]);
    RotateMirrors();
    for (int i = 0; i < rows; ++i) std::puts(map[i]);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

