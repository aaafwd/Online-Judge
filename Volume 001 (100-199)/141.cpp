/* @JUDGE_ID: 19899RK 141 C++ "By Anadan" */ 
// The Spot Game
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>

struct Point{
	int x, y;
	int operator != (Point &p) { return (x != p.x || y != p.y); }
}pt[100][100], newp;
int np[100], move, N;
char action[2];

int test(int a, int b, int a1, int b1, int c1, int a2, int b2, int c2){
	int i, j;

	for (i = 0; i < np[a]; ++i){
		for (j = 0; j < np[b]; ++j){
			if (a1*pt[a][i].x + b1*pt[a][i].y + c1 == pt[b][j].x && a2*pt[a][i].x + b2*pt[a][i].y + c2 == pt[b][j].y) break;
		}
		if (j == np[b]) return 0;
	}

	return 1;
}

int repeated(int a, int b){
	return (test(a, b, 1, 0, 0, 0, 1, 0) || test(a, b, 0, 1, 0, -1, 0, N - 1) ||
		test(a, b, 0, -1, N - 1, 1, 0, 0) || test(a, b, -1, 0, N - 1, 0, -1, N - 1));
}

int isloose(){
	int i;

	np[move] = 0;
	if (action[0] == '+'){
		if (move){
			while (np[move] < np[move - 1]){
				pt[move][np[move]++] = pt[move - 1][np[move]];
			}
		}
		pt[move][np[move]++] = newp;
	}else{
		for (i = 0; i < np[move - 1]; ++i){
			if (pt[move - 1][i] != newp) pt[move][np[move]++] = pt[move - 1][i];
		}
	}

	for (i = 0; i < move; ++i){
		if (np[i] == np[move] && repeated(i, move)) return 1;
	}

	++move;
	return 0;
}

int main(){
	int i;

	while (scanf("%d\n", &N) == 1 && N){
		for (move = i = 0; i < N; ++i){
			scanf("%d%d%s\n", &newp.x, &newp.y, action);
			--newp.x; --newp.y;
			if (isloose()){
				scanf("%*d%*d%*s\n");
				printf("Player 2 wins on move %d\n", move + 1);
				break;
			}

			scanf("%d%d%s\n", &newp.x, &newp.y, action);
			--newp.x; --newp.y;
			if (isloose()){
				printf("Player 1 wins on move %d\n", move + 1);
				break;
			}
		}

		if (i == N) printf("Draw\n");
		else while (++i < N) scanf("%*d%*d%*s\n%*d%*d%*s\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
