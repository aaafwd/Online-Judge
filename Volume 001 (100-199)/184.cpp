/* @JUDGE_ID: 19899RK 184 C++11 "By Anadan" */
// Laser Lines
// Accepted (0.000 seconds with low memory spent)

#include <algorithm>
#include <cstdio>
#include <vector>

struct Point {
  int x, y;

  constexpr bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }
};

std::vector<std::vector<Point>> FindAllLines(const std::vector<Point>& points) {
  const int size = points.size();
  std::vector<std::vector<Point>> lines;
  std::vector<Point> sorted = points;
  for (const auto& origin : points) {
    std::sort(sorted.begin(), sorted.end(),
              [&origin](const Point& o1, const Point& o2) {
                if (origin == o1) return true;
                if (origin == o2) return false;
                Point p1 = {o1.x - origin.x, o1.y - origin.y};
                Point p2 = {o2.x - origin.x, o2.y - origin.y};
                if (p1.x == 0 && p2.x == 0) {
                  return p1.y < p2.y;
                }
                if (p1.x == 0) return true;
                if (p2.x == 0) return false;
                if (p1.x < 0) {
                  p1.x = -p1.x;
                  p1.y = -p1.y;
                }
                if (p2.x < 0) {
                  p2.x = -p2.x;
                  p2.y = -p2.y;
                }
                // Return: y1/|x1| < y2/|x2| <=> y1*|x2| < y2*|x1|
                const int diff = p1.y * p2.x - p2.y * p1.x;
                if (diff == 0) {
                  if (p1.x == p2.x) return p1.y < p2.y;
                  return p1.x < p2.x;
                }
                return diff < 0;
              });
    for (int start = 1; start < size; ++start) {
      bool save_line = true;
      const Point p1 = {sorted[start].x - origin.x, sorted[start].y - origin.y};
      if ((p1.x == 0 && p1.y < 0) || p1.x < 0) save_line = false;
      int end = start + 1;
      for (; end < size; ++end) {
        const Point p2 = {sorted[end].x - origin.x, sorted[end].y - origin.y};
        if (p1.x == 0) {
          if (p2.x != 0) break;
        } else {
          const int diff = p1.y * p2.x - p2.y * p1.x;
          if (diff != 0) break;
        }
        if ((p2.x == 0 && p2.y < 0) || p2.x < 0) save_line = false;
      }
      if (save_line && end - start > 1) {
        std::vector<Point> line = {origin};
        for (int i = start; i < end; ++i) {
          line.push_back(sorted[i]);
        }
        lines.push_back(std::move(line));
      }
      start = end - 1;
    }
  }
  std::sort(
      lines.begin(), lines.end(),
      [](const std::vector<Point>& line1, const std::vector<Point>& line2) {
        for (int i = 0; i < line1.size() && i < line2.size(); ++i) {
          const auto& p1 = line1[i];
          const auto& p2 = line2[i];
          if (p1.x != p2.x) return p1.x < p2.x;
          if (p1.y != p2.y) return p1.y < p2.y;
        }
        return line1.size() < line2.size();
      });
  return lines;
}

int main() {
  int x, y;
  std::vector<Point> points;
  while (1) {
    points.clear();
    while (std::scanf("%d%d", &x, &y) == 2) {
      if (x == 0 && y == 0) break;
      points.push_back({x, y});
    }
    if (points.empty()) break;

    const auto lines = FindAllLines(points);
    if (lines.empty()) {
      std::puts("No lines were found");
    } else {
      std::puts("The following lines were found:");
      for (const auto& line : lines) {
        for (const auto& point : line) {
          std::printf("(%4d,%4d)", point.x, point.y);
        }
        std::puts("");
      }
    }
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */

