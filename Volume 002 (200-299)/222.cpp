/* @JUDGE_ID: 19899RK 222 C++ "By Anadan" */ 
// Budget Travel
// Accepted (0.006 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

struct Gasoline{
	double dist, price, toend;
}pt[75];
int N;
double tank, gpm, min;

void setmin(int i, double cur, double gas){
	for (;; ++i){
		if (min != -1 && cur >= min) return;

		if (i == N){
			min = cur;
			return;
		}

		if (gas > 0.5 * tank && gas >= (pt[i + 1].dist - pt[i].dist) * gpm - 1e-12){
			gas -= (pt[i + 1].dist - pt[i].dist) * gpm;
			continue;
		}

		if (gas >= (pt[i + 1].dist - pt[i].dist) * gpm - 1e-12){
			setmin(i + 1, cur, gas - (pt[i + 1].dist - pt[i].dist) * gpm);
		}

		cur += 200 + (tank - gas) * pt[i].price;
		cur = floor(cur + 0.5);

		if (pt[i].toend != -1 && pt[i].toend <= cur + 1e-12) return;
		pt[i].toend = cur;

		gas = tank - (pt[i + 1].dist - pt[i].dist) * gpm;
	}
}

int main(){
	int set = 0, i;
	double dist, res;

	while (scanf("%lf", &dist) == 1 && dist > -1e-12){
		scanf("%lf%lf%lf%d", &tank, &gpm, &res, &N);
		gpm = 1.0 / gpm;
		for (i = 0; i < N; ++i){
			scanf("%lf%lf", &pt[i].dist, &pt[i].price);
			pt[i].toend = -1.0;
		}
		pt[N].dist = dist;

		res *= 100;
		res = floor(res + 0.5);

		min = -1.0;
		setmin(0, 0, tank - pt[0].dist * gpm);

		res += min;
		printf("Data Set #%d\n", ++set);
		printf("minimum cost = $%.2lf\n", res * 0.01);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
