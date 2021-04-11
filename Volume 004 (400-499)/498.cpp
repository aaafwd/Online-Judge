/* @JUDGE_ID: 19899RK 498 C++ "By Anadan" */
// Polly the Polynomial
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

char str1[256], str2[256];
double ci[128], x;
int index, flag;

void func(){
	int i;
	double res = 0.0;

	for (i = 0; i < index; i++){
		res += ci[i] * pow(x, index-1-i);
	}
	if (flag) printf(" "); else flag = 1;
	printf("%.0lf", res);

}

int main(){
	char *p;
	int off;
	while (gets(str1) && gets(str2)){
		index = flag = 0;
		p = str1;
		while (sscanf(p, "%lf%n", &ci[index], &off) > 0){
			index++;
			p += off;
		}
		p = str2;
		while (sscanf(p, "%lf%n", &x, &off) > 0){
			func();
			p += off;
		}
		printf("\n");
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
