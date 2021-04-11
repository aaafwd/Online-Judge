/* @JUDGE_ID: 19899RK 295 C++ "By Anadan" */
// Fatman
// Accepted (0.050 seconds with low memory spent)

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

struct Point {
  int x, y;
};

struct Edge {
  int i, j, sqr_distance;
};

inline int sqr(int x) { return x * x; }

int dsu_parent[384], dsu_rank[384];

void DsuInit(int size) {
  for (int i = 0; i < size; ++i) {
    dsu_parent[i] = i;
    dsu_rank[i] = 0;
  }
}

int DsuGetParent(int x) {
  if (dsu_parent[x] == x) return x;
  return (dsu_parent[x] = DsuGetParent(dsu_parent[x]));
}

void DsuJoin(int a, int b) {
  a = DsuGetParent(a);
  b = DsuGetParent(b);
  if (a == b) return;
  if (dsu_rank[a] < dsu_rank[b]) std::swap(a, b);
  dsu_parent[b] = a;
  if (dsu_rank[a] == dsu_rank[b]) ++dsu_rank[a];
}

double FindMaxDiameter(const int W, std::vector<Point>& points,
                       std::vector<Point>& ext_points,
                       std::vector<Edge>& edges) {
  if (points.empty()) return W;
  std::sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
    if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y < p2.y;
  });

  // Optimization: find upper bound for the sqr(diameter).
  int upper_bound = W * W;
  int size = points.size();
  for (int i = 0; i < size; ++i) {
    const int x = points[i].x;
    int slice_max = sqr(points[i].y);
    for (++i; i < size; ++i) {
      if (points[i].x != x) break;
      slice_max = std::max(slice_max, sqr(points[i].y - points[i - 1].y));
    }
    --i;
    slice_max = std::max(slice_max, sqr(W - points[i].y));
    upper_bound = std::min(upper_bound, slice_max);
  }

  ext_points.reserve(size * 3);
  for (int i = 0; i < size; ++i) {
    const int x = points[i].x;
    if (points[i].y != 0 && sqr(points[i].y) <= upper_bound) {
      ext_points.push_back({x, 0});
    }
    for (; i < size; ++i) {
      if (points[i].x != x) break;
      ext_points.push_back(std::move(points[i]));
    }
    --i;
    if (ext_points.back().y != W &&
        sqr(W - ext_points.back().y) <= upper_bound) {
      ext_points.push_back({x, W});
    }
  }
  size = ext_points.size();
  DsuInit(size);

  int bottom = -1;
  int top = -1;
  for (int i = 0; i < size; ++i) {
    const Point& p1 = ext_points.data()[i];
    if (p1.y == 0) {
      if (bottom == -1) {
        bottom = i;
      } else {
        DsuJoin(bottom, i);
      }
    }
    if (p1.y == W) {
      if (top == -1) {
        top = i;
      } else {
        DsuJoin(top, i);
      }
    }
  }

  edges.reserve((size * (size - 1)) / 2);
  for (int i = 0; i < size; ++i) {
    const Point& p1 = ext_points.data()[i];
    for (int j = i + 1; j < size; ++j) {
      const Point& p2 = ext_points.data()[j];
      if (p1.x == p2.x && j - i > 1) continue;
      if (p1.y == p2.y && (p1.y == 0 || p1.y == W)) continue;
      int sqr_distance = sqr(p2.x - p1.x);
      if (sqr_distance > upper_bound) break;
      sqr_distance += sqr(p2.y - p1.y);
      if (sqr_distance <= upper_bound) edges.push_back({i, j, sqr_distance});
    }
  }
  std::sort(edges.begin(), edges.end(), [](const Edge& e1, const Edge& e2) {
    return e1.sqr_distance < e2.sqr_distance;
  });

  int diameter = 0;
  for (int i = 0; i < edges.size(); ++i) {
    top = DsuGetParent(top);
    bottom = DsuGetParent(bottom);
    if (top == bottom) break;
    Edge& edge = edges.data()[i];
    diameter = edge.sqr_distance;
    DsuJoin(edge.i, edge.j);
  }
  return std::sqrt(diameter);
}

int main() {
  std::vector<Point> points, ext_points;
  std::vector<Edge> edges;
  int test_cases, L, W, N, x, y;
  std::scanf("%d", &test_cases);
  for (int t = 1; t <= test_cases; ++t) {
    points.clear();
    ext_points.clear();
    edges.clear();
    std::scanf("%d%d%d", &L, &W, &N);
    for (int i = 0; i < N; ++i) {
      std::scanf("%d%d", &x, &y);
      points.push_back({x, y});
    }
    std::printf("Maximum size in test case %d is %.4lf.\n", t,
                FindMaxDiameter(W, points, ext_points, edges));
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

