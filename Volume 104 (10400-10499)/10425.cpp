/* @JUDGE_ID: 19899RK 10425 C++ "By Anadan" */ 
// Mobile Destroyer
// Accepted (0.016 seconds with low memory spent)

#include <stdio.h>

typedef long long qword;
inline qword sqr(qword x) { return x * x; }

int main(){
	char name[6];
	qword x1, y1, z1, r1, x2, y2, z2, r2, x, y, z, tmp1, tmp2;

	while (scanf("%s\n", name) == 1){
		printf("%s\n", name);
		scanf("%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &z1, &r1, &x2, &y2, &z2, &r2, &x, &y, &z);
		tmp1 = sqr(x1 - x) + sqr(y1 - y) + sqr(z1 - z) - r1 * r1;
		tmp2 = sqr(x2 - x) + sqr(y2 - y) + sqr(z2 - z) - r2 * r2;
		if (tmp1 <= 0) printf("y\n"); else printf("n\n");
		if (tmp2 <= 0) printf("y\n"); else printf("n\n");

		if (tmp1 <= 0){
			if (tmp2 <= 0){
				if (tmp1 == tmp2) printf("n\n");
				else printf("y\n");
			}else printf("y\n");
		}else if (tmp2 <= 0) printf("y\n");
		else printf("n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
