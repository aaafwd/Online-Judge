/* @JUDGE_ID: 19899RK 395 C++11 "By Anadan" */
// Board Silly
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>

constexpr int kDirs[4][2] = {{-1, -1}, {0, -1}, {1, -1}, {-1, 0}};

struct Game {
  char board[8][12];
  char player[4];

  void PrintAllMoves() const {
    std::vector<int> moves;
    bool has_moves = false;
    for (int y = 0; y < 8; ++y) {
      for (int x = 0; x < 8; ++x) {
        if (board[y][x] != player[0]) continue;
        moves.clear();
        for (int k = 0; k < 4; ++k) {
          const int dx = kDirs[k][0];
          const int dy = kDirs[k][1];
          int pieces_count = 1;
          for (int sign = -1; sign <= 1; sign += 2) {
            for (int step = 1; step < 8; ++step) {
              const int nx = x + dx * step * sign;
              if (nx < 0 || nx >= 8) break;
              const int ny = y + dy * step * sign;
              if (ny < 0 || ny >= 8) break;
              if (board[ny][nx] != '.') ++pieces_count;
            }
          }
          for (int sign = -1; sign <= 1; sign += 2) {
            const int nx = x + dx * pieces_count * sign;
            if (nx < 0 || nx >= 8) continue;
            const int ny = y + dy * pieces_count * sign;
            if (ny < 0 || ny >= 8) continue;
            if (board[ny][nx] == player[0]) continue;
            bool jumps_opponent = false;
            for (int step = 1; step < pieces_count; ++step) {
              const int bx = x + dx * step * sign;
              assert(0 <= bx && bx < 8);
              const int by = y + dy * step * sign;
              assert(0 <= by && by < 8);
              if (board[by][bx] != player[0] && board[by][bx] != '.') {
                jumps_opponent = true;
                break;
              }
            }
            if (jumps_opponent) continue;
            moves.push_back(ny * 8 + nx);
          }
        }
        if (moves.empty()) continue;
        std::sort(moves.begin(), moves.end());
        for (const int pos : moves) {
          const int ny = pos / 8;
          const int nx = pos % 8;
          std::printf("%c%d-%c%d\n", 'A' + y, x + 1, 'A' + ny, nx + 1);
          has_moves = true;
        }
      }
    }
    if (!has_moves) {
      std::puts("No moves are possible");
    }
  }
};

int main() {
  Game game;
  bool had_output = false;
  while (1) {
    for (int i = 0; i < 8; ++i) {
      if (std::scanf("%s", game.board[i]) != 1) return 0;
    }
    std::scanf("%s", game.player);

    if (had_output) std::putchar('\n');
    game.PrintAllMoves();
    had_output = true;
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
