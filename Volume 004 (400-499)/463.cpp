/* @JUDGE_ID: 19899RK 463 C++11 "By Anadan" */
// Polynomial Factorization
// Accepted (0.010 seconds with low memory spent)

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <vector>

int gcd(int x, int y) {
  if (x < 0) x = -x;
  if (y < 0) y = -y;
  while (x && y) {
    x %= y;
    std::swap(x, y);
  }
  return x + y;
}

class Factorizer {
 public:
  explicit Factorizer(int N) : number(N) {}

  bool GetNextDivisor(int* divisor, const int upper_bound = 0,
                      const int prime_with = 0) {
    if (finished_iteration) return false;
    if (last_divisor == 0) {
      last_divisor = 1;
      *divisor = 1;
      return true;
    }
    if (last_divisor == 1) {
      if (number < 2) {
        finished_iteration = true;
        return false;
      }
      last_divisor = number;
      if ((upper_bound < 1 || last_divisor <= upper_bound) &&
          (prime_with < 2 || gcd(last_divisor, prime_with) == 1)) {
        *divisor = last_divisor;
        return true;
      }
    }
    if (last_divisor == number) {
      if (powers.empty()) DoFactorize();
      current_powers.resize(powers.size(), 0);
      current_factors.resize(powers.size(), 1);
      last_divisor = 1;
    }
    for (int i = 0; i < primes.size(); ++i) {
      if (current_powers[i] < powers[i]) {
        ++current_powers[i];
        current_factors[i] *= primes[i];
        last_divisor *= primes[i];
        if (last_divisor < number &&
            (upper_bound < 1 || last_divisor <= upper_bound) &&
            (prime_with < 2 || gcd(last_divisor, prime_with) == 1)) {
          *divisor = last_divisor;
          return true;
        }
      }
      last_divisor /= current_factors[i];
      current_powers[i] = 0;
      current_factors[i] = 1;
    }
    finished_iteration = true;
    return false;
  }

  void FinishIteration() { finished_iteration = true; }

  void ResetIteration() {
    last_divisor = 0;
    finished_iteration = false;
  }

 private:
  void DoFactorize() {
    int N = number;
    if (N < 2) {
      primes.push_back(2);
      powers.push_back(0);
      return;
    }
    while (!(N & 1)) {
      N >>= 1;
      if (primes.empty()) {
        primes.push_back(2);
        powers.push_back(0);
      }
      ++powers[0];
    }
    for (int p = 3; p <= N / p; p += 2) {
      if (N % p) continue;
      int power = 1;
      N /= p;
      while (!(N % p)) {
        ++power;
        N /= p;
      }
      primes.push_back(p);
      powers.push_back(power);
    }
    if (N > 1) {
      primes.push_back(N);
      powers.push_back(1);
    }
  }

  const int number;
  std::vector<int> primes;
  std::vector<int> powers;
  std::vector<int> current_factors;
  std::vector<int> current_powers;
  int last_divisor = 0;
  bool finished_iteration = false;
};

// Tries to divide a given polynomial by (ax + b).
bool MaybeDivideByFirstDegreePolynomial(int a, int b,
                                        std::vector<int>* coefficients) {
  std::vector<int> result = *coefficients;
  std::reverse(result.begin(), result.end());
  // f(x) = a0 * x^n + a1 * x^(n-1) + a2 * x^(n-2) + ... + an;
  for (int i = 0; i + 1 < result.size(); ++i) {
    // a0 * x^n = (ax + b) * (a0/a) * x^(n-1) - (b*a0/a) * x^(n-1)
    if (result[i] % a) return false;
    result[i] /= a;
    result[i + 1] -= result[i] * b;
  }
  if (result.back() != 0) return false;
  result.pop_back();
  std::reverse(result.begin(), result.end());
  coefficients->swap(result);
  return true;
}

// Factorizes polynomial roots (1st degree polynomials).
// (p/q) is a root <=>
//   1) p divides coefficients[0]
//   2) q divides coefficients.back()
//   3) f(p/q) = 0
//   4) f(+1)/(p-q) is an integer
//   5) f(-1)/(p+q) is an integer
std::vector<std::vector<int>> FactorizePolynomialRoots(
    std::vector<int> coefficients) {
  std::vector<std::vector<int>> results;
  // Force precondition: power_coefficient != 0.
  while (!coefficients.empty() && coefficients.back() == 0) {
    coefficients.pop_back();
  }
  // Force precondition: free_coefficient != 0.
  for (int i = 0; i < coefficients.size(); ++i) {
    if (!coefficients[i]) continue;
    if (i) {
      std::rotate(coefficients.begin(), coefficients.begin() + i,
                  coefficients.end());
      while (i > 0) {
        results.push_back({0, 1});
        coefficients.pop_back();
        --i;
      }
    }
    break;
  }

  while (!coefficients.empty()) {
    const int size = coefficients.size();
    if (size == 1) {
      assert(!results.empty());
      results.back()[0] *= coefficients[0];
      results.back()[1] *= coefficients[0];
      break;
    }
    // Trivial case: Linear function.
    if (size == 2) {
      results.push_back(std::move(coefficients));
      break;
    }
    // Fast case: Quadratic function.
    if (size == 3) {
      // f(x) = a*x^2 + b*x + c
      const int a = coefficients[2];
      const int b = coefficients[1];
      const int c = coefficients[0];
      const int D = b * b - 4 * a * c;
      if (D < 0) {
        results.push_back(std::move(coefficients));
        break;
      }
      const int sqrt_d = (int)(std::sqrt(D) + 0.5);
      if ((sqrt_d * sqrt_d) != D) {
        results.push_back(std::move(coefficients));
        break;
      }
      int p1 = -b - sqrt_d;
      int q1 = 2 * a;
      int p2 = -b + sqrt_d;
      int q2 = q1;
      if (a < 0) {
        p1 = -p1;
        p2 = -p2;
        q2 = q1 = -q1;
      }
      int d1 = gcd(p1, q1);
      p1 /= d1;
      q1 /= d1;
      int d2 = gcd(p2, q2);
      p2 /= d2;
      q2 /= d2;
      results.push_back({-p1, q1});
      results.push_back({-p2, q2});
      break;
    }

    int f1plus = 0;   // f(1)
    int f1minus = 0;  // f(-1)
    for (int i = 0; i < size; ++i) {
      f1plus += coefficients[i];
      f1minus += coefficients[i] * ((i & 1) ? -1 : 1);
    }
    if (f1plus == 0) {
      // Divide by (x - 1).
      results.push_back({-1, 1});
      assert(MaybeDivideByFirstDegreePolynomial(1, -1, &coefficients));
      continue;
    }
    if (f1minus == 0) {
      // Divide by (x + 1).
      results.push_back({1, 1});
      assert(MaybeDivideByFirstDegreePolynomial(1, 1, &coefficients));
      continue;
    }
    int p = 1;
    int q = 1;
    const int abs_power_coefficient = std::abs(coefficients.back());
    const int abs_free_coefficient = std::abs(coefficients[0]);
    Factorizer factorizer_q(abs_power_coefficient);
    Factorizer factorizer_p(abs_free_coefficient);
    while (factorizer_q.GetNextDivisor(&q)) {
      factorizer_p.ResetIteration();
      while (factorizer_p.GetNextDivisor(&p, 0, q)) {
        if (p == q) continue;
        // Try: +(p/q).
        if (!(f1plus % (p - q)) && !(f1minus % (p + q)) &&
            MaybeDivideByFirstDegreePolynomial(q, -p, &coefficients)) {
          results.push_back({-p, q});
          factorizer_q.FinishIteration();
          factorizer_p.FinishIteration();
          break;
        }
        // Try: -(p/q).
        if (!(f1plus % (p + q)) && !(f1minus % (p - q)) &&
            MaybeDivideByFirstDegreePolynomial(q, p, &coefficients)) {
          results.push_back({p, q});
          factorizer_q.FinishIteration();
          factorizer_p.FinishIteration();
          break;
        }
      }
    }
    if (coefficients.size() == size) {
      // Could not extract a polynomial root.
      results.push_back(std::move(coefficients));
      break;
    }
  }
  return results;
}

std::vector<std::vector<int>> Factorize4thDegreePolynomial(
    std::vector<int> coefficients) {
  if (coefficients.size() != 5) return {std::move(coefficients)};
  // f(x) = a*x^4 + b*x^3 + c*x^2 + d*x + e
  // f(x) = (a1*x^2 + b1*x + c1) * (a2*x^2 + b2*x + c2)
  // a1 <= a2, a1^2 <= a
  const int a = coefficients[4];
  const int b = coefficients[3];
  const int c = coefficients[2];
  const int d = coefficients[1];
  const int e = coefficients[0];
  const int abs_a = std::abs(a);
  const int abs_e = std::abs(e);
  const int sqrt_abs_a = (int)(std::sqrt(abs_a) + 0.5);

  // Fast case: Quadratic function 1.
  if (b == 0 && d == 0) {
    // t = x^2
    // f(t) = a*t^2 + c*t + e
    std::vector<std::vector<int>> results = FactorizePolynomialRoots({e, c, a});
    if (results.size() == 1) return {std::move(coefficients)};
    for (auto& coeff : results) {
      coeff.insert(coeff.begin() + 1, 0);
    }
    return results;
  }

  // Fast case: Quadratic function 2.
  if (b == d && a == e) {
    // t = x + 1/x
    // f(t) = a*t^2 + b*t + (c - 2*a)
    std::vector<std::vector<int>> results =
        FactorizePolynomialRoots({c - 2 * a, b, a});
    if (results.size() == 1) return {std::move(coefficients)};
    for (auto& coeff : results) {
      coeff.insert(coeff.begin(), coeff[1]);
    }
    return results;
  }

  // Fast case: Quadratic function 3.
  // f(x) = (a1*x^2 + b1*x + c1) ^ 2
  if (e > 0 && !(b & 1) && !(d & 1) && (sqrt_abs_a * sqrt_abs_a) == a) {
    const int a1 = sqrt_abs_a;
    int b1 = (b >> 1);
    if (!(b1 % a1)) {
      b1 /= a1;
      const int c1 = (int)(std::sqrt(abs_e) + 0.5);
      if ((c1 * c1) == e && d == 2 * b1 * c1 && c == b1 * b1 + 2 * a1 * c1) {
        return {{c1, b1, a1}, {c1, b1, a1}};
      }
    }
  }

  Factorizer factorizer_a(abs_a);
  Factorizer factorizer_e(abs_e);
  int a1;
  while (factorizer_a.GetNextDivisor(&a1, sqrt_abs_a)) {
    const int a2 = a / a1;
    const int gcd_a = gcd(a1, a2);
    if (b % gcd_a) continue;
    const int da1 = d * a1;
    const int da2 = d * a2;
    int c1;
    factorizer_e.ResetIteration();
    while (factorizer_e.GetNextDivisor(&c1)) {
      int c2 = e / c1;
      const int gcd_c = gcd(c1, c2);
      if (d % gcd_c) continue;
      // Try both: e = c1*c2 and e = (-c1)*(-c2)
      // b1 * (a2*c1 - a1*c2) = b*c1 - d*a1
      // b2 * (a2*c1 - a1*c2) = d*a2 - b*c2
      // b1 * b2 = c - (a2*c1 + a1*c2)
      // a1 * b2 + a2 * b1 = b
      int a2c1 = a2 * c1;
      int a1c2 = a1 * c2;
      int bc1 = b * c1;
      int bc2 = b * c2;
      for (int sign = 0; sign < 2; ++sign) {
        c1 = -c1;
        c2 = -c2;
        a2c1 = -a2c1;
        a1c2 = -a1c2;
        bc1 = -bc1;
        bc2 = -bc2;
        if (a2c1 == a1c2) {
          if (bc1 != da1 || bc2 != da2) continue;
          const int b1b2 = c - a2c1 - a1c2;
          if (b1b2 == 0) {
            // Case 1: b1 == 0
            if (!(b % a1)) {
              const int b1 = 0;
              const int b2 = b / a1;
              return {{c1, b1, a1}, {c2, b2, a2}};
            }
            // Case 2: b2 == 0
            if (!(b % a2)) {
              const int b1 = b / a2;
              const int b2 = 0;
              return {{c1, b1, a1}, {c2, b2, a2}};
            }
          } else {
            // a1 * b2^2 - b * b2 + a2 * b1b2 = 0
            const int D = b * b - 4 * a * b1b2;
            if (D < 0) continue;
            int sqrt_d = (int)(std::sqrt(D) + 0.5);
            if ((sqrt_d * sqrt_d) != D) continue;
            // b2 = (b ± sqrt_d) / (2*a1)
            // b1 = (b - a1 * b2) / a2
            const int q = a1 * 2;
            for (int root = 0; root < 2; ++root) {
              sqrt_d = -sqrt_d;
              if ((b + sqrt_d) % q) continue;
              const int b2 = (b + sqrt_d) / q;
              int b1 = b - a1 * b2;
              if (b1 % a2) continue;
              b1 /= a2;
              return {{c1, b1, a1}, {c2, b2, a2}};
            }
          }
        } else {
          const int q = a2c1 - a1c2;
          if ((bc1 - da1) % q) continue;
          if ((da2 - bc2) % q) continue;
          const int b1 = (bc1 - da1) / q;
          const int b2 = (da2 - bc2) / q;
          const int b1b2 = c - a2c1 - a1c2;
          if ((b1 * b2) == b1b2) {
            return {{c1, b1, a1}, {c2, b2, a2}};
          }
        }
      }
    }
  }
  return {std::move(coefficients)};
}

std::vector<std::vector<int>> FactorizePolynomial(
    std::vector<int> coefficients) {
  int common_gcd = 0;
  for (int i = 0; i < coefficients.size(); ++i) {
    common_gcd = gcd(common_gcd, coefficients[i]);
  }
  if (common_gcd > 1) {
    for (int i = 0; i < coefficients.size(); ++i) {
      coefficients[i] /= common_gcd;
    }
  }

  std::vector<std::vector<int>> results =
      FactorizePolynomialRoots(std::move(coefficients));

  // Try to factorize a 4th degree polynomial into two 2nd degrees.
  if (results.size() == 1) {
    results = Factorize4thDegreePolynomial(std::move(results[0]));
  }

  std::sort(results.begin(), results.end(),
            [](const std::vector<int>& p1, const std::vector<int>& p2) {
              if (p1.size() != p2.size()) {
                return p1.size() < p2.size();
              }
              for (int i = p1.size() - 1; i >= 0; --i) {
                if (p1[i] != p2[i]) {
                  return p1[i] < p2[i];
                }
              }
              return true;
            });
  if (common_gcd > 1) {
    auto& last = results.back();
    for (int i = 0; i < last.size(); ++i) {
      last[i] *= common_gcd;
    }
  }
  return results;
}

int main() {
  while (1) {
    std::vector<int> coefficients;
    coefficients.reserve(5);
    for (int i = 0; i < 5; ++i) {
      int x = 0;
      if (std::scanf("%d", &x) != 1) return 0;
      coefficients.push_back(x);
    }
    std::reverse(coefficients.begin(), coefficients.end());

    auto results = FactorizePolynomial(std::move(coefficients));
    for (auto& coeff : results) {
      std::reverse(coeff.begin(), coeff.end());
      for (int i = 0; i < coeff.size(); ++i) {
        if (i) std::putchar(' ');
        std::printf("%d", coeff[i]);
      }
      std::puts("");
    }
    std::puts("");
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
