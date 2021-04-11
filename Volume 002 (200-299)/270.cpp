/* @JUDGE_ID: 19899RK 270 C++ "By Anadan" */
// Lining Up
// Accepted (0.030 seconds with low memory spent)

#include <algorithm>
#include <cstdio>
#include <vector>

struct Point {
  int x, y;

  constexpr bool operator<(const Point& other) const {
    return (x != other.x) ? (x < other.x) : (y < other.y);
  }
};

int FindMaxPointsOnLine(std::vector<Point>& points) {
  const int size = points.size();
  if (size < 3) return size;

  int max_count = 2;
  std::sort(points.begin(), points.end());

  int left = size - 1;
  for (int line = 1; left >= 0; ++line) {
    const int ox = points[left].x;
    const int right = left + 1;
    bool skip_extension = (max_count >= line);
    for (; left >= 0 && points[left].x == ox; --left) {
      if (skip_extension) continue;
      const Point& origin = points[left];
      std::sort(points.begin() + right, points.end(),
                [&origin](const Point& o1, const Point& o2) {
                  // Return: y1/|x1| < y2/|x2| <=> y1*|x2| < y2*|x1|
                  return (o1.y - origin.y) * (o2.x - origin.x) <
                         (o2.y - origin.y) * (o1.x - origin.x);
                });
      for (int start = right; start < size; ++start) {
        const Point p1 = {points[start].x - origin.x,
                          points[start].y - origin.y};
        int end = start + 1;
        for (; end < size; ++end) {
          const Point p2 = {points[end].x - origin.x, points[end].y - origin.y};
          if (p1.y * p2.x != p2.y * p1.x) break;
        }
        const int count = end - start + 1;
        if (max_count < count) {
          max_count = count;
          skip_extension = true;
          break;
        }
        start = end - 1;
      }
    }
    const int count = right - left - 1;
    if (max_count < count) max_count = count;
  }
  return max_count;
}

int main() {
  char buffer[512];
  int N;
  scanf("%d\n\n", &N);
  std::vector<Point> points;
  points.reserve(700);
  while (N--) {
    points.clear();
    while (1) {
      Point pt;
      if (!std::fgets(buffer, sizeof(buffer), stdin)) break;
      if (std::sscanf(buffer, "%d %d\n", &pt.x, &pt.y) < 2) break;
      points.push_back(std::move(pt));
    }
    std::printf("%d\n", FindMaxPointsOnLine(points));
    if (N) std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

