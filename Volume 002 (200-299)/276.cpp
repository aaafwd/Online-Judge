/* @JUDGE_ID: 19899RK 276 C++ "By Anadan" */
// Egyptian Multiplication
// Accepted (0.020 seconds with low memory spent)

#include <stdio.h>

long getnumber(){
	int c;
	long res = 0;

	while ((c = getchar()) != '\n' && c != EOF){
		if (c == '|') ++res;
		else if (c == 'n') res += 10;
		else if (c == '9') res += 100;
		else if (c == '8') res += 1000;
		else if (c == 'r') res += 10000;
	}

	return res;
}

int outprint(long n){
	int i = 0, tmp;

	tmp = int(n % 10);
	if (tmp){
		i += tmp + 1;
		while (tmp--) putchar('|');
		putchar(' ');
	}
	n /= 10;

	tmp = int(n % 10);
	if (tmp){
		i += tmp + 1;
		while (tmp--) putchar('n');
		putchar(' ');
	}
	n /= 10;

	tmp = int(n % 10);
	if (tmp){
		i += tmp + 1;
		while (tmp--) putchar('9');
		putchar(' ');
	}
	n /= 10;

	tmp = int(n % 10);
	if (tmp){
		i += tmp + 1;
		while (tmp--) putchar('8');
		putchar(' ');
	}
	n /= 10;

	tmp = int(n % 10);
	if (tmp){
		i += tmp + 1;
		while (tmp--) putchar('r');
		putchar(' ');
	}
	n /= 10;

	return i;
}

int main(){
	int i;
	long a, b, c, left;

	while (1){
		if ((a = getnumber()) == 0) break;
		if ((b = getnumber()) == 0) break;
		c = a * b;
		left = 1;

		while (b){
			i = outprint(left);
			if (b & 1) putchar('*'), ++i;

			while (i++ < 34) putchar(' ');
			outprint(a);
			putchar('\n');

			a <<= 1;
			left <<= 1;
			b >>= 1;
		}

		printf("The solution is: ");
		outprint(c);
		putchar('\n');
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
