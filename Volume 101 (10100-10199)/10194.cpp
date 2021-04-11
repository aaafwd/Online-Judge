/* @JUDGE_ID: 19899RK 10194 C++ "By Anadan" */ 
// Football (aka Soccer)
// Accepted (0.027 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Team{
	int pts, wins, scored, against, games, losses, ties, i;
	char name[31];
}pt[30];

int strcasecmp(char *a, char *b){
	char c1, c2;
	while (*a && *b){
		if ('a' <= *a && *a <= 'z') c1 = *a - 'a' + 'A'; else c1 = *a;
		if ('a' <= *b && *b <= 'z') c2 = *b - 'a' + 'A'; else c2 = *b;
		if (c1 < c2) return -1;
		if (c1 > c2) return 1;
		++a; ++b;
	}

	if (*a == 0 && *b == 0) return 0;
	if (*a) return 1; else return -1;
}

int sort_function1(const void *a, const void *b){
	return strcasecmp(((Team *)a)->name, ((Team *)b)->name);
}

int sort_function2(const void *a, const void *b){
	Team *ta = (Team *)a, *tb = (Team *)b;
	if (ta->pts != tb->pts) return tb->pts - ta->pts;
	if (ta->wins != tb->wins) return tb->wins - ta->wins;
	if (ta->scored - ta->against != tb->scored - tb->against) return tb->scored - tb->against - ta->scored + ta->against;
	if (ta->scored != tb->scored) return tb->scored - ta->scored;
	if (ta->games != tb->games) return ta->games - tb->games;
	if (ta->i < tb->i) return -1;
	return 1;
}

int main(){
	int set, N, G, i, j;
	char str[128];
	Team t1, t2, *p1, *p2;

	scanf("%d\n", &set);
	while (set--){
		gets(str);
		printf("%s\n", str);
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i){
			gets(pt[i].name);
			pt[i].pts = pt[i].wins = pt[i].scored = pt[i].ties = 0;
			pt[i].against = pt[i].games = pt[i].losses = 0;
		}
		qsort(pt, N, sizeof(Team), sort_function1);
		for (i = 0; i < N; ++i) pt[i].i = i;

		scanf("%d\n", &G);
		while (G--){
			scanf("%[^#]#%d@%d#%[^\n]\n", t1.name, &i, &j, t2.name);
			p1 = (Team *)bsearch(&t1, pt, N, sizeof(Team), sort_function1);
			p2 = (Team *)bsearch(&t2, pt, N, sizeof(Team), sort_function1);
			++p1->games; ++p2->games;
			p1->scored += i; p1->against += j;
			p2->scored += j; p2->against += i;
			if (i == j){
				++p1->pts; ++p2->pts; ++p1->ties; ++p2->ties;
			}else if (i > j){
				p1->pts += 3; ++p1->wins; ++p2->losses;
			}else{
				p2->pts += 3; ++p2->wins; ++p1->losses;
			}
		}

		qsort(pt, N, sizeof(Team), sort_function2);
		for (i = 0; i < N; ++i){
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i + 1, pt[i].name, pt[i].pts, pt[i].games, pt[i].wins, pt[i].ties, pt[i].losses, pt[i].scored - pt[i].against, pt[i].scored, pt[i].against);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
