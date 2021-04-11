/* @JUDGE_ID: 19899RK 738 C++ "By Anadan" */
// A Logical Problem
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char map[102][102], str[27];

struct Tree{
	char cop, invert;
	struct Tree *left, *right;
}pt[1000];
int index;

void createbtree(int i, int j, char dir, Tree *T){
	char changedir = 0, inv;
	while (1){
		map[i][j] = ' ';
		if (changedir){
			changedir = 0;
			if (dir == '-'){
				if (i && map[i - 1][j] == '|') --i;
				else if (map[i + 1][j] == '|') ++i;
				dir = '|';
			}
			else if (dir == '|'){
				if (j && map[i][j - 1] == '-') --j;
				else if (map[i][j + 1] == '-') ++j;
				dir = '-';
			}
		}
		else if (dir == '-'){
			if (j && map[i][j - 1] == '-') --j;
			else if (map[i][j + 1] == '-') ++j;
			else{
				if (j && map[i][j - 1] == '+') --j;
				else if (map[i][j + 1] == '+') ++j;
				else{
					if (j && map[i][j - 1] != ' ') --j;
					else if (map[i][j + 1] != ' ') ++j;
					break;
				}
				changedir = 1;
			}
		}
		else if (dir == '|'){
			if (i && map[i - 1][j] == '|') --i;
			else if (map[i + 1][j] == '|') ++i;
			else{
				if (i && map[i - 1][j] == '+') --i;
				else if (map[i + 1][j] == '+') ++i;
				else{
					if (j && map[i - 1][j] != ' ') --i;
					else if (map[i + 1][j] != ' ') ++i;
					break;
				}
				changedir = 1;
			}
		}
		else break;
	}

	if (map[i][j] == 'o'){
		T->invert = 1;
		map[i][j--] = ' ';
	}else T->invert = 0;

	T->left = T->right = NULL;
	T->cop = map[i][j];
	if (isalpha(T->cop)){
		map[i][j] = ' ';
		return;
	}

	map[i][j] = map[i - 1][j - 1]  = map[i - 1][j - 2] = ' ';
	map[i][j - 2] = map[i + 1][j - 1]  = map[i + 1][j - 2] = ' ';

	if (map[i - 1][j - 3] == 'o') inv = 1; else inv = 0;
	T->left = &pt[index++];
	createbtree(i - 1, j - 3, '-', T->left);
	T->left->invert ^= inv;

	if (map[i + 1][j - 3] == 'o') inv = 1; else inv = 0;
	T->right = &pt[index++];
	createbtree(i + 1, j - 3, '-', T->right);
	T->right->invert ^= inv;
}

int getvalue(Tree *T){
	if (isalpha(T->cop)) return (str[T->cop - 'A'] - '0') ^ T->invert;
	if (T->cop == ')') return (getvalue(T->left) & getvalue(T->right)) ^ T->invert;
	return (getvalue(T->left) | getvalue(T->right)) ^ T->invert;
}

int main(){
	int N, i, j;
	char *p;

	while (1){
		N = index = 0;
		while (1){
			if (!gets(map[N])) return 0;
			strcat(map[N], " ");
			if (map[N][0] == '*') break;
			++N;
		}
		memset(map[N], ' ', 102);

		for (i = 0; i < N; ++i){
			if ((p = strchr(map[i], '?')) != NULL){
				j = int(p - map[i]);
				map[i][j] = ' ';
				if (map[i - 1][j] && map[i - 1][j] != ' ') --i;
				else if (map[i + 1][j] && map[i + 1][j] != ' ') ++i;
				else if (map[i][j - 1] && map[i][j - 1] != ' ') --j;
				else if (map[i][j + 1] && map[i][j + 1] != ' ') ++j;
				createbtree(i, j, map[i][j], &pt[index++]);
				break;
			}
		}

		while (gets(str) && str[0] != '*'){
			printf("%d\n", getvalue(&pt[0]) & 1);
		}

		printf("\n");
	}
}
/* @END_OF_SOURCE_CODE */
