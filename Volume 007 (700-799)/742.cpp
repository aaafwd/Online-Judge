/* @JUDGE_ID: 19899RK 742 C++ "By Anadan" */
// Domino Game
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

struct Domino{
	int a, b, f;
}pt[2][14];
int N, win, sp[2];

void generate(int p, int a, int b, int passed){
	int i, ispass = 1;

	if (win == 3) return;
	if (sp[0] == 0){
		win |= 1;
		return;
	}
	if (sp[1] == 0){
		win |= 2;
		return;
	}

	--sp[p];
	for (i = 0; i < N; ++i){
		if (pt[p][i].f) continue;

		pt[p][i].f = 1;
		if (a == pt[p][i].a || a == pt[p][i].b){
			ispass = 0;
			generate(p ^ 1, pt[p][i].a + pt[p][i].b - a, b, 0);
		}
		if (a != b && (b == pt[p][i].a || b == pt[p][i].b)){
			ispass = 0;
			generate(p ^ 1, a, pt[p][i].a + pt[p][i].b - b, 0);
		}
		pt[p][i].f = 0;
	}
	++sp[p];

	if (ispass){
		if (passed) return;
		else generate(p ^ 1, a, b, 1);
	}
}

int main(){
	int i, j, p, max = -2;

	while (scanf("%d", &N) == 1 && N){
		if (max != -2) putchar('\n');

		for (i = 0; i < N; ++i) scanf("%d%d", &pt[0][i].a, &pt[0][i].b);
		for (i = 0; i < N; ++i) scanf("%d%d", &pt[1][i].a, &pt[1][i].b);

		max = -1;
		for (p = i = 0; i < N; ++i){
			pt[0][i].f = 0;
			if (pt[0][i].a != pt[0][i].b) continue;
			if (max < pt[0][i].a) { max = pt[0][i].a; j = i; }
		}

		for (i = 0; i < N; ++i){
			pt[1][i].f = 0;
			if (pt[1][i].a != pt[1][i].b) continue;
			if (max < pt[1][i].a) { max = pt[1][i].a; j = i; p = 1; }
		}

		if (N == 1){
			win = p + 1;
		}else{
			win = 0;
			pt[p][j].f = 1;
			sp[0] = sp[1] = N; --sp[p];
			generate(p ^ 1, max, max, 0);
		}

		if (win == 0) puts("No players can win");
		else if (win == 1) puts("Only player Red can win");
		else if (win == 2) puts("Only player Green can win");
		else puts("Both players can win");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
