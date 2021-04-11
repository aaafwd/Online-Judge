/* @JUDGE_ID: 19899RK 472 C++11 "By Anadan" */
// Simultaneous Equations
// Accepted (0.010 seconds with low memory spent)

#ifdef ONLINE_JUDGE
#define NDEBUG
#endif

#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <vector>

constexpr double kErr = 1e-10;

class Complex {
 public:
  Complex() : Complex(0, 0, 0) {}
  Complex(double re, double im) : Complex(re, im, 0) {}

  double re() const { return re_; }
  double im() const { return im_; }
  double sqr_mod() const {
    if (sqr_mod_ < kErr) sqr_mod_ = re_ * re_ + im_ * im_;
    return sqr_mod_;
  }

  const Complex operator-() const { return Complex{-re_, -im_, sqr_mod_}; }
  const Complex invert() const { return Complex{re_, -im_, sqr_mod_}; }

  const Complex& operator+=(const Complex& other) {
    re_ += other.re_;
    im_ += other.im_;
    sqr_mod_ = 0;
    return *this;
  }

  const Complex& operator*=(const Complex& other) {
    // (re1 + im1i)*(re2 + im2i) = (re1*re2 - im1*im2) + i(im1*re2 + re1*im2)
    const double re = re_ * other.re_ - im_ * other.im_;
    const double im = im_ * other.re_ + re_ * other.im_;
    re_ = re;
    im_ = im;
    sqr_mod_ *= other.sqr_mod_;
    return *this;
  }

  const Complex& operator/=(const Complex& other) {
    // (re1 + im1i)/(re2 + im2i) = (re1 + im1i)*(re2 - im2i) / sqr_mod2
    const double re = (re_ * other.re_ + im_ * other.im_) / other.sqr_mod();
    const double im = (im_ * other.re_ - re_ * other.im_) / other.sqr_mod();
    re_ = re;
    im_ = im;
    sqr_mod_ /= other.sqr_mod();
    return *this;
  }

 private:
  Complex(double re, double im, double sqr_mod)
      : re_(re), im_(im), sqr_mod_(sqr_mod) {}

  double re_, im_;
  mutable double sqr_mod_;
};

struct LinearEquationsSystem {
  std::vector<std::vector<Complex>> equations;
  std::vector<Complex> answers;
};

bool eq_zero(const double x) { return -kErr < x && x < kErr; }
bool eq_zero(const Complex& c) { return eq_zero(c.re()) && eq_zero(c.im()); }

bool ReadUntilChar(const char target) {
  while (1) {
    const char ch = std::getchar();
    if (ch == target) return true;
    if (ch == EOF || ch == '\n') break;
  }
  return false;
}

bool ReadInput(LinearEquationsSystem& sys) {
  sys.equations.clear();
  double re, im;
  while (1) {
    std::vector<Complex> line;
    while (ReadUntilChar('(')) {
      std::scanf("%lf,%lf)", &re, &im);
      line.emplace_back(re, im);
    }
    if (line.empty()) break;
    sys.equations.push_back(std::move(line));
  }
  return !sys.equations.empty();
}

void DebugPrint(const LinearEquationsSystem& sys) {
  for (const auto& eq : sys.equations) {
    std::putchar(' ');
    std::putchar(' ');
    for (const Complex& c : eq) {
      std::printf("(%.1lf,%.1lf)", c.re(), c.im());
    }
    std::putchar('\n');
  }
  std::putchar('\n');
}

void SolveLinearEquationsSystem(LinearEquationsSystem& sys) {
  assert(!sys.equations.empty());
  assert(sys.equations.size() + 1 == sys.equations[0].size());
  sys.answers.clear();
  const int N = sys.equations.size();
  for (int i = 0; i < N; ++i) {
    // Implement "partial pivoting", i.e. choose the pivot with max module.
    for (int j = i + 1; j < N; ++j) {
      if (sys.equations[j][i].sqr_mod() > sys.equations[i][i].sqr_mod()) {
        using std::swap;
        swap(sys.equations[i], sys.equations[j]);
      }
    }
    if (eq_zero(sys.equations[i][i])) return;  // No solution.

    // Multiply each equation below by (-equations[i][i]/equations[j][i]) and
    // add the sys.equations[i].
    for (int j = i + 1; j < N; ++j) {
      if (eq_zero(sys.equations[j][i])) continue;
      Complex coeff = -sys.equations[i][i];
      coeff /= sys.equations[j][i];
      sys.equations[j][i] = Complex();
      for (int k = i + 1; k <= N; ++k) {
        sys.equations[j][k] *= coeff;
        sys.equations[j][k] += sys.equations[i][k];
      }
    }
  }

  // Calculate the answers.
  // 1) Move terms with indexes `j > i` to the right.
  // 2) Divide the result by sys.equations[i][i].
  sys.answers.resize(N);
  for (int i = N - 1; i >= 0; --i) {
    sys.answers[i] = sys.equations[i][N];
    for (int j = i + 1; j < N; ++j) {
      if (eq_zero(sys.answers[j])) continue;
      Complex tmp = -sys.equations[i][j];
      tmp *= sys.answers[j];
      sys.answers[i] += tmp;
    }
    sys.answers[i] /= sys.equations[i][i];
  }
}

int main() {
  int datasets = 0;
  LinearEquationsSystem sys;
  while (ReadInput(sys)) {
    SolveLinearEquationsSystem(sys);
    if (datasets++) std::putchar('\n');
    if (sys.answers.empty()) {
      std::puts("No solution");
    } else {
      for (const Complex& c : sys.answers) {
        std::printf("(%.1lf,%.1lf)\n", floor(c.re() * 10 + 0.5 + kErr) * 0.1,
                    floor(c.im() * 10 + 0.5 + kErr) * 0.1);
      }
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
