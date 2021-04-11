/* @JUDGE_ID: 19899RK 306 C++ "By Anadan" */
// Cipher
// Accepted (0.840 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

char str[201];
int k, N, index[200];

void func(){
	int i, j, pos;
	char tmp[200], flags[200];

	for (i = 0; i < N; i++){
		memset(flags, 0, N);
		for (pos = i, j = 0; j < k; j++){
			if (flags[pos]) break;
			flags[pos] = 1;
			pos = index[pos];
		}
		if (j < k){
			j = k % j;
			pos = i;
			while (j--) pos = index[pos];
		}
		tmp[pos] = str[i];
	}
	memcpy(str, tmp, N);
}

int main(){
	int i, j;
	char *p;

	while (scanf("%d", &N) > 0){
		if (N == 0) break;
		for (i = 0; i < N; i++){
			scanf("%d", index + i);
			--index[i];
		}

		scanf("\n");
		while (scanf("%d", &k) == 1 && k){
			getchar();
			scanf("%[^\n]\n", str);
			i = strlen(str);
			p = str + i;
			while (i++ < N) *p++ = ' ';
			*p = 0;
			func();
			printf("%s\n", str);
		}
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
