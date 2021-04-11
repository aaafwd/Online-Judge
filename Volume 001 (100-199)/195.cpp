/* @JUDGE_ID: 19899RK 195 C++ "By Anadan" */
// Anagram
// Accepted (0.220 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

int len;
char str[512];
int A[52];

void func(int n){
	int i;

	if (n == len){
		str[n] = 0;
		printf("%s\n", str);
		return;
	}

	for (i = 0; i < 26; i++){
		if (A[i]){
			A[i]--;
			str[n] = 'A' + i;
			func(n + 1);
			A[i]++;
		}
		if (A[i + 26]){
			A[i + 26]--;
			str[n] = 'a' + i;
			func(n + 1);
			A[i + 26]++;
		}
	}
}

int main(){
	char *p;
	long N;
	scanf("%ld\n", &N);

	while(N--){
		scanf("%s\n", str); p = str;
		memset(A, 0, 52 * sizeof(int));
		while(*p){
			if (*p <= 'Z') A[*p - 'A']++;
			else A[*p - 'a' + 26]++;
			p++;
		}
		len = strlen(str);
		func(0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
