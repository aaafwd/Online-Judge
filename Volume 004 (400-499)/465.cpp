/* @JUDGE_ID: 19899RK 465 C++ "By Anadan" */
// Overflow
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#define SIZE 1024

char maxint[32];
int max = 127, L;

int isint(char *p){
	int len;
	while (*p == '0') ++p;
	if ((len = strlen(p)) == 0) return 1;
	if (len < L) return 1;
	if (len > L) return 0;
	if (strcmp(p, maxint) <= 0) return 1;
	return 0;
}

int isintres(int n1, int n2, char ch){
	if (ch == '+'){
		n1 = max - n1;
		if (n2 <= n1) return 1; else return 0;
	}else{
		if (n1 == 0) return 1;
		n1 = max / n1;
		if (n2 <= n1) return 1; else return 0;
	}
}

int main(){
	int i, n1, n2;
	char op1[SIZE], op2[SIZE], ch;

	for (i = 1; i < sizeof(int); i++, max += 255) max <<= 8;
	sprintf(maxint, "%d%n", max, &L);

	while (scanf("%s %c %s\n", op1, &ch, op2) == 3){
		printf("%s %c %s\n", op1, ch, op2);
		n1 = n2 = -1;
		if (!isint(op1)) printf("first number too big\n");
		else sscanf(op1, "%d", &n1);
		if (!isint(op2)) printf("second number too big\n");
		else sscanf(op2, "%d", &n2);
		if (n1 >= 0 && n2 >= 0){
			if (!isintres(n1, n2, ch)) printf("result too big\n");
		}else if (ch == '+' || (n1 != 0 && n2 != 0)){
			printf("result too big\n");
		}
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
