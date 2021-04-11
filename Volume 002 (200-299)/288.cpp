/* @JUDGE_ID: 19899RK 288 C++ "By Anadan" */
// Arithmetic Operations With Large Integers
// Accepted (0.000 seconds with low memory spent)

#include <cctype>
#include <cstdio>
#include <iostream>
#include <limits>
#include <ostream>
#include <string>
#include <vector>

//------------------------------------------------------------------------------
/**
 * Signed big integer number class implementation.
 * @version $Revision: 1.3 $, $Date: 30/06/2005 $
 * @author Andrey A. Adaikin <Andrey.Adaikin@gmail.com>
 */
class ABigInt {
 protected:
  /** True, if and only if the number is non-negative. */
  bool positive;

  /** Holds the big integer number representation. */
  std::vector<unsigned int> number;

  /** Base number used in ABigInt representation. Equals to (10^LOG10_BASE). */
  static const unsigned int BASE;

  /** Number of digits kept in one element of std::vector. */
  static const unsigned int LOG10_BASE;

  /** Special value used in the algorithm of multiplication of two ABigInt
   * numbers. */
  static const unsigned int MULTIPLICATIONS_THRESHOLD;

  typedef std::vector<unsigned int>::size_type size_type;

/**
 * Defines 64 bit signed integer type.
 */
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
  typedef __int64 qword;
#else
  typedef long long qword;
#endif

  /**
   * Removes leading zeros.
   * It is assumed there are no leading zeros in ABigInt number representation,
   * and this method is used to maintain this assumption.
   * Complexity: O(N)
   */
  const ABigInt& removeLeadingZeros();

 public:
  // Constructors and destructors

  ABigInt() : positive(true) {}  // zero by default
  ABigInt(const ABigInt& b);
  ABigInt(ABigInt&& b);
  /* explicit */ ABigInt(int x);  // TODO: must be explicit!

  /**
   * Parses signed integer number from the string in decimal notation.
   * Omits leading blanks and parses until the end of the string or
   * the first non-decimal character except the number sign.
   */
  static ABigInt ParseBigInt(const std::string& str);
  static ABigInt ParseBigInt(const char* str, int* num_read = 0);

  virtual ~ABigInt() {}

  void swap(ABigInt& other) {
    using std::swap;
    swap(positive, other.positive);
    swap(number, other.number);
  }

  // Copy assignment operators
  ABigInt& operator=(const ABigInt& other);
  ABigInt& operator=(ABigInt&& other);

  // Unary operators

  const ABigInt operator-() const { return ABigInt(*this).negate(); }

  const ABigInt operator++(int);
  const ABigInt& operator++();
  const ABigInt operator--(int);
  const ABigInt& operator--();

  // Binary operators

  const ABigInt& operator+=(int x);
  const ABigInt& operator-=(int x);
  const ABigInt& operator+=(const ABigInt& b);
  const ABigInt& operator-=(const ABigInt& b);

  const ABigInt operator+(int x) const { return (ABigInt(*this) += x); }
  const ABigInt operator-(int x) const { return (ABigInt(*this) -= x); }
  const ABigInt operator+(const ABigInt& b) const {
    return (ABigInt(*this) += b);
  }
  const ABigInt operator-(const ABigInt& b) const {
    return (ABigInt(*this) -= b);
  }

  /**
   * Binary multiplication operator of two ABigInt numbers.
   * Complexity: O(N^log2(3)) = O(N^1.58)
   * Note: there is a faster algorithm of multiplication of two big numbers
   * using Fast Fourier Transform (FFT) with complexity O(N*log(N)).
   */
  const ABigInt& operator*=(int x);
  const ABigInt& operator/=(int x);
  const ABigInt& operator%=(int x);
  const ABigInt& operator*=(const ABigInt& b);
  const ABigInt& operator/=(const ABigInt& b);
  const ABigInt& operator%=(const ABigInt& b);

  const ABigInt operator*(int x) const { return (ABigInt(*this) *= x); }
  const ABigInt operator/(int x) const { return (ABigInt(*this) /= x); }
  const ABigInt operator%(int x) const { return (ABigInt(*this) %= x); }
  const ABigInt operator*(const ABigInt& b) const {
    return (ABigInt(*this) *= b);
  }
  const ABigInt operator/(const ABigInt& b) const {
    return (ABigInt(*this) /= b);
  }
  const ABigInt operator%(const ABigInt& b) const {
    return (ABigInt(*this) %= b);
  }

  // Comparison operators

  bool operator<(const ABigInt& b) const;
  bool operator>(const ABigInt& b) const { return (b < *this); }
  bool operator>=(const ABigInt& b) const { return !(*this < b); }
  bool operator<=(const ABigInt& b) const { return !(b < *this); }
  bool operator==(const ABigInt& b) const {
    return (positive == b.positive && number == b.number);
  }
  bool operator!=(const ABigInt& b) const {
    return (positive != b.positive || number != b.number);
  }

  bool operator<(int x) const { return (*this < ABigInt(x)); }
  bool operator>(int x) const { return (*this > ABigInt(x)); }
  bool operator>=(int x) const { return (*this >= ABigInt(x)); }
  bool operator<=(int x) const { return (*this <= ABigInt(x)); }
  bool operator==(int x) const { return (*this == ABigInt(x)); }
  bool operator!=(int x) const { return (*this != ABigInt(x)); }

  // Conversion operators

  /**
   * Converts const class ABigInt to integer number.
   * If the number is out of integer limits, the result is undefined.
   */
  operator int() const;  // TODO: Remove this method!

  /**
   * Returns a string representation of this ABigInt number.
   * Complexity: O(N*LOG10_BASE)
   */
  operator std::string() const;

  // Internal methods

  /**
   * Multiplies this number by -1.
   */
  const ABigInt& negate() {
    if (number.size()) {
      positive = !positive;
    }
    return *this;
  }

  /**
   * Reserves the storage memory of std::vector allocated to hold the controlled
   * sequence. Invokes std::vector.reserve(n).
   */
  void reserve(size_type n) { number.reserve(n); }

  /**
   * Returns the size of std::vector allocated to hold the controlled sequence.
   * Invokes std::vector.size().
   */
  size_type size() const { return number.size(); }  // TODO: Remove this method!

  /**
   * Returns true if the number is odd.
   */
  bool isOdd() const { return (number.size() && (number[0] & 1)); }

  /**
   * Returns true if the number is even.
   */
  bool isEven() const { return !isOdd(); }

  /**
   * Multiplies this number by 2.
   * Fast linear algorithm used.
   */
  const ABigInt& mul2();
  /**
   * Divides this number by 2.
   * Fast linear algorithm used.
   */
  const ABigInt& div2();

  /**
   * Multiplies this number by (BASE ^ shift).
   * Complexity: O(N+shift).
   */
  const ABigInt& leftBaseShift(int shift);
  /**
   * Divides this number by (BASE ^ shift).
   * Complexity: O(N).
   */
  const ABigInt& rightBaseShift(int shift);

  /**
   * Calculates the quotient and remainder of this ABigInt number divided by the
   * divisor. If the divisor is zero, the behavior is undefined.
   * Complexity: O(N).
   * Examples:
   *     9 / 6   =  1        9 % 6 =  3
   *    -9 / 6   = -1       -9 % 6 = -3
   *    9 / (-6) = -1     9 % (-6) =  3
   *   -9 / (-6) =  1    -9 % (-6) = -3
   */
  void divide(int divisor, ABigInt& quotient, ABigInt& remainder) const;

  /**
   * Calculates the quotient and remainder of this ABigInt number divided by the
   * divisor. If the divisor is zero, the behavior is undefined.
   * Complexity: O(N*divisor.N*log(BASE)).
   */
  void divide(const ABigInt& divisor, ABigInt& quotient,
              ABigInt& remainder) const;
};

void swap(ABigInt& a, ABigInt& b) { a.swap(b); }

// Binary operators

inline const ABigInt operator+(int x, ABigInt b) { return (b += x); }
inline const ABigInt operator-(int x, ABigInt b) { return -(b -= x); }
inline const ABigInt operator*(int x, ABigInt b) { return (b *= x); }
inline const ABigInt operator/(int x, const ABigInt& b) {
  return (ABigInt(x) /= b);
}
inline const ABigInt operator%(int x, const ABigInt& b) {
  return (ABigInt(x) %= b);
}

inline bool operator==(int x, const ABigInt& b) { return (b == x); }
inline bool operator!=(int x, const ABigInt& b) { return (b != x); }
inline bool operator>=(int x, const ABigInt& b) { return (b <= x); }
inline bool operator<=(int x, const ABigInt& b) { return (b >= x); }
inline bool operator>(int x, const ABigInt& b) { return (b < x); }
inline bool operator<(int x, const ABigInt& b) { return (b > x); }

inline std::ostream& operator<<(std::ostream& os, const ABigInt& b) {
  return (os << std::string(b));
}

// ABigInt applications

/**
 * Returns the absolute value of the given ABigInt number.
 */
inline const ABigInt abs(const ABigInt& b) { return (b < 0) ? (-b) : (b); }

/**
 * Returns the maximal integer number such that its square is not greater
 * than the absolute value of the given ABigInt number.
 * The result is non-negative.
 * Complexity: O(N^2)
 */
const ABigInt sqrt(ABigInt x);

/**
 * Calculates (b ^ exponent).
 * Complexity: O(exponent * exponent.N * b.N)
 */
const ABigInt power(const ABigInt& b, const ABigInt& exponent);

/**
 * Calculates ((b ^ exponent) modulo mod).
 * Complexity: O(mod.N * mod.N * exponent.N * log(BASE))
 */
const ABigInt modPower(const ABigInt& b, const ABigInt& exponent,
                       const ABigInt& mod);

/**
 * Calculates N factorial.
 * Complexity: O(N^2*log(N))
 */
const ABigInt factorial(int N);

const unsigned int ABigInt::BASE = 1000000000;
const unsigned int ABigInt::LOG10_BASE = 9;
const unsigned int ABigInt::MULTIPLICATIONS_THRESHOLD = 100;

ABigInt::ABigInt(int x) {
  if (x >= 0) {
    positive = true;
  } else {
    positive = false;
    x = -x;
  }
  // also handles special case for x = -2147483648
  unsigned int tmp = (unsigned int)x;
  while (tmp) {
    number.push_back(tmp % BASE);
    tmp /= BASE;
  }
}

ABigInt::ABigInt(const ABigInt& b) {
  positive = b.positive;
  number = b.number;
}

ABigInt::ABigInt(ABigInt&& b) {
  positive = b.positive;
  number = std::move(b.number);
}

// static
ABigInt ABigInt::ParseBigInt(const std::string& str) {
  return ParseBigInt(str.c_str());
}

// static
ABigInt ABigInt::ParseBigInt(const char* str, int* num_read) {
  ABigInt result;

  int i, len = 0;
  bool negative = false;
  unsigned int num;
  int read_count = 0;

  result.positive = true;

  while (*str == ' ' || *str == '\t' || *str == '\r' || *str == '\n') ++str;
  if (*str == '-') {
    negative = true;
    ++str;
    ++read_count;
  } else if (*str == '+') {
    ++str;
    ++read_count;
  }

  while ('0' <= str[len] && str[len] <= '9') ++len;
  result.number.reserve((len + LOG10_BASE - 1) / LOG10_BASE);

  read_count += len;
  if (num_read) *num_read = read_count;

  while (len > 0) {
    len -= LOG10_BASE;
    i = (len >= 0) ? (0) : (-len);
    for (num = 0; i < LOG10_BASE; ++i) {
      num = num * 10 + (str[len + i] - '0');
    }
    result.number.push_back(num);
  }

  result.removeLeadingZeros();
  if (negative) result.negate();
  return result;
}

ABigInt& ABigInt::operator=(const ABigInt& other) {
  positive = other.positive;
  number = other.number;
  return *this;
}

ABigInt& ABigInt::operator=(ABigInt&& other) {
  positive = other.positive;
  number = std::move(other.number);
  return *this;
}

const ABigInt ABigInt::operator++(int) {
  ABigInt res(*this);
  ++*this;
  return res;
}

const ABigInt& ABigInt::operator++() {
  if (number.size() == 0) {  // zero
    number.push_back(1);
    positive = true;
  } else if (!positive) {
    positive = true;
    --*this;
    if (number.size()) positive = false;  // for nonzero values
  } else {
    int i;
    for (i = 0; i < number.size(); ++i) {
      if (++number[i] < BASE) break;
      number[i] = 0;
    }
    if (i == number.size()) number.push_back(1);
  }
  return *this;
}

const ABigInt ABigInt::operator--(int) {
  ABigInt res(*this);
  --*this;
  return res;
}

const ABigInt& ABigInt::operator--() {
  if (number.size() == 0) {  // zero
    number.push_back(1);
    positive = false;
  } else if (!positive) {
    positive = true;
    ++*this;
    positive = false;
  } else {
    for (int i = 0; i < number.size(); ++i) {
      if (number[i]) {
        --number[i];
        break;
      }
      number[i] = BASE - 1;
    }
    removeLeadingZeros();
  }
  return *this;
}

const ABigInt& ABigInt::operator+=(int x) {
  if (x == 0) return *this;

  if (positive ^ (x >= 0)) {
    if (x == -x) {  // special case for x = -2147483648
      ++x;
      --*this;
    }
    return (*this -= (-x));
  }

  if (x < 0) x = -x;
  unsigned int rest = (unsigned int)x;

  for (int i = 0; i < number.size() && rest; ++i) {
    rest += number[i];
    if (rest < BASE) {
      number[i] = rest;
      rest = 0;
    } else {
      number[i] = rest % BASE;
      rest /= BASE;
    }
  }

  while (rest) {
    if (rest < BASE) {
      number.push_back(rest);
      rest = 0;
    } else {
      number.push_back(rest % BASE);
      rest /= BASE;
    }
  }
  return *this;
}

const ABigInt& ABigInt::operator-=(int x) {
  if (x == 0) return *this;

  if (positive ^ (x >= 0)) {
    if (x == -x) {  // special case for x = -2147483648
      ++x;
      ++*this;
    }
    return (*this += (-x));
  }
  return (*this -= ABigInt(x));
}

const ABigInt& ABigInt::operator+=(const ABigInt& b) {
  if (b.number.size() == 0) return *this;
  if (number.size() == 0) return (*this = b);

  if (positive ^ b.positive) return (*this -= (-b));

  unsigned int rest = 0;
  int i, minsz = b.number.size();
  if (minsz > number.size()) minsz = number.size();

  for (i = 0; i < minsz; ++i) {
    rest += number[i] + b.number[i];
    if (rest < BASE) {
      number[i] = rest;
      rest = 0;
    } else {
      number[i] = rest % BASE;
      rest /= BASE;
    }
  }

  minsz = number.size();
  for (; i < minsz; ++i) {
    rest += number[i];
    if (rest < BASE) {
      number[i] = rest;
      rest = 0;
    } else {
      number[i] = rest % BASE;
      rest /= BASE;
    }
  }

  minsz = b.number.size();
  for (; i < minsz; ++i) {
    rest += b.number[i];
    if (rest < BASE) {
      number.push_back(rest);
      rest = 0;
    } else {
      number.push_back(rest % BASE);
      rest /= BASE;
    }
  }

  while (rest) {
    if (rest < BASE) {
      number.push_back(rest);
      rest = 0;
    } else {
      number.push_back(rest % BASE);
      rest /= BASE;
    }
  }
  return *this;
}

const ABigInt& ABigInt::operator-=(const ABigInt& b) {
  if (b.number.size() == 0) return *this;
  if (number.size() == 0) return (*this = -b);
  if (*this == b) return (*this = 0);

  if (positive ^ b.positive) return (*this += (-b));

  if (positive) {
    if (*this < b) {
      *this = b - *this;
      return this->negate();
    }
  } else {
    if (b < *this) {
      *this = b - *this;
      return this->negate();
    }
  }

  unsigned int rest = 0, tmp;
  int i, sz = b.number.size();

  for (i = 0; i < sz; ++i) {
    rest += b.number[i];
    if (rest < BASE) {
      if (number[i] >= rest) {
        number[i] -= rest;
        rest = 0;
      } else {
        number[i] += BASE - rest;
        rest = 1;
      }
    } else {
      tmp = rest / BASE;
      rest %= BASE;
      if (number[i] >= rest) {
        number[i] -= rest;
        rest = 0;
      } else {
        number[i] += BASE - rest;
        rest = 1;
      }
      rest += tmp;
    }
  }

  sz = number.size();
  for (; i < sz && rest; ++i) {
    if (rest < BASE) {
      if (number[i] >= rest) {
        number[i] -= rest;
        rest = 0;
      } else {
        number[i] += BASE - rest;
        rest = 1;
      }
    } else {
      tmp = rest / BASE;
      rest %= BASE;
      if (number[i] >= rest) {
        number[i] -= rest;
        rest = 0;
      } else {
        number[i] += BASE - rest;
        rest = 1;
      }
      rest += tmp;
    }
  }

  return this->removeLeadingZeros();
}

const ABigInt& ABigInt::operator*=(int x) {
  if (number.size() == 0 || x == 0) return (*this = 0);
  if (x < 0) {
    negate();
    x = -x;
  }

  unsigned int mul = (unsigned int)x;
  qword rest = 0;

  for (int i = 0; i < number.size(); ++i) {
    rest += qword(number[i]) * mul;
    number[i] = (unsigned int)(rest % BASE);
    rest /= BASE;
  }

  while (rest) {
    if (rest < BASE) {
      number.push_back((unsigned int)(rest));
      break;
    } else {
      number.push_back((unsigned int)(rest % BASE));
      rest /= BASE;
    }
  }
  return *this;
}

const ABigInt& ABigInt::operator/=(int x) {
  ABigInt quotient, remainder;
  divide(x, quotient, remainder);
  return (*this = quotient);
}

const ABigInt& ABigInt::operator%=(int x) {
  ABigInt quotient, remainder;
  divide(x, quotient, remainder);
  return (*this = remainder);
}

const ABigInt& ABigInt::operator*=(const ABigInt& b) {
  int sz = number.size(), bsz = b.number.size();

  if (sz == 0 || bsz == 0) return (*this = 0);
  if (sz >= MULTIPLICATIONS_THRESHOLD && bsz >= MULTIPLICATIONS_THRESHOLD) {
    int power = (sz < bsz) ? (sz) : (bsz);
    bool isPositive = !(positive ^ b.positive);

    positive = true;

    power >>= 1;
    ABigInt x1(*this), y1(*this), x2 = abs(b), y2(x2);
    x1.rightBaseShift(power);
    x2.rightBaseShift(power);
    y1.number.resize(power);
    y2.number.resize(power);

    ABigInt tmp = (x1 + y1) * (x2 + y2);
    x1 *= x2;
    y1 *= y2;
    tmp -= x1 + y1;
    tmp.leftBaseShift(power);
    tmp += y1;

    *this = x1;
    leftBaseShift(power << 1);
    *this += tmp;

    positive = isPositive;
  } else {
    int i, j;
    ABigInt res;
    res.number.resize(sz + bsz);
    res.positive = !(positive ^ b.positive);

    unsigned int mul;
    qword rest;

    for (j = 0; j < bsz; ++j) {
      rest = 0;
      mul = b.number[j];

      for (i = 0; i < sz; ++i) {
        rest += qword(number[i]) * mul + res.number[i + j];
        res.number[i + j] = (unsigned int)(rest % BASE);
        rest /= BASE;
      }

      while (rest) {
        if (rest < BASE) {
          res.number[j + i++] = (unsigned int)(rest);
          break;
        } else {
          res.number[j + i++] = (unsigned int)(rest % BASE);
          rest /= BASE;
        }
      }
    }
    *this = res.removeLeadingZeros();
  }
  return *this;
}

const ABigInt& ABigInt::operator/=(const ABigInt& b) {
  ABigInt quotient, remainder;
  divide(b, quotient, remainder);
  return (*this = quotient);
}

const ABigInt& ABigInt::operator%=(const ABigInt& b) {
  ABigInt quotient, remainder;
  divide(b, quotient, remainder);
  return (*this = remainder);
}

bool ABigInt::operator<(const ABigInt& b) const {
  if (!positive && b.positive) return true;
  if (positive && !b.positive) return false;

  int sz = number.size(), bsz = b.number.size();

  if (positive) {  // if (*this < b)
    if (sz < bsz) {
      return true;
    } else if (sz > bsz) {
      return false;
    }

    for (--sz; sz >= 0; --sz) {
      if (number[sz] < b.number[sz]) {
        return true;
      } else if (number[sz] > b.number[sz]) {
        return false;
      }
    }
  } else {  // if (-*this > -b)
    if (sz < bsz) {
      return false;
    } else if (sz > bsz) {
      return true;
    }

    for (--sz; sz >= 0; --sz) {
      if (number[sz] < b.number[sz]) {
        return false;
      } else if (number[sz] > b.number[sz]) {
        return true;
      }
    }
  }
  return false;
}

ABigInt::operator int() const {
  unsigned int res = 0, mul = 1;

  for (int i = 0; i < number.size(); ++i) {
    res += number[i] * mul;
    mul *= BASE;
  }

  int toRet = (int)res;
  if (!positive) toRet = -toRet;
  return toRet;
}

ABigInt::operator std::string() const {
  int len = number.size() * LOG10_BASE + 1, i, j, pos = 0;
  unsigned int tmp;

  std::string str(len, ' ');
  if (!positive)
    str[pos++] = '-';
  else if (!number.size())
    str[pos++] = '0';

  for (i = 0; i < number.size(); ++i) {
    tmp = number[i];
    for (j = 0; j < LOG10_BASE; ++j) {
      str[pos++] = '0' + tmp % 10;
      tmp /= 10;
    }
  }

  --pos;
  i = (positive) ? (0) : (1);
  while (pos > i && str[pos] == '0') --pos;

  str.resize(pos + 1);
  for (j = pos; i < j; ++i, --j) {
    pos = str[i];
    str[i] = str[j];
    str[j] = pos;
  }
  return str;
}

const ABigInt& ABigInt::mul2() {
  int sz = number.size();
  unsigned int rest = 0;

  for (int i = 0; i < sz; ++i) {
    rest += number[i] << 1;
    if (rest < BASE) {
      number[i] = rest;
      rest = 0;
    } else {
      number[i] = rest - BASE;
      rest = 1;
    }
  }
  if (rest) number.push_back(1);
  return *this;
}

const ABigInt& ABigInt::div2() {
  int sz = number.size();
  unsigned int rest = 0;

  while (sz-- > 0) {
    rest += number[sz];
    number[sz] = rest >> 1;
    rest = (rest & 1) ? (BASE) : (0);
  }
  return this->removeLeadingZeros();
}

const ABigInt& ABigInt::leftBaseShift(int shift) {
  if (shift < 0) {
    if (shift == -shift) ++shift;
    return rightBaseShift(-shift);
  }

  int sz = number.size();
  if (shift == 0 || sz == 0) return *this;

  number.resize(sz + shift);
  for (--sz; sz >= 0; --sz) number[sz + shift] = number[sz];
  for (sz = shift - 1; sz >= 0; --sz) number[sz] = 0;
  return *this;
}

const ABigInt& ABigInt::rightBaseShift(int shift) {
  if (shift < 0) {
    if (shift == -shift) ++shift;
    return leftBaseShift(-shift);
  }

  int sz = number.size();
  if (shift == 0 || sz == 0) return *this;
  if (shift >= sz) return (*this = 0);

  sz -= shift;
  for (int i = 0; i < sz; ++i) number[i] = number[i + shift];
  number.resize(sz);
  return *this;
}

void ABigInt::divide(int divisor, ABigInt& quotient, ABigInt& remainder) const {
  bool quotientPositive = !(positive ^ (divisor > 0));
  bool remainderPositive = positive;

  quotient = remainder = 0;
  if (number.size() == 0) return;

  if (divisor < 0) divisor = -divisor;
  unsigned int div = (unsigned int)divisor;
  qword rest = 0;

  remainder = abs(*this);
  if (remainder >= abs(ABigInt(divisor))) {
    int sz = number.size();

    quotient.number.resize(sz);
    for (int i = sz - 1; i >= 0; --i) {
      rest = rest * BASE + number[i];
      quotient.number[i] = (unsigned int)(rest / div);
      rest %= div;
    }

    remainder = 0;
    while (rest) {
      remainder.number.push_back((unsigned int)(rest % BASE));
      rest /= BASE;
    }

    quotient.removeLeadingZeros();
  }

  if (!quotientPositive) quotient.negate();
  if (!remainderPositive) remainder.negate();
}

void ABigInt::divide(const ABigInt& divisor, ABigInt& quotient,
                     ABigInt& remainder) const {
  quotient = remainder = 0;
  if (number.size() == 0) return;

  const int MIN_INT = std::numeric_limits<int>::min();
  const int MAX_INT = std::numeric_limits<int>::max();
  if (MIN_INT <= divisor && divisor <= MAX_INT) {
    divide(int(divisor), quotient, remainder);
    return;
  }

  bool quotientPositive = !(positive ^ divisor.positive);
  bool remainderPositive = positive;

  remainder = abs(*this);
  if (remainder >= abs(divisor)) {
    int sz = number.size(), divsz = divisor.number.size(), remsz = sz - 1;
    int i, j, qIndex = sz - divsz;
    unsigned int minq, maxq, resq;
    qword rest;

    ABigInt tmp;
    tmp.number.resize(divsz + 1);

    quotient.number.resize(qIndex + 1);

    for (i = sz - 1; i >= divsz - 1; --i, --qIndex) {
      if (remsz == i) {
        for (j = 0; j < divsz; ++j) {
          if (remainder.number[i - j] != divisor.number[divsz - j - 1]) break;
        }

        if (j == divsz) {
          resq = 1;
          for (j = 0; j < divsz; ++j) remainder.number[i - j] = 0;
        } else if (remainder.number[i - j] < divisor.number[divsz - j - 1]) {
          resq = 0;
        } else {
          bool fit;

          minq = 1;
          maxq = (j) ? (1) : (remainder.number[i] / divisor.number[divsz - 1]);
          while (minq <= maxq) {
            resq = (minq + maxq + 1) >> 1;

            rest = 0;
            fit = true;
            for (j = 0; j < divsz; ++j) {
              rest += qword(divisor.number[j]) * resq;
              tmp.number[j] = (unsigned int)(rest % BASE);
              rest /= BASE;
              if (remainder.number[i - (divsz - j - 1)] > tmp.number[j])
                fit = true;
              else if (remainder.number[i - (divsz - j - 1)] < tmp.number[j])
                fit = false;
            }
            if (rest) fit = false;

            if (minq == maxq) break;
            if (!fit)
              maxq = resq - 1;
            else
              minq = resq;
          }

          resq = 0;
          for (j = 0; j < divsz; ++j) {
            resq += tmp.number[j];
            if (resq < BASE) {
              if (remainder.number[i - (divsz - j - 1)] >= resq) {
                remainder.number[i - (divsz - j - 1)] -= resq;
                resq = 0;
              } else {
                remainder.number[i - (divsz - j - 1)] += BASE - resq;
                resq = 1;
              }
            } else {
              maxq = resq / BASE;
              resq %= BASE;
              if (remainder.number[i - (divsz - j - 1)] >= resq) {
                remainder.number[i - (divsz - j - 1)] -= resq;
                resq = 0;
              } else {
                remainder.number[i - (divsz - j - 1)] += BASE - resq;
                resq = 1;
              }
              resq += maxq;
            }
          }
          resq = minq;
        }
        if (remainder.number[remsz] == 0) --remsz;
      } else {
        bool fit;

        rest = qword(remainder.number[i + 1]) * BASE + remainder.number[i];

        minq = (unsigned int)((rest - BASE + divisor.number[divsz - 1]) /
                              divisor.number[divsz - 1]);
        maxq = (unsigned int)(rest / divisor.number[divsz - 1]);
        while (minq <= maxq) {
          resq = (minq + maxq + 1) >> 1;

          rest = 0;
          fit = true;
          for (j = 0; j < divsz; ++j) {
            rest += qword(divisor.number[j]) * resq;
            tmp.number[j] = (unsigned int)(rest % BASE);
            rest /= BASE;
            if (remainder.number[i - (divsz - j - 1)] > tmp.number[j])
              fit = true;
            else if (remainder.number[i - (divsz - j - 1)] < tmp.number[j])
              fit = false;
          }
          tmp.number[j] = (unsigned int)rest;
          if (remainder.number[i + 1] > tmp.number[j])
            fit = true;
          else if (remainder.number[i + 1] < tmp.number[j])
            fit = false;

          if (minq == maxq) break;
          if (!fit)
            maxq = resq - 1;
          else
            minq = resq;
        }

        resq = 0;
        for (j = 0; j < divsz; ++j) {
          resq += tmp.number[j];
          if (resq < BASE) {
            if (remainder.number[i - (divsz - j - 1)] >= resq) {
              remainder.number[i - (divsz - j - 1)] -= resq;
              resq = 0;
            } else {
              remainder.number[i - (divsz - j - 1)] += BASE - resq;
              resq = 1;
            }
          } else {
            maxq = resq / BASE;
            resq %= BASE;
            if (remainder.number[i - (divsz - j - 1)] >= resq) {
              remainder.number[i - (divsz - j - 1)] -= resq;
              resq = 0;
            } else {
              remainder.number[i - (divsz - j - 1)] += BASE - resq;
              resq = 1;
            }
            resq += maxq;
          }
        }
        remainder.number[i + 1] -= resq + tmp.number[j];

        resq = minq;
        if (remainder.number[--remsz] == 0) --remsz;
      }
      quotient.number[qIndex] = resq;
    }
    quotient.removeLeadingZeros();
    remainder.removeLeadingZeros();
  }

  if (!quotientPositive) quotient.negate();
  if (!remainderPositive) remainder.negate();
}

const ABigInt& ABigInt::removeLeadingZeros() {
  int i;
  for (i = number.size() - 1; i >= 0; --i)
    if (number[i]) break;
  number.resize(++i);
  if (i == 0) positive = true;
  return *this;
}

const ABigInt sqrt(ABigInt x) {
  ABigInt a, b(1), aa, ab;

  if (x < 0) x.negate();
  b.leftBaseShift((x.size() + 1) / 2);

  ABigInt bb(b);
  bb *= b;

  while (a != b) {
    if (a.isOdd() ^ b.isOdd()) {
      bb -= b + b - 1;
      --b;
      if (bb <= x) break;
      ab -= a;
    }

    ABigInt c(a);
    c += b;
    c.div2();

    ABigInt cc(ab);
    cc.mul2();
    cc += aa;
    cc += bb;
    cc /= 4;

    if (x < cc) {
      ab += aa;
      ab.div2();
      b = c;
      bb = cc;
    } else {
      ab += bb;
      ab.div2();
      a = c;
      aa = cc;
    }
  }
  return b;
}

// Note: returns 1 for 0^0.
const ABigInt power(const ABigInt& b, const ABigInt& exponent) {
  if (exponent < 0) return ABigInt();
  if (b == 0) {
    return exponent == 0 ? ABigInt(1) : ABigInt();
  }
  if (exponent == 0) return ABigInt(1);

  ABigInt res(1), tmp(b), power(exponent);

  while (power != 0) {
    if (power.isOdd()) {
      --power;
      res *= tmp;
    } else {
      power.div2();
      tmp *= tmp;
    }
  }
  return res;
}

// Note: returns 1 for 0^0.
const ABigInt modPower(const ABigInt& b, const ABigInt& exponent,
                       const ABigInt& mod) {
  if (exponent < 0 || mod == 1) return ABigInt();
  if (b == 0) {
    return exponent == 0 ? ABigInt(1) : ABigInt();
  }
  if (exponent == 0) return ABigInt(1);

  ABigInt res(1), pmod = abs(mod), tmp = b % pmod, power(exponent);

  const int MAX_INT = std::numeric_limits<int>::max();
  if (pmod <= MAX_INT) {
    int imod = int(pmod);
    while (power != 0) {
      if (power.isOdd()) {
        --power;
        res *= tmp;
        res %= imod;
      } else {
        power.div2();
        tmp *= tmp;
        tmp %= imod;
      }
    }
  } else {
    while (power != 0) {
      if (power.isOdd()) {
        --power;
        res *= tmp;
        res %= pmod;
      } else {
        power.div2();
        tmp *= tmp;
        tmp %= pmod;
      }
    }
  }
  return res;
}

const ABigInt factorial(int N) {
  if (N < 0) return ABigInt(0);
  if (N < 2) return ABigInt(1);

  int i = 2;
  const int MAX_INT = std::numeric_limits<int>::max();

  ABigInt res;

  if (N >= 12) {
    res = 479001600;  // 12! = 479001600
    i = 13;
  } else {
    res = N--;
  }

  while (i < N && i <= MAX_INT / i) {
    res *= i * (i + 1);
    i += 2;
  }
  while (i <= N) res *= i++;
  return res;
}

const ABigInt gcd(ABigInt a, ABigInt b) {
  if (a < 0) a.negate();
  if (b < 0) b.negate();

  if (a == 0 || b == 0) return (a += b);
  if (a == b) return a;

  ABigInt res(1);

  while (a.isEven() && b.isEven()) {
    a.div2();
    b.div2();
    res.mul2();
  }
  while (a.isEven()) a.div2();
  while (b.isEven()) b.div2();

  while (a != b) {
    if (a > b) {
      a -= b;
      while (a.isEven()) a.div2();
    } else {
      b -= a;
      while (b.isEven()) b.div2();
    }
  }
  return (res *= a);
}
//------------------------------------------------------------------------------

int ReadNumber(char* buffer) {
  int x;
  while ((x = std::getchar()) != EOF) {
    if (x == '\n' || !std::isspace(x)) break;
  }
  while ('0' <= x && x <= '9') {
    *buffer++ = x;
    x = std::getchar();
  }
  *buffer = 0;
  return x;
}

int main() {
  char buffer[1024 * 4];
  std::vector<ABigInt> numbers;
  std::vector<int> ops;

  while (1) {
    numbers.clear();
    ops.clear();
    while (1) {
      int last_ch = ReadNumber(buffer);
      if (!*buffer) break;
      ABigInt big_int = ABigInt::ParseBigInt(buffer);
      if (!ops.empty() && ops.back() == '^') {
        numbers.back() = power(numbers.back(), big_int);
        ops.pop_back();
      } else {
        numbers.push_back(std::move(big_int));
      }

      while (last_ch != '\n' && std::isspace(last_ch)) {
        last_ch = std::getchar();
      }
      if (last_ch == '\n') break;
      if (last_ch == '*') {
        int x = std::getchar();
        if (x == '*') {
          last_ch = '^';
        } else {
          std::ungetc(x, stdin);
        }
      }
      ops.push_back(last_ch);
    }
    if (numbers.empty()) break;
    if (ops.empty()) {
      std::cout << numbers[0] << "\n";
      continue;
    }

    ABigInt result;
    for (int i = 0; i < ops.size(); ++i) {
      if (ops[i] == '*') {
        numbers[i + 1] *= numbers[i];
      } else if (ops[i] == '/') {
        numbers[i + 1] = numbers[i] / numbers[i + 1];
      } else {
        result += numbers[i];
        if (ops[i] == '-') numbers[i + 1].negate();
      }
    }
    result += numbers[numbers.size() - 1];
    std::cout << result << "\n";
  }
}
/* @END_OF_SOURCE_CODE */

