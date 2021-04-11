/* @JUDGE_ID: 19899RK 503 C++ "By Anadan" */ 
// Parallelepiped walk
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>

int min, tmp, x1, y1, z1;

inline void swap(int &a, int &b)
	{ a ^= b ^= a ^= b; }
inline void swap3(int &a, int &b, int &c)
	{ int tmp = a; a = b; b = c; c = tmp; }

void findminpath(int x0, int y0, int x, int y, int z, int L, int W, int H, int rx, int ry){
	if (rx < -2 || rx > 2 || ry < -2 || ry > 2) return;

	if (z == 0){
		tmp = (x - x1) * (x - x1) + (y - y1) * (y - y1);
		if (min == -1 || min > tmp) min = tmp;
		return;
	}

	if (rx >= 0) findminpath(x0 + L, y0, x0 + L + z, y, x0 + L - x, H, W, L, rx + 1, ry);
	if (rx <= 0) findminpath(x0 - H, y0, x0 - z, y, x - x0, H, W, L, rx - 1, ry);
	if (ry >= 0) findminpath(x0, y0 + W, x, y0 + W + z, y0 + W - y, L, H, W, rx, ry + 1);
	if (ry <= 0) findminpath(x0, y0 - H, x, y0 - z, y - y0, L, H, W, rx, ry - 1);
}

int main(){
	int L, W, H, x2, y2, z2;

	while (scanf("%d%d%d%d%d%d%d%d%d", &L, &W, &H, &x1, &y1, &z1, &x2, &y2, &z2) == 9){

		if (z1 == H){
			swap(x1, y1); swap(x2, y2); swap(L, W);
			z1 = H - z1; z2 = H - z2;
		}else if (x1 == 0){
			swap3(x1, y1, z1); swap3(x2, y2, z2); swap3(L, W, H);
		}else if (x1 == L){
			swap(x1, z1); swap(x2, z2); swap(L, H);
			z1 = H - z1; z2 = H - z2;
		}else if (y1 == 0){
			swap3(x1, z1, y1); swap3(x2, z2, y2); swap3(L, H, W);
		}else if (y1 == W){
			swap(y1, z1); swap(y2, z2); swap(W, H);
			z1 = H - z1; z2 = H - z2;
		}

		min = -1;
		findminpath(0, 0, x2, y2, z2, L, W, H, 0, 0);
		printf("%d\n", min);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
