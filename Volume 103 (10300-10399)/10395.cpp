/* @JUDGE_ID: 19899RK 10395 C++ "By Anadan" */
// Titans are in Danger!
// Accepted (0.324 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

char str[16];

void generate(int n){
	int i;

	if (n == 0){
		printf("%s\n", str);
		return;
	}

	generate(n - 1);
	if (n & 1){
		for (i = 0; i < n; ++i){
			str[i] ^= str[n] ^= str[i] ^= str[n];
			generate(n - 1);
		}
	}else{
		for (i = 0; i < n; ++i){
			str[0] ^= str[n] ^= str[0] ^= str[n];
			generate(n - 1);
		}
	}
}

int main(){
	while (scanf("%s\n", str) == 1){
		generate(strlen(str) - 1);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
