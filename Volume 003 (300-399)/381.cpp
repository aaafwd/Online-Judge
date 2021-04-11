/* @JUDGE_ID: 19899RK 381 C++ "By Anadan" */ 
// Making the Grade
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int S, T, bonus[30], att[30];
double avg[30];

int main(){
	int set, i, j, k, min, sum;
	double mean, sd;

	puts("MAKING THE GRADE OUTPUT");
	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &S, &T);
		mean = 0.0;
		for (i = 0; i < S; ++i){
			sum = 0;
			min = 1000;
			for (j = 0; j < T; ++j){
				scanf("%d", &k);
				sum += k;
				if (min > k) min = k;
			}

			if (T > 2) avg[i] = double(sum - min) / double(T - 1);
			else avg[i] = double(sum) / T;
			avg[i] = floor(avg[i] * 10 + 0.5) * 0.1;

			scanf("%d%d", &bonus[i], &att[i]);
			mean += avg[i];
		}

		mean /= S;
		mean = floor(mean * 10 + 0.5) * 0.1;

		sd = 0;
		for (i = 0; i < S; ++i){
			sd += (avg[i] - mean) * (avg[i] - mean);
		}
		sd = sqrt(sd / S);
		sd = floor(sd * 10 + 0.5) * 0.1;
		if (sd < 1.0) sd = 1.0;

		for (sum = i = 0; i < S; ++i){
			avg[i] += (bonus[i] >> 1) * 3;

			if (avg[i] >= mean + sd - 1e-12) j = 4;
			else if (avg[i] >= mean - 1e-12) j = 3;
			else if (avg[i] >= mean - sd - 1e-12) j = 2;
			else j = 1;

			if (att[i] == 0) ++j;
			else j -= att[i] / 4;

			if (j < 0) j = 0;
			if (j > 4) j = 4;

			sum += j;
		}

		printf("%.1lf\n", double(sum) / S);
	}
	puts("END OF OUTPUT");

	return 0;
}
/* @END_OF_SOURCE_CODE */
