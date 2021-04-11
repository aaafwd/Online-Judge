/* @JUDGE_ID: 19899RK 439 C++ "By Anadan" */
// Knight Moves
// Accepted (0.010 seconds using as much as 388 kbytes)

#include <stdio.h>

int x1, y1, x2, y2;

int func(){
	int res;
	int matrix[8][8] = {
		0, 3, 2, 3, 2, 3, 4, 5,
		3, 2, 1, 2, 3, 4, 3, 4,
		2, 1, 4, 3, 2, 3, 4, 5,
		3, 2, 3, 2, 3, 4, 3, 4,
		2, 3, 2, 3, 4, 3, 4, 5,
		3, 4, 3, 4, 3, 4, 5, 4,
		4, 3, 4, 3, 4, 5, 4, 5,
		5, 4, 5, 4, 5, 4, 5, 6
	};

	if (x1 > x2){
		res = x1; x1 = x2; x2 = res;
		res = y1; y1 = y2; y2 = res;
	}
	if (y1 > y2){
		y1 = 7 - y1; y2 = 7 - y2;
	}
	if (((x1 == 0) && (y1 == 0)) || ((x1 == 6) && (y1 == 6))){
		if ((x2 == x1 + 1) && (y2 == y1 + 1)) return 4;
	}

	return matrix[x2 - x1][y2 - y1];
}

int main(){
	char str1[3], str2[3];

	while (scanf("%2s %2s\n", str1, str2) > 1){
		x1 = str1[0] - 'a'; y1 = str1[1] - '1';
		x2 = str2[0] - 'a'; y2 = str2[1] - '1';
		printf("To get from %s to %s takes %d knight moves.\n", str1, str2, func());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
