/* @JUDGE_ID: 19899RK 613 C++ "By Anadan" */
// Numbers That Count
// Accepted (0.289 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <string.h>

void setinvent(char *p1, char *p2){
	char *p;
	int c, count, off;

	for (c = '0'; c <= '9'; c++){
		count = 0;
		p = strchr(p1, c);
		while (p){
			count++;
			p = strchr(p + 1, c);
		}
		if (count){
			sprintf(p2, "%d%d%n", count, c - '0', &off);
			p2 += off;
		}
	}
}

int main(){
	int k, j;
	char str[17][128], solved;

	while (scanf("%s\n", str[0]) > 0){
		if (str[0][0] == '-') break;
		solved = 0;
		printf("%s ", str[0]);
		for (j = 0; j < 16; j++){
			setinvent(str[j], str[j+1]);
			if (!strcmp(str[j], str[j+1])){
				if (j) printf("is self-inventorying after %d steps\n", j);
				else printf("is self-inventorying\n");
				solved = 1;
				break;
			}
			for (k = 0; k < j - 1; k++){
				if (!strcmp(str[k], str[j])){
					printf("enters an inventory loop of length %d\n", j-k);
					j = 100;
					solved = 1;
					break;
				}
			}
		}
		if (!solved) printf("can not be classified after 15 iterations\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
