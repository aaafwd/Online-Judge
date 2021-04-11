/* @JUDGE_ID: 19899RK 247 C++11 "By Anadan" */
// Calling Circles
// Accepted (0.000 seconds with low memory spent)

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>

char calls[32][32];
char visited[32];
std::vector<int> order;
std::vector<int> component;

// Search strongly connected components.
void dfs1(int v, int n) {
  visited[v] = 1;
  for (int i = 0; i < n; ++i) {
    if (i == v || !calls[v][i]) continue;
    if (!visited[i]) {
      dfs1(i, n);
    }
  }
  order.push_back(v);
}

void dfs2(int v, int n) {
  visited[v] = 1;
  component.push_back(v);
  for (int i = 0; i < n; ++i) {
    if (i == v || !calls[i][v]) continue;
    if (!visited[i]) {
      dfs2(i, n);
    }
  }
}

int main() {
  int n, m;
  char buffer1[32];
  char buffer2[32];
  int data_set = 0;
  while (std::scanf("%d%d", &n, &m) == 2) {
    if (n == 0 && m == 0) break;
    for (int i = 0; i < n; ++i) {
      std::memset(calls[i], 0, n);
    }

    int next_id = 0;
    std::map<std::string, int> name_to_id;
    std::map<int, std::string> id_to_name;
    for (; m > 0; --m) {
      std::scanf("%s %s", buffer1, buffer2);
      std::string name1(buffer1);
      std::string name2(buffer2);
      if (!name_to_id.count(name1)) {
        name_to_id[name1] = next_id;
        id_to_name[next_id] = name1;
        ++next_id;
      }
      if (!name_to_id.count(name2)) {
        name_to_id[name2] = next_id;
        id_to_name[next_id] = name2;
        ++next_id;
      }
      const int id1 = name_to_id[name1];
      const int id2 = name_to_id[name2];
      calls[id1][id2] = 1;
    }
    n = next_id;

    order.clear();
    std::memset(visited, 0, n);
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) dfs1(i, n);
    }

    if (data_set) std::putchar('\n');
    std::printf("Calling circles for data set %d:\n", ++data_set);

    std::memset(visited, 0, n);
    for (int i = n - 1; i >= 0; --i) {
      if (!visited[order[i]]) {
        component.clear();
        dfs2(order[i], n);

        for (int j = 0; j < component.size(); ++j) {
          if (j) std::printf(", ");
          std::printf("%s", id_to_name[component[j]].c_str());
        }
        std::putchar('\n');
      }
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
