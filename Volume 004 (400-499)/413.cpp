/* @JUDGE_ID: 19899RK 413 C++ "By Anadan" */ 
// Up and Down Sequences
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

int main(){
	int usum, un, dsum, dn, n, old, count, u_or_d, nr;
	float uf, df;

	while(1){
		usum = dsum = un = dn = u_or_d = 0;
		scanf("%d", &old);
		if (old == 0) break;
		count = 0; nr = 1;

		while(1){
			scanf("%d", &n);
			if (n == 0) break;
			nr++;
			if (n == old){
				if (u_or_d == 0){
					count++;
					continue;
				}
				if (u_or_d == 1) usum++;
				else dsum++;
				continue;
			}
			if (n > old){
				if (u_or_d == 0){
					u_or_d = 1;
					count++;
					usum = count;
					un++;
				}
				else if (u_or_d == 1) usum++;
				else{
					u_or_d = 1;
					un++;
					usum++;
				}
			}else{
				if (u_or_d == 0){
					u_or_d = 2;
					count++;
					dsum = count;
					dn++;
				}
				else if (u_or_d == 2) dsum++;
				else{
					u_or_d = 2;
					dn++;
					dsum++;
				}
			}
			old = n;
		}
		if (un == 0) uf = 0.0;
		else uf = 1.0*usum/un;
		if (dn == 0) df = 0.0;
		else df = 1.0*dsum/dn;
		printf("Nr values = %d:  %.6f %.6f\n", nr, uf, df);
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
