/* @JUDGE_ID: 19899RK 10275 C++ "By Anadan" */ 
// Guess the Number!
// Accepted (0.146 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int getdigits(int len){
	int i = 1, j = 200000, N, tmp;

	while (i < j - 1){
		N = (i + j) >> 1;
		tmp = int(floor(log10(N) * N)) + 1;
		if (tmp > len) j = N; else i = N;
	}

	tmp = int(floor(log10(i) * i)) + 1;
	if (tmp == len) return i; else return j;
}

int getrest9(int N){
	int a = N % 9, i = 1;

	if (a == 0 || a == 1) return a;
	if (a == 2 || a == 5){
		N %= 6;
		while (N--) i *= a;
	}else if (a == 3 || a == 6) return 0;
	else if (a == 4 || a == 7){
		N %= 3;
		while (N--) i *= a;
	}else if (a == 8){
		N %= 2;
		while (N--) i *= a;
	}

	return (i % 9);
}

int getrest11(int N){
	int a = N % 11, i = 1;

	if (a == 0 || a == 1) return a;
	if (a == 2 || a == 6 || a == 7 || a == 8){
		N %= 10;
		while (N--) i *= a;
	}else if (a == 3 || a == 4 || a == 5 || a == 9){
		N %= 5;
		while (N--) i *= a;
	}else if (a == 10){
		N %= 2;
		while (N--) i *= a;
	}

	return (i % 11);
}

int main(){
	int set, i, j, len, rest9, rest11, N;

	scanf("%d\n", &set);
	while (set--){
		len = rest9 = rest11 = 0;
		while ((i = getchar()) != '\n' && i != EOF){
			rest9 = (rest9 + i - '0') % 9;
			rest11 = (rest11 * 10 + i - '0') % 11;
			++len;
		}

		if (len == 1){
			if (rest11 == 1) printf("1\n");
			else if (rest11 == 4) printf("2\n");
			else printf("-1\n");
			continue;
		}

		N = getdigits(len);
		i = getrest9(N);
		j = getrest11(N);
		if (i == rest9 && j == rest11) printf("%d\n", N);
		else printf("-1\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
