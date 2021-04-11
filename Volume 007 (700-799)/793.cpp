/* @JUDGE_ID: 19899RK 793 C++ "By Anadan" */ 
// Network Connections
// Accepted (1.062 seconds using as much as 388 kbytes)

#include <stdio.h>
#define SZ 1000

int N, map[SZ];

void addedge(int x, int y){
	int i, gx = map[x], gy = map[y];
	for (i = 0; i < N; ++i) if (map[i] == gy) map[i] = gx;
}

int main(){
	int set, i, j, a, b;
	char str[21], tmp[2];

	scanf("%d\n\n", &set);
	while (set--){
		a = b = 0;
		scanf("%d", &N); gets(str);
		for (i = 0; i < N; ++i) map[i] = i;
		while (gets(str) && sscanf(str, "%1s%d%d", tmp, &i, &j) == 3){
			--i; --j;
			if (tmp[0] == 'c'){
				if (map[i] != map[j]) addedge(i, j);
			}else if (map[i] == map[j]) ++a; else ++b;
		}

		printf("%d,%d\n", a, b);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
