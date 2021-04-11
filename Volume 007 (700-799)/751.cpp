/* @JUDGE_ID: 19899RK 751 C++ "By Anadan" */ 
// Triangle War
// Accepted (0.129 seconds using as much as 652 kbytes)

#include <stdio.h>
#include <string.h>

char max[262144];
const int triags[18][4] = {
	{ 0, 0, 2, 4 },
	{ 0, 0, 1, 4 },
	{ 16, 32, 1, 2 },
	{ 0, 0, 16, 128 },
	{ 8, 128, 4, 32 },
	{ 4, 16, 64, 256 },
	{ 0, 0, 32, 256 },
	{ 8, 16, 1024, 2048 },
	{ 32, 64, 4096, 8192 },
	{ 0, 0, 1024, 32768 },
	{ 512, 32768, 128, 2048 },
	{ 128, 1024, 4096, 65536 },
	{ 256, 8192, 2048, 65536 },
	{ 256, 4096, 16384, 131072 },
	{ 0, 0, 8192, 131072 },
	{ 0, 0, 512, 1024 },
	{ 0, 0, 2048, 4096 },
	{ 0, 0, 8192, 16384 }
};

int getedge(int i, int j){
	switch (i){
		case 1: return j - 2;
		case 2: return j - 1;
		case 3: return j;
		case 4: return j + 2;
		case 5: return (j == 6) ? (8) : (j + 3);
		case 6: return j + 4;
		default: return i + 8;
	}
}

inline int owned(int state, int k){
	return ((state & triags[k][0]) && (state & triags[k][1])) + ((state & triags[k][2]) && (state & triags[k][3]));
}

int getmax(int state, int fr){
	int i, j, m = 0, tmp, x;

	if (max[state] != -1) return max[state];
	for (j = 1, i = 0; i < 18; ++i, j <<= 1){
		if (state & j) continue;
		if ((x = owned(state, i)) != 0){
			tmp = x + getmax(state | j, fr - x);
		}else{
			tmp = fr - getmax(state | j, fr);
		}

		if (m < tmp) m = tmp;
	}

	max[state] = m;
	return m;
}

void myscanf(int &x){
	int i;

	while ((x = getchar()) != EOF && (x < '0' || x > '9'));
	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
		x = x * 10 + i - '0';
	}
}

int main(){
	int game, g, m, i, j, k, x, c, score[2], state;

	memset(max, -1, sizeof(max));
	myscanf(game);
	for (g = 1; g <= game; ++g){
		myscanf(m);
		state = score[0] = score[1] = c = 0;
		while (m--){
			myscanf(i); myscanf(j);
			k = getedge(i, j);
			if ((x = owned(state, k)) != 0) score[c] += x;
			else c ^= 1;
			state |= 1 << k;
		}

		score[c] += getmax(state, 9 - score[0] - score[1]);
		score[c ^ 1] += 9 - score[0] - score[1];

		printf("Game %d: %c wins.\n", g, (score[0] > score[1]) ? ('A') : ('B'));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
