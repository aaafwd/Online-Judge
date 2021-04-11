/* @JUDGE_ID: 19899RK 706 C++ "By Anadan" */
// LC-Display
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

int s, len, column;
char nums[23][104];

void print(char *str, char c1, char c2, char c3){
	*str++ = c1;
	for (int i = 0; i < s; i++) *str++ = c2;
	*str = c3;
}

void printnum(char c){
	int i, j;

	switch(c){
	case '0':
		print(nums[0]+column, ' ', '-', ' ');
		print(nums[s+1]+column, ' ', ' ', ' ');
		print(nums[2*s+2]+column, ' ', '-', ' ');
		for (i = 1; i <= s; i++){
			print(nums[s+1-i]+column, '|', ' ', '|');
			print(nums[s+1+i]+column, '|', ' ', '|');
		}
		break;
	case '1':
		print(nums[0]+column, ' ', ' ', ' ');
		print(nums[s+1]+column, ' ', ' ', ' ');
		print(nums[2*s+2]+column, ' ', ' ', ' ');
		for (i = 1; i <= s; i++){
			print(nums[s+1-i]+column, ' ', ' ', '|');
			print(nums[s+1+i]+column, ' ', ' ', '|');
		}
		break;
	case '2':
		print(nums[0]+column, ' ', '-', ' ');
		print(nums[s+1]+column, ' ', '-', ' ');
		print(nums[2*s+2]+column, ' ', '-', ' ');
		for (i = 1; i <= s; i++){
			print(nums[s+1-i]+column, ' ', ' ', '|');
			print(nums[s+1+i]+column, '|', ' ', ' ');
		}
		break;
	case '3':
		print(nums[0]+column, ' ', '-', ' ');
		print(nums[s+1]+column, ' ', '-', ' ');
		print(nums[2*s+2]+column, ' ', '-', ' ');
		for (i = 1; i <= s; i++){
			print(nums[s+1-i]+column, ' ', ' ', '|');
			print(nums[s+1+i]+column, ' ', ' ', '|');
		}
		break;
	case '4':
		print(nums[0]+column, ' ', ' ', ' ');
		print(nums[s+1]+column, ' ', '-', ' ');
		print(nums[2*s+2]+column, ' ', ' ', ' ');
		for (i = 1; i <= s; i++){
			print(nums[s+1-i]+column, '|', ' ', '|');
			print(nums[s+1+i]+column, ' ', ' ', '|');
		}
		break;
	case '5':
		print(nums[0]+column, ' ', '-', ' ');
		print(nums[s+1]+column, ' ', '-', ' ');
		print(nums[2*s+2]+column, ' ', '-', ' ');
		for (i = 1; i <= s; i++){
			print(nums[s+1-i]+column, '|', ' ', ' ');
			print(nums[s+1+i]+column, ' ', ' ', '|');
		}
		break;
	case '6':
		print(nums[0]+column, ' ', '-', ' ');
		print(nums[s+1]+column, ' ', '-', ' ');
		print(nums[2*s+2]+column, ' ', '-', ' ');
		for (i = 1; i <= s; i++){
			print(nums[s+1-i]+column, '|', ' ', ' ');
			print(nums[s+1+i]+column, '|', ' ', '|');
		}
		break;
	case '7':
		print(nums[0]+column, ' ', '-', ' ');
		print(nums[s+1]+column, ' ', ' ', ' ');
		print(nums[2*s+2]+column, ' ', ' ', ' ');
		for (i = 1; i <= s; i++){
			print(nums[s+1-i]+column, ' ', ' ', '|');
			print(nums[s+1+i]+column, ' ', ' ', '|');
		}
		break;
	case '8':
		print(nums[0]+column, ' ', '-', ' ');
		print(nums[s+1]+column, ' ', '-', ' ');
		print(nums[2*s+2]+column, ' ', '-', ' ');
		for (i = 1; i <= s; i++){
			print(nums[s+1-i]+column, '|', ' ', '|');
			print(nums[s+1+i]+column, '|', ' ', '|');
		}
		break;
	case '9':
		print(nums[0]+column, ' ', '-', ' ');
		print(nums[s+1]+column, ' ', '-', ' ');
		print(nums[2*s+2]+column, ' ', '-', ' ');
		for (i = 1; i <= s; i++){
			print(nums[s+1-i]+column, '|', ' ', '|');
			print(nums[s+1+i]+column, ' ', ' ', '|');
		}
		break;
	}
	column += s + 2;
	for (i = 0; i < 2*s+3; i++) nums[i][column] = ' ';
	++column;
}

int main(){
	int i;
	char str[9], *p;

	while (scanf("%d %s\n", &s, str) == 2){
		if (s == 0) break;
		len = strlen(str);
		column = 0;
		for (p = str; *p; p++) printnum(*p);
		--column;
		for (i = 0, s = 2*s + 3; i < s; i++){
			nums[i][column] = 0;
			printf("%s\n", nums[i]);
		}
		printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
