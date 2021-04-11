/* @JUDGE_ID: 19899RK 10009 C++ "By Anadan" */ 
// All Roads Lead Where?
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char map[26][26], path[26][26];

void dowave(){
	int i = 0, j = 1, u, v, vertexes[26], back[26];

	vertexes[0] = 'R' - 'A';
	memset(back, -1, sizeof(back));

	while (i < j){
		u = vertexes[i++];
		for (v = 0; v < 26; ++v){
			if (map[u][v]){
				vertexes[j++] = v;
				back[v] = u;
			}
		}
	}

	for (i = 0; i < 26; ++i){
		path[i][0] = 'A' + i;
		j = 1; u = i;
		while ((u = back[u]) != -1) path[i][j++] = 'A' + u;
	}
}

int main(){
	int set, N, Q, c;
	char s1[2], s2[2], *s;

	scanf("%d\n\n", &set);
	while (set--){
		memset(map, 0, sizeof(map));
		scanf("%d%d\n", &N, &Q);
		while (N--){
			scanf("%1s", s1);
			while ((c = getchar()) != ' ' && c != '\n');
			scanf("%1s", s2);
			while ((c = getchar()) != ' ' && c != '\n');
			map[s1[0] - 'A'][s2[0] - 'A'] = 1;
		}

		dowave();

		while (Q--){
			scanf("%1s", s1);
			while ((c = getchar()) != ' ' && c != '\n');
			scanf("%1s", s2);
			while ((c = getchar()) != ' ' && c != '\n');

			c = 'R';
			for (N = 0; path[s1[0] - 'A'][N]; ++N){
				if (strchr(path[s2[0] - 'A'], path[s1[0] - 'A'][N])){
					c = path[s1[0] - 'A'][N];
					break;
				}
			}

			for (N = 0; path[s1[0] - 'A'][N] != c; ++N){
				putchar(path[s1[0] - 'A'][N]);
			}

			s = strchr(path[s2[0] - 'A'], c);
			while (*s != s2[0]) putchar(*s--);
			putchar(*s); putchar('\n');
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
