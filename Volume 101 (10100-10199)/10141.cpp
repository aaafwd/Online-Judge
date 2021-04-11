/* @JUDGE_ID: 19899RK 10141 C++ "By Anadan" */ 
// Request for Proposal
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

void getlines(int i) { while (i--) while (getchar() != '\n'); }

int main(){
	int set = 0, N, P, i, j;
	double price, tmp;
	char names[2][81];

	while (scanf("%d%d\n", &N, &P) == 2 && N){
		getlines(N);
		i = 1;
		gets(names[0]);
		scanf("%lf%d", &price, &N); getlines(N + 1);
		while (--P){
			gets(names[i]);
			scanf("%lf%d", &tmp, &j); getlines(j + 1);
			if (j > N || (j == N && tmp < price)){
				price = tmp;
				N = j;
				i ^= 1;
			}
		}

		if (set) putchar('\n');
		printf("RFP #%d\n%s\n", ++set, names[i ^ 1]);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
