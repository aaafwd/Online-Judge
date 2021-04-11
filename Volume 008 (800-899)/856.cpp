/* @JUDGE_ID: 19899RK 856 C++ "By Anadan" */ 
// The Vigenere Cipher
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const char numbers[10][6] = { "nine", "eight", "seven", "six", "five", "four", "three", "two", "one", "zero" };

struct Decoded{
	int len;
	char str[16];
}pt[1000];

int main(){
	int i, j, k, N = 0;
	char str[256];

	for (i = 0; i < 10; ++i) for (j = 0; j < 10; ++j) for (k = 0; k < 10; ++k){
		sprintf(pt[N].str, "%s%s%s%n", numbers[i], numbers[j], numbers[k], &pt[N].len);
		++N;
	}

	N = 0;
	while (scanf("%s\n", str) == 1){
		if (N) putchar('\n');
		N = strlen(str);
		for (i = 0; i < 1000; ++i) if (pt[i].len == N){
			for (j = 0; j < pt[i].len; ++j) putchar((52 + str[j] - 'A' - pt[i].str[j] + 'a' - 1) % 26 + 'A');
			printf(" -> %s\n", pt[i].str);
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
