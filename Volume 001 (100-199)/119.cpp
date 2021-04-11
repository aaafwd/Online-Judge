/* @JUDGE_ID: 19899RK 119 C++ "By Anadan" */ 
// Greedy Gift Givers
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct People{
	char name[13];
	int sum;
}pt[10];

int getindex(char *str){
	int i;
	for (i = 0; strcmp(str, pt[i].name); ++i);
	return i;
}

int main(){
	char str[13];
	int i, j, N, m, n;

	str[0] = 0;
	while (scanf("%d", &N) > 0){
		for (i = 0; i < N; i++){
			scanf("%s", pt[i].name);
			pt[i].sum = 0;
		}

		if (str[0]) putchar('\n');
		for (i = 0; i < N; i++){
			scanf("%s %d %d", str, &m, &n);
			if (n == 0) continue;
			m /= n;
			pt[getindex(str)].sum -= m * n;
			for (j = 0; j < n; j++){
				scanf("%s", str);
				pt[getindex(str)].sum += m;
			}
		}

		for (i = 0; i < N; i++)
			printf("%s %d\n", pt[i].name, pt[i].sum);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
