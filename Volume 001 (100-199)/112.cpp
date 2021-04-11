/* @JUDGE_ID: 19899RK 112 C++ "By Anadan" */
// Tree Summing
// Accepted (0.360 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <ctype.h>

int sum;
char res;

void scanfch(int ch){
	int c;
	while (isspace(c = getchar()));
	if (c != ch) ungetc(c, stdin);
}

int scanftree(int cursum){
	int n;

	scanfch('(');
	if (scanf("%d", &n) != 1){
		scanfch(')');
		return 1;
	}

	cursum += n;
	if (scanftree(cursum)){
		if (scanftree(cursum)){
			if (cursum == sum) res = 1;
		}
	}else scanftree(cursum);
	scanfch(')');

	return 0;
}

int main(){
	while (scanf("%d", &sum) > 0){
		res = 0;
		scanftree(0);
		if (res) printf("yes\n"); else printf("no\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
