/* @JUDGE_ID: 19899RK 174 C++ "By Anadan" */ 
// Strategy
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int score[10], c;
char programs[10][256], memory[2][2];

int cond(char *&p){
	int i = c, j, nt = 0;

	if (p[0] == 'M') p += 2;
	else { p += 4; i ^= 1; }
	p += 4;
	j = *p++ - '1';
	if (*p++ == '#') nt = 1;

	if (p[0] == 'T'){
		p += 5;
		return ((memory[i][j] == 0) ^ nt);
	}else if (p[0] == 'C'){
		p += 5;
		return ((memory[i][j] == 1) ^ nt);
	}else{
		p += 4;
		return ((memory[i][j] == -1) ^ nt);
	}
}

int condition(char *&p){
	int res = cond(p);

	while (1){
		if (p[0] == 'A'){
			p += 3;
			res &= cond(p);
		}else if (p[0] == 'O'){
			p += 2;
			res |= condition(p);
		}else break;
	}

	return res;
}

// Statements: TRADE=0 CHEAT=1
int statement(char *&p){
	int ret;

	if (p[0] == 'T') { p += 5; return 0; }
	if (p[0] == 'C') { p += 5; return 1; }
	p += 2;
	if (condition(p)){
		p += 4;
		ret = statement(p);
		p += 4;
		statement(p);
	}else{
		p += 4;
		statement(p);
		p += 4;
		ret = statement(p);
	}

	return ret;
}

void play(int a, int b){
	int i, j, k;
	char *p;

	memory[0][0] = memory[0][1] = memory[1][0] = memory[1][1] = -1;
	for (i = 0; i < 10; ++i){
		c = 0; p = programs[a]; j = statement(p);
		c = 1; p = programs[b]; k = statement(p);

		if (j == 0){
			if (k == 0) ++score[a], ++score[b];
			else score[a] -= 2, score[b] += 2;
		}else{
			if (k == 0) score[a] += 2, score[b] -= 2;
			else --score[a], --score[b];
		}

		memory[0][1] = memory[0][0]; memory[0][0] = j;
		memory[1][1] = memory[1][0]; memory[1][0] = k;
	}
}

int main(){
	int N = 0, i, j;
	char *p;

	while (1){
		p = programs[N];
		while ((i = getchar()) != '.'){
			if (i != ' ' && i != '\n') *p++ = i;
		}
		*p = 0;
		++N;

		while ((i = getchar()) == ' ' || i == '\n');
		if (i == '#') break;
		ungetc(i, stdin);
	}

	for (i = 0; i < N; ++i) score[i] = 0;
	for (i = 0; i < N; ++i){
		for (j = i + 1; j < N; ++j){
			play(i, j);
		}
	}
	for (i = 0; i < N; ++i) printf("%3d\n", score[i]);

	return 0;
}
/* @END_OF_SOURCE_CODE */
