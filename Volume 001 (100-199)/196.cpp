/* @JUDGE_ID: 19899RK 196 C++ "By Anadan" */
// Spreadsheet
// Accepted (0.219 seconds using as much as 868 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define sheet(i, j) sheet_ptr[(i) * cols + (j)]

struct Node {
	int value;
	char *formula, *p;
}*sheet_ptr;

inline char *_strdup(char *str){
	return strcpy((char *)malloc(strlen(str) + 1), str);
}

inline void doparse(char *str, int &i, int &j){
	char *p = str + 1, ch;
	if ('A' <= *p && *p <= 'Z') ++p;
	if ('A' <= *p && *p <= 'Z') ++p;
	sscanf(p, "%d", &i);
	ch = *p; *p = 0;
	j = int(str[0] - 'A' + 1);
	if (str[1]){
		j = j * 26 + str[1] - 'A' + 1;
		if (str[2]){
			j = j * 26 + str[2] - 'A' + 1;
		}
	}
	*p = ch;
	--i; --j;
}

int main(){
	int set, cols, rows, c, r, i, j, tmp;
	char str[1024], *p;

	scanf("%d\n", &set);
	while (set--){
		scanf("%d%d", &cols, &rows);
		sheet_ptr = (Node *)malloc(cols * rows * sizeof(Node));
		for (r = 0; r < rows; ++r){
			for (c = 0; c < cols; ++c){
				scanf("%s", str);
				if (str[0] == '='){
					sheet(r, c).value = 0;
					sheet(r, c).p = sheet(r, c).formula = _strdup(str + 1);
				}else{
					sscanf(str, "%d", &tmp);
					sheet(r, c).value = tmp;
					sheet(r, c).p = sheet(r, c).formula = NULL;
				}
			}
		}

		for (tmp = 1; tmp;){
			tmp = 0;
			for (r = 0; r < rows; ++r){
				for (c = 0; c < cols; ++c){
					if (sheet(r, c).p){
						p = sheet(r, c).p;
						while (p){
							doparse(p, i, j);
							if (sheet(i, j).p) break;
							sheet(r, c).value += sheet(i, j).value;
							p = strchr(p, '+');
							if (p) ++p;
							tmp = 1;
						}

						sheet(r, c).p = p;
					}
				}
			}
		}

		for (r = 0; r < rows; ++r){
			printf("%d", sheet(r, 0).value);
			for (c = 1; c < cols; ++c){
				printf(" %d", sheet(r, c).value);
			}
			putchar('\n');
		}

		for (r = 0; r < rows; ++r) for (c = 0; c < cols; ++c){
			if (sheet(r, c).formula) free(sheet(r, c).formula);
		}

		free(sheet_ptr);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
