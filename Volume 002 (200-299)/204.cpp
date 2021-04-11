/* @JUDGE_ID: 19899RK 204 C++11 "By Anadan" */
// Robot Crash
// Accepted (0.020 seconds with low memory spent)
// Accepted (0.030 seconds with low memory spent) without fastio

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cwctype>
#include <limits>
#include <vector>

constexpr double kPiOver180 = std::acos(-1) / 180.0;
constexpr double kEps = 1e-7;
constexpr bool feq_zero(double x) { return -kEps <= x && x <= kEps; }
constexpr bool fge_zero(double x) { return -kEps <= x; }
constexpr bool fle_zero(double x) { return x <= kEps; }
constexpr bool fbetween(double l, double r, double value) {
  return (l < r) ? (l <= value + kEps && value <= r + kEps)
                 : (r <= value + kEps && value <= l + kEps);
}

struct Point {
  double x, y;

  constexpr bool operator<(const Point& pt) const {
    return feq_zero(x - pt.x) ? (y < pt.y) : (x < pt.x);
  }
};

struct Vector2 {
  double x, y;
};

struct Interval {
  Point p1, p2;
};

struct Line {
  double A, B, C;  // A*x + B*y + C = 0

  Line(const Point& p1, const Point& p2) {
    A = p1.y - p2.y;
    B = p2.x - p1.x;
    C = -A * p1.x - B * p1.y;
    // const double norm = (A > 0) ? std::hypot(A, B) : -std::hypot(A, B);
    // A /= norm;
    // B /= norm;
    // C /= norm;
  }

  constexpr bool contains(const Point& pt) const {
    return feq_zero(A * pt.x + B * pt.y + C);
  }
};

bool IntersectIntervals1d(double min1, double max1, double min2, double max2) {
  if (min1 > max1) std::swap(min1, max1);
  if (min2 > max2) std::swap(min2, max2);
  return fle_zero(std::max(min1, min2) - std::min(max1, max2));
}

bool IntersectIntervals(const Interval& i1, const Interval& i2, Interval* res) {
  if (!IntersectIntervals1d(i1.p1.x, i1.p2.x, i2.p1.x, i2.p2.x) ||
      !IntersectIntervals1d(i1.p1.y, i1.p2.y, i2.p1.y, i2.p2.y)) {
    return false;
  }
  const Line l1{i1.p1, i1.p2};
  const Line l2{i2.p1, i2.p2};
  const double norm = l1.A * l2.B - l2.A * l1.B;
  if (feq_zero(norm)) {
    // Parallel or equal lines or empty interval(s).
    if (!l1.contains(i2.p1) || !l2.contains(i1.p1)) return false;
    const Point* p1 = &i1.p1;
    const Point* p2 = &i1.p2;
    if (*p2 < *p1) std::swap(p1, p2);
    const Point* q1 = &i2.p1;
    const Point* q2 = &i2.p2;
    if (*q2 < *q1) std::swap(q1, q2);
    res->p1 = std::max(*p1, *q1);
    res->p2 = std::min(*p2, *q2);
    assert(!(res->p2 < res->p1));
    return true;
  }
  const double x = (l2.C * l1.B - l1.C * l2.B) / norm;
  const double y = (l2.A * l1.C - l1.A * l2.C) / norm;
  res->p1 = res->p2 = Point{x, y};
  return fbetween(i1.p1.x, i1.p2.x, x) && fbetween(i1.p1.y, i1.p2.y, y) &&
         fbetween(i2.p1.x, i2.p2.x, x) && fbetween(i2.p1.y, i2.p2.y, y);
}

void ClampToStrip(Point& pt, Vector2& vec) {
  if (pt.y > 10) {
    const double count20 = std::floor(pt.y * 0.05 + kEps);
    pt.y -= count20 * 20;
    if (pt.y > 10) {
      pt.y = 20 - pt.y;
      vec.y = -vec.y;
      assert(vec.y < 0);
    }
  } else if (pt.y < 0) {
    const double count20 = std::floor(-pt.y * 0.05 + kEps);
    pt.y += count20 * 20;
    if (pt.y < -10) {
      pt.y += 20;
    } else {
      assert(pt.y < 0);
      pt.y = -pt.y;
      vec.y = -vec.y;
      assert(vec.y > 0);
    }
  }
  assert(0 <= pt.y && pt.y <= 10);
}

std::vector<Interval> BuildIntervals(Point pt, Vector2 vec, const double t_min,
                                     const double t_max) {
  std::vector<Interval> intervals;
  pt.x += vec.x * t_min;
  pt.y += vec.y * t_min;
  ClampToStrip(pt, vec);
  double t = t_min;
  while (1) {
    double next_t = t_max;
    if (!feq_zero(vec.y)) {
      if (vec.y > 0) {
        next_t = t + (10 - pt.y) / vec.y;
      } else {
        next_t = t - pt.y / vec.y;
      }
      if (next_t > t_max) next_t = t_max;
    }
    Point next_pt{pt.x + vec.x * (next_t - t), pt.y + vec.y * (next_t - t)};
    intervals.push_back(Interval{pt, next_pt});
    pt = next_pt;
    t = next_t;
    vec.y = -vec.y;
    if (fge_zero(t - t_max)) break;
  }
  return intervals;
}

// Left robot is allowed to be "anywhere" on its path within the 0.5 sec
// interval from the first possible meeting point, while the right robot is
// just a point colliding with the left robot's trek.
bool CollideLeftSideCase(const Point& p1, const Vector2& v1, const Point& p2,
                         const Vector2& v2, const bool is_flipped,
                         double* collision_time, Point* result) {
  const double distance = p2.x - p1.x;
  if (feq_zero(distance)) {
    if (feq_zero(p2.y - p1.y) && !is_flipped) {
      *collision_time = 0;
      *result = p1;
      return true;
    }
    return false;
  }
  if (distance < 0) return false;
  assert(v1.x > 0);
  assert(v2.x < 0);

  const double t_meet = distance / (v1.x - v2.x);  // First possible meeting.
  double t_right_max = t_meet + v1.x / (v1.x - v2.x) * 0.5;
  if (t_right_max > *collision_time) {
    t_right_max = *collision_time;
    if (!fge_zero(t_right_max - t_meet)) return false;
  }
  const double t_left_min = std::max(0.0, t_meet + v2.x / (v1.x - v2.x) * 0.5);

  std::vector<Interval> rights = BuildIntervals(p2, v2, t_meet, t_right_max);
  std::vector<Interval> lefts = BuildIntervals(p1, v1, t_left_min, t_meet);
  std::reverse(lefts.begin(), lefts.end());

  Interval res;
  bool has_intersection = false;
  for (const Interval& i2 : rights) {
    for (const Interval& i1 : lefts) {
      if (IntersectIntervals(i1, i2, &res)) {
        has_intersection = true;
        break;
      }
    }
    if (has_intersection) break;
  }
  if (!has_intersection) return false;

  const double t = (res.p2.x - p2.x) / v2.x;
  assert(t > 0);
  assert(t <= *collision_time);
  const double x = is_flipped ? (p1.x + p2.x - res.p2.x) : res.p2.x;
  assert(t_meet <= t + kEps && t <= t_right_max + kEps);
  if (feq_zero(*collision_time - t)) {
    if (x < result->x) {
      result->x = x;
      result->y = res.p2.y;
    }
  } else {
    assert(*collision_time > t);
    *collision_time = t;
    result->x = x;
    result->y = res.p2.y;
  }
  return true;
}

bool Collide(Point p1, Vector2 v1, Point p2, Vector2 v2, Point* result) {
  double collision_time = std::numeric_limits<double>::max();
  bool found =
      CollideLeftSideCase(p1, v1, p2, v2, false, &collision_time, result);

  // Swap left and right robots and solve again.
  using std::swap;
  swap(p1.y, p2.y);
  swap(v1, v2);
  v1.x = -v1.x;
  v2.x = -v2.x;
  found |= CollideLeftSideCase(p1, v1, p2, v2, true, &collision_time, result);

  return found;
}

namespace fastio {

bool ReadDouble(const char*& ptr, double* value) {
  static constexpr std::uint64_t kMaxIntValue =
      std::numeric_limits<std::uint64_t>::max() / 10;
  static constexpr double kNegativeExpTable[] = {
      1, 1e-1, 1e-2, 1e-3, 1e-4, 1e-5, 1e-6, 1e-7, 1e-8, 1e-9, 1e-10,
  };
  static constexpr double kPositiveExpTable[] = {
      1, 1e+1, 1e+2, 1e+3, 1e+4, 1e+5, 1e+6, 1e+7, 1e+8, 1e+9, 1e+10,
  };

  while (std::iswspace(*ptr)) ++ptr;

  bool negate = false;
  if (*ptr == '-') {
    negate = true;
    ++ptr;
  }

  std::uint64_t uint_value = 0;
  int exponent = 0;
  bool read_point = false;
  bool read_exponent = false;
  const char* const start = ptr;
  for (char ch;; ++ptr) {
    ch = *ptr ^ '0';
    if (ch <= 9) {
      if (uint_value < kMaxIntValue) {
        uint_value = uint_value * 10 + ch;
        if (read_point) --exponent;
      } else {
        if (!read_point) ++exponent;
      }
    } else if (*ptr == '.') {
      if (read_point) break;
      read_point = true;
    } else if ((*ptr | ('E' ^ 'e')) == 'e') {
      if (read_exponent) break;
      read_exponent = true;
      ++ptr;
      const bool negative_exponent = (*ptr == '-');
      if (*ptr == '+' || *ptr == '-') ++ptr;
      int exp_value = 0;
      for (char i; (i = *ptr ^ '0') <= 9; ++ptr) exp_value = exp_value * 10 + i;
      if (negative_exponent) {
        exponent -= exp_value;
      } else {
        exponent += exp_value;
      }
      break;
    } else {
      break;
    }
  }
  if (start == ptr) return false;

  *value = uint_value;
  for (; exponent >= 100; exponent -= 100) *value *= 1e100;
  for (; exponent >= 10; exponent -= 10) *value *= 1e10;
  for (; exponent <= -100; exponent += 100) *value *= 1e-100;
  for (; exponent <= -10; exponent += 10) *value *= 1e-10;
  if (exponent > 0) *value *= kPositiveExpTable[exponent];
  if (exponent < 0) *value *= kNegativeExpTable[-exponent];
  if (negate) *value = -*value;
  return true;
}

}  // namespace fastio

int main() {
  using fastio::ReadDouble;
  char buffer[1024 * 4];
  int testcase = 0;
  double a1, a2, v1, v2;
  Point p1, p2, result;
  // while (std::scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &p1.x, &p1.y, &a1, &v1,
  //                   &p2.x, &p2.y, &a2, &v2) == 8) {
  while (std::fgets(buffer, sizeof(buffer), stdin)) {
    const char* p = buffer;
    if (!ReadDouble(p, &p1.x)) break;
    if (!ReadDouble(p, &p1.y)) break;
    if (!ReadDouble(p, &a1)) break;
    if (!ReadDouble(p, &v1)) break;
    std::fgets(buffer, sizeof(buffer), stdin);
    p = buffer;
    if (!ReadDouble(p, &p2.x)) break;
    if (!ReadDouble(p, &p2.y)) break;
    if (!ReadDouble(p, &a2)) break;
    if (!ReadDouble(p, &v2)) break;
    a1 *= kPiOver180;
    a2 *= kPiOver180;
    if (Collide(p1, {v1 * std::cos(a1), v1 * std::sin(a1)}, p2,
                {v2 * std::cos(a2), v2 * std::sin(a2)}, &result)) {
      std::printf("Robot Problem #%d: Robots collide at (%.2lf,%.2lf)\n\n",
                  ++testcase, result.x + kEps, result.y + kEps);
    } else {
      std::printf("Robot Problem #%d: Robots do not collide.\n\n", ++testcase);
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
