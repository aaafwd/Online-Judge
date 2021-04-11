/* @JUDGE_ID: 19899RK 203 C++11 "By Anadan" */
// Running Lights Visibility Calculator
// Accepted (0.010 seconds with low memory spent)
// Accepted (0.030 seconds with low memory spent) without fastio

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cmath>
#include <cstdio>
#include <cwctype>
#include <limits>
#include <string>
#include <vector>

constexpr double kPi = std::acos(-1);
constexpr double k2Pi = kPi * 2;
constexpr double kPiOver180 = kPi / 180.0;
constexpr double k180OverPi = 180.0 / kPi;

constexpr double kEps = 1e-7;
constexpr bool feq_zero(double x) { return -kEps <= x && x <= kEps; }
constexpr bool fge(double x, double y) { return x + kEps >= y; }
constexpr bool fgt(double x, double y) { return x > y + kEps; }
constexpr bool fle(double x, double y) { return x <= y + kEps; }
constexpr bool flt(double x, double y) { return x + kEps < y; }

struct Point {
  double x, y;
};

struct Ship {
  std::string name;
  Point p1, p2;
  double course, initial_bearing, initial_distance;
};

char* RemoveTrailingNewLine(char* ptr) {
  char* start = ptr;
  while (*ptr && *ptr != '\n') ++ptr;
  *ptr = 0;
  return start;
}

constexpr double GetDistance(const Point& p1, const Point& p2) {
  return std::sqrt((p2.x - p1.x) * (p2.x - p1.x) +
                   (p2.y - p1.y) * (p2.y - p1.y));
}

constexpr int FloatToRound100(const double x) {
  return static_cast<int>(std::floor(x * 100 + 0.5 + kEps));
}

void PrintLightsLn(const double bearing, const double distance) {
  if (fgt(distance, 10.0)) {
    std::puts("Lights not visible");
  } else if (feq_zero(bearing) || feq_zero(bearing - 360)) {
    std::puts("Green Masthead Red");
  } else if (flt(bearing, 2.5)) {
    std::puts("Masthead Green Red");
  } else if (fle(bearing, 110.0)) {
    std::puts("Masthead Green");
  } else if (flt(bearing, 115.0)) {
    std::puts("Stern Masthead Green");
  } else if (flt(bearing, 180.0)) {
    std::puts("Stern Masthead");
  } else if (fle(bearing, 245.0)) {
    std::puts("Masthead Stern");
  } else if (flt(bearing, 250.0)) {
    std::puts("Red Masthead Stern");
  } else if (fle(bearing, 357.5)) {
    std::puts("Red Masthead");
  } else {
    std::puts("Green Red Masthead");
  }
}

double GetBearingsDiff(double x, double y) {
  return x > y ? std::min(x - y, y + 360 - x) : std::min(y - x, x + 360 - y);
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
  int size;
  char buffer[1024];
  std::vector<Ship> ships;
  double speed;

  while (std::fgets(buffer, sizeof(buffer), stdin)) {
    if (buffer[0] == 0 || buffer[0] == '\n') break;
    std::printf("Scenario: %s\n", buffer);
    std::fgets(buffer, sizeof(buffer), stdin);
    std::sscanf(buffer, "%d", &size);
    ++size;
    ships.resize(size);
    for (int i = 0; i < size; ++i) {
      Ship& ship = ships[i];
      std::fgets(buffer, sizeof(buffer), stdin);
      ship.name = std::string(RemoveTrailingNewLine(buffer));
      std::fgets(buffer, sizeof(buffer), stdin);
      // std::sscanf(buffer, "%lf%lf%lf%lf", &ship.p1.x, &ship.p1.y,
      //             &ship.course, &speed);
      const char* ptr = buffer;
      ReadDouble(ptr, &ship.p1.x);
      ReadDouble(ptr, &ship.p1.y);
      ReadDouble(ptr, &ship.course);
      ReadDouble(ptr, &speed);
      ship.course *= kPiOver180;
      speed *= 0.05;
      ship.p2.x = ship.p1.x + speed * std::sin(ship.course);
      ship.p2.y = ship.p1.y + speed * std::cos(ship.course);
    }

    std::printf(
        "Boat ID         Bearing      Distance   Lights (left to right)\n"
        "---------------------------------------------------------------\n");
    const Ship& ship0 = ships[0];
    for (int i = 1; i < size; ++i) {
      Ship& ship = ships[i];

      double bearing =
          std::atan2(ship0.p1.x - ship.p1.x, ship0.p1.y - ship.p1.y);
      bearing -= ship.course;
      while (bearing < 0) bearing += k2Pi;
      bearing *= k180OverPi;
      ship.initial_bearing = bearing;

      int bearing100 = FloatToRound100(bearing);
      assert(bearing100 <= 36000);
      while (bearing100 >= 36000) bearing100 -= 36000;

      const double distance = GetDistance(ship0.p1, ship.p1);
      ship.initial_distance = distance;
      const int distance100 = FloatToRound100(distance);

      std::printf("%-16s%4d.%02d%9d.%02d     ", ship.name.c_str(),
                  bearing100 / 100, bearing100 % 100, distance100 / 100,
                  distance100 % 100);
      PrintLightsLn(bearing, distance);
    }
    for (int i = 1; i < size; ++i) {
      const Ship& ship = ships[i];
      if (fgt(ship.initial_distance, 10.0)) continue;

      const double distance = GetDistance(ship0.p2, ship.p2);
      if (!flt(distance, ship.initial_distance)) continue;

      double bearing =
          std::atan2(ship0.p2.x - ship.p2.x, ship0.p2.y - ship.p2.y);
      bearing -= ship.course;
      while (bearing < 0) bearing += k2Pi;
      bearing *= k180OverPi;
      if (!fle(GetBearingsDiff(bearing, ship.initial_bearing), 2.0)) continue;

      const int distance100 = FloatToRound100(distance);
      std::printf("** Collision warning -->%s:  Distance =  %d.%02d\n",
                  ship.name.c_str(), distance100 / 100, distance100 % 100);
    }
    std::puts(
        "***************************************************************");
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
