/* @JUDGE_ID: 19899RK 211 C++ "By Anadan" */
// The Domino Effect
// Accepted (0.310 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <string.h>

char domino[28];
int map[7][8], layout[8][9], solves;

int getdomino(int i, int j){
	if (i > j) { i ^= j; j ^= i; i ^= j; }
	switch(i){
		case 0: return j;
		case 1: return j + 6;
		case 2: return j + 11;
		case 3: return j + 15;
		case 4: return j + 18;
		case 5: return j + 20;
		case 6: return 27;
	}
	return -1;
}

void func(int i, int j, int index){
	int k, l, d;

	if (index == 27){
		k = l = -1;
		if (layout[i][j+1] == 0) k = i, l = j+1;
		else if (layout[i+1][j] == 0) k = i+1, l = j;
		if (k == -1) return;
		d = getdomino(map[i][j], map[k][l]);
		if (domino[d]) return;
		layout[i][j] = layout[k][l] = d + 1;

		for (int x = 0; x < 7; x++){
			putchar(' ');
			for (int y = 0; y < 8; y++) printf("%4d", layout[x][y]);
			putchar('\n');
		}
		putchar('\n');
		++solves;

		layout[i][j] = layout[k][l] = 0;
		return;
	}

	if (layout[i][j+1] == 0){
		d = getdomino(map[i][j], map[i][j+1]);
		if (!domino[d]){
			++domino[d];
			layout[i][j] = layout[i][j+1] = d + 1;
			for (k = i ;; k++){
				for (l = 0; l < 8; l++) if (layout[k][l] == 0) break;
				if (l < 8) break;
			}
			func(k, l, index + 1);
			layout[i][j] = layout[i][j+1] = 0;
			--domino[d];
		}
	}

	if (layout[i+1][j]== 0){
		d = getdomino(map[i][j], map[i+1][j]);
		if (!domino[d]){
			++domino[d];
			layout[i][j] = layout[i+1][j] = d + 1;
			for (k = i ;; k++){
				for (l = 0; l < 8; l++) if (layout[k][l] == 0) break;
				if (l < 8) break;
			}
			func(k, l, index + 1);
			layout[i][j] = layout[i+1][j] = 0;
			--domino[d];
		}
	}
}

int main(){
	int set = 0, i, j;

	for (i = 0; i < 8; i++) layout[7][i] = layout[i][8] = -1;
	while (1){
		for (i = 0; i < 7; i++) for (j = 0; j < 8; j++){
			if (scanf("%d", map[i] + j) < 1) return 0;
			layout[i][j] = 0;
		}
		if (set) printf("\n\n\n");
		printf("Layout #%d:\n\n", ++set);
		for (i = 0; i < 7; i++){
			putchar(' ');
			for (j = 0; j < 8; j++) printf("%4d", map[i][j]);
			putchar('\n');
		}
		printf("\nMaps resulting from layout #%d are:\n\n", set);

		solves = 0;
		memset(domino, 0, 28);
		func(0, 0, 0);

		printf("There are %d solution(s) for layout #%d.\n", solves, set);
	}
}
/* @END_OF_SOURCE_CODE */
