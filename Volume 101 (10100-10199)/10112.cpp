/* @JUDGE_ID: 19899RK 10112 C++ "By Anadan" */
// Myacm Triangles
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <math.h>

int a, b, c, n, pt[30];
double s;

int isIn(int i, int j, int k){
    int x;
    double tmp;
    for (x = 0; x < n; x++){
	if ((x == i) || (x == j) || (x == k)) continue;
	s = fabs(0.5 * ( (pt[2*k+1]-pt[2*i+1]) * (pt[2*j]-pt[2*i]) - (pt[2*j+1]-pt[2*i+1]) * (pt[2*k]-pt[2*i]) ));
	tmp = fabs(0.5 * ( (pt[2*k+1]-pt[2*x+1]) * (pt[2*j]-pt[2*x]) - (pt[2*j+1]-pt[2*x+1]) * (pt[2*k]-pt[2*x]) ));
	tmp += fabs(0.5 * ( (pt[2*k+1]-pt[2*i+1]) * (pt[2*x]-pt[2*i]) - (pt[2*x+1]-pt[2*i+1]) * (pt[2*k]-pt[2*i]) ));
	tmp += fabs(0.5 * ( (pt[2*x+1]-pt[2*i+1]) * (pt[2*j]-pt[2*i]) - (pt[2*j+1]-pt[2*i+1]) * (pt[2*x]-pt[2*i]) ));
	if (fabs(tmp-s) < 10e-12) return 1;
    }
    return 0;
}

void func(){
    int i, j, k;
    double maxs = 0.0;

    for (i = 0; i < n - 2; i++){
	for (j = i + 1; j < n; j++){
	    for (k = j + 1; k < n; k++){
		if (!isIn(i, j, k)){
		   if (s > maxs) {
		      maxs = s;
		      a = i; b = j; c = k;
		   }
		}
	    }
	}
    }
}

int main(){
	char s[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i, m;

	while (scanf("%d\n", &n) > 0){
		if (n == 0) break;
		for (i = m = 0; i < n; i++){
			char ch;
			scanf("%c %d %d\n", &ch, &pt[m], &pt[m+1]);
			m += 2;
		}
		func();
		printf("%c%c%c\n", s[a], s[b], s[c]);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
