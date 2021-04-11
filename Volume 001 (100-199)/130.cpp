/* @JUDGE_ID: 19899RK 130 C++ "By Anadan" */
// Roman Roulette
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

struct People{
	int n;
	struct People *next, *prev;
}pt[100];

People *getnext(People *p, int k){
	while (k--) p = p->next;
	return p;
}

int main(){
	int N, K, i, rest;
	struct People *p1, *p2;

	while (scanf("%d%d", &N, &K) == 2 && N){
		pt[0].n = 0;
		pt[0].next = pt + 1;
		pt[0].prev = pt + N - 1;
		pt[N - 1].n = N - 1;
		pt[N - 1].next = pt;
		pt[N - 1].prev = pt + N - 2;

		for (i = 1; i < N - 1; ++i){
			pt[i].n = i;
			pt[i].next = pt + i + 1;
			pt[i].prev = pt + i - 1;
		}

		p1 = pt; rest = N; --K;
		while (rest > 1){
			p1 = getnext(p1, K % rest);
			p1->prev->next = p1->next;
			p1->next->prev = p1->prev;
			--rest;
			p2 = getnext(p1->next, K % rest);
			p1->prev->next = p1;
			p1->next->prev = p1;
			p1->n = p2->n;
			p2->prev->next = p2->next;
			p2->next->prev = p2->prev;
			p1 = p1->next;
		}

		if (p1->n) printf("%d\n", N - p1->n + 1);
		else printf("1\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
