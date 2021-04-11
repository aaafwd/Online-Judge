/* @JUDGE_ID: 19899RK 10313 C++ "By Anadan" */ 
// Pay the Price
// Accepted (0.158 seconds using as much as 1104 kbytes)

#include <stdio.h>

typedef unsigned long long qword;

int mytriplescanf(int &i, int &j, int &k){
	int x;

	while ((x = getchar()) != EOF && x != '\n' && (x < '0' || x > '9'));
	if (x == EOF || x == '\n') return 0;
	for (i = x - '0'; (x = getchar()) >= '0' && x <= '9'; i = i * 10 + x - '0');
	if (x == EOF || x == '\n') return 1;

	while ((x = getchar()) != EOF && x != '\n' && (x < '0' || x > '9'));
	if (x == EOF || x == '\n') return 1;
	for (j = x - '0'; (x = getchar()) >= '0' && x <= '9'; j = j * 10 + x - '0');
	if (x == EOF || x == '\n') return 2;

	while ((x = getchar()) != EOF && x != '\n' && (x < '0' || x > '9'));
	if (x == EOF || x == '\n') return 2;
	for (k = x - '0'; (x = getchar()) >= '0' && x <= '9'; k = k * 10 + x - '0');

	while (x != EOF && x != '\n') x = getchar();

	return 3;
}

int main(){
	int i, j, k, m;
	qword map[301][301];

	map[0][0] = 1;
	for (j = 1; j <= 300; ++j) map[0][j] = 1;

	for (i = 1; i <= 300; ++i){
		map[i][0] = 0;
		for (j = 1; j <= i; ++j){
			map[i][j] = map[i][j - 1] + map[i - j][j];
		}
		for (j = i + 1; j <= 300; ++j) map[i][j] = map[i][i];
	}

	while ((m = mytriplescanf(i, j, k)) != 0){
		if (i == 0){
			if (m == 3 && j) puts("0");
			else puts("1");
		}else if (m == 1){
			printf("%lld\n", map[i][i]);
		}else if (m == 2){
			if (j > i) j = i;
			printf("%lld\n", map[i][j]);
		}else{
			if (k == 0 || j > i) puts("0");
			else{
				if (j == 0) j = 1;
				if (k > i) k = i;
				printf("%lld\n", map[i][k] - map[i][j - 1]);
			}
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
