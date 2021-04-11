/* @JUDGE_ID: 19899RK 384 C++ "By Anadan" */ 
// Slurpys
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

char str[64], *p;

int findSlump(){
	while (1){
		if ((*p != 'D') && (*p != 'E')) return 0;
		if (*++p != 'F') return 0;
		while (*p == 'F') p++;
		if (*p == 'G') return (++p, 1);
	}
}

int findSlimp(){
	if (*p++ != 'A') return 0;
	if (*p == 'H') return (++p, 1);
	if (*p == 'B'){
		p++;
		if (!findSlimp()) return 0;
	}
	else if (!findSlump()) return 0;
	if (*p++ != 'C') return 0;
	return 1;
}

int isSlurpy(){
	p = str;
	if (!findSlimp()) return 0;
	if (!findSlump()) return 0;
	if (*p) return 0;
	return 1;
}

int main(){
	int i, N;
	scanf("%d\n", &N);
	printf("SLURPYS OUTPUT\n");
	for (i = 0; i < N; i++){
		scanf("%63s\n", str);
		if (isSlurpy()) printf("YES\n"); else printf("NO\n");
	}
	printf("END OF OUTPUT\n");
	return 0;
}
/* @END_OF_SOURCE_CODE */
