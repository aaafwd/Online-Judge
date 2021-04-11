/* @JUDGE_ID: 19899RK 10204 C++ "By Anadan" */ 
// Adventures in Moving - Part V
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int w, h, l, H;
double tmp, tmp1;

int goes(int a, int b, int c){
	if (a > h || b > l || c > w) return 0;

	// Tilting forward
	if (a*a + b*b <= H*H) return 1;
	if (a*b <= l*H){
		tmp = (double(a) * sqrt(H*H - b*b) + double(b)*b) / H;
		tmp1 = sqrt(a*a + b*b);
		if (tmp < tmp1) tmp = tmp1;
		tmp -= h;
		if (tmp < 1e-12) return 1;
	}

	// Tilting sideways
	if (a <= H) return 1;
	if (a*a + c*c <= h*h){
		tmp1 = a*a + c*c;
		tmp = (sqrt(tmp1 - H*H) * (a*a-c*c) + a*c*H) / tmp1 - w;
		if (tmp < 1e-12) return 1;
	}

	return 0;
}

int main(){
	int a, b, c;

	while (scanf("%d%d%d%d\n", &w, &h, &l, &H) == 4){
		scanf("%d%d%d\n", &a, &b, &c);
		if (goes(a, b, c) || goes(a, c, b) || goes(b, a, c) ||
		    goes(b, c, a) || goes(c, a, b) || goes(c, b, a)){
			printf("The box goes on the truck.\n");
		}else printf("The box will not go on the truck.\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
