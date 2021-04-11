/* @JUDGE_ID: 19899RK 265 C++11 "By Anadan" */
// Dining Diplomats
// Accepted (0.010 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <string>
#include <unordered_map>
#include <vector>

struct Diplomat {
  void clear() {
    for (int i = 0; i < 10; ++i) common_langs[i] = friends[i] = 0;
  }
  char country[16];
  char langs[16];
  char common_langs[10];
  char friends[10];
};

char FindCommonChar(const char* p, const char* const p1) {
  for (; *p; ++p) {
    for (const char* q = p1; *q; ++q) {
      if (*p == *q) return *p;
    }
  }
  return 0;
}

bool IsConnected(const Diplomat* diplomats) {
  char mask[10] = {0};
  mask[0] = 1;
  int count_left = 9;
  std::vector<int> queue;
  queue.push_back(0);
  while (!queue.empty()) {
    const int index = queue.back();
    queue.pop_back();
    const Diplomat& d = diplomats[index];
    for (int i = 1; i < 10; ++i) {
      if (mask[i] || !d.friends[i]) continue;
      if (--count_left == 0) return true;
      mask[i] = 1;
      queue.push_back(i);
    }
  }
  return false;
}

bool FindSolution(const Diplomat* diplomats, int index, char* mask,
                  int* permutation) {
  if (index == 0) {
    if (!IsConnected(diplomats)) return false;
    mask[0] = 1;
    permutation[0] = 0;
    const Diplomat& d = diplomats[0];
    // Optimization: set up #1 and #9 diplomats right away.
    for (int i = 1; i < 10; ++i) {
      if (!d.friends[i]) continue;
      mask[i] = 1;
      permutation[1] = i;
      for (int j = i + 1; j < 10; ++j) {
        if (!d.friends[j]) continue;
        mask[j] = 1;
        permutation[9] = j;
        if (FindSolution(diplomats, 2, mask, permutation)) return true;
        mask[j] = 0;
      }
      mask[i] = 0;
    }
    return false;
  }
  for (int i = 1; i < 10; ++i) {
    if (mask[i]) continue;
    const Diplomat& d = diplomats[i];
    if (!d.friends[permutation[index - 1]]) continue;
    if (index == 8) {
      if (!d.friends[permutation[9]]) continue;
      permutation[index] = i;
      return true;
    }
    mask[i] = 1;
    permutation[index] = i;
    if (FindSolution(diplomats, index + 1, mask, permutation)) return true;
    mask[i] = 0;
  }
  return false;
}

int main() {
  int offset, permutation[16];
  char buffer[10][1024 * 3], country[16], mask[16];
  Diplomat diplomats[10];
  std::unordered_map<std::string, std::vector<int>> country_indexes;

  while (1) {
    country_indexes.clear();
    for (int i = 0; i < 10; ++i) {
      mask[i] = 0;
      permutation[i] = -1;
      Diplomat& d = diplomats[i];
      d.clear();
      if (std::scanf("%s%s", d.country, d.langs) != 2) return 0;
      country_indexes[std::string(d.country)].push_back(i);
      std::fgets(buffer[i], sizeof(buffer[i]), stdin);
    }

    for (int i = 0; i < 10; ++i) {
      Diplomat& d = diplomats[i];
      for (const char* p = buffer[i];
           std::sscanf(p, "%s%n", country, &offset) == 1; p += offset) {
        auto it = country_indexes.find(std::string(country));
        if (it == country_indexes.end()) continue;
        for (const int j : it->second) {
          assert(0 <= j && j < 10);
          d.friends[j] = 1;
        }
      }
      // Mark as friends from the same country.
      for (const int j : country_indexes[std::string(d.country)]) {
        assert(0 <= j && j < 10);
        d.friends[j] = 1;
      }
    }

    for (int i = 0; i < 10; ++i) {
      for (int j = i + 1; j < 10; ++j) {
        const char ch = FindCommonChar(diplomats[i].langs, diplomats[j].langs);
        diplomats[i].common_langs[j] = diplomats[j].common_langs[i] = ch;
        // Also unmark non-mutual friendships.
        if (ch == 0 || !diplomats[i].friends[j] || !diplomats[j].friends[i]) {
          diplomats[i].friends[j] = diplomats[j].friends[i] = 0;
        }
      }
    }

    if (FindSolution(diplomats, 0, mask, permutation)) {
      for (int i = 0; i < 10; ++i) {
        const int index = permutation[i];
        assert(0 <= index && index < 10);
        const int next = permutation[i < 9 ? i + 1 : 0];
        assert(0 <= next && next < 10);
        const int prev = permutation[i > 0 ? i - 1 : 9];
        assert(0 <= prev && prev < 10);
        const Diplomat& d = diplomats[index];
        std::printf("%d %c %s %c\n", i + 1, d.common_langs[prev], d.country,
                    d.common_langs[next]);
      }
    } else {
      std::puts("NO SOLUTION EXISTS");
    }
    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
