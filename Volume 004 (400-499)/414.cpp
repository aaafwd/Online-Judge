/* @JUDGE_ID: 19899RK 414 C++ "By Anadan" */ 
// Machined Surfaces
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

#define LEN 25

int main(){
	int i, j, N;
	int cur_sp, min_sp, sum_sp;
	char str[LEN + 2];

	while(scanf("%d\n", &N) > 0){
		if (N == 0) break;
		min_sp = LEN;
		sum_sp = 0;
		for (i=0; i<N; i++){
			fgets(str, LEN+2, stdin);
			cur_sp = 0;
			for (j=0; j<LEN; j++) if (str[j] == ' ') cur_sp++;
			if(cur_sp < min_sp) min_sp = cur_sp;
			sum_sp += cur_sp;
		}
		sum_sp -= N * min_sp;
		printf("%d\n", sum_sp);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
