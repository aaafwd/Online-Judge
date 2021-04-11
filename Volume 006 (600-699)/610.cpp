/* @JUDGE_ID: 19899RK 610 C++ "By Anadan" */
// Street Directions
// Accepted (0.105 seconds using as much as 460 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ   1000
#define MAXV 2000

int N, curnum, sp;
short map[SZ][4], dv[SZ], num[SZ], lowpg[SZ];
short stack_v[MAXV], stack_u[MAXV];
char isbridge;

void myprintf(int x){
	if (x){
		myprintf(x / 10);
		putchar('0' + (x % 10));
	}
}

void dobicomp(int v, int p){
	int i, u;

	num[v] = lowpg[v] = ++curnum;
	for (i = 0; i < dv[v]; ++i){
		u = map[v][i];
		if (num[v] > num[u] && u != p){
			stack_v[sp] = v;
			stack_u[sp] = u;
			++sp;
		}

		if (num[u] == 0){
			dobicomp(u, v);
			if (lowpg[v] > lowpg[u]) lowpg[v] = lowpg[u];
			if (lowpg[u] >= num[v]){
				--sp;
				isbridge = 1;
				while (stack_v[sp] != v || stack_u[sp] != u){
					myprintf(stack_v[sp] + 1); putchar(' ');
					myprintf(stack_u[sp] + 1); putchar('\n');
					--sp;
					isbridge = 0;
				}

				myprintf(stack_v[sp] + 1); putchar(' ');
				myprintf(stack_u[sp] + 1); putchar('\n');
				if (isbridge){
					myprintf(stack_u[sp] + 1); putchar(' ');
					myprintf(stack_v[sp] + 1); putchar('\n');
				}
			}
		}else{
			if (lowpg[v] > num[u]) lowpg[v] = num[u];
		}
	}
}

int myscanf(int &x){
	register int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));
	if (x == EOF) return 0;

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}

	return 1;
}

int main(){
	int subset = 0, M, i, j, k;

	while (myscanf(N) && myscanf(M) && N){
		for (i = 0; i < N; ++i) dv[i] = num[i] = 0;
		for (i = 0; i < M; ++i){
			myscanf(j); myscanf(k); --j; --k;
			map[j][dv[j]++] = k;
			map[k][dv[k]++] = j;
		}

		myprintf(++subset); putchar('\n'); putchar('\n');

		curnum = sp = 0;
		dobicomp(0, -1);

		puts("#");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
