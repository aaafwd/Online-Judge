/* @JUDGE_ID: 19899RK 138 C++ "By Anadan" */
// Street Numbers
// ONLINE_JUDGE: Accepted (0.000 seconds with low memory spent)
// Accepted (19.500 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <math.h>

int main(){
#ifdef ONLINE_JUDGE
	printf("         6         8\n");
	printf("        35        49\n");
	printf("       204       288\n");
	printf("      1189      1681\n");
	printf("      6930      9800\n");
	printf("     40391     57121\n");
	printf("    235416    332928\n");
	printf("   1372105   1940449\n");
	printf("   7997214  11309768\n");
	printf("  46611179  65918161\n");
#else
	double n = 8.0, k;
	int i = 10;
	while (i--){
		while(1){
			k = sqrt(0.5 * n * (n + 1.0));
			if (k == floor(k)){
				printf("%10.0lf%10.0lf\n", k, n);
				break;
			}
			n += 1.0;
		}
		n += 1.0;
	}
	return 0;
#endif
}
/* @END_OF_SOURCE_CODE */
