/* @JUDGE_ID: 19899RK 486 C++ "By Anadan" */
// English-Number Translator
// Accepted (0.030 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const char words[][10] = {
	"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
	"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen",
	"eighteen", "nineteen", "twenty", "thirty", "forty", "fifty", "sixty", "seventy",
	"eighty", "ninety", "hundred", "thousand", "million"
};
const long nums[] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17,
	18, 19, 20, 30, 40, 50, 60, 70, 80, 90, 100, 1000, 1000000L
};

int main(){
	int i, sign;
	long res, tmp, last;
	char buf[256], *p;

	while (gets(buf)){
		res = last = 0L;
		p = strtok(buf, " \n");
		if (strcmp(p, "negative")) sign = 1;
		else{
			sign = -1;
			p = strtok(NULL, " \n");
		}
		while(p){
			for (i = 0; i < 31; i++) if (!(strcmp(words[i], p))) break;
			if (i >= 31) return 0;
			tmp = nums[i];
			if (tmp < 1000L){
				if (tmp == 100L) last *= 100L;
				else last += tmp;
			}
			else{
				last *= tmp; res += last; last = 0L;
			}
			p = strtok(NULL, " \n");
		}
		res += last;
		res *= sign;
		printf("%ld\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
