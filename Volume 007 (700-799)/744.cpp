/* @JUDGE_ID: 19899RK 744 C++ "By Anadan" */
// Triangular Museum
// Accepted (0.523 seconds using as much as 408 kbytes)

#include <math.h>
#include <stdio.h>
#include <string.h>
#define SZ 4000

int K, indexes[100];

int totres;
struct Result{
	char x, y;
}pt[SZ];

int getnum(int x, int y){
	if (y & 1){
		y = (y + x + x + 3) >> 1;
		return y*y - x - x - 2;
	}else{
		y = (y + x + x + 2) >> 1;
		return y*y - x - x - 1;
	}
}

void swaps(int i, int j){
	pt[totres].x = indexes[i];
	pt[totres].y = indexes[j];
	indexes[i] ^= indexes[j] ^= indexes[i] ^= indexes[j];
	++totres;
}

void donextswap(int i, int isright){
	int j, n1, n2, x0, y0, x1, y1;

	for (j = 0; indexes[j] != i - 1; ++j);
	if (i == ++j) return;

	n1 = (int)sqrt(j);
	if (n1 * n1 < j) ++n1;
	n2 = (int)sqrt(i);
	if (n2 * n2 < i) ++n2;

	if (n1 == n2){
		for (; i < j; --j){
			swaps(j - 1, j - 2);
		}

		for (; j < i; ++j){
			swaps(j - 1, j);
		}

		return;
	}

	x0 = (n1*n1 - j) / 2;
	y0 = n1 + n1 + j - n1*n1 - 2;

	x1 = (n2*n2 - i) / 2;
	y1 = n2 + n2 + i - n2*n2 - 2;

	if ((i - n2) & 1){
		--y1;
	}else{
		if (isright) y1 -= 2;
		else --x1;
	}

	while (x0 < x1){
		if (!(y0 & 1)){
			if (y1 >= y0){
				swaps(getnum(x0, y0), getnum(x0, y0 + 1));
				++y0;
			}else{
				swaps(getnum(x0, y0), getnum(x0, y0 - 1));
				--y0;
			}
		}

		swaps(getnum(x0, y0), getnum(x0 + 1, y0 - 1));
		++x0; --y0;
	}

	while (x0 > x1){
		if (y0 & 1){
			if (y1 > y0){
				swaps(getnum(x0, y0), getnum(x0, y0 + 1));
				++y0;
			}else{
				swaps(getnum(x0, y0), getnum(x0, y0 - 1));
				--y0;
			}
		}

		swaps(getnum(x0, y0), getnum(x0 - 1, y0 + 1));
		--x0; ++y0;
	}

	for (; y0 < y1; ++y0){
		swaps(getnum(x0, y0), getnum(x0, y0 + 1));
	}

	for (; y0 > y1; --y0){
		swaps(getnum(x0, y0), getnum(x0, y0 - 1));
	}

	if ((i - n2) & 1){
		swaps(getnum(x1, y1), getnum(x1, y1 + 1));
	}else if (isright){
		swaps(getnum(x1, y1), getnum(x1, y1 + 1));
		swaps(getnum(x1, y1 + 1), getnum(x1, y1 + 2));
	}else{
		swaps(getnum(x1, y1), getnum(x1, y1 + 1));
		swaps(getnum(x1, y1 + 1), getnum(x1 + 1, y1));
	}
}

void dospecialcase(int i, int j){
	int x, y, n;

	if (i == j) return;
	if (indexes[i - 1] == j - 1){

		n = (int)sqrt(i);
		if (n * n < i) ++n;
		x = (n*n - i) / 2;
		y = n + n + i - n*n - 2;

		swaps(getnum(x, y), getnum(x, y - 1)); --y;
		swaps(getnum(x, y), getnum(x - 1, y + 1)); --x; ++y;
		swaps(getnum(x, y), getnum(x, y + 1)); ++y;
		swaps(getnum(x, y), getnum(x, y + 1));

	}else if (indexes[j - 1] == i - 1){
		n = (int)sqrt(j);
		if (n * n < j) ++n;
		x = (n*n - j) / 2;
		y = n + n + j - n*n - 2;

		swaps(getnum(x, y), getnum(x, y - 1)); --y;
		swaps(getnum(x, y), getnum(x, y - 1)); --y;
		swaps(getnum(x, y), getnum(x + 1, y - 1)); ++x; --y;
		swaps(getnum(x, y), getnum(x, y + 1));
	}
}

int main(){
	char flag = 0;
	int i, j, k, L;
	char curr[100][11], last[100][11];

	while (scanf("%d\n", &L) == 1 && L){
		K = L * L;
		for (i = 0; i < K; ++i) scanf("%s", curr[i]);
		for (i = 0; i < K; ++i) scanf("%s", last[i]);
		totres = 0;

		for (i = 0; i < K; ++i){
			for (j = 0; strcmp(curr[i], last[j]); ++j);
			indexes[i] = j;
		}

		for (k = L; k > 0; --k){
			for (j = k*k, i = j - k - k + 2; i < j - 2; ++i, --j){
				donextswap(i, 0);
				donextswap(j, 1);
			}

			if (k & 1){
				donextswap(i + 1, 0);
				dospecialcase(i, j);
				donextswap(i, 0);
				donextswap(j, 1);
			}else{
				donextswap(i, 0);
				donextswap(j, 1);
				donextswap(i + 1, 0);
			}
		}

		if (flag) putchar('\n'); else flag = 1;
		printf("%d\n", totres);
		for (i = 0; i < totres; ++i){
			printf("%s %s\n", last[pt[i].x], last[pt[i].y]);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
