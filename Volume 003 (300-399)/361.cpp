/* @JUDGE_ID: 19899RK 361 C++11 "By Anadan" */
// Cops and Robbers
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

struct Point {
  int x, y;

  bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }

  bool operator<(const Point& other) const {
    if (x != other.x) return x < other.x;
    return y < other.y;
  }
};

// Returns the signed doubled area of the {p1, p2, p3} triangle.
// Positive sign <=> {p1,p2,p3} are in counterclockwise order.
// |     i         j     k |
// | p2.x-p1.x p2.y-p1.y 0 |
// | p3.x-p1.x p3.y-p1.y 0 |
int TriangleSignedArea2(const Point& p1, const Point& p2, const Point& p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

void MakeConvexHull(std::vector<Point>& points) {
  if (points.size() < 2) return;
  std::sort(points.begin(), points.end());
  if (points[0] == points.back()) {
    points.resize(1);
    return;
  }
  std::vector<Point> above, below;
  above.push_back(points[0]);
  below.push_back(points[0]);
  for (int i = 1; i < points.size(); ++i) {
    const int cmp = TriangleSignedArea2(points[0], points[i], points.back());
    if (cmp > 0 || i + 1 == points.size()) {
      // Below the line.
      while (below.size() > 1 &&
             TriangleSignedArea2(below[below.size() - 2], below.back(),
                                 points[i]) <= 0) {
        below.pop_back();
      }
      below.push_back(points[i]);
    }
    if (cmp < 0 || i + 1 == points.size()) {
      // Above the line.
      while (above.size() > 1 &&
             TriangleSignedArea2(above[above.size() - 2], above.back(),
                                 points[i]) >= 0) {
        above.pop_back();
      }
      above.push_back(points[i]);
    }
  }
  int count = 0;
  for (const Point& pt : below) points[count++] = pt;
  for (int i = above.size() - 2; i > 0; --i) points[count++] = above[i];
  points.resize(count);
}

bool IsInsideInterval(int a, int b, int x) {
  if (a > b) std::swap(a, b);
  return a <= x && x <= b;
}

bool IsInsideConvexHull(const std::vector<Point>& points, const Point& pt) {
  if (points.empty()) return false;
  if (points.size() == 1) return points[0] == pt;
  for (int j = 0; j < points.size(); ++j) {
    if (points[j] == pt) return true;
    const int i = j ? j - 1 : points.size() - 1;
    const int cmp = TriangleSignedArea2(points[i], points[j], pt);
    if (cmp < 0) return false;
    if (cmp == 0) {
      return IsInsideInterval(points[i].x, points[j].x, pt.x) &&
             IsInsideInterval(points[i].y, points[j].y, pt.y);
    }
  }
  return true;
}

void ReadPoints(const int size, std::vector<Point>& points) {
  points.resize(size);
  for (int i = 0; i < size; ++i) {
    std::scanf("%d%d", &points[i].x, &points[i].y);
  }
}

void DebugPrint(const std::vector<Point>& points) {
  for (const Point& pt : points) {
    std::printf("(%d, %d) ", pt.x, pt.y);
  }
  std::putchar('\n');
}

int main() {
  int dataset = 0, c, r, o;
  std::vector<Point> cops, robbers, others;
  while (std::scanf("%d%d%d", &c, &r, &o) == 3 && c + r + o != 0) {
    ReadPoints(c, cops);
    ReadPoints(r, robbers);
    ReadPoints(o, others);

    MakeConvexHull(cops);
    MakeConvexHull(robbers);

    std::printf("Data set %d:\n", ++dataset);
    for (const Point& pt : others) {
      const bool is_safe = (c > 2) && IsInsideConvexHull(cops, pt);
      if (is_safe) {
        std::printf("     Citizen at (%d,%d) is safe.\n", pt.x, pt.y);
      } else {
        const bool is_robbed = (r > 2) && IsInsideConvexHull(robbers, pt);
        if (is_robbed) {
          std::printf("     Citizen at (%d,%d) is robbed.\n", pt.x, pt.y);
        } else {
          std::printf("     Citizen at (%d,%d) is neither.\n", pt.x, pt.y);
        }
      }
    }
    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
