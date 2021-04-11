/* @JUDGE_ID: 19899RK 286 C++ "By Anadan" */
// Dead Or Not – That Is The Question
// Accepted (0.000 seconds with low memory spent)

#include <cstdio>

const int kPawnSteps[2][2] = {{-1, 1}, {1, 1}};
const int kBishopSteps[4][2] = {{-1, 1}, {1, 1}, {-1, -1}, {1, -1}};
const int kRookSteps[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const int kKnightSteps[8][2] = {{1, -2},  {1, 2},  {2, -1},  {2, 1},
                                {-1, -2}, {-1, 2}, {-2, -1}, {-2, 1}};
char board[8][8];

bool IsAttacked(const int x, const int y) {
  // Check for Pawns.
  for (int i = 0; i < 2; ++i) {
    int nx = x + kPawnSteps[i][0];
    if (nx < 0 || nx > 7) continue;
    int ny = y + kPawnSteps[i][1];
    if (ny < 0 || ny > 7) continue;
    if (board[ny][nx] == 'p') return true;
  }

  // Check for Knights.
  for (int i = 0; i < 8; ++i) {
    int nx = x + kKnightSteps[i][0];
    if (nx < 0 || nx > 7) continue;
    int ny = y + kKnightSteps[i][1];
    if (ny < 0 || ny > 7) continue;
    if (board[ny][nx] == 'n') return true;
  }

  // Check for Bishop/Queen/King.
  for (int i = 0; i < 4; ++i) {
    int nx = x;
    int ny = y;
    for (int step = 1; step < 8; ++step) {
      nx += kBishopSteps[i][0];
      if (nx < 0 || nx > 7) break;
      ny += kBishopSteps[i][1];
      if (ny < 0 || ny > 7) break;
      if (board[ny][nx] == 'b' || board[ny][nx] == 'q') return true;
      if (step == 1 && board[ny][nx] == 'k') return true;
      if (board[ny][nx] != ' ') break;
    }
  }

  // Check for Rook/Queen/King.
  for (int i = 0; i < 4; ++i) {
    int nx = x;
    int ny = y;
    for (int step = 1; step < 8; ++step) {
      nx += kRookSteps[i][0];
      if (nx < 0 || nx > 7) break;
      ny += kRookSteps[i][1];
      if (ny < 0 || ny > 7) break;
      if (board[ny][nx] == 'r' || board[ny][nx] == 'q') return true;
      if (step == 1 && board[ny][nx] == 'k') return true;
      if (board[ny][nx] != ' ') break;
    }
  }

  return false;
}

int MakeMove() {
  int x, y;
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      if (board[i][j] == 'K') {
        board[i][j] = ' ';
        x = j;
        y = i;
        i = j = 8;
        break;
      }
    }
  }
  for (int dx = -1; dx <= 1; ++dx) {
    int nx = x + dx;
    if (nx < 0 || nx > 7) continue;
    for (int dy = -1; dy <= 1; ++dy) {
      if (dy == 0 && dx == 0) continue;
      int ny = y + dy;
      if (ny < 0 || ny > 7) continue;
      if (!IsAttacked(nx, ny)) return 1;
    }
  }
  const bool is_king_attacked = IsAttacked(x, y);
  return is_king_attacked ? -1 : 0;
}

int main() {
  char buffer[128];
  while (fgets(buffer, sizeof(buffer), stdin)) {
    if (buffer[0] == '\n') break;
    int count = 0;
    for (int i = 7; i >= 0; --i) {
      for (int j = 0; j < 8; ++j) {
        board[i][j] = buffer[count++];
      }
    }
    int result = MakeMove();
    if (result > 0) {
      std::puts("game is not over");
    } else if (result < 0) {
      std::puts("checkmate");
    } else {
      std::puts("draw");
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
