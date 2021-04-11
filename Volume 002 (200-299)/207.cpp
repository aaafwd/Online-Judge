/* @JUDGE_ID: 19899RK 207 C++ "By Anadan" */
// PGA Tour Prize Money
// Accepted (0.000 seconds with low memory spent)

#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <vector>

struct Player {
  char name[24];
  bool amateur = false;
  std::vector<int> scores;
  int total_score = 0;
  int half_score = 0;
};

struct Standing {
  const Player* player;
  bool won = false;
  int money = 0;
  int place = -1;  // DQ
  bool place_tie = false;
};

struct Tournament {
  double prize;
  double prize_ratio[70];
  std::vector<Player> players;
};

void ReadEndLine() {
  while (1) {
    int x = std::getchar();
    if (x == EOF || x == '\n') break;
  }
}

void PrintSpaces(int spaces) {
  while (spaces-- > 0) std::putchar(' ');
}

void PrintNumber(int x, int* chars) {
  if (x < 10) {
    std::putchar('0' + x);
    *chars = 1;
  } else {
    PrintNumber(x / 10, chars);
    std::putchar('0' + (x % 10));
    ++(*chars);
  }
}

void RunTournament(const Tournament& tournament) {
  int size = tournament.players.size();
  std::vector<Standing> standings(size);
  for (int i = 0; i < size; ++i) {
    standings[i].player = &tournament.players[i];
  }
  if (size > 70) {
    std::sort(standings.begin(), standings.end(),
              [](const Standing& st1, const Standing& st2) {
                return st1.player->half_score < st2.player->half_score;
              });
    for (int i = 70; i < size; ++i) {
      if (standings[i].player->half_score !=
          standings[i - 1].player->half_score) {
        standings.resize(size = i);
        break;
      }
    }
  }
  std::sort(standings.begin(), standings.end(),
            [](const Standing& st1, const Standing& st2) {
              const int rd1 = st1.player->scores.size();
              const int rd2 = st2.player->scores.size();
              if ((rd1 != 4 || rd2 != 4) && rd1 != rd2) return rd1 > rd2;
              const int s1 = st1.player->total_score;
              const int s2 = st2.player->total_score;
              if (s1 != s2) return s1 < s2;
              return std::strcmp(st1.player->name, st2.player->name) < 0;
            });
  int win_index = 0;
  for (int i = 0; i < size; ++i) {
    const Player* p1 = standings[i].player;
    int prof_players = 0;
    bool has_wins = false;
    double prize_for_place = 0;
    if (!p1->amateur) {
      ++prof_players;
      if (win_index < 70) {
        has_wins = true;
        prize_for_place += tournament.prize_ratio[win_index++];
      }
    }
    int end = i + 1;
    for (; end < size; ++end) {
      const Player* p2 = standings[end].player;
      if (p2->total_score != p1->total_score) break;
      if (!p2->amateur) {
        ++prof_players;
        if (win_index < 70) {
          has_wins = true;
          prize_for_place += tournament.prize_ratio[win_index++];
        }
      }
    }
    if (has_wins) {
      if (prof_players > 1) prize_for_place /= prof_players;
      prize_for_place *= tournament.prize;
      prize_for_place += 0.5 + 1e-8;
    }
    const int place = i + 1;
    for (; i < end; ++i) {
      Standing& st = standings[i];
      const bool is_profi = !st.player->amateur;
      const bool is_dq = (st.player->scores.size() != 4);
      st.place = is_dq ? -1 : place;
      st.won = is_profi && !is_dq && has_wins;
      st.money = (int)prize_for_place;
      st.place_tie = st.won && (prof_players > 1);
    }
    --i;
  }

  std::puts(
      "Player Name          Place     RD1  RD2  RD3  RD4  TOTAL     Money "
      "Won\n-------------------------------------------------------------------"
      "----");
  int x;
  for (int i = 0; i < size; ++i) {
    const Standing& st = standings[i];
    const Player& player = *st.player;
    std::printf("%s ", player.name);
    int spaces = 10;
    if (st.place != -1) {
      PrintNumber(st.place, &x);
      // std::printf("%d%n", st.place, &x);
      spaces -= x;
      if (st.place_tie) {
        std::putchar('T');
        --spaces;
      }
    }
    PrintSpaces(spaces);
    for (int k = 0; k < 4; ++k) {
      spaces = 5;
      if (k < player.scores.size()) {
        PrintNumber(player.scores[k], &x);
        // std::printf("%d%n", player.scores[k], &x);
        spaces -= x;
      }
      PrintSpaces(spaces);
    }
    spaces = 10;
    if (player.scores.size() == 4) {
      PrintNumber(player.total_score, &x);
      // std::printf("%d%n", player.total_score, &x);
      spaces -= x;
    } else {
      std::putchar('D');
      std::putchar('Q');
      spaces -= 2;
    }
    if (st.won) {
      PrintSpaces(spaces);
      std::printf("$%6d.%02d", st.money / 100, st.money % 100);
    }
    std::putchar('\n');
  }
}

int main() {
  char buffer[64];
  Tournament tournament;
  int test_cases, N, x;
  std::scanf("%d\n", &test_cases);
  tournament.players.reserve(144);
  while (test_cases--) {
    std::scanf("%lf", &tournament.prize);
    for (int i = 0; i < 70; ++i) {
      std::scanf("%lf", tournament.prize_ratio + i);
    }
    std::scanf("%d", &N);
    ReadEndLine();
    tournament.players.clear();
    for (int i = 0; i < N; ++i) {
      std::fgets(buffer, sizeof(buffer), stdin);
      Player player;
      const char* p = buffer + 20;
      for (int k = 0; k < 4; ++k) {
        while (*p && std::isspace(*p)) ++p;
        if ('0' <= *p && *p <= '9') {
          x = 0;
          do {
            x = x * 10 + (*p++ - '0');
          } while ('0' <= *p && *p <= '9');
          player.scores.push_back(x);
          player.total_score += x;
          if (k < 2) player.half_score += x;
          while (*p && !std::isspace(*p)) ++p;
        } else {
          break;
        }
      }
      if (player.scores.size() >= 2) {
        for (int k = 0; k < 20; ++k) {
          player.name[k] = buffer[k];
        }
        for (int k = 19; k > 0; --k) {
          if (buffer[k] == '*') player.amateur = true;
          if (!std::isspace(buffer[k])) break;
        }
        player.name[20] = 0;
        tournament.players.push_back(std::move(player));
      }
    }

    RunTournament(tournament);
    if (test_cases) std::putchar('\n');
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
