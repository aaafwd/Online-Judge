/* @JUDGE_ID: 19899RK 10424 C++ "By Anadan" */ 
// Love Calculator
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int getsum(char *p){
	int res = 0, i;

	while (*p){
		if ('a' <= *p && *p <= 'z') res += *p - 'a' + 1;
		else if ('A' <= *p && *p <= 'Z') res += *p - 'A' + 1;
		++p;
	}

	while (res >= 10){
		i = 0;
		while (res){
			i += res % 10;
			res /= 10;
		}
		res = i;
	}

	return res;
}

int main(){
	int i, j;
	char str[30];
	double res;

	while (gets(str)){	
		i = getsum(str);
		if (!gets(str)) break;
		j = getsum(str);
		if (i > j) i ^= j ^= i ^= j;
		if (j) res = 100.0 * double(i) / double(j);
		else{
			if (i == 0) res = 100.0;
			else res = 0.0;
		}
		printf("%.2lf %%\n", res);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
