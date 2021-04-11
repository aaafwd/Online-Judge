/* @JUDGE_ID: 19899RK 294 C++ "By Anadan" */
// Divisors
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int odd_primes[3424];

int GetDivisorsCount(int a) {
  int res = 1, cur = 1;

  while (!(a & 1)) {
    a >>= 1;
    cur++;
  }
  res *= cur;

  for (int i = 0; odd_primes[i] <= a / odd_primes[i]; ++i) {
    const int p = odd_primes[i];
    if (!(a % p)) {
      cur = 1;
      do {
        a /= p;
        cur++;
      } while (!(a % p));
      res *= cur;
    }
  }
  if (a > 1) res <<= 1;
  return res;
}

void Init() {
  // Precalc all odd primes till sqrt(1000000000).
  const int kMax = 1000000000;
  int count = 0;
  for (int x = 3;; x += 2) {
    bool is_prime = true;
    for (int k = 3; k <= x / k; k += 2) {
      if (!(x % k)) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) {
      odd_primes[count++] = x;
      if (x * x > kMax) break;
    }
  }
}

int main() {
  Init();
  int N, L, U, num;
  scanf("%d", &N);
  while (N--) {
    scanf("%d%d", &L, &U);
    int max = 0;
    int current = (L * 2 < U) ? U / 2 : L;
    for (; current <= U; ++current) {
      const int count = GetDivisorsCount(current);
      if (max < count) {
        max = count;
        num = current;
      }
    }
    printf("Between %d and %d, %d has a maximum of %d divisors.\n", L, U, num,
           max);
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */

