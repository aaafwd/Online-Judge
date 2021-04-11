/* @JUDGE_ID: 19899RK 244 C++ "By Anadan" */
// Train Time
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

constexpr double eps = 1e-7;
constexpr int kFeetsInMile = 5280;

double max_speed, acceleration, station_delay;
std::vector<double> distances, out_times, moving_times;

constexpr bool eq(double a, double b) {
  return (a > b) ? (a - b < eps) : (b - a < eps);
}

void solve() {
  const int size = distances.size();
  for (int i = size - 1; i > 0; --i) {
    distances[i] -= distances[i - 1];
  }
  bool in_miles;
  if (max_speed > 100 && acceleration > 100) {
    in_miles = true;
    max_speed /= kFeetsInMile;
    acceleration /= kFeetsInMile;
  } else {
    in_miles = false;
    for (int i = 1; i < size; ++i) {
      distances[i] *= kFeetsInMile;
    }
  }

  // 0 -> max_speed: t1 = max_speed/acceleration; s = acceleration*t1^2/2
  // max_speed -> 0: <same>
  // middle: t2 = (S - acceleration*t1^2)/max_speed = S/max_speed - t1
  // moving_time = t1 + t2 + t1 = t1 + S/max_speed
  const double acceleration_time = max_speed / acceleration;
  moving_times.resize(size);
  moving_times[0] = 0;
  for (int i = 1; i < size; ++i) {
    const double t2 = distances[i] / max_speed;
    assert(t2 >= acceleration_time);
    moving_times[i] = acceleration_time + t2;
  }

  out_times.resize(size);
  out_times[0] = 0;
  for (int i = 1; i < size; ++i) {
    out_times[i] = out_times[i - 1] + moving_times[i] + station_delay;
  }

  double back_train_time = 0;
  int right = size - 1;
  for (; right > 0; --right) {
    // In-time at pos @(right - 1).
    const double in_time_right = back_train_time + moving_times[right];
    if (out_times[right - 1] < in_time_right) break;
    const double in_time_left = out_times[right - 1] - station_delay;
    const double out_time_right = in_time_right + station_delay;
    if (out_time_right < in_time_left) {
      back_train_time = out_time_right;
      continue;
    }

    // Meeting at pos @(right - 1).
    const double meeting_time = std::max(in_time_right, in_time_left);
    double distance = 0;
    for (int i = 1; i < right; ++i) {
      distance += distances[i];
    }
    if (!in_miles) distance /= kFeetsInMile;
    std::printf(
        "   Meeting time: %.1lf minutes\n   Meeting distance: %.3lf miles from "
        "metro center hub, in station %d\n",
        meeting_time, distance, right - 1);
    return;
  }

  const int left = right - 1;
  double distance = 0;
  for (int i = 1; i < right; ++i) {
    distance += distances[i];
  }
  double time_diff = out_times[left] - back_train_time;
  double meeting_time = out_times[left];
  bool count_reverse = false;
  if (time_diff < 0) {
    time_diff = -time_diff;
    meeting_time = back_train_time;
    count_reverse = true;
  }
  time_diff = moving_times[right] - time_diff;

  time_diff *= 0.5;
  meeting_time += time_diff;
  double distance_diff = 0;
  if (time_diff <= acceleration_time) {
    distance_diff = acceleration * time_diff * time_diff * 0.5;
  } else {
    time_diff -= acceleration_time;
    distance_diff = max_speed * (acceleration_time * 0.5 + time_diff);
  }
  if (count_reverse) {
    distance += distances[right] - distance_diff;
  } else {
    distance += distance_diff;
  }
  if (!in_miles) distance /= kFeetsInMile;
  std::printf(
      "   Meeting time: %.1lf minutes\n   Meeting distance: %.3lf miles from "
      "metro center hub\n",
      meeting_time, distance);
}

int main() {
  int test_case = 0;
  double x;
  distances.reserve(32);
  out_times.reserve(32);
  moving_times.reserve(32);
  while (1) {
    distances.clear();
    while (std::scanf("%lf", &x) == 1 && x) {
      if (distances.empty()) {
        if (eq(x, -1.0)) break;
        distances.push_back(0.0);
      }
      distances.push_back(x);
    }
    if (distances.empty()) break;
    std::scanf("%lf%lf%lf", &max_speed, &acceleration, &station_delay);

    if (test_case++) std::putchar('\n');
    std::printf("Scenario #%d:\n", test_case);
    solve();
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

