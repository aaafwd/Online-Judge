/* @JUDGE_ID: 19899RK 10367 C++ "By Anadan" */ 
// Equations
// Accepted (0.002 seconds with low memory spent)

#include <stdio.h>
#include <ctype.h>

void reduce(int &a0, int &b0){
	int gcd = 1, a, b;
	char sign = 0;

	if (b0 < 0){
		b0 = -b0;
		a0 = -a0;
	}
	if (a0 < 0){
		a0 = -a0;
		sign = 1;
	}

	a = a0; b = b0;
	while (a && b){
		while ((a & 1 == 0) && (b & 1 == 0)){
			a >>= 1; b >>= 1; gcd <<= 1;
		}

		while (a && (a & 1 == 0)) a >>= 1;
		while (b && (b & 1 == 0)) b >>= 1;
		if (a > b) a = a - b;
		else b = b - a;
	}

	if (a) gcd *= a; else gcd *= b;
	a0 /= gcd; b0 /= gcd;
	if (sign) a0 = -a0;
}

void parsestr(int &a, int &b, int &c){
	int i, k;
	char sign, equ = 0;

	a = b = c = 0;
	while ((i = getchar()) != '\n'){
		if (i == '-'){
			sign = equ ^ 1;
			while ((i = getchar()) == ' ');
		}else sign = equ;
			if (isdigit(i)){
			k = i - '0';
			while (isdigit(i = getchar())){
				k *= 10;
				k += i - '0';
			}
			if (sign) k = -k;
			if (i == 'x') a += k;
			else if (i == 'y') b += k;
			else c -= k;
			if (i == '\n' || i == EOF) break;
		}else if (i == '='){
			equ = 1;
		}else if (i == 'x'){
			if (sign) --a; else ++a;
		}else if (i == 'y'){
			if (sign) --b; else ++b;
		}
	}
}

int main(){
	int i, j, k, set, a1, b1, c1, a2, b2, c2, det;

	scanf("%d\n", &set);
	while (set--){
		parsestr(a1, b1, c1);
		parsestr(a2, b2, c2);
		while ((i = getchar()) != '\n' && i != EOF);

		det = a1*b2 - a2*b1;
		if (det){
			i = c1*b2 - c2*b1;
			k = det;
			reduce(i, k);
			j = a1*c2 - a2*c1;
			reduce(j, det);
			if (k > 1) printf("%d/%d\n", i, k); else printf("%d\n", i);
			if (det > 1) printf("%d/%d\n", j, det); else printf("%d\n", j);
		}else{
			if (a1 == 0 && b1 == 0 && c1 != 0 ||
			    a2 == 0 && b2 == 0 && c2 != 0 ||
			    a1 == 0 && b1 == 0 && a2 == 0 && b2 == 0) printf("don't know\ndon't know\n");
			else{
				if (a1 == 0 && b1 == 0){
					if (a2 == 0 && b2){
						i = c2; j = b2; reduce(i, j);
						printf("don't know\n");
						if (j > 1) printf("%d/%d\n", i, j); else printf("%d\n", i);
					}else if (a2 && b2 == 0){
						i = c2; j = a2; reduce(i, j);
						if (j > 1) printf("%d/%d\n", i, j); else printf("%d\n", i);
						printf("don't know\n");
					}else printf("don't know\ndon't know\n");
				}else if (a2 == 0 && b2 == 0){
					if (a1 == 0 && b1){
						i = c1; j = b1; reduce(i, j);
						printf("don't know\n");
						if (j > 1) printf("%d/%d\n", i, j); else printf("%d\n", i);
					}else if (a1 && b1 == 0){
						i = c1; j = a1; reduce(i, j);
						if (j > 1) printf("%d/%d\n", i, j); else printf("%d\n", i);
						printf("don't know\n");
					}else printf("don't know\ndon't know\n");
				}else if(a1 == 0 && a2 == 0){
					i = c1; j = b1; reduce(i, j);
					k = c2; det = b2; reduce(k, det);
					printf("don't know\n");
					if (i == k && j == det){
						if (j > 1) printf("%d/%d\n", i, j); else printf("%d\n", i);
					}else printf("don't know\n");
				}else if(b1 == 0 && b2 == 0){
					i = c1; j = a1; reduce(i, j);
					k = c2; det = a2; reduce(k, det);
					if (i == k && j == det){
						if (j > 1) printf("%d/%d\n", i, j); else printf("%d\n", i);
					}else printf("don't know\n");
					printf("don't know\n");
				}
				else printf("don't know\ndon't know\n");
			}
		}

		if (set) putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
