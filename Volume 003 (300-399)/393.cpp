/* @JUDGE_ID: 19899RK 393 C++11 "By Anadan" */
// The Doors
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cmath>
#include <cstdio>
#include <vector>

constexpr double kEps = 1e-10;
constexpr bool fbetween(double l, double r, double value) {
  return l <= value + kEps && value <= r + kEps;
}

struct Point {
  double x, y;
};

struct Wall {
  double x, y[4];
  mutable double dist[4];  // Minimum distances.
};

constexpr double GetDistance(const Point& p1, const Point& p2) {
  return std::sqrt((p2.x - p1.x) * (p2.x - p1.x) +
                   (p2.y - p1.y) * (p2.y - p1.y));
}

bool HasIntersection(const std::vector<Wall>& walls, const int from,
                     const int to, const Point& p1, const Point& p2) {
  for (int i = from; i < to; ++i) {
    const Wall& w = walls[i];
    const double y = p1.y + (w.x - p1.x) * (p2.y - p1.y) / (p2.x - p1.x);
    if (!fbetween(w.y[0], w.y[1], y) && !fbetween(w.y[2], w.y[3], y)) {
      return true;
    }
  }
  return false;
}

double FindMinDistance(const std::vector<Wall>& walls) {
  const int size = walls.size();
  const Point start{0.0, 5.0};
  const Point end{10.0, 5.0};
  if (!HasIntersection(walls, 0, size, start, end)) return 10.0;

  double result = 1e300;
  for (int i = 0; i < size; ++i) {
    const Wall& w2 = walls[i];
    for (int k = 0; k < 4; ++k) {
      w2.dist[k] = 1e300;
      const Point p2{w2.x, w2.y[k]};
      // Check the distance from `start`.
      if (!HasIntersection(walls, 0, i, start, p2)) {
        w2.dist[k] = GetDistance(start, p2);
      }
      // Distances from other doors in the walls.
      for (int j = 0; j < i; ++j) {
        const Wall& w1 = walls[j];
        for (int m = 0; m < 4; ++m) {
          const Point p1{w1.x, w1.y[m]};
          if (!HasIntersection(walls, j + 1, i, p1, p2)) {
            w2.dist[k] = std::min(w2.dist[k], w1.dist[m] + GetDistance(p1, p2));
          }
        }
      }
      // Check the distance to `end`.
      if (!HasIntersection(walls, i + 1, size, p2, end)) {
        result = std::min(result, w2.dist[k] + GetDistance(p2, end));
      }
    }
  }
  return result;
}

int main() {
  int size;
  std::vector<Wall> walls;
  while (std::scanf("%d", &size) == 1 && size >= 0) {
    walls.resize(size);
    for (int i = 0; i < size; ++i) {
      Wall& w = walls[i];
      std::scanf("%lf%lf%lf%lf%lf", &w.x, &w.y[0], &w.y[1], &w.y[2], &w.y[3]);
    }
    const double distance = FindMinDistance(walls);
    std::printf("%.2lf\n", distance + kEps);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
