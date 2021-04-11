/* @JUDGE_ID: 19899RK 122 C++ "By Anadan" */
// Trees on the level
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
char error;
struct Node{
	char *path;
	int value, l;
}nd[256];

char *_strdup(char *s){
	int i = strlen(s);
	s[i - 1] = 0;
	return strcpy((char *)malloc(i), s);
}

int sort_function(const void *a, const void *b){
	int i;
	Node *p1 = (Node *)a, *p2 = (Node *)b;

	if (p1->l < p2->l) return -1;
	if (p1->l > p2->l) return 1;
	i = strcmp(p1->path, p2->path);
	if (i == 0) error = 1;
	return i;
}

int complete(int n){
	char c;
	int i, j = nd[n].l - 1;

	c = nd[n].path[j];
	nd[n].path[j] = 0;

	for (i = n - 1; nd[i].l >= j; i--){
		if (!strcmp(nd[i].path, nd[n].path)){
			nd[n].path[j] = c;
			return 1;
		}
	}
	return 0;
}

int printlevels(){
	int i, off;
	char str[3000], *p = str;

	if (error) return 1;
	if (N == 0) return 1;
	if (nd[0].path[0]) return 1;

	sprintf(p, "%d%n", nd[0].value, &off);
	p += off;

	for (i = 1; i < N; i++){
		if (!complete(i)) return 1;
		sprintf(p, " %d%n", nd[i].value, &off);
		p += off;
	}

	*p = 0;
	printf("%s\n", str);
	return 0;
}

int main(){
	int i;
	char str[300];

	N = 0;
	error = 0;
	while (scanf("%s", str) > 0){
		if (str[1] ==  ')'){
			qsort((void *)nd, N, sizeof(Node), sort_function);
			if (printlevels()) printf("not complete\n");
			for (i = 0; i < N; i++) free(nd[i].path);
			N = 0;
			error = 0;
		}else{
			sscanf(str, "(%d,%n", &nd[N].value, &i);
			nd[N].path = _strdup(str + i);
			nd[N].l = strlen(nd[N].path);
			++N;
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
