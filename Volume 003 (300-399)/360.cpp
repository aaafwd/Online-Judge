/* @JUDGE_ID: 19899RK 360 C++11 "By Anadan" */
// Don’t Get Hives From This One!
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdio>
#include <vector>

struct Position {
  int room, wall;

  bool operator==(const Position& other) const {
    return room == other.room && wall == other.wall;
  }
};

// Hexagonal maze.
//    0
//    __
// 5 /  \ 1
// 4 \  / 2
//    ￣
//    3
class Maze {
 public:
  Maze(const int rows, const int columns)
      : rows_(rows), columns_(columns), nodes_((rows * columns + 1) / 2, 0) {}

  void AddOpenWall(const int room, const int wall) {
    assert(room < nodes_.size());
    assert(0 <= wall && wall < 6);
    assert(!HasOpenWall(room, wall));
    nodes_[room] |= (1 << wall);
  }

  bool HasOpenWall(const int room, const int wall) const {
    assert(room < nodes_.size());
    assert(0 <= wall && wall < 6);
    return (nodes_[room] & (1 << wall)) != 0;
  }

  void Traverse(const Position& start, const Position& end,
                std::vector<int>* path, bool* reached_destination) const {
    path->clear();
    Position pos = start;
    while (1) {
      path->push_back(pos.room);
      do {
        --pos.wall;
        if (pos.wall < 0) pos.wall += 6;
      } while (!HasOpenWall(pos.room, pos.wall));
      if (pos == start) {
        *reached_destination = false;
        break;
      }
      if (pos == end) {
        *reached_destination = true;
        break;
      }
      WalkToNextRoom(&pos);
    }
  }

  void WalkToNextRoom(Position* pos) const {
    int row, column;
    RoomToRowColumn(pos->room, &row, &column);
    switch (pos->wall) {
      case 0:
        row -= 2;
        break;
      case 1:
        row -= 1;
        column += 1;
        break;
      case 2:
        row += 1;
        column += 1;
        break;
      case 3:
        row += 2;
        break;
      case 4:
        row += 1;
        column -= 1;
        break;
      case 5:
        row -= 1;
        column -= 1;
        break;
      default:
        assert(0 <= pos->wall && pos->wall < 6);
        break;
    }
    RowColumnToRoom(row, column, &pos->room);

    // Invert direction of the wall.
    if (pos->wall < 3) {
      pos->wall += 3;
    } else {
      pos->wall -= 3;
    }
  }

  void RoomToRowColumn(const int room, int* row, int* column) const {
    const int full_rows = (room / columns_) * 2;
    int offset_room = room - (full_rows * columns_ + 1) / 2;
    assert(offset_room >= 0);
    *row = full_rows;
    if (offset_room > (columns_ - 1) / 2) {
      ++(*row);
      offset_room -= (columns_ + 1) / 2;
      *column = 2 * offset_room + 1;
    } else {
      *column = 2 * offset_room;
    }
    assert(0 <= *row && *row < rows_);
    assert(0 <= *column && *column < columns_);
  }

  void RowColumnToRoom(const int row, const int column, int* room) const {
    assert(0 <= row && row < rows_);
    assert(0 <= column && column < columns_);
    *room = (row / 2) * columns_;
    if (row & 1) {
      *room += (columns_ + 1) / 2;
    }
    *room += column / 2;
    assert(0 <= *room && *room < nodes_.size());
  }

 private:
  int rows_;
  int columns_;
  std::vector<int> nodes_;  // Value is a bitmask of open walls for nodes.
};

int main() {
  char buffer[1024];
  int rows, columns, room, wall, offset;
  Position start, end;
  std::vector<int> path;
  bool reached_destination;

  while (std::scanf("%d %d", &rows, &columns) == 2 && rows) {
    Maze maze(rows, columns);
    std::scanf("%d %d %d %d", &start.room, &start.wall, &end.room, &end.wall);
    --start.room;
    --start.wall;
    --end.room;
    --end.wall;
    while (std::scanf("%d", &room) == 1 && room) {
      std::fgets(buffer, sizeof(buffer), stdin);
      --room;
      for (char* ptr = buffer; std::sscanf(ptr, "%d%n", &wall, &offset) == 1;
           ptr += offset) {
        --wall;
        maze.AddOpenWall(room, wall);
      }
    }

    // {
    //   int x, y, nr;
    //   for (int r = 0; r < (rows * columns + 1) / 2; ++r) {
    //     maze.RoomToRowColumn(r, &x, &y);
    //     std::printf("Room %d, row %d, col %d\n", r + 1, x + 1, y + 1);
    //     maze.RowColumnToRoom(x, y, &nr);
    //     assert(r == nr);
    //   }
    // }
    // continue;

    maze.Traverse(start, end, &path, &reached_destination);

    // Output results.
    for (int i = 0; i < path.size(); ++i) {
      if (i) std::putchar((i % 20) ? ' ' : '\n');
      std::printf("%d", path[i] + 1);
    }
    std::putchar('\n');
    if (reached_destination) {
      std::puts("SOLUTION FOUND");
    } else {
      std::puts("NO SOLUTION");
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
