/* @JUDGE_ID: 19899RK 240 C++11 "By Anadan" */
// Variable Radix Huffman Encoding
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <queue>
#include <string>
#include <vector>

constexpr int kFictitiousSymbol = 999;

struct Node {
  int symbol, freq;
  std::vector<int> children;
};

void CollectEncodings(const std::vector<Node>& nodes, const int index,
                      std::vector<std::string>& encodings,
                      std::string& current) {
  const Node& node = nodes[index];
  if (node.children.empty()) {
    if (node.symbol < kFictitiousSymbol) {
      assert(node.symbol < encodings.size());
      encodings[node.symbol] = current;
    }
    return;
  }
  current.push_back('0');
  for (int i = 0; i < node.children.size(); ++i) {
    current.back() = '0' + i;
    CollectEncodings(nodes, node.children[i], encodings, current);
  }
  current.pop_back();
}

int HuffmanEncode(const int R, std::vector<Node>& nodes,
                  std::vector<std::string>& encodings) {
  auto cmp = [&nodes](const int i, const int j) {
    const Node& a = nodes[i];
    const Node& b = nodes[j];
    return !((a.freq != b.freq) ? (a.freq < b.freq) : (a.symbol < b.symbol));
  };
  std::priority_queue<int, std::vector<int>, decltype(cmp)> queue(cmp);

  for (int i = 0; i < nodes.size(); ++i) {
    queue.push(i);
  }
  while (queue.size() != 1) {
    assert(queue.size() >= R);
    Node composite;
    composite.freq = 0;
    composite.symbol = kFictitiousSymbol;
    composite.children.resize(R);
    for (int i = 0; i < R; ++i) {
      const int index = queue.top();
      const Node& node = nodes[index];
      queue.pop();
      composite.children[i] = index;
      composite.freq += node.freq;
      if (composite.symbol > node.symbol) {
        composite.symbol = node.symbol;
      }
    }
    assert(composite.symbol < kFictitiousSymbol);
    assert(composite.freq > 0);
    nodes.push_back(std::move(composite));
    queue.push(nodes.size() - 1);
  }
  std::string current;
  CollectEncodings(nodes, nodes.size() - 1, encodings, current);

  int average = 0, sum_freq = 0;
  for (int i = 0; i < encodings.size(); ++i) {
    assert(nodes[i].symbol == i);
    sum_freq += nodes[i].freq;
    average += nodes[i].freq * encodings[i].size();
  }
  average *= 100;
  average += sum_freq / 2;
  average /= sum_freq;
  return average;
}

int main() {
  int data_set = 0, R, N, M, K;
  std::vector<Node> nodes;
  std::vector<std::string> encodings;
  while (std::scanf("%d", &R) == 1 && R) {
    std::scanf("%d", &N);
    // k ∗ (R − 1) + R >= N
    // k >= (N - R) / (R - 1)
    K = (N <= R) ? 0 : (N - 2) / (R - 1);
    M = (N <= R) ? R : K * (R - 1) + R;
    assert(M >= N);
    nodes.clear();
    nodes.reserve(M + K + 1);
    for (int i = 0; i < N; ++i) {
      Node node;
      node.symbol = i;
      std::scanf("%d", &node.freq);
      nodes.push_back(std::move(node));
    }
    for (int i = N; i < M; ++i) {
      Node node;
      node.symbol = kFictitiousSymbol + i;
      node.freq = 0;
      nodes.push_back(std::move(node));
    }
    assert(nodes.size() == M);

    encodings.clear();
    encodings.resize(N);

    const int average100 = HuffmanEncode(R, nodes, encodings);
    assert(nodes.size() == M + K + 1);
    std::printf("Set %d; average length %d.%02d\n", ++data_set,
                average100 / 100, average100 % 100);
    for (int i = 0; i < N; ++i) {
      std::printf("    %c: %s\n", 'A' + i, encodings[i].c_str());
    }
    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
