/* @JUDGE_ID: 19899RK 281 C++ "By Anadan" */
// Rubik’s Cube
// Accepted (0.000 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <array>
#include <cassert>
#include <cctype>
#include <cstdio>
#include <set>
#include <vector>

struct Vector {
  int x, y, z;

  const bool operator==(const Vector& vec) const {
    return x == vec.x && y == vec.y && z == vec.z;
  }

  const bool operator!=(const Vector& vec) const {
    return x != vec.x || y != vec.y || z != vec.z;
  }

  const Vector operator*(const int k) const { return {x * k, y * k, z * k}; }

  const Vector operator+(const Vector& vec) const {
    return {x + vec.x, y + vec.y, z + vec.z};
  }
};

const Vector kNorms[6] = {
    //  0           1          2           3          4          5
    {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1},
};

Vector CrossProduct(const Vector& v1, const Vector& v2) {
  // |   i    j    k  |
  // | v1.x v1.y v1.z |
  // | v2.x v2.y v2.z |
  return {v1.y * v2.z - v2.y * v1.z, v2.x * v1.z - v1.x * v2.z,
          v1.x * v2.y - v2.x * v1.y};
}

void DoAsserts(const int k, const int norm, const int pos,
               std::set<int>& cube_positions, std::set<int>& buf_positions) {
  assert(!cube_positions.count(k * 10 + norm));
  cube_positions.insert(k * 10 + norm);
  assert(0 <= pos && pos < 54);
  assert(!buf_positions.count(pos));
  buf_positions.insert(pos);
}

// . . . B B B . . . . . .
// . . . B B B . . . . . .
// . . . B B B . . . . . .
// L L L T T T R R R U U U
// L L L T T T R R R U U U
// L L L T T T R R R U U U
// . . . F F F . . . . . .
// . . . F F F . . . . . .
// . . . F F F . . . . . .
//
//  .  .  .  0  1  2  .  .  .  .  .  .
//  .  .  .  3  4  5  .  .  .  .  .  .
//  .  .  .  6  7  8  .  .  .  .  .  .
//  9 10 11 12 13 14 15 16 17 18 19 20
// 21 22 23 24 25 26 27 28 29 30 31 32
// 33 34 35 36 37 38 39 40 41 42 43 44
//  .  .  . 45 46 47  .  .  .  .  .  .
//  .  .  . 48 49 50  .  .  .  .  .  .
//  .  .  . 51 52 53  .  .  .  .  .  .
std::vector<std::array<int, 54>> GenerateCubePermutations() {
  // {x, y, z}: {0,0,0}, {1,0,0}, {2,0,0}, {0,1,0}, ..., {2,2,0}, ... {2,2,2}
  // index1 [0..26] = z * 9 + y * 3 + x
  // index2 [0..5] = normale vector;
  int input_positions[27][6];
  int x, y, z, k, norm, pos;
#ifndef NDEBUG
  std::set<int> cube_positions, buf_positions;
#endif

  for (int i = 0; i < 27; ++i) {
    for (int j = 0; j < 6; ++j) {
      input_positions[i][j] = -1;
    }
  }

  // Up.
  z = 2;
  norm = 4;
  for (y = 0; y < 3; ++y) {
    for (x = 0; x < 3; ++x) {
      k = z * 9 + y * 3 + x;
      pos = (2 - y) * 3 + x;
      input_positions[k][norm] = pos;
#ifndef NDEBUG
      DoAsserts(k, norm, pos, cube_positions, buf_positions);
#endif
    }
  }

  // Bottom.
  z = 0;
  norm = 5;
  for (y = 0; y < 3; ++y) {
    for (x = 0; x < 3; ++x) {
      k = z * 9 + y * 3 + x;
      pos = 45 + y * 3 + x;
      input_positions[k][norm] = pos;
#ifndef NDEBUG
      DoAsserts(k, norm, pos, cube_positions, buf_positions);
#endif
    }
  }

  // Front.
  y = 0;
  norm = 3;
  for (z = 0; z < 3; ++z) {
    for (x = 0; x < 3; ++x) {
      k = z * 9 + y * 3 + x;
      pos = 12 + (2 - z) * 12 + x;
      input_positions[k][norm] = pos;
#ifndef NDEBUG
      DoAsserts(k, norm, pos, cube_positions, buf_positions);
#endif
    }
  }

  // Back.
  y = 2;
  norm = 2;
  for (z = 0; z < 3; ++z) {
    for (x = 0; x < 3; ++x) {
      k = z * 9 + y * 3 + x;
      pos = 18 + (2 - z) * 12 + (2 - x);
      input_positions[k][norm] = pos;
#ifndef NDEBUG
      DoAsserts(k, norm, pos, cube_positions, buf_positions);
#endif
    }
  }

  // Left.
  x = 0;
  norm = 1;
  for (z = 0; z < 3; ++z) {
    for (y = 0; y < 3; ++y) {
      k = z * 9 + y * 3 + x;
      pos = 9 + (2 - z) * 12 + (2 - y);
      input_positions[k][norm] = pos;
#ifndef NDEBUG
      DoAsserts(k, norm, pos, cube_positions, buf_positions);
#endif
    }
  }

  // Right.
  x = 2;
  norm = 0;
  for (z = 0; z < 3; ++z) {
    for (y = 0; y < 3; ++y) {
      k = z * 9 + y * 3 + x;
      pos = 15 + (2 - z) * 12 + y;
      input_positions[k][norm] = pos;
#ifndef NDEBUG
      DoAsserts(k, norm, pos, cube_positions, buf_positions);
#endif
    }
  }
#ifndef NDEBUG
  assert(cube_positions.size() == 54);
  assert(buf_positions.size() == 54);
#endif

  std::vector<std::array<int, 54>> result;
  result.reserve(24);
  for (int dx = 0; dx < 2; ++dx) {
    for (int dy = 0; dy < 2; ++dy) {
      for (int dz = 0; dz < 2; ++dz) {
        const Vector origin = {dx * 2, dy * 2, dz * 2};
        int axes[3] = {dx, 2 + dy, 4 + dz};
        if (CrossProduct(kNorms[axes[0]], kNorms[axes[1]]) != kNorms[axes[2]]) {
          std::swap(axes[0], axes[1]);
        }
#ifndef NDEBUG
        assert(CrossProduct(kNorms[axes[0]], kNorms[axes[1]]) ==
               kNorms[axes[2]]);
#endif
        for (int rot = 0; rot < 3; ++rot) {
          std::rotate(std::begin(axes), std::begin(axes) + 1, std::end(axes));
          int count = 0;
          std::array<int, 54> permutation;
          for (z = 0; z < 3; ++z) {
            for (y = 0; y < 3; ++y) {
              for (x = 0; x < 3; ++x) {
                const Vector current = origin + kNorms[axes[0]] * x +
                                       kNorms[axes[1]] * y +
                                       kNorms[axes[2]] * z;
                pos = current.z * 9 + current.y * 3 + current.x;
#ifndef NDEBUG
                assert(0 <= current.x && current.x < 3);
                assert(0 <= current.y && current.y < 3);
                assert(0 <= current.z && current.z < 3);
                assert(0 <= pos && pos < 27);
#endif
                for (int i = 0; i < 3; ++i) {
                  int num = axes[i];
                  if (input_positions[pos][num] != -1) {
                    permutation[count++] = input_positions[pos][num];
                  }
                  num ^= 1;
                  if (input_positions[pos][num] != -1) {
                    permutation[count++] = input_positions[pos][num];
                  }
                }
              }
            }
          }
#ifndef NDEBUG
          assert(count == 54);
          assert(std::set<int>(permutation.begin(), permutation.end()).size() ==
                 54);
#endif
          result.push_back(std::move(permutation));
        }
      }
    }
  }
#ifndef NDEBUG
  assert(result.size() == 24);
#endif
  return result;
}

void ApplyPermutation(const std::array<int, 54>& permutation,
                      const std::array<char, 54>& buffer,
                      std::array<char, 54>& result) {
  for (int i = 0; i < 54; ++i) {
    result[i] = buffer[permutation[i]];
  }
}

bool CheckSamePositions(const std::array<char, 54>& buffer,
                        const std::vector<std::vector<int>>& same_positions) {
  for (int i = 0; i < same_positions.size(); ++i) {
    const std::vector<int>& positions = same_positions[i];
    const char ch = buffer[positions[0]];
    for (int j = 1; j < positions.size(); ++j) {
      if (ch != buffer[positions[j]]) return false;
    }
  }
  return true;
}

bool IsSameCubes(const std::vector<std::array<int, 54>>& permutations,
                 const std::array<char, 54>& buf1,
                 const std::array<char, 54>& buf2) {
  std::array<char, 54> buffer;
  std::vector<std::vector<int>> same_positions;
  int char_to_pos[256];

  ApplyPermutation(permutations[0], buf2, buffer);
  for (int i = 0; i < 256; ++i) char_to_pos[i] = -1;
  for (int i = 0; i < 54; ++i) {
    const char ch = buffer[i];
    if (char_to_pos[ch] == -1) {
      char_to_pos[ch] = same_positions.size();
      same_positions.push_back({i});
    } else {
      same_positions[char_to_pos[ch]].push_back(i);
    }
  }
#ifndef NDEBUG
  assert(same_positions.size() == 6);
  for (int i = 0; i < same_positions.size(); ++i) {
    assert(same_positions[i].size() == 9);
  }
#endif

  for (int i = 0; i < permutations.size(); ++i) {
    ApplyPermutation(permutations[i], buf1, buffer);
    if (CheckSamePositions(buffer, same_positions)) return true;
  }
  return false;
}

int GetNonSpaceChar() {
  int x;
  do {
    x = std::getchar();
  } while (x != EOF && std::isspace(x));
  return x;
}

int main() {
  const std::vector<std::array<int, 54>> permutations =
      GenerateCubePermutations();
  std::array<char, 54> buf1, buf2;
  int test_cases, x;
  std::scanf("%d\n", &test_cases);
  while (test_cases--) {
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 12; ++j) {
        x = GetNonSpaceChar();
        if (x != '.') buf1[count1++] = x;
      }
      x = GetNonSpaceChar();
      assert(x == '|');
      for (int j = 0; j < 12; ++j) {
        x = GetNonSpaceChar();
        if (x != '.') buf2[count2++] = x;
      }
    }
    assert(count1 == 54);
    assert(count2 == 54);
    if (IsSameCubes(permutations, buf1, buf2)) {
      std::puts("same");
    } else {
      std::puts("different");
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
