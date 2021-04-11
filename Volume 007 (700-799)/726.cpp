/* @JUDGE_ID: 19899RK 726 C++ "By Anadan" */
// Decode
// Accepted (0.370 seconds using as much as 2348 kbytes)

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Symb{
	char c;
	long freq;
}pt1[26], pt2[26];

int sort_function(const void *a, const void *b){
	Symb *p1 = (Symb *)a, *p2 = (Symb *)b;
	if (p1->freq > p2->freq) return -1;
	if (p1->freq == p2->freq && p1->c < p2->c) return -1;
	return 1;
}

int main(){
	char str[2000000], *p;
	int i, c1 = 0, c2;

	for (i = 0; i < 26; i++){
		pt1[i].c = pt2[i].c = 'a' + i;
		pt1[i].freq = pt2[i].freq = 0L;
	}

	while (1){
		c2 = getchar();
		if (('a' <= c2) && (c2 <= 'z')) ++pt1[c2 - 'a'].freq;
		else if (('A' <= c2) && (c2 <= 'Z')) ++pt1[c2 - 'A'].freq;
		else if (c2 == '\n' && c1 == '\n') break;
		c1 = c2;
	}
	qsort((void *)pt1, 26, sizeof(Symb), sort_function);

	p = str;
	while ((c2 = getchar()) != EOF){
		if (('a' <= c2) && (c2 <= 'z')) ++pt2[c2 - 'a'].freq;
		else if (('A' <= c2) && (c2 <= 'Z')) ++pt2[c2 - 'A'].freq;
		*p++ = c2;
	}
	*p = 0;

	qsort((void *)pt2, 26, sizeof(Symb), sort_function);
	for (p = str; *p; p++){
		if (isalpha(*p)){
			c2 = 0;
			if (('A' <= *p) && (*p <= 'Z')) c1 = *p - 'A' + 'a';
			else c1 = c2 = *p;
			for (i = 0 ;; i++) if (pt2[i].c == c1) break;
			if (c2) putchar(pt1[i].c);
			else putchar(pt1[i].c - 'a' + 'A');
		}else putchar(*p);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
