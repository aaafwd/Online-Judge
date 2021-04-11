/* @JUDGE_ID: 19899RK 444 C++ "By Anadan" */ 
// Encoder and Decoder
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

char str[256];

void decode(){
	int i, len = strlen(str), cur = 0;
	for (i = len - 1; i >= 0; i--){
		cur *= 10;
		cur += str[i] - '0';
		if (cur >= ' '){
			printf("%c", cur); cur = 0;
		}
	}
	printf("\n");
}

void encode(){
	int i, j, len = strlen(str);
	for (i = len - 1; i >= 0; i--){
		j = str[i];
		while (j){
			printf("%d", j % 10);
			j /= 10;
		}
	}
	printf("\n");
}

int main(){
	while (gets(str)){
	  	if (('0' <= str[0]) && (str[0] <= '9')) decode();
		else encode();
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
