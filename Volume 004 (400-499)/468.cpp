/* @JUDGE_ID: 19899RK 468 C++ "By Anadan" */ 
// Key to Success
// Accepted (0.004 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>

struct freq{
	int f;
	char c;
}pt1[52], pt2[52];

int sort_function(const void *a, const void *b){
	freq *p1 = (freq *)a, *p2 = (freq *)b;
	if (p1->f < p2->f) return 1;
	return -1;
}

int main(){
	int i;
	long set;
	char str[1000000], *p;
	scanf("%ld\n\n", &set);

	while (set--) {
		gets(str);
		for (i = 0; i < 26; i++){
			pt1[i].f = pt2[i].f = 0;
			pt1[i].c = pt2[i].c = 'a' + i;
		}

		for (i = 26; i < 52; i++){
			pt1[i].f = pt2[i].f = 0;
			pt1[i].c = pt2[i].c = 'A' + i - 26;
		}

		for (p = str; *p; p++){
			if (('a' <= *p) && (*p <= 'z')) pt1[*p - 'a'].f++;
			else if (('A' <= *p) && (*p <= 'Z')) pt1[*p - 'A' + 26].f++;
		}
		qsort((void *)pt1, 52, sizeof(freq), sort_function);

		gets(str); scanf("\n");
		for (p = str; *p; p++){
			if (('a' <= *p) && (*p <= 'z')) pt2[*p - 'a'].f++;
			else if (('A' <= *p) && (*p <= 'Z')) pt2[*p - 'A' + 26].f++;
		}
		qsort((void *)pt2, 52, sizeof(freq), sort_function);

		for (p = str; *p; p++){
			if ((('a' <= *p) && (*p <= 'z')) ||
			    (('A' <= *p) && (*p <= 'Z'))){
				for (i = 0; i < 52; i++){
					if (pt2[i].c == *p){
						putchar(pt1[i].c);
						break;
					}
				}
			}else putchar(*p);
		}
		putchar('\n');
		if (set) putchar('\n');
	}
	return 0;
}
/* @END_OF_SOURCE_CODE */
