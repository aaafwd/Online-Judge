/* @JUDGE_ID: 19899RK 448 C++ "By Anadan" */
// OOPS!
// Accepted (0.030 seconds using as much as 392 kbytes)

#include <stdio.h>

const char commands[16][5] = {	"ADD",  "SUB",  "MUL",  "DIV",  "MOV", "BREQ",
				"BRLE", "BRLS", "BRGE", "BRGR", "BRNE",
				"BR",   "AND",  "OR",   "XOR",  "NOT"  };

void printoperand(){
	int op, code, tmp;
	scanf("%1x", &op);  code = op >> 2; op &= 3;
	scanf("%1x", &tmp); op <<= 4; op |= tmp;
	scanf("%1x", &tmp); op <<= 4; op |= tmp;
	scanf("%1x", &tmp); op <<= 4; op |= tmp;
	if (code == 0) printf("R");
	else if (code == 1) printf("$");
	else if (code == 2) printf("PC+");
	printf("%d", op);
}

int main(){
	int cop;

	while (scanf("%1x", &cop) > 0){
		printf("%s ", commands[cop]);
		printoperand();
		if (cop < 5 || (cop > 11 && cop != 15)){
			printf(",");
			printoperand();
			if (cop > 11){
				printf(",");
				printoperand();
			}
		}
		printf("\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
