/* @JUDGE_ID: 19899RK 10044 C++ "By Anadan" */
// Erdos Numbers
// Accepted (1.287 seconds using as much as 20368 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSZ 4500

int index;
int ErdosNums[MAXSZ];

struct Names{
	char *name;
	int index;
}names[MAXSZ];
char map[MAXSZ][MAXSZ], cur_true;

int getindex(char *str){
	int i;
	for (i = 0; i < index; ++i) if (strcmp(names[i].name, str) == 0) return i;
	names[index].name = strcpy((char *)malloc(strlen(str) + 1), str);
	names[index].index = index;
	return index++;
}

int sort_function(const void *a, const void *b){
	return strcmp(((Names *)a)->name, ((Names *)b)->name);
}

int getindex2(char *str){
	Names a;
	a.name = str;

	Names *tmp = (Names *)bsearch(&a, names, index, sizeof(Names), sort_function);
	if (tmp == NULL) return index;
	return tmp->index;
}

void getErdosNums(){
	char mask[MAXSZ];
	int i, j = 1, v, k, vertexes[MAXSZ], count, step;

	memset(mask, 0, index);
	for (i = 0; i < MAXSZ; ++i) ErdosNums[i] = -1;
	ErdosNums[0] = 0;
	mask[0] = 1;

	step = 1;
	i = vertexes[0] = 0;
	while (i < j){
		count = 0;

		while (i < j){
			v = vertexes[i++];
			for (k = 1; k < index; ++k){
				if (mask[k] == 0 && map[v][k] == cur_true){
					vertexes[j + count] = k;
					mask[k] = 1;
					ErdosNums[k] = step;
					++count;
				}
			}
		}

		j += count;
		++step;
	}
}

int main(){
	int set, scena = 0, P, N, i, j;
	int buf[MAXSZ], buf_sz;
	char str[1024], *p, *q;

	scanf("%d\n", &set);
	for (i = 0; i < MAXSZ; ++i) memset(map[i], 0, MAXSZ);
	/* No more than 255 sets !, e.g. set <= 255 */
	cur_true = 1;
	while (set--){
		names[0].name = "Erdos, P.";
		names[0].index = 0;
		index = 1;
		scanf("%d %d\n", &P, &N);
		while (P--){
			gets(str);
			*strchr(str, ':') = 0;
			if ((p = strchr(str, ',')) == NULL) continue;
			if ((p = strchr(p + 1, ',')) == NULL) continue;
			*p = 0;
			p += 2;
			buf[0] = getindex(str);
			buf_sz = 1;
			while ((q = strchr(p, ',')) != NULL){
				q = strchr(q + 1, ',');
				if (q) *q = 0;
				buf[buf_sz++] = getindex(p);
				if (q) p = q + 2;
				else break;
			}

			for (i = 0; i < buf_sz; ++i){
				for (j = i + 1; j < buf_sz; ++j){
					map[buf[i]][buf[j]] = map[buf[j]][buf[i]] = cur_true;
				}
			}
		}

		getErdosNums();
		printf("Scenario %d\n", ++scena);

		qsort((void *)names, index, sizeof(Names), sort_function);
		while (N--){
			i = ErdosNums[getindex2(gets(str))];
			if (i == -1) printf("%s infinity\n", str);
			else printf("%s %d\n", str, i);
		}

		for (i = 1; i < index; ++i) if (names[i].index) free(names[i].name);
		++cur_true;
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
