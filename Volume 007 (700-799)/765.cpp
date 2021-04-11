/* @JUDGE_ID: 19899RK 765 C++ "By Anadan" */ 
// References
// Accepted (0.086 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SZ 40000

struct Refs{
	int old;
	char *descr;
}pt[1000];
char *lines[SZ];

int empty(char *p){
	while (*p == ' ') ++p;
	return (*p == 0);
}

inline char *_strdup(char *p){
	return strcpy((char *)malloc(strlen(p) + 1), p);
}

int sort_function(const void *a, const void *b){
	if (((Refs *)a)->old < ((Refs *)b)->old) return -1;
	return 1;
}

void mysscanf(char *s, int &x){
	x = 0;
	while ('0' <= *s && *s <= '9') x = x * 10 + *s++ - '0';
}

void mysprintf(char *s, int k, int &i){
	if (k){
		mysprintf(s, k / 10, i);
		s[i++] = '0' + (k % 10);
	}
}

inline int numlen(int x){
	if (x < 10) return 1;
	else if (x < 100) return 2;
	else return 3;
}

int main(){
	int nums[1000], i, j, k, count = 0, R = 0, L = 0;
	char str[2][128], buf[300], *p, *q;

	memset(nums, -1, sizeof(nums));

	while (gets(str[0])){
		if (str[0][0] == '[' && (L == 0 || lines[L - 1] == NULL)){
			mysscanf(str[0] + 1, pt[R].old);
			for (p = str[0]; *p != ']'; ++p); ++p;
			for (q = buf; *q = *p; ++q, ++p); *q++ = '\n';

			while (gets(str[0]) && !empty(str[0])){
				for (p = str[0]; *q = *p; ++q, ++p); *q++ = '\n';
			}

			*q = 0;
			pt[R++].descr = _strdup(buf);

		}else if (empty(str[0])){
			if (L && lines[L - 1] != NULL) lines[L++] = NULL;

		}else{
			j = 0;
			p = str[0];
			while ((p = strchr(p, '[')) != NULL){
				mysscanf(p + 1, i);
				if (nums[i] == -1) nums[i] = ++count;
				if (i != nums[i]){
					q = p;
					*p++ = 0;
					k = 0;
					while (*p++ != ']') ++k;
					if (numlen(nums[i]) == k){
						*q++ = '[';
						k = 0;
						mysprintf(q, nums[i], k);
						continue;
					}

					k = nums[i];
					for (i = 0; str[j][i]; ++i) str[j ^ 1][i] = str[j][i];

					j ^= 1;

					str[j][i++] = '[';
					mysprintf(str[j], k, i);
					str[j][i++] = ']';

					for (k = 0; p[k]; ++k) str[j][i + k] = p[k];
					str[j][i + k] = p[k];

					p = str[j] + i - 1;
				}

				++p;
			}

			lines[L++] = _strdup(str[j]);
		}
	}

	for (i = 0; i < L; ++i){
		if (lines[i]){
			puts(lines[i]);
			free(lines[i]);
		}else putchar('\n');
	}

	for (i = 0; i < R; ++i) pt[i].old = nums[pt[i].old];
	qsort(pt, R, sizeof(Refs), sort_function);

	for (i = 0; i < R; ++i){
		printf("\n[%d]%s", pt[i].old, pt[i].descr);
		free(pt[i].descr);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
