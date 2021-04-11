/* @JUDGE_ID: 19899RK 565 C++ "By Anadan" */
// Pizza Anyone?
// Accepted (2.420 seconds using as much as 392 kbytes)

#include <stdio.h>
#include <string.h>
#define SZ 20

int N, b_tot, b_curr[16], curr[16];
char list[SZ][16], mask[16], setted[SZ];

void generate(int i, int tot){
	int k, flag, totset;
	char tmp[SZ];
	if (tot >= b_tot) return;

	for (; i < 16; ++i){
		if (!mask[i]) continue;
		for (k = 0; k < N; ++k){
			if (!setted[k] && list[k][i]) break;
		}

		if (k < N) break;
	}

	if (i == 16) return;

	// not include ('A' + i) component
	flag = 0;
	totset = 1;
	for (k = 0; k < N; ++k){
		tmp[k] = 0;
		if (setted[k]) continue;
		if (list[k][i] == -1){
			setted[k] = tmp[k] = 1;
			flag = 1;
		}else totset = 0;
	}

	if (!totset) generate(i + 1, tot);
	if (flag){
		for (k = 0; k < N; ++k) if (tmp[k]) setted[k] = 0;
	}

	if (totset){
		b_tot = tot;
		memcpy(b_curr, curr, sizeof(curr));
		return;
	}

	// try to include ('A' + i) component
	flag = 0;
	totset = 1;
	for (k = 0; k < N; ++k){
		tmp[k] = 0;
		if (setted[k]) continue;
		if (list[k][i] == 1){
			setted[k] = tmp[k] = 1;
			flag = 1;
		}else totset = 0;
	}

	curr[i] = 1;
	if (flag){
		if (!totset) generate(i + 1, tot + 1);
		for (k = 0; k < N; ++k) if (tmp[k]) setted[k] = 0;
	}

	if (totset && b_tot > tot + 1){
		b_tot = tot + 1;
		memcpy(b_curr, curr, sizeof(curr));
	}

	curr[i] = 0;
}

int main(){
	int i;
	char str[128], *p;

	while (scanf("%s", str) == 1){
		N = 0;
		memset(mask, 0, sizeof(mask));
		while (str[0] != '.'){
			memset(list[N], 0, sizeof(list[N]));
			for (p = str; *p && *p != ';'; p += 2){
				list[N][p[1] - 'A'] = (p[0] == '+' ? 1 : -1);
				mask[p[1] - 'A'] = 1;
			}

			++N;
			scanf("%s", str);
		}

		memset(setted, 0, N);
		memset(curr, 0, sizeof(curr));
		b_tot = 100;
		generate(0, 0);

		if (b_tot == 100) puts("No pizza can satisfy these requests.");
		else{
			printf("Toppings: ");
			for (i = 0; i < 16; ++i) if (b_curr[i]) putchar('A' + i);
			putchar('\n');
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
