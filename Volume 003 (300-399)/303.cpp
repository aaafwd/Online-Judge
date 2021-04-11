/* @JUDGE_ID: 19899RK 303 C++11 "By Anadan" */
// Pipe
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cmath>
#include <cstdio>
#include <vector>

struct Point {
  double x, y;
};

struct Line {
  double A, B, C;

  Line() {}
  Line(double a, double b, double c) : A(a), B(b), C(c) {}
  Line(const Point& p1, const Point& p2) {
    A = p1.y - p2.y;
    B = p2.x - p1.x;
    C = -A * p1.x - B * p1.y;
    // const double norm = (A > 0) ? std::hypot(A, B) : -std::hypot(A, B);
    // A /= norm;
    // B /= norm;
    // C /= norm;
  }
};

constexpr double kEps = 1e-10;
constexpr bool feq_zero(double x) { return -kEps <= x && x <= kEps; }
constexpr bool fge_zero(double x) { return -kEps <= x; }
constexpr bool fle_zero(double x) { return x <= kEps; }

// Returns the signed doubled area of the {p1, p2, p3} triangle.
// Positive sign <=> {p1,p2,p3} are in counterclockwise order.
// |     i         j     k |
// | p2.x-p1.x p2.y-p1.y 0 |
// | p3.x-p1.x p3.y-p1.y 0 |
double TriangleSignedArea2(const Point& p1, const Point& p2, const Point& p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool IntersectLinesAtSinglePoint(const Line& l1, const Line& l2, Point* pt) {
  //            |C1 B1|              |A1 C1|
  //            |C2 B2|              |A2 C2|
  // x = (-1) * -------;  y = (-1) * -------
  //            |A1 B1|              |A1 B1|
  //            |A2 B2|              |A2 B2|
  const double norm = l1.A * l2.B - l2.A * l1.B;
  if (feq_zero(norm)) return false;
  pt->x = (l2.C * l1.B - l1.C * l2.B) / norm;
  pt->y = (l2.A * l1.C - l1.A * l2.C) / norm;
  return true;
}

bool FindMaxPointInsidePipeForLine(const std::vector<Point>& points,
                                   const std::vector<Line>& above_lines,
                                   const std::vector<Line>& below_lines,
                                   const Point& p1, const Point& p2,
                                   double* x) {
  const int n = points.size();
  Point on_pipe = points[0];
  const Line line(p1, p2);

  double area = TriangleSignedArea2(p1, p2, on_pipe);
  if (!fge_zero(area)) return true;
  on_pipe.y -= 1;
  area = TriangleSignedArea2(p1, p2, on_pipe);
  if (!fle_zero(area)) return true;
  for (int i = 1; i < n; ++i) {
    on_pipe = points[i];
    area = TriangleSignedArea2(p1, p2, on_pipe);
    if (!fge_zero(area)) {
      bool res = IntersectLinesAtSinglePoint(line, above_lines[i], &on_pipe);
      assert(res);
      assert(points[i - 1].x - kEps <= on_pipe.x &&
             on_pipe.x <= points[i].x + kEps);
      if (*x < on_pipe.x) *x = on_pipe.x;
      return true;
    }
    on_pipe.y -= 1;
    area = TriangleSignedArea2(p1, p2, on_pipe);
    if (!fle_zero(area)) {
      bool res = IntersectLinesAtSinglePoint(line, below_lines[i], &on_pipe);
      assert(res);
      assert(points[i - 1].x - kEps <= on_pipe.x &&
             on_pipe.x <= points[i].x + kEps);
      if (*x < on_pipe.x) *x = on_pipe.x;
      return true;
    }
  }
  return false;
}

bool FindMaxPointInsidePipe(const std::vector<Point>& points,
                            const std::vector<Line>& above_lines,
                            const std::vector<Line>& below_lines, double* x) {
  const int n = points.size();
  Point p1, p2;
  *x = points[0].x;
  for (int i = 0; i < n; ++i) {
    p1 = points[i];
    for (int j = i + 1; j < n; ++j) {
      p2 = points[j];
      for (int z = 0; z < 4; ++z) {
        if (z == 1) p1.y -= 1;
        if (z == 2) p2.y -= 1;
        if (z == 3) p1.y = points[i].y;
        if (!FindMaxPointInsidePipeForLine(points, above_lines, below_lines, p1,
                                           p2, x)) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
  int n;
  std::vector<Point> points;
  std::vector<Line> above_lines, below_lines;
  double x;
  while (std::scanf("%d", &n) == 1 && n) {
    points.resize(n);
    above_lines.resize(n);
    below_lines.resize(n);
    for (int i = 0; i < n; ++i) {
      std::scanf("%lf%lf", &points[i].x, &points[i].y);
      if (i) {
        above_lines[i] = Line(points[i - 1], points[i]);
        below_lines[i] = Line(above_lines[i].A, above_lines[i].B,
                              above_lines[i].B + above_lines[i].C);
      }
    }
    if (FindMaxPointInsidePipe(points, above_lines, below_lines, &x)) {
      std::printf("%.2lf\n", x);
    } else {
      std::puts("Through all the pipe.");
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
