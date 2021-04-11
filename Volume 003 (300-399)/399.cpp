/* @JUDGE_ID: 19899RK 399 C++11 "By Anadan" */
// Another Puzzling Problem
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <vector>

struct Piece {
  char image[32][32];
  // top, left, bottom, right
  int edges[4];
};

struct Puzzle {
  std::vector<Piece> pieces;
  int dimension, height, width;

  mutable std::vector<int> arranged;
  mutable std::vector<bool> used;

  bool Solve(int row, int column, int index) const {
    const int size = pieces.size();
    if (index == size) return true;
    if (column >= dimension) {
      column = 0;
      ++row;
    }
    for (int i = 0; i < size; ++i) {
      if (used[i]) continue;
      const Piece& piece = pieces[i];
      const int top =
          (row == 0) ? 0 : -pieces[arranged[index - dimension]].edges[2];
      if (piece.edges[0] != top) continue;
      const int left =
          (column == 0) ? 0 : -pieces[arranged[index - 1]].edges[3];
      if (piece.edges[1] != left) continue;
      if (row == dimension - 1 && piece.edges[2] != 0) continue;
      if (column == dimension - 1 && piece.edges[3] != 0) continue;

      used[i] = true;
      arranged[index] = i;
      if (Solve(row, column + 1, index + 1)) return true;
      used[i] = false;
    }
    return false;
  }

  void Solve() const {
    const int size = pieces.size();
    arranged.resize(size);
    used.clear();
    used.resize(size, false);
    Solve(0, 0, 0);
  }

  void Print() const {
    for (int i = 0; i < dimension; ++i) {
      for (int row = 0; row < height; ++row) {
        for (int j = 0, index = i * dimension; j < dimension; ++j, ++index) {
          const Piece& piece = pieces[arranged[index]];
          std::printf("%s", piece.image[row]);
        }
        std::putchar('\n');
      }
    }
  }
};

void ReadUntilEOL() {
  while (1) {
    int x = std::getchar();
    if (x == EOF || x == '\n') break;
  }
}

int main() {
  int testcases;
  Puzzle puzzle;

  std::scanf("%d", &testcases);
  ReadUntilEOL();
  while (testcases-- > 0) {
    std::scanf("%d%d%d", &puzzle.dimension, &puzzle.height, &puzzle.width);
    const int size = puzzle.dimension * puzzle.dimension;
    puzzle.pieces.resize(size);
    ReadUntilEOL();
    for (int k = 0; k < size; ++k) {
      Piece& piece = puzzle.pieces[k];
      for (int i = 0; i < puzzle.height; ++i) {
        std::fgets(piece.image[i], sizeof(piece.image[i]), stdin);
        assert(piece.image[i][puzzle.width] == '\n');
        piece.image[i][puzzle.width] = 0;
      }
      for (int i = 0; i < 4; ++i) {
        std::scanf("%d", &piece.edges[i]);
      }
      ReadUntilEOL();
      ReadUntilEOL();
    }

    puzzle.Solve();
    puzzle.Print();

    if (testcases) std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
