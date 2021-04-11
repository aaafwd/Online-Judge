/* @JUDGE_ID: 19899RK 708 C++ "By Anadan" */ 
// Dreisam Equations
// Accepted (0.318 seconds using as much as 392 kbytes)

#include <stdio.h>

char str[81], op[11];
int nums[12], N, res;

int evaluate(char *&p, int &i){
	int tmp = 0, tmp2, j;

	if (*p == '('){
		++p;
		tmp = evaluate(p, i);
	}else tmp = nums[*p++];

	while (*p != -1){
		j = i;
		if (*p == '('){
			++p; ++i;
			tmp2 = evaluate(p, i);
		}else if (*p == ')'){
			++p;
			return tmp;
		}else tmp2 = nums[*p++], ++i;

		if (op[j] == '+') tmp += tmp2;
		else if (op[j] == '-') tmp -= tmp2;
		else tmp *= tmp2;
	}

	return tmp;
}

void outprint(char *&p, int &i){
	if (*p == '('){
		++p;
		putchar('(');
		outprint(p, i);
	}else{
		printf("%d", nums[*p++]);
	}

	while (*p != -1){
		if (*p == ')'){
			++p;
			putchar(')');
			break;
		}

		putchar(op[i++]);
		if (*p == '('){
			++p;
			putchar('(');
			outprint(p, i);
		}else printf("%d", nums[*p++]);
	}
}


int generate(int pos){
	char *p = str;

	if (pos == N - 1){
		pos = 0;
		return (evaluate(p, pos) == res);
	}

	op[pos] = '+';
	if (generate(pos + 1)) return 1;
	op[pos] = '-';
	if (generate(pos + 1)) return 1;
	op[pos] = '*';
	if (generate(pos + 1)) return 1;
	return 0;
}

int main(){
	int set = 0, i;
	char *p;

	while (1){
		while ((res = getchar()) != EOF && (res < '0' || res > '9'));
		res -= '0';
		while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
			res = res * 10 + i - '0';
		}
		if (res == 0) break;
		while (i != '=') i = getchar();

		N = 0;
		p = str;
		while (1){
			while ((i = getchar()) != '\n' && (i < '0' || i > '9') && i != '(' && i != ')');
			if (i == '\n') break;
			if ('0' <= i && i <= '9'){
				nums[N] = i - '0';
				while ((i = getchar()) != EOF && '0' <= i && i <= '9'){
					nums[N] = nums[N] * 10 + i - '0';
				}
				*p++ = N++;
				if (i == '\n') break;
				else if (i == '(' || i == ')') *p++ = i;
			}else *p++ = i;
		}
		*p = -1;

		printf("Equation #%d:\n", ++set);
		if (generate(0)){
			printf("%d=", res);

			i = 0;
			p = str;
			outprint(p, i);

			printf("\n\n");
		}else printf("Impossible.\n\n");
	}

	return 0;
}
/* @END_OF_SOURCE_CODE */
