/* @JUDGE_ID: 19899RK 370 C++11 "By Anadan" */
// Bingo
// Accepted (0.010 seconds with low memory spent)
// Accepted (0.040 seconds with low memory spent) without fastio

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <vector>

struct Bingo {
  //  0  1  2  3  4
  //  5  6  7  8  9
  // 10 11 12 13 14
  // 15 16 17 18 19
  // 20 21 22 23 24
  int numbers[25];
  bool has_bingo_;
  int gen_ = 0;
  int present_[100] = {0};
  std::vector<int> indexes_[100];

  // 5 in a rows
  // 5 in a column
  // 1 in corners
  // 1 in diagonal 0,6,12,18,24
  // 1 in diagonal 4,8,12,16,20
  int bingo_counters_[13];

  void Init() {
    has_bingo_ = false;
    ++gen_;

    for (int i = 0; i < 13; ++i) bingo_counters_[i] = 5;
    bingo_counters_[10] = 4;

    for (int i = 0; i < 25; ++i) {
      const int x = numbers[i];
      if (present_[x] != gen_) {
        present_[x] = gen_;
        indexes_[x].clear();
      }
      indexes_[x].push_back(i);
    }
    Call(0);
  }

  void Call(const int x) {
    assert(0 <= x && x < 100);
    if (has_bingo_ || present_[x] != gen_) return;
    present_[x] = 0;
    for (const int index : indexes_[x]) {
      const int row = index / 5;
      const int col = index % 5;
      if (--bingo_counters_[row] == 0) has_bingo_ = true;
      if (--bingo_counters_[5 + col] == 0) has_bingo_ = true;
      if (index == 0 || index == 4 || index == 20 || index == 24) {
        if (--bingo_counters_[10] == 0) has_bingo_ = true;
      }
      if (row == col) {
        if (--bingo_counters_[11] == 0) has_bingo_ = true;
      }
      if (row + col == 4) {
        if (--bingo_counters_[12] == 0) has_bingo_ = true;
      }
    }
  }

  void PrintBingo() {
    if (!has_bingo_) {
      std::puts("No BINGO on this card.");
      return;
    }
    int indexes[5];
    for (int i = 0; i < 13; ++i) {
      if (bingo_counters_[i] != 0) continue;
      const int kind = (i < 5) ? 1 : ((i < 10) ? 2 : (i == 10 ? 3 : 4));
      std::printf("BINGO #%d\n", kind);
      if (kind == 1) {
        for (int k = 0; k < 5; ++k) indexes[k] = 5 * i + k;
      } else if (kind == 2) {
        for (int k = 0; k < 5; ++k) indexes[k] = i - 5 + k * 5;
      } else if (kind == 3) {
        indexes[0] = 0;
        indexes[1] = 4;
        indexes[2] = 20;
        indexes[3] = 24;
        indexes[4] = -1;
      } else if (i == 11) {
        indexes[0] = 0;
        indexes[1] = 6;
        indexes[2] = 12;
        indexes[3] = 18;
        indexes[4] = 24;
      } else {
        indexes[0] = 4;
        indexes[1] = 8;
        indexes[2] = 12;
        indexes[3] = 16;
        indexes[4] = 20;
      }
      for (int k = 0; k < 5; ++k) {
        if (indexes[k] == -1) continue;
        const int x = numbers[indexes[k]];
        const int row = indexes[k] / 5;
        const int col = indexes[k] % 5;
        if (x == 0) {
          std::printf("%d,%d,FREE\n", row + 1, col + 1);
        } else {
          std::printf("%d,%d,%d\n", row + 1, col + 1, x);
        }
      }
    }
  }
};

namespace fastio {

bool ReadInt(int* x) {
  while (1) {
    *x = std::getchar();
    if (*x == EOF) return false;
    *x ^= '0';
    if (*x <= 9) break;
  }
  for (char ch; (ch = std::getchar() ^ '0') <= 9;) *x = (*x) * 10 + ch;
  return true;
}

}  // namespace fastio

int main() {
  using fastio::ReadInt;
  int x;
  Bingo bingo;
  while (1) {
    for (int i = 0; i < 25; ++i) {
      if (!ReadInt(bingo.numbers + i)) return 0;
      // if (std::scanf("%d", bingo.numbers + i) != 1) return 0;
    }
    bingo.Init();
    while (ReadInt(&x) && x) bingo.Call(x);
    // while (std::scanf("%d", &x) == 1 && x) bingo.Call(x);
    bingo.PrintBingo();
    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
