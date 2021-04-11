/* @JUDGE_ID: 19899RK 548 C++11 "By Anadan" */
// Tree
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <vector>

static constexpr int kMaxSize = 1024 * 10;

struct ArrayView {
  const int* data;
  int begin, end;  // [data[begin] .. data[end - 1]]

  explicit ArrayView(const std::vector<int>& array)
      : data(array.data()), begin(0), end(array.size()) {}

  ArrayView(const ArrayView& array_view, int b, int e)
      : data(array_view.data), begin(b), end(e) {
    assert(b <= e);
    assert(array_view.begin <= b && b <= array_view.end);
    assert(array_view.begin <= e && e <= array_view.end);
  }

  int size() const { return end - begin; }
  bool empty() const { return size() <= 0; }

  int front() const { return data[begin]; }
  int back() const { return data[end - 1]; }
};

bool ReadIntUntilEOL(int* x) {
  int ch;
  while (1) {
    ch = std::getchar();
    if (ch == EOF || ch == '\n') return false;
    ch ^= '0';
    if (ch <= 9) break;
  }
  *x = ch;
  while ((ch = std::getchar() ^ '0') <= 9) *x = (*x) * 10 + ch;
  std::ungetc(ch ^ '0', stdin);
  return true;
}

bool ReadArray(std::vector<int>& array) {
  array.clear();
  array.reserve(kMaxSize);
  for (int x; ReadIntUntilEOL(&x);) array.push_back(x);
  return !array.empty();
}

void Traverse(ArrayView inorder, ArrayView postorder,
              const int* value_to_inorder_index, int* min_leaf, int* min_path,
              int current_path = 0) {
  assert(inorder.size() == postorder.size());
  if (inorder.size() == 1) {
    current_path += inorder.front();
    if (current_path < *min_path ||
        (current_path == *min_path && inorder.front() < *min_leaf)) {
      *min_path = current_path;
      *min_leaf = inorder.front();
    }
    return;
  }
  if (current_path > *min_path) return;

  const int root = postorder.back();
  const int middle_index = value_to_inorder_index[root];
  const ArrayView left_inorder(inorder, inorder.begin, middle_index);
  const ArrayView right_inorder(inorder, middle_index + 1, inorder.end);
  const int left_size = left_inorder.size();
  assert(left_size >= 0);
  const ArrayView left_postorder(postorder, postorder.begin,
                                 postorder.begin + left_size);
  const ArrayView right_postorder(postorder, postorder.begin + left_size,
                                  postorder.end - 1);
  current_path += root;
  if (!left_inorder.empty()) {
    Traverse(left_inorder, left_postorder, value_to_inorder_index, min_leaf,
             min_path, current_path);
  }
  if (!right_inorder.empty()) {
    Traverse(right_inorder, right_postorder, value_to_inorder_index, min_leaf,
             min_path, current_path);
  }
}

int main() {
  int value_to_inorder_index[kMaxSize];
  std::vector<int> inorder, postorder;
  while (ReadArray(inorder) && ReadArray(postorder)) {
    assert(inorder.size() == postorder.size());
    for (int i = 0; i < inorder.size(); ++i) {
      value_to_inorder_index[inorder[i]] = i;
    }
    int min_leaf = 2147483647;
    int min_path = 2147483647;
    Traverse(ArrayView(inorder), ArrayView(postorder), value_to_inorder_index,
             &min_leaf, &min_path);
    std::printf("%d\n", min_leaf);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
