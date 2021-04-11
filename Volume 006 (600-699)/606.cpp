/* @JUDGE_ID: 19899RK 606 C++ "By Anadan" */ 
// Keeps Going and Going and ...
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct List{
	int n, arr[40], p, q;
}pt[26];

int getnum(int n, int k){
	int pos[26];
	memset(pos, -1, sizeof(pos));

	while (1){
		if (pos[n] != -1) k %= (pos[n] - k);
		if (k < pt[n].n) return pt[n].arr[k];
		if (pt[n].n == 0){
			if (k & 1) n = pt[n].q; else n = pt[n].p;
			k >>= 1;
		}else{
			pos[n] = k;
			k -= pt[n].n;
			n = pt[n].p;
		}
	}
}

int main(){
	int set, N, M, i, j, k;
	char name[2];

	scanf("%d\n\n", &set);
	while (set--){
		scanf("%d%d\n", &N, &M);
		for (i = 0; i < N; ++i){
			scanf("%1s%*1s", name);
			j = name[0] - 'A';
			pt[j].n = 0;
			while (scanf("%d", &k) == 1) pt[j].arr[pt[j].n++] = k;
			if (pt[j].n == 0) scanf("%*s");
			scanf("%s", name);
			pt[j].p = name[0] - 'A';
			if (pt[j].n == 0){
				scanf("%s\n", name);
				pt[j].q = name[0] - 'A';
			}
		}

		while (M--){
			scanf("%s%d%d\n", name, &i, &j);
			printf("%d", getnum(name[0] - 'A', i));
			for (k = i + 1; k <= j; ++k) printf(" %d", getnum(name[0] - 'A', k));
			putchar('\n');
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
