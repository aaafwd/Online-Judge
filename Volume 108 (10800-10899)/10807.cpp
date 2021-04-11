/* @JUDGE_ID: 19899RK 10807 C++ "By Anadan" */
// Prim, Prim.
// Accepted (0.117 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 0x7FFFFFFF

struct LinkSet{
	int p[32], rank[32];
};
struct Link {
	int i, j, k;
} links[32];
int best, M, psum[32];
char map[32][32];

int sort_function(const void *a, const void *b) {
	if (((Link*)a)->k < ((Link*)b)->k) return -1;
	return 1;
}

int getp(LinkSet & ls, int i) {
	if (ls.p[i] != i) ls.p[i] = getp(ls, ls.p[i]);
	return ls.p[i];
}

int link(LinkSet & ls, int i, int j) {
	i = getp(ls, i);
	j = getp(ls, j);
	if (i == j) return 0;
	if (ls.rank[i] < ls.rank[j]) ls.p[i] = j;
	else {
		ls.p[j] = i;
		if (ls.rank[i] == ls.rank[j]) ++ls.rank[i];
	}
	return 1;
}

void generate(LinkSet& set1, LinkSet& set2, int i, int curr, int coherence) {
	int u, v;

	if (curr >= best) return;
	if (coherence == 2) { best = curr; return; }

	for (; i <= M - coherence + 2; ++i) {
		u = links[i].i;
		v = links[i].j;
		if (curr + psum[i + coherence - 2] - psum[i] >= best) break;

		if (getp(set1, u) == getp(set1, v) || getp(set2, u) == getp(set2, v) || i == 0) {
			if (link(set1, u, v) || link(set2, u, v)) {
				curr += links[i].k;
				if (--coherence == 2) break;
			}
		} else {
			LinkSet tmp1 = set1, tmp2 = set2;

			link(tmp2, u, v);
			--coherence;
			curr += links[i].k;
			generate(tmp1, tmp2, i+1, curr, coherence);

			link(set1, u, v);
			if (coherence == 2) break;
		}
	}

	if (coherence == 2 && best > curr) { best = curr; return; }
}

int main() {
	int N, i, j, coherence;
	LinkSet set1, set2;

	while (scanf("%d%d", &N, &M) == 2 && N) {
		for (i = 0; i < N; ++i) {
			set1.p[i] = set2.p[i] = i;
			set1.rank[i] = set2.rank[i] = 0;
		}

		coherence = N;
		for (i = 0; i < M; ++i){
			scanf("%d%d%d", &links[i].i, &links[i].j, &links[i].k);
			if (link(set1, --links[i].i, --links[i].j)) --coherence;
		}
		qsort(links, M, sizeof(Link), sort_function);

		memset(map, 0, sizeof(map));
		for (i = j = 0; i < M; ++i) {
			if (map[links[i].i][links[i].j] < 2) {
				++map[links[i].i][links[i].j];
				++map[links[i].j][links[i].i];
				links[j++] = links[i];
			}
		}
		M = j;

		psum[0] = 0;
		for (i = 0; i < M; ++i) {
			psum[i+1] = psum[i] + links[i].k;
		}

		best = MAX;
		if (coherence == 1 && M >= 2*N-2) {
			for (i = 0; i < N; ++i) {
				set1.p[i] = set2.p[i] = i;
				set1.rank[i] = set2.rank[i] = 0;
			}
			generate(set1, set2, 0, 0, N << 1);
		}

		if (best != MAX) printf("%d\n", best);
		else puts("No way!");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
