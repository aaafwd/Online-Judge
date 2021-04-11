/* @JUDGE_ID: 19899RK 10537 C++ "By Anadan" */ 
// The Toll! Revisited
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

typedef long long int qword;

char map[52][52];

int getindex(){
	int i;

	while ((i = getchar()) != EOF){
		if ('A' <= i && i <= 'Z') return i - 'A';
		if ('a' <= i && i <= 'z') return i - 'a' + 26;
	}

	return -1;
}

qword getbackcost(qword t){
	qword l = t, r = t + t, m;

	while (l + 1 < r){
		m = (l + r) >> 1;
		if (m - (m + 19) / 20 > t) r = m;
		else l = m;
	}

	while (l - (l + 19) / 20 >= t) --l;
	while (l - (l + 19) / 20 < t) ++l;

	return l;
}

int main(){
	int set = 0, N, i, j, k, curr, src, next[52], que[5000];
	qword spoons[52], tmp;

	while (scanf("%d", &N) == 1 && N != -1){
		memset(map, 0, sizeof(map));
		while (N--){
			i = getindex();
			j = getindex();

			map[i][j] = map[j][i] = 1;
		}

		for (i = 0; i < 52; ++i) spoons[i] = -1;

		scanf("%d", &i);
		src = getindex();
		que[0] = getindex();
		spoons[que[0]] = i;

		memset(next, -1, sizeof(next));
		i = 0; j = 1;
		while (i != j){
			curr = que[i++]; i %= 5000;
			for (k = 0; k < 52; ++k){
				if (!map[k][curr]) continue;
				if (curr < 26) tmp = getbackcost(spoons[curr]);
				else tmp = spoons[curr] + 1;
				if (spoons[k] == -1 || spoons[k] > tmp || (spoons[k] == tmp && next[k] > curr)){
					que[j++] = k; j %= 5000;
					spoons[k] = tmp;
					next[k] = curr;
				}
			}
		}

		printf("Case %d:\n%lld\n", ++set, spoons[src]);
		for (i = src; next[i] != -1; i = next[i]){
			if (i != src) putchar('-');
			if (i < 26) putchar('A' + i);
			else putchar('a' + i - 26);
		}

		if (i != src) putchar('-');
		if (i < 26) putchar('A' + i);
		else putchar('a' + i - 26);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
