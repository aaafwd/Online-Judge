/* @JUDGE_ID: 19899RK 271 C++ "By Anadan" */
// Simply Syntax
// Accepted (0.030 seconds with low memory spent)

#include <stdio.h>

char *str;

int correct(){
	while(1){
		if (*str == 0) return 0;
		if (*str >= 'p') return (str++, 1);
		if (*str++ == 'N') continue;
		if (!correct()) return 0;
		if (!correct()) return 0;
		return 1;
	}
}

int main(){
	char buf[257];
	while (scanf("%256s\n", buf) > 0){
		str = buf;
		if (correct() && (*str == 0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
