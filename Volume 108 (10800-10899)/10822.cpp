/* @JUDGE_ID: 19899RK 10822 C++ "By Anadan" */
// Planet of the Rock, Paper and Scissors
// Accepted (0.135 seconds using as much as 468 kbytes)

#include <stdio.h>
#define SZ 5000

int N, over[SZ], under[SZ], p[SZ], rank[SZ];

int getp(int i) {
	if (i == -1) return -1;
	if (p[i] != i) p[i] = getp(p[i]);
	return p[i];
}

void link(int i, int j) {
	if (i == -1 || j == -1) return;
	if (rank[i] < rank[j]) p[i] = j;
	else {
		p[j] = i;
		if (rank[i] == rank[j]) ++rank[i];
	}
}

void myscanf(int &x){
	int i;
	while ((x = getchar()) < '0' || x > '9');
	x -= '0';
	while ((i = getchar()) >= '0' && i <= '9'){
		x = x * 10 + i - '0';
	}
}

int main() {
	int set, cs = 0, M, i, j, k, conflict, coherence;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d", &N, &M);
		for (i = 0; i < N; ++i) {
			p[i] = i;
			rank[i] = 0;
			over[i] = under[i] = -1;
		}

		conflict = 0;
		coherence = N;
		while (M--) {
			while (getchar() != '(');
			myscanf(i); i = getp(--i);
			myscanf(j); j = getp(--j);
			over[i] = getp(over[i]); under[i] = getp(under[i]);
			over[j] = getp(over[j]); under[j] = getp(under[j]);

			if (j == i || j == over[i] || conflict) { conflict = 1; continue; }
			else if (j == under[i]) continue;

			--coherence;

			link(under[i], j);
			link(i, over[j]);
			link(over[i], under[j]);

			k = getp((under[j] != -1) ? (under[j]) : (over[i]));
			i = getp(i);
			j = getp(j);

			over[i] = k; under[i] = j;
			over[j] = i; under[j] = k;
			if (k != -1) { over[k] = j; under[k] = i; }
		}

		printf("Community %d: ", ++cs);
		if (conflict) puts("Conflicting Records");
		else if (coherence == 1) puts("Observation Complete");
		else puts("Not Enough Data");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
