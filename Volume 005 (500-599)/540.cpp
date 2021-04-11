/* @JUDGE_ID: 19899RK 540 C++11 "By Anadan" */
// Team Queue
// Accepted (0.010 seconds with low memory spent)
// Accepted (0.020 seconds with low memory spent) without fastio

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <deque>
#include <unordered_map>
#include <vector>

struct TeamQueue {
  struct Block {
    std::deque<int> block;
  };

  std::unordered_map<int, int> id_to_team;
  int teams_count;

  std::deque<Block> queue;
  std::unordered_map<int, Block*> team_to_block;

  void clear() {
    id_to_team.clear();
    teams_count = 0;
    queue.clear();
    team_to_block.clear();
  }

  void AddTeam(const std::vector<int>& ids) {
    ++teams_count;
    for (const int id : ids) id_to_team[id] = teams_count;
  }

  void Enqueue(const int id) {
    const int team = id_to_team[id];
    assert(team != 0);
    if (team == 0) {
      queue.emplace_back();
      queue.back().block.push_back(id);
    } else {
      Block* block = team_to_block[team];
      if (block == nullptr) {
        queue.emplace_back();
        block = &queue.back();
        team_to_block[team] = block;
      }
      block->block.push_back(id);
    }
  }

  int Dequeue() {
    assert(!queue.empty());
    if (queue.empty()) return 0;
    const int id = queue.front().block.front();
    const int team = id_to_team[id];

    queue.front().block.pop_front();
    if (queue.front().block.empty()) {
      queue.pop_front();
      team_to_block.erase(team);
    }
    return id;
  }
};

namespace fastio {

bool ReadInt(int* x) {
  while (1) {
    *x = std::getchar();
    if (*x == EOF) return false;
    *x ^= '0';
    if (*x <= 9) break;
  }
  for (char ch; (ch = std::getchar() ^ '0') <= 9;) *x = (*x) * 10 + ch;
  return true;
}

void PrintUInt(int x) {
  if (x) {
    PrintUInt(x / 10);
    std::putchar('0' + (x % 10));
  }
}

}  // namespace fastio

int main() {
  using fastio::ReadInt;
  using fastio::PrintUInt;
  char buffer[16];
  int testcase = 0, teams, x;
  TeamQueue queue;
  std::vector<int> team_ids;
  while (ReadInt(&teams) == 1 && teams) {
    queue.clear();
    for (int i = 0; i < teams; ++i) {
      int team_size;
      ReadInt(&team_size);
      team_ids.resize(team_size);
      for (int j = 0; j < team_size; ++j) {
        ReadInt(&team_ids[j]);
      }
      queue.AddTeam(team_ids);
    }

    std::printf("Scenario #%d\n", ++testcase);
    while (std::scanf("%s", buffer) == 1) {
      if (buffer[0] == 'E') {
        ReadInt(&x);
        queue.Enqueue(x);
      } else if (buffer[0] == 'D') {
        x = queue.Dequeue();
        if (x == 0) {
          std::puts("0");
        } else {
          PrintUInt(x);
          std::putchar('\n');
        }
      } else {
        break;  // STOP
      }
    }
    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
