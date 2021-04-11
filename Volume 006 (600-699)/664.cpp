/* @JUDGE_ID: 19899RK 664 C++ "By Anadan" */
// Single-Player Games
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int N;
char mask[26], undefinite[26];
double map[26][27], avg[26];

void parsetree(double coeff, double * equ){
	int i, j;

	while (isspace(i = getchar()) && i != '\n');
	if (i == '\n' || i == ')') return;
	
	if (isalpha(i)){
		equ[i - 'a' + 1] += coeff;

	}else if (isdigit(i) || i == '-'){
		ungetc(i, stdin);
		scanf("%d", &i);
		equ[0] += coeff * i;

	}else if (i == '('){
		double tmp[27];
		for (j = 0; j <= N; ++j) tmp[j] = 0;
		for (j = 1 ;; ++j){
			parsetree(coeff, tmp);
			while (isspace(i = getchar()));
			if (i == ')') break;
			else ungetc(i, stdin);
		}
		for (i = 0; i <= N; ++i) equ[i] += tmp[i] / j;
	}
}

int getcoeff(int i, double coeff, double * equ){
	int j, k;

	if (undefinite[i]) return 0;
	if (mask[i] == 1){
		equ[i + 1] += coeff;
		return 1;
	}
	if (mask[i] == 2){
		equ[0] += coeff * avg[i];
		return 1;
	}

	mask[i] = 1;

	double tmp[27], ttmp[27];

	for (j = 0; j <= N; ++j) tmp[j] = 0;
	tmp[0] = map[i][0];
	tmp[i + 1] = map[i][i + 1];

	for (j = 1; j <= N; ++j){
		if (map[i][j] < 1e-12 || j == i + 1) continue;
		for (k = 0; k <= N; ++k) ttmp[k] = 0;
		if (!getcoeff(j - 1, 1.0, ttmp)) break;
		for (k = 0; k <= N; ++k) tmp[k] += map[i][j] * ttmp[k];
	}
	mask[i] = 0;

	if (j <= N) return 0;
	coeff = 1.0 - tmp[i + 1];
	if (coeff < 1e-12) return 0;
	tmp[i + 1] = 0;

	for (j = 0; j <= N; ++j) equ[j] += tmp[j] / coeff;
	return 1;
}

double getscore(int i){
	int j, k;
	double tmp[27], ttmp[27], coeff;

	if (mask[i] == 2) return avg[i];

	mask[i] = 1;
	for (j = 0; j <= N; ++j) tmp[j] = 0;
	tmp[0] = map[i][0];
	tmp[i + 1] = map[i][i + 1];

	for (j = 1; j <= N; ++j){
		if (map[i][j] < 1e-12 || j == i + 1) continue;
		for (k = 0; k <= N; ++k) ttmp[k] = 0;
		if (!getcoeff(j - 1, 1.0, ttmp)) break;
		for (k = 0; k <= N; ++k) tmp[k] += map[i][j] * ttmp[k];
	}

	mask[i] = 2;
	coeff = 1.0 - tmp[i + 1];

	if (j <= N || coeff < 1e-12) undefinite[i] = 1;
	else avg[i] = tmp[0] / coeff;
	return avg[i];
}

int main(){
	int set = 0, i, j, c;
	double tmp[27], score;

	while (scanf("%d", &N) == 1 && N){
		for (i = 0; i < N; ++i) for (j = 0; j < N; ++j) map[i][j] = 0;
		for (i = 0; i < N; ++i){
			while (isspace(c = getchar()));
			while (getchar() != '=');
			for (j = 0; j <= N; ++j) tmp[j] = 0;
			parsetree(1.0, tmp);
			for (j = 0; j <= N; ++j) map[c - 'a'][j] = tmp[j];
		}

		memset(mask, 0, N);
		memset(undefinite, 0, N);
		printf("Game %d\n", ++set);
		for (i = 0; i < N; ++i){
			score = getscore(i);
			if (undefinite[i]) printf("Expected score for %c undefined\n", i + 'a');
			else printf("Expected score for %c = %.3lf\n", i + 'a', score);
		}
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
