/* @JUDGE_ID: 19899RK 233 C++11 "By Anadan" */
// Package Pricing
// Accepted (0.120 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <array>
#include <cassert>
#include <cstdio>
#include <vector>

template <class T>
class MyVector {
 public:
  using size_type = typename std::vector<T>::size_type;

  MyVector() = default;
  explicit MyVector(size_type size) : vec_(size) {}

  inline T& operator[](size_type pos) {
    if (pos < vec_.size()) return vec_[pos];
    vec_.resize(pos + 1);
    return vec_.back();
  }
  inline void clear() { vec_.clear(); }
  inline size_type size() const { return vec_.size(); }

 private:
  std::vector<T> vec_;
};

struct Package {
  int catalogue;
  double price;
  std::array<int, 4> bulbs;
};

struct CacheItem {
  int package;  // =(index + 1) in packages or -1
  double value;
};

MyVector<MyVector<MyVector<MyVector<CacheItem>>>> cache;
std::vector<Package> packages;

const std::array<int, 4> operator-(const std::array<int, 4>& lhs,
                                   const std::array<int, 4>& rhs) {
  return {std::max(0, lhs[0] - rhs[0]), std::max(0, lhs[1] - rhs[1]),
          std::max(0, lhs[2] - rhs[2]), std::max(0, lhs[3] - rhs[3])};
}

CacheItem& GetCacheItem(const std::array<int, 4>& index) {
  return cache[index[0]][index[1]][index[2]][index[3]];
}

const CacheItem& GetMinPrice(const std::array<int, 4>& requirement) {
  CacheItem& item = GetCacheItem(requirement);
  if (item.package != 0) return item;
  item.package = -1;

  for (int i = 0; i < packages.size(); ++i) {
    const std::array<int, 4> sub_requirement = requirement - packages[i].bulbs;
    if (sub_requirement == requirement) continue;
    const CacheItem& sub_item = GetMinPrice(sub_requirement);
    const double sub_value = sub_item.value + packages[i].price;
    if (item.package == -1 || item.value > sub_value) {
      item.value = sub_value;
      item.package = i + 1;
    }
  }

  return item;
}

void CollectCatalogueNumbers(std::array<int, 4> requirement,
                             std::vector<int>* catalogues) {
  while (requirement[0] || requirement[1] || requirement[2] || requirement[3]) {
    const CacheItem& item = GetCacheItem(requirement);
    assert(item.package > 0);
    const int index = item.package - 1;
    const Package& pkg = packages[index];
    catalogues->push_back(index);
    requirement = requirement - pkg.bulbs;
  }
  std::sort(catalogues->begin(), catalogues->end(), [](int a, int b) {
    const Package& pkg_a = packages[a];
    const Package& pkg_b = packages[b];
    return pkg_a.catalogue < pkg_b.catalogue;
  });
}

void ScanfBulbs(std::array<int, 4>* bulbs) {
  int x, num;
  std::fill(bulbs->begin(), bulbs->end(), 0);
  while ((x = std::getchar()) != EOF) {
    if (x == '\n') break;
    if ('a' <= x && x <= 'd') {
      std::scanf("%d", &num);
      (*bulbs)[x - 'a'] += num;
    }
  }
}

int main() {
  std::array<int, 4> requirement;
  std::vector<int> catalogues;
  int N, M, x;
  while (std::scanf("%d", &N) == 1) {
    packages.resize(N);
    for (int i = 0; i < N; ++i) {
      std::scanf("%d%lf", &packages[i].catalogue, &packages[i].price);
      ScanfBulbs(&packages[i].bulbs);
    }

    cache.clear();
    cache[0][0][0][0] = {-1, 0.0};
    std::scanf("%d\n", &M);
    for (int i = 1; i <= M; ++i) {
      ScanfBulbs(&requirement);
      const CacheItem& item = GetMinPrice(requirement);
      catalogues.clear();
      CollectCatalogueNumbers(requirement, &catalogues);
      std::printf("%d:%8.2lf", i, item.value);
      for (int k = 0; k < catalogues.size(); ++k) {
        int count = 1;
        for (; k + count < catalogues.size(); ++count) {
          if (catalogues[k + count] != catalogues[k]) break;
        }
        const Package& pkg = packages[catalogues[k]];
        if (count == 1) {
          std::printf(" %d", pkg.catalogue);
        } else {
          std::printf(" %d(%d)", pkg.catalogue, count);
          k += count - 1;
        }
      }
      std::putchar('\n');
    }

    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
