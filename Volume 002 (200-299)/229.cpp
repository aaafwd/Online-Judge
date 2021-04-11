/* @JUDGE_ID: 19899RK 229 C++ "By Anadan" */
// Scanner
// Accepted (0.060 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <iterator>
#include <set>
#include <vector>

class Point {
 public:
  Point(int x, int y) : payload((y << 4) | x) {}
  int x() const { return payload & 0x0F; }
  int y() const { return (payload >> 4); }

  bool operator<(const Point& other) const { return payload < other.payload; }

 private:
  int payload;
};

class Sensor {
 public:
  class Comparator {
   public:
    bool operator()(const Sensor* s1, const Sensor* s2) const {
      int diff = s1->GetKey() - s2->GetKey();
      if (diff != 0) return diff < 0;
      return s1 < s2;
    }
  };

  void Reset(int v) {
    value = v;
    if (!visited.empty()) {
      points.insert(std::make_move_iterator(visited.begin()),
                    std::make_move_iterator(visited.end()));
      visited.clear();
    }
  }

  int GetKey() const {
    return std::min(value, static_cast<int>(points.size()) - value);
  }

  int value;
  std::set<Point> points;
  std::vector<Point> visited;
};

typedef std::set<Sensor*, Sensor::Comparator> SensorsQueue;

// 10 + 24 + 15 + 24 == 73
std::array<Sensor, 73> sensors;
char map[10][16], solution[10][16];
bool found_solution;

void Init() {
  for (int y = 0; y < 10; ++y) {
    for (int x = 0; x < 15; ++x) {
      const int indexes[4] = {y, 10 + x + y, 34 + x, 58 - y + x};
      for (int k = 0; k < 4; ++k) {
        assert(0 <= indexes[k] && indexes[k] < sensors.size());
        sensors[indexes[k]].points.insert(Point(x, y));
      }
    }
  }
  for (int i = 0; i < sensors.size(); ++i) {
    sensors[i].visited.reserve(sensors[i].points.size());
  }
}

bool VisitSensorPoints(Sensor* sensor, SensorsQueue* sensors_queue,
                       const std::set<Point>& points, const bool mark,
                       const bool unvisit) {
  if (points.empty()) return true;
  if (!unvisit) {
    for (std::set<Point>::iterator it = points.begin(); it != points.end();
         ++it) {
      const Point& pt = *it;
      const int indexes[4] = {pt.y(), 10 + pt.x() + pt.y(), 34 + pt.x(),
                              58 - pt.y() + pt.x()};
      for (int k = 0; k < 4; ++k) {
        const Sensor* s = &sensors[indexes[k]];
        if (sensor == s) continue;
        if (mark) {
          if (s->value == 0) return false;
        } else {
          if (s->value + 1 > s->points.size()) return false;
        }
      }
    }
  }
  for (std::set<Point>::iterator it = points.begin(); it != points.end();
       ++it) {
    const Point& pt = *it;
    const int indexes[4] = {pt.y(), 10 + pt.x() + pt.y(), 34 + pt.x(),
                            58 - pt.y() + pt.x()};
    for (int k = 0; k < 4; ++k) {
      assert(0 <= indexes[k] && indexes[k] < sensors.size());
      Sensor* s = &sensors[indexes[k]];
      if (sensor == s) continue;
      sensors_queue->erase(s);
    }
  }
  for (std::set<Point>::iterator it = points.begin(); it != points.end();
       ++it) {
    const Point& pt = *it;
    const int indexes[4] = {pt.y(), 10 + pt.x() + pt.y(), 34 + pt.x(),
                            58 - pt.y() + pt.x()};
    for (int k = 0; k < 4; ++k) {
      assert(0 <= indexes[k] && indexes[k] < sensors.size());
      Sensor* s = &sensors[indexes[k]];
      if (sensor == s) continue;
      if (unvisit) {
        s->points.insert(pt);
        s->visited.pop_back();
        if (mark) ++s->value;
      } else {
        s->points.erase(pt);
        s->visited.push_back(pt);
        assert(0 <= pt.y() && pt.y() < 10);
        assert(0 <= pt.x() && pt.x() < 15);
        if (mark) {
          --s->value;
          map[pt.y()][pt.x()] = '#';
        } else {
          map[pt.y()][pt.x()] = '.';
        }
      }
    }
  }
  for (std::set<Point>::iterator it = points.begin(); it != points.end();
       ++it) {
    const Point& pt = *it;
    const int indexes[4] = {pt.y(), 10 + pt.x() + pt.y(), 34 + pt.x(),
                            58 - pt.y() + pt.x()};
    for (int k = 0; k < 4; ++k) {
      assert(0 <= indexes[k] && indexes[k] < sensors.size());
      Sensor* s = &sensors[indexes[k]];
      if (sensor == s) continue;
      if (!s->points.empty()) sensors_queue->insert(s);
    }
  }
  return true;
}

bool Generate(SensorsQueue* sensors_queue) {
  if (sensors_queue->empty()) {
    if (found_solution) return false;
    for (int y = 0; y < 10; ++y) {
      for (int x = 0; x < 15; ++x) solution[y][x] = map[y][x];
    }
    found_solution = true;
    return true;
  }
  Sensor* sensor = *sensors_queue->begin();
  const int key = sensor->GetKey();
  if (key < 0) return true;

  sensors_queue->erase(sensors_queue->begin());
  if (key == 0) {
    const bool mark = (sensor->value > 0);
    if (VisitSensorPoints(sensor, sensors_queue, sensor->points, mark, false)) {
      if (!Generate(sensors_queue)) return false;
      VisitSensorPoints(sensor, sensors_queue, sensor->points, mark, true);
    }
  } else {
    const Point pt = *sensor->points.begin();
    std::set<Point> one;
    one.insert(pt);
    sensor->points.erase(sensor->points.begin());
    sensor->visited.push_back(pt);
    for (int mark = 0; mark < 2; ++mark) {
      if (VisitSensorPoints(sensor, sensors_queue, one, mark, false)) {
        sensors_queue->insert(sensor);
        if (!Generate(sensors_queue)) return false;
        sensors_queue->erase(sensor);
        VisitSensorPoints(sensor, sensors_queue, one, mark, true);
      }
    }
    sensor->visited.pop_back();
    sensor->points.insert(pt);
  }
  sensors_queue->insert(sensor);
  return true;
}

void MakeEmptyMap() {
  for (int y = 0; y < 10; ++y) {
    for (int x = 0; x < 15; ++x) solution[y][x] = map[y][x] = '.';
    solution[y][15] = map[y][15] = 0;
  }
}

int main() {
  int test_cases, x;
  std::scanf("%d", &test_cases);
  Init();
  while (test_cases--) {
    for (int i = 0; i < sensors.size(); ++i) {
      std::scanf("%d", &x);
      sensors[i].Reset(x);
    }
    SensorsQueue sensors_queue;
    for (int i = 0; i < sensors.size(); ++i) {
      sensors_queue.insert(&sensors[i]);
    }

    MakeEmptyMap();
    found_solution = false;
    if (!Generate(&sensors_queue) || !found_solution) MakeEmptyMap();
    for (int i = 0; i < 10; ++i) std::puts(solution[i]);
    if (test_cases) std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
