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
constexpr int fsign(double x) { return feq_zero(x) ? 0 : (x < 0 ? -1 : 1); }

struct Point {
  double x, y;

  constexpr bool operator==(const Point& pt) const {
    return feq_zero(x - pt.x) && feq_zero(y - pt.y);
  }

  constexpr bool operator!=(const Point& pt) const {
    return !feq_zero(x - pt.x) || !feq_zero(y - pt.y);
  }
};

struct Interval {
  Point p1, p2;

  constexpr double distance() const {
    return std::sqrt((p2.x - p1.x) * (p2.x - p1.x) +
                     (p2.y - p1.y) * (p2.y - p1.y));
  }
};

struct Rectangle {
  Point points[4];
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

bool IsPointStrictlyInside(const Rectangle& rect, const Point& pt) {
  for (int k = 0; k < 4; ++k) {
    const Point& p1 = rect.points[k];
    const Point& p2 = (k == 3) ? rect.points[0] : rect.points[k + 1];
    if (fle_zero(TriangleSignedArea2(p1, p2, pt))) return false;
  }
  return true;
}

bool IntervalsIntersectInside(const Interval& i1, const Interval& i2) {
  return (fsign(TriangleSignedArea2(i1.p1, i1.p2, i2.p1)) *
          fsign(TriangleSignedArea2(i1.p1, i1.p2, i2.p2))) < 0 &&
         (fsign(TriangleSignedArea2(i2.p1, i2.p2, i1.p1)) *
          fsign(TriangleSignedArea2(i2.p1, i2.p2, i1.p2))) < 0;
}

bool IntersectsRectangleInside(const Interval& i, const Rectangle& rect) {
  // Check only diagonals.
  return IntervalsIntersectInside(i, {rect.points[0], rect.points[2]}) ||
         IntervalsIntersectInside(i, {rect.points[1], rect.points[3]});
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
      if (IsPointStrictlyInside(rect, pt)) {
        graph.Exclude(i);
        break;
      }
    }
  }

  for (int i = 0; i < vertexes; ++i) {
    if (graph.IsExcluded(i)) continue;
    const Point& p1 =
        (i < start_index) ? rectangles[i / 4].points[i & 3] : start;
    for (int j = i + 1; j < vertexes; ++j) {
      if (graph.IsExcluded(j)) continue;
      const Point& p2 = (j < start_index) ? rectangles[j / 4].points[j & 3]
                                          : (j == start_index ? start : stop);
      const Interval interval{p1, p2};
      bool has_intersections = false;
      for (const Rectangle& rect : rectangles) {
        if (IntersectsRectangleInside(interval, rect)) {
          has_intersections = true;
          break;
        }
      }
      if (!has_intersections) {
        graph.Add(i, j, interval.distance());
      }
    }
  }
}

double FindShortestDistance(const int rectangles, Graph& graph) {
  constexpr double kMaxValue = std::numeric_limits<double>::max();
  const int vertexes = rectangles * 4 + 2;
  const int start_index = vertexes - 2;
  const int stop_index = vertexes - 1;

  // Solve with Dijkstra's algorithm.
  std::vector<double> distances(vertexes, kMaxValue);
  distances[start_index] = 0;
  auto cmp = [&](int i, int j) {
    if (distances[i] == distances[j]) return i < j;
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
        queue.erase(next_node);
        distances[next_node] = new_distance;
        queue.insert(next_node);
      }
    }
  }
  assert(distances[stop_index] < kMaxValue);
  return distances[stop_index];
}

void SetupRectangle(Rectangle* rect) {
  using std::swap;
  Point* points = rect->points;
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
      Point* points = rectangles[i].points;
      for (int j = 0; j < 3; ++j) {
        std::scanf("%lf%lf", &points[j].x, &points[j].y);
      }
      SetupRectangle(&rectangles[i]);
    }
    BuildGraph(rectangles, start, stop, graph);
    const double result = FindShortestDistance(rectangles.size(), graph);
    if (testcase) std::putchar('\n');
    std::printf("Scenario #%d\n   route distance: %.2lf\n", ++testcase, result);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
