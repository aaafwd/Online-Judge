/* @JUDGE_ID: 19899RK 378 C++ "By Anadan" */ 
// Intersecting Lines
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>

struct POINT{
	long x, y;
};

void isCrossed(POINT p1, POINT p2, POINT p3, POINT p4){
	long det = (p2.x - p1.x) * (p3.y - p4.y) - (p3.x - p4.x) * (p2.y - p1.y);
	long it1 = (p3.x - p1.x) * (p3.y - p4.y) - (p3.x - p4.x) * (p3.y - p1.y);
	long it2 = (p2.x - p1.x) * (p3.y - p1.y) - (p3.x - p1.x) * (p2.y - p1.y);

	if (det == 0){
		if (it1 == 0 && it2 == 0) printf("LINE\n");
		else printf("NONE\n");
	}else{
		double t = double(it1) / double(det), tmp = t;
		tmp *= double(p2.x - p1.x); tmp += double(p1.x);
		printf("POINT %.2lf ", tmp);
		tmp = t * double(p2.y - p1.y) + double(p1.y);
		printf("%.2lf\n", tmp);
	}
}

int main(){
	int N;
	POINT p1, p2, p3, p4;
	scanf("%d", &N);
	printf("INTERSECTING LINES OUTPUT\n");
	while (N--){
		scanf("%ld%ld%ld%ld", &p1.x, &p1.y, &p2.x, &p2.y);
		scanf("%ld%ld%ld%ld", &p3.x, &p3.y, &p4.x, &p4.y);
		isCrossed(p1, p2, p3, p4);
	}
	printf("END OF OUTPUT\n");
	return 0;
}
/* @END_OF_SOURCE_CODE */
