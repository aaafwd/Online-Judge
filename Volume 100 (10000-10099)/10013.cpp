/* @JUDGE_ID: 19899RK 10013 C++ "By Anadan" */
// Super long sums
// Accepted (1.010 seconds using as much as 392 kbytes)

#include <stdio.h>

const char s0[] = "00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
const char s9[] = "99999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";

void myscanf(int &x){
	int i;
	while ((x = getchar()) != EOF && (x < '0' || x > '9'));
	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
}

int main(){
	int set, M, nines, b, i, j, k;

	scanf("%d", &set);
	while (set--) {
		scanf("%d%d%d", &M, &b, &k);
		b += k;
		nines = 0;
		
		if (b >= 10) {
			if (b == 19) b = nines = 1;
			else {
				putchar('1');
				b -= 10;
			}
		}

		for (i = 1; i < M; ++i) {
			myscanf(j);
			myscanf(k);
			j += k;
			if (j < 9) {
				putchar(b + '0');

				fwrite(s9, 1, nines & 127, stdout);
				nines >>= 7;
				while (nines--) fwrite(s9, 1, 128, stdout);

				b = j;
				nines = 0;
			} else if (j > 9) {
				putchar(b + '1');

				fwrite(s0, 1, nines & 127, stdout);
				nines >>= 7;
				while (nines--) fwrite(s0, 1, 128, stdout);

				b = j - 10;
				nines = 0;
			} else ++nines;
		}

		putchar(b + '0');

		fwrite(s9, 1, nines & 127, stdout);
		nines >>= 7;
		while (nines--) fwrite(s9, 1, 128, stdout);

		putchar('\n');
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
