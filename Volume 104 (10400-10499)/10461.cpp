/* @JUDGE_ID: 19899RK 10461 C++ "By Anadan" */ 
// Difference
// Accepted (0.146 seconds using as much as 2352 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 500

int days[SZ], solves[SZ], N;
int tot[SZ], depend[SZ][SZ], itot[SZ], idepend[SZ][SZ];

int getmaxdiff(int n){
	int i, j, k, v = n, vertexes[SZ];
	char mask[SZ];

	if (solves[n] != -1) return solves[n];

	memset(mask, 0, N);
	vertexes[0] = n;
	mask[n] = 1;
	i = 0; j = 1;

	while (i < j){
		n = vertexes[i++];
		for (k = 0; k < tot[n]; ++k){
			if (mask[depend[n][k]] == 0){
				mask[depend[n][k]] = 1;
				vertexes[j++] = depend[n][k];
			}
		}
	}

	i = 0; j = 1;
	while (i < j){
		n = vertexes[i++];
		for (k = 0; k < itot[n]; ++k){
			if (mask[idepend[n][k]] == 0){
				mask[idepend[n][k]] = 1;
				vertexes[j++] = idepend[n][k];
			}
		}
	}

	solves[v] = 0;
	for (i = 0; i < N; ++i){
		if (!mask[i]) solves[v] += days[i];
	}

	return solves[v];
}

void myscanf(int &x){
	int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));
	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
}

void myprintf(int x){
	char str[20], *p = str + 19;

	if (x == 0){
		putchar('0'); putchar('\n');
	}else{
		*p-- = 0;
		while (x){
			*p-- = '0' + (x % 10);
			x /= 10;
		}

		puts(p + 1);
	}
}

int main(){
	int set = 0, E, i, j;

	while (scanf("%d%d\n", &N, &E) == 2 && N){
		for (i = 0; i < N; ++i){
			myscanf(days[i]);
			solves[i] = -1;
			tot[i] = itot[i] = 0;
		}

		while (E--){
			myscanf(i); myscanf(j); --i; --j;
			depend[j][tot[j]++] = i;
			idepend[i][itot[i]++] = j;
		}

		scanf("%d\n", &E);
		printf("Case #%d:\n", ++set);
		while (E--){
			myscanf(i); --i;
			myprintf(getmaxdiff(i));
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
