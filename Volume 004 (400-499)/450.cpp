/* @JUDGE_ID: 19899RK 450 C++ "By Anadan" */ 
// Little Black Book
// Accepted (0.066 seconds with low memory spent)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SZ 8000

struct Book{
	char *title, *fname, *lname;
	char *address, *department;
	char *wphone, *hphone, *box;
}pt[SZ];

int sort_function(const void *a, const void *b){
	return strcmp(((Book *)a)->lname, ((Book *)b)->lname);
}

inline char *_strdup(char *s){
	return strcpy((char *)malloc(strlen(s) + 1), s);
}

int main(){
	int N, i;
	char str[256], department[256], *p;

	i = 0;
	scanf("%d\n", &N);
	while (N--){
		gets(department);
		while (gets(str) && (p = strtok(str, ",")) != NULL){
			pt[i].title = _strdup(p);
			p = strtok(NULL, ",");
			pt[i].fname = _strdup(p);
			p = strtok(NULL, ",");
			pt[i].lname = _strdup(p);
			p = strtok(NULL, ",");
			pt[i].address = _strdup(p);
			p = strtok(NULL, ",");
			pt[i].hphone = _strdup(p);
			p = strtok(NULL, ",");
			pt[i].wphone = _strdup(p);
			p = strtok(NULL, ",");
			pt[i].box = _strdup(p);
			pt[i].department = _strdup(department);
			++i;
		}
	}

	N = i;
	qsort(pt, N, sizeof(Book), sort_function);
	for (i = 0; i < N; ++i){
		printf("----------------------------------------\n");
		printf("%s %s %s\n", pt[i].title, pt[i].fname, pt[i].lname);
		printf("%s\n", pt[i].address);
		printf("Department: %s\n", pt[i].department);
		printf("Home Phone: %s\n", pt[i].hphone);
		printf("Work Phone: %s\n", pt[i].wphone);
		printf("Campus Box: %s\n", pt[i].box);

		free(pt[i].title); free(pt[i].fname); free(pt[i].lname);
		free(pt[i].address); free(pt[i].department);
		free(pt[i].hphone); free(pt[i].wphone); free(pt[i].box);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
