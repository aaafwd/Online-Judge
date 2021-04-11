/* @JUDGE_ID: 19899RK 234 C++ "By Anadan" */
// Switching Channels
// Accepted (0.000 seconds with low memory spent)

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

std::vector<int> programmes;
std::vector<std::vector<int>> all_alignments;
char programmes_mask[16];

int best_error;
std::vector<int> current_programmes, best_programmes;
std::vector<int> current_alignments, best_alignments;

int CalculateAlignmentError(const std::vector<int>& current_programmes,
                            const std::vector<int>& alignments) {
  const int alignments_size = alignments.size();
  const int size = current_programmes.size();
  int error = 0, offset = 0, prog_sum = 0;
  for (int i = 0; i < size; ++i) {
    const int prog = current_programmes[i];
    prog_sum += prog;
    while (offset < alignments_size && alignments[offset] <= prog_sum) {
      assert(alignments[offset] >= (prog_sum - prog));
      error += std::min(prog_sum - alignments[offset],
                        alignments[offset] - (prog_sum - prog));
      ++offset;
    }
  }
  assert(offset == alignments_size);
  return error;
}

void Generate(const int index, const int prog_sum, int offset,
              int current_error) {
  const int size = programmes.size();
  if (index == size) {
    current_alignments.assign(all_alignments.size(), 0);
    int total_error = 0;
    for (int k = 0; k < all_alignments.size(); ++k) {
      const int error =
          CalculateAlignmentError(current_programmes, all_alignments[k]);
      current_alignments[k] = error;
      total_error += error;
    }
    if (best_programmes.empty() || current_alignments < best_alignments) {
      best_programmes = current_programmes;
      best_alignments.swap(current_alignments);
      best_error = total_error;
    }
    return;
  }

  if (index > 0) {
    const std::vector<int>& alignments = all_alignments[0];
    const int alignments_size = alignments.size();
    const int last_prog = current_programmes[index - 1];
    while (offset < alignments_size && alignments[offset] <= prog_sum) {
      assert(alignments[offset] >= (prog_sum - last_prog));
      current_error += std::min(prog_sum - alignments[offset],
                                alignments[offset] - (prog_sum - last_prog));
      ++offset;
    }
    if (!best_alignments.empty() && best_alignments[0] < current_error) {
      return;
    }
  }

  for (int i = 0; i < size; ++i) {
    if (programmes_mask[i]) continue;
    programmes_mask[i] = 1;
    current_programmes[index] = programmes[i];
    Generate(index + 1, prog_sum + programmes[i], offset, current_error);
    programmes_mask[i] = 0;
  }
}

void PrintAnswer(const std::vector<int>& programmes,  const int error) {
  std::printf("Order:");
  for (int i = 0; i < programmes.size(); ++i) {
    std::printf(" %d", programmes[i]);
  }
  std::printf("\nError: %d\n", error);
}

int main() {
  int N, M, priority, x, sum, error_offset, min_prog, data_set = 0;
  std::vector<int> alignments[5];
  all_alignments.reserve(5);
  while (std::scanf("%d", &N) == 1 && N) {
    sum = 0;
    min_prog = -1;
    programmes.clear();
    for (int i = 0; i < N; ++i) {
      std::scanf("%d", &x);
      programmes.push_back(x);
      programmes_mask[i] = 0;
      sum += x;
      if (min_prog == -1 || min_prog > x) {
        min_prog = x;
      }
    }
    std::scanf("%d", &M);
    for (int i = 0; i < 5; ++i) alignments[i].clear();
    error_offset = 0;
    min_prog /= 2;
    for (int i = 0; i < M; ++i) {
      std::scanf("%d%d", &priority, &x);
      if (x <= 0) {
        error_offset -= x;
        continue;
      }
      if (x <= min_prog) {
        error_offset += x;
        continue;
      }
      if (x >= sum) {
        error_offset += x - sum;
        continue;
      }
      if (x >= sum - min_prog) {
        error_offset += sum - x;
        continue;
      }
      alignments[priority - 1].push_back(x);
    }

    all_alignments.clear();
    for (int i = 0; i < 5; ++i) {
      if (!alignments[i].empty()) {
        std::sort(alignments[i].begin(), alignments[i].end());
        all_alignments.push_back(std::move(alignments[i]));
      }
    }

    std::printf("Data set %d\n", ++data_set);
    if (all_alignments.empty()) {
      PrintAnswer(programmes, error_offset);
      continue;
    }

    best_error = -1;
    current_programmes.resize(programmes.size());
    best_programmes.clear();
    best_alignments.clear();
    Generate(0, 0, 0, 0);
    PrintAnswer(best_programmes, best_error + error_offset);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

