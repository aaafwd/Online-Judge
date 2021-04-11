/* @JUDGE_ID: 19899RK 225 C++11 "By Anadan" */
// Golygons
// Accepted (0.000 seconds with low memory spent)

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// dir: { ↑ → ↓ ← }
//      { 0 1 2 3  }
//      { n e s w  }
// 0^1, 0^3 => 1, 3
// 1^1, 1^3 => 0, 2
// 2^1, 2^3 => 3, 1
// 3^1, 3^3 => 2, 0
const int kSteps[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

struct Point {
  int x, y;
};

typedef std::unordered_map<int, std::vector<std::vector<int>>> GolygonsMap;

int EncodePoint(int x, int y, int dir) {
  x += 4096;
  y += 4096;
  assert(x >= 0 && y >= 0);
  return (x << 16) | (y << 2) | dir;
}

void UncodePoint(int code, int* x, int* y, int* dir) {
  *dir = code & 3;
  *y = ((code >> 2) & 0x3FFF) - 4096;
  *x = (code >> 16) - 4096;
}

void AdvanceWave(const int step, const std::unordered_set<int>& wave,
                 std::unordered_set<int>* wave_next) {
  int x, y, dir, nx, ny;
  wave_next->clear();
  wave_next->reserve((wave.size() * 3) / 2);
  for (const int code : wave) {
    UncodePoint(code, &x, &y, &dir);
    dir ^= 1;
    nx = x + kSteps[dir][0] * step;
    ny = y + kSteps[dir][1] * step;
    wave_next->insert(EncodePoint(nx, ny, dir));
    dir ^= 2;
    nx = x + kSteps[dir][0] * step;
    ny = y + kSteps[dir][1] * step;
    wave_next->insert(EncodePoint(nx, ny, dir));
  }
}

void CollectGolygons(const std::unordered_set<int>* waves, int code, int step,
                     std::vector<int>* current, std::unordered_set<int>* mask,
                     std::vector<std::vector<int>>* golygons) {
  if (step == 0) {
    golygons->push_back(*current);
    return;
  }
  int x, y, dir;
  UncodePoint(code, &x, &y, &dir);
  (*current)[step - 1] = dir;
  dir ^= 2;

  x += kSteps[dir][0] * step;
  y += kSteps[dir][1] * step;
  dir ^= 1;
  code = EncodePoint(x, y, dir);
  if (waves[step - 1].count(code) && !mask->count(code | 3)) {
    mask->insert(code | 3);
    CollectGolygons(waves, code, step - 1, current, mask, golygons);
    mask->erase(code | 3);
  }

  dir ^= 2;
  code = EncodePoint(x, y, dir);
  if (waves[step - 1].count(code) && !mask->count(code | 3)) {
    mask->insert(code | 3);
    CollectGolygons(waves, code, step - 1, current, mask, golygons);
    mask->erase(code | 3);
  }
}

void RunPrecalc(GolygonsMap* golygons) {
  static const int kMaxStep = 16;  // Precalc: no Golygons for [17..20].
  static const int kStartCodes[4] = {EncodePoint(0, 0, 0), EncodePoint(0, 0, 1),
                                     EncodePoint(0, 0, 2),
                                     EncodePoint(0, 0, 3)};
  std::unordered_set<int> waves[kMaxStep + 1];
  waves[0].insert(EncodePoint(0, 0, 0));
  waves[1].insert(EncodePoint(1, 0, 1));
  waves[2].insert(EncodePoint(1, 2, 0));
  for (int step = 3; step <= kMaxStep; ++step) {
    AdvanceWave(step, waves[step - 1], &waves[step]);
    // Check for golygons.
    for (int dir = 0; dir < 4; ++dir) {
      if (waves[step].count(kStartCodes[dir])) {
        std::vector<int> current(step);
        std::unordered_set<int> mask;
        CollectGolygons(waves, kStartCodes[dir], step, &current, &mask,
                        &(*golygons)[step]);
      }
    }
  }

  // Flip and rotate the golygons.
  for (auto& kv : *golygons) {
    auto& paths = kv.second;
    paths.reserve(paths.size() * 8);
    // Flip over X-axis.
    for (int i = 0, size = paths.size(); i < size; ++i) {
      std::vector<int> path = paths[i];
      for (int j = 0; j < path.size(); ++j) {
        if (path[j] == 0 || path[j] == 2) path[j] ^= 2;
      }
      paths.push_back(std::move(path));
    }
    // Rotate.
    for (int i = 0, size = paths.size(); i < size; ++i) {
      for (int rot = 1; rot < 4; ++rot) {
        std::vector<int> path = paths[i];
        for (int j = 0; j < path.size(); ++j) {
          path[j] = (path[j] + rot) & 3;
        }
        paths.push_back(std::move(path));
      }
    }

    std::sort(paths.begin(), paths.end(),
              [](const std::vector<int>& path1, const std::vector<int>& path2) {
                for (int i = 0; i < path1.size(); ++i) {
                  int a = path1[i];
                  int b = path2[i];
                  if (a == 0 || a == 1) a ^= 1;
                  if (b == 0 || b == 1) b ^= 1;
                  if (a != b) return a < b;
                }
                return false;
              });
  }
}

bool IsBlockOnLine(int x, int y1, int y2, const std::vector<Point>& points) {
  if (y1 > y2) std::swap(y1, y2);
  auto it = std::lower_bound(points.begin(), points.end(), Point{x, y1},
                   [](const Point& p1, const Point& p2) {
                     if (p1.x != p2.x) return p1.x < p2.x;
                     return p1.y < p2.y;
                   });
  return it != points.end() && it->x == x && it->y <= y2;
}

bool VerifyGolygonWithBlocks(const std::vector<int>& golygon,
                             const std::vector<Point>& points_x,
                             const std::vector<Point>& points_y) {
  int x = 0, y = 0;
  for (int step = 0; step < golygon.size(); ++step) {
    const int dir = golygon[step];
    const int nx = x + kSteps[dir][0] * (step + 1);
    const int ny = y + kSteps[dir][1] * (step + 1);
    if (x == nx) {
      if (IsBlockOnLine(x, y, ny, points_x)) return false;
    } else {
      if (IsBlockOnLine(y, x, nx, points_y)) return false;
    }
    x = nx;
    y = ny;
  }
  return true;
}

int main() {
  GolygonsMap golygons;
  int test_cases = 0, N, M, x, y;
  std::vector<Point> points_x, points_y;
  std::scanf("%d", &test_cases);
  RunPrecalc(&golygons);
  while (test_cases--) {
    std::scanf("%d %d", &N, &M);
    points_x.clear();
    for (int i = 0; i < M; ++i) {
      std::scanf("%d %d", &x, &y);
      points_x.push_back({x, y});
    }
    if (golygons.count(N) == 0) {
      std::puts("Found 0 golygon(s).");
    } else {
      points_y = points_x;
      for (auto& pt : points_y) std::swap(pt.x, pt.y);
      std::sort(points_x.begin(), points_x.end(),
                [](const Point& p1, const Point& p2) {
                  if (p1.x != p2.x) return p1.x < p2.x;
                  return p1.y < p2.y;
                });
      std::sort(points_y.begin(), points_y.end(),
                [](const Point& p1, const Point& p2) {
                  if (p1.x != p2.x) return p1.x < p2.x;
                  return p1.y < p2.y;
                });
      int count = 0;
      for (const auto& golygon : golygons[N]) {
        if (VerifyGolygonWithBlocks(golygon, points_x, points_y)) {
          for (const int dir : golygon) std::putchar("nesw"[dir]);
          std::putchar('\n');
          ++count;
        }
      }
      std::printf("Found %d golygon(s).\n", count);
    }
    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
