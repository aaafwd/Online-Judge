/* @JUDGE_ID: 19899RK 475 C++11 "By Anadan" */
// Wild Thing
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <unordered_set>

struct StrView {
  const char* ptr;
  int i, j;

  int size() const { return j - i + 1; }
  bool empty() const { return i > j; }

  char front() const { return ptr[i]; }
  void pop_front() { ++i; }

  char back() const { return ptr[j]; }
  void pop_back() { --j; }
};

class MatchesCache {
 public:
  void clear() { cache_.clear(); }
  bool insert(const StrView& pattern_view, const StrView& filename_view) {
    const int key = (pattern_view.i << 15) | (pattern_view.j << 10) |
                    (filename_view.i << 5) | filename_view.j;
    return cache_.insert(key).second;
  }

 private:
  std::unordered_set<int> cache_;
};

char* DedupWildcards(const char* ptr, char* output) {
  char* begin = output;
  *output = *ptr;
  if (*output == 0) return begin;
  for (++ptr; *ptr; ++ptr) {
    if (*ptr == '*' && *output == '*') continue;
    *(++output) = *ptr;
  }
  *(++output) = 0;
  return begin;
}

char* RemoveTrailingNewLine(char* ptr) {
  char* begin = ptr;
  while (*ptr && *ptr != '\n') ++ptr;
  *ptr = 0;
  return begin;
}

StrView ToStrView(char* ptr) {
  StrView result{ptr, 0, -1};
  while (*ptr) {
    ++ptr;
    ++result.j;
  }
  return result;
}

bool Matches(StrView pattern_view, StrView filename_view, MatchesCache* cache) {
  // Make pattern's front() point to a wildcard.
  while (!pattern_view.empty() && pattern_view.front() != '*') {
    if (filename_view.empty() ||
        filename_view.front() != pattern_view.front()) {
      return false;
    }
    pattern_view.pop_front();
    filename_view.pop_front();
  }
  // Make pattern's back() point to a wildcard.
  while (!pattern_view.empty() && pattern_view.back() != '*') {
    if (filename_view.empty() || filename_view.back() != pattern_view.back()) {
      return false;
    }
    pattern_view.pop_back();
    filename_view.pop_back();
  }
  if (pattern_view.empty()) {
    return filename_view.empty();
  }
  if (pattern_view.size() == 1) {
    return true;  // A single wildcard left.
  }

  // Pop wildcards from both ends.
  pattern_view.pop_front();
  pattern_view.pop_back();
  assert(!pattern_view.empty());  // There should be no duplicated wildcards.

  while (!filename_view.empty() &&
         filename_view.front() != pattern_view.front()) {
    filename_view.pop_front();
  }
  while (!filename_view.empty() &&
         filename_view.back() != pattern_view.back()) {
    filename_view.pop_back();
  }
  if (filename_view.empty()) return false;

  // Now run recursion with dynamic programming cache.
  if (!cache->insert(pattern_view, filename_view)) return false;
  for (int i = filename_view.i; i <= filename_view.j; ++i) {
    if (filename_view.ptr[i] != filename_view.front()) continue;
    for (int j = i; j <= filename_view.j; ++j) {
      if (filename_view.ptr[j] != filename_view.back()) continue;
      if (Matches(pattern_view, StrView{filename_view.ptr, i, j}, cache)) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  char pattern[32], normalized_pattern[32], filename[32];
  bool has_datasets_output = false;
  bool has_pattern_output = false;
  MatchesCache cache;

  while (std::fgets(pattern, sizeof(pattern), stdin)) {
    const StrView pattern_view = ToStrView(
        DedupWildcards(RemoveTrailingNewLine(pattern), normalized_pattern));
    if (pattern_view.empty()) break;
    has_pattern_output = false;
    while (std::fgets(filename, sizeof(filename), stdin)) {
      const StrView filename_view = ToStrView(RemoveTrailingNewLine(filename));
      if (filename_view.empty()) break;
      cache.clear();
      if (Matches(pattern_view, filename_view, &cache)) {
        if (!has_pattern_output) {
          has_pattern_output = true;
          if (has_datasets_output) {
            std::putchar('\n');
          } else {
            has_datasets_output = true;
          }
          std::printf("MATCHES FOR THE PATTERN: %s\n", pattern);
        }
        std::puts(filename);
      }
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
