/* @JUDGE_ID: 19899RK 157 C++ "By Anadan" */
// Route Finding
// Accepted (0.060 seconds with low memory spent)

#include <stdio.h>
#define MAX 676

int map[MAX][MAX], e[MAX][MAX], last, tmp;

void printpath(int i, int j){
	while (e[i][j] != -1){
		printpath(i, e[i][j]);
		tmp = e[i][j] / 26;
		if (last != tmp) printf("=%c", tmp + 'A');
		last = tmp;
		putchar(e[i][j] % 26 + 'a');
		i = e[i][j];
	}
}

int main(){
	int i, j, k, l, v, N, stack[MAX], sp;
	char str[256], *p;

	for (i = 0; i < MAX; ++i) for (j = 0; j < MAX; ++j)
		map[i][j] = e[i][j] = -1;

	scanf("%d\n", &N);
	for (i = 0; i < N; ++i){
		scanf("%s\n", str);
		v = 26 * (str[0] - 'A');
		j = v + str[2] - 'a';
		for (p = str + 3; *p; ++p){
			if (*p == '='){
				sp = 1;
				stack[0] = j;
				while (*p == '='){
					++p;
					k = 26 * (*p++ - 'A');
					k = k + *p++ - 'a';
					stack[sp++] = k;
				}

				for (k = 0; k < sp; ++k){
					for (l = k + 1; l < sp; ++l){
						map[stack[k]][stack[l]] = 3;
						map[stack[l]][stack[k]] = 3;
					}
				}

				--p;
			}else{
				k = v + *p - 'a';
				map[j][k] = map[k][j] = 1;
				j = k;
			}
		}
	}

	for (k = 0; k < MAX; ++k){
		for (i = 0; i < MAX; ++i){
			if (i == k || map[i][k] != 3) continue;
			for (j = 0; j < MAX; ++j){
				if (j == k || map[k][j] != 3) continue;
				map[i][j] = 3;
			}
		}
	}

	for (k = 0; k < MAX; ++k){
		for (i = 0; i < MAX; ++i){
			if (i == k || map[i][k] == -1) continue;
			for (j = 0; j < MAX; ++j){
				if (j == k || map[k][j] == -1) continue;
				if (map[i][j] == -1 || map[i][j] > map[i][k] + map[k][j]){
					map[i][j] = map[i][k] + map[k][j];
					e[i][j] = k;
				}
			}
		}
	}

	while (scanf("%s\n", str) == 1 && str[0] != '#'){
		i = 26 * (str[0] - 'A') + str[1] - 'a';
		j = 26 * (str[2] - 'A') + str[3] - 'a';
		printf("%3d: %c%c", map[i][j], str[0], str[1]);
		last = int(str[0] - 'A');
		printpath(i, j);

		if (last != int(str[2] - 'A')){
			printf("=%c", str[2]);
		}

		printf("%c\n", str[3]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
