/* @JUDGE_ID: 19899RK 330 C++11 "By Anadan" */
// Inventory Maintenance
// Accepted (0.020 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <cassert>
#include <cstdint>
#include <cstdio>
#include <cwctype>
#include <map>
#include <string>

struct Item {
  int buy_price, sell_price;
  int quantity = 0;
};
std::map<std::string, Item> inventory;

int ReadInt(int *value) {
  *value = 0;
  int ch;
  do {
    ch = std::getchar();
  } while (std::iswspace(ch));
  for (; (ch ^= '0') <= 9; ch = std::getchar()) *value = (*value) * 10 + ch;
  return ch ^ '0';
}

void ReadPrice(int* price) {
  int ch = ReadInt(price);
  *price *= 100;
  if (ch == '.') {
    int cents = 0;
    int exponent = 0;
    while ((ch = std::getchar() ^ '0') <= 9) {
      cents = cents * 10 + ch;
      ++exponent;
    }
    for (; exponent < 2; ++exponent) cents *= 10;
    for (; exponent > 2; --exponent) cents /= 10;
    *price += cents;
  }
}

void PrintReport(int profit) {
  std::puts("                  INVENTORY REPORT");
  std::puts("Item Name     Buy At      Sell At      On Hand        Value");
  std::puts("---------     ------      -------      -------        -----");
  int total_value = 0;
  for (const auto& kv : inventory) {
    const std::string& name = kv.first;
    const Item& item = kv.second;
    const int value = item.quantity * item.buy_price;
    std::printf("%-14s%3d.%02d%10d.%02d%13d%10d.%02d\n", name.c_str(),
                item.buy_price / 100, item.buy_price % 100,
                item.sell_price / 100, item.sell_price % 100, item.quantity,
                value / 100, value % 100);
    total_value += value;
  }
  std::puts("------------------------");
  std::printf("Total value of inventory                      %10d.%02d\n",
              total_value / 100, total_value % 100);
  if (profit >= 0) {
    std::printf("Profit since last report                      %10d.%02d\n\n",
                profit / 100, profit % 100);
  } else if (profit >= -99) {
    std::printf(
        "Profit since last report                              -0.%02d\n\n",
        -profit);
  } else {
    std::printf("Profit since last report                      %10d.%02d\n\n",
                profit / 100, (-profit) % 100);
  }
}

int main() {
  char buffer[128];
  int profit = 0;
  int quantity;
  while (std::scanf("%s", buffer) == 1 && buffer[0] != '*') {
    if (buffer[0] == 'n') {
      Item item;
      std::scanf("%s", buffer);
      ReadPrice(&item.buy_price);
      ReadPrice(&item.sell_price);
      assert(item.buy_price >= 0);
      assert(item.sell_price >= 0);
      inventory[std::string(buffer)] = item;
    } else if (buffer[0] == 'd') {
      std::scanf("%s", buffer);
      const std::string name(buffer);
      const Item& item = inventory[name];
      const int price = (item.buy_price) * item.quantity;
      profit -= price;
      inventory.erase(name);
    } else if (buffer[0] == 'b') {
      std::scanf("%s%d", buffer, &quantity);
      const std::string name(buffer);
      Item& item = inventory[name];
      item.quantity += quantity;
    } else if (buffer[0] == 's') {
      std::scanf("%s%d", buffer, &quantity);
      const std::string name(buffer);
      Item& item = inventory[name];
      assert(quantity <= item.quantity);
      item.quantity -= quantity;
      profit += (item.sell_price - item.buy_price) * quantity;
    } else if (buffer[0] == 'r') {
      PrintReport(profit);
      profit = 0;
    } else {
      assert(0);
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
