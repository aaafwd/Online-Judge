/* @JUDGE_ID: 19899RK 321 C++11 "By Anadan" */
// The New Villa
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <deque>
#include <set>
#include <vector>

struct Villa {
  std::vector<std::set<int>> doors;
  std::vector<std::set<int>> lamps;

  void resize(const int rooms) {
    doors.clear();
    doors.resize(rooms);
    lamps.clear();
    lamps.resize(rooms);
  }
};

class StateCache {
 public:
  void clear() { ++cache_gen_; }

  void insert(const int state, const int prev_state) {
    assert(state < kMaxCacheSize);
    cache_[state] = cache_gen_;
    prev_state_[state] = prev_state;
  }

  bool contains(const int state) const {
    assert(state < kMaxCacheSize);
    return cache_[state] == cache_gen_;
  }

  int GetPrevState(const int state) const {
    assert(contains(state));
    return prev_state_[state];
  }

 private:
  static constexpr int kMaxRooms = 10;
  static constexpr int kMaxCacheSize = kMaxRooms * (1 << kMaxRooms);
  int cache_[kMaxCacheSize] = {0};
  int prev_state_[kMaxCacheSize] = {0};
  int cache_gen_ = 0;
};

void FindPath(const Villa& villa, StateCache& cache, std::vector<int>& path) {
  cache.clear();
  path.clear();
  const int rooms = villa.doors.size();
  const int init_state = 1;
  const int final_state = ((rooms - 1) << rooms) | (1 << (rooms - 1));
  const int lamps_mask = (1 << rooms) - 1;

  std::deque<int> queue;
  queue.push_back(init_state);
  while (!queue.empty()) {
    const int state = queue.front();
    const int room = state >> rooms;
    const int lamps = state & lamps_mask;
    queue.pop_front();

    for (const int next_room : villa.doors[room]) {
      // Can't go to the next room if there is no light.
      if (!(lamps & (1 << next_room))) continue;
      const int next_state = (next_room << rooms) | lamps;
      if (cache.contains(next_state)) continue;
      cache.insert(next_state, state);
      if (next_state == final_state) break;
      queue.push_back(next_state);
    }
    if (cache.contains(final_state)) break;

    for (const int next_lamp : villa.lamps[room]) {
      // Can't turn off the light in the current room.
      if (next_lamp == room) continue;
      const int next_state = state ^ (1 << next_lamp);
      if (cache.contains(next_state)) continue;
      cache.insert(next_state, state);
      if (next_state == final_state) break;
      queue.push_back(next_state);
    }
    if (cache.contains(final_state)) break;
  }

  if (cache.contains(final_state)) {
    for (int state = final_state; state != init_state;
         state = cache.GetPrevState(state)) {
      path.push_back(state);
    }
    path.push_back(init_state);
    std::reverse(path.begin(), path.end());
  }
}

void PrintPath(const int rooms, const std::vector<int>& path) {
  const int lamps_mask = (1 << rooms) - 1;
  int room = path[0] >> rooms;
  int lamps = path[0] & lamps_mask;
  for (int i = 1; i < path.size(); ++i) {
    const int next_room = path[i] >> rooms;
    const int next_lamps = path[i] & lamps_mask;
    if (next_room != room) {
      assert(lamps == next_lamps);
      std::printf("- Move to room %d.\n", next_room + 1);
      room = next_room;
    } else {
      const int lamp_bit = lamps ^ next_lamps;
      int lamp = 0;
      while (!(lamp_bit & (1 << lamp))) ++lamp;
      if ((next_lamps & lamp_bit) != 0) {
        // Switched on.
        std::printf("- Switch on light in room %d.\n", lamp + 1);
      } else {
        // Switched off.
        std::printf("- Switch off light in room %d.\n", lamp + 1);
      }
      lamps = next_lamps;
    }
  }
}

int main() {
  Villa villa;
  StateCache cache;
  int testcase = 0, rooms, doors, lamps, i, j;
  std::vector<int> path;

  while (std::scanf("%d%d%d", &rooms, &doors, &lamps) == 3 && rooms) {
    villa.resize(rooms);
    while (doors-- > 0) {
      std::scanf("%d%d", &i, &j);
      if (i == j) continue;
      --i;
      --j;
      villa.doors[i].insert(j);
      villa.doors[j].insert(i);
    }
    while (lamps-- > 0) {
      std::scanf("%d%d", &i, &j);
      if (i == j) continue;
      --i;
      --j;
      villa.lamps[i].insert(j);
    }

    FindPath(villa, cache, path);
    std::printf("Villa #%d\n", ++testcase);
    if (rooms == 1) {
      std::puts("The problem can be solved in 0 steps:");
    } else  if (path.empty()) {
      std::puts("The problem cannot be solved.");
    } else {
      const int steps = path.size() - 1;
      std::printf("The problem can be solved in %d steps:\n", steps);
      PrintPath(rooms, path);
    }
    std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
