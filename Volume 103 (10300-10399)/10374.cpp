/* @JUDGE_ID: 19899RK 10374 C++ "By Anadan" */ 
// Election
// Accepted (0.012 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Names{
	char name[81], party[81];
	int votes;
}pt[20];

int main(){
	int set, i, N, M;
	char str[256];

	scanf("%d\n", &set);
	while (set--){
		scanf("%d\n", &N);
		for (i = 0; i < N; ++i){
			gets(pt[i].name);
			gets(pt[i].party);
			pt[i].votes = 0;
		}

		scanf("%d\n", &M);
		while (M--){
			gets(str);
			for (i = 0; i < N; ++i){
				if (strcmp(pt[i].name, str) == 0){
					++pt[i].votes;
					break;
				}
			}
		}

		for (M = i = 0; i < N; ++i) if (M < pt[i].votes) M = pt[i].votes;
		for (i = 0; i < N; ++i) if (pt[i].votes == M) break;
		for (M = i + 1; M < N; ++M) if (pt[M].votes == pt[i].votes) break;

		if (M < N) printf("tie\n");
		else printf("%s\n", pt[i].party);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
