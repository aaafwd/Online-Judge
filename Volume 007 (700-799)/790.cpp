/* @JUDGE_ID: 19899RK 790 C++ "By Anadan" */ 
// Head Judge Headache
// Accepted (0.281 seconds using as much as 404 kbytes)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;
struct Log{
	int no;
	char problem[2], res[2];
	int time;
}log[256];

struct Team{
	int no, solved, tot_time;
	char mask[8];
	int time[8], tries[8];
}pt[25];

int sort_function(const void *a, const void *b){
	Team *ta = (Team *)a, *tb = (Team *)b;
	if (ta->solved > tb->solved) return -1;
	if (ta->solved < tb->solved) return 1;
	if (ta->tot_time < tb->tot_time) return -1;
	if (ta->tot_time > tb->tot_time) return 1;
	if (ta->no < tb->no) return -1;
	return 1;
}

int log_sort(const void *a, const void *b){
	if (((Log *)a)->time < ((Log *)b)->time) return -1;
	if (((Log *)a)->time > ((Log *)b)->time) return 1;
	if (((Log *)a)->res[0] == 'N') return -1;
	return 1;
}

int main(){
	int set, teamno, hh, mm, i, maxteam;
	char str[80];

	scanf("%d\n\n", &set);
	while (set--){
		N  = maxteam = 0;
		while (gets(str) && str[0]){
			sscanf(str, "%d %s %d:%d %s", &log[N].no, log[N].problem, &hh, &mm, log[N].res);
			if (maxteam < log[N].no) maxteam = log[N].no;
			log[N++].time = hh * 60 + mm;
		}

		qsort(log, N, sizeof(Log), log_sort);
		for (i = 0; i < maxteam; ++i){
			pt[i].no = i + 1;
			pt[i].solved = pt[i].tot_time = 0;
			memset(pt[i].mask, 0, 8);
			memset(pt[i].time, 0, 8 * sizeof(int));
			memset(pt[i].tries, 0, 8 * sizeof(int));
		}

		for (i = 0; i < N; ++i){
			mm = log[i].time;
			teamno = log[i].no - 1;
			if (pt[teamno].mask[*log[i].problem - 'A']) continue;
			if (*log[i].res == 'Y'){
				pt[teamno].mask[*log[i].problem - 'A'] = 1;
				++pt[teamno].solved;
				pt[teamno].tot_time += mm + pt[teamno].tries[*log[i].problem - 'A'] * 20;
			}else{
				++pt[teamno].tries[*log[i].problem - 'A'];
			}
		}

		qsort(pt, maxteam, sizeof(Team), sort_function);

		printf("RANK TEAM PRO/SOLVED TIME\n");
		for (i = 0, hh = 0; i < maxteam; ++i){
			if (i == 0 || pt[i - 1].solved != pt[i].solved || pt[i - 1].tot_time != pt[i].tot_time) hh = i + 1;
			printf("%4d %4d", hh, pt[i].no);
			if (pt[i].solved == 0) putchar('\n');
			else printf(" %4d %10d\n", pt[i].solved, pt[i].tot_time);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
