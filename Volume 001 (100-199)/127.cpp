/* @JUDGE_ID: 19899RK 127 C++ "By Anadan" */
// ``Accordian'' Patience
// Accepted (1.740 seconds using as much as 396 kbytes)

#include <stdio.h>

struct Piles{
	char card[3];
	struct Piles *next, *prev, *pile;
}pt[52], *last, *head;

Piles *getleftmost(Piles *p){
	Piles *q = p, *t;

	while (1){
		t = q->prev;
		if (t) t = t->prev; else break;
		if (t) t = t->prev;
		if (t && (t->card[0] == p->card[0] || t->card[1] == p->card[1])) q = t;
		else{
			t = q->prev;
			if (t->card[0] == p->card[0] || t->card[1] == p->card[1]) q = t;
			else break;
		}
	}

	if (q == p) return NULL;
	return q;
}

int main(){
	int N;
	char card[3];
	struct Piles *cur, *tmp;

	while (scanf("%s", pt[0].card) == 1 && pt[0].card[0] != '#'){
		head = last = pt;
		pt[0].next = pt[0].prev = pt[0].pile = NULL;

		for (N = 1; N < 52; ++N){
			scanf("%s", pt[N].card);
			cur = pt + N;
			cur->next = cur->pile = NULL;
			cur->prev = last; last->next = cur;

			while (1){
				if ((last = getleftmost(cur)) != NULL){
					if (cur->pile){
						cur->pile->next = cur->next;
						cur->pile->prev = cur->prev;
						cur->prev->next = cur->pile;
						if (cur->next) cur->next->prev = cur->pile;
					}else{
						cur->prev->next = cur->next;
						if (cur->next) cur->next->prev = cur->prev;
					}

					cur->prev = last->prev;
					if (last->prev) last->prev->next = cur;
					else head = cur;
					cur->next = last->next;
					if (last->next) last->next->prev = cur;
					cur->pile = last;
				}

				if (cur->next == NULL) break;
				cur = cur->next;
			}

			last = cur;
		}

		for (N = 1, cur = head->next; cur; cur = cur->next, ++N);
		if (N == 1) printf("1 pile remaining:");
		else printf("%d piles remaining:", N);

		for (last = head; last; last = last->next){
			cur = last->pile;
			for (N = 1; cur; cur = cur->pile, ++N);
			printf(" %d", N);
		}

		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
