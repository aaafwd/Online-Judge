/* @JUDGE_ID: 19899RK 10158 C++ "By Anadan" */
// War
// Accepted (2.822 seconds using as much as 480 kbytes)
// Too much time!

#include <stdio.h>
#define SZ 10000

int p[SZ], rank[SZ], N;
char mask[SZ];

int getp(int i){
	if (p[i] != i) p[i] = getp(p[i]);
	return p[i];
}

void link(int i, int j){
	i = getp(i);
	j = getp(j);
	
	if (rank[i] > rank[j]) p[j] = i;
	else{
		p[i] = j;
		if (rank[i] == rank[j]) ++rank[j];
	}
}

void invert(int k){
	int i;
	for (i = 0; i < N; ++i) if (getp(i) == k) mask[i] ^= 1;
}

int main(){
	int i, j, k;

	scanf("%d", &N);
	for (i = 0; i < N; ++i){
		p[i] = i;
		rank[i] = 0;
		mask[i] = 0;
	}

	while (scanf("%d%d%d", &k, &i, &j) == 3 && k){
		if (k < 3){
			if (getp(i) != getp(j)){
				if ((mask[i] == mask[j]) ^ (k == 1)) invert(getp(i));
				link(i, j);
			}else{
				if ((mask[i] == mask[j]) ^ (k == 1)) puts("-1");
			}
		}else{
			if (getp(i) != getp(j)) puts("0");
			else puts(((mask[i] == mask[j]) ^ (k == 3)) ? "0" : "1");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
