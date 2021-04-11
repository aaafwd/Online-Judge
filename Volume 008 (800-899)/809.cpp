/* @JUDGE_ID: 19899RK 809 C++ "By Anadan" */
// Bullet Hole
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

const double eps = 1e-6;
int x1, y1, z1, x2, y2, z2;

double getminz(double x0, double y0, double z0, double size) {
  int fx, fy, fz;
  double t, x, y, z, minz = -1.0;

  if (z2) {
    t = (z0 - z1) / double(z2);
    x = x1 + t * x2;
    y = y1 + t * y2;
    if (t >= -eps && x0 <= x + eps && x - eps <= x0 + size && y0 <= y + eps &&
        y - eps <= y0 + size) {
      return z0;
    }

    t = (z0 + size - z1) / double(z2);
    x = x1 + t * x2;
    y = y1 + t * y2;
    if (t >= -eps && x0 <= x + eps && x - eps <= x0 + size && y0 <= y + eps &&
        y - eps <= y0 + size) {
      minz = z0 + size;
    }
  }

  if (y2) {
    t = (y0 - y1) / double(y2);
    x = x1 + t * x2;
    z = z1 + t * z2;
    if (t >= -eps && x0 <= x + eps && x - eps <= x0 + size && z0 <= z + eps &&
        z - eps <= z0 + size) {
      if (minz == -1.0 || minz > z) minz = z;
    }

    t = (y0 + size - y1) / double(y2);
    x = x1 + t * x2;
    z = z1 + t * z2;
    if (t >= -eps && x0 <= x + eps && x - eps <= x0 + size && z0 <= z + eps &&
        z - eps <= z0 + size) {
      if (minz == -1.0 || minz > z) minz = z;
    }
  }

  if (x2) {
    t = (x0 - x1) / double(x2);
    y = y1 + t * y2;
    z = z1 + t * z2;
    if (t >= -eps && y0 <= y + eps && y - eps <= y0 + size && z0 <= z + eps &&
        z - eps <= z0 + size) {
      if (minz == -1.0 || minz > z) minz = z;
    }

    t = (x0 + size - x1) / double(x2);
    y = y1 + t * y2;
    z = z1 + t * z2;
    if (t >= -eps && y0 <= y + eps && y - eps <= y0 + size && z0 <= z + eps &&
        z - eps <= z0 + size) {
      if (minz == -1.0 || minz > z) minz = z;
    }
  }

  fx = (x0 <= x1 + eps && x1 - eps <= x0 + size);
  fy = (y0 <= y1 + eps && y1 - eps <= y0 + size);
  fz = (z0 <= z1 + eps && z1 - eps <= z0 + size);

  if (fx && fy && (minz == -1.0 || minz > z1)) {
    if (-eps <= z0 - z1 && z0 - z1 <= eps) {
      minz = z1;
    } else if (-eps <= z0 + size - z1 && z0 + size - z1 <= eps) {
      minz = z1 + size;
    }
  }

  if (fx && fz) {
    if ((minz == -1.0 || minz > z1) && -eps <= y0 - y1 && y0 - y1 <= eps) {
      minz = z1;
    }
    if ((minz == -1.0 || minz > z1) && -eps <= y0 + size - y1 &&
        y0 + size - y1 <= eps) {
      minz = z1;
    }
  }

  if (fy && fz) {
    if ((minz == -1.0 || minz > z1) && -eps <= x0 - x1 && x0 - x1 <= eps) {
      minz = z1;
    }
    if ((minz == -1.0 || minz > z1) && -eps <= x0 + size - x1 &&
        x0 + size - x1 <= eps) {
      minz = z1;
    }
  }

  return minz;
}

int main() {
  int set = 0, n, d, i, j, k, endflag;
  double minz, res, size, x, y, z, tmp;

  while (scanf("%d%d%d%d%d%d%d%d\n", &n, &d, &x1, &y1, &z1, &x2, &y2, &z2) ==
             8 &&
         n) {
    x2 -= x1;
    y2 -= y1;
    z2 -= z1;

    minz = getminz(0.0, 0.0, 0.0, double(d));

    if (set) putchar('\n');
    printf("Trial %d, Volume = ", ++set);
    if (minz == -1 || minz + eps >= d) {
      printf("0.00\n");
    } else {
      size = double(d) / double(n);
      res = z = 0.0;
      for (i = 0; i < n; ++i) {
        if (z + size > minz) break;
        z += size;
      }

      for (; i < n; ++i) {
        x = 0.0;
        endflag = 1;
        for (j = 0; j < n; ++j) {
          y = 0.0;
          for (k = 0; k < n; ++k) {
            tmp = getminz(x, y, z, size);
            if (tmp != -1.0) {
              if (z <= minz + eps && minz - eps <= z + size) {
                if (tmp < minz) tmp = minz;
              }
              if (tmp + eps >= minz) {
                res += (z + size - tmp) * size * size;
              }
              endflag = 0;
            }
            y += size;
          }
          x += size;
        }

        if (endflag) break;
        z += size;
      }

      printf("%.2lf\n", res);
    }
  }
  return 0;
}
/* @END_OF_SOURCE_CODE */
