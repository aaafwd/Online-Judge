/* @JUDGE_ID: 19899RK 165 C++11 "By Anadan" */
// Stamps
// Accepted (0.120 seconds without precalculation)

#include <cstdio>
#include <vector>
#include <set>

struct State {
  // Attainable values using |i| stamps of the given denominations.
  std::vector<std::set<int>> values;
  // Largest attainable value in the continuous sequence from $0.
  int max_seq_attainable = 0;

  void AddDenomination(const int value, const int max_stamps) {
    if (values.empty()) {
      values.push_back({0});
    }
    for (int i = 0; i < max_stamps; ++i) {
      if (i + 1 >= values.size()) values.push_back({});
      for (const int prev : values[i]) {
        values[i + 1].insert(prev + value);
      }
    }
    std::set<int> all_values;
    for (int i = 0; i <= max_stamps; ++i) {
      all_values.insert(values[i].begin(), values[i].end());
    }
    while (all_values.count(max_seq_attainable + 1) == 1) {
      ++max_seq_attainable;
    }
  }
};

void generate(const int max_stamps, const int max_denoms, const State& state,
              std::vector<int>* current_denoms, int* best_max_seq,
              std::vector<int>* best_denoms) {
  if (current_denoms->size() == max_denoms) {
    if (state.max_seq_attainable > *best_max_seq) {
      *best_max_seq = state.max_seq_attainable;
      *best_denoms = *current_denoms;
    }
    return;
  }
  int denom = current_denoms->empty() ? 1 : current_denoms->back() + 1;
  while (denom <= state.max_seq_attainable + 1) {
    State new_state = state;
    new_state.AddDenomination(denom, max_stamps);
    current_denoms->push_back(denom);
    generate(max_stamps, max_denoms, new_state, current_denoms, best_max_seq,
             best_denoms);
    current_denoms->pop_back();
    ++denom;
  }
}

int main() {
  const char* precalculated[9][9] = {
    { "", "", "", "", "", "", "", "", ""},
    { "", "  1 ->  1", "  1  2 ->  2", "  1  2  3 ->  3", "  1  2  3  4 ->  4", "  1  2  3  4  5 ->  5", "  1  2  3  4  5  6 ->  6", "  1  2  3  4  5  6  7 ->  7", "  1  2  3  4  5  6  7  8 ->  8"},
    { "", "  1 ->  2", "  1  2 ->  4", "  1  3  4 ->  8", "  1  3  5  6 -> 12", "  1  3  5  7  8 -> 16", "  1  2  5  8  9 10 -> 20", "  1  2  5  8 11 12 13 -> 26", ""},
    { "", "  1 ->  3", "  1  3 ->  7", "  1  4  5 -> 15", "  1  4  7  8 -> 24", "  1  4  6 14 15 -> 36", "  1  3  7  9 19 24 -> 52", "", ""},
    { "", "  1 ->  4", "  1  3 -> 10", "  1  5  8 -> 26", "  1  3 11 18 -> 44", "  1  3 11 15 32 -> 70", "", "", ""},
    { "", "  1 ->  5", "  1  4 -> 14", "  1  6  7 -> 35", "  1  4 12 21 -> 71", "", "", "", ""},
    { "", "  1 ->  6", "  1  4 -> 18", "  1  7 12 -> 52", "", "", "", "", ""},
    { "", "  1 ->  7", "  1  5 -> 23", "", "", "", "", "", ""},
    { "", "  1 ->  8", "", "", "", "", "", "", ""}
  };

  int h, k;
  while (std::scanf("%d%d", &h, &k) == 2) {
    if (h == 0 && k == 0) break;
    if (h + k <= 9) {
      puts(precalculated[h][k]);
      continue;
    }

    std::vector<int> best_denoms;
    std::vector<int> current_denoms;
    int best_max_seq = -1;
    generate(h, k, State(), &current_denoms, &best_max_seq, &best_denoms);

    for (const int denom : best_denoms) {
      std::printf("%3d", denom);
    }
    std::printf(" ->%3d\n", best_max_seq);
  }
  return 0;
}

