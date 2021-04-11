/* @JUDGE_ID: 19899RK 238 C++ "By Anadan" */
// Jill’s Bike
// Accepted (0.020 seconds with low memory spent)

#include <cassert>
#include <cstdio>
#include <vector>

// dir: { ↑ → ↓ ← }
//      { 0 1 2 3 }
// 0^1, 0^3 => 1, 3
// 1^1, 1^3 => 0, 2
// 2^1, 2^3 => 3, 1
// 3^1, 3^3 => 2, 0
const int kSteps[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

struct Point {
  int x, y;
};

int mask_to_dirs[16][4];
int altitude[32][32];
int road_out_dirs[32][32], road_in_dirs[32][32], prev[2][32][32];

void CollectBackPath(int code, std::vector<Point>& path) {
  code &= 0xFFFF;
  const int x = code & 0xFF;
  const int y = code >> 8;
  if ((prev[0][y][x] & 0xFFFF) != code) CollectBackPath(prev[0][y][x], path);
  path.push_back({x, y});
}

void CollectForwardPath(int code, std::vector<Point>& path) {
  while (1) {
    code &= 0xFFFF;
    const int x = code & 0xFF;
    const int y = code >> 8;
    path.push_back({x, y});
    if ((prev[1][y][x] & 0xFFFF) == code) break;
    code = prev[1][y][x];
  }
}

void FindPath(const int Y, const int X, int generation,
              std::vector<Point>& queue1, std::vector<Point>& queue2,
              std::vector<Point>& next_queue, std::vector<Point>& path) {
  generation <<= 16;
  int nx = queue1[0].x;
  int ny = queue1[0].y;
  prev[0][ny][nx] = generation | (ny << 8) | nx;

  nx = queue2[0].x;
  ny = queue2[0].y;
  prev[1][ny][nx] = generation | (ny << 8) | nx;

  int queue_num;
  std::vector<Point>* queue;
  while (!queue1.empty() || !queue2.empty()) {
    if (queue2.empty() || (!queue1.empty() && queue1.size() <= queue2.size())) {
      queue = &queue1;
      queue_num = 0;
    } else {
      queue = &queue2;
      queue_num = 1;
    }
    next_queue.clear();
    while (!queue->empty()) {
      const int x = queue->back().x;
      const int y = queue->back().y;
      queue->pop_back();
      int mask = (queue_num == 0) ? road_out_dirs[y][x] : road_in_dirs[y][x];
      for (int k = 0; k < 4; ++k) {
        const int dir = mask_to_dirs[mask][k];
        if (dir == -1) break;
        if (queue_num == 0) {
          nx = x + kSteps[dir][0];
          ny = y + kSteps[dir][1];
        } else {
          nx = x + kSteps[dir ^ 2][0];
          ny = y + kSteps[dir ^ 2][1];
        }
        if ((prev[queue_num][ny][nx] ^ generation) <= 0xFFFF) continue;
        if ((prev[queue_num ^ 1][ny][nx] ^ generation) <= 0xFFFF) {
          if (queue_num == 0) {
            CollectBackPath((y << 8) | x, path);
            CollectForwardPath((ny << 8) | nx, path);
          } else {
            CollectBackPath((ny << 8) | nx, path);
            CollectForwardPath((y << 8) | x, path);
          }
          return;
        }
        prev[queue_num][ny][nx] = generation | (y << 8) | x;
        next_queue.push_back({nx, ny});
      }
    }
    queue->swap(next_queue);
  }
}

int main() {
  int N, M, x1, y1, x2, y2, dir, generation;
  bool has_output = false;
  std::vector<Point> path, queue1, queue2, next_queue;
  path.reserve(512);
  queue1.reserve(512);
  queue2.reserve(512);
  next_queue.reserve(512);
  for (int i = 0; i < 32; ++i) {
    road_out_dirs[0][i] = road_out_dirs[i][0] = 0;
    road_in_dirs[0][i] = road_in_dirs[i][0] = 0;
  }
  for (int mask = 0; mask < 16; ++mask) {
    int count = 0;
    for (int dir = 0; dir < 4; ++dir) {
      if (mask & (1 << dir)) mask_to_dirs[mask][count++] = dir;
    }
    while (count < 4) {
      mask_to_dirs[mask][count++] = -1;
    }
  }
  while (std::scanf("%d%d", &N, &M) == 2) {
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= M; ++j) {
        std::scanf("%d", &altitude[i][j]);
        road_out_dirs[i][j] = road_in_dirs[i][j] = 0;
      }
    }
    for (int i = 1; i <= N + 1; ++i) {
      road_out_dirs[i][M + 1] = road_in_dirs[i][M + 1] = 0;
    }
    for (int j = 1; j <= M + 1; ++j) {
      road_out_dirs[N + 1][j] = road_in_dirs[N + 1][j] = 0;
    }
    while (std::scanf("%d%d%d%d", &y1, &x1, &y2, &x2) == 4 && x1) {
      if (y1 == y2) {
        dir = (x1 < x2) ? 1 : 3;
      } else if (x1 == x2) {
        dir = (y1 < y2) ? 2 : 0;
      } else {
        assert(0);
      }
      while (y1 != y2 || x1 != x2) {
        const int nx = x1 + kSteps[dir][0];
        const int ny = y1 + kSteps[dir][1];
        const int alt_diff = altitude[y1][x1] - altitude[ny][nx];
        if (alt_diff >= -10 && alt_diff <= 10) {
          road_out_dirs[y1][x1] |= (1 << dir);
          road_in_dirs[ny][nx] |= (1 << dir);
        }
        x1 = nx;
        y1 = ny;
      }
    }
    generation = 0;
    for (int i = 1; i <= N; ++i) {
      for (int j = 1; j <= M; ++j) {
        prev[0][i][j] = prev[1][i][j] = 0;
      }
    }
    while (std::scanf("%d%d%d%d", &y1, &x1, &y2, &x2) == 4 && x1) {
      if (has_output) std::putchar('\n');
      has_output = true;
      if (y1 == y2 && x1 == x2) {
        std::printf("To get from %d-%d to %d-%d, stay put!\n", y1, x1, y2, x2);
      } else {
        path.clear();
        queue1.clear();
        queue2.clear();
        queue1.push_back({x1, y1});
        queue2.push_back({x2, y2});
        ++generation;
        FindPath(N, M, generation, queue1, queue2, next_queue, path);
        if (path.empty()) {
          std::printf("There is no acceptable route from %d-%d to %d-%d.\n", y1,
                      x1, y2, x2);
        } else {
          std::printf("%d-%d", path[0].y, path[0].x);
          for (int i = 1; i < path.size(); ++i) {
            std::printf(" to %d-%d", path[i].y, path[i].x);
          }
          std::putchar('\n');
        }
      }
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

