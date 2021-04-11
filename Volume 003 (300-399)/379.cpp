/* @JUDGE_ID: 19899RK 379 C++ "By Anadan" */
// Hi-Q
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

#define TRY(a, b, c) if (map[b] && map[c]) { invert(a, b, c); i = 34; continue; }

char map[34];

void invert(int i, int j, int k){
	map[i] ^= 1; map[j] ^= 1; map[k] ^= 1;
}

int remove_pegs(){
	int i, j = 0;

	for (i = 33; i > 0; --i){
		if (map[i] == 1) continue;
		if (i == 33) { TRY(33, 32, 31); TRY(33, 30, 25); }
		else if (i == 32) { TRY(32, 29, 24); }
		else if (i == 31) { TRY(31, 32, 33); TRY(31, 28, 23); }
		else if (i == 30) { TRY(30, 29, 28); TRY(30, 25, 18); }
		else if (i == 29) { TRY(29, 24, 17); }
		else if (i == 28) { TRY(28, 29, 30); TRY(28, 23, 16); }
		else if (i == 27) { TRY(27, 26, 25); TRY(27, 20, 13); }
		else if (i == 26) { TRY(26, 25, 24); TRY(26, 19, 12); }
		else if (23 <= i && i <= 25){
			TRY(i, i + 5, i + 8);  TRY(i, i + 1, i + 2);
			TRY(i, i - 1, i - 2);  TRY(i, i - 7, i - 14); }
		else if (i == 22) { TRY(22, 23, 24); TRY(22, 15,  8); }
		else if (i == 21) { TRY(21, 22, 23); TRY(21, 14,  7); }
		else if (i == 20 || i == 19) { TRY(i, i - 1, i - 2); }
		else if (16 <= i && i <= 18){
			TRY(i, i + 7, i + 12); TRY(i, i + 1, i + 2);
			TRY(i, i - 1, i - 2);  TRY(i, i - 7, i - 12); }
		else if (i == 15 || i == 14) { TRY(i, i + 1, i + 2); }
		else if (i == 13 || i == 12){
			TRY(i, i + 7, i + 14);
			TRY(i, i - 1, i - 2); }
		else if (9 <= i && i <= 11){
			TRY(i, i + 7, i + 14); TRY(i, i + 1, i + 2);
			TRY(i, i - 1, i - 2);  TRY(i, i - 5, i - 8); }
		else if (i == 8 || i == 7){
			TRY(i, i + 7, i + 14);
			TRY(i, i + 1, i + 2); }
		else if (i == 6) { TRY(6, 11, 18); TRY(6, 5, 4); }
		else if (i == 5) { TRY(5, 10, 17); }
		else if (i == 4) { TRY(4, 9, 16); TRY(4, 5, 6); }
		else if (i == 3) { TRY(3, 6, 11); TRY(3, 2, 1); }
		else if (i == 2) { TRY(2, 5, 10); }
		else if (i == 1) { TRY(1, 4, 9); TRY(1, 2, 3); }
	}

	for (i = 1; i <= 33; ++i) if (map[i]) j += i;
	return j;
}

int main(){
	int set, i;

	scanf("%d\n", &set);
	printf("HI Q OUTPUT\n");
	while (set--){
		memset(map, 0, 34);
		while (scanf("%d", &i) == 1 && i) map[i] = 1;
		printf("%d\n", remove_pegs());
	}
	printf("END OF OUTPUT\n");

	return 0;
}
/* @END_OF_SOURCE_CODE */
