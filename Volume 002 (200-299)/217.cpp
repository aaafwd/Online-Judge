/* @JUDGE_ID: 19899RK 217 C++11 "By Anadan" */
// Radio Direction Finder
// Accepted (0.020 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cmath>
#include <cstdio>
#include <unordered_map>
#include <string>

constexpr double kPiOver180 = std::acos(-1) / 180.0;
constexpr double kEps = 1e-10;
constexpr bool feq_zero(double x) { return -kEps <= x && x <= kEps; }

struct Point {
  double x, y;
};

struct Vector2 {
  double x, y;
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
};

constexpr Point operator+(const Point& pt, const Vector2& vec) {
  return Point{pt.x + vec.x, pt.y + vec.y};
}

bool IntersectLines(const Line& l1, const Line& l2, Point* res) {
  const double norm = l1.A * l2.B - l2.A * l1.B;
  if (feq_zero(norm)) return false;
  res->x = (l2.C * l1.B - l1.C * l2.B) / norm;
  res->y = (l2.A * l1.C - l1.A * l2.C) / norm;
  return true;
}

int main() {
  int testcase = 0, size, boats, time1, time2;
  std::unordered_map<std::string, Point> beacons;
  char name1[32], name2[32];
  Point pt;
  double course, speed, angle1, angle2;
  beacons.reserve(32);

  while (std::scanf("%d", &size) == 1) {
    beacons.clear();
    for (int i = 0; i < size; ++i) {
      std::scanf("%s%lf%lf", name1, &pt.x, &pt.y);
      beacons[std::string(name1)] = pt;
    }
    std::scanf("%d", &boats);
    for (int i = 0; i < boats; ++i) {
      std::scanf("%lf%lf%d%s%lf%d%s%lf", &course, &speed, &time1, name1,
                 &angle1, &time2, name2, &angle2);
      course *= kPiOver180;
      angle1 *= kPiOver180;
      angle2 *= kPiOver180;
      assert(beacons.find(std::string(name1)) != beacons.end());
      assert(beacons.find(std::string(name2)) != beacons.end());
      const Point& p1 = beacons[std::string(name1)];
      const Point& p2 = beacons[std::string(name2)];
      const Vector2 bearing1{std::sin(course + angle1),
                             std::cos(course + angle1)};
      const Vector2 bearing2{std::sin(course + angle2),
                             std::cos(course + angle2)};

      const double distance = speed * (time2 - time1);
      const Vector2 movement{distance * std::sin(course),
                             distance * std::cos(course)};

      const Line line1{p1 + movement, p1 + bearing1 + movement};
      const Line line2{p2, p2 + bearing2};
      if (IntersectLines(line1, line2, &pt)) {
        std::printf("Scenario %d: Position is (%.2lf, %.2lf)\n", ++testcase,
                    pt.x + kEps, pt.y + kEps);
      } else {
        std::printf("Scenario %d: Position cannot be determined\n", ++testcase);
      }
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
