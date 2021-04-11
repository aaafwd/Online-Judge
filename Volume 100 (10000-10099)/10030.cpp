/* @JUDGE_ID: 19899RK 10030 C++ "By Anadan" */
// Computer Dialogue
// Accepted (0.043 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N, M;
char names[1000][16], * name8[1000], * name3[1000], mask[1000];
int count8[1000], count3[1000];

struct Archive{
	int i8, i3, dot;
} pt[1000];

int sort_function(const void *a, const void *b){
	return strcmp(*(char **)a, *(char **)b);
}

int getindex8(char * s){
	char **ptr = (char **)bsearch(&s, name8, N, sizeof(char *), sort_function);
	return int(ptr - name8);
}

int getindex3(char * s){
	char **ptr = (char **)bsearch(&s, name3, N, sizeof(char *), sort_function);
	return int(ptr - name3);
}

inline void outprint(int i){
	if (pt[i].dot) printf("%s.%s\n", name8[pt[i].i8], name3[pt[i].i3]);
	else puts(name8[pt[i].i8]);
}

int main(){
	int set, i, j, res, sp;
	char * p;

	scanf("%d", &set);
	while (set--){
		scanf("%d%d", &N, &M);

		sp = 0;
		for (i = 0; i < N; ++i){
			scanf("%s", names[i]);
			p = strchr(names[i], '.');
			if (p){
				pt[i].dot = 1;
				*p++ = 0;
			}else{
				pt[i].dot = 0;
				p = names[i] + strlen(names[i]);
			}

			name3[sp] = p;
			name8[sp++] = names[i];
			count3[i] = count8[i] = 0;
		}

		qsort(name8, N, sizeof(char *), sort_function);
		qsort(name3, N, sizeof(char *), sort_function);

		for (i = 0; i < N; ++i){
			pt[i].i8 = getindex8(names[i]);
			++count8[pt[i].i8];
			p = names[i] + strlen(names[i]);
			if (pt[i].dot) ++p;
			pt[i].i3 = getindex3(p);
			++count3[pt[i].i3];
		}

		memset(mask, 0, N);
		for (j = 0; j < M; ++j){
			if (j & 1){
				for (i = 0; i < N; ++i){
					if (mask[i]) continue;
					if (count8[pt[i].i8] <= 1){
						--count3[pt[i].i3];
						--count8[pt[i].i8];
						mask[i] = 1;
					}
				}
			}else{
				for (i = 0; i < N; ++i){
					if (mask[i]) continue;
					if (count3[pt[i].i3] <= 1){
						--count3[pt[i].i3];
						--count8[pt[i].i8];
						mask[i] = 1;
					}
				}
			}
		}

		res = 0;
		for (i = 0; i < N; ++i) if (!mask[i]) ++res;

		printf("%d\n", res);
		for (i = 0; i < N; ++i) if (!mask[i]) outprint(i);

		if (set) putchar('\n');
	}

	return 0;
}

/* @END_OF_SOURCE_CODE */
