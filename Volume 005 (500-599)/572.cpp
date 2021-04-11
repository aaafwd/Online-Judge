/* @JUDGE_ID: 19899RK 572 C++ "By Anadan" */
// Oil Deposits
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int m, n;
char map[101][101];

void getdeposit(int i, int j){
	map[i][j] = 0;
	if (i){
		if (map[i-1][j] == '@') getdeposit(i-1, j);
		if (map[i-1][j+1] == '@') getdeposit(i-1, j+1);
		if (j && map[i-1][j-1] == '@') getdeposit(i-1, j-1);
	}
	if (j && map[i][j-1] == '@') getdeposit(i, j-1);
	if (map[i][j+1] == '@') getdeposit(i, j+1);

	if (j && map[i+1][j-1] == '@') getdeposit(i+1, j-1);
	if (map[i+1][j] == '@') getdeposit(i+1, j);
	if (map[i+1][j+1] == '@') getdeposit(i+1, j+1);
}

int main(){
	int i, j, res;

	for (i = 0; i < 101; i++) map[100][i] = 0;
	while (scanf("%d%d\n", &m, &n) == 2){
		if (!m) break;
		for (i = 0; i < m; i++) scanf("%s\n", map[i]);
		for (i = res = 0; i < m; i++){
			for (j = 0; j < n; j++){
				if (map[i][j] == '@'){
					getdeposit(i, j);
					res++;
				}
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
