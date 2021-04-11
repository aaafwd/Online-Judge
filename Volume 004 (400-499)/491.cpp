/* @JUDGE_ID: 19899RK 491 C++11 "By Anadan" */
// Tile Topology
// Accepted (0.000 seconds with low memory spent)
//
// Generates one-sided polyominoes (https://en.wikipedia.org/wiki/Polyomino).
// Number of one-sided polyominoes with n cells: https://oeis.org/A000988
//
// Time to generate the answer (g++ -lm -lcrypt -O2 -pipe -D NDEBUG):
//     N=11: 0.141s
//     N=12: 0.715s
//     N=13: 3.171s
//     N=14: 14.002s
//     N=15: 1m1.920s
//     N=16: 5m31.590s
//     N=17: 26m20.486s

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <functional>
#include <string>
#include <unordered_set>
#include <vector>

constexpr int kDirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

struct Point {
  int x, y;

  bool operator==(const Point& other) const {
    return x == other.x && y == other.y;
  }
};

class Polyomino {
 public:
  static Polyomino BuildFromPoints(std::vector<Point> points) {
    int min_x = points[0].x;
    int min_y = points[0].y;
    for (const Point& p : points) {
      if (min_x > p.x) min_x = p.x;
      if (min_y > p.y) min_y = p.y;
    }
    // Pin the points to the X & Y axis.
    for (Point& p : points) {
      p.x -= min_x;
      p.y -= min_y;
    }
    SortPointsForPolyomino(&points);
    return BuildFromSortedPoints(points);
  }

  static Polyomino BuildFromSortedPoints(const std::vector<Point>& points) {
    if (points.size() <= 16) {
      std::string serialized(points.size(), 0);
      for (int i = 0; i < points.size(); ++i) {
        serialized[i] = static_cast<char>((points[i].x << 4) | points[i].y);
      }
      return Polyomino(serialized);
    } else {
      std::string serialized(points.size() * 2, 0);
      for (int i = 0; i < points.size(); ++i) {
        serialized[2 * i] = static_cast<char>(points[i].x);
        serialized[2 * i + 1] = static_cast<char>(points[i].y);
      }
      return Polyomino(serialized);
    }
  }

  static void SortPointsForPolyomino(std::vector<Point>* points) {
    std::sort(points->begin(), points->end(),
              [](const Point& a, const Point& b) {
                if (a.y == b.y) return a.x < b.x;
                return a.y < b.y;
              });
  }

  std::vector<Point> AsPoints() const {
    if (serialized_.size() <= 16) {
      std::vector<Point> points(serialized_.size());
      for (int i = 0; i < points.size(); ++i) {
        unsigned char ch = static_cast<unsigned char>(serialized_[i]);
        points[i].x = ch >> 4;
        points[i].y = ch & 15;
      }
      return points;
    } else {
      std::vector<Point> points(serialized_.size() / 2);
      for (int i = 0; i < points.size(); ++i) {
        points[i].x = serialized_[2 * i];
        points[i].y = serialized_[2 * i + 1];
      }
      return points;
    }
  }

  std::string DebugString() const {
    std::string str;
    const std::vector<Point> points = AsPoints();
    for (const Point& p : points) {
      str += "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
    }
    return str;
  }

 private:
  friend class PolyominoesSet;

  explicit Polyomino(std::string serialized)
      : serialized_(std::move(serialized)) {}

  // Serialized points ordered by Y axis then by X axis.
  std::string serialized_;
};

class PolyominoesSet {
 public:
  void forEach(const std::function<void(const Polyomino&)>& fn) const {
    for (const std::string& serialized : set_) {
      fn(Polyomino(serialized));
    }
  }

  std::size_t size() const { return set_.size(); }

  bool contains(const Polyomino& polyomino) const {
    return set_.find(polyomino.serialized_) != set_.end();
  }

  bool insert(const Polyomino& polyomino) {
    return set_.insert(polyomino.serialized_).second;
  }

  void swap(PolyominoesSet& other) { set_.swap(other.set_); }

  void clear() { set_.clear(); }

 private:
  std::unordered_set<std::string> set_;
};

// Rotates a given Polyomino clockwise to 90 degree.
// |x'|   | 0  1|   |x|
// |  | = |     | * | |
// |y'|   |-1  0|   |y|
Polyomino Rotate90(const Polyomino& polyomino) {
  std::vector<Point> points = polyomino.AsPoints();
  for (Point& point : points) {
    std::swap(point.x, point.y);
    point.y = -point.y;
  }
  return Polyomino::BuildFromPoints(std::move(points));
}

void RotateAndInsertIntoSets(const std::vector<Point>& next_gen_points,
                             PolyominoesSet* next_gen_polyominoes,
                             PolyominoesSet* next_gen_rotations) {
  Polyomino p = Polyomino::BuildFromSortedPoints(next_gen_points);
  if (next_gen_polyominoes->contains(p) || next_gen_rotations->contains(p)) {
    return;
  }
  next_gen_polyominoes->insert(p);
  for (int i = 0; i < 3; ++i) {
    p = Rotate90(p);
    if (!next_gen_rotations->insert(p)) return;
  }
}

void GenerateNextTilePolyominoes(PolyominoesSet* polyominoes,
                                 PolyominoesSet* next_gen_polyominoes,
                                 PolyominoesSet* next_gen_rotations) {
  std::vector<std::vector<bool>> mask;
  next_gen_polyominoes->clear();
  next_gen_rotations->clear();

  polyominoes->forEach([&mask, next_gen_polyominoes,
                        next_gen_rotations](const Polyomino& polyomino) {
    const std::vector<Point> points = polyomino.AsPoints();
    const int N = points.size();

    // Set up the mask.
    if (mask.empty()) {
      mask.resize(N);
      for (int i = 0; i < N; ++i) {
        mask[i].resize(N, false);
      }
    } else {
      assert(mask.size() == N);
    }
    for (const Point& p : points) {
      mask[p.y][p.x] = true;
    }

    // 1. Try adding a new tile at {y == -1}.
    std::vector<Point> next_gen_points(N + 1);
    for (int i = 1; i <= N; ++i) {
      next_gen_points[i] = points[i - 1];
      next_gen_points[i].y++;
    }
    for (int x = 0; x < N; ++x) {
      if (!mask[0][x]) continue;
      // The new tile is at {x, y == 0}.
      next_gen_points[0] = {x, 0};
      RotateAndInsertIntoSets(next_gen_points, next_gen_polyominoes,
                              next_gen_rotations);
    }

    // 2. Try adding a new tile at {x == -1}.
    // NOTE: Reusing the setup of `next_gen_points` from the previous step!
    for (int i = 1; i <= N; ++i) {
      next_gen_points[i].x++;
      next_gen_points[i].y--;
    }
    for (int insert_index = 0, y = 0; y < N; ++y) {
      if (!mask[y][0]) continue;
      // The new tile is at {x == 0, y}.
      while (1) {
        assert(insert_index < N);
        const int ny = next_gen_points[insert_index + 1].y;
        if (ny >= y) break;
        next_gen_points[insert_index] = next_gen_points[insert_index + 1];
        ++insert_index;
      }
      next_gen_points[insert_index] = {0, y};
      RotateAndInsertIntoSets(next_gen_points, next_gen_polyominoes,
                              next_gen_rotations);
    }

    // 3. Try adding a new tile at {x >= 0 && y >= 0}.
    std::vector<Point> candidates;
    candidates.reserve(N * 2);
    for (const Point& p : points) {
      for (int i = 0; i < 4; ++i) {
        const int nx = p.x + kDirs[i][0];
        const int ny = p.y + kDirs[i][1];
        if (nx < 0 || ny < 0) continue;
        if (nx < N && ny < N && mask[ny][nx]) continue;
        candidates.push_back({nx, ny});
      }
    }
    Polyomino::SortPointsForPolyomino(&candidates);
    for (int i = 0; i < N; ++i) {
      next_gen_points[i + 1] = points[i];
    }
    for (int insert_index = 0, i = 0; i < candidates.size(); ++i) {
      if (i && candidates[i] == candidates[i - 1]) continue;
      const int x = candidates[i].x;
      const int y = candidates[i].y;
      while (insert_index < N) {
        const int nx = next_gen_points[insert_index + 1].x;
        const int ny = next_gen_points[insert_index + 1].y;
        if (ny > y || (ny == y && nx > x)) break;
        next_gen_points[insert_index] = next_gen_points[insert_index + 1];
        ++insert_index;
      }
      next_gen_points[insert_index] = candidates[i];
      RotateAndInsertIntoSets(next_gen_points, next_gen_polyominoes,
                              next_gen_rotations);
    }

    // Clean up the mask for a next use.
    for (const Point& p : points) {
      mask[p.y][p.x] = false;
    }
  });

  polyominoes->swap(*next_gen_polyominoes);
}

void GenerateAllPolyominoes(const int max_n,
                            std::vector<int>* polyominoes_count) {
  PolyominoesSet next_gen_polyominoes;
  PolyominoesSet next_gen_rotations;
  polyominoes_count->clear();
  polyominoes_count->push_back(0);  // Answer for N == 0.
  polyominoes_count->push_back(1);  // Answer for N == 1.

  PolyominoesSet polyominoes_set;
  polyominoes_set.insert(Polyomino::BuildFromPoints({{0, 0}}));
  for (int i = 2; i <= max_n; ++i) {
    GenerateNextTilePolyominoes(&polyominoes_set, &next_gen_polyominoes,
                                &next_gen_rotations);
    polyominoes_count->push_back(polyominoes_set.size());
#ifndef ONLINE_JUDGE
    std::fprintf(stderr, "N = %d: answer = %d (cache size: %d)\n", i,
                 polyominoes_count->at(i), next_gen_rotations.size());
    if (i < 5) {
      polyominoes_set.forEach([](const Polyomino& polyomino) {
        std::string str = polyomino.DebugString();
        std::fprintf(stderr, "    %s\n", str.c_str());
      });
    }
#endif
  }
}

int main() {
  std::vector<int> polyominoes_count;
#ifdef ONLINE_JUDGE
  polyominoes_count = {
      0,    1,    1,     2,      7,      18,      60,      196,      704,
      2500, 9189, 33896, 126759, 476270, 1802312, 6849777, 26152418, 100203194,
  };
#endif

  int N, max_n = -1;
  std::vector<int> input;
  while (std::scanf("%d", &N) == 1) {
    input.push_back(N);
    if (max_n < N) max_n = N;
  }
  if (max_n >= polyominoes_count.size()) {
    GenerateAllPolyominoes(max_n, &polyominoes_count);
  }
  for (const int N : input) {
    std::printf("%d\n", polyominoes_count[N]);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
