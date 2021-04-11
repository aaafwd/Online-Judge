/* @JUDGE_ID: 19899RK 473 C++11 "By Anadan" */
// Raucous Rockers
// Accepted (0.190 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <set>
#include <vector>

int disk_time;
std::vector<int> song_times;

// Indexes: num_disks * begin_index.
std::vector<std::vector<int>> max_songs;

// Indexes: begin_index * end_index.
std::vector<std::vector<int>> max_songs_single_disk;

int solve_single_disk(int begin, int end) {
  int result = max_songs_single_disk[begin][end];
  if (result >= 0) return result;

  auto cmp = [](const int i, const int j) {
    if (song_times[i] == song_times[j]) return i < j;
    return song_times[i] > song_times[j];
  };
  std::set<int, decltype(cmp)> best_songs(cmp);

  int disk_time_left = disk_time;
  for (int i = begin; i < song_times.size(); ++i) {
    if (disk_time_left >= song_times[i]) {
      disk_time_left -= song_times[i];
      best_songs.insert(i);
    } else if (!best_songs.empty()) {
      const int max_time_song = *best_songs.begin();
      const int max_time = song_times[max_time_song];
      if (max_time > song_times[i]) {
        disk_time_left += max_time;
        best_songs.erase(max_time_song);
        disk_time_left -= song_times[i];
        best_songs.insert(i);
      }
    }
    max_songs_single_disk[begin][i] = best_songs.size();
  }
  return max_songs_single_disk[begin][end];
}

int solve(const int disks, const int begin) {
  const int end = song_times.size() - 1;
  int result = max_songs[disks - 1][begin];
  if (result >= 0) return result;
  if (disks > end - begin) {
    result = end - begin + 1;
  } else if (disks == 1) {
    result = solve_single_disk(begin, end);
  } else {
    result = 0;
    // Optimization #1 with checking `prev_single_result`: ~40% faster.
    int prev_single_result = 0;
    for (int i = begin; i < end; ++i) {
      int tmp = solve_single_disk(begin, i);
      if (tmp <= prev_single_result) continue;
      prev_single_result = tmp;
      tmp += solve(disks - 1, i + 1);
      if (result < tmp) {
        result = tmp;
      } else if (result > tmp + 1) {
        // Optimization #2: ~75% faster vs after optimization #1.
        // Note that `(result > tmp)` condition is not enough: WA.
        //
        // Rationale: next improvement is possible at some index i* when both:
        // a) prev_single_result := prev_single_result + 1
        // b) `solve(disks - 1, i* + 1)` returns the same result (cannot return
        //    more)
        // IOW, next improvement can be at most `tmp + 1`.
        // If we already have a result that is strictly greater than the next
        // possible improvement, then adding more songs to the current single
        // disk is no longer optimal and we can halt the iteration.
        break;
      }
    }
  }
  max_songs[disks - 1][begin] = result;
  return result;
}

int main() {
  int datasets, songs, disks;

  std::scanf("%d\n\n", &datasets);
  while (datasets-- > 0) {
    std::scanf("%d %d %d\n", &songs, &disk_time, &disks);

    song_times.clear();
    song_times.reserve(songs);
    for (int i = 0; i < songs; ++i) {
      int song_time;
      std::scanf("%d%*[ ,]", &song_time);
      if (song_time <= disk_time) song_times.push_back(song_time);
    }
    songs = song_times.size();

    // Setup the cache for dynamic programming.
    max_songs.resize(disks);
    for (int i = 0; i < disks; ++i) {
      max_songs[i].clear();
      max_songs[i].resize(songs, -1);
    }

    max_songs_single_disk.resize(songs);
    for (int i = 0; i < songs; ++i) {
      max_songs_single_disk[i].clear();
      max_songs_single_disk[i].resize(songs, -1);
    }

    std::printf("%d\n", solve(disks, 0));

    if (datasets) std::putchar('\n');
  }

  return 0;
}
/* @END_OF_SOURCE_CODE */
