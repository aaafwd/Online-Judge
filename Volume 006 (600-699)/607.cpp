/* @JUDGE_ID: 19899RK 607 C++ "By Anadan" */ 
// Scheduling Lectures
// Accepted (0.102 seconds using as much as 400 kbytes)

#include <stdio.h>

struct DI{
	int lectures, di, time;
}pt[1000];

int main(){
	int N, L, C, i, j, set, lect, tmp, di;

	set = 0;
	while (scanf("%d", &N) == 1 && N){
		scanf("%d%d%d", &L, &C, &tmp);

		pt[0].time = tmp;
		pt[0].lectures = 1;
		tmp = long(L - tmp);
		if (tmp == 0) pt[0].di = 0;
		else if (tmp <= 10) pt[0].di = -C;
		else pt[0].di = (tmp - 10) * (tmp - 10);

		for (i = 1; i < N; ++i){
			scanf("%ld", &tmp);
			pt[i].time = tmp;

			if (L == tmp) pt[i].di = 0;
			else if (L - tmp <= 10) pt[i].di = -C;
			else pt[i].di = (L - tmp - 10) * (L - tmp - 10);
			pt[i].di += pt[i - 1].di;
			lect = pt[i].lectures = pt[i - 1].lectures + 1;

			for (j = i - 1; j >= 0; --j){
				tmp += pt[j].time;
				if (tmp > L) break;

				if (L == tmp) di = 0;
				else if (L - tmp <= 10) di = -C;
				else di = (L - tmp - 10) * (L - tmp - 10);
				if (j){
					di += pt[j - 1].di;
					lect = pt[j - 1].lectures + 1;
				}else lect = 1;

				if (pt[i].lectures < lect) continue;
				if (pt[i].lectures > lect || di < pt[i].di){
					pt[i].di = di;
					if (j) pt[i].lectures = lect;
					else pt[i].lectures = 1;
				}
			}
		}

		if (set) putchar('\n');
		printf("Case %d:\n", ++set);
		printf("Minimum number of lectures: %d\n", pt[N - 1].lectures);
		printf("Total dissatisfaction index: %ld\n", pt[N - 1].di);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
