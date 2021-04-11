/* @JUDGE_ID: 19899RK 300 C++ "By Anadan" */
// Maya Calendar
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const char Haab[19][10] = {
	"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax",
	"zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};

const char Tzolkin[20][10] = {
	"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat",
	"muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban",
	"eznab", "canac", "ahau"
};

int main(){
	int set, dd, mm, yy, D;
	char str[10];

	scanf("%d\n", &set);
	printf("%d\n", set);
	while (set--){
		scanf("%d. %s %d\n", &dd, str, &yy);
		for (mm = 0; strcmp(Haab[mm], str); ++mm);
		D = yy*365 + mm * 20 + dd;
		yy = D / 260;
		D %= 260;
		printf("%d %s %d\n", (D % 13) + 1, Tzolkin[D % 20], yy);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
