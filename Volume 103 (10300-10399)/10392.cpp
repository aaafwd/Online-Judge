/* @JUDGE_ID: 19899RK 10392 C++ "By Anadan" */
// Factoring Large Numbers
// Accepted (0.623 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

typedef long long int dword;

void outprint(dword num){
	if (num == 0) return;
	outprint(num / 10);
	putchar('0' + num % 10);
}

void proceed(dword num){
	dword i, toi = sqrt((double)num);
	for (i = 2; i <= toi; ++i){
		if (!(num % i)){
			while (!(num % i)){
				printf("    ");
				outprint(i);
				putchar('\n');
				num /= i;
			}
			toi = sqrt((double)num);
		}
	}

	if (num > 1){
		printf("    ");
		outprint(num);
		putchar('\n');
	}
}

int main(){
	char c;
	dword num;

	while (1){
		num = 0;
		while ((c = getchar()) != '\n' && c != EOF){
			if (c == '-') return 0;
			num *= 10;
			num += c - '0';
		}

		proceed(num);
		putchar('\n');
	}
}
/* @END_OF_SOURCE_CODE */
