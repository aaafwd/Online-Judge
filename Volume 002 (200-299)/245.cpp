/* @JUDGE_ID: 19899RK 245 C++11 "By Anadan" */
// Uncompress
// Accepted (0.000 seconds with low memory spent)

#include <cstdio>
#include <deque>
#include <iterator>
#include <list>
#include <string>

template <class T>
class ListWithRandomAccess {
 public:
  T& front() { return elements.front(); }
  const T& front() const { return elements.front(); }

  void push_front(const T& x) {
    elements.push_front(x);
    IncreaseSizeFront();
  }

  void push_front(T&& x) {
    elements.push_front(std::move(x));
    IncreaseSizeFront();
  }

  void MoveToFront(const int index) {
    if (index <= 0) return;
    int left_it_index = -1;
    auto it = GetIteratorAt(index, &left_it_index);
    for (int i = (offset == 0 ? 1 : 0); i <= left_it_index; ++i) {
      std::advance(iterators[i], -1);
    }
    elements.splice(elements.begin(), elements, it, std::next(it));
    if (offset == 0) {
      std::advance(iterators[0], -1);
    }
  }

 private:
  constexpr static int kIteratorOffsetSize = 50;
  typedef typename std::list<T>::const_iterator const_list_iterator;

  void IncreaseSizeFront() {
    ++size;
    ++offset;
    if (offset == kIteratorOffsetSize) {
      iterators.push_front(elements.begin());
      offset = 0;
    }
  }

  const_list_iterator GetIteratorAt(int index, int* left_it_index) const {
    if (index < offset) {
      *left_it_index = -1;
      auto left = elements.begin();
      auto right = iterators.empty() ? elements.end() : iterators[0];
      if (index * 2 <= offset) {
        return std::next(left, index);
      }
      return std::next(right, index - offset);
    }
    index -= offset;
    const int iter_i = index / kIteratorOffsetSize;
    *left_it_index = iter_i;
    auto left = iterators[iter_i];
    auto right = (iter_i + 1 < iterators.size()) ? iterators[iter_i + 1]
                                                 : elements.end();
    index %= kIteratorOffsetSize;
    if (index * 2 <= kIteratorOffsetSize) {
      return std::next(left, index);
    }
    return std::next(right, index - kIteratorOffsetSize);
  }

  std::list<T> elements;
  std::deque<const_list_iterator> iterators;
  int size = 0;
  int offset = 0;
};

inline bool IsLetter(int x) {
  return ('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z');
}

inline bool IsDigit(int x) {
  return '0' <= x && x <= '9';
}

int main() {
  ListWithRandomAccess<std::string> list;
  std::string word;
  int ch = std::getchar();
  while (ch != EOF) {
    if (IsLetter(ch)) {
      word.clear();
      do {
        word.push_back(ch);
        std::putchar(ch);
      } while (IsLetter(ch = std::getchar()));
      list.push_front(std::move(word));
    } else if (IsDigit(ch)) {
      int x = 0;
      do {
        x = 10 * x + (ch - '0');
      } while (IsDigit(ch = std::getchar()));
      if (x == 0) break;
      list.MoveToFront(x - 1);
      std::printf("%s", list.front().c_str());
    } else {
      std::putchar(ch);
      ch = std::getchar();
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
