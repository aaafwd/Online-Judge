/* @JUDGE_ID: 19899RK 162 C++ "By Anadan" */ 
// Beggar My Neighbour
// Accepted (0.145 seconds using as much as 388 kbytes)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Deck{
	struct Deck *next;
	char card;
}*b[2], *c[2], *d[2];

int main(){
	int i, j, k;
	char s1[3], s2[3], str[5] = "JQKA", *p;

	while (scanf("%s", s2) == 1 && s2[0] != '#'){
		scanf("%s", s1);
		b[0] = c[0] = (Deck *)malloc(sizeof(Deck)); // dealer
		b[1] = c[1] = (Deck *)malloc(sizeof(Deck)); // first to play
		b[0]->card = s1[1]; b[0]->next = NULL;
		b[1]->card = s2[1]; b[1]->next = NULL;
		
		for (i = 0; i < 25; ++i){
			scanf("%s%s", s2, s1);
			d[0] = (Deck *)malloc(sizeof(Deck));
			d[1] = (Deck *)malloc(sizeof(Deck));
			d[0]->card = s1[1]; d[0]->next = c[0];
			d[1]->card = s2[1]; d[1]->next = c[1];
			c[0] = d[0]; c[1] = d[1];
		}

		i = 1;
		d[0] = d[1] = NULL;
		while (1){
			if (d[0] == NULL){
				d[0] = d[1] = c[i];
				c[i] = c[i]->next;
				d[0]->next = NULL;
				i ^= 1;
			}else if ((p = strchr(str, d[1]->card)) != NULL){
				k = int(p - str);
				for (j = 0; j <= k; ++j){
					if (c[i] == NULL) { j = -1; break; }
					d[1] = d[1]->next = c[i];
					c[i] = c[i]->next;
					d[1]->next = NULL;
					if (strchr(str, d[1]->card)) break;
				}

				if (j == -1) break;
				i ^= 1;
				if (j > k){
					if (c[i]) b[i]->next = d[0];
					else c[i] = d[0];
					b[i] = d[1];
					d[0] = d[1] = NULL;
				}
			}else{
				if (c[i] == NULL) break;
				d[1] = d[1]->next = c[i];
				c[i] = c[i]->next;
				d[1]->next = NULL;
				i ^= 1;
			}
		}

		i ^= 1;
		for (j = 0; c[i]; ++j){
			b[0] = c[i];
			c[i] = c[i]->next;
			free(b[0]);
		}

		while (d[0]){
			b[0] = d[0];
			d[0] = d[0]->next;
			free(b[0]);
		}

		printf("%d%3d\n", i + 1, j);
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
