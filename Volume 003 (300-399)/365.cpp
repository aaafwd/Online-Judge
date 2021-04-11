/* @JUDGE_ID: 19899RK 365 C++ "By Anadan" */
// Welfare Reform
// Accepted (0.271 seconds using as much as 392 kbytes)

#include <stdio.h>

inline int getage(int mm, int dd, int yy){
	int res = 96 - yy;
	if (mm > 9 || (mm == 9 && dd > 1)) --res;
	return res;
}

int main(){
	int income[10][12], ages[10], i, j, k, N, set, ifee;
	int mm[10], dd[10], yy[10];
	double fee[12], tmp;
	char name[21];

	for (i = 0; i < 12; ++i){
		scanf("%lf", fee + i);
		for (j = 0; j < 10; ++j) scanf("%d", &income[j][i]);
	}

	scanf("%d\n", &set);
	while (set--){
		scanf("%s\n", name);
		scanf("%d%d\n", &N, &j);

		for (ifee = 1; ifee < 12; ++ifee) if (j < income[N - 1][ifee]) break;
		--ifee;

		for (i = 0, j = -1; i < N; ++i){
			scanf("%d%d%d\n", mm + i, dd + i, yy + i);
			ages[i] = getage(mm[i], dd[i], yy[i]);
			if (ages[i] < 13){
				if (j == -1 || j > ages[i]) j = ages[i], k = i;
				else if (j == ages[i]){
					if (yy[k] < yy[i]) k = i;
					else if (yy[k] == yy[i]){
						if (mm[k] < mm[i]) k = i;
						else if (mm[k] == mm[i]){
							if (dd[k] < dd[i]) k = i;
						}
					}
				}
			}
		}

		tmp = fee[ifee] * 0.5;
		for (i = 0; i < N; ++i){
			printf("%s %d ", name, ages[i]);
			if (ages[i] < 13){
				if (i == k) printf("%.2lf\n", fee[ifee]);
				else printf("%.2lf\n", tmp);
			}else printf("0.00\n");
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
