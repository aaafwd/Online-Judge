/* @JUDGE_ID: 19899RK 433 C++ "By Anadan" */ 
// Bank (Not Quite O.C.R.)
// Accepted (0.012 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

const char numbers[3][31] = {
	" _     _  _     _  _  _  _  _ ",
	"| |  | _| _||_||_ |_   ||_||_|",
	"|_|  ||_  _|  | _||_|  ||_| _|",
};
const int map[10][7] = {
	{ 8, -1 },
	{ 0, 3, 4, 7, 8, 9, -1 },
	{ 8, -1 },
	{ 8, 9, -1 },
	{ 8, 9, -1 },
	{ 6, 8, 9, -1 },
	{ 8, -1 },
	{ 0, 3, 8, 9, -1 },
	{ -1 },
	{ 8, -1 }
};

int getdiff(const char *s, const char *p){
	if (*s != ' ' && *p == ' ') return 1; ++s; ++p;
	if (*s != ' ' && *p == ' ') return 1; ++s; ++p;
	if (*s != ' ' && *p == ' ') return 1;
	return 0;
}

int main(){
	int set, i, j, k, m, nums[9], res[9], rest11;
	char account[3][28];

	scanf("%d", &set);
	while (getchar() != '\n');

	while (set--){
		gets(account[0]); gets(account[1]); gets(account[2]);
		for (i = 0; i < 9; ++i){
			for (j = 0; j < 10; ++j){
				if (!strncmp(account[0] + 3*i, numbers[0] + 3*j, 3)
				 && !strncmp(account[1] + 3*i, numbers[1] + 3*j, 3)
				 && !strncmp(account[2] + 3*i, numbers[2] + 3*j, 3)
				){
				 	break;
				}
			}

			if (j < 10) nums[i] = j; else nums[i] = -1;
		}

		rest11 = 0;
		for (j = -1, i = 0; i < 9; ++i){
			if (nums[i] == -1) j = i;
			else rest11 += (9 - i) * nums[i];
			res[i] = nums[i];
		}
		rest11 %= 11;

		if (j == -1){
			if (rest11) k = 0; else k = 1;

			for (i = 0; i < 9; ++i){
				for (j = 0; map[nums[i]][j] != -1; ++j){
					m = (rest11 + (9 - i) * (map[nums[i]][j] - nums[i]) + 1111) % 11;
					if (m == 0){
						if (++k > 1) break;
						res[i] = map[nums[i]][j];
					}
				}
			}
		}else{
			k = 0;
			for (i = 0; i < 10; ++i){
				if ((rest11 + (9 - j) * i) % 11) continue;
				m  = getdiff(account[0] + 3*j, numbers[0] + 3*i);
				m += getdiff(account[1] + 3*j, numbers[1] + 3*i);
				m += getdiff(account[2] + 3*j, numbers[2] + 3*i);
				if (m) continue;
				if (++k > 1) break;
				res[j] = i;
			}
		}

		if (k == 0) puts("failure");
		else if (k > 1) puts("ambiguous");
		else{
			for (i = 0; i < 9; ++i) putchar(res[i] + '0');
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
