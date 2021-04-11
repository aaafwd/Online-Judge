/* @JUDGE_ID: 19899RK 618 C++ "By Anadan" */
// Doing Windows
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int Ws, Hs, w[4], h[4];

int gcd(int a, int b){
	while (a && b) if (a > b) a %= b; else b %= a;
	if (a) return a; else return b;
}

inline int ratio(int tH, int tW, int i) {
	return (tH*w[i] == tW*h[i]);
}

int fit(int a, int b, int c, int d) {
	int tH, tW;

	if (!(Ws % w[a])) {
		tH = Hs - Ws / w[a] * h[a];
		if (tH > 0) {
			if (!(Ws % w[b])) {
				int ttH = tH - Ws / w[b] * h[b];
				if (ttH > 0) {
					if (!(Ws % w[c])) {
						int tttH = ttH - Ws / w[c] * h[c];
						if (tttH > 0 && ratio(tttH, Ws, d)) return 1;
					}
					if (!(ttH % h[c]) && !(ttH % h[d]) && (ttH/h[c]*w[c] + ttH/h[d]*w[d] == Ws)) return 2;
				}
			}

			if (!(tH % h[b])) {
				tW = Ws - tH / h[b] * w[b];
				if (tW > 0) {
					if (!(tW % w[c]) && !(tW % w[d]) && (tW/w[c]*h[c] + tW/w[d]*h[d] == tH)) return 3;
					if (!(tH % h[c]) && !(tH % h[d]) && (tH/h[c]*w[c] + tH/h[d]*w[d] == tW)) return 4;
				}
			}
		}
	}

	tH = h[b]*w[a]*Ws;
	tW = h[a]*w[b] + h[b]*w[a];
	if (!(tH % tW)) {
		tW = tH / tW;
		if ((tW % w[a]) || ((Ws - tW) % w[b])) return 0;
		tH = Hs - tW / w[a] * h[a];
		if (tH > 0) {
			if (!(tH % h[c]) && !(tH % h[d]) && (tH/h[c]*w[c] + tH/h[d]*w[d] == Ws)) return 5;
		}
	}

	return 0;
}

int solved() {
	if (fit(0,1,2,3)) return 1;
	if (fit(0,1,3,2)) return 1;
	if (fit(0,2,1,3)) return 1;
	if (fit(0,2,3,1)) return 1;
	if (fit(0,3,1,2)) return 1;
	if (fit(0,3,2,1)) return 1;

	if (fit(1,0,2,3)) return 1;
	if (fit(1,0,3,2)) return 1;
	if (fit(1,2,0,3)) return 1;
	if (fit(1,2,3,0)) return 1;
	if (fit(1,3,0,2)) return 1;
	if (fit(1,3,2,0)) return 1;

	if (fit(2,1,0,3)) return 1;
	if (fit(2,1,3,0)) return 1;
	if (fit(2,0,1,3)) return 1;
	if (fit(2,0,3,1)) return 1;
	if (fit(2,3,1,0)) return 1;
	if (fit(2,3,0,1)) return 1;

	if (fit(3,1,2,0)) return 1;
	if (fit(3,1,0,2)) return 1;
	if (fit(3,2,1,0)) return 1;
	if (fit(3,2,0,1)) return 1;
	if (fit(3,0,1,2)) return 1;
	if (fit(3,0,2,1)) return 1;
	return 0;
}

int main() {
	int i, j, set = 0, yes;

	while (scanf("%d%d", &Ws, &Hs) == 2 && Ws) {
		for (i = 0; i < 4; ++i) {
			scanf("%d%d", w+i, h+i);
			j = gcd(w[i], h[i]);
			w[i] /= j; h[i] /= j;
		}

		if (solved()) yes = 1;
		else {
			j = Ws; Ws = Hs; Hs = j;
			for (i = 0; i < 4; ++i) { j = w[i]; w[i] = h[i]; h[i] = j; }
			yes = solved();
		}

		printf("Set %d: %s\n", ++set, (yes ? "Yes" : "No"));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
