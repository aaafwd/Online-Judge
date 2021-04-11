/* @JUDGE_ID: 19899RK 660 C++ "By Anadan" */ 
// Going in circles on Alpha Centauri
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#define SZ 5001

int N, M, R, weight[20], tidle[100], port[100], req_time, uti_time;
struct Order{
	int t, o, d, w;
}pt[SZ];

void donextorder(int n){
	int i, j = -1, k;

	for (i = 0; i < M; ++i){
		if (weight[i] < pt[n].w) continue;
		if (j == -1) j = i;
		else if (tidle[j] > pt[n].t){
			if (tidle[i] < tidle[j] || (tidle[i] == tidle[j] && ((pt[n].o - port[i] + N) % N) < ((pt[n].o - port[j] + N) % N))){
				j = i;
			}
		}else if (tidle[i] <= pt[n].t && ((pt[n].o - port[i] + N) % N) < ((pt[n].o - port[j] + N) % N)){
			j = i;
		}
	}

	if (tidle[j] > pt[n].t) req_time += tidle[j] - pt[n].t;
	else tidle[j] = pt[n].t;
	k = (pt[n].o - port[j] + N) % N + (pt[n].d - pt[n].o + N) % N + 10;
	req_time += k;
	tidle[j] += k;
	uti_time += k;
	port[j] = pt[n].d;
}

int main(){
	int set = 0, i, T;

	while (scanf("%d%d", &N, &M) == 2 && N){
		for (i = 0; i < M; ++i) scanf("%d", weight + i);
		for (i = 0; i < M; ++i) tidle[i] = port[i] = 0;
		R = 0;
		while (scanf("%d%d%d%d", &pt[R].t, &pt[R].o, &pt[R].d, &pt[R].w) == 4 && pt[R].t != -1){
			--pt[R].o; --pt[R].d;
			++R;
		}

		req_time = uti_time = 0;
		for (i = 0; i < R; ++i){
			donextorder(i);
			if (pt[0].t > pt[i].t) pt[0].t = pt[i].t;
		}

		for (T = tidle[0], i = 1; i < M; ++i){
			if (T < tidle[i]) T = tidle[i];
		}
		T -= pt[0].t;

		printf("Simulation %d\n", ++set);
		printf("Average wait time   = %.3lf minutes\n", double(req_time) / R);
		printf("Average utilization = %.3lf %%\n\n", double(uti_time) / T / M * 100.0);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
