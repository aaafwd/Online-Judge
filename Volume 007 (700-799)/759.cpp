/* @JUDGE_ID: 19899RK 759 C++ "By Anadan" */
// The Return of the Roman Empire
// Accepted (0.180 seconds using as much as 384 kbytes)

#include <stdio.h>
#include <string.h>

const int Arabic[13] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
const char Roman[13][3] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M" };

char *ArabicToRoman(int num, char *str){
	char *sav = str;
	const char *p;
	int i = 12;

	while (num){
		while (Arabic[i] > num) i--;
		num -= Arabic[i];
		p = Roman[i];
		while (*p) *str++ = *p++;
	}

	*str = 0;
	return sav;
}


int RomanToArabic(char *str){
	int res = 0L;
	char *sav = str, buf[80];
	int i = 12, len = strlen(Roman[12]);

	while (*str){
		while (strncmp(str, Roman[i], len)){
			if (--i < 0) return 0L;
			len = strlen(Roman[i]);
		}
		res += Arabic[i];
		str += len;
	}

	if (strcmp(sav, ArabicToRoman(res, buf))) return 0L;
	return res;
}

int main(){
	int res;
	char str[80];

	while (gets(str)){
		res = RomanToArabic(str);
		if (res && res < 4000) printf("%d\n", res);
		else printf("This is not a valid number\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
