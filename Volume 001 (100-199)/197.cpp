/* @JUDGE_ID: 19899RK 197 C++11 "By Anadan" */
// Cube
// Accepted (0.540 seconds without precalculation solution)
// Generates precalculated solution of size 320K (but over 40K are not accepted)

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <set>
#include <string>
#include <vector>

std::string Transform(const int transformed[27], const std::string& cube) {
  std::string result(cube.size(), '*');
  for (int i = 0; i < cube.size(); ++i) {
    const int old_i = transformed[i] - 1;
    result[i] = cube[old_i];
  }
  return result;
}

// Rotates back over X-axis:
//
// {1 2 3}     {7 8 9}
// {4 5 6}  => {16 17 18}
// {7 8 9}     {25 26 27}
//
// {10 11 12}      {4 5 6}
// {13 14 15}  =>  {13 14 15}
// {16 17 18}      {22 23 24}
//
// {19 20 21}      {1 2 3}
// {22 23 24}  =>  {10 11 12}
// {25 26 27}      {19 20 21}
std::string RotateX(const std::string& cube) {
  constexpr int transformed[27] = {7, 8, 9, 16, 17, 18, 25, 26, 27,
                                   4, 5, 6, 13, 14, 15, 22, 23, 24,
                                   1, 2, 3, 10, 11, 12, 19, 20, 21};
  return Transform(transformed, cube);
}

// Rotates left over Y-axis:
//
// {1 2 3}     {3 6 9}
// {4 5 6}  => {2 5 8}
// {7 8 9}     {1 4 7}
//
// {10 11 12}      {12 15 18}
// {13 14 15}  =>  {11 14 17}
// {16 17 18}      {10 13 16}
//
// {19 20 21}      {21 24 27}
// {22 23 24}  =>  {20 23 26}
// {25 26 27}      {19 22 25}
std::string RotateY(const std::string& cube) {
  constexpr int transformed[27] = {3,  6,  9,  2,  5,  8,  1,  4,  7,
                                   12, 15, 18, 11, 14, 17, 10, 13, 16,
                                   21, 24, 27, 20, 23, 26, 19, 22, 25};
  return Transform(transformed, cube);
}

// Rotates left over Z-axis:
//
// {1 2 3}     {3 12 21}
// {4 5 6}  => {6 15 24}
// {7 8 9}     {9 18 27}
//
// {10 11 12}      {2 11 20}
// {13 14 15}  =>  {5 14 23}
// {16 17 18}      {8 17 26}
//
// {19 20 21}      {1 10 19}
// {22 23 24}  =>  {4 13 22}
// {25 26 27}      {7 16 25}
std::string RotateZ(const std::string& cube) {
  constexpr int transformed[27] = {3, 12, 21, 6, 15, 24, 9, 18, 27,
                                   2, 11, 20, 5, 14, 23, 8, 17, 26,
                                   1, 10, 19, 4, 13, 22, 7, 16, 25};
  return Transform(transformed, cube);
}

void PositionToXYZ(const int pos, int* x, int* y, int* z) {
  *x = pos % 3;
  *y = pos / 9;
  *z = 2 - ((pos % 9) / 3);
}

int XYZToPosition(const int x, const int y, const int z) {
  return y * 9 + (2 - z) * 3 + x;
}

void GetAllTranslations(const std::string& initial,
                        std::vector<std::string>* results) {
  struct Point {
    int x, y, z, pos;
  };
  std::vector<Point> points;
  for (int pos = 0; pos < initial.size(); ++pos) {
    if (initial[pos] != '.') {
      Point point;
      point.pos = pos;
      PositionToXYZ(pos, &point.x, &point.y, &point.z);
      points.push_back(std::move(point));
    }
  }
  for (int dx = -2; dx <= 2; ++dx) {
    for (int dy = -2; dy <= 2; ++dy) {
      for (int dz = -2; dz <= 2; ++dz) {
        std::string translated(initial.size(), '.');
        for (const auto& point : points) {
          const int x = point.x + dx;
          const int y = point.y + dy;
          const int z = point.z + dz;
          if (x < 0 || y < 0 || z < 0 || x > 2 || y > 2 || z > 2) {
            translated.clear();
            break;
          }
          const int pos = XYZToPosition(x, y, z);
          translated[pos] = initial[point.pos];
        }
        if (!translated.empty()) {
          results->push_back(std::move(translated));
        }
      }
    }
  }
}

std::vector<std::string> GetAllRotationsAndTranslations(
    const std::string& initial) {
  std::vector<std::string> results;
  std::string rot_x = initial;
  for (int dx = 0; dx < 4; ++dx) {
    std::string rot_y = rot_x;
    for (int dy = 0; dy < 4; ++dy) {
      std::string rot_z = rot_y;
      for (int dz = 0; dz < 4; ++dz) {
        GetAllTranslations(rot_z, &results);
        rot_z = RotateZ(rot_z);
      }
      rot_y = RotateY(rot_y);
    }
    rot_x = RotateX(rot_x);
  }
  std::sort(results.begin(), results.end());
  results.erase(std::unique(results.begin(), results.end()), results.end());
  return results;
}

int GetNonEmptyPositionsMask(const std::string& piece) {
  int mask = 0;
  for (int pos = 0; pos < piece.size(); ++pos) {
    if (piece[pos] != '.') mask |= (1 << pos);
  }
  return mask;
}

void GenerateCubeAssemblings(
    const std::string& initial,
    const std::vector<std::vector<int>> pieces_positions[6],
    int current_positions[6], int index, int* used_positions,
    std::vector<std::string>* results) {
  while (index < initial.size() && (*used_positions & (1 << index))) ++index;
  if (index == initial.size()) {
    std::string current = initial;
    for (int i = 0; i < 6; ++i) {
      const int piece_positions = current_positions[i];
      for (int pos = 0; pos < initial.size(); ++pos) {
        if (piece_positions & (1 << pos)) {
          current[pos] = 'b' + i;
        }
      }
    }
    results->push_back(current);
    return;
  }
  for (int i = 0; i < 6; ++i) {
    if (current_positions[i]) continue;
    const std::vector<int>& pieces_positions_for_index =
        pieces_positions[i][index];
    for (const int piece_positions : pieces_positions_for_index) {
      if (piece_positions & *used_positions) continue;
      current_positions[i] = piece_positions;
      *used_positions ^= piece_positions;
      GenerateCubeAssemblings(initial, pieces_positions, current_positions,
                              index + 1, used_positions, results);
      *used_positions ^= piece_positions;
      current_positions[i] = 0;
    }
  }
}

void GeneratePrecalculatedSolution(
    const std::vector<std::vector<int>> pieces_positions[6]) {
  struct PrecalcSolution {
    std::vector<std::string> initials;
    std::vector<std::string> cubes;
  };

  std::fprintf(stderr, "Generating precalculated solution!\n");
  const std::vector<std::string> initial_pieces =
      GetAllRotationsAndTranslations("aa.a..a....................");
  std::fprintf(stderr, "Total initial positions: %lu\n", initial_pieces.size());

  std::set<std::string> processed;
  std::vector<PrecalcSolution> solutions;
  for (const std::string& initial_piece : initial_pieces) {
    if (processed.count(initial_piece)) continue;
    std::fprintf(stderr, "Generating solution for: %s\n",
                 initial_piece.c_str());

    PrecalcSolution precalc;
    GetAllTranslations(initial_piece, &precalc.initials);
    for (const std::string& initial : precalc.initials) {
      processed.insert(initial);
      int positions = GetNonEmptyPositionsMask(initial);
      int piece_index[6] = {0};
      GenerateCubeAssemblings(initial, pieces_positions, piece_index, 0,
                              &positions, &precalc.cubes);
    }
    std::sort(precalc.initials.begin(), precalc.initials.end());
    std::sort(precalc.cubes.begin(), precalc.cubes.end());
    solutions.push_back(std::move(precalc));
  }

  std::puts(R"(
    #include <cstdio>
    #include <set>
    #include <string>
    #include <vector>
    int main() {
    const std::vector<std::set<std::string>> kInitials = {
  )");
  for (int i = 0; i < solutions.size(); ++i) {
    if (i) std::puts(",\n");
    const auto& solution = solutions[i];
    std::puts("  {");
    for (int j = 0; j < solution.initials.size(); ++j) {
      if (j) std::puts(", ");
      std::printf("\"%s\"", solution.initials[j].c_str());
    }
    std::puts("}");
  }
  std::puts(R"(
    };
    const char* kAnswers[] = {
  )");
  for (int i = 0; i < solutions.size(); ++i) {
    if (i) std::puts(",\n");
    const auto& solution = solutions[i];
    std::string solution_string;
    for (int j = 0; j < solution.cubes.size(); ++j) {
      solution_string += solution.cubes[j] + '\n';
    }
    std::printf("R\"(%s)\"", solution_string.c_str());
  }
  std::puts(R"(
    };
    char buffer[32];
    while (std::scanf("%s", buffer) == 1) {
      std::string initial = buffer;
      for (int i = 0; i < kInitials.size(); ++i) {
        if (kInitials[i].count(initial)) {
          std::puts(kAnswers[i]);
          break;
        }
      }
    }
    return 0;
    }
  )");
}

int main(int argc, char** argv) {
  char buffer[32];

  // Self test.
  for (int i = 0; i < 27; ++i) {
    int x, y, z;
    PositionToXYZ(i, &x, &y, &z);
    assert(0 <= x && x < 3);
    assert(0 <= y && y < 3);
    assert(0 <= z && z < 3);
    assert(i == XYZToPosition(x, y, z));
  }

  const char* pieces_initial[6] = {
      "bb.b.......................", "ccc.c......................",
      "d..dd..d...................", "ee.e.....e.................",
      ".f.ff.....f................", ".g.gg.......g..............",
  };
  std::vector<std::vector<int>> pieces_positions[6];
  for (int i = 0; i < 6; ++i) {
    const std::vector<std::string> pieces =
        GetAllRotationsAndTranslations(pieces_initial[i]);
    pieces_positions[i].resize(27);
    for (const auto& piece : pieces) {
      int mask = GetNonEmptyPositionsMask(piece);
      for (int index = 0; index < pieces_positions[i].size(); ++index) {
        if (mask & (1 << index)) {
          pieces_positions[i][index].push_back(mask);
        }
      }
    }
  }

  if (argc > 1 && std::string(argv[1]) == "--generate_precalc") {
    GeneratePrecalculatedSolution(pieces_positions);
    return 1;
  }

  while (std::scanf("%s", buffer) == 1) {
    std::vector<std::string> initials;
    GetAllTranslations(buffer, &initials);

    std::vector<std::string> cubes;
    for (const std::string& initial : initials) {
      int positions = GetNonEmptyPositionsMask(initial);
      int piece_index[6] = {0};
      GenerateCubeAssemblings(initial, pieces_positions, piece_index, 0,
                              &positions, &cubes);
    }

    for (const std::string& cube : cubes) {
      std::puts(cube.c_str());
    }
    std::puts("");
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

