/* @JUDGE_ID: 19899RK 615 C++ "By Anadan" */
// Is It A Tree?
// Accepted (0.010 seconds with low memory spent)

#include <stdio.h>
#define MAXSZ 200

int nodes_num[MAXSZ], nodes;
char G[MAXSZ][MAXSZ], error_flag;

int getnode(int n){
	int i;
	for (i = 0; i < nodes; ++i) if (nodes_num[i] == n) return i;
	nodes_num[nodes] = n;
	return nodes++;
}

int istree(){
	int i, j, k, root = -1, vertexes[MAXSZ];

	if (error_flag) return 0;
	for (i = 0; i < nodes; ++i){
		for (k = j = 0; j < nodes; ++j) if (G[j][i]) ++k;
		if (k > 1) return 0;
		if (k == 0){
			if (root != -1) return 0;
			root = i;
		}
	}

	if (root == -1) return 0;
	i = 0; j = 1; vertexes[0] = root;
	while (i < j){
		root = vertexes[i++];
		for (k = 0; k < nodes; ++k)
			if (G[root][k]) vertexes[j++] = k;
	}

	if (j != nodes) return 0;
	return 1;
}

int main(){
	int i, j, n, m, set = 0;

	while (1){
		nodes = 0;
		scanf("%d%d", &n, &m);
		if (n < 0 || m < 0) break;
		if (n == 0){
			printf("Case %d is a tree.\n", ++set);
			continue;
		}

		for (i = 0; i < MAXSZ; ++i) for (j = 0; j < MAXSZ; ++j) G[i][j] = 0;
		n = getnode(n);
		m = getnode(m);
		G[n][m] = 1;

		error_flag = 0;
		while (scanf("%d%d", &n, &m) == 2 && n){
			n = getnode(n); m = getnode(m);
			if (G[n][m]) error_flag = 1;
			G[n][m] = 1;
		}

		printf("Case %d is %sa tree.\n", ++set, (istree()) ? ("") : ("not "));
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
