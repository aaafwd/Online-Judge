/* @JUDGE_ID: 19899RK 10028 C++ "By Anadan" */ 
// Demerit Points
// Accepted (0.000 seconds with low memory spent)

#include <stdio.h>

void outprint(int curr, int merit, int demerit){
	printf("%.4d-%.2d-%.2d ", curr / 10000, (curr / 100) % 100, curr % 100);
	if (demerit) printf("%d demerit point(s).\n", demerit);
	else if (merit) printf("%d merit point(s).\n", merit);
	else printf("No merit or demerit points.\n");
}

int main(){
	int set, i, p, merit, demerit, curr, next;

	scanf("%d\n\n", &set);
	while (set--){
		merit = demerit = 0;
		scanf("%d", &curr); while (getchar() != '\n');
		outprint(curr, merit, demerit);
		while (1){
			while ((i = getchar()) == ' ' || i == '\t');
			if (i == '\n' || i == EOF) break;
			scanf("%d%d", &next, &p);
			next += 10000000 * (i - '0');
			while (getchar() != '\n');

			i = 0;
			curr += 10000;
			while (curr <= next){
				if (demerit){
					if (demerit < 3) demerit = 0;
					else demerit /= 2;
				}else{
					if (merit == 5) break;
					++i;
					if (i & 1) { curr += 10000; continue; }
					++merit;
				}

				outprint(curr, merit, demerit);
				curr += 10000;
			}

			curr = next;
			demerit += p;
			if (merit){
				if (demerit > merit * 2){
					demerit -= merit * 2;
					merit = 0;
				}else{
					merit -= (demerit + 1) / 2;
					demerit = 0;
				}
			}
			outprint(curr, merit, demerit);
		}

		while (demerit){
			curr += 10000;
			if (demerit < 3) demerit = 0;
			else demerit /= 2;
			outprint(curr, merit, demerit);
		}

		while (merit < 5){
			curr += 20000;
			outprint(curr, ++merit, demerit);
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
