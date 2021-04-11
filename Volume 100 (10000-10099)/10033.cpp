/* @JUDGE_ID: 19899RK 10033 C++ "By Anadan" */ 
// Interpreter
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>

int main(){
	int set, i, j, ram[1000], res, reg[10];
	char str[256];

	scanf("%d\n\n", &set);
	while (set--){
		i = 0;
		while (gets(str)){
			if (sscanf(str, "%d", ram + i) < 1) break;
			++i;
		}
		while (i < 1000) ram[i++] = 0;

		for (i = 0; i < 10; ++i) reg[i] = 0;
		for (res = i = 0; ram[i] != 100; ++i, ++res){
			if (ram[i] < 100){
				if (reg[ram[i] % 10]) i = reg[ram[i] / 10] - 1;
			}else if (ram[i] < 300){
				j = ram[i] - 200;
				reg[j / 10] = j % 10;
			}else if (ram[i] < 400){
				j = ram[i] - 300;
				reg[j / 10] += j % 10;
				if (reg[j / 10] >= 1000) reg[j / 10] -= 1000;
			}else if (ram[i] < 500){
				j = ram[i] - 400;
				reg[j / 10] *= (j % 10);
				if (reg[j / 10] >= 1000) reg[j / 10] %= 1000;
			}else if (ram[i] < 600){
				j = ram[i] - 500;
				reg[j / 10] = reg[j % 10];
			}else if (ram[i] < 700){
				j = ram[i] - 600;
				reg[j / 10] += reg[j % 10];
				if (reg[j / 10] >= 1000) reg[j / 10] -= 1000;
			}else if (ram[i] < 800){
				j = ram[i] - 700;
				reg[j / 10] *= reg[j % 10];
				if (reg[j / 10] >= 1000) reg[j / 10] %= 1000;
			}else if (ram[i] < 900){
				j = ram[i] - 800;
				reg[j / 10] = ram[reg[j % 10]];
			}else{
				j = ram[i] - 900;
				ram[reg[j % 10]] = reg[j / 10];
			}
		}

		printf("%d\n", res + 1);
		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
