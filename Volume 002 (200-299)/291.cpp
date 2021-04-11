/* @JUDGE_ID: 19899RK 291 C++ "By Anadan" */
// The House Of Santa Claus
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

char map[5][6] = {
	"01101", "10101", "11011", "00101", "11110"
};
char cur[10];

void outprint(int n, int v){
	int i;

	cur[n] = v + 1 + '0';
	if (n == 8){
		printf("%s\n", cur);
		return;
	}

	for (i = 0; i < 5; ++i){
		if (map[v][i] == '1'){
		 	map[v][i] = map[i][v] = '0';
			outprint(n + 1, i);
		 	map[v][i] = map[i][v] = '1';
		}
	}
}

int main(){
	cur[9] = 0;
	outprint(0, 0);
	return 0;
}
/* @END_OF_SOURCE_CODE */
