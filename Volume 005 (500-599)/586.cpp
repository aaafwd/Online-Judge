/* @JUDGE_ID: 19899RK 586 C++ "By Anadan" */ 
// Instant Complexity
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

long powers[11], tmp;
char buf[20];

void parse(long m, int n){
	while (scanf("%s", buf) == 1 && strcmp(buf, "END")){
		if (strcmp(buf, "LOOP") == 0){
			scanf("%s", buf);
			if (buf[0] == 'n') parse(m, n + 1);
			else{
				sscanf(buf, "%ld", &tmp);
				parse(m * tmp, n);
			}
		}else{
			scanf("%ld", &tmp);
			tmp *= m;
			powers[n] += tmp;
		}
	}
}

int main(){
	int set, i, N = 0;
	char written;

	scanf("%d\n", &set);
	while (set--){
		scanf("%*s");
		for (i = 0; i < 11; ++i) powers[i] = 0l;
		parse(1l, 0);
		printf("Program #%d\nRuntime = ", ++N);

		written = 0;
		for (i = 10; i > 1; --i){
			if (powers[i]){
				if (written) printf("+"); else written = 1;
				if (powers[i] != 1) printf("%ld*", powers[i]);
				printf("n^%d", i);
			}
		}

		if (powers[1]){
			if (written) printf("+"); else written = 1;
			if (powers[1] != 1) printf("%ld*", powers[1]);
			printf("n");
		}

		if (written){
			if (powers[0]) printf("+%ld", powers[0]);
		}else printf("%ld", powers[0]);

		printf("\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
