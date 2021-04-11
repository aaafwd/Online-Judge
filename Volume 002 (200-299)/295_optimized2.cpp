/* @JUDGE_ID: 19899RK 295 C++ "By Anadan" */
// Fatman
// Accepted (0.020 seconds with low memory spent)

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <set>
#include <vector>

struct Point {
  int x, y;
  bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }
};

class Edges {
 public:
  Edges() {
    const int kMaxWidth = 100;
    const int kMaxSqrDistance = kMaxWidth * kMaxWidth;
    std::set<int> sqr_distances_set;
    for (int i = 0; i <= kMaxWidth; ++i) {
      for (int j = 0; j <= kMaxWidth; ++j) {
        const int x = i * i + j * j;
        if (x <= kMaxSqrDistance) sqr_distances_set.insert(x);
      }
    }
    sqr_distances.assign(sqr_distances_set.begin(), sqr_distances_set.end());
    edges.resize(sqr_distances.size());
    edges_at_all_distances.resize(kMaxSqrDistance + 1, 0);
    for (int i = 0; i < sqr_distances.size(); ++i) {
      edges[i].reserve(64);
      const int sqr_distance = sqr_distances[i];
      edges_at_all_distances[sqr_distance] = &edges[i];
    }
  }

  void AddEdge(int i, int j, int sqr_distance) {
    edges_at_all_distances.data()[sqr_distance]->push_back({i, j});
  }

  int GetNextEdges(int pos, std::vector<Point>** result, int* sqr_distance) {
    std::vector<Point>* edges_data = edges.data();
    for (; pos < edges.size(); ++pos) {
      if (!edges_data[pos].empty()) {
        *result = &edges_data[pos];
        *sqr_distance = sqr_distances[pos];
        return pos + 1;
      }
    }
    return -1;
  }

  void clear() {
    std::vector<Point>* edges_data = edges.data();
    for (int i = 0; i < edges.size(); ++i) {
      edges_data[i].clear();
    }
  }

 private:
  std::vector<int> sqr_distances;
  std::vector<std::vector<Point>> edges;
  std::vector<std::vector<Point>*> edges_at_all_distances;
};

inline int sqr(int x) { return x * x; }

int dsu_parent[384], dsu_rank[384];

void DsuInit(int size) {
  for (int i = 0; i < size; ++i) {
    dsu_parent[i] = i;
    dsu_rank[i] = 1;
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
  dsu_rank[a] += dsu_rank[b];
  // if (dsu_rank[a] == dsu_rank[b]) ++dsu_rank[a];
}

int max_diameter_slice[101];

double FindMaxDiameter(const int W, int size, Point* points, Point* ext_points,
                       Edges& edges) {
  if (size == 0) return W;
  std::sort(points, points + size, [](const Point& p1, const Point& p2) {
    if (p1.x != p2.x) return p1.x < p2.x;
    return p1.y < p2.y;
  });

  // Optimization: find upper bound for the sqr(diameter).
  int upper_bound = sqr(W);
  for (int i = 0; i < size; ++i) {
    const Point& p1 = points[i];
    for (int j = i + size / 2; j < size && j < i + 5; ++j) {
      const Point& p2 = points[j];
      const int middle = sqr(p2.x - p1.x) + sqr(p2.y - p1.y);
      upper_bound = std::min(
          upper_bound,
          std::max(middle, std::min(std::max(sqr(p1.y), sqr(W - p2.y)),
                                    std::max(sqr(p2.y), sqr(W - p1.y)))));
    }
  }

  for (int i = 0; i < size; ++i) {
    const int x = points[i].x;
    int slice_max = sqr(points[i].y);
    for (++i; i < size; ++i) {
      if (points[i].x != x) break;
      slice_max = std::max(slice_max, sqr(points[i].y - points[i - 1].y));
    }
    --i;
    slice_max = std::max(slice_max, sqr(W - points[i].y));
    max_diameter_slice[x] = std::min(slice_max, upper_bound);
  }
  for (int i = size - 1; i >= 0; --i) {
    if (i + 1 >= size) continue;
    const int x1 = points[i].x;
    const int x2 = points[i + 1].x;
    max_diameter_slice[x1] =
        std::min(max_diameter_slice[x1], max_diameter_slice[x2]);
  }

  int ext_points_size = 0;
  for (int i = 0; i < size; ++i) {
    const int x = points[i].x;
    if (points[i].y != 0 && sqr(points[i].y) <= max_diameter_slice[x]) {
      ext_points[ext_points_size++] = {x, 0};
    }
    for (; i < size; ++i) {
      if (points[i].x != x) break;
      ext_points[ext_points_size++] = std::move(points[i]);
    }
    --i;
    const int last_y = ext_points[ext_points_size - 1].y;
    if (last_y != W && sqr(W - last_y) <= max_diameter_slice[x]) {
      ext_points[ext_points_size++] = {x, W};
    }
  }
  size = ext_points_size;
  DsuInit(size);

  int bottom = -1;
  int top = -1;
  for (int i = 0; i < size; ++i) {
    const Point& p1 = ext_points[i];
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

  for (int i = 0; i < size; ++i) {
    const Point& p1 = ext_points[i];
    if (p1.y == 0) {
      const int j = i + 1;
      if (j < size) {
        const Point& p2 = ext_points[j];
        const int sqr_distance = sqr(p2.x - p1.x) + sqr(p2.y - p1.y);
        if (sqr_distance <= max_diameter_slice[p2.x]) {
          edges.AddEdge(i, j, sqr_distance);
        }
      }
      continue;
    }
    if (p1.y == W) {
      const int j = i - 1;
      if (j >= 0) {
        const Point& p2 = ext_points[j];
        const int sqr_distance = sqr(p2.x - p1.x) + sqr(p2.y - p1.y);
        if (sqr_distance <= max_diameter_slice[p2.x]) {
          edges.AddEdge(i, j, sqr_distance);
        }
      }
      continue;
    }
    for (int j = i + 1; j < size; ++j) {
      const Point& p2 = ext_points[j];
      if (p2.y == 0 || p2.y == W) continue;
      if (p1.x == p2.x && j - i > 1) continue;
      int sqr_distance = sqr(p2.x - p1.x);
      int tmp_upper_bound = max_diameter_slice[p2.x];
      if (sqr_distance > tmp_upper_bound) break;
      sqr_distance += sqr(p2.y - p1.y);
      if (sqr_distance <= tmp_upper_bound) edges.AddEdge(i, j, sqr_distance);
    }
  }

  int diameter = 0;
  int pos = 0;
  while (pos != -1) {
    top = DsuGetParent(top);
    bottom = DsuGetParent(bottom);
    if (top == bottom) break;
    std::vector<Point>* joins;
    pos = edges.GetNextEdges(pos, &joins, &diameter);
    for (int i = 0; i < joins->size(); ++i) {
      DsuJoin(joins->data()[i].x, joins->data()[i].y);
    }
  }
  return std::sqrt(diameter);
}

int main() {
  Point points[128], ext_points[384];
  Edges edges;
  int test_cases, L, W, N, x, y, size;
  std::scanf("%d", &test_cases);
  for (int t = 1; t <= test_cases; ++t) {
    edges.clear();
    std::scanf("%d%d%d", &L, &W, &N);
    size = 0;
    for (int i = 0; i < N; ++i) {
      std::scanf("%d%d", &points[size].x, &points[size].y);
      if (points[size].y != 0 && points[size].y != W) ++size;
    }
    std::printf("Maximum size in test case %d is %.4lf.\n", t,
                FindMaxDiameter(W, size, points, ext_points, edges));
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

