/* @JUDGE_ID: 19899RK 506 C++ "By Anadan" */
// System Dependencies
// Accepted (0.040 seconds using as much as 5216 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SZ 2200

struct Point{
	int i, n;
};

int N, installed[SZ], ins_count;
char items[SZ][21], depend[SZ][SZ], ex[SZ];

int getindex(char *s){
	int i;
	for (i = 0; i < N; ++i) if (!strcmp(items[i], s)) return i;
	strcpy(items[i], s);
	ex[i] = 0;
	installed[i] = 0;
	for (i = 0; i <= N; ++i) depend[i][N] = depend[N][i] = 0;
	return N++;
}

void doinstall(int n){
	int i;

	for (i = 0; i < N; ++i){
		if (i != n && depend[n][i] && !installed[i]) doinstall(i);
	}

	ex[n] = 0;
	installed[n] = ++ins_count;
	printf("   Installing %s\n", items[n]);
}

int sort_function(const void *a, const void *b){
	if (((Point *)a)->n < ((Point *)b)->n) return -1;
	return 1;
}

void dolist(){
	int i;
	Point tmp[SZ];

	for (i = 0; i < N; ++i){
		tmp[i].i = i;
		tmp[i].n = installed[i];
	}

	qsort(tmp, N, sizeof(Point), sort_function);
	for (i = 0; i < N; ++i){
		if (tmp[i].n){
			printf("   %s\n", items[tmp[i].i]);
		}
	}
}

void doremove(int n){
	int i = 0, j = 1, k, m, queue[SZ], t = 1;
	Point tmp[SZ];

	queue[0] = n;
	tmp[0].i = n;
	tmp[0].n = installed[n];
	installed[n] = 0;

	while (i < j){
		n = queue[i++];
		for (k = 0; k < N; ++k){
			if (k != n && depend[n][k] && installed[k] && !ex[k]){
				for (m = 0; m < N; ++m){
					if (m != k && depend[m][k] && installed[m]) break;
				}

				if (m == N){
					tmp[t].i = k;
					tmp[t++].n = installed[k];
					queue[j++] = k;
					installed[k] = 0;
				}
			}
		}
	}

	qsort(tmp, t, sizeof(Point), sort_function);
	for (i = t-1; i >= 0; --i) { // reversed order
		printf("   Removing %s\n", items[tmp[i].i]);
	}
}

int main(){
	int i, j;
	char str[128], *p;

	N = ins_count = 0;
	while (fgets(str, sizeof(str), stdin)){
    str[strlen(str) - 1] = 0;
    printf("%s\n", str);
		if (str[0] == 'D'){
			p = strtok(str, " ");
			p = strtok(NULL, " ");
			i = getindex(p);
			p = strtok(NULL, " ");
			while (p){
				j = getindex(p);
				depend[i][j] = 1;
				p = strtok(NULL, " ");
			}

			continue;
		}

		p = strtok(str, " ");
		if (str[0] == 'I'){
			p = strtok(NULL, " ");
			i = getindex(p);
			if (installed[i]) printf("   %s is already installed.\n", p);
			else{
				doinstall(i);
				ex[i] = 1;
			}

		}else if (str[0] == 'R'){
			p = strtok(NULL, " ");
			i = getindex(p);
			if (!installed[i]) printf("   %s is not installed.\n", p);
			else{
				for (j = 0; j < N; ++j){
					if (j != i && installed[j] && depend[j][i]) break;
				}

				if (j < N) printf("   %s is still needed.\n", p);
				else{
					ex[i] = 0;
					doremove(i);
				}
			}
		}else if (str[0] == 'L'){
			dolist();
		}else break;
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */

