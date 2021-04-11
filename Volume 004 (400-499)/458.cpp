/* @JUDGE_ID: 19899RK 458 C++ "By Anadan" */
// The Decoder
// Accepted (0.088 seconds with low memory spent)

#include <stdio.h>

int main(){
	int c;

	while ((c = getchar()) != EOF){
		if (c != '\n' && c != '\r') c -= 7;
		putchar(c);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
