/* @JUDGE_ID: 19899RK 10474 C++ "By Anadan" */ 
// Where is the Marble?
// Accepted (0.316 seconds using as much as 412 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 10001

void myprintf(int x){
	if (x){
		myprintf(x / 10);
		putchar('0' + (x % 10));
	}
}

int main(){
	int set = 0, N, Q, i, x, max = SZ - 1;
	unsigned short arr[SZ];

	while (scanf("%d%d", &N, &Q) == 2 && (N || Q)){
		memset(arr, 0, sizeof(short) * (max + 1));
		max = 0;
		while (N--){
			while ((x = getchar()) < '0' || x > '9');
			x -= '0';
			while ((i = getchar()) >= '0' && i <= '9'){
				x = x * 10 + i - '0';
			}

			++arr[x];
			if (max < x) max = x;
		}

		for (i = 1; i <= max; ++i) arr[i] += arr[i - 1];

		printf("CASE# %d:\n", ++set);
		while (Q--){
			while ((x = getchar()) < '0' || x > '9');
			x -= '0';
			while ((i = getchar()) >= '0' && i <= '9'){
				x = x * 10 + i - '0';
			}

			if (x > max){
				myprintf(x);
				puts(" not found");
			}else if (x){
				myprintf(x);
				if (arr[x - 1] == arr[x]) puts(" not found");
				else{
					fputs(" found at ", stdout);
					myprintf(arr[x - 1] + 1);
					putchar('\n');
				}
			}else{
				if (arr[x]) puts("0 found at 1");
				else puts("0 not found");
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
