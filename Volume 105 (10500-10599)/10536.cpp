/* @JUDGE_ID: 19899RK 10536 C++ "By Anadan" */
// Game of Euler
// Accepted (0.184 seconds using as much as 456 kbytes)

#include <stdio.h>

char win[65536];
const int hmask[4] = { 3, 7, 12, 14 };
const int vmask[4] = { 0x11, 0x111, 0x1100, 0x1110 };

void solve(){
	int i, j, k, c;

	win[65535] = 1;
	for (i = 65534; i >= 0; --i){
		win[i] = 0;
		for (j = 1; j < 65536; j <<= 1){
			if (!(i & j) && !win[i | j]){
				win[i] = 1;
				goto next;
			}
		}

		for (k = 0; k < 4; ++k){
			c = hmask[k];
			for (j = 0; j < 4; ++j, c <<= 4){
				if (!(i & c) && !win[i | c]){
					win[i] = 1;
					goto next;
				}
			}
		}

		for (k = 0; k < 4; ++k){
			c = vmask[k];
			for (j = 0; j < 4; ++j, c <<= 1){
				if (!(i & c) && !win[i | c]){
					win[i] = 1;
					goto next;
				}
			}
		}

		next:;
	}
}

int main(){
	int set, i, j, res;

	solve();

	scanf("%d", &set);
	while (set--){
		res = 0;
		for (i = 0; i < 16; ++i){
			while ((j = getchar()) != 'X' && j != '.');
			if (j == 'X') res |= (1 << i);
		}

		puts(win[res] ? "WINNING" : "LOSING");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
