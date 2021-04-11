/* @JUDGE_ID: 19899RK 352 C++ "By Anadan" */
// The Seasonal War
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

char map[26][26];

void geteagle(int i, int j){
	map[i][j] = 0;
	if (i){
		if (map[i-1][j] == '1') geteagle(i-1, j);
		if (map[i-1][j+1] == '1') geteagle(i-1, j+1);
		if (j && map[i-1][j-1] == '1') geteagle(i-1, j-1);
	}
	if (j && map[i][j-1] == '1') geteagle(i, j-1);
	if (map[i][j+1] == '1') geteagle(i, j+1);

	if (j && map[i+1][j-1] == '1') geteagle(i+1, j-1);
	if (map[i+1][j] == '1') geteagle(i+1, j);
	if (map[i+1][j+1] == '1') geteagle(i+1, j+1);
}

int main(){
	long set = 0L;
	int i, j, n, res;

	for (i = 0; i < 26; i++) map[25][i] = 0;
	while (scanf("%d\n", &n) > 0){
		for (i = 0; i < n; i++) scanf("%s\n", map[i]);
		for (i = res = 0; i < n; i++){
			for (j = 0; j < n; j++){
				if (map[i][j] == '1'){
					geteagle(i, j);
					res++;
				}
			}
		}
		printf("Image number %ld contains %d war eagles.\n", ++set, res);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
