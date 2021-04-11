/* @JUDGE_ID: 19899RK 239 C++ "By Anadan" */
// Tempus et mobilius. Time and motion
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <cstdio>
#include <deque>

int64_t gcd(int64_t x, int64_t y) {
  while (x && y) {
    x %= y;
    std::swap(x, y);
  }
  return x + y;
}

int64_t lcm(int64_t x, int64_t y) { return (x / gcd(x, y)) * y; }

int64_t solve(const int N) {
  int five_minutes[12], hours[12];
  std::deque<int> balls(N);
  for (int i = 0; i < N; ++i) balls[i] = i;

  for (int j = 0; j < 12; ++j) {
    for (int i = 0; i < 12; ++i) {
      for (int k = 0; k < 4; ++k) {
        assert(!balls.empty());
        const int x = balls.front();
        balls.pop_front();
        balls.push_back(x);
      }
      assert(balls.size() >= 4);
      std::reverse(balls.end() - 4, balls.end());
      five_minutes[i] = balls.front();
      balls.pop_front();
    }
    hours[j] = five_minutes[11];
    for (int i = 10; i >= 0; --i) {
      balls.push_back(five_minutes[i]);
    }
  }
  for (int j = 10; j >= 0; --j) {
    balls.push_back(hours[j]);
  }
  balls.push_back(hours[11]);
  assert(balls.size() == N);

  // Find cycles.
  int64_t result = 1;
  for (int i = 0; i < N; ++i) {
    if (balls[i] == -1) continue;
    int cycle = 0;
    for (int j = i; balls[j] != -1;) {
      ++cycle;
      const int x = balls[j];
      balls[j] = -1;
      j = x;
    }
    result = lcm(result, cycle);
  }
  return result / 2;
}

int main() {
  int N;
  while (std::scanf("%d", &N) == 1 && N) {
    std::printf("%d balls cycle after %lld days.\n", N, solve(N));
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
