/* @JUDGE_ID: 19899RK 246 C++11 "By Anadan" */
// 10-20-30
// Accepted (0.000 seconds with low memory spent)

#include <cstdio>
#include <deque>
#include <string>
#include <unordered_set>
#include <vector>

std::string GetStateKey(int index, const std::vector<std::deque<int>>& piles,
                        const std::deque<int>& deck) {
  std::string result;
  result.reserve(52 + piles.size());
  for (int i = 0; i < piles.size(); ++i) {
    int j = (index + i) % piles.size();
    if (piles[j].empty()) continue;
    for (int value : piles[j]) result.push_back(value);
    result.push_back(42);
  }
  for (int value : deck) result.push_back(value);
  return result;
}

void solve(std::deque<int>& deck, int* win, int* deals) {
  std::vector<std::deque<int>> piles(7);
  int piles_cards = 0;
  *deals = 0;
  for (int i = 0; i < piles.size(); ++i) {
    piles[i].push_back(deck.front());
    deck.pop_front();
    ++piles_cards;
    ++(*deals);
  }
  int index = 0, i, j, k, sum;
  std::unordered_set<std::string> visited;
  while (piles_cards && !deck.empty()) {
    while (piles[index].empty()) {
      if (++index == piles.size()) index = 0;
    }

    std::string key = GetStateKey(index, piles, deck);
    if (visited.count(key)) break;
    visited.insert(std::move(key));

    auto& pile = piles[index];
    pile.push_back(deck.front());
    deck.pop_front();
    ++piles_cards;
    ++(*deals);

    while (pile.size() >= 3) {
      i = 0;
      j = 1;
      k = pile.size() - 1;
      sum = pile[i] + pile[j] + pile[k];
      if (sum == 10 || sum == 20 || sum == 30) {
        piles_cards -= 3;
        deck.push_back(pile[i]);
        deck.push_back(pile[j]);
        deck.push_back(pile[k]);
        pile.pop_front();
        pile.pop_front();
        pile.pop_back();
        continue;
      }

      i = 0;
      j = pile.size() - 2;
      k = pile.size() - 1;
      sum = pile[i] + pile[j] + pile[k];
      if (sum == 10 || sum == 20 || sum == 30) {
        piles_cards -= 3;
        deck.push_back(pile[i]);
        deck.push_back(pile[j]);
        deck.push_back(pile[k]);
        pile.pop_front();
        pile.pop_back();
        pile.pop_back();
        continue;
      }

      i = pile.size() - 3;
      j = pile.size() - 2;
      k = pile.size() - 1;
      sum = pile[i] + pile[j] + pile[k];
      if (sum == 10 || sum == 20 || sum == 30) {
        piles_cards -= 3;
        deck.push_back(pile[i]);
        deck.push_back(pile[j]);
        deck.push_back(pile[k]);
        pile.pop_back();
        pile.pop_back();
        pile.pop_back();
        continue;
      }
      break;
    }
    if (pile.empty()) visited.clear();
    if (++index == piles.size()) index = 0;
  }
  if (piles_cards == 0) {
    *win = 1;
  } else if (deck.empty()) {
    *win = -1;
  } else {
    *win = 0;
  }
}

int main() {
  int x, win, deals;
  std::deque<int> deck;
  while (1) {
    deck.clear();
    for (int i = 0; i < 52; ++i) {
      if (std::scanf("%d", &x) != 1 || x == 0) return 0;
      deck.push_back(x);
    }
    solve(deck, &win, &deals);
    if (win == 0) {
      printf("Draw: %d\n", deals);
    } else if (win > 0) {
      printf("Win : %d\n", deals);
    } else {
      printf("Loss: %d\n", deals);
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
