/* @JUDGE_ID: 19899RK 318 C++11 "By Anadan" */
// Domino Effect
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cstdio>
#include <set>
#include <vector>

void solve(const std::vector<std::vector<int>>& graph, int* node1, int* node2,
           int* doubled_time) {
  const int N = graph.size();
  std::vector<int> falldown_time(N, -1);
  std::vector<int> previous_node(N, -1);

  auto cmp = [&](const int i, const int j) {
    if (falldown_time[i] == falldown_time[j]) return i < j;
    return falldown_time[i] < falldown_time[j];
  };
  std::set<int, decltype(cmp)> queue(cmp);

  falldown_time[0] = 0;
  queue.insert(0);
  while (!queue.empty()) {
    const int node = *queue.begin();
    queue.erase(queue.begin());
    for (int i = 0; i < N; ++i) {
      if (graph[node][i] == -1) continue;
      const int new_time = falldown_time[node] + graph[node][i];
      if (falldown_time[i] > new_time) {
        queue.erase(i);
      } else if (falldown_time[i] != -1) {
        continue;
      }
      falldown_time[i] = new_time;
      previous_node[i] = node;
      queue.insert(i);
    }
  }

  *node1 = *node2 = *doubled_time = 0;
  for (int i = 0; i < N; ++i) {
    // Wrong Answer: `if (*doubled_time < falldown_time[i] * 2) { ... }`
    // IOW, "at key domino Z" should be prefered over the "between X and Y".
    if (*doubled_time <= falldown_time[i] * 2) {
      *doubled_time = falldown_time[i] * 2;
      *node1 = *node2 = i;
    }
    for (int j = i + 1; j < N; ++j) {
      if (graph[i][j] == -1) continue;
      if (previous_node[i] == j || previous_node[j] == i) continue;
      const int middle_time = falldown_time[i] + falldown_time[j] + graph[i][j];
      if (*doubled_time < middle_time) {
        *doubled_time = middle_time;
        *node1 = i;
        *node2 = j;
      }
    }
  }
}

int main() {
  std::vector<std::vector<int>> graph;
  int system_count = 0, n, m, a, b, l;

  while (std::scanf("%d %d", &n, &m) == 2 && n) {
    graph.clear();
    graph.resize(n);
    for (int i = 0; i < n; ++i) {
      graph[i].resize(n, -1);
    }
    for (int i = 0; i < m; ++i) {
      std::scanf("%d %d %d", &a, &b, &l);
      --a;
      --b;
      graph[a][b] = graph[b][a] = l;
    }

    int node1, node2, doubled_time;
    solve(graph, &node1, &node2, &doubled_time);
    ++node1;
    ++node2;

    std::printf("System #%d\n", ++system_count);
    if (node1 == node2) {
      std::printf(
          "The last domino falls after %d.%d seconds, at key domino %d.\n\n",
          doubled_time / 2, (doubled_time & 1) ? 5 : 0, node1);
    } else {
      std::printf(
          "The last domino falls after %d.%d seconds, between key dominoes %d "
          "and %d.\n\n",
          doubled_time / 2, (doubled_time & 1) ? 5 : 0, node1, node2);
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
