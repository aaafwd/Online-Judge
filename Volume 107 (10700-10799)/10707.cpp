/* @JUDGE_ID: 19899RK 10707 C++ "By Anadan" */
// 2-D Nim
// Accepted (5.240 seconds using as much as 428 kbytes)
// Too much time !

#include <stdio.h>
#include <string.h>

int W, H, st, nst;
char m1[100][100], m2[100][100], pt1[3010];
int dx[]={ 1, 0,-1, 0 };
int dy[]={ 0,-1, 0, 1 };

inline int valid(int x, int y) { return 0 <= x && 0 <= y && x < W && y < H; }

void path1(int i, int j){
	int k, val = 0;
	m1[i][j] = 0;
	for (k = 0; k < 4; ++k){
		if (valid(i+dx[k], j+dy[k]) && m1[i+dx[k]][j+dy[k]]){
			val |= 1 << k;
			path1(i+dx[k], j+dy[k]);
		}
	}
	pt1[st++] = val;
}

int path2(int i, int j){
	int k, val = 0;
	m2[i][j] = 0;
	for (k = 0; k < 4; ++k){
		if (valid(i+dx[k], j+dy[k]) && m2[i+dx[k]][j+dy[k]]){
			if (!path2(i+dx[k], j+dy[k])) return 0;
			val |= 1 << k;
		}
	}
	if (nst >= st || pt1[nst++] != val) return 0;
	return 1;
}

int coinside(int i, int j){
	int k;
	char tmp[100][100];

	memcpy(tmp, m2, sizeof(m2));

	for (k = 0; k < 4; ++k){
		nst = 0;
		if (path2(i, j) && nst == st) return 1;

		dx[0] ^= dx[1] ^= dx[0] ^= dx[1]; dy[0] ^= dy[1] ^= dy[0] ^= dy[1];
		dx[1] ^= dx[2] ^= dx[1] ^= dx[2]; dy[1] ^= dy[2] ^= dy[1] ^= dy[2];
		dx[2] ^= dx[3] ^= dx[2] ^= dx[3]; dy[2] ^= dy[3] ^= dy[2] ^= dy[3];

		memcpy(m2, tmp, sizeof(m2));
	}

	dx[0] ^= dx[3] ^= dx[0] ^= dx[3]; dy[0] ^= dy[3] ^= dy[0] ^= dy[3];
	dx[1] ^= dx[2] ^= dx[1] ^= dx[2]; dy[1] ^= dy[2] ^= dy[1] ^= dy[2];

	for (k = 0; k < 4; ++k){
		nst = 0;
		if (path2(i, j) && nst == st) return 1;

		dx[0] ^= dx[1] ^= dx[0] ^= dx[1]; dy[0] ^= dy[1] ^= dy[0] ^= dy[1];
		dx[1] ^= dx[2] ^= dx[1] ^= dx[2]; dy[1] ^= dy[2] ^= dy[1] ^= dy[2];
		dx[2] ^= dx[3] ^= dx[2] ^= dx[3]; dy[2] ^= dy[3] ^= dy[2] ^= dy[3];

		memcpy(m2, tmp, sizeof(m2));
	}

	return 0;
}

int found(int i, int j){
	st = 0;
	path1(i, j);
	for (i = 0; i < W; ++i) for (j = 0; j < H; ++j){
		if (m2[i][j] && coinside(i, j)) return 1;
	}
	return 0;
}

int equal(){
	int i, j;
	for (i = 0; i < W; ++i) for (j = 0; j < H; ++j){
		if (m1[i][j] && !found(i, j)) return 0;
	}
	return 1;
}

int main(){
	int set, N, i, j, k;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d%d", &W, &H, &N);
		memset(m1, 0, sizeof(m1));
		memset(m2, 0, sizeof(m2));
		for (k = 0; k < N; ++k){
			scanf("%d%d", &i, &j);
			m1[i][j] = 1;
		}
		for (k = 0; k < N; ++k){
			scanf("%d%d", &i, &j);
			m2[i][j] = 1;
		}

		puts(equal() ? "YES" : "NO");
	}
	
	return 0;
}
/* @END_OF_SOURCE_CODE */
