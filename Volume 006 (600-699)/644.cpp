/* @JUDGE_ID: 19899RK 644 C++ "By Anadan" */
// Immediate Decodability
// Accepted (0.240 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int N;
char codes[9][11];

int func(){
	int i, j, k, tmp;

	for (i = 0; i < N; i++){
		k = strlen(codes[i]);
		for (j = 0; j < N; j++){
			if (i == j) continue;
			tmp = codes[j][k];
			codes[j][k] = 0;
			if (!strcmp(codes[i], codes[j])){
				codes[j][k] = tmp;
				return 0;
			}
			codes[j][k] = tmp;
		}
	}
	return 1;
}

int main(){
	long set = 0L;

	while (1){
		for (N = 0; N < 9; N++){
			if (scanf("%s\n", codes[N]) < 1) return 0;
			if (codes[N][0] == '9') break;
		}
		printf("Set %ld is ", ++set);
		if (func()) printf("immediately decodable\n");
		else printf("not immediately decodable\n");
	}
}
/* @END_OF_SOURCE_CODE */
