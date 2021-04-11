/* @JUDGE_ID: 19899RK 219 C++11 "By Anadan" */
// Department of Redundancy Department
// Accepted (0.030 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <vector>

struct FD {
  int mask1, mask2;
};

void ParseFD(const char* ptr, FD& fd) {
  fd.mask1 = fd.mask2 = 0;
  for (; 'A' <= *ptr && *ptr <= 'Z'; ++ptr) {
    const int bit = *ptr - 'A';
    fd.mask1 |= 1 << bit;
  }
  assert(*ptr == '-');
  ++ptr;
  assert(*ptr == '>');
  ++ptr;
  for (; 'A' <= *ptr && *ptr <= 'Z'; ++ptr) {
    const int bit = *ptr - 'A';
    fd.mask2 |= 1 << bit;
  }
}

bool IsReachable(const std::vector<FD>& fds, const int index, const int start,
                 const int target, std::vector<int>& path) {
  const int size = fds.size();
  std::vector<int> queue;
  queue.reserve(size - 1);
  for (int i = 0; i < size; ++i) {
    if (i != index) queue.push_back(i);
  }

  path.clear();
  int current = start;
  while (1) {
    const int saved = current;
    for (int k = queue.size() - 1; k >= 0; --k) {
      const int i = queue[k];
      const FD& fd = fds[i];
      if ((current & fd.mask1) != fd.mask1) continue;
      std::swap(queue[k], queue.back());
      queue.pop_back();
      const int next = current | fd.mask2;
      if (current == next) continue;
      path.push_back(i);
      current = next;
      if ((current & target) == target) return true;
    }
    if (saved == current) break;
  }
  return false;
}

bool CanReducePath(const std::vector<FD>& fds, const int index, const int start,
                   const int target, const std::vector<int>& path) {
  int current = start;
  for (int i = 0; i < path.size(); ++i) {
    if (i == index) continue;
    const FD& fd = fds[path[i]];
    if ((current & fd.mask1) != fd.mask1) return false;
    current |= fd.mask2;
  }
  return (current & target) == target;
}

bool IsRedundant(const std::vector<FD>& fds, const int index,
                 std::vector<int>& path) {
  const int start = fds[index].mask1;
  const int target = fds[index].mask2;
  if (!IsReachable(fds, index, start, target, path)) return false;

  // Try to reduce the path.
  for (int i = path.size() - 1; i >= 0; --i) {
    if (CanReducePath(fds, i, start, target, path)) {
      path.erase(path.begin() + i);
    }
  }
  return true;
}

int main() {
  int testcase = 0, size;
  char buffer[256];
  std::vector<FD> fds;
  std::vector<int> path;

  while (std::scanf("%d", &size) == 1 && size) {
    fds.resize(size);
    for (int i = 0; i < size; ++i) {
      std::scanf("%s", buffer);
      ParseFD(buffer, fds[i]);
    }

    std::printf("Set number %d\n", ++testcase);
    bool found = false;
    for (int i = 0; i < size; ++i) {
      if (IsRedundant(fds, i, path)) {
        std::printf("     FD %d is redundant using FDs:", i + 1);
        for (const int p : path) std::printf(" %d", p + 1);
        std::putchar('\n');
        found = true;
      }
    }
    if (!found) std::puts("     No redundant FDs.");
    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
