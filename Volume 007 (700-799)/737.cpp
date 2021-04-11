/* @JUDGE_ID: 19899RK 737 C++ "By Anadan" */
// Gleaming the Cubes
// Accepted (0.160 seconds using as much as 388 kbytes)

#include <stdio.h>

struct Parallel{
	long xll, yll, zll, xur, yur, zur;
	long volume() { return ((xur - xll) * (yur - yll) * (zur - zll)); }
};

void intersectParallel(Parallel &r1, Parallel &r2){
	if (r2.xll >= r1.xur || r2.xur <= r1.xll || r2.yll >= r1.yur ||
	    r2.yur <= r1.yll || r2.zll >= r1.zur || r2.zur <= r1.zll){
		r1.xll = r1.xur = r1.yll = r1.yur = r1.zll = r1.zur = 0;
	}else{
		if (r2.xll > r1.xll) r1.xll = r2.xll;
		if (r2.xur < r1.xur) r1.xur = r2.xur;
		if (r2.yll > r1.yll) r1.yll = r2.yll;
		if (r2.yur < r1.yur) r1.yur = r2.yur;
		if (r2.zll > r1.zll) r1.zll = r2.zll;
		if (r2.zur < r1.zur) r1.zur = r2.zur;
	}
}

int main(){
	int i, N;
	long tmp;
	Parallel res, cur;

	while (scanf("%d", &N) > 0){
		if (N == 0) break;
		scanf("%ld%ld%ld%ld", &res.xll, &res.yll, &res.zll, &tmp);
		res.xur = res.xll + tmp;
		res.yur = res.yll + tmp;
		res.zur = res.zll + tmp;
		for (i = 1; i < N; i++){
			scanf("%ld%ld%ld%ld", &cur.xll, &cur.yll, &cur.zll, &tmp);
			cur.xur = cur.xll + tmp;
			cur.yur = cur.yll + tmp;
			cur.zur = cur.zll + tmp;
			intersectParallel(res, cur);
		}
		printf("%ld\n", res.volume());
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
