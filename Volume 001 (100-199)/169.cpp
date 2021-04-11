/* @JUDGE_ID: 19899RK 169 C++11 "By Anadan" */
// Xenosemantics
// Accepted (0.000 seconds with low memory spent)

#include <algorithm>
#include <cstdio>
#include <map>
#include <string>
#include <vector>

struct Interval {
  int start, end;
  std::string sorted;
  bool repeats = false;
  bool overlaps = false;
  bool first_repeat = false;

  Interval(int s, int e) : start(s), end(e) {}

  const int size() const { return end - start + 1; }

  const bool IsValid() const {
    const int len = size();
    return 2 <= len && len <= 250;
  }
};

void solve(const char* message, const int length) {
  std::vector<Interval> intervals;

  std::vector<int> letter_positions[26];
  for (int i = 0; i < length; ++i) {
    letter_positions[message[i] - 'a'].push_back(i);
  }

  // 1. Start wild spacer.
  for (int letter = 0; letter < 26; ++letter) {
    const std::vector<int>& positions = letter_positions[letter];
    if (positions.empty()) continue;
    Interval iv(0, positions[0] - 1);
    if (iv.IsValid()) intervals.push_back(std::move(iv));
  }

  // 2. Middle letter spacers.
  for (int letter = 0; letter < 26; ++letter) {
    const std::vector<int>& positions = letter_positions[letter];
    for (int i = 0; i + 1 < positions.size(); ++i) {
      Interval iv(positions[i] + 1, positions[i + 1] - 1);
      if (iv.IsValid()) intervals.push_back(std::move(iv));
    }
  }

  // 3. End wild spacer.
  for (int letter = 0; letter < 26; ++letter) {
    const std::vector<int>& positions = letter_positions[letter];
    if (positions.empty()) continue;
    Interval iv(positions.back() + 1, length - 1);
    if (iv.IsValid()) intervals.push_back(std::move(iv));
  }

  // Sort according to the order for output.
  std::sort(intervals.begin(), intervals.end(),
            [](const Interval& i1, const Interval& i2) {
              if (i1.end < i2.start) return true;
              if (i2.end < i1.start) return false;
              return i1.end < i2.end;
            });

  // Find all repeated occurrences of words.
  std::map<std::string, std::vector<int>> repeated_occurrences;
  for (int i = 0; i < intervals.size(); ++i) {
    std::string& sorted = intervals[i].sorted;
    sorted.assign(message + intervals[i].start, intervals[i].size());
    std::sort(sorted.begin(), sorted.end());
    repeated_occurrences[sorted].push_back(i);
  }
  for (const auto& kv : repeated_occurrences) {
    const std::vector<int>& positions = kv.second;
    intervals[positions[0]].first_repeat = true;
    if (positions.size() > 1) {
      for (int pos : positions) {
        intervals[pos].repeats = true;
      }
    }
  }

  // Resort to mitigate O(N^2) while searching for all overlaps.
  std::vector<Interval*> sorted_by_start;
  sorted_by_start.reserve(intervals.size());
  for (auto& interval : intervals) {
    sorted_by_start.push_back(&interval);
  }
  std::sort(sorted_by_start.begin(), sorted_by_start.end(),
            [](const Interval* i1, const Interval* i2) {
              return i1->start < i2->start;
            });

  // Search for all overlaps.
  for (int i = 0; i < sorted_by_start.size(); ++i) {
    Interval& i1 = *sorted_by_start[i];
    if (!i1.repeats) continue;
    for (int j = i + 1; j < sorted_by_start.size(); ++j) {
      Interval& i2 = *sorted_by_start[j];
      if (i1.end < i2.start) break;
      if (!i2.repeats) continue;
      i1.overlaps = i2.overlaps = true;
    }
  }

  // Propagate the overlaps bit to all repeated occurrences.
  for (const auto& interval : intervals) {
    if (!interval.overlaps) continue;
    const std::vector<int>& positions = repeated_occurrences[interval.sorted];
    for (int pos : positions) {
      intervals[pos].overlaps = true;
    }
  }

  for (const auto& interval : intervals) {
    if (interval.overlaps && interval.repeats && interval.first_repeat) {
      std::string str(message + interval.start, interval.size());
      std::puts(str.c_str());
    }
  }
  std::puts("*");
}

int main() {
  int length = 0;
  char message[1024];
  char buffer[64];
  while (std::fgets(buffer, sizeof(buffer), stdin)) {
    char last_char = 0;
    for (char* p = buffer; *p; ++p) {
      if (*p == '\n') {
        *p = 0;
        break;
      }
      last_char = *p;
      if ('a' <= *p && *p <= 'z') message[length++] = *p;
    }
    if (last_char == '-') continue;
    if (buffer[0] == '#' && buffer[1] == 0) break;
    message[length] = 0;
    solve(message, length);
    length = 0;
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

