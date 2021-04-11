/* @JUDGE_ID: 19899RK 323 C++11 "By Anadan" */
// Jury Compromise
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <vector>

struct DpCache {
  struct Path {
    int candidate, prev_index;
  };

  void clear() {
    ++cache_gen_;
    prev_path_.clear();
  }

  bool HasItem(int i, int j) const {
    j += 512;
    assert(0 <= i && i < 20);
    assert(0 <= j && j < 1024);
    return mask_[i][j] == cache_gen_;
  }

  void AddItem(int i, int j, int sum_score, int candidate, int prev_index) {
    j += 512;
    assert(0 <= i && i < 20);
    assert(0 <= j && j < 1024);
    mask_[i][j] = cache_gen_;
    sum_scores_[i][j] = sum_score;
    prev_path_index_[i][j] = prev_path_.size();
    prev_path_.push_back({candidate, prev_index});
  }

  int GetSumScore(int i, int j) const {
    j += 512;
    assert(0 <= i && i < 20);
    assert(0 <= j && j < 1024);
    return sum_scores_[i][j];
  }

  int GetPathIndex(int i, int j) const {
    j += 512;
    assert(0 <= i && i < 20);
    assert(0 <= j && j < 1024);
    return prev_path_index_[i][j];
  }

  int GetCandidateByPathIndex(int path_index) const {
    assert(0 <= path_index && path_index < prev_path_.size());
    return prev_path_[path_index].candidate;
  }

  int GetPrevPathIndex(int path_index) const {
    assert(0 <= path_index && path_index < prev_path_.size());
    return prev_path_[path_index].prev_index;
  }

  int mask_[20][1024] = {0};
  int sum_scores_[20][1024];
  int prev_path_index_[20][1024];
  std::vector<Path> prev_path_;
  int cache_gen_ = 0;
};

void FindJuryCompromise(const std::vector<int>& pi, const std::vector<int>& di,
                        std::vector<int>& candidates, DpCache& dp_cache) {
  const int N = pi.size();
  const int M = candidates.size();
  std::vector<int> min_scores(M, 0), max_scores(M, 0);

  for (int i = 0; i < N; ++i) {
    for (int m = M - 2; m >= 0; --m) {
      for (int score = min_scores[m]; score <= max_scores[m]; ++score) {
        if (!dp_cache.HasItem(m, score)) continue;
        const int new_score = score + pi[i] - di[i];
        const int new_sum_score =
            dp_cache.GetSumScore(m, score) + pi[i] + di[i];
        if (!dp_cache.HasItem(m + 1, new_score) ||
            dp_cache.GetSumScore(m + 1, new_score) < new_sum_score) {
          dp_cache.AddItem(m + 1, new_score, new_sum_score, i,
                           dp_cache.GetPathIndex(m, score));
          if (min_scores[m + 1] > new_score) min_scores[m + 1] = new_score;
          if (max_scores[m + 1] < new_score) max_scores[m + 1] = new_score;
        }
      }
    }
    const int new_score = pi[i] - di[i];
    const int new_sum_score = pi[i] + di[i];
    if (!dp_cache.HasItem(0, new_score) ||
        dp_cache.GetSumScore(0, new_score) < new_sum_score) {
      dp_cache.AddItem(0, new_score, new_sum_score, i, -1);
      if (min_scores[0] > new_score) min_scores[0] = new_score;
      if (max_scores[0] < new_score) max_scores[0] = new_score;
    }
  }

  int abs_score = 0;
  if (min_scores.back() > 0) abs_score = min_scores.back();
  if (max_scores.back() < 0) abs_score = -max_scores.back();
  while (!dp_cache.HasItem(M - 1, abs_score) &&
         !dp_cache.HasItem(M - 1, -abs_score)) {
    ++abs_score;
  }
  if (dp_cache.HasItem(M - 1, abs_score) &&
      dp_cache.HasItem(M - 1, -abs_score)) {
    if (dp_cache.GetSumScore(M - 1, -abs_score) >
        dp_cache.GetSumScore(M - 1, abs_score)) {
      abs_score = -abs_score;
    }
  } else if (!dp_cache.HasItem(M - 1, abs_score)) {
    abs_score = -abs_score;
  }

  // Construct the answer.
  int path_index = dp_cache.GetPathIndex(M - 1, abs_score);
  for (int m = M - 1; m >= 0; --m) {
    candidates[m] = dp_cache.GetCandidateByPathIndex(path_index);
    path_index = dp_cache.GetPrevPathIndex(path_index);
  }
  assert(path_index == -1);
}

int main() {
  int testcase = 0, n, m;
  std::vector<int> pi, di, candidates;
  DpCache dp_cache;

  while (std::scanf("%d%d", &n, &m) == 2 && n) {
    pi.resize(n);
    di.resize(n);
    candidates.resize(m);
    dp_cache.clear();
    for (int i = 0; i < n; ++i) {
      std::scanf("%d%d", &pi[i], &di[i]);
    }

    FindJuryCompromise(pi, di, candidates, dp_cache);
    int prosecution = 0, defence = 0;
    for (int i = 0; i < m; ++i) {
      prosecution += pi[candidates[i]];
      defence += di[candidates[i]];
    }

    std::printf(
        "Jury #%d\nBest jury has value %d for prosecution and value %d for "
        "defence:\n",
        ++testcase, prosecution, defence);
    for (int i = 0; i < m; ++i) {
      std::printf(" %d", candidates[i] + 1);
    }
    std::putchar('\n');
    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
