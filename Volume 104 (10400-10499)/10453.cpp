/* @JUDGE_ID: 19899RK 10453 C++ "By Anadan" */ 
// Make Palindrome
// Accepted (1.812 seconds using as much as 2388 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 1000

short minletters[SZ][SZ];
char str[1010], res[2020], *p;

inline int min(int x, int y) { return (x < y) ? (x) : (y); }

int getminletters(int i, int j){
	if (minletters[i][j] != -1) return minletters[i][j];
	if (i >= j) return 0;
	if (str[i] == str[j]) minletters[i][j] = getminletters(i + 1, j - 1);
	else minletters[i][j] = 1 + min(getminletters(i + 1, j), getminletters(i, j - 1));
	return minletters[i][j];
}

void makepalindrome(int i, int j){
	if (i == j){
		*p++ = str[i];
	}else if (i > j){
		return;
	}else if (str[i] == str[j]){
		*p++ = str[i];
		makepalindrome(i + 1, j - 1);
		*p++ = str[i];
	}else if (minletters[i][j] == 1 + minletters[i + 1][j]){
		*p++ = str[i];
		makepalindrome(i + 1, j);
		*p++ = str[i];
	}else{
		*p++ = str[j];
		makepalindrome(i, j - 1);
		*p++ = str[j];
	}
}

int main(){
	int i, j, len;

	while (1){
		while ((j = getchar()) != EOF && (j == ' ' || j == '\n'));
		if (j == EOF) break;
		str[0] = j;
		for (p = str + 1; *p = getchar(); ++p){
			if (*p < 'a' || *p > 'z') break;
		}
		*p = 0;

		len = strlen(str) - 1;
		j = (len + 1) * sizeof(short);
		for (i = 0; i <= len; ++i) memset(minletters[i], -1, j);
		i = getminletters(0, len);
		p = res;
		makepalindrome(0, len);
		*p = 0;
		printf("%d %s\n", i, res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
