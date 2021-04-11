/* @JUDGE_ID: 19899RK 266 C++11 "By Anadan" */
// Stamping Out Stamps
// Accepted (0.010 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

constexpr int kMaxStamps = 10;
constexpr int kMaxAmount = 1024 * 3;
int used_stamps[kMaxStamps + 1][kMaxAmount];
int used_lower_bound[kMaxStamps + 1][kMaxAmount];
std::vector<int> used_stamps_queue[kMaxStamps + 1];

void solve(const int max_amount, const std::vector<int>& stamps) {
  for (int k = 1; k <= kMaxStamps; ++k) {
    used_stamps_queue[k].clear();
    std::fill(std::begin(used_stamps[k]), std::end(used_stamps[k]), 0);
  }
  used_stamps_queue[0] = {0};
  for (int i = 0; i < stamps.size(); ++i) {
    for (int k = 0; k < kMaxStamps; ++k) {
      for (int x : used_stamps_queue[k]) {
        if (x >= max_amount) continue;
        const int amount = x + stamps[i];
        if (amount >= kMaxAmount) continue;
        if (k + 1 < kMaxStamps && used_stamps[k + 1][amount] == 0) {
          used_stamps_queue[k + 1].push_back(amount);
        }
        used_stamps[k + 1][amount] = stamps[i];
      }
    }
  }
  for (int k = 1; k <= kMaxStamps; ++k) {
    used_lower_bound[k][kMaxAmount - 1] = 0;
    for (int i = kMaxAmount - 2; i >= 0; --i) {
      if (used_stamps[k][i]) {
        used_lower_bound[k][i] = i;
      } else {
        used_lower_bound[k][i] = used_lower_bound[k][i + 1];
      }
    }
  }
}

void FindAndPrintPath(const int amount) {
  int best = -1, num_stamps;
  for (int k = 1; k <= kMaxStamps; ++k) {
    const int current = used_lower_bound[k][amount];
    if (!current) continue;
    if (best == -1 || best > current) {
      best = current;
      num_stamps = k;
      if (best == amount) break;
    }
  }
  assert(best >= amount);
  std::vector<int> answer;
  answer.reserve(num_stamps);
  for (int i = num_stamps; i > 0; --i) {
    assert(used_stamps[i][best] != 0);
    const int x = used_stamps[i][best];
    answer.push_back(x);
    best -= x;
    assert(best >= 0);
  }
  std::printf("STAMPS USED");
  for (int i = 0; i < answer.size(); ++i) {
    std::printf(" %d", answer[i]);
  }
  std::putchar('\n');
}

int main() {
  int N, x, max_amount;
  std::vector<int> stamps, amounts;
  stamps.reserve(16);
  amounts.reserve(1024);
  while (std::scanf("%d", &N) == 1 && N) {
    stamps.clear();
    for (int i = 0; i < N; ++i) {
      std::scanf("%d", &x);
      stamps.push_back(x);
    }
    std::sort(stamps.begin(), stamps.end());
    std::printf("STAMP VALUES");
    for (int i = 0; i < N; ++i) {
      std::printf(" %d", stamps[i]);
    }
    std::putchar('\n');
    std::putchar('\n');

    max_amount = 0;
    amounts.clear();
    while (std::scanf("%d", &x) == 1 && x) {
      amounts.push_back(x);
      if (x > stamps.back() * 10) continue;
      if (max_amount < x) max_amount = x;
    }
    solve(max_amount, stamps);

    for (int i = 0; i < amounts.size(); ++i) {
      x = amounts[i];
      std::printf("AMOUNT %d\n", x);
      if (x > stamps.back() * 10) {
        std::puts("NO SOLUTION EXISTS");
      } else {
        FindAndPrintPath(x);
      }
      std::putchar('\n');
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
