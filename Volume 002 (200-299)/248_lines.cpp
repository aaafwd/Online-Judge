/* @JUDGE_ID: 19899RK 248 C++11 "By Anadan" */
// Cutting Corners
// Accepted (0.020 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <set>
#include <vector>

constexpr double kEps = 1e-10;
constexpr bool feq_zero(double x) { return -kEps <= x && x <= kEps; }
constexpr bool fge_zero(double x) { return -kEps <= x; }
constexpr bool fle_zero(double x) { return x <= kEps; }

struct Point {
  double x, y;

  constexpr bool operator==(const Point& other) const {
    return feq_zero(x - other.x) && feq_zero(y - other.y);
  }

  constexpr bool operator!=(const Point& other) const {
    return !feq_zero(x - other.x) || !feq_zero(y - other.y);
  }
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

struct BoundingBox {
  double minx, maxx, miny, maxy;

  BoundingBox() {}
  BoundingBox(const Point& p1, const Point& p2)
      : minx(p1.x), maxx(p2.x), miny(p1.y), maxy(p2.y) {
    if (minx > maxx) std::swap(minx, maxx);
    if (miny > maxy) std::swap(miny, maxy);
  }

  constexpr bool IsWithinBoundaries(const Point& pt) const {
    return fge_zero(pt.x - minx) && fge_zero(maxx - pt.x) &&
           fge_zero(pt.y - miny) && fge_zero(maxy - pt.y);
  }
};

struct Interval {
  Point p1, p2;
  Line line;
  BoundingBox bounding_box;

  Interval() {}
  Interval(const Point& pp1, const Point& pp2)
      : p1(pp1), p2(pp2), line(p1, p2), bounding_box(p1, p2) {}
};

struct Rectangle {
  Point points[4];
  Interval diagonals[2];
};

// Scalar product.
constexpr double operator*(const Point& p1, const Point& p2) {
  return p1.x * p2.x + p1.y * p2.y;
}

constexpr Point operator+(const Point& p1, const Point& p2) {
  return Point{p1.x + p2.x, p1.y + p2.y};
}

constexpr Point operator-(const Point& p1, const Point& p2) {
  return Point{p1.x - p2.x, p1.y - p2.y};
}

double TriangleSignedArea2(const Point& p1, const Point& p2, const Point& p3) {
  return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

bool IntersectBoundingBoxes(const BoundingBox& b1, const BoundingBox& b2) {
  return fge_zero(std::min(b1.maxx, b2.maxx) - std::max(b1.minx, b2.minx)) &&
         fge_zero(std::min(b1.maxy, b2.maxy) - std::max(b1.miny, b2.miny));
}

bool IsPointStrictlyInsideRectangle(const Rectangle& rect, const Point& pt) {
  for (int k = 0; k < 4; ++k) {
    const Point& p1 = rect.points[k];
    const Point& p2 = (k == 3) ? rect.points[0] : rect.points[k + 1];
    if (fle_zero(TriangleSignedArea2(p1, p2, pt))) return false;
  }
  return true;
}

bool IntersectLinesAtSinglePoint(const Line& l1, const Line& l2, Point* pt) {
  const double norm = l1.A * l2.B - l2.A * l1.B;
  if (feq_zero(norm)) return false;
  pt->x = (l2.C * l1.B - l1.C * l2.B) / norm;
  pt->y = (l2.A * l1.C - l1.A * l2.C) / norm;
  return true;
}

bool IntersectIntervalsStrictlyInside(const Interval& i1, const Interval& i2) {
  Point pt;
  if (!IntersectBoundingBoxes(i1.bounding_box, i2.bounding_box) ||
      !IntersectLinesAtSinglePoint(i1.line, i2.line, &pt)) {
    return false;
  }
  return i1.bounding_box.IsWithinBoundaries(pt) &&
         i2.bounding_box.IsWithinBoundaries(pt) && pt != i1.p1 && pt != i1.p2 &&
         pt != i2.p1 && pt != i2.p2;
}

bool IntervalIntersectsRectangleInsides(const Interval& interval,
                                        const Rectangle& rect) {
  return IntersectIntervalsStrictlyInside(interval, rect.diagonals[0]) ||
         IntersectIntervalsStrictlyInside(interval, rect.diagonals[1]);
}

struct Graph {
  void clear() { ++gen_; }

  bool HasEdge(int i, int j) const { return connected_[i][j] == gen_; }

  double GetDistance(int i, int j) const {
    assert(HasEdge(i, j));
    return distance_[i][j];
  }

  void Add(int i, int j, double distance) {
    connected_[i][j] = connected_[j][i] = gen_;
    distance_[i][j] = distance_[j][i] = distance;
  }

  void Exclude(int i) { excluded_[i] = gen_; }

  bool IsExcluded(int i) const { return excluded_[i] == gen_; }

  int gen_ = 0;
  int excluded_[96] = {0};
  int connected_[96][96] = {0};
  double distance_[96][96];
};

void BuildGraph(const std::vector<Rectangle>& rectangles, const Point& start,
                const Point& stop, Graph& graph) {
  graph.clear();

  const int vertexes = rectangles.size() * 4 + 2;
  const int start_index = vertexes - 2;
  const int stop_index = vertexes - 1;

  // Mask all points that are strictly inside a rectangle.
  for (int i = 0; i < start_index; ++i) {
    const Point& pt = rectangles[i / 4].points[i & 3];
    for (const Rectangle& rect : rectangles) {
      if (IsPointStrictlyInsideRectangle(rect, pt)) {
        graph.Exclude(i);
        break;
      }
    }
  }

  for (int i = 0; i < vertexes; ++i) {
    if (graph.IsExcluded(i)) continue;
    const int rect_index1 = i / 4;
    const Point& p1 =
        (i < start_index) ? rectangles[rect_index1].points[i & 3] : start;
    for (int j = i + 1; j < vertexes; ++j) {
      if (graph.IsExcluded(j)) continue;
      const int rect_index2 = j / 4;
      const Point& p2 = (j < start_index)
                            ? rectangles[rect_index2].points[j & 3]
                            : (j == start_index ? start : stop);
      Interval interval{p1, p2};

      bool has_intersections = false;
      for (const Rectangle& rect : rectangles) {
        if (IntervalIntersectsRectangleInsides(interval, rect)) {
          has_intersections = true;
          break;
        }
      }
      if (!has_intersections) {
        const double distance = std::hypot(p2.x - p1.x, p2.y - p1.y);
        graph.Add(i, j, distance);
      }
    }
  }
}

double FindShortestDistance(const int rectangles, Graph& graph) {
  const int vertexes = rectangles * 4 + 2;
  const int start_index = vertexes - 2;
  const int stop_index = vertexes - 1;

  // Solve with Dijkstra's algorithm.
  std::vector<double> distances(vertexes, std::numeric_limits<double>::max());
  distances[start_index] = 0;
  auto cmp = [&](int i, int j) {
    if (feq_zero(distances[i] - distances[j])) return i < j;
    return distances[i] < distances[j];
  };
  std::set<int, decltype(cmp)> queue(cmp);

  queue.insert(start_index);
  while (!queue.empty()) {
    const int node = *queue.begin();
    if (node == stop_index) break;
    queue.erase(queue.begin());
    graph.Exclude(node);
    for (int next_node = 0; next_node < vertexes; ++next_node) {
      if (graph.IsExcluded(next_node) || !graph.HasEdge(node, next_node)) {
        continue;
      }
      const double new_distance =
          distances[node] + graph.GetDistance(node, next_node);
      if (new_distance < distances[next_node]) {
        if (queue.find(next_node) != queue.end()) queue.erase(next_node);
        distances[next_node] = new_distance;
        queue.insert(next_node);
      }
    }
  }
  assert(distances[stop_index] < std::numeric_limits<double>::max());
  return distances[stop_index];
}

int main() {
  int testcase = 0, n;
  Point start, stop;
  std::vector<Rectangle> rectangles;
  Graph graph;

  while (std::scanf("%d", &n) == 1 && n >= 0) {
    std::scanf("%lf%lf%lf%lf", &start.x, &start.y, &stop.x, &stop.y);
    rectangles.resize(n);
    for (int i = 0; i < n; ++i) {
      using std::swap;
      Point* points = rectangles[i].points;
      for (int j = 0; j < 3; ++j) {
        std::scanf("%lf%lf", &points[j].x, &points[j].y);
      }
      // Make {0,1,2} points in counterclockwise order.
      if (feq_zero((points[1] - points[0]) * (points[2] - points[0]))) {
        swap(points[0], points[1]);
      } else if (feq_zero((points[1] - points[2]) * (points[0] - points[2]))) {
        swap(points[2], points[1]);
      }
      assert(feq_zero((points[0] - points[1]) * (points[2] - points[1])));
      if (fle_zero(TriangleSignedArea2(points[0], points[1], points[2]))) {
        swap(points[0], points[2]);
      }
      assert(TriangleSignedArea2(points[0], points[1], points[2]) >= -kEps);
      points[3] = points[0] + points[2] - points[1];
      rectangles[i].diagonals[0] = Interval{points[0], points[2]};
      rectangles[i].diagonals[1] = Interval{points[1], points[3]};
    }
    BuildGraph(rectangles, start, stop, graph);
    const double result = FindShortestDistance(rectangles.size(), graph) + kEps;
    if (testcase) std::putchar('\n');
    std::printf("Scenario #%d\n   route distance: %.2lf\n", ++testcase, result);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
