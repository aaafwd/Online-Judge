/* @JUDGE_ID: 19899RK 600 C++ "By Anadan" */
// A Duckpin Tournament
// Accepted (0.000 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

int balls[3][12];

int getbonus(int n, int q){
	int res = balls[0][n], tmp;

	if (res < 0) return 0;
	if (q == 2){
		tmp = balls[1][n];
		if (tmp < -10) tmp = balls[0][n + 1];
		if (tmp > 0) res += tmp;
	}

	return res;
}

void readdata(){
	int i, k;
	char flag;

	for (i = 0; i < 12; ++i) balls[0][i] = balls[1][i] = balls[2][i] = -100;
	i = 0; flag = 0;
	while ((k = getchar()) != '\n'){
		if (k == '-'){
			flag = 1;
			k = getchar();
		}

		if (k == '1'){
			if ((k = getchar()) == '0'){
				balls[0][i++] = (flag) ? (-10) : (10);
			}else{
				ungetc(k, stdin);
				balls[0][i++] = (flag) ? (-1) : (1);
			}
			flag = 0;
		}else if ('0' <= k && k <= '9'){
			if (flag) balls[0][i++] = -k + '0';
			else balls[0][i++] = k - '0';
			flag = 0;
		}
	}

	i = 0; flag = 0;
	while ((k = getchar()) != '\n'){
		if (k == '-'){
			flag = 1;
			k = getchar();
		}

		if (k == '1'){
			if ((k = getchar()) == '0'){
				k = (flag) ? (-10) : (10);
			}else{
				ungetc(k, stdin);
				k = (flag) ? (-1) : (1);
			}
			flag = 0;
		}else if ('0' <= k && k <= '9'){
			k -= '0';
			if (flag) { k = -k; flag = 0; }
		}else continue;

		if (k < 0) while (balls[0][i] < 0 || balls[0][i] == 10) ++i;
		else while (balls[0][i] < 0 || balls[0][i] == 10 || balls[0][i] + k > 10) ++i;
		balls[1][i++] = k;
	}

	i = 0; flag = 0;
	while ((k = getchar()) != '\n'){
		if (k == '-'){
			flag = 1;
			k = getchar();
		}

		if (k == '1'){
			if ((k = getchar()) == '0'){
				k = (flag) ? (-10) : (10);
			}else{
				ungetc(k, stdin);
				k = (flag) ? (-1) : (1);
			}
			flag = 0;
		}else if ('0' <= k && k <= '9'){
			k -= '0';
			if (flag) { k = -k; flag = 0; }
		}else continue;

		if (k < 0) while (balls[0][i] == 10 || balls[1][i] < 0 || balls[0][i] + balls[1][i] == 10) ++i;
		else while (balls[1][i] < 0 || balls[0][i] + balls[1][i] == 10 || balls[0][i] + balls[1][i] + k > 10) ++i;
		balls[2][i++] = k;
	}
}

int main(){
	int N, i, j, game, score, cur, tmp, off;
	int high_score, winner, series[4];
	char names[4][11];

	while (scanf("%d\n", &N) == 1 && N){
		for (i = 0; i < N; ++i){
			scanf("%s\n", names[i]);
			series[i] = 0;
		}

		high_score = 0;
		for (game = 0; game < 3; ++game){
			for (i = 0; i < N; ++i){
				printf("%-10s", names[i]);
				readdata();
				for (score = j = 0; j < 10; ++j){
					cur = balls[0][j];
					if (cur < 0) cur = 0;
					else if (cur == 10) cur += getbonus(j + 1, 2);
					else if (balls[1][j] >= 0){
						cur += balls[1][j];
						if (cur == 10) cur += getbonus(j + 1, 1);
						else if (balls[2][j] > 0) cur += balls[2][j];
					}
					score += cur;
					printf("%4d", score);
				}

				if (high_score < score){
					high_score = score;
					winner = i;
				}
				series[i] += score;
				putchar('\n');
			}
		}

		for (j = i = 0; i < N; ++i) if (j < series[i]){
			j = series[i];
			tmp = i;
		}
		printf("%s has the high series score of %d.\n", names[tmp], j);
		printf("%s has the high game score of %d.\n\n", names[winner], high_score);
		scanf("%*s");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
