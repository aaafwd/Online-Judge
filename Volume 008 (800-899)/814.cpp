/* @JUDGE_ID: 19899RK 814 C++ "By Anadan" */
// The Letter Carrier's Rounds
// Accepted (0.035 seconds with low memory spent)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int N;
struct MTA{
	int n;
	char mtaname[16];
	char **names;
}mta[100];
char names[100][100][16];

int data_count;
char data[101][80];

int str_sort(const void *a, const void *b){
	return strcmp((char *)a, (char *)b);
}

int mta_sort(const void *a, const void *b){
	return strcmp(((MTA *)a)->mtaname, ((MTA *)b)->mtaname);
}

void readata(){
	for (data_count = 0; gets(data[data_count]) && data[data_count][0] != '*'; ++data_count);
}

void writedata(){
	register int i;
	printf("     DATA\n");
	printf("     354\n");
	for (i = 0; i < data_count; ++i){
		if (data[i][0]) printf("     %s\n", data[i]);
		else putchar('\n');
	}
	printf("     .\n     250\n");
}

int main(){
	int off, i, j;
	char str[1024], *p, *q, *s, cur, flag;
	char recipients[101][50], mask[100];
	MTA *sender, *receiver, tmp;

	N = 0;
	while (1){
		gets(str);
		if (str[0] == '*') break;
		sscanf(str, "%*s%s%d%n", mta[N].mtaname, &mta[N].n, &off);
		for (p = str + off, i = 0; i < mta[N].n; ++i){
			sscanf(p, "%s%n", names[N][i], &off);
			p += off;
		}

		mta[N].names = (char **)names[N];
		++N;
	}

	for (i = 0; i < N; ++i){
		qsort(names[i], mta[i].n, 16, str_sort);
	}
	qsort(mta, N, sizeof(MTA), mta_sort);

	while (1){
		scanf("%s", str);
		if (str[0] == '*') break;

		off = 0;
		while (1){
			scanf("%s", recipients[off]);
			if (recipients[off][0] == '*') break;
			++off;
		}
		while (getchar() != '\n');
		readata();

		s = strchr(str, '@');
		*s++ = 0;
		strcpy(tmp.mtaname, s);

		sender = (MTA *)bsearch(&tmp, mta, N, sizeof(MTA), mta_sort);

		memset(mask, 0, off);

		for (i = 0; i < off; ++i){
			if (mask[i]) continue;
			for (j = i + 1; j < off; ++j){
				if (!strcmp(recipients[i], recipients[j])) mask[j] = 1;
			}
		}

		for (cur = 1, i = 0; i < off; ++i){
			++cur;
			if (mask[i]) continue;
			p = strchr(recipients[i], '@');
			*p++ = 0;

			strcpy(tmp.mtaname, p);
			receiver = (MTA *)bsearch(&tmp, mta, N, sizeof(MTA), mta_sort);

			mask[i] = cur;
			for (j = i + 1; j < off; ++j){
				if (mask[j]) continue;
				q = strchr(recipients[j], '@');
				if (strcmp(q + 1, p)) continue;
				*q = 0;
				mask[j] = cur;
			}

			printf("Connection between %s and %s\n", s, p);
			printf("     HELO %s\n", s);
			printf("     250\n");
			printf("     MAIL FROM:<%s@%s>\n", str, s);
			printf("     250\n");
			for (flag = 0, j = i; j < off; ++j){
				if (mask[j] != cur) continue;
				printf("     RCPT TO:<%s@%s>\n", recipients[j], p);
				if (bsearch(recipients[j], receiver->names, receiver->n, 16, str_sort)) printf("     250\n"), flag = 1;
				else printf("     550\n");
			}

			if (flag) writedata();
			printf("     QUIT\n     221\n");
		}
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
