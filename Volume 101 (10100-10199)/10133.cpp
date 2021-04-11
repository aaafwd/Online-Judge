/* @JUDGE_ID: 19899RK 10133 C++ "By Anadan" */ 
// Audubon's Stormy Arctic Trip
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Node{
	int N, count[25], sum;
	char leaves[25][25], link[25];
}pt[100];

int getsum(int n){
	int i;

	if (pt[n].sum != -1) return pt[n].sum;
	pt[n].sum = 0;
	for (i = 0; i < pt[n].N; ++i){
		if (pt[n].link[i] == -1) pt[n].count[i] = 1;
		else pt[n].count[i] = getsum(pt[n].link[i]);

		pt[n].sum += pt[n].count[i];
	}

	return pt[n].sum;
}

void outprint(int n){
	int v = 0, i, j;

	while (1){
		for (j = i = 0; i < pt[v].N; ++i){
			if (j + pt[v].count[i] >= n) break;
			j += pt[v].count[i];
		}

		if (pt[v].link[i] == -1){
			printf("%s\n", pt[v].leaves[i]);
			break;
		}

		n -= j;
		printf("%s-", pt[v].leaves[i]);
		v = pt[v].link[i];
	}
}

int main(){
	int set, N, i;
	char str[256], *p, *q;

	scanf("%d\n\n", &set);
	while (set--){
		gets(str);
		while (str[0]){
			if (str[2] == ':'){
				N = 10 * (str[0] - '0') + (str[1] - '0');
				pt[N].N = 0;
				pt[N].sum = -1;
			}else if (str[0] == ' ' && str[1] == ' '){
				p = strtok(str, " ");
				while (p){
					q = strchr(p, ':'); *q++ = 0;
					strcpy(pt[N].leaves[pt[N].N], p);
					if (*q == '$') pt[N].link[pt[N].N] = -1;
					else{
						sscanf(q, "%d", &i);
						pt[N].link[pt[N].N] = i;
					}
					++pt[N].N;
					p = strtok(NULL, " ");
				}

			}else break;

			if (gets(str) == NULL) break;
		}

		getsum(0);

		while (str[0]){
			sscanf(str, "%d", &N);
			outprint(N);
			if (gets(str) == NULL) break;
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
