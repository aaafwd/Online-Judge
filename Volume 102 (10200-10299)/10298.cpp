/* @JUDGE_ID: 19899RK 10298 C++ "By Anadan" */ 
// Power Strings
// Accepted (0.610 seconds using as much as 1368 kbytes)

#include <stdio.h>
#include <string.h>

int len;
char str[1000001];

int gcd(int a, int b){
	while (a && b) if (a > b) a %= b; else b %= a;
	return a + b;
}

int powerstr(int period){
	int k = len / period;
	char *p = str + period;

	while (--k){
		if (strncmp(p, str, period)) return 0;
		p += period;
	}

	return 1;
}

int main(){
	int i, freq[256], g;
	char *p;

	while (scanf("%s\n", str) == 1){
		if (str[0] == '.' && str[1] == 0) break;
		len = strlen(str);

		memset(freq, 0, sizeof(freq));
		for (p = str; *p; ++p) ++freq[*p];
		for (g = i = 0; i < 256; ++i) g = gcd(g, freq[i]);

		for (i = g; i > 1; --i){
			if (len % i) continue;
			if (powerstr(len / i)) break;
		}

		printf("%d\n", i);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
