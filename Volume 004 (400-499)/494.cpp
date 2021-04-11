/* @JUDGE_ID: 19899RK 494 C++ "By Anadan" */
// Kindergarten Counting Game
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>

int main(){
	int c;
	long words = 0L;
	char inword = 0, isnteol;

	do{
		if (isalpha(c = getchar())) inword = 1;
		else{
			if (inword) ++words;
			inword = 0;

			if (c == EOF){
				if (words || isnteol) printf("%ld\n", words);
				break;
			}

			if (c == '\n'){
				printf("%ld\n", words);
				words = 0L;
				isnteol = 0;
			}else isnteol = 1;
		}
	}while(1);
	return 0;
}
/* @END_OF_SOURCE_CODE */
