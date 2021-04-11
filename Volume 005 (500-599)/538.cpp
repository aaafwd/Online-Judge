/* @JUDGE_ID: 19899RK 538 C++ "By Anadan" */
// Balancing Bank Accounts
// Accepted (0.328 seconds using as much as 396 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Traveller{
	int ballance;
	char name[81];
}pt[20];

int sort_function(const void *a, const void *b){
	return strcmp(((Traveller *)a)->name, ((Traveller *)b)->name);
}

int main(){
	int n, i, j, set = 0;
	Traveller p1, p2, *q1, *q2;

	while (scanf("%d%d\n", &n, &j) == 2 && n){
		for (i = 0; i < n; ++i){
			pt[i].ballance = 0;
			scanf("%s\n", pt[i].name);
		}

		qsort(pt, n, sizeof(Traveller), sort_function);

		while (j--){
			scanf("%s%s%d\n", p1.name, p2.name, &i);
			q1 = (Traveller *)bsearch(&p1, pt, n, sizeof(Traveller), sort_function);
			q2 = (Traveller *)bsearch(&p2, pt, n, sizeof(Traveller), sort_function);
			q1->ballance -= i;
			q2->ballance += i;
		}

		printf("Case #%d\n", ++set);

		for (i = 0; i < n; ++i){
			if (pt[i].ballance <= 0) continue;
			for (j = 0; j < n; ++j){
				if (pt[j].ballance >= 0) continue;
				if (pt[i].ballance >= -pt[j].ballance){
					printf("%s %s %d\n", pt[i].name, pt[j].name, -pt[j].ballance);
					pt[i].ballance += pt[j].ballance;
					pt[j].ballance = 0;
				}
			}

			if (pt[i].ballance){
				for (j = 0; pt[i].ballance > -pt[j].ballance; ++j);
				printf("%s %s %d\n", pt[i].name, pt[j].name, pt[i].ballance);
				pt[j].ballance += pt[i].ballance;
				pt[i].ballance = 0;
			}
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
