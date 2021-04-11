/* @JUDGE_ID: 19899RK 10147 C++ "By Anadan" */ 
// Highways
// Accepted (0.246 seconds using as much as 412 kbytes)

#include <stdio.h>
#define MAX 750

struct Point{
	int x, y;
}pt[750];
int N, groups[750], rank[750], t[750], length[750];
char mask[750];

inline int sqr(int a) { return (int(a) * int (a)); }

int getgroups(int v){
	if (groups[v] != v) groups[v] = getgroups(groups[v]);
	return groups[v];
}

void addedge(int x, int y){
	x = getgroups(x);
	y = getgroups(y);

	if (rank[x] > rank[y]) groups[y] = x;
	else{
		groups[x] = y;
		if (rank[x] == rank[y]) ++rank[y];
	}
}

int mask_vertexes(int n){
	int masked = 0, m = groups[n], i, j;
	int tmp;

	for (i = 0; i < N; ++i) if (groups[i] == m){
			groups[i] = MAX;
			mask[i] = 1;
			++masked;
			for (j = 0; j < N; ++j) if (mask[j] == 0 && groups[j] != m && groups[j] != MAX){
				if (length[j] == -1L){
					length[j] = sqr(pt[i].x - pt[j].x) + sqr(pt[i].y - pt[j].y);
					t[j] = i;
				}
				else{
					tmp = sqr(pt[i].x - pt[j].x) + sqr(pt[i].y - pt[j].y);
					if (length[j] > tmp){
						length[j] = tmp;
						t[j] = i;
					}
				}
			}
	}

	return masked;
}

void myscanf(int &x){
	int i, sgn = 0;

	while ((x = getchar()) != EOF && x != '-' && (x < '0' || x > '9'));
	if (x == '-') { sgn = 1; x = getchar(); }

	x -= '0';
	while ((i = getchar()) != EOF && '0' <= i && i <= '9') x = x * 10 + i - '0';
	if (sgn) x = -x;
}

void myprintf(int x){
	if (x){
		myprintf(x / 10);
		putchar('0' + (x % 10));
	}
}

int main(){
	int i, x, y, M, masked, set, min;

	scanf("%d", &set);
	while (set--){
		scanf("%d", &N);
		for (i = 0; i < N; ++i){
			myscanf(pt[i].x); myscanf(pt[i].y);
			groups[i] = i;
			rank[i] = 0;
			mask[i] = 0;
			length[i] = -1;
		}

		myscanf(M);
		for (i = 0; i < M; ++i){
			myscanf(x); myscanf(y);
			addedge(x - 1, y - 1);
		}

		for (i = 0; i < N; ++i) groups[i] = getgroups(i);

		masked = mask_vertexes(0);
		if (masked == N) puts("No new highways need");
		while (masked < N){
			for (i = 0; i < N; ++i) if (!mask[i]) break;
			min = length[i];
			for (x = i++; i < N; ++i) if (mask[i] == 0 && length[i] < min){
				min = length[i];
				x = i;
			}

			myprintf(x + 1); putchar(' ');
			myprintf(t[x] + 1); putchar('\n');

			masked += mask_vertexes(x);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
