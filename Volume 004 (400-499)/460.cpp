/* @JUDGE_ID: 19899RK 460 C++ "By Anadan" */
// Overlapping Rectangles
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

struct Rect{
	int xll, yll, xur, yur;
}r1, r2, res;

int intersectRect(){
	if (r1.xll > r2.xll) { res = r1; r1 = r2; r2 = res; }
	if (r2.xll >= r1.xur) return 0;
	if (r2.yll >= r1.yur) return 0;
	if (r2.yur <= r1.yll) return 0;
	res.xll = r2.xll;
	if (r2.xur < r1.xur) res.xur = r2.xur; else res.xur = r1.xur;
	if (r2.yll > r1.yll) res.yll = r2.yll; else res.yll = r1.yll;
	if (r2.yur < r1.yur) res.yur = r2.yur; else res.yur = r1.yur;
	return 1;
}

int main(){
	long set;
	scanf("%ld\n\n", &set);

	while (set--){
		scanf("%d%d%d%d\n", &r1.xll, &r1.yll, &r1.xur, &r1.yur);
		scanf("%d%d%d%d\n", &r2.xll, &r2.yll, &r2.xur, &r2.yur);
		if (intersectRect()) printf("%d %d %d %d\n", res.xll, res.yll, res.xur, res.yur);
		else printf("No Overlap\n");
		if (set) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
