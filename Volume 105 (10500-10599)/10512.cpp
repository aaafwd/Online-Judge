/* @JUDGE_ID: 19899RK 10512 C++ "By Anadan" */
// A Day in Math-land
// Accepted (0.443 seconds using as much as 400 kbytes)

#include <stdio.h>
#include <math.h>
#define MINY -32768
#define MAXY 32767

typedef long long qword;

inline int _abs(int x) { return x < 0 ? -x : x; }
inline int isfit(int x) { return MINY <= x && x <= MAXY; }

int p, q;

int tryx(qword x){
	qword y = x * x - q;

	if (!isfit((int)x)) return 0;
	if (y % x) return 0;
	y /= x;
	if (!isfit((int)y)) return 0;
	if (x >= y){
		printf("%d %d\n", (int)x, (int)y);
		return 1;
	}

	return 0;
}

int main(){
	int set, nt = 0, x, y, flag;
	qword tmp, d, xx;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &p, &q);
		printf("Case %d:\n", ++nt);
		if (q == 0){
			if (p < 0) { puts("Impossible."); continue; }
			y = (int)sqrt(p);
			if (y * y == p && isfit(-y)) printf("0 %d\n", -y);
			else if (p & 1) puts("Impossible.");
			else{
				x = (int)sqrt(p >> 1);
				if (x * x == (p >> 1)){
					if (isfit(-x)) printf("%d %d\n", -x, -x);
					else if (isfit(x)) printf("%d %d\n", x, x);
					else puts("Impossible.");
				}
				else puts("Impossible.");
			}
		}else{
			tmp = qword(p) * qword(p) + qword(q) * qword(q) + qword(p) * qword(q) * 6;
			if (tmp < 0) { puts("Impossible."); continue; }
			d = (qword)sqrt(tmp);
			if (d * d != tmp) { puts("Impossible."); continue; }

			flag = 0;
			xx = qword(q) * 3 + p + d;
			if (xx >= 0 && (xx & 3) == 0){
				tmp = (qword)sqrt(xx >> 2);
				if (tmp * tmp == (xx >> 2)){
					flag = 1;
					if (tryx(-tmp)) continue;
				}
			}

			xx = qword(q) * 3 + p - d;
			if (xx >= 0 && (xx & 3) == 0){
				tmp = (qword)sqrt(xx >> 2);
				if (tmp * tmp == (xx >> 2)){
					if (tryx(-tmp)) continue;
					if (tryx(tmp)) continue;
				}
			}

			if (flag){
				xx = qword(q) * 3 + p + d;
				tmp = (qword)sqrt(xx >> 2);
				if (tryx(tmp)) continue;
			}

			puts("Impossible.");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
