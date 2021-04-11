/* @JUDGE_ID: 19899RK 144 C++ "By Anadan" */
// Student Grants
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#include <string.h>

struct Student{
	int n, grant;
}st[25];

int main(){
	int i, N, lim_k, cur_k, store, cur_st;

	while (scanf("%d%d", &N, &lim_k) == 2){
		if (N == 0 && lim_k == 0) break;
		for (i = 0; i < N; i++){
			st[i].n = i + 1;
			st[i].grant = 40;
		}

		cur_k = 1;
		store = cur_st = 0;

		while (N > 1){
			if (!store){
				store += cur_k;
				if (++cur_k > lim_k) cur_k = 1;
			}

			if (st[cur_st].grant > store){
				st[cur_st].grant -= store;
				store = 0;
				if (++cur_st == N) cur_st = 0;
			}else{
				store -= st[cur_st].grant;
				printf("%3d", st[cur_st].n);
				memcpy(st + cur_st, st + cur_st + 1, sizeof(Student) * (N - cur_st - 1));
				if (cur_st == --N) cur_st = 0;
			}
		}

		printf("%3d\n", st[0].n);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
