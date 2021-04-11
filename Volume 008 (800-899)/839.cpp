/* @JUDGE_ID: 19899RK 839 C++ "By Anadan" */
// Not so Mobile
// Accepted (0.380 seconds using as much as 388 kbytes)

#include <stdio.h>

char ok;

int equil(){
	int wl, dl, wr, dr;
	scanf("%d%d%d%d", &wl, &dl, &wr, &dr);
	if (wl == 0) wl = equil();
	if (wr == 0) wr = equil();
	if (wl*dl != wr*dr) ok = 0;
	return wl + wr;
}

int main(){
	int set;

	scanf("%d\n\n", &set);
	while (set--){
		ok = 1;
		equil();
		if (ok) printf("YES\n"); else printf("NO\n");
		if (set) printf("\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
