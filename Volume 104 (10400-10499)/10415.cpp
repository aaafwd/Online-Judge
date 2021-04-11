/* @JUDGE_ID: 19899RK 10415 C++ "By Anadan" */
// Eb Alto Saxophone Player
// Accepted (0.047 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const char letters[15] = "abcdefgABCDEFG";
const char select[15][11] = {
	"0110000000",
	"0100000000",
	"0111001111",
	"0111001110",
	"0111001100",
	"0111001000",
	"0111000000",
	"1110000000",
	"1100000000",
	"0010000000",
	"1111001110",
	"1111001100",
	"1111001000",
	"1111000000",
	"0000000000"
};

int main(){
	int set, i, j, k, l, res[10];
	char str[256];
	const char *p;

	scanf("%d", &set);
	while ((i = getchar()) != '\n' && i != -1);

	while (set--){
		gets(str);
		memset(res, 0, 10 * sizeof(int));
		for (j = 14, k = 0; str[k]; ++k){
			p = strchr(letters, str[k]);
			i = int(p - letters);
			for (l = 0; l < 10; ++l){
				if (select[i][l] == '1' && select[j][l] == '0') ++res[l];
			}
			j = i;
		}

		printf("%d", res[0]);
		for (i = 1; i < 10; ++i) printf(" %d", res[i]);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
