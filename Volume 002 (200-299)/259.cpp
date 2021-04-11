/* @JUDGE_ID: 19899RK 259 C++11 "By Anadan" */
// Software Allocation
// Accepted (0.000 seconds with low memory spent)

#include <cstdio>
#include <vector>

struct Allocation {
  char app;
  char instances;
  int computers_mask;
};
std::vector<Allocation> allocations;
char answer[16];
int answer_bits[32];

bool FindAllocation(int index, int alloc_index, int available_mask) {
  if (alloc_index == allocations.size()) {
    // Build the answer string.
    for (int i = 0; i < index; i += 2) {
      const int bit = answer_bits[i];
      const int ch = answer_bits[i + 1];
      for (int j = 0; j < 10; ++j) {
        if (bit == (1 << j)) {
          answer[j] = ch;
          break;
        }
      }
    }
    return true;
  }
  auto& alloc = allocations[alloc_index];
  int mask = available_mask & alloc.computers_mask;
  if (!mask) return false;
  --alloc.instances;
  answer_bits[index + 1] = alloc.app;
  do {
    const int new_mask = mask & (mask - 1);
    const int bit = mask - new_mask;
    mask = new_mask;
    answer_bits[index] = bit;
    if (FindAllocation(index + 2,
                       alloc.instances ? alloc_index : alloc_index + 1,
                       (available_mask ^ bit))) {
      return true;
    }
  } while (mask);
  ++alloc.instances;
  return false;
}

int main() {
  char app[4];
  char computers[16];
  char buffer[64];
  while (1) {
    allocations.clear();
    while (std::fgets(buffer, sizeof(buffer), stdin)) {
      if (buffer[0] == '\n') break;
      if (std::sscanf(buffer, "%s %[0-9]s;", app, computers) != 2) break;
      Allocation alloc;
      alloc.app = app[0];
      alloc.instances = app[1] - '0';
      alloc.computers_mask = 0;
      for (const char* p = computers; *p; ++p) {
        alloc.computers_mask |= (1 << (*p - '0'));
      }
      allocations.push_back(std::move(alloc));
    }
    if (allocations.empty()) break;

    int total = 0;
    int total_mask = 0;
    for (const auto& alloc : allocations) {
      total += alloc.instances;
      total_mask |= alloc.computers_mask;
    }
    for (int i = 0; i < 10; ++i) {
      if (total_mask & (1 << i)) --total;
      answer[i] = '_';
    }
    answer[11] = 0;
    if (total > 0 || !FindAllocation(0, 0, total_mask)) {
      std::puts("!");
    } else {
      std::puts(answer);
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
